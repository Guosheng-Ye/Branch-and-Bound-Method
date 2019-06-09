/*************************************************************************
	> File Name: hungry2.cpp
	> Author: YeGuoSheng
	> Description:  
	> Created Time: 2019年05月15日 星期三 22时16分59秒
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

int  bfs(long x)
{
	if(x < 1 || x > 10000000006L)
	{
		return -1;
	}
	x %= MOD;
	queue<long >qu;
	map<long,int >mymap;
	qu.push(x);
	mymap[x] = 0;
	while( ! qu.empty())
	{
		long e = qu.front();
		qu.pop();
		if(e == 0)
		{
			return mymap[e];
		}
		if( mymap[e] <= 100000)
		{
			
			long x1 = (4 * e + 3) % MOD;
			if(mymap.find(x1) == mymap.end())
			{
				mymap[x1] = mymap[x] + 1;
				qu.push(x1);
			}
			long x2 = (8 * e + 7) % MOD;
			if(mymap.find(x2) == mymap.end())
			{
				mymap[x2] = mymap[x] + 1;
				qu.push(x2);
			}	
		}
	}
}
int main()
{
	while(cin>>x) 
	{
		cout<<bfs(x)<<endl;
	}
    return 0;
}
