#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ri(x) scanf("%d",&(x))
#define rll(x) scanf("%lld",&(x))
#define N 0
typedef long long ll;
using namespace std;
int a[200005];
int n,k;
int main(){
	int t;cin >> t;
	while(t--){
		cin >> n >> k;
		for(int i = 0 ; i < n ;i++) cin >>a[i];
		int cnt = 0;
		for(int i = 0 ; i < n ;i++){
			if(a[i]%2) cnt++;
		}
		a[n] = 1;
		if(cnt>=k && (cnt-k)%2==0){
			int cnt = 0;
			cout << "YES\n";
			for(int i = 0 ; i < n ;i++){
				if(a[i]%2){
					cnt++;
					if(cnt==k){ cout << n << " "; break; }
					cout << i+1<< " ";
				}
			}
		}else{
			cout << "NO";
		}
		cout << endl;
	}
	return 0;	
}
