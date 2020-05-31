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
        vector<int> a(n);
        for(int &i:a) cin >> i;
        bool found = 0;
        for(int i = 0 ; i < n ; i++){
            if(a[i]%2==0){
                cout << 1 << endl <<  i+1 << endl;
                found = 1;
                break;
            }
        }
        if(found == 0){
            if(n==1) cout << -1 << endl;
            else cout << 2 << endl << "1 2" << endl;
        }
    }
	return 0;
}