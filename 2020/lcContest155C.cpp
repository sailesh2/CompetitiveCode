class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.length();
        int has[100005]={0};
        for(int i=0;i<=n;i++)
            has[i]=-1;
        for(int i=0;i<pairs.size();i++){
            int x=pairs[i][0];
            int y=pairs[i][1];
            {
                int ctrx=0,ctry=0;
                int xtemp=x,ytemp=y;
                vector<int> vx,vy;
                int savex=x,savey=y;
                while(xtemp!=-1){
                    ctrx++;
                    vx.push_back(xtemp);
                    savex=xtemp;
                    xtemp=has[xtemp];
                }
                while(ytemp!=-1){
                    ctry++;
                    vy.push_back(ytemp);
                    savey=ytemp;
                    ytemp=has[ytemp];
                }

                if(savex!=savey){
                    cout<<savex<<" "<<savey<<"s";
                    if(ctrx>ctry){
                        for(int j=0;j<vy.size();j++)
                        has[vy[j]]=savex;
                    }else{
                        for(int j=0;j<vx.size();j++)
                        has[vx[j]]=savey;
                    }
                }
            }
        }

        vector<int> grps[n];
        for(int i=0;i<n;i++){
            int xtemp=i;
            int save=i;
            cout<<i<<"\n";
            while(xtemp!=-1){
                save=xtemp;

                xtemp=has[xtemp];
            }
            grps[save].push_back(i);
        }

        for(int i=0;i<n;i++){
            vector<int> v =grps[i];
            string stemp="";
            cout<<i<<" -";
            for(int j=0;j<v.size();j++){
                stemp.push_back(s[v[j]]);
                cout<<v[j]<<" ";
            }
            cout<<"\n";
            sort(stemp.begin(),stemp.end());
            sort(v.begin(),v.end());
            for(int j=0;j<v.size();j++){
                s[v[j]]=stemp[j];
            }
        }

        return s;
    }
};
