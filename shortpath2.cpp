/*************************************************************************
	> File Name: shortpath2.cpp
	> Author: YeGuoSheng
	> Description:  For A weighted graph with n vertices, the adjacency matrix is represented by A, 
	and the branch and bound method is used to calculate the value of the graph from the starting point S to the target T
Shortest paths. And the number of paths with the shortest path length
> Created Time: Sunday, May 19, 2019 19:34.42
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
#define MAX 20
int n = 5;
int S;
int T;
int arr[MAX][MAX] ={
	{0,1,4,INF,INF,},
	{INF,0,INF,8,4},
	{INF,INF,0,INF,1},
	{INF,INF,2,1,6},
	{INF,INF,INF,INF,INF}
};
int bestlen = INF;
int ans = 0;

struct NodeType
{
	int no;
	int length;
	bool operator <(const NodeType &s)const
	{
		return length > s.length;
	}
};

void bfs(int S,int T)
{
	NodeType e;
	NodeType e1;
	e.length =  0;
	e.no = S;
	priority_queue<NodeType>qu;
	qu.push(e);
	while(! qu.empty())
	{
		e = qu.top();
		qu.pop();
		if(e.no == T)
		{
			if(e.length < bestlen)
			{
				ans = 1;
				bestlen = e.length;
			}
			else if(e.length == bestlen)
			{
				ans ++;
			}
		}
		else
		{
			for(int j = 0 ; j < n ; j ++)
			{
				if(arr[e.no][j]  != INF && arr[e.no][j] !=0)
				{
					if(e.length + arr[e.no][j] < bestlen)
					{
						e1.no = j;
						e1.length = e.length + arr[e.no][j];
						qu.push(e1);	
					}
				}
			}
		}
	}
}

void Add(int i,int j,int w)
{	
	arr[i][j] = w;
}

int main()
{
	S = 0;
	T = 4;
	bfs(S,T);
	cout<<bestlen<<" "<<ans<<endl;
    return 0;
}
