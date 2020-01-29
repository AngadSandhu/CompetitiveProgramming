#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	string s;
	int p = 0;
	while(getline(cin,s)){
		p++;
		vector<int> ini,cur;
		stringstream in(s);
		int aux,ans = -1;
		bool b = 1;
		ll g = 0,lc = 1;
		while(in>>aux) ini.push_back(aux); 
		for(auto &v : ini) cur.push_back(3*v), v-=5;
		while(ans==-1&&b){
			int l = -1, r = INT_MAX;
			for(int i = 0 ; i < cur.size(); i++){
				l = max(l,cur[i]);
				r = min(r,cur[i]+ini[i]);
			}
			if(l<=r && l>lc) ans = l;
			for(int i = 0 ; i < cur.size() ; i++){
				cur[i] += ini[i]+5;
			}
		}
		if(b) printf("Set %d synchs again at %d minute(s) and %d second(s) after all turning green.\n",p,ans/60,ans%60);
		else printf("Set %d is unable to synch after one hour.\n",p);
	}
}
