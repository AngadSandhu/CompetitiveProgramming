#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    string s,b;
    cin >> s >> b;
    char a[m];
    for(int i = m-n, j = 0; i < m, j < n; i++, j++)
        a[i] = s[j];
    for(int i = m-1; i >= n; i--){
        a[i-n] = char((b[i]-a[i]+26)%26+'a');
    }
    for(int i = 0; i<  m; i++)
        cout << a[i];
    cout << endl;
    return 0;
}