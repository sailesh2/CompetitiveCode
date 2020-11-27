class Solution {
private:

    int gcd(int a , int b)
    {
       if(b==0) return a;
       a%=b;
       return gcd(b,a);
    }
    string convertToStr(int n){
        string rev="",s="";
        while(n>0){
            rev.push_back((char)(n%10+48));
            n=n/10;
        }

        for(int i=rev.length()-1;i>=0;i--)
            s.push_back(rev[i]);
        return s;
    }

    string getFraction(int num, int den){
        int g = gcd(num,den);
        num=num/g;
        den=den/g;
        string numS=convertToStr(num);
        string denS=convertToStr(den);
        numS.push_back('/');
        for(int i=0;i<denS.length();i++)
            numS.push_back(denS[i]);
        return numS;
    }
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> v;
        set<string> st;
        for(int i=n;i>=2;i--){
            for(int j=i-1;j>=1;j--){
                string fraction = getFraction(j,i);
                if(st.count(fraction)==0){
                    st.insert(fraction);
                    v.push_back(fraction);
                }
            }
        }
        return v;
    }
};
