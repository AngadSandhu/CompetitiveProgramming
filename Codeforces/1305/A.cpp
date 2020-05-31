#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

int main(){
	FIO;
	int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n),b(n);
        for(int &i: a) cin >> i;
        for(int &i: b) cin >> i;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        for(int i : a) cout << i << " ";
        cout << endl;
        for(int i : b) cout << i << " ";
        cout << endl;
    }
	return 0;
}