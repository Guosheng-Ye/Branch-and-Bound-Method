/*************************************************************************
	> File Name: hungry.cpp
	> Author: YeGuoSheng
	> Description:  Small yi in the initial position x_0, for the current position x, she can only move to by mysterious force
4 * x + 3 or 8 * x + 7. She can move up to 100,000 times. The target is in the divisible position of 1,000,000 007
(0, 1 million, 0007, 2 million, 014) please help him calculate the minimum number of times to the target position
Input:(x_0 (1 ~ 1,000,000 006)) if not output -1;
125000000
1
	> Created Time: Wednesday, May 15, 2019 at 21:41:51
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

long  x;
const long  MOD  = 1000000007L;
struct Position
{
	long  x;
	int num;
};

int  bfs()
{
	queue<Position> qu;
	Position p;
	Position p1;
	p.x = x;
	p.num = 0;
	qu.push(p);
	while(!qu.empty())
	{
		p = qu.front();
		qu.pop();
		if( p.x == 0)
			return p.num;
		if(p.num < 1000000)
		{
			p1.x = (p.x * 4 + 3 )  % MOD;
			p1.num = p.num + 1;
			qu.push(p1);
			p1.x = (p.x * 8 + 7) % MOD;
			p1.num = p.num + 1;
			qu.push(p1);
		}
	}
	return -1;
}
int main()
{
	while(cin>>x) 
	{
		cout<<bfs()<<endl;
	}
    return 0;
}
