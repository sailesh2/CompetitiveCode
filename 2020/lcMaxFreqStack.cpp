struct FrequencyStack{
    int value;
    int freq;
    int pos;
};

struct custom_compare {
    bool operator() (const FrequencyStack& lhs, const FrequencyStack& rhs) const {
        if(lhs.freq == rhs.freq){
            return lhs.pos > rhs.pos;
        }
        return lhs.freq>rhs.freq;
    }
};

class FreqStack {
private:
    set<FrequencyStack, custom_compare> stackSet;
    set<FrequencyStack, custom_compare>::iterator stackSetIt;
    int top =-1;
    map<int,int> freqMap;
    map<int,int>::iterator freqMapIt;

public:
    FreqStack() {

    }

    void push(int x) {
        int f = 0;
        freqMapIt = freqMap.find(x);
        if(freqMapIt != freqMap.end()){
            f=freqMapIt->second;
            freqMap.erase(freqMapIt);
        }
        f++;
        freqMap.insert(make_pair(x,f));

        FrequencyStack stk;
        stk.freq = f;
        stk.pos = ++top;
        stk.value = x;
        stackSet.insert(stk);
    }

    int pop() {
        //top--;
        stackSetIt = stackSet.begin();
        FrequencyStack stk = *stackSetIt;
        int ret = stk.value;
        freqMapIt = freqMap.find(ret);
        int f= freqMapIt->second;
        f--;
        freqMap.erase(freqMapIt);
        freqMap.insert(make_pair(ret,f));

        stackSet.erase(stackSetIt);
        return ret;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
