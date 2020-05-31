#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 
int a[4];
int main(){
	FIO;
	for(int i = 0 ; i < 4 ; i ++) cin >> a[i];
    sort(a,a+4);
    cout << a[3] - a[0] << " " << a[3] - a[1] << " " << a[3] - a[2] << endl;
	return 0;
}