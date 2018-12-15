#include <bits/stdc++.h>

using namespace std;

//Order structure
struct Order{
    long long int orderId;
    long long int timestamp;
    string symbol;
    char orderType;
    char orderSide;
    float price;
    int quantity;
    int quantityMatched;
};

//Utility classes
class StringUtil{
    public:
    static vector<string> split(const string& s, char delimiter)
    {
       std::vector<std::string> tokens;
       std::string token;
       std::istringstream tokenStream(s);
       while (std::getline(tokenStream, token, delimiter))
       {
          tokens.push_back(token);
       }
       return tokens;
    }

    static string to_string(int num){
        string result="",rev="";
        while(num>0){
            rev=rev+(char)(num%10+48);
            num=num/10;
        }
        for(int i=rev.size()-1;i>=0;i--){
            result=result+rev[i];
        }
        return result;
    }

    static string to_string(float num){
        int integeralPart=(int)num;
        int decimalPart=ceil((num*100-integeralPart*100));
        string result=to_string(integeralPart)+"."+to_string(decimalPart);
        return result;
    }

    static string to_string(long long int num){
        string result="",rev="";
        while(num>0){
            rev=rev+(char)(num%10+48);
            num=num/10;
        }
        for(int i=rev.size()-1;i>=0;i--){
            result=result+rev[i];
        }
        return result;
    }

    static string to_string(char c){
        string result=""+c;
        return result;
    }

    static bool isSymbol(string s){
        bool doesContainChar=false;
        for(int i=0;i<s.length();i++){
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
                doesContainChar=true;
                break;
            }
        }
        return doesContainChar;
    }
};

class NumberUtil{
    public:
    static long long int convertToInt(string value){
        long long int convertedInt=0;
        for(int i=0;i<value.length();i++){
            if(value[i]>='0' && value[i]<='9'){
                convertedInt=convertedInt*10+(value[i]-'0');
            }else{
                return -1;
            }
        }
        return convertedInt;
    }
    static float convertToFloat(string value){
        vector<string> parts=StringUtil::split(value,'.');
        if(parts.size()!=2){
            return -1;
        }else{
            if(parts[1].length()!=2)
                return -1;
            int integralPart=convertToInt(parts[0]);
            int decimalPart=convertToInt(parts[1]);
            float convertedFloat=integralPart+(float)decimalPart/100;
            return convertedFloat;
        }
    }
};

class OrderManagementUtil{
    public:
    static Order* createNewOrder(vector<string> params){
        if(params.size()!=8)
            return NULL;
        Order* order = new Order();
        order->orderId=NumberUtil::convertToInt(params[1]);
        order->timestamp=NumberUtil::convertToInt(params[2]);
        order->symbol=params[3];
        order->orderType=params[4][0];
        order->orderSide=params[5][0];
        order->price=NumberUtil::convertToFloat(params[6]);
        order->quantity=NumberUtil::convertToInt(params[7]);
        order->quantityMatched=0;
        return order;
    }
};

//Order Book(containing all order information)
class OrderBook{

    private:
    map<long long int,Order *> orderMap;
    map<long long int,Order *>::iterator orderMapIt;
    set<string> symbolList;
    set<string>::iterator it;
    map<string,vector<long long int> > orderListBySymbol;
    map<string,vector<long long int> >::iterator orderListIt;

    public:
    void addOrder(Order* order){
        orderMap.insert(make_pair(order->orderId,order));
        symbolList.insert(order->symbol);
        orderListIt=orderListBySymbol.find(order->symbol);
        vector<long long int> v;
        if(orderListIt!=orderListBySymbol.end()){
            v=orderListIt->second;
            orderListBySymbol.erase(orderListIt);
        }
        v.push_back(order->orderId);
        orderListBySymbol.insert(make_pair(order->symbol,v));
    }

    void ammendOrder(Order* order){
        orderMapIt=orderMap.find(order->orderId);
        Order* existingOrder=orderMapIt->second;
        if(existingOrder->quantityMatched>=order->quantity){
            removeOrder(existingOrder);
        }else{
            if(existingOrder->price!=order->price){
                existingOrder->timestamp=order->timestamp;
                existingOrder->price=order->price;
            }
            existingOrder->quantity=order->quantity-existingOrder->quantityMatched;
        }
    }

