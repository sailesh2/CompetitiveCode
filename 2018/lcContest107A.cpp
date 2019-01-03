class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i=0,j=0;
        while(i<name.length() && j<typed.length()){
            if(name[i]!=typed[j])
                return false;
            int ctr1=0,ctr2=0;
            while(i+1<name.length() && name[i]==name[i+1]){
                ctr1++;
                i++;
            }
            while(j+1<typed.length() && typed[j]==typed[j+1]){
                ctr2++;
                j++;
            }

            if(ctr1>ctr2)
                return false;
            i++;
            j++;
        }
        return i>=name.length() && j>=typed.length();
    }
};
