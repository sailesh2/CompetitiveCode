#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,cnt=0,found,selNum;
    cin>>n;
    int selected[300]={0};
    for(int i=(int)'a';i<=(int)'z';i++){
        selected[i]=1;
    }
    int blackList[300]={0};
    char type,guess;
    string word;
    int ctr=0,extraShocks;
    for(int i=0;i<n;i++){
        cin>>type;
        if(type=='.'){
            cin>>word;
            for(int j=0;j<word.length();j++){
                selected[(int)word[j]]=0;
                blackList[(int)word[j]]=1;
            }
        }else if(type=='!'){
            cin>>word;

            for(int j=(int)'a';j<=(int)'z';j++){
                found=0;
                for(int k=0;k<word.length();k++){
                    if((int)word[k]==j){
                        found=1;
                        break;
                    }
                }
                if(found==1 && blackList[j]==0 && selected[j]==1){
                    selected[j]=1;
                }else{
                    selected[j]=0;
                }
            }
            ctr++;
        }else{
            cin>>guess;
            selected[(int)guess]=0;
            blackList[(int)guess]=1;
            if(i!=n-1)
                ctr++;
        }
        selNum=0;
        for(int j=(int)'a';j<=(int)'z';j++){
            selNum=selNum+selected[j];
        }
        //cout<<i<<" "<<selNum<<"\n";
        if(selNum==1 && cnt==0){
            extraShocks=ctr;
            cnt=1;
        }
    }
    if(cnt==0)
        cout<<"0";
    else
        cout<<ctr-extraShocks;
    return 0;
}
