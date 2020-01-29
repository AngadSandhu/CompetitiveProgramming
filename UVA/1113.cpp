#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 10000005
string change[] = {
	".-", "-...", "-.-.", "-..",
	".", "..-.", "--.", "....",
	"..", ".---", "-.-", ".-..",
	"--", "-.", "---", ".--.",
	"--.-", ".-.", "...", "-",
	"..-", "...-", ".--", "-..-",
	"-.--", "--.."};
int trie[N][2];
int terminal[N];
int dp[1005];
int nodes = 1;
string camb(string trad){
	string ret = "";
	for(int i = 0 ; i < trad.size() ; i++){
		ret += change[trad[i]-'A'];
	}
	return ret;
}
void add(string s){
	int cur = 0;
	for(int i = 0 ; i < s.size() ; i++){
		int c = (s[i] == '.');
		if(trie[cur][c]==-1) trie[cur][c] = nodes++;
		cur = trie[cur][c];
	}
	terminal[cur]++;
}
int main(){
	int t,cases = 0; cin >> t;
	int n,m;
	memset(trie,-1,sizeof trie);
	while(t--){
		nodes = 1;
		string s,q;
		cin >> s;
		cin >> m;
		n = s.size();
		for(int i = 0 ; i < m ; i++){
			cin >> q;
			add(camb(q));
		}
		dp[n] = 1;
		int cur = 0;
		for(int i = n-1; i >= 0 ; i--){
			cur = 0;
			dp[i] = 0;
			for(int j = i ; j < n ; j++){
				int c = s[j]=='.';
				if(trie[cur][c]==-1) break;
				cur = trie[cur][c];
				if(terminal[cur]) dp[i] += dp[j+1]*terminal[cur];
			}
		}
		if(0<cases++) cout << endl;
		cout << dp[0] << endl;
		for(int i = 0 ; i <= nodes; i++){
			trie[i][0] = trie[i][1] = -1;
			terminal[i] = 0;
		}
	}	
	return 0;
}

