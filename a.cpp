#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ri(x) scanf("%d",&(x))
#define rll(x) scanf("%lld",&(x))
#define N 0

typedef long long ll;
using namespace std;

int n;
int a[150005];
int freq[150005];

int main(){
	cin >> n;

	for(int i = 0 ; i < n ;i ++){ ri(a[i]); freq[a[i]]++; }
	for(int i = 1 ; i < 150001 ;i ++){
		if(freq[i]>3) continue;
		if(freq[max(i-1,1)]==0 && freq[i]>=1) {freq[max(i-1,1)]++;freq[i]--;}
		if(freq[i]>1){freq[min(i+1,150000)]++; freq[i]--; }
	}
	int c = 0;
	for(int i = 1 ; i < 150001 ;i ++){
		if(freq[i]>=1) c++;
	}
	cout << c << endl;
}