    void cancelOrder(Order* order){
        removeOrder(order);
    }

    void cancelOrder(long long int orderId){
        Order* existingOrder=getOrder(orderId);
        if(existingOrder!=NULL){
            removeOrder(existingOrder);
        }
    }

    Order* getOrder(long long int orderId){
        orderMapIt=orderMap.find(orderId);
        if(orderMapIt==orderMap.end()){
            return NULL;
        }else{
            return orderMapIt->second;
        }
    }

    vector<string> getSymbolList(){
        vector<string> symbolVec;
        for (it = symbolList.begin(); it != symbolList.end(); ++it)
        {
            symbolVec.push_back(*it);
        }
        return symbolVec;
    }

    vector<Order*> getOrderForSymbol(string symbol){
        vector<Order*> ordersBySymbol;
        vector<long long int> orderIds;
        orderListIt=orderListBySymbol.find(symbol);
        if(orderListIt!=orderListBySymbol.end()){
            orderIds=orderListIt->second;
            for(int i=0;i<orderIds.size();i++){
                ordersBySymbol.push_back(getOrder(orderIds[i]));
            }
        }
        return ordersBySymbol;
    }

    private:
    void removeOrder(Order* existingOrder){
        long long int orderId=existingOrder->orderId;
        string symbol=existingOrder->symbol;

        orderListIt=orderListBySymbol.find(symbol);
        vector<long long int> vec=orderListIt->second;
        vec.erase(std::remove(vec.begin(), vec.end(), existingOrder->orderId), vec.end());
        orderListBySymbol.erase(orderListIt);
        if(vec.size()>0){
            orderListBySymbol.insert(make_pair(symbol,vec));
        }else{
            symbolList.erase(symbol);
        }
        orderMap.erase(orderId);
    }
};

//Order validator. Validates all types of request(add,ammend,cancel).
class OrderValidator{
    private:
    bool static isOrderTypeValid(char orderType){
        return orderType=='M' || orderType=='L' || orderType=='I';
    }
    bool static isOrderSideValid(char orderSide){
        return orderSide=='B' || orderSide=='S';
    }
    bool static isOrderMatch(Order *order1,Order *order2){
        return order1->orderSide==order2->orderSide && order1->orderType==order2->orderType && order1->symbol==order2->symbol;
    }
    public:
    static pair<bool,string> validateAddOrder(Order *order, long long int currentTime){
        string successMsg=StringUtil::to_string(order->orderId)+" - Accept";
        string errorMsg=StringUtil::to_string(order->orderId)+" - Reject - 303 - Invalid order details";
        if(order==NULL || order->orderId==-1 || order->timestamp==-1 || order->price==-1 || order->quantity==-1
           || !isOrderTypeValid(order->orderType) || !isOrderSideValid(order->orderSide)){
            return make_pair(false,errorMsg);
        }

        if(currentTime>order->timestamp){
            return make_pair(false,errorMsg);
        }

        return make_pair(true,successMsg);
    }

    static pair<bool,string> validateAmmendOrder(Order *order,Order *existingOrder,long long int currentTime){
        string successMsg=StringUtil::to_string(order->orderId)+" - AmendAccept";
        string invalidErrorMsg=StringUtil::to_string(order->orderId)+" - AmendReject - 101 - Invalid amendment details";
        string notExistErrorMsg=StringUtil::to_string(order->orderId)+" - AmendReject - 404 - Order does not exist";

        if(existingOrder == NULL){
            return make_pair(false,notExistErrorMsg);
        }

        if(currentTime>order->timestamp){
            return make_pair(false,invalidErrorMsg);
        }
        if(!isOrderMatch(order,existingOrder)){
            return make_pair(false,invalidErrorMsg);
        }
        return make_pair(true,successMsg);
    }

    static pair<bool,string> validateCancelOrder(long long int cancelOrderId,Order* existingOrder,long long int cancelTime,long long int currentTime){
        string successMsg=StringUtil::to_string(cancelOrderId)+" - CancelAccept";
        string errorMsg=StringUtil::to_string(cancelOrderId)+" - CancelReject - 404 - Order does not exist";

        if(existingOrder == NULL){
            return make_pair(false,errorMsg);
        }

        if(currentTime>cancelTime){
            return make_pair(false,errorMsg);
        }
        return make_pair(true,successMsg);
    }
};

