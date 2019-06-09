/*************************************************************************
	> File Name: clotharrange.cpp
	> Author: YeGuoSheng
	> Description:  Wiring problem	
	> Created Time: Tuesday, May 14, 2019, 15:29.30
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
int n;
int arr[MAX][MAX];
int H[4] = {0,1,0,-1};
int V[4] = {-1,0,1,0};
int x;
int y;
int a;
int b;

struct clotharrange
{
	/* data */
	int x;
	int y;
	int pre;
};
clotharrange qu[MAX];
int front = -1;
int rear = -1;

void setMap()
{
	for(int i = 0;i < n;i++)
	{
		for(int j = 0 ; j < n;j++)
		{
			cin>>arr[i][j];
		}
	}
}

void Disp(int front )
{
	for(int i = 0;i <n;i++)
	{
		for(int j = 0 ; j < n;j++)
		{
			if(arr[i][j] == 5)
			{
				arr[i][j] = 0;
			}
		}
	}
	int k = front;
	while(k != -1)
	{
		arr[qu[k].x][qu[k].y] = 8;
		k = qu[k].pre;
	}
	for(int i = 0;i <n;i++)
	{
		for(int j = 0 ; j < n;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}

}

void bfs(int x,int y,int a,int b)
{
	
	clotharrange p;
	clotharrange p1;
	clotharrange p2;
	p.x = x;
	p.y = y;
	p.pre = -1;
	rear ++;
	arr[p.x][p.y] = 5;
	qu[rear ] = p;
	while(front != rear)
	{
		front ++;
		p1 = qu[front];
	
		if(p1.x == a && p1.y == b)
		{
			Disp(front);
			return ;
		}
		for(int i = 0;i < 4; i++)
		{
			p2.x = p1.x + H[i];
			p2.y = p1.y + V[i];
			if(p2.x >= 0 && p2.y >=0 && p2.x <n && p2.y < n && arr[p2.x][p2.y] == 0 )
			{
				arr[p1.x][p1.y] = 5;
				p2.pre = front;
				rear ++;
				qu[rear] = p2;
			}
		}
	}

}


int main()
{
	memset(arr,0,sizeof(arr));
	cout<<"input the size of map:";
	cin>>n;
	setMap();
	cout<<"input the start position:";
	cin>>x>>y;
	cout<<"input the target positon:";
	cin>>a>>b;
	bfs(x,y,a,b);
    return 0;
}
