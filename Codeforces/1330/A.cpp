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
        int n,x; cin >> n >> x;
        vector<int> a(n);
        vector<bool> places(500);
        for(int &i : a) cin >> i,places[i] = 1;
        int i;
        for(i = 1 ; i < 500 ; i++){
            if(places[i]==0 && x==0) break;
            else if(places[i]==0) x--;
        }
        cout << i-1 << endl;
    }
	return 0;
}