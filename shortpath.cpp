/*************************************************************************
	> File Name: shortpath.cpp
	> Author: YeGuoSheng
	> Description:  The single source shortest path of the graph
	> Created Time: Sunday, May 12, 2019 22.31mins 21secs
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
#define INF 0x3f3f3f3f
int n;
int path[MAX][MAX];

struct  Node
{
	int vno;
	int length;
	bool operator <(const Node & s)const
	{
		return  length > s.length;
	}
};

int startnode;
int dist[MAX];
int pre[MAX];


void bfs(int startnode)
{
	Node e,e1;
	priority_queue<Node>qu;

	e.vno = startnode;
	e.length = 0;
	qu.push(e);
	dist[startnode] = 0;
	while(!qu.empty())
	{
		e = qu.top();
		qu.pop();

		for(int j = 0 ; j < n ; j++)
		{
			if(path[e.vno][j] < INF && e.length + path[e.vno][j] < dist[j])
			{
				dist[j] = e.length + path[e.vno][j] ;
				pre[j] = e.vno;
				e1.vno = j;
				e1.length = dist[j];
				qu.push(e1);
			}
		}
	}
}
void Add(int i,int j ,int w)
{
	path[i][j] = w;
}

void DispPath(int v,int i)
{
	vector<int >Path;
	if(v == i)return;
	if(dist[i] == INF)
	{
		cout<<v<<"  ->  "<<i<<" No path"<<endl;
	}
	else
	{
		int k = pre[i];
		Path.push_back(i);
		while (k != v)
		{
			Path.push_back(k);
			k = pre[k];
		}
		Path.push_back(v);
		cout<<v<<"  ->  "<<i<<" min path is :"<<dist[i]<<"  "<<"path ";
		for(int j = Path.size() - 1; j >= 0 ; j--)
		{
			cout<<Path[j]<< " ";
		}
		cout<<endl;
	}
}

void DispAllPath(int v)
{
	for(int i = 0 ; i< n; i++)
	{
		DispPath(v,i);
	}
}

int main()
{
	memset(dist,INF,sizeof(dist));
	memset(path,INF,sizeof(path));
	n = 6; 
	for(int i = 0 ; i<n;i++)
	{
		path[i][i] = 0;
	}
	Add(0,2,10);
	Add(0,4,30);
	Add(0,5,100);
	Add(1,2,4);
	Add(2,3,50);
	Add(3,5,10);
	Add(4,3,20);
	Add(4,5,60);
	startnode = 0;
	bfs(startnode);
	DispAllPath(startnode);
    return 0;
}
