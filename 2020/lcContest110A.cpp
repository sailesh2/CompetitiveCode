pair<string,string> getLogContent(string log){
    string identifier = "";
    int save=0;
    for(int i=0;i<log.length();i++){
        if(log[i]==' '){
            save=i;
            break;
        }
        identifier = identifier+log[i];
    }
    string content="";
    for(int i=save+1;i<log.length();i++){
        content = content+log[i];
    }

    return make_pair(identifier,content);
}

bool logComparator(string loga, string logb){
    pair<string,string> contentsA = getLogContent(loga);
    string identifiera = contentsA.first;
    string contenta = contentsA.second;

    pair<string,string> contentsB = getLogContent(logb);
    string identifierb = contentsB.first;
    string contentb = contentsB.second;

    if(contenta == contentb){
        return identifiera < identifierb;
    }else{
        return contenta < contentb;
    }
}
class Solution {
private:

    bool isNumLog(string log){
        pair<string,string> contents = getLogContent(log);
        string content = contents.second;
        return content[0]>='0' && content[0]<='9';
    }

    vector<string> reorderLogs(vector<string>& logs){
        vector<string> orderedLogs;
        vector<string> numLogs;
        vector<string> letLogs;
        for(int i=0;i<logs.size();i++){
            if(isNumLog(logs[i])){
                numLogs.push_back(logs[i]);
            }else{
                letLogs.push_back(logs[i]);
            }
        }

        sort(letLogs.begin(),letLogs.end(),logComparator);

        for(int i=0;i<letLogs.size();i++){
            orderedLogs.push_back(letLogs[i]);
        }

        for(int i=0;i<numLogs.size();i++){
            orderedLogs.push_back(numLogs[i]);
        }
        return orderedLogs;
    }
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        return reorderLogs(logs);
    }
};
