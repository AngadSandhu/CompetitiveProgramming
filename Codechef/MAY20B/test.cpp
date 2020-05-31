#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

int main(){
	FIO;
    int t = 10;
    cout << t << endl;
    while(t--){
        for(int i = 0 ; i < 100 ; i++){
            cout << char(rand()%26 + 'a');
        }
        cout << endl;
        for(int i = 0 ; i < 100 ; i++){
            cout << char(rand()%26 + 'a');
        }
        cout << endl;
        int tx = 10;
        cout << tx << endl;
        while(tx--){
            for(int i = 0 ; i < 10 ; i++){
                cout << char(rand()%26 + 'a');
            }
            cout << " " << rand()%10 << endl;
        }
        cout << endl;
    }
	return 0;
}