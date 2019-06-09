/*************************************************************************
	> File Name: clotharrange2.cpp
	> Author: YeGuoSheng
	> Description:  
	> Created Time: 2019年05月14日 星期二 21时34分45秒
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
/*
 (1) node expansion: outgoing node e, if e is the target node, i.e., leaf node, save the length of the shortest path to bestlen and the shortest path to bestpath by comparing path length
If e is not the target, then search around
(2) pruning, since the length of each square is increased by 1. If we go from e to any valid node e1, then we have e.logth + 1 >= bestlen, which is the deadlock point
*/

#define INF 0x3f3f3f3f
#define MAXQ 101
#define MAXN 10
#define MAXM 10
int H[4] = {0,1,0,-1};
int V[4] = {-1,0,1,0};

struct Position
{	
	int x;
	int y;
	Position(){}
	Position(int i,int j)
	{
		x = i;
		y = j;
	}
};

int n  = 7;
int m  = 7;
int grid[MAXN][MAXM] ={
	{0,0,1,1,0,0,0},
	{0,0,0,1,0,0,0},
	{0,0,0,0,1,0,0},
	{0,0,0,1,1,0,0},
	{1,0,0,0,1,0,0},
	{1,1,1,0,0,0,0},
	{1,1,1,0,0,0,0}
};
Position a(2,1),b(3,5);
int bestlen = INF; 
vector<Position>bestpath;
int Count = 0;

//queue
typedef struct
{
	int no;//the node's index in queue
	Position p;//curent node ( x，y)
	int length;//curent length 
	int pre;//The subscript of the precursor of the current node in the queue

}NodeType;

class QUEUE//
{
private:
	NodeType data[MAXQ];
	int front;
	int rear;

public:
	QUEUE()
	{
		front = rear = -1;
	}
	bool empty()
	{
		return front == rear;
	}

	void push(NodeType e)
	{
		rear ++;
		data[rear] = e;
	}
	NodeType pop()
	{
		front ++;
		return data[front];
	}

	void GetPath(int s,vector<Position> &path)
	{
		int k = s;
		while( k != -1)
		{
			path.push_back(data[k].p);
			k = data[k].pre;
		}
	}
};

void Solve()
{
	NodeType e,e1;
	Position p,p1;
	QUEUE qu;
	e.no = Count++;
	e.pre = -1;
	e.p = a;
	e.length = 0;
	qu.push(e);
	while(! qu.empty())
	{
		e = qu.pop();
		p = e.p;
		if( p.x == b.x && p.y == b.y)
		{
			if(e.length < bestlen)
			{
				bestlen = e.length;
				bestpath.clear();
				qu.GetPath(e.no,bestpath);
			}
		}
		else
		{
			for(int j = 0; j < 4 ; j++)
			{
				p1.x = p.x + H[j];
				p1.y = p.y + V[j];
				if(p1.x >=0 && p1.y >= 0 && p1.x <n && p1.y < m && grid[p1.x][p1.y] == 0)
				{
					if(e.length + 1 < bestlen)
					{
						e1.no = Count++;
						e1.length =e.length + 1;
						e1.pre = e.no;
						e1.p = p1;
						qu.push(e1);
						grid[p1.x][p1.y] = -1;
					}
				}
			}
		}
	}
}


int main()
{
	Solve();
	cout<<"best solution:"<<endl;
	cout<<"min length :"<<bestlen<<endl;
	vector<Position>::reverse_iterator it;
	for(it = bestpath.rbegin();it != bestpath.rend();it++ )
	{
		cout<<" [ "<<it->x <<","<<it->y <<" ] ";
	}
	cout<<endl;
    return 0;
}
