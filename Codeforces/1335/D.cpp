#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 100
char ar[N][N];
int main(){
	FIO;
    int t; cin >> t;
    while(t--){
        for(int i = 0 ; i < 9 ; i++){
            for(int j = 0 ; j < 9 ; j++){
                cin >> ar[i][j];
                if(ar[i][j]=='1') ar[i][j] = '2';
            }
        }
        for(int i = 0 ; i < 9 ; i++){
            for(int j = 0 ; j < 9 ; j++){
                cout << ar[i][j];
            }
            cout << endl;
        }
    }
	return 0;
}