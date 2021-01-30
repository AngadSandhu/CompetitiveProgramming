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
        ll k, s, g;
        cin >> k >> s >> g;
        ll l = 0, r = g, med, n;
        while (l < r)
        {
            med = (l + r) / 2;
            n = med;
            if ((n * (s + s + (n - 1) * k)) / 2 > g)
                r = med;
            else
                l = med + 1;
        }
        cout << l << endl;
    }
    return 0;
}