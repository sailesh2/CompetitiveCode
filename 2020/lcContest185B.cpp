class Solution {
private:
    map<int,map<string,int>> tableMp;
    map<int,map<string,int>>::iterator tableMpIt;

    set<string> uniqueFoods;
    set<string>::iterator uniqueFoodsIt;
    set<int> tables;
    set<int>::iterator tablesIt;

    int convertToInt(string s){
        int num=0;
        for(int i=0;i<s.length();i++){
            num=num*10 + (int)(s[i])-48;
        }
        return num;
    }

    string convertToStr(int num){
        string srev="",s="";
        while(num>0){
            srev.push_back((char)(num%10+48));
            num=num/10;
        }

        for(int i=srev.length()-1;i>=0;i--){
            s.push_back(srev[i]);
        }

        if(s.length()==0){
            s="0";
        }
        return s;
    }

    void insertFood(int tableNo, string food){
        uniqueFoods.insert(food);
        tables.insert(tableNo);

        tableMpIt = tableMp.find(tableNo);
        map<string,int> foods;
        map<string,int>::iterator foodsIt;
        if(tableMpIt != tableMp.end()){
            foods = tableMpIt->second;
            tableMp.erase(tableMpIt);
        }

        foodsIt = foods.find(food);
        int fc=0;
        if(foodsIt != foods.end()){
            fc=foodsIt->second;
            foods.erase(foodsIt);
        }

        foods.insert(make_pair(food,fc+1));
        tableMp.insert(make_pair(tableNo, foods));
    }

    vector<vector<string>> displayFood(){

        vector<vector<string>> tableDisplay;

        // insert headers
        vector<string> headers;
        headers.push_back("Table");
        uniqueFoodsIt = uniqueFoods.begin();
        while(uniqueFoodsIt != uniqueFoods.end()){
            headers.push_back(*uniqueFoodsIt);
            uniqueFoodsIt++;
        }
        tableDisplay.push_back(headers);

        // insert tables
        tablesIt = tables.begin();
        while(tablesIt != tables.end()){
            int tableNo = *tablesIt;
            string tableNoStr = convertToStr(tableNo);
            vector<string> foodTable;

            foodTable.push_back(tableNoStr);

            tableMpIt = tableMp.find(tableNo);
            map<string,int> foods = tableMpIt->second;

            map<string,int>::iterator foodsIt;

            uniqueFoodsIt = uniqueFoods.begin();

            while(uniqueFoodsIt != uniqueFoods.end()){
                string unFood = *uniqueFoodsIt;
                foodsIt = foods.find(unFood);
                int fc=0;
                if(foodsIt!=foods.end()){
                    fc=foodsIt->second;
                }
                foodTable.push_back(convertToStr(fc));
                uniqueFoodsIt++;
            }

            tableDisplay.push_back(foodTable);
            tablesIt++;
        }

        return tableDisplay;
    }

    vector<vector<string>> display(vector<vector<string>>& orders){
        for(int i=0;i<orders.size();i++){
            int tableNo = convertToInt(orders[i][1]);
            string food  = orders[i][2];

            insertFood(tableNo, food);
        }

        return displayFood();
    }
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        return display(orders);
    }
};
