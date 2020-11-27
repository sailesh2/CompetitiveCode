class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x=0,y=0;
        int dir=0;

        for(int j=0;j<4;j++){
        for(int i=0;i<instructions.length();i++){
            switch(instructions[i]){
            case 'G':
                if(dir==0)
                    y++;
                else if(dir==1)
                    x++;
                else if(dir==2)
                    y--;
                else
                    x--;
                break;
            case 'L':
                dir=(dir-1+4)%4;
                break;
            case 'R':
                dir=(dir+1)%4;
                break;
            default:
                break;
            }
        }
        }

        return x==0 && y==0 && dir==0;
    }
};