//Comparators for sorting of orders.
bool buyOrderSortComparator(Order * orderA,Order * orderB){
    if(orderA->price==orderB->price){
        return orderA->timestamp<orderB->timestamp;
    }else{
        return orderA->price>orderB->price;
    }
}

bool sellOrderSortComparator(Order * orderA,Order * orderB){
    if(orderA->price==orderB->price){
        return orderA->timestamp<orderB->timestamp;
    }else{
        return orderA->price<orderB->price;
    }
}

//Order Book Manager aka Matcher.It maintains one buy order book and one sell order book, and manages all incoming requests
//like add, amend, cancel,match and query.
class OrderBookManager{
    private:
    OrderBook* buyBook;
    OrderBook* sellBook;
    long long int currentTime=0;
    set<long long int> orderIds;

    public:
    OrderBookManager(){
        buyBook = new OrderBook();
        sellBook = new OrderBook();
    }

    vector<string> processQueries(vector<string> queries){
        string query;
        vector<string> responses;
        vector<string> res;
        for(int i=0;i<queries.size();i++){
            query=queries[i];
            res=processQuery(query);
            responses.insert(responses.end(),res.begin(),res.end());
        }
        return responses;
    }

    private:
    void updateTime(long long int time){
        if(time>=currentTime){
            currentTime=time;
        }
    }

    string to_string(int num){
        return StringUtil::to_string(num);
    }

    string to_string(long long int num){
        return StringUtil::to_string(num);
    }

    string to_string(char num){
        return StringUtil::to_string(num);
    }

    string to_string(float num){
        return StringUtil::to_string(num);
    }

    vector<string> processQuery(string query){
        vector<string> params = StringUtil::split(query,',');
        vector<string> response;
        vector<string> res;
        char op=params[0][0];
        switch(op){
            case 'N':
                response.push_back(processAddQuery(params));
                break;
            case 'A':
                response.push_back(processAmmendQuery(params));
                break;
            case 'X':
                response.push_back(processCancelQuery(params));
                break;
            case 'M':
                res=processMatchQuery(params);
                response.insert(response.end(),res.begin(),res.end());
                break;
            case 'Q':
                res=processQueryQuery(params);
                response.insert(response.end(),res.begin(),res.end());
                break;
            default:
                break;
        }
        return response;
    }

    string processAddQuery(vector<string> params){
        string response;
        Order* order,*existingOrder;

        string bookType=params[5];
        order = OrderManagementUtil::createNewOrder(params);
        existingOrder=buyBook->getOrder(order->orderId);
        if(existingOrder == NULL){
            existingOrder=sellBook->getOrder(order->orderId);
        }
        if(existingOrder!=NULL){
            order->quantity=-1;
        }
        pair<bool,string> result = OrderValidator::validateAddOrder(order,currentTime);
        if(result.first){
            if(bookType=="B"){
               buyBook->addOrder(order);
            }else{
               sellBook->addOrder(order);
            }
        }
        updateTime(order->timestamp);
        response=result.second;
        return response;
    }

    string processAmmendQuery(vector<string> params){
        string response;
        Order *order,*existingOrder;

        order = OrderManagementUtil::createNewOrder(params);
        char bookType;
        existingOrder=buyBook->getOrder(order->orderId);
        if(existingOrder == NULL){
            existingOrder=sellBook->getOrder(order->orderId);
            bookType='S';
        }else{
            bookType='B';
        }
        pair<bool,string> result = OrderValidator::validateAmmendOrder(order,existingOrder,currentTime);
        if(result.first){
            if(bookType=='B'){
               buyBook->ammendOrder(order);
            }else{
               sellBook->ammendOrder(order);
            }
        }
        updateTime(order->timestamp);
        response=result.second;
        return response;
    }

