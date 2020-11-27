class Solution {
private:
	int numSub(string s){
		int f=0,r=0;
		int a=0,b=0,c=0;

		int n = s.length();
		int ctr=0;

if(s[f]=='a')
		a++;
	if(s[f]=='b')
		b++;
	if(s[f]=='c')
		c++;

		while(r<n){
			while(a>0 && b>0 && c>0){
	ctr=ctr+n-r;
	if(s[f]=='a')
		a--;
	if(s[f]=='b')
		b--;
	if(s[f]=='c')
		c--;
	f++;
}

r++;
while(r<n){
	if(s[r]=='a')
		a++;
	if(s[r]=='b')
		b++;
	if(s[r]=='c')
		c++;

	if(a>0 && b>0 && c>0)
		break;
	r++;
}
}

return ctr;
}
public:
int numberOfSubstrings(string s) {
	if(s.length()==0)
		return 0;
	return numSub(s);
}
};
