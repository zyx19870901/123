#ifndef _PATH_H_
#define _PATH_H_

#include <vector>
using namespace std;

namespace path
{
	struct Point
	{
		float x, y;
		Point()
		{
			x = 0.0f; 
			y = 0.0f;
		}
		Point(float _x, float _y)
		{
			x = _x;
			y = _y;
		}
	};

	typedef vector<Point> Path;
	typedef vector<Path> Paths;

	void optimize_path(
		Point &start_end_pt, 

		const Paths &path, 
		const vector<bool> &is_closed, 
		
		vector<int> &path_order, 
		vector<int> &path_start
		);

	void optimize_path(Point &start_end_pt, const Paths &path_in, Paths &path_out);
}

#endif // #ifndef _PATH_H_