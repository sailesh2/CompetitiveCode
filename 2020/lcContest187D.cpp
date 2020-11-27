struct takenComp{
  bool operator() (pair<int,vector<int>> a , pair<int,vector<int>> b) const{
      return a.first<b.first;
  }
};


class Solution {
private:
    vector<vector<int>> matrix;

    multiset<pair<int,vector<int>>, takenComp> taken;
    multiset<pair<int,vector<int>>, takenComp>::iterator takenIt;

    set<vector<int>> has;
    int kSum;

    int sum(vector<int> indices){
        int s=0;
        for(int i=0;i<indices.size();i++){
            s=s+matrix[i][indices[i]];
        }
        return s;
    }

    vector<int> formNextIndices(vector<int> indices, int d){
        vector<int> next;
        for(int i=0;i<indices.size();i++){
            if(i==d)
            next.push_back(indices[i]+1);
            else
            next.push_back(indices[i]);
        }
        return next;
    }

    pair<bool,int> isPossible(vector<int> indices){
        int s=0;
        if(has.count(indices)>0)
            return make_pair(false,s);

        for(int i=0;i<indices.size();i++){
            if(indices[i] >= matrix[i].size()){
                return make_pair(false,s);
            }
            s=s+matrix[i][indices[i]];
        }
        return make_pair(true,s);
    }

    vector<int> findMinNextIndex(){
        takenIt = taken.begin();
        vector<int> min = takenIt->second;
        kSum=takenIt->first;
        taken.erase(takenIt);
        return min;
    }

    void print(vector<int> indices){
        for(int i=0;i<indices.size();i++){
            cout<<indices[i]<<" ";
        }
        cout<<"\n";
    }

public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        matrix = mat;
        int ctr=0;
        vector<int> t;
        for(int i=0;i<mat.size();i++){
            t.push_back(0);
        }
        taken.insert(make_pair(sum(t),t));
        vector<int> next;
        while(ctr<k){


            next = findMinNextIndex();

            for(int j=0;j<next.size();j++){
                vector<int> nextIndices = formNextIndices(next,j);
                pair<bool, int> isP = isPossible(nextIndices);

                if(isP.first){
                    taken.insert(make_pair(isP.second,nextIndices));
                    has.insert(nextIndices);
                }
            }

            ctr++;
        }

        return kSum;
    }
};
