#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 10005
ll fibo[N];
const int mod = INT_MAX;
int main()
{
    FIO;
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i < N; i++)
        fibo[i] = (fibo[i - 1] + (int)fibo[i - 2]) % mod;
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        bool flag = 0;
        for (int i = 0; i < N; i++)
        {
            if (fibo[i] == n)
            {
                flag = 1;
                break;
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}