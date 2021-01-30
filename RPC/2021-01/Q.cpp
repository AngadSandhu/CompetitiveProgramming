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
        multiset<int> st;
        stack<int> q;
        int queries;
        cin >> queries;
        while (queries--)
        {
            int caso;
            cin >> caso;
            if (caso == 1)
            {
                int v;
                cin >> v;
                q.push(v);
                st.insert(v);
            }
            else if (caso == 2)
            {
                if (q.empty())
                    continue;
                int v;
                v = q.top();
                q.pop();
                st.erase(st.find(v));
            }
            else
            {
                if (q.empty())
                    cout << "Empty!" << endl;
                else
                    cout << abs(*(--st.end()) - *st.begin()) << endl;
            }
        }
    }
    return 0;
}