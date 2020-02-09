#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int ar[100005];
int main(){
    int n; cin >> n;
    int maxi = -1;
    int res = 0;
    int maxres = 0;
    for(int i = 0 ; i < n ; i++){
        cin >> ar[i];
        maxi = max(ar[i],maxi);
    }
    for(int i = 0 ; i < n ; i++){
        if(maxi==ar[i]) res++;
        else res = 0;
        maxres = max(maxres,res);
    }
    cout << maxres << endl;
    return 0;
}