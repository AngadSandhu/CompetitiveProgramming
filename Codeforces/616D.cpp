#include<bits/stdc++.h>
using namespace std;
#define N 1000005
int n,k;
int a[N];
int freq[N];
int main(){
	cin >> n >>k;
	for(int i = 0 ; i < n ; i ++) scanf("%d",&a[i]);
	int maxi = INT_MIN, cnt = 0, r = 0,ll,rr;
	for(int l = 0 ; l < n ;l++){
		while(cnt<k && r < n){
			if(freq[a[r]]==0) cnt++;
			freq[a[r]]++;
			r++;
		}
		while(cnt==k && freq[a[r]]!=0 && r < n) freq[a[r]]++, r++;
		if(maxi<r-l){ maxi = r-l; ll = l; rr =r; }
		if(freq[a[l]]==1) cnt--;
		freq[a[l]]--;
	}
	cout << ll+1 << " " << rr << endl;
	return 0;
}
