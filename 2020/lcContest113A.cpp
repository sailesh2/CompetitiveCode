class Solution {
private:
    vector<int> digs;

    bool isPresent(int *has,int num){
        int ctr[10]={0};
        for(int i=0;i<digs.size();i++){
            ctr[digs[i]]++;
            if(ctr[digs[i]]-has[digs[i]]>0 && digs[i]==num){
                return true;
            }
        }
        return false;
    }

    string greatestMin(int *has){
        string minute="";
        int maxi=-1;
        int ctr[10]={0};
        for(int i=0;i<digs.size();i++){
             ctr[digs[i]]++;
            if(ctr[digs[i]] - has[digs[i]]>0 && digs[i]<=5){
                maxi=max(maxi,digs[i]);
            }
        }
        if(maxi==-1)
            return minute;
        has[maxi]++;

        minute=(char)(maxi+48);

        int ctr2[10]={0};
        for(int i=0;i<digs.size();i++){
             ctr2[digs[i]]++;
            if(ctr2[digs[i]] - has[digs[i]]>0){
                return minute+(char)(digs[i]+48);
            }
        }
        return minute;
    }

    string getGreatest(int *has, int alreadyHr){

        int maxi=-1;
        int ctr[10]={0};
        for(int i=0;i<digs.size();i++){
            ctr[digs[i]]++;
            if(ctr[digs[i]] - has[digs[i]]>0){
                maxi=max(maxi,digs[i]);
            }
        }
        has[maxi]++;
        string hr="";
        hr=(char)(alreadyHr+48);
        hr=hr + (char)(maxi+48);
        string mint = greatestMin(has);
        return larTime(hr,mint);
    }

    string larTime(string hr, string mint){
        if(mint.length()==0){
            return "";
        }
        return hr+":"+mint;
    }

    bool minPossible(string min){
        return min.length()>0;
    }

    string tryWithOne(){
        int has[10]={0};

        if(isPresent(has,1)){
            has[1]++;
            return getGreatest(has,1);

        }else{
            return tryWithZero();
        }
    }

    string tryWithZero(){
        int has[10]={0};

        if(isPresent(has,0)){
            has[0]++;
            return getGreatest(has,0);
         }else{
             return "";
         }
    }

    string tryWithTwo(){
         int has[10]={0};
        string m;
        if(isPresent(has,2)){
            has[2]++;
            if(isPresent(has,3)){
                has[3]++;
                m=greatestMin(has);
                if(minPossible(m))
                    return larTime("23",m);
                else
                    return tryWithOne();
            }else if(isPresent(has,2)){

                has[2]++;
                m=greatestMin(has);
                if(minPossible(m))
                    return larTime("22",m);
                else
                    return tryWithOne();
            }else if(isPresent(has,1)){

                has[1]++;
                m=greatestMin(has);
                if(minPossible(m))
                    return larTime("21",m);
                else
                    return tryWithOne();
            }else if(isPresent(has,0)){

                has[0]++;
                m=greatestMin(has);
                if(minPossible(m))
                    return larTime("20",m);
                else
                    return tryWithOne();
            }else{
                return "";
            }
        }else{
            return tryWithOne();
        }
    }
public:
    string largestTimeFromDigits(vector<int>& A) {
        digs=A;
        return tryWithTwo();
    }
};
