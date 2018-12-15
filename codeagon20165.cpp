#include <stdio.h>
#include<iostream>
#include <limits.h>

#define V 1001

using namespace std;

int minDistance(int dist[], bool sptSet[])
{
   int min = INT_MAX, min_index;

   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;

   return min_index;
}


void dijkstra(int graph[V][V], int taxi[V][V], int src, int ans)
{
     int dist[V];     // The output array.  dist[i] will hold the shortest
                      // distance from src to i

     bool sptSet[V]; // sptSet[i] will true if vertex i is included in shortest
                     // path tree or shortest distance from src to i is finalized


int d[V];
int t[V];
     for (int i = 0; i < V; i++)
    {
        t[i]=0;
        d[i]=0;
        dist[i] = INT_MAX, sptSet[i] = false;
    }

     dist[src] = 0;

     for (int count = 0; count < V-1; count++)
     {
       int u = minDistance(dist, sptSet);

       sptSet[u] = true;

       for (int v = 0; v < V; v++)
       {
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                                       && dist[u]+graph[u][v] < dist[v])
        {
            if(dist[u]-t[u]+d[u]+taxi[u][v]<dist[u] + graph[u][v])
            {
                t[v]=taxi[u][v];
                d[v]=graph[u][v];
            }
            else
                dist[v] = dist[u] + graph[u][v];
        }
       }
     }

     cout<<dist[ans];
}

// driver program to test above function
int main()
{
   /* Let us create the example graph discussed above */
   int i,j,t,m,x,y,r,s;
    int n;
   cin>>n;
   for(i=0;i<t;i++)
   {

        int graph[1001][1001]={0},taxi[1001][1001]={0};
       cin>>n>>m;
       for(j=0;j<m;j++)
       {
           cin>>x>>y>>r>>s;
           graph[x][y]=r;
           taxi[x][y]=s;
       }

       cin>>r>>s;
        dijkstra(graph,taxi, r,s);
   }
    return 0;
}
