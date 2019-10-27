#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include "path_search.h"

using namespace std;

int main()
{
	map m;
	vector< vector<int> > block;
	int num_block;
	int x,y;
	ifstream input;
	string tmp;

	input.open("block.dat");
	num_block = 0;
	while(getline(input,tmp))
		num_block++;
	input.clear(); input.seekg(ios::beg);
	block.resize(num_block);
	for(auto& m1:block)
	{
		m1.resize(2);
		input>>x>>y;
		m1[0] = x;
		m1[1] = y;
	}

	m.init(10,20);
	m.search_run(block,1,3,0,0);
	m.print();
}
