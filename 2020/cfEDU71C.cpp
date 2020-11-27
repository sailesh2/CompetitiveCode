#include<bits/stdc++.h>

using namespace std;

string pillar(string s){
    string road="";
    int ctr=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='0'){
            if(i==0){
                road.push_back('0');
                road.push_back('0');
                ctr=ctr+2;
            }else{
                road.push_back('0');
                ctr++;
            }
        }else{
            road[ctr-1]='1';
            road.push_back('1');
            ctr++;
        }
    }

    return road;
}

int main(){
    long long int t;
    cin>>t;
    for(long long int i=0;i<t;i++){
        long long int n,pil,pipe;
        cin>>n>>pipe>>pil;
        string s,road;
        cin>>s;
        road = pillar(s);
        //cout<<road<<"\n";
        long long int c=0;
        for(long long int j=1;j<road.length();j++){
            if(road[j-1]=='0' && road[j]=='1'){
                c=c+pil*2+pipe*2;
            }else if(road[j-1]=='1' && road[j]=='0'){
                int cnt=0;

                for(long long int k=j;k<road.length();k++){
                    if(road[k]=='1'){
                        long long int d=k-j+1;
                        if( (d*(2*pil+pipe)) > (4*pipe + (d-2)*pipe + (d-1)*pil+2*pil) ){
                            c=c+(4*pipe + (d-2)*pipe + (d-1)*pil+2*pil);
                        }else{
                            c=c+(d*(2*pil+pipe));
                        }
                        cnt=1;
                        j=k;
                        break;
                    }
                }
                if(cnt==0){
                    long long int d= (road.length())-j;
                    c=c+d*pil+(d-1)*pipe+2*pipe;
                    break;
                }
            }else if(road[j-1]=='0' && road[j]=='0'){
                c=c+pil+pipe;
            }else{
                c=c+2*pil+pipe;
            }
        }

        cout<<c+pil<<"\n";
    }
    return 0;
}
