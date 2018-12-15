class Solution {
private:

    string convertToStr(int v){
        string rev="";
        while(v>0){
            rev=rev+(char)(v%10 + 48);
            v=v/10;
        }
        string conv="";
        for(int i=rev.length()-1;i>=0;i--)
            conv=conv+rev[i];
        return conv;
    }

public:
    string countOfAtoms(string formula) {
        vector<string> Atoms;
        int cnt=0,sum;
        map<string,int> mp;
        map<string,int>::iterator mpIt;
        string atom="";
        set<string> has;

        for(int i=0;i<formula.size();i++){
            if(cnt==0){
                if(formula[i]>='A' && formula[i]<='Z'){
                    cnt=1;
                    atom=atom+formula[i];
                }
            }else{
                if(formula[i]>='a' && formula[i]<='z'){

                    atom=atom+formula[i];
                }else{
                    cnt=0;
                    if(has.count(atom)==0){
                        Atoms.push_back(atom);
                        has.insert(atom);
                    }
                    atom="";
                    i--;
                }
            }
        }
        if(atom.length()>0){
            if(has.count(atom)==0){
                        Atoms.push_back(atom);
                        has.insert(atom);
            }
        }

        int st,en,k,ctr,l,pn;
        for(int i=0;i<Atoms.size();i++){
            atom=Atoms[i];
            st=0;
            ctr=0;
            while(st<formula.size()){

                k=0;
                en=-1;
                for(int j=st;j<formula.size();j++){
                    if(formula[j]=='(')
                       ctr++;
                    if(formula[j]==')')
                        ctr--;
                    if(formula[j]==atom[k]){
                        if(k==atom.size()-1){
                            en=j;
                            break;
                        }
                        k++;
                    }
                }

                if(en==-1)
                    break;
                if(!(en+1<formula.size() && formula[en+1]>='a' && formula[en+1]<='z')){
                    sum=1;
                    if(en+1<formula.size() && formula[en+1]>='0' && formula[en+1]<='9')
                     {
                            l=en+1;
                            pn=0;
                            while(l<formula.size() && formula[l]>='0' && formula[l]<='9'){
                                pn=pn*10+(int)(formula[l]-48);
                                l++;
                            }
                            sum=sum*pn;
                     }

                    int ctr1=0,ctr2=0;
                    for(int j=en+1;j<formula.size();j++){
                        if(formula[j]=='('){
                            ctr2++;
                        }
                        if(formula[j]==')'){
                            if(ctr2==0){
                                ctr1++;
                                if(j+1<formula.size() && formula[j+1]>='0' && formula[j+1]<='9'){
                                    l=j+1;
                                    pn=0;
                                    while(l<formula.size() && formula[l]>='0' && formula[l]<='9'){
                                        pn=pn*10+(int)(formula[l]-48);
                                        l++;
                                    }
                                    sum=sum*pn;
                                 }
                                if(ctr1==ctr)
                                    break;
                            }else{
                                ctr2--;
                            }
                        }
                    }
                    mpIt=mp.find(atom);
                    if(mpIt!=mp.end()){
                        sum=sum+mpIt->second;
                        mp.erase(mpIt);
                    }
                    mp.insert(make_pair(atom,sum));
                }
                st=en+1;
            }
        }
        string ans="";
        for(mpIt=mp.begin();mpIt!=mp.end();mpIt++){
            //cout<<mpIt->first<<" "<<mpIt->second<<"\n";
            ans=ans+mpIt->first;
            if(mpIt->second>1)
                ans=ans+convertToStr(mpIt->second);
        }
        return ans;
    }
};
