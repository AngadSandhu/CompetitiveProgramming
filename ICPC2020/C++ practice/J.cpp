#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

int main(){
	FIO;
	vector<int> v(4);
    for(int &i:v) cin >> i;
    sort(v.begin(),v.end());
    bool pos = 0;
    if(v[0] + v[3] == v[1] + v[2]) pos = 1;
    if(v[3] == v[0] + v[1] + v[2]) pos = 1;
    cout << (pos ? "YES" : "NO") << endl;
	return 0;
}