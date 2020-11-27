#include<bits/stdc++.h>

using namespace std;

bool charPresent[100005][26];
char allCharEqual[100005];

int n;
void storeCharPresent(string* strings){
    for(int i=0;i<n;i++){
        for(int j=0;j<26;j++){
            if(i>0)
            charPresent[i][j] = charPresent[i-1][j];
            else
            charPresent[i][j] = false;
        }
        for(int j=0;j<strings[i].length();j++){
            charPresent[i][strings[i][j]-'a']=true;
        }
    }
}

void storeAllCharEqual(string* strings){
    for(int i=0;i<n;i++){
        int ctr=0;
        char prev=strings[i][0];
        for(int j=1;j<strings[i].length();j++){
            if(strings[i][j]!=prev){
                ctr=1;
                break;
            }
        }
        if(ctr==0){
            allCharEqual[i]=prev;
        }else{
            allCharEqual[i]='#';
        }
    }
}


long long int findMultipleChar(int index, string* strings, char ch){
    if(allCharEqual[index] == ch){
        if(index-1>=0){
            long long int prev = findMultipleChar(index-1, strings, ch);
            long long int l = strings[index].length();
            return l*(prev+1) + prev;
        }else{
            return (long long int)strings[index].length();
        }
    }else{
        long long int ctr1=0,ctr2=0;
        for(int i=0;i<strings[index].length();i++){
            if(strings[index][i]==ch){
                ctr1++;
            }else{
                break;
            }
        }

        for(int i=strings[index].length()-1;i>=0;i--){
            if(strings[index][i]==ch){
                ctr2++;
            }else{
                break;
            }
        }
        long long int maxCtr;

        if(index-1>=0 && charPresent[index-1][ch-'a'])
            maxCtr = ctr1+ctr2+1;
        else
            maxCtr = max(ctr1,ctr2);

        long long int subctr=0;
        for(int i=0;i<strings[index].length();i++){
            if(strings[index][i]==ch){
                subctr++;
                maxCtr=max(maxCtr,subctr);
            }else{
                subctr=0;
            }
        }

        return maxCtr;
    }
}

int main(){
    cin>>n;

    string strings[n];
    for(int i=0;i<n;i++){
        cin>>strings[i];
    }

    storeCharPresent(strings);
    storeAllCharEqual(strings);

    if(allCharEqual[n-1]!='#'){
        long long int v =findMultipleChar(n-2,strings,allCharEqual[n-1]);
        long long int l = strings[n-1].length();
        cout<<l*(v+1)+v;
    }else{
        long long int ctr1=1,ctr2=1;
        char prev = strings[n-1][0];
        int saveF=0;
        for(int i=1;i<strings[n-1].length();i++){
            if(strings[n-1][i]==prev){
                ctr1++;
                saveF=i;
            }else{
                break;
            }
        }


        char last = strings[n-1][strings[n-1].length()-1];
        int saveL=strings[n-1].length()-1;
        for(int i=strings[n-1].length()-2;i>=0;i--){
            if(strings[n-1][i]==last){
                ctr2++;
                saveL=i;
            }else{
                break;
            }
        }

        long long int maxCtr;
        if(saveF<saveL && strings[n-1][saveF] == strings[n-1][saveL]){
            maxCtr=ctr1+ctr2;
            if(charPresent[n-2][strings[n-1][saveF]-'a'])
            maxCtr++;

        }else{
            if(charPresent[n-2][strings[n-1][saveF]-'a'])
            ctr1++;

            if(charPresent[n-2][strings[n-1][saveL]-'a'])
            ctr2++;

            maxCtr=max(ctr1,ctr2);
        }

        long long int subctr=1;
        prev = strings[n-1][0];
        for(int i=1;i<strings[n-1].length();i++){
            if(strings[n-1][i]==prev){
                subctr++;
                maxCtr=max(maxCtr,subctr);
            }else{
                subctr=1;
                prev=strings[n-1][i];
            }
        }
        maxCtr=max(maxCtr,subctr);
        cout<<maxCtr;
    }
    return 0;
}
