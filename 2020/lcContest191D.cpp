class Solution {
private:
    vector<int> ballArr;
    double fac[9];
    vector<string> pers;
    set<string> perSt;
    double ans=0;

    void setup(){
        fac[0]=1;
        for(int i=1;i<9;i++)
            fac[i]=fac[i-1]*i;
    }

    double getDen(){
        double d= 1;
        for(int i=0;i<ballArr.size();i++){
            d=d*fac[ballArr[i]];
        }
        return d;
    }

    string getDigStr(){
        string s="";
        int ctr=1;
        for(int i=0;i<ballArr.size();i++){
            for(int j=0;j<ballArr[i];j++){
                s.push_back((char)(ctr+48));
            }
            ctr++;
        }
        return s;
    }

    void getPer(string p, int index, int last){
        if(index==last){
            if(perSt.count(p)==0){
                perSt.insert(p);
                pers.push_back(p);
            }
            return;
        }

        for(int i=index;i<=last;i++){

            char c = p[index];
            p[index] = p[i];
            p[i] = c;

            getPer(p,index+1,last);

            c = p[index];
            p[index] = p[i];
            p[i] = c;
        }
    }

    void backtrack(int index, string digs, int* has){
        if(index==digs.length()){
            int ctra=0;
            int ctrb=0;
            set<char> sta,stb;
            for(int i=0;i<digs.length();i++){
                if(has[i]==1){
                    if(sta.count(digs[i])==0){
                        sta.insert(digs[i]);
                        ctra++;
                    }
                }else{
                    if(stb.count(digs[i])==0){
                        stb.insert(digs[i]);
                        ctrb++;
                    }
                }
            }
            if(ctra==ctrb)
                ans++;
            return;
        }

        has[index]=1;
        backtrack(index+1,digs,has);
        has[index]=0;
        backtrack(index+1,digs,has);
    }

    double getNum(){
        string digs = getDigStr();
        int has[60]={0};
        backtrack(0,digs,has);
        return ans;
        /*int n = digs.length();
        getPer(digs,0,n-1);
        double c=0;
        for(int i=0;i<pers.size();i++){
            int hasLeft[100]={0};
            int hasRight[100]={0};
            int left=0,right=0;

            for(int j=0;j<n/2;j++){
                if(hasLeft[(int)pers[i][j]]==0){
                    left++;
                    hasLeft[(int)pers[i][j]]=1;
                }
            }

            for(int j=n/2;j<n;j++){
                if(hasRight[(int)pers[i][j]]==0){
                    right++;
                    hasRight[(int)pers[i][j]]=1;
                }
            }

            if(left==right)
                c++;
        }
        return c;*/
    }

    void display(){
        cout<<pers.size()<<"\n";
        for(int i=0;i<pers.size();i++){
            cout<<pers[i]<<"\n";
        }

    }
public:
    double getProbability(vector<int>& balls) {
        ballArr = balls;
        setup();
        double num = getNum();

        double den = getDen();

        //display();

        return num/den;
    }
};
