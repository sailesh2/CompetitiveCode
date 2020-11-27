class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int Minx=-1000000000;
        multiset<pair<int,int>> vals;
        multiset<pair<int,int>>::iterator valsIt;
        int i;
        for(i=1;i<points.size();i++){
            if((points[i][0]-points[0][0])<=k){
                vals.insert(make_pair(points[i][0]-Minx+points[i][1],i));
            }else{
                break;
            }
        }
        int j=0;
        int maxi=Minx;
        while(j<points.size()){
            if(vals.size()>0){
            valsIt=vals.end();
            valsIt--;
            int ind = valsIt->second;
            maxi=max(maxi,points[ind][0]-points[j][0]+points[j][1]+points[ind][1]);
            }
            j++;

            if(j==points.size())
                break;

            valsIt=vals.find(make_pair(points[j][0]-Minx+points[j][1],j));
            if(valsIt!=vals.end())
                vals.erase(valsIt);

            i=max(i,j+1);
            while(i<points.size()){
                    if((points[i][0]-points[j][0])<=k){
                        vals.insert(make_pair(points[i][0]-Minx+points[i][1],i));
                    }else{
                        break;
                    }
                    i++;
            }
        }
        return maxi;
    }
};
