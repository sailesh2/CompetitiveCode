class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int maxi=0;

        int i=0,j=0,zB=0,tot=0,ctr=0;
        int cnt=1;
        while(i<A.size()){
            if(A[i]==0){
                zB++;
            }else{
                j=i;
                break;
            }
            i++;
        }
        while(j<A.size() && i<A.size() && i<=j){
            if(cnt==0){
                    cnt=1;
                    int cnt2=0,cnt3=0;
                    while(i<j){
                        if(A[i]==1 && cnt2==1){
                            cnt3=1;
                            break;
                        }
                        if(A[i]==0){
                            ctr--;
                            zB++;
                            cnt2=1;
                        }
                        tot--;
                        i++;
                    }
                if(cnt3==0){
                ctr--;
                while(i<A.size()){
                    if(A[i]==0){
                        zB++;
                    }else{
                        j=i;
                        break;
                    }
                    i++;
                }
                }else{
                    j++;
                    tot++;
                    maxi=max(maxi,tot+min(zB,K-ctr));
                }
                //cout<<"I-"<<i<<"\n";
            }else{
                if(A[j]==0){
                    ctr++;
                }
                if(ctr>K){
                    //ctr--;
                    cnt=0;
                    zB=0;
                }else{
                    tot++;
                    maxi=max(maxi,tot+min(zB,K-ctr));
                    //cout<<tot<<" "<<ctr<<" "<<zB<<"\n";
                    j++;
                }
            }
        }


        return maxi;
    }
};
