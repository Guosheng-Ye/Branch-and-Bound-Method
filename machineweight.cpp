/**
 * @FileName :
 * @Description :
 * @Author : Yeguosheng
 * @Date :
 3 3 7
 1 2 3
 3 2 1
 2 3 2
 1 2 3
 5 4 2
 2 1 2

 1 3 1
 4

 */

#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

#define MAX 20
#define INF 0x3f3f3f3f
int N;
int M;
int cost;
int w[MAX][MAX];
int c[MAX][MAX];

typedef struct
{
    int no;
    int i;
    int w;
    int c;
    int x[MAX];
    int y[MAX];
}Node;


struct Cmp
{
    bool operator ()(const Node &s,const Node &t)
    {

        return (s.w > t.w) || (s.w == t.w && s.c > t.c);
    }
};

int bestw = INF;
int bestc = INF;
int bestx[MAX];
int Count = 1;

void bfs()
{
    Node e;
    Node e1;
    priority_queue<Node,vector<Node>,Cmp> qu;
    e.no = Count++;
    e.i = 0;
    e.w = 0;
    e.c = 0;
    memset(e.x,0,sizeof(e.x));
    memset(e.y,0,sizeof(e.y));
    qu.push(e);
    while( !qu.empty())
    {
        e = qu.top();
        qu.pop();
        if(e.i == N)
        {
            if(e.c <= cost && e.c < bestc && e.w < bestw)
            {
                bestw = e.w;
                bestc = e.c;
                for(int j = 1; j<= N;j++)
                {
                    bestx[j] = e.x[j];
                }
            }
        }
        else
        {
            for(int j = 1; j <= M;j++)
            {
                if(e.y[j] == 0)
                {
                    if(e.c + c[e.i+1][j] <= cost && e.w + w[e.i+1][j] < bestw && e.c + c[e.i+1][j] < bestc)
                    {
                        e1.no = Count++;
                        e1.i = e.i + 1;
                        e1.w = e.w  + w[e1.i][j];
                        e1.c = e.c + c[e1.i][j];
                        for(int k = 1;k <= N; k++)
                        {
                            e1.x[k] = e.x[k];
                        }
                        for(int k1 = 1; k1 <= N;k1 ++)
                        {
                            e1.y[k1] = e.y[k1];
                        }
                        e1.x[e1.i] = j;
                        e1.y[j] = 1;
                        qu.push(e1);
                    }
                }
            }
        }
    }
}

int main()
{
    cin>>N>>M>>cost;
    for(int i = 1;i <= N;i++)
    {
        for(int j = 1;j <= M ;j++)
        {
            cin>>w[i][j];
        }
    }
    for(int i = 1;i <= N;i++)
    {
        for(int j = 1;j <= M ;j++)
        {
            cin>>c[i][j];
        }
    }
    bfs();
    cout<<endl;
    for(int i = 1;i <= N;i++)
    {
        cout<<bestx[i]<<" ";
    }
    cout<<endl<<bestw<<endl;
    return 0;
}
