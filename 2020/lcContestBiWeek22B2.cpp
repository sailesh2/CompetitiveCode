class Solution {
private:
    set<pair<int,int>> st;
    set<pair<int,int>>::iterator stIt;

    bool isAisle1(int r){
        bool is= st.count(make_pair(r,1))==0 && st.count(make_pair(r,2))==0 && st.count(make_pair(r,3))==0
        && st.count(make_pair(r,4))==0;
        if(is){
            st.insert(make_pair(r,1));
            st.insert(make_pair(r,2));
            st.insert(make_pair(r,3));
            st.insert(make_pair(r,4));
        }
        return is;
    }

    bool isAisle2(int r){
        bool is= st.count(make_pair(r,5))==0 && st.count(make_pair(r,6))==0 && st.count(make_pair(r,7))==0
        && st.count(make_pair(r,8))==0;
        if(is){
            st.insert(make_pair(r,5));
            st.insert(make_pair(r,6));
            st.insert(make_pair(r,7));
            st.insert(make_pair(r,8));
        }
        return is;
    }

    bool isMiddle(int r){
        return st.count(make_pair(r,3))==0 && st.count(make_pair(r,4))==0 && st.count(make_pair(r,5))==0
        && st.count(make_pair(r,6))==0;

    }

public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        vector<int> rows;
        set<int> rowsTaken;
        for(int i=0;i<reservedSeats.size();i++){
            int r = reservedSeats[i][0]-1;
            int c = reservedSeats[i][1]-1;
            st.insert(make_pair(r,c));
            if(rowsTaken.count(r)==0){
                rowsTaken.insert(r);
                rows.push_back(r);
            }
        }
        int ctr=0;

        for(int i=0;i<rows.size();i++){
            int r=rows[i];
            if(isAisle1(r)){
                ctr++;
            }
            if(isAisle2(r)){
                ctr++;
            }
            if(isMiddle(r)){
                ctr++;
            }
        }
        int rl = rows.size();
        int leftR = n - rl;

        return ctr + 2*leftR;
    }
};
