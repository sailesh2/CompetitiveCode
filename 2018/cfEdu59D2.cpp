#include<bits/stdc++.h>

using namespace std;
int pow2[100000]={0};
vector<string> mat;
void createPow(int n){
    int p=1;
    while(p<=n+1){
        pow2[p]=1;
        p=p*2;
    }
}

bool isPow2(int v){
    return pow2[v]==1;
}

int minimum(int a, int b, int c ,int d){
    return min(a,min(b,min(c,d)));
}

int isEqual(int a, int b , int c, int d){
    return a==b && b==c && c==d;
}

string convertHexToBin(char a){
    switch(a){
    case '0':
        return "0000";
    case '1':
        return "0001";
    case '2':
        return "0010";
    case '3':
        return "0011";
    case '4':
        return "0100";
    case '5':
        return "0101";
    case '6':
        return "0110";
    case '7':
        return "0111";
    case '8':
        return "1000";
    case '9':
        return "1001";
    case 'A':
        return "1010";
    case 'B':
        return "1011";
    case 'C':
        return "1100";
    case 'D':
        return "1101";
    case 'E':
        return "1110";
    case 'F':
        return "1111";
    }
}

int getValue(char a, int dig){
    string digs = convertHexToBin(a);
    return (int)digs[dig] - 48;
}
pair<bool,int> findComp(pair<int,int> fst, pair<int,int> sec, pair<int,int> thr, pair<int,int> fr ,
                       int subSize){

    if(subSize == 1){

        return make_pair(true,getValue(mat[fst.first/4][fst.second/4],fst.second%4));
    }

    pair<int,int> sub1 = make_pair((fst.first + sec.first)/2, (fst.second + sec.second)/2);

    pair<int,int> sub2 = make_pair((fst.first + thr.first)/2, (fst.second + thr.second)/2);

    pair<int,int> sub3 = make_pair((sec.first + fr.first)/2, (sec.second + fr.second)/2);

    pair<int,int> sub4 = make_pair((thr.first + fr.first)/2, (thr.second + fr.second)/2);

    pair<int,int> mid = make_pair(sub2.first,sub1.second);

    pair<int,int> sub1Ans = findComp(fst,sub1,sub2,mid,subSize/2);
    pair<int,int> sub2Ans = findComp(make_pair(sub1.first,sub1.second+1),sec,make_pair(mid.first,mid.second+1),sub3,subSize/2);
    pair<int,int> sub3Ans = findComp(make_pair(sub2.first+1,sub2.second),make_pair(mid.first+1,mid.second),thr,sub4,subSize/2);
    pair<int,int> sub4Ans = findComp(make_pair(mid.first+1,mid.second+1),make_pair(sub3.first+1,sub3.second),make_pair(sub4.first+1,sub4.second),fr,subSize/2);

    if(!sub1Ans.first || !sub2Ans.first || !sub3Ans.first || !sub4Ans.first){
        return make_pair(false,minimum(sub1Ans.second, sub2Ans.second, sub3Ans.second, sub4Ans.second));
    }else{
        if(isEqual(sub1Ans.first, sub2Ans.first, sub3Ans.first, sub4Ans.first)){
            return make_pair(true,sub1Ans.first);
        }else{
            return make_pair(false,subSize/2);
        }
    }
}

int main(){
    int n;
    cin>>n;
    string s;
    createPow(n);
    for(int i=0;i<n;i++){
        cin>>s;
        mat.push_back(s);
    }
    if(isPow2(n)){
        cout<<findComp(make_pair(1,1),make_pair(1,n),make_pair(n,1),make_pair(n,n),n).second;
    }else{
        cout<<"1";
    }
    return 0;
}
