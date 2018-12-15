#include <bits/stdc++.h>

using namespace std;

struct Order{
    int orderId;
    long long int timestamp;
    string symbol;
    char orderType;
    char orderSide;
    float price;
    int quantity;
    int quantityMatched;
};

class OrderBook{

    private:
    map<long long int,Order> orderMap;
    map<long long int,Order>::iterator orderMapIt;
    set<string> orderTypes;
    map<string,vector<long long int> > orderListByType;
    map<string,vector<long long int> >::iterator orderListIt;

    public:
    void addOrder(Order order){
        orderMap.insert(make_pair(order.orderId,order));
        orderTypes.insert(order.orderType);
        orderListIt=orderListByType.find(order.orderType);
        vector<string> v;
        if(orderListIt!=orderListByType.end()){
            v=orderListIt->second;
            orderListByType.erase(orderListIt);
        }
        v.push_back(order.orderId);
        orderListByType.insert(make_pair(order.orderType,v));
    }

    void ammendOrder(Order order){
        orderMapIt=orderMap.find(order.orderId);
        Order existingOrder=orderMapIt->second;
        if(existingOrder.quantityMatched>=order.quantity){
            removeOrder(order.orderId);
        }else{

            if(existingOrder.price==order.price){
                order.timestamp=existingOrder.timestamp;
            }
            order.quantityMatched=existingOrder.quantityMatched;
            order.quantity=order.quantity-order.quantityMatched;
            removeOrder(existingOrder);
            addOrder(order);
        }
    }

    void cancelOrder(Order order){
        removeOrder(order);
    }

    Order getOrder(long long int orderId){
        orderMapIt=OrderMap.find(orderId);
        if(orderMapIt==OrderMap.end()){
            return NULL;
        }else{
            return orderMapIt->second;
        }
    }

    vector<string> match(){

    }

    vector<string> query(){

    }

    private:
    void removeOrder(Order existingOrder){
        long long int orderId=existingOrder.orderId;
        string orderType=existingOrder.orderType;

        orderListIt=orderListByType.find(orderType);
        vector<long long int> vec=orderListIt->second;
        vec.erase(std::remove(vec.begin(), vec.end(), existingOrder.orderId), vec.end());
        orderListByType.erase(orderListIt);
        if(vec.size()>0){
            orderListByType.insert(make_pair(orderType,vec));
        }else{
            orderTypes.erase(orderType);
        }
        orderMap.erase(orderId);
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
        vector<string> parts=value.split(".");
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
    private:

    public:
    static Order createNewOrder(vector<string> params){
        if(params.size()!=8)
            return NULL;
        struct Order order;
        order.orderId=NumberUtil.convertToInt(params[1]);
        order.timestamp=NumberUtil.convertToInt(params[2]);
        order.symbol=params[3];
        order.orderType=params[4];
        order.orderSide=params[5];
        order.price=NumberUtil.convertToFloat(params[6]);
        order.quantity=NumberUtil.convertToInt(params[7]);

        return order;
    }

    static Order createAppendOrder(vector<string> params){
        if(params.size()!=8)
            return NULL;
        struct Order order;
        order.orderId=NumberUtil.convertToInt(params[1]);
        order.timestamp=NumberUtil.convertToInt(params[2]);
        order.symbol=params[3];
        order.orderType=params[4];
        order.orderSide=params[5];
        order.price=NumberUtil.convertToFloat(params[6]);
        order.quantity=NumberUtil.convertToInt(params[7]);

        return order;
    }
};

class OrderValidator{
    private:
    bool static isOrderTypeValid(char orderType){
        return orderType=="M" || orderType=="L" || orderType=="I";
    }
    bool static isOrderSideValid(char orderSide){
        return orderSide=="B" || orderSide=="S";
    }
    bool isOrderMatch(Order order1,Order order2){
        return order1.orderSide==order2.orderSide && order1.orderType==order2.orderType && order1.symbol==order2.symbol;
    }
    public:
    static pair<bool,string> validateAddOrder(Order order, set<long long int> ids, long long int currentTime){
        string successMsg=order.orderId+" - Accept\n";
        string errorMsg=order.orderId+" - Reject - 303 - Invalid order details\n";
        if(order==NULL || order.orderId==-1 || order.timestamp==-1 || order.price==-1 || order.quantity==-1
           || !isOrderTypeValid(order.orderType) || !isOrderSideValid(order.orderSide)){
            return make_pair(false,errorMsg);
        }
        if(ids.count(order.orderId)>0){
            return make_pair(false,errorMsg);
        }

        if(currentTime>order.timestamp){
            return make_pair(false,errorMsg);
        }

        return make_pair(true,successMsg);
    }

