#include<bits/stdc++.h>

using namespace std;

#define gc getchar

long long int MAXL=1000000000;
long long int n;
long long int sx,sy;

inline long long int lscan()
{
long long int n=0,c=gc();
while(c<'0'||c>'9')
c=gc();
while(c<='9'&&c>='0'){
n=n*10+c-'0';
c=gc();}
return n;
}

bool isWithin(long long int studentCo, long long int swarmaCo, long long int schoolCo){
    long long int stuDist=studentCo - schoolCo;
    long long int swarmaDist=swarmaCo - schoolCo;

    if(stuDist<=0 && swarmaDist<=0){
        return swarmaDist>=stuDist;
    }
    if(stuDist>=0 && swarmaDist>=0){
        return swarmaDist<=stuDist;
    }
    return false;
}

long long int calStu(long long int x, long long int y, vector<pair<long long int,long long int> > p){
    long long int ctr=0;
    for(long long int i=0;i<n;i++){
        if(isWithin(p[i].first,x,sx) && isWithin(p[i].second,y,sy)){
            ctr++;
        }
    }
    return ctr;
}
int main(){
    n=lscan();
    sx=lscan();
    sy=lscan();
    long long int px,py;
    vector<pair<long long int,long long int> > p;
    for(long long int i=0;i<n;i++){
        px=lscan();
        py=lscan();
        p.push_back(make_pair(px,py));
    }
    long long int maxi=0,ansx=0,ansy=0;
    if(sx-1>=0){
        long long int stu=calStu(sx-1,sy,p);
        if(stu>=maxi){
            maxi=stu;
            ansx=sx-1;
            ansy=sy;
        }
    }
    if(sx+1<=MAXL){
        long long int stu=calStu(sx+1,sy,p);
        if(stu>=maxi){
            maxi=stu;
            ansx=sx+1;
            ansy=sy;
        }
    }
    if(sy-1>=0){
        long long int stu=calStu(sx,sy-1,p);
        if(stu>=maxi){
            maxi=stu;
            ansx=sx;
            ansy=sy-1;
        }
    }
    if(sy+1<=MAXL){
        long long int stu=calStu(sx,sy+1,p);
        if(stu>=maxi){
            maxi=stu;
            ansx=sx;
            ansy=sy+1;
        }
    }
    cout<<maxi<<"\n";
    cout<<ansx<<" "<<ansy;
    return 0;
}
