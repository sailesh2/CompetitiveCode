class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(),salary.end());
        double tot=0;
        for(int i=1;i<salary.size()-1;i++)
            tot=tot+salary[i];

        double cnt = salary.size();
        cnt=cnt-2;
        if(cnt<=0)
            return 0;
        else
            return tot/cnt;
    }
};
