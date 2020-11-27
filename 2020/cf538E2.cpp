#include<bits/stdc++.h>
#define MAX 1000000000

using namespace std;
int n;

int binSear(int low, int high){
    if(low==high-1){
        return high;
    }

    int mid = (low+high)/2;

    cout<<"> "<<mid<<"\n";
    fflush(stdout);

    int res;
    cin>>res;

    if(res==-1)
        return -1;

    if(res==0){
        return binSear(low,mid);
    }else{
        return binSear(mid,high);
    }
}

int takeInput(int q){
    int num;
    cout<<"? "<<q<<"\n";
    fflush(stdout);

    cin>>num;
    return num;
}

int gcd(int a , int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}

int findD(int last){
    int num,fir,sec;
    int j=1;
    int d,diff,cnt=0;
    set<int> st;
    st.insert(last);

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    mt19937::result_type seed = time(0);
    auto dice_rand = std::bind(std::uniform_int_distribution<int>(1,n),
                       mt19937(seed));

    while(j<30){
        num=takeInput(dice_rand());
        if(num==-1)
            return -1;
        st.insert(num);
        j++;
    }
    set<int>::iterator stIt;
    for(stIt=st.begin();stIt!=st.end();stIt++){
        fir=*stIt;
        stIt++;
        if(stIt==st.end())
            break;
        sec=*stIt;
        diff=sec-fir;
        if(cnt==0)
            d=diff;
        else
            d=gcd(d,diff);
        cnt=1;
    }
    return d;
}

int main(){
    cin>>n;
    int d;
    int lastNum = binSear(0,MAX);
    if(lastNum!=-1){
        d = findD(lastNum);
        if(d!=-1){
            cout<<"! "<<(lastNum - (n-1)*d)<<" "<<d<<"\n";
            fflush(stdout);
        }
    }


    return 0;
}
