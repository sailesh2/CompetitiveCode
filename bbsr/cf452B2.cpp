#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,dec=0,aug=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int cnt=0,ctr=0,ctr2=0,l=0,save=-1,dupl=7;
    if(arr[0]==31){
        ctr=1;
    }else{
        ctr=0;
    }
    for(int i=1;i<n;i++){
        if(save!=-1 && (i-save==dupl)){
            if(arr[i]!=31){
                cnt=1;
          //      cout<<"in";
                break;
            }
        }
        if(arr[i]==31){
            if(ctr==0){
                ctr=1;
            }else{
                if(ctr==1){

                    if(save!=-1 && (i-save!=dupl)){
                        cnt=1;
                        //cout<<"notd75";
                        break;
                    }
                    if(dupl==7){
                        dupl=5;
                    }else{
                        dupl=7;
                        if(i+1<n && (arr[i+1]!=29 && arr[i+1]!=28)){
                            cnt=1;
                            //cout<<"not29";
                            break;
                        }
                    }

                    ctr++;
                    save=i;
                }else{
                    cnt=1;
            //        cout<<"31";
                    break;
                }
            }
        }else if(arr[i]==30){
            if(ctr==1 || ctr==2){
                ctr=0;
            }else{
                cnt=1;
              //  cout<<"30";
                break;
            }
        }else if(arr[i]==29){
            if(l==29 || ((i-1>=0 && arr[i-1]==30) || (i+1<n && arr[i+1]==30))){
                cnt=1;
                //cout<<"29";
                break;
            }
            ctr=0;
            l=29;
        }else{
            if( ((i-1>=0 && arr[i-1]==30) || (i+1<n && arr[i+1]==30))){
                cnt=1;
                //cout<<"28";
                break;
            }
            ctr=0;
        }
    }




    if(cnt==1 || (save==-1 && n>=8)){
        dec=1;
    }

    {
        cnt=0;ctr=0;ctr2=0;l=0;save=-1;dupl=5;
        if(arr[0]==31){
            ctr=1;
        }else{
            ctr=0;
        }
        for(int i=1;i<n;i++){
            if(save!=-1 && (i-save==dupl)){
                if(arr[i]!=31){
                    cnt=1;
                    break;
                }
            }
            if(arr[i]==31){
                if(ctr==0){
                    ctr=1;
                }else{
                    if(ctr==1){

                        if(save!=-1 && (i-save!=dupl)){
                            cnt=1;
                            break;
                        }
                        if(dupl==7){
                            dupl=5;
                        }else{
                            dupl=7;
                            if(i+1<n && (arr[i+1]!=29 && arr[i+1]!=28)){
                                cnt=1;
                                break;
                            }
                        }
                        ctr++;
                        save=i;
                    }else{
                        cnt=1;
                        break;
                    }
                }
            }else if(arr[i]==30){
                if(ctr==1 || ctr==2){
                    ctr=0;
                }else{
                    cnt=1;
                    break;
                }
            }else if(arr[i]==29){
                if(l==29 || ((i-1>=0 && arr[i-1]==30) || (i+1<n && arr[i+1]==30))){
                    cnt=1;
                    break;
                }
                ctr=0;
                l=29;
            }else{
                if( ((i-1>=0 && arr[i-1]==30) || (i+1<n && arr[i+1]==30))){
                    cnt=1;
                    break;
                }
                ctr=0;
            }
        }


        if(cnt==1 || (save==-1 && n>=8)){
            aug=1;
        }
    }
    if(dec==1 && aug==1){
        cout<<"NO";
    }
    else{
        cnt=0;
        int feb=0;
        for(int i=0;i<n;i++){
            if(arr[i]==28 || arr[i]==29){
                feb++;
                ctr=1;
                ctr2=0;
                if(i!=0 && arr[i-1]!=31){
                    cnt=1;
                    break;
                }
                for(int j=i+1;j<n;j++){
                    if(ctr2==5 || ctr2==10){
                        if(arr[j]!=31){
                            cnt=1;
                            break;
                        }
                    }else if(ctr2==11){
                        if(arr[j]!=28){
                            if(arr[j]==29 && arr[i]==28){

                            }else{
                                cnt=1;
                                break;
                            }
                        }
                        break;
                    }else{
                        if(arr[j]!=30+ctr){
                            cnt=1;
                            break;
                        }
                        ctr=1-ctr;
                    }
                    ctr2++;
                }
            }
            if(cnt==1)
                break;
        }
        if(cnt==1 || feb>2 || (feb<2 && n==24) || (feb<1 && n>=12)){
            cout<<"NO";
        }else{
            cout<<"YES";
        }
    }
    return 0;
}
