#include<stdio.h>
#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;


// * Definition for a point.
  struct Point {
      int x;
      int y;
      Point() : x(0), y(0) {}
      Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point>& points) {

        int size = points.size();

        if(size==1)
            return 1;

        map<pair<int,int>,int> has;

        map<pair<int,int>,int>::iterator hasIt;
        int x,y,c1;
        for(int i=0;i<size;i++){
            x=points.at(i).x;
            y=points.at(i).y;
            hasIt=has.find(make_pair(x,y));
            if(hasIt!=has.end()){
                points.erase(points.begin()+i);
                c1=hasIt->second;
                has.erase(hasIt);
                has.insert(make_pair(make_pair(x,y),c1+1));
                size--;
                i--;
                cout<<"not";
            } else {
                cout<<"ought";
                has.insert(make_pair(make_pair(x,y),1));
            }
        }



        size=points.size();

        set<int> st;
        map<pair<int,int>,pair<set<int>,int> > mp;
        map<pair<int,int>,pair<set<int>,int> >::iterator mpIt;
        int x1,y1,x2,y2;
        int maxi=0,ctr;
        float m,c;
        pair<int,int> p;


        for(int i=0;i<size;i++){
            for(int j=i+1;j<size;j++){
                x1=points.at(i).x;
                y1=points.at(i).y;
                x2=points.at(j).x;
                y2=points.at(j).y;

                if(x2==x1){
                    m=1000000000;
                    c=x2;
                } else {
                    m = ((float)(y2-y1))/(x2-x1);
                    c = y1 - (m*x1);
                }
                mpIt=mp.find(make_pair(m,c));
                if(mpIt == mp.end()){
                    ctr=2;
                    st.clear();
                    st.insert(i);
                    st.insert(j);
                } else {
                    st = mpIt->second.first;

                    ctr = mpIt->second.second;
                    if(st.count(i)==0){
                        ctr++;
                        st.insert(i);
                    }
                    if(st.count(j)==0){
                        ctr++;
                        st.insert(j);
                    }
                    mp.erase(mpIt);
                }

                if(ctr>maxi){
                    maxi=ctr;
                    p=make_pair(m,c);
                }
                mp.insert(make_pair(make_pair(m,c),make_pair(st,ctr)));
            }
        }

        int ind;
cout<<size;
        if(size==1){
            maxi=1;
            ind=0;
            x1=points.at(ind).x;
            y1=points.at(ind).y;
            maxi=maxi+(has.find(make_pair(x1,y1))->second)-1;

        } else {
            mpIt=mp.find(p);

            st=mpIt->second.first;
            set<int>::iterator stIt;
            for(stIt=st.begin();stIt!=st.end();stIt++){
                ind=*stIt;
                x1=points.at(ind).x;
                y1=points.at(ind).y;
                maxi=maxi+(has.find(make_pair(x1,y1))->second)-1;
            }
        }
        return maxi;
    }
};


int main(){
    vector<Point> p;
    struct Point p1;
    p1.x=1;
    p1.y=1;
    struct Point p2;
    p2.x=1;
    p2.y=1;
    struct Point p3;
    p3.x=1;
    p3.y=1;
    p.push_back(p1);
    p.push_back(p2);
    p.push_back(p3);
    Solution sol;
    cout<<sol.maxPoints(p);
    return 0;
}
