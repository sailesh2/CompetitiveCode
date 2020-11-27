class Solution {
public:
    string defangIPaddr(string address) {
        string daggedAddres="";
        for(int i=0;i<address.size();i++){
            if(address[i]=='.'){
                daggedAddres.push_back('[');
                daggedAddres.push_back('.');
                daggedAddres.push_back(']');
            }else{
                daggedAddres.push_back(address[i]);
            }
        }
        return daggedAddres;
    }
};
