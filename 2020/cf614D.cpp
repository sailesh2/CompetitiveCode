#include<bits/stdc++.h>

using namespace std;

long long int x0,y0,ax,ay,bx,by;
long long int xs,ys,t;
long long int near,mint;
long long int xnear,ynear;
long long int xmin,ymin;
long long int xlast,ylast;
long long int dataCollected=0;
long long int mod=10000000000000009;


long long int power(long long int a, long long int b){
    long long int bin=a,p=1;
    while(b>0){
        if(b%2==1){
            if(p*bin>mod){
                return p;
            }
            p=(p*bin);
        }
        bin=(bin*bin);
        b=b/2;
    }
    return p;
}


long long int getX(long long int n){
    long long int px = power(ax,n);
    long long int xn = px*x0 + bx*((px-1)/(ax-1));
    return xn;
}

long long int getY(long long int n){

    long long int py = power(ay,n);
    long long int yn = py*y0 + by*((py-1)/(ay-1));
    return yn;
}

long long int dis(long long int n, long long int xn, long long int yn){
    long long int x1n=getX(n);
    long long int y1n=getY(n);

    return abs(x1n-xn) + abs(y1n-yn);
}

void findNearestData(){
    long long int ctr=1;
    long long int save=-1;
    long long int save2=-1;
    long long int k=10000000000000001;
    while(1){
        while(save+ctr<k && dis(save+ctr,xs,ys)>dis(save+ctr+1,xs,ys)){
            save2=save+ctr;
            ctr=ctr*2;
        }
        if(save==save2){
            break;
        }
        save=save2;
        ctr=1;
    }


    if(dis(save+ctr,xs,ys)<=t){
        t=t-dis(save+ctr,xs,ys);
        dataCollected++;
        xnear = getX(save+ctr);
        ynear = getY(save+ctr);
        near=save+ctr;
    }
}


void findMin(){
    long long int ctr=1;
    long long int save=-1;
    long long int save2=-1;
    long long int k=10000000000000000;
    while(1){
        while(save+ctr<near && dis(save+ctr,xnear,ynear)>t){
            save2=save+ctr;
            ctr=ctr*2;
        }
        if(save==save2){
            break;
        }
        save=save2;
        ctr=1;
    }
    if(near>(save+ctr)){
    t=t-dis(save+ctr,xnear,ynear);
    xmin=getX(save+ctr);
    ymin=getY(save+ctr);
    mint=save+ctr;
    dataCollected = dataCollected + near-(save+ctr);
    }else{
        xmin=xnear;
        ymin=ynear;
        mint=near;
    }
}


void findLast(){
    long long int ctr=1;
    long long int save=-1;
    long long int save2=-1;
    long long int k=10000000000000001;
    while(1){
        while(save+ctr+mint<k && dis(save+ctr+mint,xmin,ymin)<=t){
            save2=save+ctr;
            ctr=ctr*2;
        }
        if(save==save2){
            break;
        }
        save=save2;
        ctr=1;
    }
    cout<<xmin<<" "<<ymin<<"\n";
    cout<<save+mint<<"\n";
    cout<<dis(save+mint,xmin,ymin)<<"\n";
    if(save+mint!=-1 && save+mint>near){
    t=t-dis(save+mint,xmin,ymin);
    dataCollected = dataCollected + save+mint-near;
    }

}

int main(){
    cin>>x0>>y0>>ax>>ay>>bx>>by;
    cin>>xs>>ys>>t;

    findNearestData();

    findMin();

    findLast();
    cout<<power(2,1000000000000000);
//cout<<xnear<<" "<<ynear<<"\n";
//cout<<xmin<<" "<<ymin<<"\n";
    cout<<dataCollected;
    return 0;
}
