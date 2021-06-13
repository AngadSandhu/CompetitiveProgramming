#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,s,n;
    cin >> t >> s >> n;
    int cur,last = 0,top = 0, bot = s;
    for(int i = 0,cur; i < n; i++){
        cin >> cur;
        top = max(0,top - (cur-last));
        bot = min(s,bot + (cur-last));
        last = cur;
        swap(top,bot);
    }
    top = max(0,top - (t-last));
    cout << top << endl;
    return 0;
}