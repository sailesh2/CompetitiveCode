class Solution {
private:
    pair<int,int> getPos(char alphabet){
        return make_pair((alphabet-'a')/5,(alphabet-'a')%5);
    }
public:
    string alphabetBoardPath(string target) {
        int r=0,c=0;
        string ans="";

        for(int i=0;i<target.length();i++){
            pair<int,int> dest=getPos(target[i]);
            int r1=dest.first;
            int c1=dest.second;

            if(target[i]!='z'){

                if(r1>r){
                    for(int j=0;j<r1-r;j++)
                        ans.push_back('D');
                }else if(r1<r){
                    for(int j=0;j<r-r1;j++)
                        ans.push_back('U');
                }

                if(c1>c){
                    for(int j=0;j<c1-c;j++)
                        ans.push_back('R');
                }else if(c1<c){
                    for(int j=0;j<c-c1;j++)
                        ans.push_back('L');
                }
            }else{

                if(c1>c){
                    for(int j=0;j<c1-c;j++)
                        ans.push_back('R');
                }else if(c1<c){
                    for(int j=0;j<c-c1;j++)
                        ans.push_back('L');
                }

                if(r1>r){
                    for(int j=0;j<r1-r;j++)
                        ans.push_back('D');
                }else if(r1<r){
                    for(int j=0;j<r-r1;j++)
                        ans.push_back('U');
                }

            }

            ans.push_back('!');
            r=r1;
            c=c1;
        }

        return ans;
    }
};
