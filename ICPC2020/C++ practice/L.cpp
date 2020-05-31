#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 5005
int a[N];
int n;
int main(){
	FIO;
	int t; cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0 ; i < n ; i++){
            cin >> a[i];
        }
        vector<pair<int,int>> place(n+1,{INT_MAX,INT_MIN});
        for(int i = 0 ; i < n ; i++){
            place[a[i]] = {min(place[a[i]].first,i),max(place[a[i]].second,i)};
        }
        bool res = 0;
        for(int i = 1 ; i <= n ; i++){
            if(place[i].second - place[i].first >= 2) res = 1;
        }
        cout << (res ? "YES" : "NO") << endl;
    }
	return 0;
}