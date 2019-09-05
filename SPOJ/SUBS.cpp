#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define mp make_pair

using namespace std;
typedef long long ll;
typedef vector<int> vi;

string a,b;

bool f(int cnt){
	int pos = 0,c = 0;
	for(int i = 0 ; i< b.size() && pos<a.size() ; i++){
		if(b[i]==a[pos]) c++;
		if(c==cnt) pos++,c=0;
	}
	return pos==a.size();
}

int main(){
	int t;cin >> t;
	while(t--){
		cin >> a >> b;
		int l =0, r = 1e6, med;
		while(l<r){
			med = l + (r-l+1)/2;
			if(f(med)) l = med;
			else r = med-1;
		}
		cout << l << endl;
	}
	return 0;
}
