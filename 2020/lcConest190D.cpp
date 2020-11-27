class Solution {
private:
    vector<int> arr1,arr2;
    int dp[505][505];
    int sign1[505];
    int sign2[505];
    int mini1,maxi1,mini2,maxi2;

    int l,m;
    int MAX=1000000000;

    void setup1(){
        int save=-1;
        int mini=MAX;
        int maxi=-1*MAX;
        for(int i=l-1;i>=0;i--){
            mini=min(mini,arr1[i]);
            maxi=max(maxi,arr1[i]);
            if(arr1[i]==0){
                if(i!=l-1)
                    sign1[i]=sign1[i+1];
                else
                    sign1[i]=0;
            }else if(arr1[i]>0){
                if(i!=l-1){
                    if(sign1[i+1]>=0){
                        sign1[i]=1;
                    }else{
                        sign1[i]=-2;
                        save=i;
                        break;
                    }
                }else{
                    sign1[i]=1;
                }
            }else{
                if(i!=l-1){
                    if(sign1[i+1]<=0){
                        sign1[i]=-1;
                    }else{
                        sign1[i]=-2;
                        save=i;
                        break;
                    }
                }else{
                    sign1[i]=-1;
                }
            }
        }
        for(int i=save;i>=0;i--){
            sign1[i]=-2;
            mini=min(mini,arr1[i]);
            maxi=max(maxi,arr1[i]);
        }

        mini1=mini;
        maxi1=maxi;
    }

    void setup2(){
        int save=-1;
        int mini=MAX;
        int maxi=-1*MAX;
        for(int i=m-1;i>=0;i--){
            mini=min(mini,arr2[i]);
            maxi=max(maxi,arr2[i]);
            if(arr2[i]==0){
                if(i!=m-1)
                    sign2[i]=sign2[i+1];
                else
                    sign2[i]=0;
            }else if(arr2[i]>0){
                if(i!=m-1){
                    if(sign2[i+1]>=0){
                        sign2[i]=1;
                    }else{
                        sign2[i]=-2;
                        save=i;
                        break;
                    }
                }else{
                    sign2[i]=1;
                }
            }else{
                if(i!=m-1){
                    if(sign2[i+1]<=0){
                        sign2[i]=-1;
                    }else{
                        sign2[i]=-2;
                        save=i;
                        break;
                    }
                }else{
                    sign2[i]=-1;
                }
            }
        }
        for(int i=save;i>=0;i--){
            sign2[i]=-2;
            mini=min(mini,arr2[i]);
            maxi=max(maxi,arr2[i]);
        }

        mini2=mini;
        maxi2=maxi;
    }

    void clearDP(){
        l=arr1.size();
        m=arr2.size();

        setup1();
        setup2();


        for(int i=0;i<=l;i++){
            for(int j=0;j<=m;j++)
                dp[i][j]=-1;
        }
    }

    int dotProd(int ind1, int ind2){
        int maxi=0;
        int p;
        if(ind1>=l || ind2>=m)
            return 0;

        if(sign1[ind1]==0 || sign2[ind2]==0)
            return 0;

        if(sign1[ind1]==1 && sign2[ind2]==-1)
            return 0;

        if(sign1[ind1]==-1 && sign2[ind2]==1)
            return 0;

        int v1 = dp[ind1][ind2+1]==-1?dotProd(ind1,ind2+1):dp[ind1][ind2+1];
        int v2 = dp[ind1+1][ind2]==-1?dotProd(ind1+1,ind2):dp[ind1+1][ind2];
        int v3 = dp[ind1+1][ind2+1]==-1?dotProd(ind1+1,ind2+1):dp[ind1+1][ind2+1];
        maxi = max(maxi,v1);
        maxi = max(maxi,v2);
        maxi = max(maxi,v3+max(0,arr1[ind1]*arr2[ind2]));

        /*for(int i=l-1;i>=ind1;i--){
            if(arr1[i]==0)
                continue;

            for(int j=m-1;j>=ind2;j--){
                if(arr1[i]>0 && arr2[j]<=0)
                    continue;
                if(arr1[i]<0 && arr2[j]>=0)
                    continue;
                if(arr1[i]>0 && (sign2[j]==-1 || sign2[j]==0))
                    continue;

                if(arr1[i]<0 && (sign2[j]==1 || sign2[j]==0))
                    continue;
                if(dp[i+1][j+1]==-1)
                p=dotProd(i+1,j+1)+max(0,arr1[i]*arr2[j]);
                else
                p=dp[i+1][j+1]+max(0,arr1[i]*arr2[j]);
                maxi=max(maxi,p);



            }

            dp[i][ind2]=maxi;
        }*/

        dp[ind1][ind2]=maxi;
        return maxi;
    }

    bool allPos(vector<int> arr, int n){

        for(int i=0;i<n;i++){
            if(arr[i]<0)
                return false;
        }
        return true;
    }


    bool allNeg(vector<int> arr, int n){

        for(int i=0;i<n;i++){
            if(arr[i]>0)
                return false;
        }
        return true;
    }

    int maximum(vector<int> arr, int n){
        int maxi=-1*MAX;
        for(int i=0;i<n;i++){
            maxi=max(maxi,arr[i]);
        }
        return maxi;
    }

    int minimum(vector<int> arr, int n){
        int mini=MAX;
        for(int i=0;i<n;i++){
            mini=min(mini,arr[i]);
        }
        return mini;
    }

    pair<bool,int> notPossible(){
        if(sign1[0]==0 && sign2[0]==0)
            return make_pair(true,0);

        if(sign1[0]==1 && sign2[0]==-1){
            return make_pair(true,mini1*maxi2);
        } else if(sign1[0]==-1 && sign2[0]==1){
            return make_pair(true,maxi1*mini2);
        } else{
            return make_pair(false,0);
        }
    }


public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        arr1=nums1;
        arr2=nums2;
        clearDP();
        pair<bool,int> ans = notPossible();
        if(ans.first)
            return ans.second;
        return dotProd(0,0);
    }
};

