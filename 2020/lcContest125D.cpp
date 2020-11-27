class Solution {
private:
    int n;
    set<pair<int,int> > lampsPresent;
    multiset<int> xlamps;
    multiset<int> ylamps;
    multiset<int>::iterator xlampsIt;
    multiset<int>::iterator ylampsIt;
    multiset<pair<int,int> > diagonalLamps;
    multiset<pair<int,int> >::iterator diagonalLampsIt;

    void illuminateLamps(vector<vector<int>>& lamps){
        int x,y;
        for(int i=0;i<lamps.size();i++){
            x=lamps[i][0];
            y=lamps[i][1];

            lampsPresent.insert(make_pair(x,y));

            xlamps.insert(x);
            ylamps.insert(y);

            diagonalLamps.insert(make_pair(x+min(n-1-x,y),y-min(n-1-x,y)));
            diagonalLamps.insert(make_pair(x+min(n-1-x,n-1-y),y+min(n-1-x,n-1-y)));
            diagonalLamps.insert(make_pair(x-min(x,y),y-min(x,y)));
            diagonalLamps.insert(make_pair(x-min(x,n-1-y),y+min(x,n-1-y)));
        }
    }

    int getLampStatus(int x, int y){
        if(xlamps.count(x)>0 || ylamps.count(y)>0)
            return 1;
        if(diagonalLamps.count(make_pair(x+min(n-1-x,y),y-min(n-1-x,y)))>0)
            return 1;
        if(diagonalLamps.count(make_pair(x+min(n-1-x,n-1-y),y+min(n-1-x,n-1-y)))>0)
            return 1;
        if(diagonalLamps.count(make_pair(x-min(x,y),y-min(x,y)))>0)
            return 1;
        if(diagonalLamps.count(make_pair(x-min(x,n-1-y),y+min(x,n-1-y)))>0)
            return 1;
        return 0;
    }

    void switchOffAdjacentLamps(int x, int y){

        switchOffLamps(x,y);

        switchOffLamps(min(x+1,n-1),y);

        switchOffLamps(x,min(y+1,n-1));

        switchOffLamps(max(x-1,0),y);

        switchOffLamps(x,max(y-1,0));

        switchOffLamps(min(x+1,n-1),max(y-1,0));

        switchOffLamps(max(x-1,0),min(y+1,n-1));

        switchOffLamps(min(x+1,n-1),min(y+1,n-1));

        switchOffLamps(max(x-1,0),max(y-1,0));

    }

    bool isLampPresent(int x, int y){
        return lampsPresent.count(make_pair(x,y))>0;
    }

    void switchOffLamps(int x,int y){

        if(!isLampPresent(x,y))
            return;

        xlampsIt=xlamps.find(x);
        if(xlampsIt!=xlamps.end())
            xlamps.erase(xlampsIt);

        ylampsIt=ylamps.find(y);
        if(ylampsIt!=ylamps.end())
            ylamps.erase(ylampsIt);

        diagonalLampsIt=diagonalLamps.find(make_pair(x+min(n-1-x,y),y-min(n-1-x,y)));
        if(diagonalLampsIt != diagonalLamps.end())
            diagonalLamps.erase(diagonalLampsIt);

        diagonalLampsIt=diagonalLamps.find(make_pair(x+min(n-1-x,n-1-y),y+min(n-1-x,n-1-y)));
        if(diagonalLampsIt != diagonalLamps.end())
            diagonalLamps.erase(diagonalLampsIt);

        diagonalLampsIt=diagonalLamps.find(make_pair(x-min(x,y),y-min(x,y)));
        if(diagonalLampsIt != diagonalLamps.end())
            diagonalLamps.erase(diagonalLampsIt);

        diagonalLampsIt=diagonalLamps.find(make_pair(x-min(x,n-1-y),y+min(x,n-1-y)));
        if(diagonalLampsIt != diagonalLamps.end())
            diagonalLamps.erase(diagonalLampsIt);
    }

    vector<int> lampQueries(vector<vector<int>>& queries){
        vector<int> lampStatus;
        int x,y;

        for(int i=0;i<queries.size();i++){
            x=queries[i][0];
            y=queries[i][1];

            lampStatus.push_back(getLampStatus(x,y));
            switchOffAdjacentLamps(x,y);
        }

        return lampStatus;
    }

public:
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        n=N;
        illuminateLamps(lamps);
        return lampQueries(queries);
    }
};
