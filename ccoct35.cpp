#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
using namespace std;
int main(){
    int i,t,j,n,m;
    vector<pair<int,int> >::iterator it,save;
    vector< pair<int,int> > v;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        v.clear();
        scanf("%d%d",&n,&m);
        long long int p=1;
        char x;
        int y;
        for(j=0;j<m;j++){
            cin>>x>>y;
            v.push_back(make_pair(y,(int)x));
        }
        sort(v.begin(),v.end());
        it=v.begin();
        save=it;
        it++;
        while(it!=v.end())
        {
            if(it->second!=save->second)
            {
                p=((p*(it->first-save->first)%1000000009))%1000000009;
            }
            save=it;
            it++;
        }
        printf("%lld\n",p);
    }
    return 0;
}
