/*************************************************************************
	> File Name: bag.cpp
	> Author: YeGuoSheng
	> Description:  by queue
	> Created Time: Monday, May 13, 2019 06:04:14
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

#define MAX 20
int n = 3;
int W = 30;
int w[] = {0,16,15,15};
int v[] = {0,45,25,25};
int maxv = -9999;
int total = 1;
int bestx[MAX]; 

struct NodeType
{
	int no;
	int i;
	int w;
	int v;
	int x[MAX];
	double ub;
};

void Bound(NodeType &e)
{
	int i = e.i + 1;
	int sumw = e.w;
	double sumv = e.v;
	while(sumw + w[i]<= W && i <= n)
	{
		sumw += w[i];
		sumv += v[i];
		i++;
	}
	if(i <= n)
	{
		e.ub = sumw + (W - sumw) * v[i] / w[i];
	}
	else
	{
		e.ub = sumv;
	}
}

void EnQueue(NodeType &e, queue<NodeType> & qu)
{
	if(e.i == n)
	{
		if(e.v > maxv)
		{
			maxv = e.v;
			for(int i = 1; i<= n;i++)
			{
				bestx[i] = e.x[i];
			}
		}
	}
	else
	{
		qu.push(e);
	}
}

void bfs()
{
	int j;
	NodeType e;
	NodeType e1;
	NodeType e2;
	queue <NodeType> qu;
	e.i = 0;
	e.w = 0;
	e.v = 0;
	e.no = total ++;
	for( j = 1 ;j <= n;j++ )
	{
		e.x[j] = 0;
	}
	Bound(e);
	qu.push(e);
	while(! qu.empty())
	{
		e = qu.front();
		qu.pop();
		if( e.w + w[e.i + 1] <= W)
		{
			e1.no = total ++;
			e1.i = e.i + 1;
			e1.w = e.w + w[e1.i];
			e1.v = e.v + v[e1.i];
			for(j = 1; j<= n;j++)
			{
				e1.x[j] = e.x[j];
			}
			e1.x[e1.i] = 1;
			Bound(e1);
			EnQueue(e1,qu);
		}
		e2.no = total++;
		e2.i = e.i +1;
		e2.w = e.w;
		e2.v = e.v;
		for(j = 1; j <= n; j++)
		{
			e2.x[j] = e.x[j];
		}
		e2.x[e2.i]  = 0 ;
		if(e2.v > maxv)
		{
			EnQueue(e2,qu);
		}
	}
}

int main()
{
	bfs();
	for(int i =1 ;i <= n ;i++)
	{
		cout<<bestx[i]<<" ";
	}
	cout<<endl;
	cout<<"max v:"<<maxv<<endl;
    return 0;
}
