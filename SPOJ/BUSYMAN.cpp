#include<bits/stdc++.h>
using namespace std;
#define N 100005
pair<int,int> rango[N];
int minindex[N];
int n;
int main(){
	int t; cin >> t;
	while(t--){
		cin >> n;
		for(int i = 0 ; i < n ; i++){
			scanf("%d %d",&rango[i].first,&rango[i].second);
		}
		sort(rango,rango+n);
		int mi = INT_MAX, index;
		for(int i = n-1; i >=0 ; i--){
			if(rango[i].second < mi){
				index = i;
				mi = rango[i].second;
			}
			minindex[i] = index;
		}
		int i = 0,cnt = 0;
		while(i<n){
			cnt++;
			i = minindex[i];
			i = lower_bound(rango,rango+n,make_pair(rango[i].second,0))-rango;
		}
		cout << cnt << endl;
	}
	return 0;
}
