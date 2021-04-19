#include<bits/stdc++.h>
using namespace std;
#define FIN ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define N 1005
string s;
int a[N];
int main(){FIN;
    int n,k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> s;
        a[i] = 0;
        for(int j = 0; j < k; j++)
            a[i] *= 2, a[i] += (s[j]=='T');
    }
    int res = 0;
    for(int i = 0; i < (1<<k); i++){
        int cur = k;
        for(int j = 0; j < n; j++)
            cur = min(cur,k-__builtin_popcount(i^a[j]));
        res = max(res,cur);
    }
    cout << res << endl;
    return 0;
}