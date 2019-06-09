/*************************************************************************
	> File Name: priorityBox.cpp
	> Author: YeGuoSheng
	> Description:  Priority queue branch bounds are used to obtain the optimal loading. N: 5,w = 5,2,6,4,3.
W = 10; The optimal loading scheme with the same loading weight is the one with the least number of containers
	> Created Time: fri May 17, 2019 22:47:36
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
int n = 5;
int W = 10;
int w[] = {0,5,2,6,4,3};
int bestw = 0;
int best[MAX] = {0};
int Count = 1;

typedef struct priorityBox
{
	/* data */
	int i;
	int no;
	int w;
	int x[MAX];
	int ub;
}NodeType;

struct Cmp
{
	/* data */
	bool operator () (const NodeType &s1,const NodeType & s2) 
	{
		return (s1.ub < s2.ub) || (s1.ub == s2.ub && s1.x[0] > s2.x[0]);
	}
};

void Bound(NodeType &e)
{
	int i = e.i+1;
	int p = 0;
	while( i <= n)
	{
		p += w[i];
		i++;
	}
	e.ub = p + e.w;
}


void bfs()
{
	NodeType e;
	NodeType e1;
	NodeType e2;
	e.i = 0;
	e.no = Count++;
	e.w = 0;
	for(int i = 0; i <= n;i++)
	{
		e.x[i] = 0;
	}
	Bound(e);
	priority_queue<NodeType,vector<NodeType>,Cmp> qu;
	qu.push(e);

	while( !qu.empty())
	{
		e = qu.top();
		qu.pop();
		if(e.i == n)
		{
			if(e.w > bestw ||(e.w==bestw && e.x[0] < best[0]))
			{
				bestw = e.w;
				for(int j = 0; j<= e.i;j ++)
				{
					best[j] = e.x[j];
				}
			}
		}
		else
		{
			if(e.w + w[e.i + 1] <= W)
			{
				e1.no = Count++;
				e1.i = e.i +1 ;
				e1.w = e.w + w[e1.i];
				for(int j = 0;j <= e.i ;j ++)
				{
					e1.x[j] = e.x[j];
				}
				e1.x[e1.i] = 1;
				e1.x[0] ++;
				Bound(e1);
				qu.push(e1);
			}
			e2.no = Count++;
			e2.i = e.i + 1;
			e2.w = e.w;
			for(int j = 0;j <= e.i ;j++)
			{
				e2.x[j] = e.x[j];
			}
			e2.x[e2.i] = 0;
			Bound(e2);
			if(e2.ub > bestw)
			{
				qu.push(e2);
			}
		}
	}
}

void DispArr(int x[],int length)
{
	for(int i = 1;i <= length; i++)
	{
		cout<<x[i]<<" ";
	}
}

void Disp()
{
	cout<<"[";
	DispArr(best,n);
	cout<<"]"<<"sun value :"<<bestw<<endl;
}


int main()
{
	bfs();
	Disp();
    return 0;
}
