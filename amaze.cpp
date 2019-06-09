/*************************************************************************
	> File Name: Amaze.cpp
	> Author: YeGuoSheng
	> Description:  Magicping To save Amaze, he will die if he meets king kong or be bitten twice by a dog
	p : Magicping
	a : Amaze
	r : Road
	k : King kong
	d : Dog
	Simple:
	4
	3
	pkk rrd rds
	3
	prr kkk rra
	4
	prr rrrr rrrr arrrr
	5
	prrrr ddddd ddddd rrrrr rrrra
	Output:
	Yes
	No
	Yes
	No
	> Created Time: Wednesday, May 15, 2019 at 21:01:02
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
#define MAX 31

int simplenum;
int n;
char Map[MAX][MAX];
int visted[MAX][MAX];
int px,py;
int ax,ay;
int bite;
int H[4] = {0,1,0,-1};
int V[4] = {-1,0,1,0};

struct Position
{
	/* data */
	int x;
	int y;
	int length;
	double lb;
	bool operator < (const Position & e)const
	{
		return lb > e.lb;
	}
};

void Bound(Position &e)
{
	double d = sqrt ((e.x - ax) * (e.x - ax) + (e.y - ay) * (e.y - ay));
	e.lb = e.length + d;
}

void SetMap()
{
	for(int i = 0 ;i < n ;i ++)
	{
		for(int j =0 ;j  < n;j ++)
		{
			cin>>Map[i][j];
			if(Map[i][j] == 'p')
			{
				px = i;
				py = j;
			}
			if(Map[i][j] == 'a')
			{
				ax = i;
				ay = j;
			}	
		}
	}
	memset(visted,0,sizeof(visted));
}


bool bfs()
{
	priority_queue<Position> qu;
	Position p;
	p.x = px;
	p.y = py;
	p.length = 0;
	Bound(p);
	visted[px][py] = 1;
	Position p1;
	Position p2;
	qu.push(p);
	while( ! qu.empty())
	{
		p = qu.top();
		qu.pop();
		if(p.x == ax && p.y == ay)
		{
			return true;
		}
		for(int k = 0; k < 4; k++ )
		{
			p1.x = p.x + H[k];
			p1.y = p.y + V[k];
			if(p1.x < 0 || p1.y < 0 || p1.x >= n || p1.y >= n)
			{
				continue;
			}
			if(visted[p1.x][p1.y])
			{
				continue;
			}
			if(Map[p1.x][p1.y] == 'k')
			{
				continue;
			}
			if(Map[p1.x][p1.y] == 'r' || Map[p1.x][p1.y] =='a')
			{
				p1.length = p.length + 1;
				Bound(p1);
				visted[p1.x][p1.y] = 1;
				qu.push(p1);
			}
			else if(Map[p1.x][p1.y] =='d')
			{
				if(bite == 0)
				{
					p1.length = p.length + 1;
					Bound(p1);
					visted[p1.x][p1.y] = 1;
					qu.push(p1);
					bite ++;
				}
			}
		}
	}
	return false;
}

int main()
{
	cin>>simplenum ;
	while(simplenum --)
	{
		bite = 0;
		cin>>n;
		SetMap();
		if(bfs())
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}
		
	}
    return 0;
}
