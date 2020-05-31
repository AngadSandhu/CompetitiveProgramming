#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

int main(){
	FIO;
	int n; cin >> n;
    vector<int> a(n);
    for(int &i : a) cin >> i;
    sort(a.begin(),a.end());
    long double mini = 1;
    bool flag = 1;
    for(int i = 0 ; i < n ; i++){
        if(a[i] > i+1) flag = 0;
        mini = min(mini,(long double)a[i]/(i+1));
    }
    if(flag) cout << setprecision(7) << mini << endl;
    else cout << "impossible" << endl;
	return 0;
}