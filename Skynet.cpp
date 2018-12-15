/*
Name : sailesh kumar upadhyaya
Brief description of algorithm :

Algorithm used is Disjoint set algorithm
steps:
    1.make groups of connected robots which are of same design
    2.make connected robots by marking the parent of one of the same robot to other
    3.if one of the same robot already belongs to some group, then mark the other robot's parent as the first robot group
    4.if both the robots belong to some group, then recursively calculate the height of the groups, make the parent of smaller height point to bigger group.
    5.count the robots of each group.
    6.the robots which are not part of any group, make their count as 1 as individual group.
    7.calculate the result by sum of (number of robots of each group)*(remaining no of robots apart from that group)
    8.return the result.
*/

#include <iostream>

#define MAXN 100000
#define MAXP 100000

using namespace std;

typedef unsigned long ulong;

long long int CountNoOfWays(int N, int P, int pairs[][2])
{
    int i,a,b,heightA,heightB;
    long long int sm=0,result=0;
    int parent[N];
    int has[N];
    int counter[N];
    for(i=0;i<N;i++)
    {
        has[i]=0;
        parent[i]=-1;
        counter[i]=0;
    }

    for(i=0;i<P;i++)
    {
        a=pairs[i][0];
        b=pairs[i][1];


        heightA=0;
        heightB=0;

        while(parent[a]!=-1)
        {
            heightA++;
            a=parent[a];
        }
        while(parent[b]!=-1)
        {
            heightB++;
            b=parent[b];
        }

        if(a!=b)
        {
            if(heightA<=heightB)
            {
                parent[a]=b;
                if(has[a]==0)
                    counter[b]++;
                else
                    counter[b]=counter[b]+counter[a];
                if(has[b]==0)
                    counter[b]++;
                counter[a]=0;
            }
            else
            {
                parent[b]=a;
                if(has[b]==0)
                    counter[a]++;
                else
                    counter[a]=counter[a]+counter[b];
                if(has[a]==0)
                    counter[a]++;
                counter[b]=0;
            }
        }
        has[a]=1;
        has[b]=1;

    }

    for(i=0;i<N;i++)
    {
        if(has[i]==0)
            counter[i]=1;
    }
    for(i=0;i<N;i++)
    {
        sm=sm+counter[i];
    }
    for(i=0;i<N;i++)
    {
        result=result+(long long int)(counter[i]*(sm-counter[i]));
    }
    return result/2;
}

int main()
{
    int N, P;
    cin >> N >> P;
    int pairs[P][2];

    for(int i = 0; i < P; i++)
    {
        cin >> pairs[i][0] >> pairs[i][1];
    }

    cout << CountNoOfWays(N, P, pairs);
}
