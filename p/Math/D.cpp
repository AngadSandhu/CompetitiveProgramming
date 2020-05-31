#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

int main(){
	FIO;
	int n,c; 
    while(cin >> c >> n, c > 0){
        vector<int> a(n), p(n+1), last(c,-1);
        for(int &i : a) cin >> i;
        p[0] = last[0] = 0;
        for(int i = 1 ; i <= n ; i++){
            p[i] = (p[i-1] + a[i-1])%c;
            if(last[p[i]] != -1){
                for(int j = last[p[i]]+1 ; j <= i ; j++){
                    cout << j;
                    if(j<i) cout << " ";
                }
                cout << endl;
                break;
            }else last[p[i]] = i;
        }
    }
	return 0;
}