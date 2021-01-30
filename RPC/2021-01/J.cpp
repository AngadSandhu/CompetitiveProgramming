#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N

int main()
{
    FIO;
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll ans = n * n * (n + 1) / 2;
        n--;
        ans -= n * (n + 1) * (n + 2) / 3;
        cout << ans << endl;
    }
    return 0;
}