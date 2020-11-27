#include<bits/stdc++.h>

using namespace std;

bool intersects(int l1, int r1, int l2, int r2){
    if(r2<l1 || l2>r1)
        return false;
    return true;
}

int main(){
    int t,n,x,m,l,r;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>x>>m;
        int mini=-1,maxi=-2;
        for(int j=0;j<m;j++){
            cin>>l>>r;
            if(x>=l && x<=r){
                if(mini==-1)
                {
                    mini=l;
                    maxi=r;
                }else{
                    if(intersects(mini,maxi,l,r)){


                        mini=min(mini,l);
                        maxi=max(maxi,r);
                    }
                }
            }else{
                if(mini!=-1){
                    if(intersects(mini,maxi,l,r)){


                        mini=min(mini,l);
                        maxi=max(maxi,r);
                    }
                }
            }
        }

        int ans=(mini==-1)?1:maxi-mini+1;
        cout<<ans<<"\n";
    }
    return 0;
}
