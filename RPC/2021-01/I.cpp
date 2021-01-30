#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N

int main()
{
    FIO;
    long long a, b;
    while (cin >> a >> b)
    {
        if (a == 0 && b == 0)
            break;
        switch (b % 4)
        {
        case 0:
            cout << a << endl;
            break;
        case 1:
            cout << a << "i" << endl;
            break;
        case 2:
            cout << -a << endl;
            break;
        case 3:
            cout << -a << "i" << endl;
            break;
        }
    }
    return 0;
}