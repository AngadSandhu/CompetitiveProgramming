#include<bits/stdc++.h>
using namespace std;
class OrderlyString{
	public:
	int memo[250];
	int n;
	string ss;
	int dp(int p){
		if(memo[p]!=-1) return memo[p];
		int ret = 0;
		for(int i = p+1 ; i < n ; i++){
			if(ss[i]>=ss[p]) ret = max(dp(i)+1,ret); 
		}
		return memo[p] = ret;
	}
	int longestLength(string s){
		n = s.size();
		ss= s;
		memset(memo,-1,sizeof(memo));
		int maxi = -1;
		for(int i = 0 ; i < n ; i ++) maxi = max(dp(i)+1,maxi);
		return maxi; 
	}
	
}test;
int main(){
string sss; cin >> sss;
	cout << test.longestLength(sss) << endl;

}
