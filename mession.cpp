/*************************************************************************
	> File Name: mession.cpp
	> Author: YeGuoSheng
	> Description: task assignment problem
	> Created Time: Monday, May 13, 2019 at 20:58:33
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<list>
#include<queue>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX 21

int n = 4;
int c[MAX][MAX] ={ {0},{0,9,2,7,8}, {0,6,4,3,7},{0,5,8,1,8} , {0,7,6,9,4}};

int bestx[MAX];
int mincost = INF;
int total = 1;

struct mession
{
	int no;
	int i;
	int x[MAX];
	bool worker[MAX];
	int cost;
	int lb;
	bool operator < (const mession &s)const
	{
		return lb > s.lb; 
	}
};

void Bound(mession &e)
{
	int minsum = 0;
	for(int t = e.i + 1;t <= n; t++)
	{
		int mine = INF;
		for(int j = 1;j <= n;j ++)
		{
			if(e.worker[j] == false  && c[t][j] < mine)
			{
				mine = c[t][j];
			}
		}
		minsum += mine;
	}
	e.lb = e.cost + minsum;
}

void bfs()
{
	int j ;
	mession e,e1;
	priority_queue<mession> qu;
	memset(e.x,0,sizeof(e.x));
	memset(e.worker,0,sizeof(e.worker));
	e.i = 0 ;
	e.cost = 0;
	Bound(e);
	e.no = total ++;
	qu.push(e);
	while(!qu.empty())
	{
		e = qu.top();
		qu.pop();
		if(e.i == n)
		{
			if(e.cost < mincost)
			{
				mincost = e.cost;
				for(int i = 1; i <= n;i ++)
				{
					bestx[i] = e.x[i];
				}
			}
		}
		e1.i = e.i + 1;
		for( j = 1; j <= n ;j++)
		{
			if(e.worker[j] == true)  continue;
			for(int i1 = 1;i1 <= n;i1++)
			{
				e1.x[i1] = e.x[i1];
			}
			e1.x[e1.i]  = 1;
			for(int i2 = 1; i2 <= n ;i2++)
			{
				e1.worker[i2] = e.worker[i2];
			}
			e1.worker[e1.i] = true;
			e1.cost = e.cost + c[e1.i][j];
			Bound(e1);
			e1.no = total ++;
			if(e1.lb < mincost)
			{
				mincost = e1.lb;
			}
		}
	}
}

int main()
{
	bfs();
	cout<<" min cost:"<<mincost<<endl;
	for(int i =1 ;i <= n;i ++)
	{
		cout<<"people "<<i<<" mession:"<<bestx[i]<<endl;
	}


    return 0;
}
