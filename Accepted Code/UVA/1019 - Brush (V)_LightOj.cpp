#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <cctype>
#include <algorithm>
#include <bitset>
#include <set>
using namespace std;

vector<int>gp[5000],cost[5000];
struct node
{
    int u,w;
    node(int a,int b){ u =a; w=b;}
    bool operator <(const node &p)const{ return w>p.w;}
};
int distanc[50005];
int  bfs(int source,int termnt)
{
    for(int i=0;i<=termnt;i++)
        distanc[i]=25000;
    priority_queue<node>q;

    q.push(node(source,0));
    distanc[source] = 0;
    while(!q.empty())
    {
        node top = q.top();
        q.pop();
        int u = top.u;
        if(u ==termnt)
        {
            while(!q.empty())
                q.pop();
            return distanc[u];
        }
        for(int i = 0;i<gp[u].size();i++)
        {
            int v = gp[u][i];
            if(distanc[u]+cost[u][i]<distanc[v])
            {
                distanc[v] = distanc[u]+cost[u][i];
                q.push(node(v,distanc[v]));
            }
        }
    }
    return -1;
}
int main()
{
    int aa;
    cin>>aa;
    for(int test =1;test<=aa;test++)
    {
        int n,e;
        cin>>n>>e;
        for(int i=0;i<e;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            gp[u].push_back(v);
            gp[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }
        int s;

        int ret = bfs(1,n);
        cout<<"Case "<<test<<": ";
        if(ret == -1)
            cout<<"Impossible"<<endl;
        else
            cout<<ret<<endl;
        for(int i=0;i<=101;i++)
        {
            gp[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}
