class Solution {
private:
    int next[200005]={0};

    void preprocessNext(vector<int> arr){
        int mp[200005]={0};
        int n=arr.size();
        for(int i=0;i<200005;i++)
        {
            mp[i]=-1;
            next[i]=-1;
        }
        for(int i=n-1;i>=0;i--){
            next[i]=mp[arr[i]];
            mp[arr[i]]=i;
        }
    }
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {

        int cnt=0;
        int sm=0;
        int has[200005]={0};
        int j=0;
        preprocessNext(A);
        int save=-1;
        for(int i=0;i<A.size();i++){
            if(has[A[i]]==0)
                cnt++;
            has[A[i]]++;
            cout<<i<<"cnt"<<cnt<<"\n";
            if(cnt==K){
                if(save==-1)
                save=i;
                sm++;
            }else if(cnt>K){
                sm++;
                for(;j<i;j++){
                    has[A[j]]--;
                    if(has[A[j]]==0){
                        cnt--;
                    }
                    cout<<j<<"c"<<next[j]<<"\n";
                    if(cnt==K || next[j]==-1 || next[j]>i){
                        save=i;
                        j++;
                        break;
                    }
                    save=max(next[j],save);
                    sm=sm+i-max(next[j],save);
                }
            }
        }
        cout<<sm;
        for(;j<A.size();j++){
            has[A[j]]--;
            if(has[A[j]]==0){
                cnt--;
            }
            if(cnt!=K || next[j]==-1){

                break;
            }
            save=max(next[j],save);
            sm=sm+A.size()-max(next[j],save);
        }

        return sm;
    }
};
