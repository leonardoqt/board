#include <iostream>
#include <iomanip>
#include "path_search.h"

using namespace std;

void grid :: assign(int X, int Y)
{
	x = X;
	y = Y;
}

bool grid :: operator==(const grid& B)
{
	if (x == B.x && y == B.y)
		return true;
	else
		return false;
}

//===================================

void map :: init(int Dim_x, int Dim_y)
{
	dim_x = Dim_x;
	dim_y = Dim_y;
	topo.resize(dim_x);
	for(auto& m1 : topo)
		m1.resize(dim_y);
	for(size_t t1=0; t1<dim_x; t1++)
	for(size_t t2=0; t2<dim_y; t2++)
	{
		topo[t1][t2].assign(t1,t2);
		topo[t1][t2].dis = -1;
		topo[t1][t2].forbid = 0;
	}
}

void map :: flush()
{
	for(auto& m1 : topo)
	for(auto& m2 : m1)
	{
		m2.dis = -1;
		m2.forbid = 0;
	}
}

void map :: search_run(std::vector< std::vector<int> >& block, int S_x, int S_y, int T_x, int T_y)
{
	flush();
	for (auto& m1:block)
		topo[m1[0]][m1[1]].forbid = 1;
	s_x = S_x;
	s_y = S_y;
	t_x = T_x;
	t_y = T_y;
	search(s_x,s_y,0);
}

void map :: search(int X, int Y, int Dis)
{
	if (X >= 0 && X < dim_x && Y >= 0 && Y < dim_y)
	if (!topo[X][Y].forbid && topo[X][Y].dis > Dis)
	{
		topo[X][Y].dis = Dis;
		search(X+1,Y,Dis+1);
		search(X-1,Y,Dis+1);
		search(X,Y+1,Dis+1);
		search(X,Y-1,Dis+1);
	}
}

void map :: print()
{
	for(auto& m1 : topo)
	{
		for(auto& m2 : m1)
		{
			if (m2.dis == -1)
			{
				if (m2.forbid == 1)
					cout<<setw(4)<<"[]";
				else
					cout<<setw(4)<<"xx";
			}
			else
				if (m2.dis < 10)
					cout<<setw(3)<<'0'<<m2.dis;
				else
					cout<<setw(4)<<m2.dis;
		}
		cout<<endl<<endl;
	}
}
