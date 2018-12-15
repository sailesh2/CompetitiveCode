#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<string>
#include<math.h>


using namespace std;
int ctr,save,save2;

int maxi=0;

map<pair<int,int>,pair<int,int> > has;
map<pair<int,int>,pair<int,int> >::iterator hasIt;
void findCount(int a,int b, int c, int i){
        int s,v;


        hasIt=has.find(make_pair(a,b));
        if(hasIt==has.end()){
            if(min(a,min(b,c))>maxi){
                maxi=min(a,min(b,c));
                ctr=1;
                save=i;
            }
            has.insert(make_pair(make_pair(a,b),make_pair(c,i)));
        } else{
            v=(hasIt->second).first;
            s=(hasIt->second).second;

            if(s!=i){
                if(min(a,min(b,c+v))>maxi){
                    maxi=min(a,min(b,c+v));
                    ctr=2;
                    save=i;
                    save2=(hasIt->second).second;
                }

            }

            if(c>v){
                has.erase(hasIt);
                has.insert(make_pair(make_pair(a,b),make_pair(c,i)));
            }
        }

}

int main(){
    int n;
    int a,b,c;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;

        findCount(a,b,c,i);
        findCount(b,a,c,i);
        findCount(a,c,b,i);
        findCount(c,a,b,i);
        findCount(b,c,a,i);
        findCount(c,b,a,i);
    }
    if(ctr==1)
        cout<<ctr<<"\n"<<save+1;
    else
        cout<<ctr<<"\n"<<save+1<<" "<<save2+1;
    return 0;
}
