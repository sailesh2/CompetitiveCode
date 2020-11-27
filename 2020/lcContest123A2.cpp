class Solution {
private:
    vector<int> rev(vector<int> arr){
        vector<int> revs;
        for(int i=arr.size()-1;i>=0;i--)
            revs.push_back(arr[i]);
        return revs;
    }

    vector<int> addOffset(int s,vector<int> arr){
        int n= arr.size()-s;
        if(n>=0){
            return arr;
        }
        n=-1*n;
        arr=rev(arr);
        for(int i=0;i<n;i++){
            arr.push_back(0);
        }
        return rev(arr);
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

    vector<int> addZeroBeg(int c, vector<int> arr){
        arr=rev(arr);
        arr.push_back(c);
        return rev(arr);
    }

    vector<int> removeOffset(vector<int> arr){
        vector<int> newArr;
        int cnt=0;
        for(int i=0;i<arr.size();i++){
            if(cnt==0){
                if(arr[i]!=0){
                    cnt=1;
                    newArr.push_back(arr[i]);
                }
            }else{
                    newArr.push_back(arr[i]);

            }
        }

        return newArr;
    }
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> kForm=getForm(K);

        int mSize=max(kForm.size(),A.size());
        vector<int> kFormPadded = addOffset(mSize,kForm);
        vector<int> aPadded = addOffset(mSize,A);

        int c=0;
        for(int i=aPadded.size()-1;i>=0;i--){
            int v=(aPadded[i]+kFormPadded[i]+c)%10;
            c=(aPadded[i]+kFormPadded[i]+c)/10;
            aPadded[i]=v;
        }
        if(c>0){
            return addZeroBeg(c,aPadded);
        }
        return aPadded.size()>1 ? removeOffset(aPadded) : aPadded;
    }
};
