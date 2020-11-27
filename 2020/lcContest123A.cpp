class Solution {
private:
    int calNum(vector<int> form){
        int n=0;
        for(int i=0;i<form.size();i++){
            n=n*10+form[i];
        }
        return n;
    }

    vector<int> getForm(int n){
        vector<int> form;
        while(n>0){
            form.push_back(n%10);
            n=n/10;
        }

        vector<int> revForm;
        for(int i=form.size()-1;i>=0;i--)
            revForm.push_back(form[i]);
        return revForm;
    }
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int n=calNum(A);
        n=n+K;
        return getForm(n);
    }
};
