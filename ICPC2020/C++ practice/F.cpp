#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 
string s[2] = {"I hate ","I love "};
int main(){
	FIO;
	int n; cin >> n;
    for(int i = 0 ; i < n ; i++){
        if(i) cout << "that ";
        cout << s[i%2];
    }
    cout <<"it"<< endl;
	return 0;
}