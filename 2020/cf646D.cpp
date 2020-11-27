#include<bits/stdc++.h>

using namespace std;
set<int> asked;

int askWithoutIndex(int index, int n, vector<int>* subsets){

    vector<int> askQ;
    int indexVals[1005]={0};
    for(int j=0;j<subsets[index].size();j++){
        indexVals[subsets[index][j]]=1;
    }

    for(int i=1;i<=n;i++){
        if(indexVals[i]==0){
            askQ.push_back(i);
        }
    }

    int st = askQ.size();
    cout<<"? "<<st<<" ";
    for(int i=0;i<st;i++){
        cout<<askQ[i]<<" ";
    }

    cout<<"\n";
    fflush(stdout);
    int val;
    cin>>val;
    return val;
}

int askMax(vector<int>* subsets, int n){

    vector<int> askQ;

    for(int i=1;i<=n;i++)
        askQ.push_back(i);

    int st = askQ.size();
    cout<<"? "<<st<<" ";
    for(int i=0;i<st;i++){
        cout<<askQ[i]<<" ";
    }

    cout<<"\n";
    fflush(stdout);
    int val;
    cin>>val;
    return val;
}

int askMid(vector<int>* subsets, int mid){

    vector<int> askQ;
    for(int i=0;i<=mid;i++){
        for(int j=0;j<subsets[i].size();j++){
            askQ.push_back(subsets[i][j]);
        }
    }

    int st = askQ.size();
    cout<<"? "<<st<<" ";
    for(int i=0;i<st;i++){
        cout<<askQ[i]<<" ";
    }

    cout<<"\n";
    fflush(stdout);
    int val;
    cin>>val;
    return val;
}

int binSearWithMiddle(int low, int high, vector<int>* subsets, int sear){
    if(low==high){
        if(asked.count(low)==0){
            int val = askMid(subsets, low);


            if(val==sear)
                return low;
            else if(val==-1)
                return -1;
            else
                return -2;
        }else
            return low;
    }

    int mid = (low+high)/2;



    int val = askMid(subsets, mid);
    asked.insert(mid);


    if(val==-1)
        return -1;

    if(val==sear){
        return binSearWithMiddle(low,mid,subsets,sear);
    }else{
        return binSearWithMiddle(mid+1,high,subsets,sear);
    }
}



int main(){
    int t,n,k,c,x;
    cin>>t;
    string s;
    int cnt=0;
    for(int i=0;i<t;i++){
        cin>>n>>k;
        vector<int> subsets[k];
        for(int j=0;j<k;j++){
            cin>>c;
            vector<int> v;
            for(int l=0;l<c;l++){
                cin>>x;
                v.push_back(x);
            }
            subsets[j]=v;
        }
        asked.clear();
        int sear = askMax(subsets,n);
        int index = binSearWithMiddle(0,k-1,subsets,sear);
        if(index==-1){
            cnt=1;
            break;
        }
        if(index==-2){
            cout<<"! ";

            for(int j=0;j<k;j++){
                cout<<sear<<" ";
            }
        }else{
            int indexVal = askWithoutIndex(index,n,subsets);
            if(indexVal==-1){
                cnt=1;
                break;
            }
            cout<<"! ";

            for(int j=0;j<index;j++){
                cout<<sear<<" ";
            }
            cout<<indexVal<<" ";
            for(int j=index+1;j<k;j++){
                cout<<sear<<" ";
            }
        }
        if(cnt==1){
            break;
        }
        cin>>s;
        if(s[0]=='I')
            break;
    }
    return 0;
}
