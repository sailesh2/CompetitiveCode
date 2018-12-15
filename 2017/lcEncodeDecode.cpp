#include<bits/stdc++.h>

using namespace std;

class Solution {

private:

    map<string,string> hashMap;

    long long int hashOf(string toHash){
        long long int hashVal = 0,p=1;
        for(int i=0;i<toHash.length();i++){
            hashVal=(hashVal+p*(toHash[i]-'0'))%257;
            p=(p*123)%257;
        }
        return hashVal;

    }

    string to_string(long long int v){
        string res="";
        int a;
        while(v>0){
            a=v%10;
            res=res+(char)v;
            v=v/10;
        }
        string rev="";
        for(int i=res.length()-1;i>=0;i--){
            rev=rev+res[i];
        }
        return rev;
    }
public:


    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string shortS=longUrl.substr(longUrl.find_last_of("/")+1);
        string hashed=to_string(hashOf(shortS));
        hashMap.insert(make_pair(hashed,longUrl));
        return "http://tinyurl.com/"+hashed;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string longS=shortUrl.substr(shortUrl.find_last_of("/")+1);
        string original = (hashMap.find(longS))->second;
        return original;
    }
};


int main(){
    Solution solution;
    cout<<solution.encode("https://leetcode.com/problems/design-tinyurl");

    return 0;
}
