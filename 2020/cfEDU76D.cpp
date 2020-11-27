#include<bits/stdc++.h>

using namespace std;

bool heroComp(pair<int,int> a, pair<int,int> b){
    if(a.first==b.first)
        return a.second>b.second;
    return a.first<b.first;
}

int findNextHero(int val, pair<int,int>* heros, int* suf, int m){
    int ctr=1;
    int save=-1;
    int save2=-1;

    while(1){
        while(save+ctr<m && heros[save+ctr].first<val){
            save2=save+ctr;
            ctr=ctr*2;
        }
        if(save==save2){
            break;
        }
        save=save2;
        ctr=1;
    }
    if(save+ctr>=m)
        return m+1;
    return suf[save+ctr];
}

int main(){
    int t,n,m,p,s;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;

        int monsters[n];
        for(int j=0;j<n;j++){
            cin>>monsters[j];
        }

        cin>>m;
        pair<int,int> heros[m];
        for(int j=0;j<m;j++){
            cin>>p>>s;
            heros[j]=(make_pair(p,s));
        }

        sort(heros,heros+m,heroComp);
        int suf[m];
        int maxi=0,saveI;
        for(int j=m-1;j>=0;j--){
            if(heros[j].second>maxi){
                maxi=heros[j].second;
                saveI=j;
            }else if(heros[j].second==maxi){
                if(heros[saveI].first<heros[j].first){
                    saveI=j;
                }
            }
            suf[j]=saveI;
        }
        int hI=0;
        int mI=0;
        int ctr=0,cnt=0;
        int d=0;
        hI=findNextHero(monsters[mI],heros,suf,m);
        while(hI<m){
            cnt=0;
            for(int j=mI;j<n;j++){
                if(heros[hI].first>=monsters[j]){
                    ctr++;
                }else{
                    mI=j;
                    cnt=1;
                    hI=findNextHero(monsters[mI],heros,suf,m);
                    if(hI<m && ctr>0 && heros[hI].second<=ctr){
                        ctr=0;
                        d++;
                    }
                    break;
                }
                if(ctr==heros[hI].second){
                    ctr=0;
                    d++;
                    if(j+1<n){
                        hI=findNextHero(monsters[j+1],heros,suf,m);
                        if(hI>=m){
                            cnt=1;
                            break;
                        }
                    }

                }
            }
            if(ctr>0 && cnt==0){
                ctr=0;
                d++;
            }

            if(cnt==0){
                break;
            }
        }

        if(cnt==1 || d==0)
            cout<<"-1\n";
        else
            cout<<d<<"\n";
    }

    return 0;
}
