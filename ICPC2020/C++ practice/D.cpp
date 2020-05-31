#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 
int q;
int n,m;
int main(){
	FIO;
	while(cin >> q, q > 0){
        cin >> n >> m;
        int x,y;
        for(int i = 0 ; i < q ; i++){
            cin >> x >> y;
            if(x==n || y==m){
                cout << "divisa" << endl;
                continue;
            }
            cout << (y < m ? "S" : "N");
            cout << (x < n ? "O" : "E");
            cout << endl;
        }

    }
	return 0;
}