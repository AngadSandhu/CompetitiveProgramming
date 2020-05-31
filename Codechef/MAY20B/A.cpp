#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

int main(){
	FIO;
	int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for(int &i : a) cin >> i;
        int mini = n+1,maxi = -1;
        for(int i = 0 ; i < n ; i++){
            int cur = 1;
            for(int j = i+1 ; j < n ; j++){
                if(a[j]-a[j-1] <= 2){
                    cur ++;
                }else break;
            }
            for(int j = i-1 ; j >= 0 ; j--){
                if(a[j+1]-a[j] <= 2){
                    cur ++;
                }else break;
            }
            mini = min(mini,cur);
            maxi = max(maxi,cur);
        }
        cout << mini << " " << maxi << endl;
    }
	return 0;
}