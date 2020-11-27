class CustomStack {
private:
    int maxS;
    vector<int> stk;
public:
    CustomStack(int maxSize) {
        maxS=maxSize;
    }

    void push(int x) {
        if(stk.size()<maxS){
            stk.push_back(x);
        }
    }

    int pop() {
        if(stk.size()==0)
            return -1;
        int popped =stk[stk.size()-1];
        stk.pop_back();
        return popped;
    }

    void increment(int k, int val) {
        int st=stk.size();
        int l=min(k,st);
        for(int i=0;i<l;i++){
            stk[i]=stk[i]+val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
