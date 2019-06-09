/**
 * @FileName : Minimum number of translations
 * @Description :
 3 2
 0 1
 1 2
 2
 0 0
 0 2
 0
 1
 * @Author : Yeguosheng
 * @Date :
 */
#include<iostream>
#include<queue>
using namespace std;
#define MAX 20

int n;
int m;
int k;
int arr[MAX][MAX] ={0};
int visted[MAX]={0};

struct node
{
    int vno;
    int length;
};

void SetArr()
{
    int x,y;
    for(int i = 1;i <= m ;i++)
    {
        cin>>x>>y;
        arr[x][y] = arr[y][x] = 1;
    }
}

int  bfs(int S,int E)
{
    if(S == E) return 0;
    node e;
    node e1;
    queue<node> qu;
    e.vno = 0;
    e.length = 0;
    visted[e.vno] = 1;
    qu.push(e);

    while(!qu.empty())
    {
        e = qu.front();
        qu.pop();
        if(e.vno == E)
        {
            return e.length - 1;
        }
        else
        {
            for(int z = 0; z < n; z++)
            {
                if(arr[e.vno][z] != 0)
                {
                    if(visted[z] == 0)
                    {
                        e1.vno = z;
                        e1.length = e.length +1;
                        qu.push(e1);
                        visted[z] = 1;
                    }
                }
            }
        }
    }
    return -1;
}

int main()
{
    cin>>n;
    cin>>m;
    SetArr();
    cin>>k;
   for(int i = 1;i <= k ;i++)
   {
       int S;
       int E;
        cin>>S>>E;
        bfs(S,E);
   }
    return 0;
}
