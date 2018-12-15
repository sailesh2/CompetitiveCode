/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
private:
    int currentIndex=0;
    string input;

    int convertToInt(string numStr){
        int num =0;
        int sign=1;
        int start=0;
        if(numStr.length()>0 && numStr[0] == '-'){
            start=1;
            sign=-1;
        }
        for(;start<numStr.length();start++){
            num = num* 10 + (int)numStr[start] - 48;
        }
        return sign*num;
    }

    void mergeChildNestedIntegers(vector<NestedInteger> &parentNestedIntegers, vector<NestedInteger> childNestedIntegers){
        NestedInteger nestedIntegerMerged;
        for(int i=0;i<childNestedIntegers.size();i++){
            nestedIntegerMerged.add(childNestedIntegers[i]);
        }
        parentNestedIntegers.push_back(nestedIntegerMerged);
    }

    void addNestedIntegerFromStr(vector<NestedInteger> & nestedIntegers, string num){
        if(num.length()>0){
            nestedIntegers.push_back(NestedInteger(convertToInt(num)));
        }
    }

    vector<NestedInteger> deserialize(){
        string num="";
        vector<NestedInteger> nestedIntegers;
        while(currentIndex<input.length()){
            if(input[currentIndex]=='['){
                currentIndex++;
                mergeChildNestedIntegers(nestedIntegers, deserialize());
            }else if(input[currentIndex]==','){
                currentIndex++;
                addNestedIntegerFromStr(nestedIntegers, num);
                num="";
            }else if(input[currentIndex]==']'){
                currentIndex++;
                break;
            }else{
                num=num+input[currentIndex++];
            }
        }
        addNestedIntegerFromStr(nestedIntegers, num);
        return nestedIntegers;
    }
public:
    NestedInteger deserialize(string s) {
        input = s;
        return deserialize()[0];
    }
};
