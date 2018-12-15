#include<bits/stdc++.h>

using namespace std;
int main(){
    long long int t,n,m,a,b,dir,saveMax,saveMin,ctr,maxR,minR;
    long long int h1,h2,w,x,y,z,h,u,d,maxih,minih,sm,val;
    double answer;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>m;
        cin>>h1>>h2>>w>>x>>y>>z;
        vector<long long int> heights;
        heights.push_back(h1);
        maxih=0;
        minih=1000000000;
        saveMax=0;
        saveMin=0;
        heights.push_back(h2);

        for(int j=2;j<n;j++){
            h=(((w*heights[j-2])%z + (x*heights[j-1])%z)%z + y)%z;
            heights.push_back(h);
        }
        long long int people[m][4];
        maxR=0;
        minR=n-1;
        for(int j=0;j<m;j++){
            cin>>a>>b>>u>>d;
            maxR=max(maxR,a-1);
            maxR=max(maxR,b-1);
            minR=min(minR,a-1);
            minR=min(minR,b-1);
            people[j][0]=a;
            people[j][1]=b;
            people[j][2]=u;
            people[j][3]=d;
        }


        for(int j=minR;j<=maxR;j++){
            if(heights[j]>maxih){
                maxih=heights[j];
                saveMax=j;
            }
            if(heights[j]<minih){
                minih=heights[j];
                saveMin=j;
            }
        }

        if(saveMax<saveMin){
            dir=0;
        }else{
            dir=1;
        }

        //cout<<"has come to -- 1\n";

        vector<pair<long long int,long long int> > jumps[n];

        for(int j=0;j<m;j++){
            a=people[j][0];
            b=people[j][1];
            u=people[j][2];
            d=people[j][3];
            maxR=max(maxR,a-1);
            maxR=max(maxR,b-1);
            minR=min(minR,a-1);
            minR=min(minR,b-1);
            if(a<b){
                if(dir==0){
                    val=d;
                }else{
                    val=u;
                }

                jumps[a-1].push_back(make_pair(val,0));
                jumps[b-1].push_back(make_pair(val,1));
            }else{
                if(dir==0){
                    val=u;
                }else{
                    val=d;
                }

                jumps[b-1].push_back(make_pair(val,0));
                //if(a<n)
                jumps[a-1].push_back(make_pair(val,1));
            }
        }

        if(maxih==minih){
            answer=0;
        }else{
            set<long long int> maxJmps;
            set<long long int>::iterator maxJmpsIt;
            map<long long int,long long int> has;
            map<long long int,long long int>::iterator hasIt;
            long long int ans[n]={0};
            pair<long long int,long long int> pr;
            for(int j=0;j<n;j++){
                for(int k=0;k<jumps[j].size();k++){
                    pr=jumps[j][k];
                    if(pr.second==0){
                        hasIt = has.find(pr.first);
                        ctr=0;
                        if(hasIt!=has.end()){
                            ctr=hasIt->second;
                            has.erase(hasIt);
                        }
                        ctr++;
                        has.insert(make_pair(pr.first,ctr));
                        maxJmps.insert(pr.first);
                    }
                    else{
                        hasIt = has.find(pr.first);
                        if(hasIt!=has.end()){
                            ctr=hasIt->second;
                            ctr--;
                            has.erase(hasIt);


                            if(ctr>0){
                                has.insert(make_pair(pr.first,ctr));
                            }else{
                                maxJmps.erase(maxJmps.find(pr.first));
                            }
                        }
                    }
                }
                maxJmpsIt = maxJmps.begin();
                if(maxJmpsIt!=maxJmps.end()){
                    ans[j]=*maxJmpsIt;
                }
            }
            sm=0;
            for(int j=min(saveMax,saveMin);j<max(saveMax,saveMin);j++){
                sm=(sm+ans[j])%z;
            }
            answer = (double)(maxih-minih-sm)/2;
        }
        cout<<"Case #"<<i+1<<": ";

        printf("%0.6f\n",answer);
    }
    return 0;
}
