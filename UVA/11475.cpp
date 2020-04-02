#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define N 1000005
#define reverse(ww) reverse(ww.begin(),ww.end())
int b[N];
void borde(string pat){
	int m = pat.size();
	b[0] = -1;
	for(int i = 0 , j = -1; i < m ; i++){
		while(j != -1 && pat[i] != pat[j]) j = b[j];
		b[i+1] = ++j;
	}
}
int maxpattern(string text,string pat){
	int n = text.size();
	int m = pat.size();
	int j = 0;
	for(int i = 0; i < n ; i++){
		while(j!=-1 && text[i] != pat[j]) j = b[j];
		j++;
	}
	return j;
}
int main(){
	string s;
	while(cin >> s){
		string r = s;
		reverse(r);
		borde(r);
		string ans = s + r.substr(maxpattern(s,r));
		cout << ans << endl;
	}
	return 0;
}
