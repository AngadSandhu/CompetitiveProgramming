#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

int main(){
	FIO;
        string s; cin >> s;
        int n = s.size();
        int maxi = -1, mini = n+1;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == ')') maxi = max(maxi,i);
            else mini = min(mini,i);
        }
        vector<int> ans;
        if(maxi < mini){
            cout << 0 << endl;
        }else{
            bool a = 1, b = 1;
            int lasti = 0, lastj = n-1;
            while(a && b){
                a = 0, b = 0;
                for(int i = lasti ; i <= lastj ; i++){
                    if(s[i] == '('){
                        a = 1;
                        lasti = i+1;
                        ans.pb(i);
                        break;
                    }
                }
                for(int i = lastj ; i >= lasti ; i--){
                    if(s[i] == ')'){
                        b = 1;
                        lastj = i-1;
                        ans.pb(i);
                        break;
                    }
                }
                if(a && !b) ans.pop_back();
                if(b && !a) ans.pop_back();
            }
            cout << 1 << endl;
            sort(ans.begin(),ans.end());
            cout << ans.size() << endl;
            for(auto v : ans) cout << v+1 << " ";
            cout << endl;
        }
	return 0;
}