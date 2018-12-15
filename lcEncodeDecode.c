#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string shortS=longUrl.substr(longUrl.find_last_of("\\")+1);
        return "http://tinyurl.com/"+shortS;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {

    }
};


int main(){
    Solution solution;
    solution.encode("https://leetcode.com/problems/design-tinyurl");
    return 0;
}