    string processCancelQuery(vector<string> params){
        string response;
        Order* existingOrder;

        long long int cancelOrderId=NumberUtil::convertToInt(params[1]);
        char bookType;
        existingOrder=buyBook->getOrder(cancelOrderId);
        if(existingOrder == NULL){
            existingOrder=sellBook->getOrder(cancelOrderId);
            bookType='S';
        }else{
            bookType='B';
        }
        long long int cancelTime=NumberUtil::convertToInt(params[2]);
        pair<bool,string> result = OrderValidator::validateCancelOrder(cancelOrderId,existingOrder,cancelTime,currentTime);
        if(result.first){
            if(bookType=='B'){
               buyBook->cancelOrder(existingOrder);
            }else{
               sellBook->cancelOrder(existingOrder);
            }
        }
        updateTime(cancelTime);
        response=result.second;
        return response;
    }

    vector<string> processMatchQuery(vector<string> params){
        bool symbolMatch=false;
        string symbol="";
        if(params.size()==3){
            symbolMatch=true;
            symbol=params[2];
        }
        vector<vector<Order*> > allBuyOrders;
        vector<vector<Order*> > allSellOrders;
        int sellOrderMap[100000]={0};

        if(symbolMatch){
            vector<Order*> buyOrders=buyBook->getOrderForSymbol(symbol);
            vector<Order*> sellOrders=sellBook->getOrderForSymbol(symbol);
            if(buyOrders.size()>0){
                allBuyOrders.push_back(buyOrders);
                if(sellOrders.size()>0){
                    allSellOrders.push_back(sellOrders);
                    sellOrderMap[allBuyOrders.size()-1]=allSellOrders.size()-1;
                }
            }
        }else{
            vector<string> buySymbols=buyBook->getSymbolList();
            for(int i=0;i<buySymbols.size();i++){
                vector<Order*> buyOrders=buyBook->getOrderForSymbol(buySymbols[i]);
                if(buyOrders.size()>0){
                    allBuyOrders.push_back(buyOrders);

                    vector<Order*> sellOrders=sellBook->getOrderForSymbol(buySymbols[i]);
                    if(sellOrders.size()>0){
                        allSellOrders.push_back(sellOrders);
                        sellOrderMap[allBuyOrders.size()-1]=allSellOrders.size()-1;
                    }
                }
            }
        }

        vector<long long int> buyOrdersToBeRemoved;
        vector<long long int> sellOrdersToBeRemoved;
        vector<string> responses;
        for(int i=0;i<allBuyOrders.size();i++){
            vector<Order*> buyOrders=allBuyOrders[i];
            int index=sellOrderMap[i];
            vector<Order*> sellOrders=allSellOrders[index];
            sort(buyOrders.begin(),buyOrders.end(),buyOrderSortComparator);
            sort(sellOrders.begin(),sellOrders.end(),sellOrderSortComparator);
            int j=0,k=0,quantiyMatched=0;
            float priceMatched;
            while(j<buyOrders.size() && k<sellOrders.size()){
                if(buyOrders[j]->price>=sellOrders[k]->price){
                    quantiyMatched=min(buyOrders[j]->quantity,sellOrders[k]->quantity);
                    priceMatched=min(buyOrders[j]->price,sellOrders[k]->price);
                    responses.push_back(buyOrders[j]->symbol+"|"+to_string(buyOrders[j]->orderId)+","+buyOrders[j]->orderType+","+to_string(quantiyMatched)+","+to_string(priceMatched)
                    +"|"+to_string(priceMatched)+","+to_string(quantiyMatched)+","+sellOrders[k]->orderType+","+to_string(sellOrders[k]->orderId));

                    buyOrders[j]->quantityMatched=buyOrders[j]->quantityMatched+quantiyMatched;
                    buyOrders[j]->quantity=buyOrders[j]->quantity-quantiyMatched;

                    sellOrders[k]->quantityMatched=sellOrders[k]->quantityMatched+quantiyMatched;
                    sellOrders[k]->quantity=sellOrders[k]->quantity-quantiyMatched;

                    if(buyOrders[j]->quantity==0){
                        buyOrdersToBeRemoved.push_back(buyOrders[j]->orderId);
                        j++;
                    }

                    if(sellOrders[k]->quantity==0){
                        sellOrdersToBeRemoved.push_back(sellOrders[k]->orderId);
                        k++;
                    }
                }else{
                    break;
                }
            }

        }

        for(int i=0;i<buyOrdersToBeRemoved.size();i++){
            buyBook->cancelOrder(buyOrdersToBeRemoved[i]);
        }

        for(int i=0;i<sellOrdersToBeRemoved.size();i++){
            sellBook->cancelOrder(sellOrdersToBeRemoved[i]);
        }

        return responses;
    }

