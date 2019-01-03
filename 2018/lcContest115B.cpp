class Solution {
private:
    int createCellValue(int prevVal, int nextVal){
        return prevVal == nextVal ? 1 : 0;
    }

    vector<int> createNextCells(vector<int>& cells){
        vector<int> newCells;
        newCells.push_back(0);
        for(int i=1;i<7;i++){
            newCells.push_back(createCellValue(cells[i-1],cells[i+1]));
        }
        newCells.push_back(0);
        return newCells;
    }

    string getString(vector<int>& cells){
        string s="";
        for(int i=0;i<8;i++){
            s=s+(char)(cells[i]+48);
        }
        return s;
    }

public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        map<string,int> has;
        map<string,int>::iterator hasIt;

        vector<int> cellStrings[1000];
        int repeatIndexStart=0;
        int repeatIndexEnd=999;

        cellStrings[0]=cells;
        has.insert(make_pair(getString(cells),0));
        for(int i=1;i<1000;i++){
            cells = createNextCells(cells);
            hasIt=has.find(getString(cells));
            if(hasIt!=has.end()){
                repeatIndexStart = hasIt->second;
                repeatIndexEnd = i;
                break;
            }
            has.insert(make_pair(getString(cells),i));
            cellStrings[i]=cells;
        }

            int r = (N-repeatIndexStart)%(repeatIndexEnd - repeatIndexStart);
            return cellStrings[repeatIndexStart + r ];

    }
};
