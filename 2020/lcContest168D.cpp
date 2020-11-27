class Solution {
private:
	vector<int> openBoxes;
	int presentBoxes[2000]={0};
	int alreadyOpenedBoxes[2000]={0};

    vector<int> status;
    vector<int> candies;
    vector<vector<int>> keys;
    vector<vector<int>> containedBoxes;
    vector<int> initialBoxes;

	void init(){
		for(int i=0;i<initialBoxes.size();i++){
			presentBoxes[initialBoxes[i]]=1;
			if(status[initialBoxes[i]]==1)
				openBoxes.push_back(initialBoxes[i]);
        }
    }

int openBox(int box){
	int c=0;
    if(alreadyOpenedBoxes[box]==0){
        alreadyOpenedBoxes[box]=1;
        c=c+candies[box];
        for(int i=0;i<keys[box].size();i++){
            int keyForBox = keys[box][i];
            status[keyForBox]=1;
            if(presentBoxes[keyForBox]==1 && alreadyOpenedBoxes[keyForBox]==0){
                openBoxes.push_back(keyForBox);
            }
        }

        for(int i=0;i<containedBoxes[box].size();i++){
            int containedBox = containedBoxes[box][i];
            presentBoxes[containedBox]=1;
            if(status[containedBox]==1){
                openBoxes.push_back(containedBox);
            }
        }
	}
	return c;
}

int maxCandies(){
	int c=0;
	for(int i=0;i<openBoxes.size();i++){
		int box = openBoxes[i];
		c=c+openBox(box);
    }
    return c;
}

public:
int maxCandies(vector<int>& statuses, vector<int>& candieses, vector<vector<int>>& keyses,   vector<vector<int>>& containedBoxeses, vector<int>& initialBoxeses) {

		status = statuses;
		candies = candieses;
		keys = keyses;
		containedBoxes = containedBoxeses;
		initialBoxes = initialBoxeses;

		init();

		return maxCandies();
    	}
};
