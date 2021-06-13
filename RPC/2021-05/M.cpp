#include <bits/stdc++.h>
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define sz(A) int(A.size())
#define FIFO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(A) begin(A),end(A)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<pair<ll,ll>> vll;
typedef vector<pair<int,int>> vii;
void f(int n) {
    if(n == 0) {cout << 0; return;}
    cout << "S(";
    f(n - 1);
    cout << ")";
}
int main(){
    string s;
    getline(cin, s);
    int x = 0, y = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'S') x++;
    }
    getline(cin, s);
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'S') y++;
    }
    f(x*y);
    cout << "\n";
    return 0;
}