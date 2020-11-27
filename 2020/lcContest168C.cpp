class Solution {
private:
	map<string,int> has;
	map<string,int>::iterator hasIt;

	void storeInHashMap(string s){
		hasIt=has.find(s);
		int freq=0;

if(hasIt!=has.end()){
			freq=hasIt->second;
			has.erase(hasIt);
}

has.insert(make_pair(s,freq+1));
}

	void storeMaxFreq(string s, int subSize, int maxLetters){
		int n=s.length();


		for(int i=0;i<n;i++){
			string sub="";
if(i+subSize>n){
	break;
}
int mp[26]={0};
int dc=0;
for(int j=i;j<i+subSize;j++){
	sub.push_back(s[j]);
	if(mp[s[j]-'a']==0){
		dc++;
}
mp[s[j]-'a']++;
}
if(dc<=maxLetters){
	storeInHashMap(sub);
}
		}
}

int maxFreq(){
	int maxi=0;
	for(hasIt=has.begin();hasIt!=has.end();hasIt++){
        //cout<<hasIt->first<<"\n";
		maxi=max(maxi,hasIt->second);
}
return maxi;
}


public:
int maxFreq(string s, int maxLetters, int minSize, int maxSize) {

storeMaxFreq(s,minSize,maxLetters);
return maxFreq();
    	}
};
