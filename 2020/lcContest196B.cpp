class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        vector<pair<int,int>> ants;

        for(int i=0;i<left.size();i++){
            ants.push_back(make_pair(left[i],1));
        }
        for(int i=0;i<right.size();i++){
            ants.push_back(make_pair(right[i],-1));
        }

        sort(ants.begin(),ants.end());
        int lastLeft=0;
        pair<int,int> que[n+1];
        int f=-1,r=-1;
        int maxiL=0;
        int tm=0;
        for(int i=0;i<ants.size();i++){
            pair<int,int> ant = ants[i];
            if(ant.second==-1){
                if(f!=-1){
                    int tmn = abs(ant.first-tm-que[r].first)/2;
                    for(int j=r;j>=f;j--){
                        int d=que[j].first+tm;
                        int t2=que[j].second+tm;
                        int tm2=(j-1>=f?abs(que[j-1].first+tm - d)/2:0);

                        que[j]=make_pair(d-tm2,t2+tm2);
                        tm=tm+tm2;
                    }
                    maxiL=max(maxiL,que[f].first+tm+que[f].second+tm);

                    f++;
                    r++;
                    que[r]=make_pair(ant.first-tmn,tmn);
                }else{
                    maxiL=max(maxiL,ant.first);
                }
            }else{
                if(f==-1){
                    f=0;
                    r=0;
                }else{
                    r++;
                }
                que[r]=make_pair(ant.first,0);
            }
        }

        int maxiR=((f!=-1)?abs(n-que[f].first)+que[f].second:0);
        //cout<<maxiR;
        return max(maxiL, maxiR);
    }
};
