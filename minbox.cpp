/*************************************************************************
	> File Name: 6-6-10.cpp
	> Author: YeGuoSheng
	> Description:  Optimal loading problem, n = 5,w = {5,2,6,4,3} w = 10. Given at the same load
The least number of containers
	> Created Time: Tuesday, May 14, 2019, 15:04:07
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
int n = 0;
int W = 0;
int w[MAX] ;
int sumw = 0;
struct minbox
{
	/* data */
	int i;//layer
	int ub;
	int weight;//pre weight
	int x[MAX];
	bool operator <(const minbox &s)const
	{
		return ub > s.ub;
	}
};

void bound(minbox & e)
{
	int prew = e.weight;
	int rw = sumw - prew;
	int num = 0;
	for(int i = e.i + 1;i<=n;i++)
	{
		if(rw - w[i] > 0)
		{
			++num;
			rw -= w[i];
		}
	}
}

int main()
{
 
    return 0;
}
