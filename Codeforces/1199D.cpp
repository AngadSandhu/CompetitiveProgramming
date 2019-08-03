#include<bits/stdc++.h>
using namespace std;
#define N 200005
int a[N],n,q,maxes[N];
pair<int,int>last[N];
vector<int>change;
int main(){
	cin >> n;
	for(int i = 0 ; i < n ; i++) scanf("%d",&a[i]);
	for(int i = 0 ; i < n ; i++) last[i] = {a[i],0};
	cin >> q;
	int op,s1,s2;
	for(int i = 0 ; i <	q; i++){
		cin >> op;
		if(op==1){
			cin >> s1 >> s2;
			last[--s1] = {s2,i};
			change.push_back(INT_MIN);
		}else{
			cin >> s1;
			change.push_back(s1);
		}
	}
	
	int maxi = INT_MIN;
	for(int i = q-1	; i>=0; i--){
		maxi = max(maxi,change[i]);
		maxes[i] = maxi;
	}
	for(int i = 0 ; i < n ; i++){
		cout << max(last[i].first,maxes[last[i].second]) << " ";
	}
	cout << endl;
	return 0;
}
