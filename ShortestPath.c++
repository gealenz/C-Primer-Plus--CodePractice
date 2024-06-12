#include <cstdio>
#include <iostream>
#include <cstring>
#include <windows.h>
#include <stack>
using namespace std;
const int N = 100;
const int INF = 1e7;
int map[N][N],dist[N],p[N],n,m;
bool flag[N];
void Dijkstra(int u)
{
	for(int i=1;i<n;i++)
	{
		dist[i] = map[u][i];
		flag[i]=false;
		if(dist[i]==INF)
			p[i]=-1;
		else
		 	p[i]=u;
	}
	dist[u] = 0;
	flag[u]=true;
	for(int i=1; i<n; i++)
	{
		int temp =INF,t = u;
		for(int j=1;j<=n;j++)
		{	
			if(!flag[j]&&dist[j]<temp)
			{
				t=j;
				temp=dist[j];
			}
			if(t==u) return ;
			flag[t]=true;
			for(int j=1;j<=n;j++)
			{
	 			if(!flag[j]&&map[t][j]<INF)
				{
					if(dist[j]>(dist[t]+map[t][j]))
					{
					dist[j]=dist[t]+map[t][j];
					p[j]=t;
					}
				}
			}
		}
	}
}

int main()
{
	int u,v,w,st;
	system("color 0d");
	cout<<"请输入城市的个数："<<endl;
	cin>>n;
	cout<<"请输入城市间的路线的个数："<<endl;
	cin>>m;
    cout<<"请输入城市间的路线和距离："<<endl;
	for(int i=1;i<n;i++)
		for(int j=1;j<=n;j++)
		{
			map[i][j]=INF;	
		}
	while(m--)
	{
		cin >> u >> v >> w;
		map[u][v] = min(map[u][v],w);
	}
	cout <<"请输入小明所在位置："<<endl;
	cin>>st;
	Dijkstra(st);
	cout <<"小明所在位置："<<st<<endl;
	for(int i =1;i<=n;i++)
	{
		cout<<"小明:"<<st<<" - "<<"要去位置："<<i<<endl;
		if(dist[i] == INF)
			cout<< "sorry,no path to get here,无路可达"<<endl;
	 	else
	 		cout<<"The stortest path is (最短路径):"<<dist[i]<<endl;
	}
	return 0;

}

