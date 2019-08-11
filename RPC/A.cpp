#include <bits/stdc++.h>
using namespace std;
const int maxw = 1e8+10;
int dp[maxw];
int main(){
	int n, d;
	cin >> n >> d;
	vector <pair <int, pair <int, int> > > anph;
	for(int i=0; i<n; i++){
		int a,b,c;
		cin >> a >> b >> c;
		anph.push_back(make_pair(a,make_pair(b,c)));
	}
	sort(anph.rbegin(), anph.rend());
	//cout << anph[0].second.first;
	//for(int i=0; i<anph.size(); i++) cout << anph[i].first << " " << anph[i].second.first << " " << anph[i].second.second << endl;
	int answ = 0;
	for(int i=0; i<n; i++){
		int aux2 = anph[i].second.first;
		if(dp[aux2] + anph[i].first > d) answ++;
		for(int j=aux2+1; j<min(2*aux2,maxw); j++){
			dp[j-aux2] = max(dp[j-aux2],dp[j]+anph[i].second.second);
		}
	}
	printf("%d\n", answ);
 	return 0;
}


