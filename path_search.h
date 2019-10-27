#ifndef __PATH_SEARCH__
#define __PATH_SEARCH__

#include <vector>

class grid;
class map;

class grid
{
public:
	int x,y;
	unsigned int dis;
	int forbid;

	void assign(int X, int Y);
	bool operator==(const grid& B);
};

class map
{
private:
	int dim_x, dim_y;
	std::vector< std::vector<grid> > topo;
	int s_x, s_y;
	int t_x, t_y;
public:
	void init(int Dim_x, int Dim_y);
	void flush();
	void search(int X, int Y, int Dis);
	void search_run(std::vector< std::vector<int> >& block, int S_x, int S_y, int T_x, int T_y);
	void print();
};
#endif
