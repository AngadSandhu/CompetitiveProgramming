#include<bits/stdc++.h>
using namespace std;
string s;
string memo[2005][15];
int n;
class ReconstructNumber{
	public:
	string dp(int pos,int last){
		if(memo[pos][last]!="-1") return memo[pos][last];
		if(pos==n)return "";
		string ret = "-2";
		if(s[pos]=='='){
			if(dp(pos+1,last)!="-2") ret = to_string(last) + dp(pos+1,last);
		}else if(s[pos]=='>'){
			for(int i = 0; i <last; i++){
				if(dp(pos+1,i)!="-2"){ ret = to_string(i)+dp(pos+1,i); break; }
			}
		}else if(s[pos]=='<'){
			for(int i = last+1; i < 10 ; i++){
				if(dp(pos+1,i)!="-2"){ ret = to_string(i)+dp(pos+1,i); break; }
			}
		}else{
			for(int i = 0; i < 10 ; i++){
				if(dp(pos+1,i)!="-2" && i!=last){ret = to_string(i)+dp(pos+1,i); break; }
			}
		}
		return memo[pos][last] = ret;
	}
	string smallest(string comparisons){
		s="!"; s+= comparisons;
		n = s.size();
		for(int i = 0 ; i < n; i ++){
			for(int j = 0 ; j < 10 ; j++) memo[i][j] = "-1";
		}
		//for(int i = 0 ; i < n ; i++)cout << s[i] << endl;
		if(dp(0,0)=="-2") return "";
		else return dp(0,0);
	}
	
}test;
int main(){ string ss; cin >> ss; cout << test.smallest(ss) << endl; return 0;}
