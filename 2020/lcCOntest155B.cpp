class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        int v[3];
        v[0]=a;
        v[1]=b;
        v[2]=c;
        sort(v,v+3);

        a=v[0];
        b=v[1];
        c=v[2];
        int l=lcm(a,lcm(b,c));
        int f=n + (n*a)/b - (n*a)/lcm(a,b) + (n*a)/c - (n*a)/lcm(a,c) + (n*a)/(l);

        int x=a*(f-n);

        f=x/a + x/b - x/lcm(a,b) + x/c - x/lcm(a,c) + x/(l);

        int ai=x/a;
        int bi=x/b;
        int ci=x/c;
        int m;
        for(int i=f;i<=n;i++){

            m=min(ai*a,min(bi*b,ci*c));
            if(m==ai*a){
                ai++;
            }if(m==bi*b){
                bi++;
            }if(m==ci*c){
                ci++;
            }
        }
        return m;
    }
};
