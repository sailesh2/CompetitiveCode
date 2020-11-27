class Solution {
private:
    int total=0;
    set<string> tilesTaken;

    void allTiles(string curr, string tiles, int* has){
        if(curr.length()>0 && tilesTaken.count(curr)==0){
            tilesTaken.insert(curr);
            total++;
        }
        for(int i=0;i<tiles.length();i++){
            if(has[i]==0){
                has[i]=1;
                curr.push_back(tiles[i]);
                allTiles(curr,tiles,has);
                curr.pop_back();
                has[i]=0;
            }
        }
    }
public:
    int numTilePossibilities(string tiles) {
        int has[10]={0};
        allTiles("",tiles,has);
        return total;
    }
};
