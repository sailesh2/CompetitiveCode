class Solution {
private:
    struct Transaction{
        string name;
        int time;
        int amount;
        string place;
    };

    int convertToInt(string input){
        int num=0;
        for(int i=0;i<input.length();i++){
            num=(num*10)+((int)input[i] - 48);
        }
        return num;
    }

    vector<string> split(string input, char delimeter){
        vector<string> splits;
        string s="";
        for(int i=0;i<input.length();i++){
            if(input[i]==delimeter){
                splits.push_back(s);
                s="";
            }else{
                s.push_back(input[i]);
            }
        }
        splits.push_back(s);
        return splits;
    }

    Transaction serializeTransaction(string transaction){
        Transaction t;
        vector<string> transactionData = split(transaction, ',');
        t.name = transactionData[0];
        t.time = convertToInt(transactionData[1]);
        t.amount = convertToInt(transactionData[2]);
        t.place = transactionData[3];

        return t;
    }

    bool isInvalidTransaction(Transaction t, vector<string>& transactions){

        if(t.amount>1000)
            return true;

        for(int j=0;j<transactions.size();j++){
            Transaction t2 = serializeTransaction(transactions[j]);
            if(t2.name.compare(t.name)==0 && t2.place.compare(t.place)!=0){
                if(abs(t2.time - t.time)<=60)
                    return true;
            }
        }

        return false;
    }
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string> invalidTransactions;
        for(int i=0;i<transactions.size();i++){
            Transaction t = serializeTransaction(transactions[i]);
          //  cout<<t.name<<" "<<t.amount<<" "<<t.time<<" "<<t.place<<"\n";
            if(isInvalidTransaction(t, transactions)){
                invalidTransactions.push_back(transactions[i]);
            }
        }

        return invalidTransactions;
    }
};
