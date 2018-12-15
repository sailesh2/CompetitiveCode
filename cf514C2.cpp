#include<bits/stdc++.h>

using namespace std;

int main(){
    int x;
    cin>>x;
    if(x==1){
        cout<<"1";
    }else if(x==2){
        cout<<"1 2";
    }else if(x==3){
        cout<<"1 1 3";
    }else{
        int ev = (int)pow(2, (int)log2(x));

        int last;
        if(x%2==0){
            last=x;
        }else{
            last=x-1;
        }
        int rest=0,c;
        vector<int> ans;
        while(rest<x){
            c=(int)(x/ev);
            int i=0;
            while(i<c-rest){
                ans.push_back(ev);
                i=i+1;
            }
            ev=(int)ev/2;
            if(ev==0)
                break;
            rest=ans.size();
        }

        int i=ans.size()-1;
        int v=(int)(last/ans[1])+1;

        if(ans[1]*v<=last){
            ans[0]=ans[1]*v;
        }else if(ans[1]*(v-1)<=last){
            ans[0]=ans[1]*(v-1);
        }

        while(i>=0){
            cout<<ans[i]<<" ";
            i=i-1;
        }
    }

    return 0;
}
