#include<bits/stdc++.h>
#define MAX 1000000000

using namespace std;
int n;

int binSear(int low, int high){
    if(low==high-1){
        return high;
    }

    int mid = (low+high)/2;

    cout<<"> "<<mid<<"\n";
    fflush(stdout);

    int res;
    cin>>res;

    if(res==-1)
        return -1;

    if(res==0){
        return binSear(low,mid);
    }else{
        return binSear(mid,high);
    }
}

int takeInput(int q){
    int num;
    cout<<"? "<<q<<"\n";
    fflush(stdout);

    cin>>num;
    return num;
}

int findD(int last){
    int num,a,b;
    int j=1;
    int d,cnt=0;
    set<int> mp;
    vector<pair<int,int> > darr;
    set<pair<int,int> > st;
    set<pair<int,int> >::iterator stIt;
    map<int,set<pair<int,int> > > locations;
    map<int,set<pair<int,int> > >::iterator locationsIt;
    while(j<=n){
        num=takeInput(j);
        if(num==last){
            j++;
            continue;
        }else if(num==-1){
            return -1;
        }else{
            darr.clear();
            for(int i=0;i<n-1;i++){
                if((last-num)%(n-1-i)==0){
                    d=(last-num)/(n-1-i);
                    if(cnt==0){
                        darr.push_back(make_pair(d,i));
                    }else{
                        if(mp.count(d)>0){
                            int lowV=-1;
                            int highV=n-1;
                            locationsIt = locations.find(d);
                            if(locationsIt!=locations.end()){
                                st=locationsIt->second;
                                stIt=st.lower_bound(make_pair(num,-1*MAX));
                                lowV = stIt==st.end() || stIt==st.begin() ? -1 : stIt->second;
                                stIt=st.upper_bound(make_pair(num,MAX));
                                highV = stIt==st.end() ? n-1 : stIt->second;
                            }
                            //cout<<num<<"------"<<lowV<<" "<<highV<<"\n";
                            if(i>lowV && i<highV)
                                darr.push_back(make_pair(d,i));
                        }
                    }
                }
            }
            if(darr.size()==1)
                return darr[0].first;
            mp.clear();
            for(int i=0;i<darr.size();i++){
                mp.insert(darr[i].first);
                locationsIt=locations.find(darr[i].first);
                st.clear();
                if(locationsIt!=locations.end()){
                    st=locationsIt->second;
                    locations.erase(locationsIt);
                }
                st.insert(make_pair(num,darr[i].second));
                locations.insert(make_pair(darr[i].first,st));
            }
            cnt=1;
            j++;
        }
    }
}

int main(){
    cin>>n;
    int d;
    int lastNum = binSear(0,MAX);
    if(lastNum!=-1){
        d = findD(lastNum);
        if(d!=-1){
            cout<<"! "<<(lastNum - (n-1)*d)<<" "<<d<<"\n";
            fflush(stdout);
        }
    }


    return 0;
}
