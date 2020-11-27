class Solution {
private:
    double getMin(vector<int>& count){
        double m=0;
        for(int i=0;i<count.size();i++){
            if(count[i]>0){
                return (double)i;
            }
        }
        return m;
    }

    double getMax(vector<int>& count){
        double m=0;
        for(int i=0;i<count.size();i++){
            if(count[i]>0){
                m=i;
            }
        }
        return m;
    }

    double getMean(vector<int>& count){
        double m=0;
        int ctr=0;
        for(int i=0;i<count.size();i++){

            m=m+i*count[i];
            ctr=ctr+count[i];
        }
        if(ctr==0)
            return m;
        return m/ctr;
    }

    double getMedian(vector<int>& count){
        vector<int> v;
        int c=0;
        for(int i=0;i<count.size();i++){
            if(count[i]>0){
               v.push_back(i);
            }
            c=c+count[i];
        }
        int mid=c/2;
        if(c%2==0)
        {
            int ctr=0;
            for(int i=0;i<v.size();i++){
                ctr=ctr+count[v[i]];
                if(ctr>mid){
                    return (double)v[i];
                }else if(ctr==mid){
                    return double(v[i]+v[i+1])/2;
                }
            }
        }else{
            int ctr=0;
            for(int i=0;i<v.size();i++){
                ctr=ctr+count[v[i]];
                if(ctr>=mid){
                    return (double)v[i];
                }
            }

        }
        return 0.0;
    }

    double getMode(vector<int>& count){
        int m=0;
        int save=0;
        for(int i=0;i<count.size();i++){
            if(count[i]>m){
                m=count[i];
                save=i;
            }
        }
        return (double)save;
    }

public:
    vector<double> sampleStats(vector<int>& count) {
        vector<double> ans;
        ans.push_back(getMin(count));

        ans.push_back(getMax(count));

        ans.push_back(getMean(count));

        ans.push_back(getMedian(count));

        ans.push_back(getMode(count));

        return ans;

    }
};
