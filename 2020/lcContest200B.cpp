class Solution {
private:
    vector<int> getKMax(vector<int> arr, int k, int n){

        k--;
        set<int> st;
        set<int>::iterator stIt;
        int p1=0,p2=k;
        for(int i=0;i<k;i++){
            st.insert(arr[i]);
        }

        vector<int> kMax;
        if(k==0){
            for(int i=0;i<n;i++)
                kMax.push_back(0);
                return kMax;
        }

        while(p2<n){
            stIt=st.end();
            stIt--;
            kMax.push_back(*stIt);
            st.erase(st.find(arr[p1]));
            p1++;
            st.insert(arr[p2]);
            p2++;
        }

        stIt=st.end();
        stIt--;
        kMax.push_back(*stIt);
        return kMax;
    }

    int getMax(vector<int> arr, int n){
        int maxi=0;
        for(int i=0;i<n;i++)
            maxi=max(maxi,arr[i]);
        return maxi;
    }

    vector<int> getLeftMax(vector<int> arr, int n){
    	int maxi=0;
        vector<int> leftMax;
        for(int i=0;i<n;i++){
            maxi=max(maxi,arr[i]);
            leftMax.push_back(maxi);
        }
        return leftMax;
    }

    int getWinner(vector<int> arr, vector<int> leftMax, vector<int> kMax, int n, int maxi, int k){

        for(int i=0;i<n;i++){
            if(arr[i]==maxi)
                return maxi;

            if(i==0){
                if(kMax[i+1]<arr[i]){
                    if(k==n || max(arr[k],kMax[i+1])<arr[i])
                        return arr[i];
                }
            }else{
                if(i+k-1>=n)
                    return maxi;
                if((leftMax[i-1]<arr[i]) && (i==n-1 || kMax[i+1]<arr[i]))
                    return arr[i];
            }
        }
        return maxi;
    }
public:
    int getWinner(vector<int>& arr, int k) {
        int n=arr.size();
        int maxi=getMax(arr,n);
        if(k>=n){
            return maxi;
        }


        vector<int> kMax = getKMax(arr,k,n);
        vector<int> leftMax = getLeftMax(arr,n);

        return getWinner(arr,leftMax,kMax,n,maxi,k);
    }
};
