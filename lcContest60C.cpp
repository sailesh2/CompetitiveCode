#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int cnt=0,save1,save2;
        while(1){
            cnt=0;
            save1=-1;
            save2=-1;
            for(int i=0;i<asteroids.size();i++){
                if(asteroids[i]>0){
                    cnt=1;
                    save1=i;
                }
                if(asteroids[i]<0 && cnt==1){
                    save2=i;
                    break;
                }
            }
            if(save1==-1 || save2==-1)
                break;
            if(abs(asteroids[save1]) > abs(asteroids[save2])){
                asteroids.erase(asteroids.begin()+save2);
            }else if(abs(asteroids[save1]) < abs(asteroids[save2])){
                asteroids.erase(asteroids.begin()+save1);
            }else{
                asteroids.erase(asteroids.begin()+save1);
                asteroids.erase(asteroids.begin()+save2);
            }
        }
        return asteroids;
    }
};
