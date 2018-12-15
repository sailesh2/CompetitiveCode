#include<bits/stdc++.h>

using namespace std;

int has[1001]={0};
void larg3(vector<int> a, vector<int> b, vector<int> c){
    int sm;
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            for(int k=0;k<6;k++){
                sm=a[i]*100+b[j]*10+c[k];
                has[sm]=1;
            }
        }
    }
}

void larg2(vector<int> a, vector<int> b){
    int sm;
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            sm=a[i]*10+b[j];
            has[sm]=1;
        }
    }
}

void larg1(vector<int> a){
    for(int i=0;i<6;i++){
        has[a[i]]=1;
    }
}
int main(){
    int n,x;
    cin>>n;

    vector<int> a;
    vector<int> b;
    vector<int> c;

    if(n==3){
        for(int i=0;i<6;i++){
            cin>>x;
            a.push_back(x);
        }

        for(int i=0;i<6;i++){
            cin>>x;
            b.push_back(x);
        }

        for(int i=0;i<6;i++){
            cin>>x;
            c.push_back(x);
        }

        larg3(a,b,c);
        larg3(a,c,b);
        larg3(b,a,c);
        larg3(b,c,a);
        larg3(c,a,b);
        larg3(c,b,a);

        larg2(a,b);
        larg2(b,a);

        larg2(b,c);
        larg2(c,b);

        larg2(a,c);
        larg2(c,a);


        larg1(a);
        larg1(b);
        larg1(c);


    } else if(n==2){
        for(int i=0;i<6;i++){
            cin>>x;
            a.push_back(x);
        }

        for(int i=0;i<6;i++){
            cin>>x;
            b.push_back(x);
        }

        larg2(a,b);
        larg2(b,a);

        larg1(a);
        larg1(b);

    }else{
        for(int i=0;i<6;i++){
            cin>>x;
            a.push_back(x);
        }
        larg1(a);
    }

    int save=0;
    for(int i=1;i<=1000;i++){
        if(has[i]==0){
            break;
        }
        save=i;
    }
    cout<<save;
    return 0;
}
