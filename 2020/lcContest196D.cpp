class Solution {
public:
    string minInteger(string num, int k) {
        int n = num.length();

        for(int i=0;i<n;i++){
            char mini=num[i];
            int save=-1;
            for(int j=i+1;j<n;j++){
                if(num[j]<mini && j-i<k){
                    mini=num[j];
                    save=j;
                }
            }
            if(save!=-1){
                char temp=num[save];
                for(int j=save;j>i;j--){
                    num[j]=num[j-1];
                }
                num[i]=temp;
                k=k-(save-i);
            }
        }

        return num;
    }
};
