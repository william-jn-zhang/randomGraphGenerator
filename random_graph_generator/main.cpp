/**@file   
 * @brief  
 * @author william-jn-zhang
 *
 * 
 */

#include <string.h>
#include <random>
#include <iostream>
#include <fstream>
using namespace std;

#define NODE_NUM 20
#define RAND_THRESHOLD 0.3

int main()
{
	int* p = NULL;
	p = new int[NODE_NUM * NODE_NUM];
	memset(p, 0, NODE_NUM * NODE_NUM * sizeof(int));
	int (*adj_mat)[NODE_NUM] = (int (*)[NODE_NUM])p;

	srand(65535);

	cout << RAND_MAX << endl;

	double r = 0.0;

	int nedge = 0;

	for(int i = 0; i < NODE_NUM; ++i)
	{
		for(int j = i + 1; j < NODE_NUM; ++j)
		{
			r = (double)rand() / (double)RAND_MAX;
			if(r < RAND_THRESHOLD)
			{
				adj_mat[i][j] = 1;
				++nedge;
			}
		}
	}

	ofstream out("result.epp");
	out << NODE_NUM << ' ' << nedge << endl;
	for(int i = 0; i < NODE_NUM; ++i)
	{
		for(int j = i + 1; j < NODE_NUM; ++j)
		{
			if(adj_mat[i][j] == 1)
			{
				out << j + 1 << ' ';
			}
		}
		out << endl;
	}
	out.close();

	return 0;
}