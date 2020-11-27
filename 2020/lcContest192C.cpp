class BrowserHistory {
private:
    vector<string> webpagesHistory;
    int currentPageIndex=-1;
    int lastPageIndex=-1;

public:
    BrowserHistory(string homepage) {
        currentPageIndex++;
        lastPageIndex++;
        webpagesHistory.push_back(homepage);
    }

    void visit(string url) {
        lastPageIndex=currentPageIndex;
        currentPageIndex++;
        lastPageIndex++;
        if(webpagesHistory.size()==lastPageIndex)
        webpagesHistory.push_back(url);
        else
        webpagesHistory[lastPageIndex]=url;
    }

    string back(int steps) {
        currentPageIndex = max(0,currentPageIndex-steps);
        return webpagesHistory[currentPageIndex];
    }

    string forward(int steps) {
        currentPageIndex = min(lastPageIndex, currentPageIndex+steps);
        return webpagesHistory[currentPageIndex];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
