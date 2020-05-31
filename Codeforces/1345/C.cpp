#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 
ll n;
ll f(ll x){
    return x*(x+1) + (x*(x+1)-2*x)/2;
}
int main(){
	FIO;
	int t; cin >> t;
    while(t--){
        cin >> n;
        vector<int> a(n);
        for(int &i:a) cin >> i;
        vector<int> room(n,0);
        for(int i = 0 ; i < n ; i++){
            room[((i+a[i])%n+n)%n]++;
        }
        bool flag = 1;
        for(int i = 0 ; i < n ; i++){
            if(room[i] >= 2 || room[i]==0) flag = 0;
        }
        cout << (flag?"YES":"NO") << endl;
    }
	return 0;
}