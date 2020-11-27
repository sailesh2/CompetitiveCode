#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;

    int a[n],b[n];
    for(int i=0;i<n;i++){
        a[i]=(int)s[i]-48;
        b[i]=a[i];
    }

    for(int i=0;i<n-k;i++)
        b[i+k]=b[i];

    int cnt=0;
    int save=0;
    for(int i=0;i<n;i++){
            if(b[i]>a[i]){
                cnt=1;
                save=i%k;
                break;
            }else if(b[i]<a[i]){
                cnt=2;
                break;
            }
    }

    if(cnt!=2){
        cout<<n<<"\n";
        for(int i=0;i<n;i++)
            cout<<(char)(b[i]+48);
    }else{

        cnt=0;
        save=0;
        for(int i=k-1;i>=0;i--){
            if(b[i]!=9){
                save=i;
                while(i<n){
                    b[i]++;
                    i=i+k;
                }
                cnt=1;
                break;
            }
        }

        if(cnt==1){
            for(int i=save+1;i<k;i++){
                int j=i;
                while(j<n){
                    b[j]=0;
                    j=j+k;
                }
            }
            cout<<n<<"\n";
            for(int i=0;i<n;i++)
                cout<<(char)(b[i]+48);
        }else{

        cout<<n+1<<"\n";
        int c[n+1];
        c[0]=1;
        for(int i=1;i<n+1;i++)
            c[i]=0;
        for(int i=0;i<n+1-k;i++)
            c[i+k]=c[i];
        for(int i=0;i<n+1;i++)
            cout<<(char)(c[i]+48);
        }
    }
    return 0;
}
