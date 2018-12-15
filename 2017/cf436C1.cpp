#include<bits/stdc++.h>

using namespace std;

int main(){
    int a,b,f,k,ctr=0,cnt=0;
    cin>>a>>b>>f>>k;
    int curr=b;
    for(int i=0;i<k;i++){
        if(curr<f){
            cnt=-1;
            break;
        } else{
            curr=curr-f;
        }

        if(i==k-1){
            if(curr<a-f){
                curr=b;
                ctr++;
                if(curr<a-f){
                    cnt=-1;
                    break;
                } else{
                    curr=curr-(a-f);
                }
            } else{
                curr=curr-(a-f);
            }
        } else{
            if(curr<2*(a-f)){
                curr=b;
                ctr++;
                if(curr<2*(a-f)){
                    cnt=-1;
                    break;
                } else{
                    curr=curr-2*(a-f);
                }
            } else{
                curr=curr-2*(a-f);
            }
        }

        i++;
        if(i==k)
            break;

        if(i==k-1){
            if(curr<f){
                curr=b;
                ctr++;
                if(curr<f){
                    cnt=-1;
                    break;
                } else{
                    curr=curr-f;
                }
            } else{
                curr=curr-f;
            }
        } else{
            if(curr<2*f){
                curr=b;
                ctr++;
                if(curr<2*f){
                    cnt=-1;
                    break;
                } else{
                    curr=curr-f;
                }
            } else{
                curr=curr-f;
            }
        }
    }
    if(cnt==-1){
        cout<<cnt;
    }else{
        cout<<ctr;
    }
    return 0;
}
