#include<bits/stdc++.h>

using namespace std;
int n;

char getDiffChar(char c1, char c2){
    if(c1=='a' && c2=='a'){
        return 'b';
    }else if(c1=='a' && c2=='b'){
        return 'c';
    }else if(c1=='a' && c2=='c'){
        return 'b';
    }

    if(c1=='b' && c2=='a'){
        return 'c';
    }else if(c1=='b' && c2=='b'){
        return 'c';
    }else if(c1=='b' && c2=='c'){
        return 'a';
    }

    if(c1=='c' && c2=='a'){
        return 'b';
    }else if(c1=='c' && c2=='b'){
        return 'a';
    }else if(c1=='c' && c2=='c'){
        return 'b';
    }
}

bool isValid(string s, string s1, string s2){
    for(int i=0;i<s.length()-1;i++){

        if( (s[i]==s1[0] && s[i+1]==s1[1]) || (s[i]==s2[0] && s[i+1]==s2[1]) )
            return false;
    }

    return true;
}

string generateEquiString(char fir, char sec, char thi, string s1, string s2){

    string s="";
    for(int i=0;i<n;i++){
        s.push_back(fir);
        s.push_back(sec);
        s.push_back(thi);
    }
    if(isValid(s,s1,s2)){
        return "YES\n"+s;
    }else{
        return "NO\n";
    }
}

string generateString(char fir, char sec, char thi, string s1, string s2){

    string s="";
    for(int i=0;i<n;i++){
        s.push_back(fir);
        s.push_back(sec);
    }
    for(int i=0;i<n;i++){
        s.push_back(thi);
    }
    if(isValid(s,s1,s2)){
        return "YES\n"+s;
    }else{
        return "NO\n";
    }
}

string getEqualString(string s1, string s2){
    char fir = s1[0];
    char sec,thi;

    if(s1[0]==s1[1] && s2[0]==s2[1]){
        sec = getDiffChar(fir,fir);
        thi = getDiffChar(fir,sec);
        return generateString(fir,sec,thi,s1,s2);
    }else if(s1[0]==s1[1]){
        fir=getDiffChar(s2[1],s1[0]);
        sec=s2[1];
        thi=s1[0];
        return generateEquiString(fir,sec,thi,s1,s2);
    }else if(s2[0]==s2[1]){
        fir=getDiffChar(s1[1],s1[0]);
        sec=s1[1];
        thi=s1[0];
        return generateEquiString(fir,sec,thi,s1,s2);
    }else{
        fir=s1[1];
        sec=getDiffChar(s1[0],fir);
        thi=s1[0];


        string s="";
        for(int i=0;i<n;i++){
            s.push_back(fir);
        }

        for(int i=0;i<n;i++){
            s.push_back(sec);
        }

        for(int i=0;i<n;i++){
            s.push_back(thi);
        }

        if(isValid(s,s1,s2)){
            return "YES\n"+s;
        }else{
            return "NO\n";
        }
    }
}

string getSameString(string s1,string s2){
    char fir,sec,thi;
    if(s1[1]==s2[0]){

        fir = getDiffChar(s1[0],s1[1]);
        sec = s1[1];
        thi = s1[0];
    }else{
        fir = s1[0];
        sec = s2[0];
        thi = getDiffChar(fir,sec);
    }

    return generateString(fir,sec,thi,s1,s2);
}

string getDiffString(string s1, string s2){
    char fir = s1[0];
    char sec,thi;
    if(s1[1]==s2[0]){
        sec = getDiffChar(s1[0],s1[1]);
        thi = s1[1];
    }else{
        fir=s1[1];
        sec=s1[0];
        thi=s2[0];
    }
    if(s1[0]==s1[1]){
        sec=getDiffChar(s1[1],s2[0]);
        thi=s2[0];
        return generateString(fir,sec,thi,s1,s2);
    }

    string s="";
    for(int i=0;i<n;i++){
        s.push_back(fir);
    }

    for(int i=0;i<n;i++){
        s.push_back(sec);
    }

    for(int i=0;i<n;i++){
        s.push_back(thi);
    }

    if(isValid(s,s1,s2)){
        return "YES\n"+s;
    }else{
        return "NO\n";
    }
}

string getOneString(string s1, string s2){
    if(isValid("abc",s1,s2)){
        return "YES\nabc";
    }else if(isValid("acb",s1,s2)){
        return "YES\nacb";
    }else if(isValid("bac",s1,s2)){
        return "YES\nbac";
    }else if(isValid("bca",s1,s2)){
        return "YES\nbca";
    }else if(isValid("cab",s1,s2)){
        return "YES\ncab";
    }else if(isValid("cba",s1,s2)){
        return "YES\ncba";
    }else{
        return "NO";
    }
}
int main(){
    string s1,s2;
    cin>>n;
    cin>>s1>>s2;

    if(n==1){
        cout<<getOneString(s1,s2);
    }else{
        if(s1[0]==s2[0]){
            cout<<getEqualString(s1,s2);
        }else if(s2[0]==s2[1]){
            cout<<getSameString(s1,s2);
        }else{
            cout<<getDiffString(s1,s2);
        }
    }
    return 0;
}