    vector<string> processQueryQuery(vector<string> params){
                bool symbolMatch=false;
        string symbol="";
        if(params.size()==3 && StringUtil::isSymbol(params[2])){
            symbolMatch=true;
            symbol=params[2];
        }
        vector<string> allSymbols;
        vector<string> responses;
        set<long long int> orderProcessed;
        if(symbolMatch){
            allSymbols.push_back(symbol);
        }else{
            vector<string> buySymbols=buyBook->getSymbolList();
            vector<string> sellSymbols=sellBook->getSymbolList();
            allSymbols=buySymbols;
            for(int i=0;i<sellSymbols.size();i++){
                allSymbols.push_back(sellSymbols[i]);
            }
        }
        sort(allSymbols.begin(),allSymbols.end());
        for(int i=0;i<allSymbols.size();i++){
            vector<Order*> buyOrders=buyBook->getOrderForSymbol(allSymbols[i]);
            vector<Order*> sellOrders=sellBook->getOrderForSymbol(allSymbols[i]);
            sort(buyOrders.begin(),buyOrders.end(),buyOrderSortComparator);
            sort(sellOrders.begin(),sellOrders.end(),sellOrderSortComparator);

            int j=0,k=0;

            while(j<buyOrders.size() && k<sellOrders.size()){
                if(buyOrders[j]->price>=sellOrders[k]->price){
                    if(orderProcessed.count(buyOrders[j]->orderId)==0 && orderProcessed.count(sellOrders[k]->orderId)==0){
                        responses.push_back(buyOrders[j]->symbol+"|"+to_string(buyOrders[j]->orderId)+","+buyOrders[j]->orderType+","+to_string(buyOrders[j]->quantity)+","+to_string(buyOrders[j]->price)
                        +"|"+to_string(sellOrders[k]->price)+","+to_string(sellOrders[k]->quantity)+","+sellOrders[k]->orderType+","+to_string(sellOrders[k]->orderId));

                        orderProcessed.insert(buyOrders[j]->orderId);
                        orderProcessed.insert(sellOrders[k]->orderId);
                    }
                    j++;
                    k++;


                }else{
                    break;
                }
            }

            for(int l=0;l<buyOrders.size();l++){
                if(orderProcessed.count(buyOrders[l]->orderId)==0){
                    responses.push_back(buyOrders[l]->symbol+"|"+to_string(buyOrders[l]->orderId)+","+buyOrders[l]->orderType+","+to_string(buyOrders[l]->quantity)+","+to_string(buyOrders[l]->price)+"|");
                    orderProcessed.insert(buyOrders[l]->orderId);
                }
            }

            for(int l=0;l<sellOrders.size();l++){
                if(orderProcessed.count(sellOrders[l]->orderId)==0){
                    responses.push_back(sellOrders[l]->symbol+"||"+to_string(sellOrders[l]->price)+","+to_string(sellOrders[l]->quantity)+","+sellOrders[l]->orderType+","+to_string(sellOrders[l]->orderId));
                    orderProcessed.insert(sellOrders[l]->orderId);
                }
            }
        }

        return responses;

    }
};

/*
 * Complete the function below.
 */
vector<string> processQueries(vector<string> queries) {
    // Write your code here.
    OrderBookManager bookManager;
    return bookManager.processQueries(queries);
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int queries_size;
    cin >> queries_size;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> queries(queries_size);
    for (int queries_i = 0; queries_i < queries_size; queries_i++) {
        string queries_item;
        getline(cin, queries_item);

        queries[queries_i] = queries_item;
    }

    vector<string> response = processQueries(queries);

    for (int response_itr = 0; response_itr < response.size(); response_itr++) {
        fout << response[response_itr];

        if (response_itr != response.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
