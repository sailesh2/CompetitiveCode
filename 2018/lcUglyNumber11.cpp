#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long int> que;
        que.insert(1);
        long long int v;
        for(int i=0;i<n;i++){
            v = *(que.begin());
            que.erase(que.begin());
            que.insert(v*2);
            que.insert(v*3);
            que.insert(v*5);
        }
        return v;
    }
};
