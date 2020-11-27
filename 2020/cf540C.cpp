#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,tot;
    multiset<int> has;
    cin>>n;
    tot=n*n;
    int brr[tot];
    int mat[n][n];
    vector<int> arr;
    vector<int> oddarr;
    for(int i=0;i<tot;i++){
        cin>>brr[i];
    }

    sort(brr,brr+tot);
    int twos=0,maxTwo=2*(n/2);
    int ctr=1,cnt=0,last=0;
    for(int i=1;i<tot;i++){
        if(brr[i]==brr[i-1]){
            ctr++;
            last=i;
        }else{
            if(ctr%4!=0){
                //cout<<i<<"d";
                if(n%2!=0){
                    if(ctr%4==2){
                        twos++;
                        if(twos>maxTwo)
                            cnt++;
                    }else{
                        if(ctr%4==3)
                            twos++;
                        cnt++;
                    }
                }else{
                    cnt++;
                }
            }
            ctr=1;
        }
    }
    if(last==tot-1){
        if(ctr%4!=0){
            if(n%2!=0){
                    if(ctr%4==2){
                        twos++;
                        if(twos>maxTwo)
                            cnt++;
                    }else{
                        if(ctr%4==3)
                            twos++;
                        cnt++;
                    }
                }else{
                    cnt++;
                }
        }
    }
    if(twos>maxTwo){
        cout<<"NO";
    }
    else if(n%2==0 && cnt>0){
        cout<<"NO";
    }else if(n%2!=0 && cnt>1){
        cout<<"NO";
    }else{
        int save=-1,oddOneOut;
        int has2[10005]={0};
        vector<int> dist;
        if(n%2!=0){
            for(int i=0;i<tot;i++){
                has.insert(brr[i]);
            }

            for(int i=0;i<tot;i++){
                if(has.count(brr[i])%2==1){
                    save=i;
                    oddOneOut=brr[i];
                }
            }

            for(int i=0;i<tot;i++){
                if(save!=i){
                    if(has2[brr[i]]==0)
                        dist.push_back(brr[i]);
                    has2[brr[i]]++;
                }
            }

            for(int i=0;i<dist.size();i++){
                int nos=4*(has2[dist[i]]/4);
                int rem=has2[dist[i]]%4;
                for(int j=0;j<nos;j++){
                    arr.push_back(dist[i]);
                }
                for(int j=0;j<rem;j++){
                    oddarr.push_back(dist[i]);
                }
            }

            for(int i=0;i<oddarr.size();i++){
                arr.push_back(oddarr[i]);
            }
        }else{
            for(int i=0;i<tot;i++){
                arr.push_back(brr[i]);
            }
        }


       /*for(int i=0;i<arr.size();i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";


        for(int i=0;i<oddarr.size();i++){
            cout<<oddarr[i]<<" ";
        }
        cout<<"\n";

        cout<<oddOneOut<<"\n";*/


        int xf=0,xl=n-1,yf=0,yl=n-1;
        int ind=0;
        while(xf<xl){
            yf=0;
            yl=n-1;
            while(yf<yl){
                mat[xf][yf]=arr[ind];
                ind++;
                mat[xf][yl]=arr[ind];
                ind++;
                mat[xl][yf]=arr[ind];
                ind++;
                mat[xl][yl]=arr[ind];
                ind++;

                yf++;
                yl--;
            }

            xf++;
            xl--;
        }

        if(n%2!=0){
            xf=n/2;
            yf=0;
            yl=n-1;
            while(yf<yl){
                mat[xf][yf]=arr[ind];
                ind++;
                mat[xf][yl]=arr[ind];
                ind++;

                yf++;
                yl--;
            }

            xf=0;
            xl=n-1;
            yf=n/2;
            while(xf<xl){
                mat[xf][yf]=arr[ind];
                ind++;
                mat[xl][yf]=arr[ind];
                ind++;

                xf++;
                xl--;
            }

            mat[n/2][n/2]=oddOneOut;
        }

        cout<<"YES\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
}
