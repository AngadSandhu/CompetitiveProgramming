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
    vector<int> a(n),frec(105,0);
    int mini = INT_MAX, maxi = 0;
    for(int &i : a) cin >> i, frec[i]++, mini = min(mini,i);
    cout << n - frec[mini] << endl;
  }
	return 0;
}