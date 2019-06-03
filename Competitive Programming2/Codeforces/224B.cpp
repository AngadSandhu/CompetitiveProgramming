#include <bits/stdc++.h>
using namespace std;
int n,k,num[100005],freq[100005];
int main() {
	set<int>check,grup;
	cin >> n >> k;
	for(int i = 0; i < n ; i++){
		scanf("%d",&num[i]);
		check.insert(num[i]);
	}
	if(check.size() < k){
		printf("-1 -1\n");
		return 0;
	}
	int l = 0, r = k;
	for(int i = 0 ; i < k ; i++){
		grup.insert(num[i]);
		freq[num[i]]++;
	}
	while(grup.size() != k){
		grup.insert(num[r]);
		freq[num[r]]++;
		r++;
	}r--;
	while(freq[num[l]] > 1){
		freq[num[l]]--;
		l++;
	}
	
	printf("%d %d\n",l+1,r+1);
	return 0;
}
