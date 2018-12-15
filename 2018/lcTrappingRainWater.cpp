class Solution {
public:
    int trap(vector<int>& height) {
        int cum[100000];
        int trapped=0;
        int popped;
        for(int i=height.size()-1;i>=0;i--){
            if(i==height.size()-1){
                cum[i]=height[i];
            }else{
                cum[i]=cum[i+1]+height[i];
            }
        }
        int top=-1;
        int stk[100000];
        for(int i=height.size()-1;i>=0;i--){
            popped=-1;
            while(top!=-1 && height[i]>=height[stk[top]]){
                popped=stk[top--];
            }
            if(top==-1 && popped>=0){
                trapped=trapped-(cum[i+1]-cum[popped])+(popped-i-1)*height[popped];
            }
            stk[++top]=i;
        }
        while(top!=-1){
            popped=stk[top--];
            if(top!=-1){
                trapped=trapped-(cum[popped+1]-cum[stk[top]])+(stk[top]-popped-1)*height[popped];
            }
        }
        return trapped;
    }
};
