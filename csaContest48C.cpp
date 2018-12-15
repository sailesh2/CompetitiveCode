#include<bits/stdc++.h>

using namespace std;

string convertToString(int val){
    string rev="",res="";
    int ctr=0;
    while(val>0){
        res=res+(char)(val%10+48);
        ctr++;
        val=val/10;
    }
    if(ctr==0){
        res=res+"000";
    }else if(ctr==1){
        res=res+"00";
    }else if(ctr==2){
        res=res+"0";
    }
    for(int i=res.length()-1;i>=0;i--){
        rev=rev+res[i];
    }
    return rev;
}

int divBy8(string s){
    int v=((int)(s[0]-48))*10+(int)(s[1]-48);
    int revV=((int)(s[1]-48))*10+(int)(s[0]-48);

    if(v%8==0 && revV%8!=0)
        return v;
    else if(v%8!=0 && revV%8==0)
        return revV;
    else if(v%8==0 && revV%8==0){
        if(v==8 || revV==8)
            return 80;
        else
            return min(v,revV);
    }else
        return -1;
}

int main(){
    string s;
    cin>>s;
    int l=s.length();
    if(l==1){
        if(s[0]=='8'){
            cout<<s;
        }else{
            cout<<"-1";
        }
    }else if(l==2){
        cout<<divBy8(s);
    }else{
        char temp;
        string div,ansS;
        vector<char> pref;
        vector<string> ans;
        int prefSave,v,save1,save2,save3;

        int has[10][3]={0};
        int cnt[10]={0};
        for(int i=0;i<l;i++){
            v=(int)(s[i]-48);
            if(cnt[v]<3)
                has[v][cnt[v]++]=i+1;
        }

        for(int i=0;i<1000;i=i+8){
            div=convertToString(i);
            int save[10]={0};
            v=(int)(div[0]-48);
            save1=has[v][save[v]++];
            v=(int)(div[1]-48);
            save2=has[v][save[v]++];
            v=(int)(div[2]-48);
            save3=has[v][save[v]++];

            if(save1>0 && save2>0 && save3>0){

                pref.clear();
                for(int i=0;i<l;i++){
                    if(i+1!=save1 && i+1!=save2 && i+1!=save3){
                        pref.push_back(s[i]);
                    }
                }
                sort(pref.begin(),pref.end());
                if(pref.size()>0 && pref[0]=='0'){
                    prefSave=0;
                    for(int i=1;i<pref.size();i++){
                        if(pref[i]!='0'){
                            prefSave=i;
                            break;
                        }
                    }
                    if(prefSave>0){
                        temp=pref[prefSave];
                        pref[prefSave]=pref[0];
                        pref[0]=temp;
                        ansS="";
                        for(int i=0;i<pref.size();i++){
                            ansS=ansS+pref[i];
                        }
                        ans.push_back(ansS+div);
                    }
                }else{
                    ansS="";
                    for(int i=0;i<pref.size();i++){
                        ansS=ansS+pref[i];
                    }
                    if((ansS+div)[0]!='0')
                        ans.push_back(ansS+div);
                }
            }
        }
        if(ans.size()==0)
            cout<<"-1";
        else{
            sort(ans.begin(),ans.end());
            cout<<ans[0];
        }
    }
    return 0;
}
