#include<bits/stdc++.h>

using namespace std;
string wind;
long long int remaining(long long int dirCnt, char dir, long long int totalEligible){
    long long int sm=0;
    long long int ind = (long long int)((ceil((float)dirCnt/(2*totalEligible)))-1);
    sm=sm+wind.length()*ind;
    dirCnt=max(0LL,dirCnt-(2*totalEligible*ind));
    int save=0;
    for(int i=0;i<wind.length();i++){

        if(wind[i]==dir && dirCnt>0){
            dirCnt-=2;
            save=i+1;
        }
    }
    sm=sm+save;
    return sm;
}


long long int withTwo(long long int dirCnt1, char dir1, long long int dirCnt2, char dir2){
    //cout<<"dirCnt1--"<<dirCnt1<<" "<<dir1<<" "<<"dircnt2--"<<dirCnt2<<" "<<dir2<<"\n";
    long long int eligible[wind.length()]={0};
    long long int totalEligible1=0,totalEligible2=0,ctr1=0,ctr2=0;
    long long int sm=0,save=0;

    for(long long int i=0;i<wind.length();i++){

        if(wind[i]==dir1){
            totalEligible1++;
            ctr1++;
            if(ctr1<=dirCnt1){
                save=max(save,i+1);
                eligible[i]=1;
            }
        }
    }
    dirCnt1 = max(dirCnt1,ctr1) - ctr1;

    for(long long int i=0;i<wind.length();i++){
        if(eligible[i]==1 && dirCnt1>0){
            eligible[i]=0;
            save=max(save,i+1);
            dirCnt1--;
        }
    }

    for(long long int i=0;i<wind.length();i++){

        if(wind[i]==dir2){
            totalEligible2++;
            ctr2++;
            if(ctr2<=dirCnt2){
                save=max(save,i+1);
                eligible[i]=1;
            }
        }
    }

    dirCnt2 = max(dirCnt2,ctr2) - ctr2;

    for(long long int i=0;i<wind.length();i++){
        if(eligible[i]==1 && dirCnt1>0){
            eligible[i]=0;
            save=max(save,i+1);
            dirCnt1--;
        }
    }

    for(long long int i=0;i<wind.length();i++){
        if(eligible[i]==1 && dirCnt2>0){
            eligible[i]=0;
            save=max(save,i+1);
            dirCnt2--;
        }
    }

    sm=save;
    if(totalEligible1 + totalEligible2 == 0)
        return -1;
    //cout<<"FirstPas--\n";
    //cout<<"dirCnt1--"<<dirCnt1<<" "<<"dirCnt2--"<<dirCnt2<<"\n";
    if(dirCnt1>0 && dirCnt2>0){
        sm=max(sm,(long long int)wind.length());
        long long int ind = (long long int)(ceil((float)dirCnt1/(totalEligible1 + totalEligible2))-1);
        long long int v = (long long int)wind.length()*ind;
        sm=sm+v;
        dirCnt2 = max(0LL,dirCnt2-(totalEligible1 + totalEligible2)*ind);

        dirCnt1=max(0LL,dirCnt1-(totalEligible1 + totalEligible2)*ind);
        save=0;
        long long int taken=0;
        for(long long int i=0;i<wind.length();i++){
            if(wind[i]==dir1 && dirCnt1>0){
                dirCnt1--;
                save=max(save,i+1);
            }
        }
        for(long long int i=0;i<wind.length();i++){
            if(wind[i]==dir2 && dirCnt1>0){
                dirCnt1--;
                save=max(save,i+1);
                taken=max(taken,i+1);
            }
        }
        for(long long int i=0;i<wind.length();i++){
            if(wind[i]==dir2 && dirCnt2>0){
                dirCnt2--;
                save=max(save,i+1);
                if(i+1>taken && dirCnt2>0){
                     dirCnt2--;
                }
            }
        }
        if(dirCnt2>0)
            save=(long long int)wind.length();
        sm=sm+save;
    }
    if(dirCnt2>0){
        if(totalEligible2==0)
            return -1;
        sm=max(sm,(long long int)wind.length());
        sm=sm+remaining(dirCnt2,dir2,totalEligible2);
    }

    return sm;
}

long long int withOne(long long int dirCnt1, char dir1){
    long long int eligible[wind.length()]={0};
    long long int totalEligible1=0,ctr1=0;
    long long int sm=0,save=0;
    //cout<<dirCnt1<<" "<<dir1<<"\n";

    for(long long int i=0;i<wind.length();i++){
        if(wind[i]==dir1){
            totalEligible1++;
            ctr1++;
            if(ctr1<=dirCnt1){

                save=max(save,i+1);
                eligible[i]=1;
            }
        }
    }
    //cout<<save<<"\n";
    dirCnt1 = max(dirCnt1,ctr1) - ctr1;
    if(totalEligible1==0)
        return -1;
    for(long long int i=0;i<wind.length();i++){
        if(eligible[i]==1 && dirCnt1>0){
            eligible[i]=0;
            dirCnt1--;

            save=max(save,i+1);
        }
    }
    sm=save;
    if(dirCnt1>0){
       // cout<<"enter";
        sm=max(sm,(long long int)wind.length());
        sm=sm+remaining(dirCnt1,dir1,totalEligible1);
    }

    return sm;

}

int withZero(){
    return 0;
}


int main(){
    long long int x,y,fx,fy,cnt,n;
    cin>>x>>y>>fx>>fy;
    cin>>n;
    cin>>wind;

    char dir1=(char)0;
    char dir2=(char)0;

    long long int hor=fx-x;
    long long int ver=fy-y;

    if(hor>0){
        dir1='R';
    }else if(hor<0){
        dir1='L';
    }

    if(ver>0){
        dir2='U';
    }else if(ver<0){
        dir2='D';
    }

    if(dir1==(char)0){
        dir1=dir2;
        dir2=(char)0;
    }

    if(dir1==(char)0 && dir2==(char)0)
        cnt=0;
    else if(dir2==(char)0)
        cnt=1;
    else
        cnt=2;

    if(cnt==0){
        cout<<withZero();
    }else if(cnt==1){
        if(hor==0)
            cout<<withOne(abs(ver),dir1);
        else
            cout<<withOne(abs(hor),dir1);;
    }else{
        hor=abs(hor);
        ver=abs(ver);

        if(hor<ver){
            cout<<withTwo(hor, dir1, ver, dir2);
        }else if(ver<hor){
            cout<<withTwo(ver, dir2, hor, dir1);
        }else{
            long long int ans1=withTwo(hor, dir1, ver, dir2);
            long long int ans2=withTwo(ver, dir2, hor, dir1);
            if(ans1==-1 && ans2==-1){
                cout<<"-1";
            }else if(ans1==-1){
                cout<<ans2;
            }else if(ans2==-1){
                cout<<ans1;
            }else{
                cout<<min(ans1,ans2);
            }
        }
    }

    return 0;
}
