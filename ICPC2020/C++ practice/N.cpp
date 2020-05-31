#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 100005
bool casado[N];
int n,k;
int main(){
	FIO;
	int t; cin >> t;
    while(t--){
        int solita = -1, solito = -1;
        cin >> n;
        for(int i = 0 ; i < n ; i++){
            cin >> k;
            vector<int> prince(k);
            for(int &x : prince) cin >> x;
            bool sola = 1;
            for(int x : prince){
                if(casado[x] == 0){
                    casado[x] = 1;
                    sola = 0;
                    break;
                }
            }
            if(sola) solita = i+1;
        }
        for(int i = 1 ; i <= n ; i++){
            if(casado[i] == 0) solito = i;
        }
        if(solita == -1) cout << "OPTIMAL" << endl;
        else{
            cout << "IMPROVE"<< endl;
            cout << solita<< " " << solito<< endl;
        }
        for(int i = 0 ; i <= n ; i++) casado[i] = 0;
    }
	return 0;
}