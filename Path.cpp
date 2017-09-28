#include "path.h"
#include <cfloat>

using namespace path;

//计算两个点的距离
inline float dist_2(const Point &pt1, const Point &pt2)
{
	float dx = float(pt1.x-pt2.x);
	float dy = float(pt1.y-pt2.y);
	return (dx*dx+dy*dy); //只用于比较大小，不必取根号
}

//判断一个path是否闭合
inline bool is_close_path(const Path &path)
{
	const float CLOSE_PATH_EP = 100.0f;
	int n = path.size();
	if(dist_2(path[0],path[n-1]) < CLOSE_PATH_EP) //头结点与尾结点的距离小于阈值
		return true;
	return false;
}

//计算一个点到一条封闭路径的最短距离
float dist_to_closed_path(const Point &start_pt, const Path &path, int &path_start, Point &end_pt)
{
	int n = path.size();
	float MIN_DIST = FLT_MAX;
	for (int i=0; i<n; i++) //逐个点进行计算距离
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

//一个点到一条开放路径的最短距离
float dist_to_opened_path(const Point &start_pt, const Path &path, int &path_start, Point &end_pt)
{
	int n = path.size();
	float d1 = dist_2(start_pt,path[0]);   //头结点计算距离
	float d2 = dist_2(start_pt,path[n-1]); //尾节点计算距离
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
	//记录每个path是否已经被占用
	vector<bool> occupied; 
	occupied.resize(n);
	for(int i=0; i<n; i++)
		occupied[i]  = false;
	//每遍寻找一个最近的path
	for (int count=0; count<n; count++) 
	{
		Point end_pt   = start_end_pt;
		float MIN_DIST = FLT_MAX;
		int order=0, start=0;
		for (int path_no=0; path_no<n; path_no++)
		{
			if(!occupied[path_no]) //已经占用的不再参与判断
			{
				int   t_start = 0; //暂存start位置
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
		if(is_closed[order]) //close标签
		{
			if(start == 0)
			{
				path_out[i] = path_in[order];
			}
			else
			{
				for (int j=0; j<=pt_num; j++) //新头结点保存两次(j==0/pt_num) 
				{ 
					int pos = (start+j)%pt_num;
					if(pos != 0) //原头结点只保存一次
						path_out[i].push_back(path_in[order][pos]);
				}
			}
			
		}
		else
		{				
			path_out[i].clear();
			if(start == 0) //从头到尾
			{
				path_out[i] = path_in[order];
			}
			else if(start==pt_num-1) //从尾到头
			{
				for (int j=pt_num-1; j>=0; j--)
					path_out[i].push_back(path_in[order][j]);
			}
		}
	}
}