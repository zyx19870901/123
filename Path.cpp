#include "path.h"
#include <cfloat>

using namespace path;

//����������ľ���
inline float dist_2(const Point &pt1, const Point &pt2)
{
	float dx = float(pt1.x-pt2.x);
	float dy = float(pt1.y-pt2.y);
	return (dx*dx+dy*dy); //ֻ���ڱȽϴ�С������ȡ����
}

//�ж�һ��path�Ƿ�պ�
inline bool is_close_path(const Path &path)
{
	const float CLOSE_PATH_EP = 100.0f;
	int n = path.size();
	if(dist_2(path[0],path[n-1]) < CLOSE_PATH_EP) //ͷ�����β���ľ���С����ֵ
		return true;
	return false;
}

//����һ���㵽һ�����·������̾���
float dist_to_closed_path(const Point &start_pt, const Path &path, int &path_start, Point &end_pt)
{
	int n = path.size();
	float MIN_DIST = FLT_MAX;
	for (int i=0; i<n; i++) //�������м������
	{
		float d = dist_2(start_pt,path[i]);
		if(d < MIN_DIST)
		{
			MIN_DIST   = d;
			path_start = i;
			end_pt     = path[i];
		}
	}
	return MIN_DIST;
}

//һ���㵽һ������·������̾���
float dist_to_opened_path(const Point &start_pt, const Path &path, int &path_start, Point &end_pt)
{
	int n = path.size();
	float d1 = dist_2(start_pt,path[0]);   //ͷ���������
	float d2 = dist_2(start_pt,path[n-1]); //β�ڵ�������
	if(d1 < d2)
	{
		path_start = 0;
		end_pt     = path[n-1];
	}
	else
	{
		path_start = n-1;
		end_pt     = path[0];
	}
	return (min(d1,d2));
}

void path::optimize_path(Point &start_end_pt, const Paths &path, const vector<bool> &is_closed, vector<int> &path_order, vector<int> &path_start)
{
	path_order.clear();
	path_start.clear();
	int n = path.size();
	//��¼ÿ��path�Ƿ��Ѿ���ռ��
	vector<bool> occupied; 
	occupied.resize(n);
	for(int i=0; i<n; i++)
		occupied[i]  = false;
	//ÿ��Ѱ��һ�������path
	for (int count=0; count<n; count++) 
	{
		Point end_pt   = start_end_pt;
		float MIN_DIST = FLT_MAX;
		int order=0, start=0;
		for (int path_no=0; path_no<n; path_no++)
		{
			if(!occupied[path_no]) //�Ѿ�ռ�õĲ��ٲ����ж�
			{
				int   t_start = 0; //�ݴ�startλ��
				Point t_end_pt;
				auto *dist_to_path = (is_closed[path_no]) ? dist_to_closed_path : dist_to_opened_path;
				float d = dist_to_path(start_end_pt, path[path_no], t_start, t_end_pt);
				if(d < MIN_DIST)
				{
					MIN_DIST = d;
					order    = path_no;
					start    = t_start;
					end_pt   = t_end_pt;
				}
			}
		}	
		occupied[order] = true;
		start_end_pt = end_pt;
		path_order.push_back(order);
		path_start.push_back(start);
	}
}

void path::optimize_path(Point &start_end_pt, const Paths &path_in, Paths &path_out)
{	
	int path_num = path_in.size();
	/////////////////////////////////////////////
	vector<bool> is_closed;
	is_closed.resize(path_num);
	for(int i=0; i<path_num; i++)
		is_closed[i] = is_close_path(path_in[i]);
	/////////////////////////////////////////////
	vector<int> polyOrder, polyStart;
	optimize_path(start_end_pt, path_in, is_closed, polyOrder, polyStart);
	/////////////////////////////////////////////
	path_out.resize(path_num);
	for (int i=0; i<path_num; i++)
	{
		int order  = polyOrder[i];
		int start  = polyStart[i];
		int pt_num = path_in[order].size();
		if(is_closed[order]) //close��ǩ
		{
			if(start == 0)
			{
				path_out[i] = path_in[order];
			}
			else
			{
				for (int j=0; j<=pt_num; j++) //��ͷ��㱣������(j==0/pt_num) 
				{ 
					int pos = (start+j)%pt_num;
					if(pos != 0) //ԭͷ���ֻ����һ��
						path_out[i].push_back(path_in[order][pos]);
				}
			}
			
		}
		else
		{				
			path_out[i].clear();
			if(start == 0) //��ͷ��β
			{
				path_out[i] = path_in[order];
			}
			else if(start==pt_num-1) //��β��ͷ
			{
				for (int j=pt_num-1; j>=0; j--)
					path_out[i].push_back(path_in[order][j]);
			}
		}
	}
}