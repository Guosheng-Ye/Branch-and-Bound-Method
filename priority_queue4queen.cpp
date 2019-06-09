/*************************************************************************
	> File Name: priority_queue4queen.cpp
	> Author: YeGuoSheng
	> Description:  
	> Created Time: Wednesday, May 15, 2019 05:11:33
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

int n = 4;
int Count = 1;

struct NodeType
{
	int no;
	int row;
	vector<int>cols;// Store the queen's column number
	bool operator < (const NodeType &s)const
	{
		return row < s.row;//The bigger the row, the better
	}
};

void DispNodes(NodeType e)
{
	if(e.row != -1)
	{
		cout<<"num "<<e.no<<" position :" <<"( "<<e.row<<", "<<e.cols[e.row]<<" )"<<endl;
	}
	else
	{
		cout<<"num "<<e.no<<" position :" <<"( "<<e.row<<", "<<" *  )"<<endl;
	}
}

bool Valid(vector<int >cols,int i,int j)
{
	int k = 0;
	while(k < i)
	{
		if( (cols[k])== j || (abs(cols[k]-j)) == abs(k - i) )
		{
			return false;
		}
		k++;
	}
	return true;
}

void Solve()
{
	int i,j;
	NodeType e,e1;
	priority_queue<NodeType> qu;
	e.no = Count++;
	e.row = -1;
	qu.push(e);
	cout<<"push ";
	DispNodes(e);
	while( ! qu.empty())
	{
		e = qu.top();
		qu.pop();
		cout<<"pop:";DispNodes(e);
		if(e.row == n - 1)//leaf node
		{
			cout<<"one solution:";
			for(i = 0; i < n ;i++)
			{
				cout<<"[ "<<i+1<<" , "<<e.cols[i] + 1<<" ]";
			}
			cout<<endl;
			return;
		}
		else
		{
			for(j = 0; j < n ; j++)//all col
			{
				i = e.row + 1;//Check the I queen
				if(Valid(e.cols,i,j))//Extend all children of node e that do not conflict with queens
				{
					e1.no = Count++;
					e1.row = i;
					e1.cols = e.cols;
					e1.cols.push_back(j);
					qu.push(e1);
					cout<<"push subnode:";DispNodes(e1);
				}
			}
		}
	}
}
int main()
{
	cout<<"Solution:"<<endl;
	Solve();
    return 0;
}
