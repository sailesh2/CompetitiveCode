class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {

        int l=s.length();
        int i=0,j=0;
        int maxi=0,sm=0;
        while(j<l){
            int cost = abs(s[j]-t[j]);
            cout<<cost<<" ";
            if((sm+cost)<=maxCost){
                sm=sm+cost;
                j++;
                maxi=max(maxi,j-i);
            }else{
                int cnt=0;
                while(i<j){
                    sm=sm-(abs(s[i]-t[i]));
                    i++;
                    if((sm+cost)<=maxCost){
                        sm=sm+cost;
                        j++;
                        maxi=max(maxi,j-i);

                        cnt=1;
                        break;
                    }
                }
                if(cnt==0){
                    i++;
                    j++;
                }
            }
            cout<<sm<<"\n";
        }
        return maxi;
    }
};
