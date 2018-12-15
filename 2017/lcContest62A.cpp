#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char save=letters[0];
        for(int i=0;i<letters.size();i++){
            if(letters[i]>target){
                save=letters[i];
                break;
            }
        }
        return save;
    }
};
