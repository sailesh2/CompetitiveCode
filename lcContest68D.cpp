#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        map<int,int> mp;
        map<int,int>::iterator mpIt;
        vector<int> brr=arr;
        sort(brr.begin(),brr.end());
        int maxi=0;
        for(int i=0;i<brr.size();i++){
            mpIt=mp.find(brr[i]);
            if(mpIt!=mp.end()){
                mp.erase(mpIt);
            }
            mp.insert(make_pair(brr[i],i));

         }
        int ctr=0,mini,save,breakp,savem;
        for(int i=0;i<arr.size();i++){
            mpIt=mp.find(arr[i]);
            maxi=i;
            mini=i;
            save=arr[i];
            if(mpIt->second>maxi){
                maxi=mpIt->second;
                save=arr[i];
            }
            if(mpIt->second<mini){
                mini=mpIt->second;
                savem=arr[i];
            }
            ctr++;
            for(int j=i+1;j<=maxi;j++){
                mpIt=mp.find(arr[j]);
                if(mpIt->second>maxi){
                    maxi=mpIt->second;
                    save=arr[j];
                }
                if(mpIt->second<mini){
                    mini=mpIt->second;
                    savem=arr[i];
                }
            }
            breakp=i-1;
            for(int j=maxi;j>i;j--){
                if(arr[j]==save){
                    ctr++;
                }else{
                    breakp=j;
                    break;
                }
            }
            for(int j=i+1;j<=breakp;j--){
                if(arr[j]==savem){
                    ctr++;
                }else{
                    break;
                }
            }
            i=maxi;
        }



        map<int,int> mp2;
        map<int,int>::iterator mp2It;
        vector<int> brr2=arr;
        sort(brr2.begin(),brr2.end());
        int mini2=arr.size();
        for(int i=0;i<brr2.size();i++){
            mp2It=mp2.find(brr2[i]);
            if(mp2It==mp2.end()){
                mp2.insert(make_pair(brr2[i],i));
            }
         }
        int ctr2=0,maxi2,save2;
        for(int i=arr.size()-1;i>=0;i--){
            mp2It=mp2.find(arr[i]);
            mini2=i;
            maxi2=i;
            save2=arr[i];
            if(mp2It->second<mini2){
                mini2=mp2It->second;
                save2=arr[i];
            }
            if(mp2It->second>maxi2){
                maxi2=mp2It->second;
                savem=arr[i];
            }
            ctr2++;
            for(int j=i-1;j>=mini;j--){
                mp2It=mp2.find(arr[j]);
                if(mp2It->second<mini2){
                    mini2=mp2It->second;
                    save2=arr[j];
                }
                if(mp2It->second>maxi2){
                    maxi2=mp2It->second;
                    savem=arr[i];
                }
            }
            breakp=i;
            for(int j=mini2;j<i;j++){
                if(arr[j]==save2){
                    ctr2++;
                }else{
                    breakp=j;
                    break;
                }
            }
            for(int j=i-1;j>=breakp;j--){
                if(arr[j]==savem){
                    ctr2++;
                }else{
                    break;
                }
            }
            i=mini2;
        }
        return max(ctr,ctr2);
    }
};
