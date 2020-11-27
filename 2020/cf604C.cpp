#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        int p[n];
        int ctr=0;
        for(int j=0;j<n;j++){
            cin>>p[j];
        }
        int prev=-1;
        int save=-1;
        vector<int> grps;
        for(int j=0;j<n;j++){
            if(p[j]!=prev){
                grps.push_back(1);
            }else{
                grps[grps.size()-1]++;
            }
            prev=p[j];
        }
        ctr=grps.size();
        ctr--;
        if(ctr<3){
            cout<<"0 0 0\n";
        }else{
            int g=grps[0];
            int last=ctr-1;
            int sm=0;
            int cumlGrp[n];
            for(int j=0;j<grps.size();j++){
                sm=sm+grps[j];
                cumlGrp[j]=sm;
            }
            int sl=0,pl=0;
            int cnt=0;
            int k=last;
            pl=grps[k];
            for(int j=last;j>1;j--){
                if(j!=last)
                pl=pl-grps[j+1];

                while(k>1 && pl<=g){
                    k--;
                    pl=pl+grps[k];
                }

                sl=cumlGrp[k-1]-g;

                if(g<sl && g<pl && (g+sl+pl)<=n/2){
                    cnt=1;
                    cout<<g<<" "<<sl<<" "<<pl<<"\n";
                    break;
                }
            }
            if(cnt==0){
                cout<<"0 0 0\n";
            }
        }
    }
    return 0;
}
