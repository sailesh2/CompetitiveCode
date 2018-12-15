#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int x,y;
    vector<pair<int,int> > points;
    cin>>n;
    if(n==1){
        cin>>x>>y;
        cout<<"-1";
    }else{
        for(int i=0;i<n;i++){
            cin>>x>>y;
            points.push_back(make_pair(x,y));
        }

        if(n==2){
            int x1=points[0].first;
            int y1=points[0].second;

            int x2=points[1].first;
            int y2=points[1].second;

            if(x1==x2 || y1==y2){
                cout<<"-1";
            } else{
                cout<<(abs(y2-y1))*(abs(x2-x1));
            }
        } else {
            int x1,y1,x2,y2,cnt=0;
            for(int j=0;j<n;j++){
                x1=points[j].first;
                y1=points[j].second;

                for(int k=0;k!=j && k<n;k++){
                    x2=points[k].first;
                    y2=points[k].second;

                    if(x1!=x2 && y1!=y2){
                        cout<<(abs(y2-y1))*(abs(x2-x1));
                        cnt=1;
                        break;
                    }

                }
                if(cnt==1)
                    break;
            }

        }
    }

    return 0;
}
