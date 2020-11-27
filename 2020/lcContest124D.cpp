class Solution {
private:
    set<string> has;
    set<int> squares;

    void setup(){
        for(int i=1;i*i<=1000000009;i++){
            squares.insert(i*i);
        }
    }

    bool isSquare(int n){
        return squares.count(n)>0;
    }

    string convertToStr(int v){
        string vStr="";
        while(v>0){
            vStr.push_back((char)(v%10+48));
            v=v/10;
        }

        string vStrRev="";
        for(int i=vStr.length()-1;i>=0;i--)
            vStrRev.push_back(vStr[i]);

        return vStrRev;
    }

    string addPrefix(string pre, int v){
        string vStr = convertToStr(v);
        for(int i=0;i<vStr.length();i++)
            pre.push_back(vStr[i]);
        return pre;
    }

    void squarePerms(vector<int> arr, int ind, int prev, string pre){
        if(ind==arr.size()){
            if(has.count(pre)==0){
                has.insert(pre);
                ans++;
            }
            return;
        }

        for(int i=ind;i<arr.size();i++){
            if(isSquare(prev+arr[i])){
                squarePerms(arr, ind+1, arr[i], addPrefix(pre));
            }
        }
    }
public:
    int numSquarefulPerms(vector<int>& A) {
        setup();
        squarePerms(A);
        return ans;
    }
};