    static pair<bool,string> validateAmmendOrder(Order order,Order existingOrder){
        string successMsg=order.orderId+" - AmmendAccept\n";
        string invalidErrorMsg=order.orderId+" - AmmendReject - 101 - Invalid ammendment details\n";
        string notExistErrorMsg=order.orderId+" - AmmendReject - 404 - Order does not exist\n";

        if(existingOrder == NULL){
            return make_pair(false,notExistErrorMsg);
        }
        if(!isOrderMatch(order,existingOrder)){
            return make_pair(false,invalidErrorMsg);
        }
        return make_pair(true,successMsg);
    }

    static pair<bool,string> validateCancelOrder(long long int cancelOrderId,Order existingOrder){
        string successMsg=cancelOrderId+" - CancelAccept\n";
        string errorMsg=cancelOrderId+" - CancelReject - 404 - Order does not exist\n";

        if(existingOrder == NULL{
            return make_pair(false,errorMsg);
        }
        return make_pair(true,successMsg);
    }
};

class OrderBookManager(){
    private:
    OrderBook* buyBook;
    OrderBook* sellBook;
    long long int currentTime;
    set<long long int> orderIds;

    public:
    BookManager(){
        buyBook = new OrderBook();
        sellBook = new OrderBook();
    }

    vector<string> processQueries(vector<string> queries){
        string query;
        vector<string> responses;
        for(int i=0;i<queries.size();i++){
            query=queries[i];
            responses.push_back(processQuery(query));
        }
        return responses;
    }

    private:
    vector<string> split(const string& s, char delimiter)
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

    string processAddQuery(vector<string> params){
        string response;
        Order order;

        string bookType=params[5];
        order = OrderManagementUtil.createNewOrder(params);
        existingOrder=buyBook.getOrder(order.orderId);
        if(existingOrder == NULL){
            existingOrder=sellBook.getOrder(order.orderId);
        }
        if(existingOrder!=NULL){
            order.quantity=-1;
        }
        pair<bool,string> result = OrderValidator.validateAddOrder(order);
        if(result.first){
            if(bookType=="B"){
               buyBook.addOrder(order);
            }else{
               sellBook.addOrder(order);
            }
        }
        response=result.second;
        return response;
    }

    string processAmmendQuery(vector<string> params){
        string response;
        Order order,existingOrder;

        order = OrderManagementUtil.createAmmendOrder(params);
        char bookType;
        existingOrder=buyBook.getOrder(order.orderId);
        if(existingOrder == NULL){
            existingOrder=sellBook.getOrder(order.orderId);
            bookType='S';
        }else{
            bookType='B';
        }
        pair<bool,string> result = OrderValidator.validateAmmendOrder(order,existingOrder);
        if(result.first){
            if(bookType=='B'){
               buyBook.ammendOrder(order);
            }else{
               sellBook.ammendOrder(order);
            }
        }
        response=result.second;
        return response;
    }

    string processCancelQuery(vector<string> params){
        string response;
        Order existingOrder;

        string cancelOrderId=params[1];
        char bookType;
        existingOrder=buyBook.getOrder(cancelOrderId);
        if(existingOrder == NULL){
            existingOrder=sellBook.getOrder(cancelOrderId);
            bookType='S';
        }else{
            bookType='B';
        }

        pair<bool,string> result = OrderValidator.validateCancelOrder(existingOrder);
        if(result.first){
            if(bookType=='B'){
               buyBook.cancelOrder(existingOrder);
            }else{
               sellBook.cancelOrder(existingOrder);
            }
        }
        response=result.second;
        return response;
    }

    string processQuery(string query){
        vector<string> params = split(query);
        string response;
        switch(params[0]){
            case "N":
                response=processAddQuery(params);
                break;
            case "A":
                response=processAmmendQuery(params);
                break;
            case "X":
                response=processCancelQuery(params);
                break;
            case "M":
                response=processMatchQuery(params);
                break;
            case "Q":
                response=processQueryQuery(params);
                break;
            default:
                break;
        }
        return response;
    }
}

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
