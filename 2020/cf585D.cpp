#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int leftV=0;
    int leftQ=0;
    int rightV=0;
    int rightQ=0;
    for(int i=0;i<n/2;i++){
        if(s[i]=='?'){
            leftQ++;
        }else{
            leftV=leftV+(int)s[i]-48;
        }
    }

    for(int i=n/2;i<n;i++){
        if(s[i]=='?'){
            rightQ++;
        }else{
            rightV=rightV+(int)s[i]-48;
        }
    }

    if(abs(leftQ-rightQ)%2!=0){
        cout<<"Monocarp";
    }else{
        if(leftQ<rightQ){
            int dif=(rightQ-leftQ)/2;
            int difV=abs(leftV-rightV);
            if(leftV<=rightV){
                cout<<"Monocarp";
            }else{
                if(9*dif==difV){
                    cout<<"Bicarp";
                }else{
                    cout<<"Monocarp";
                }
            }
        }else if(leftQ==rightQ){
            if(leftV==rightV){
                cout<<"Bicarp";
            }else{
                cout<<"Monocarp";
            }
        }else{
            int dif=(leftQ-rightQ)/2;
            int difV=abs(leftV-rightV);
            if(rightV<=leftV){
                cout<<"Monocarp";
            }else{
                if(9*dif==difV){
                    cout<<"Bicarp";
                }else{
                    cout<<"Monocarp";
                }
            }
        }
    }
    return 0;
}
