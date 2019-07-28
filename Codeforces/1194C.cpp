#include<bits/stdc++.h>
using namespace std;
string s,t, p, t2;
int l;
int f1[30],f2[30];
bool posi;
int main(){
	int q; cin >> q;
	while(q--){
		cin >> s >> t >> p;
		memset(f1,0,sizeof f1);
		memset(f2,0,sizeof f2);
		l = 0 , posi = 1;
		t2.clear();
		for(int i = 0 ; i < t.size() ; i++){
			if(t[i]==s[l] && l<s.size()){
				l++;
			}else{
				t2 += t[i];
			}
		}
		if(l!=s.size()) posi = 0;
		for(int i = 0 ; i < t2.size() ; i++) f1[t2[i]-'a']++;
		for(int i = 0 ; i < p.size() ; i++) f2[p[i] - 'a']++;
		for(int i = 0 ; i < 30 ; i++) if(f1[i]>f2[i]) posi = 0; 
		cout << (posi?"YES":"NO") << endl;
	}
	return 0;
}

