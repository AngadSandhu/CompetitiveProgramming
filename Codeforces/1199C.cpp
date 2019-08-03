#include<bits/stdc++.h>
using namespace std;
#define N 400005
int n,I,k,K;
int a[N];
vector<int> freq;
int main(){
	cin >> n >> I;
	for(int i =0 ; i < n ;i++) scanf("%d",&a[i]);
	k = (8*I)/n;
	K = 1<<min(20,k);
	int cnt = 0;
	sort(a,a+n);
	for(int i = 0 ; i < n ; i++){
		cnt++;
		if(a[i]!=a[i+1]){ freq.push_back(cnt); cnt = 0; }
	}
	int r = 0,nn = freq.size(),c = 0,maxi = INT_MIN;
	for(int l = 0 ; l < nn ; l++){
		while(r-l<K && r < nn) c+= freq[r], r++;
		maxi = max(maxi,c);
		c-=freq[l];
	}
	cout << n - maxi << endl;
	return 0;
}
