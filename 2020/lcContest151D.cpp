class DinnerPlates {
private:
    set<int> pushIndices;
    set<int>::iterator pIt;
    vector<vector<int>> dishStacks;
    int maxCapacity;
public:
    DinnerPlates(int capacity) {
        maxCapacity=capacity;
        pushIndices.insert(0);
    }

    void push(int val) {
        int index = *(pushIndices.begin());
        if(dishStacks.size()>=index+1){
            dishStacks[index].push_back(val);
        }else{
            vector<int> dishStack;
            dishStack.push_back(val);
            dishStacks.push_back(dishStack);
        }

        if(dishStacks[index].size()==maxCapacity){
            pushIndices.erase(pushIndices.begin());
            if(pushIndices.size()==0){
                pushIndices.insert(index+1);
            }
        }
    }

    int pop() {
        pIt = (pushIndices.end());
        pIt--;
        int index = *pIt;


        if(dishStacks.size()<index+1){
            index--;
        }
        if(index<0)
            return -1;

        int e = (int)dishStacks[index].size()-1;
        int popped = dishStacks[index][e];
        dishStacks[index].pop_back();
        if(dishStacks[index].size()==0){
            dishStacks.pop_back();
            pushIndices.erase(pIt);
        }
        pushIndices.insert(index);

        return popped;
    }

    int popAtStack(int index) {
        if(dishStacks.size()<index+1){
            return -1;
        }

        if(dishStacks[index].size()==0)
            return -1;
        int e = (int)dishStacks[index].size()-1;

        int popped = dishStacks[index][e];

        dishStacks[index].pop_back();
        pushIndices.insert(index);
        return popped;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
