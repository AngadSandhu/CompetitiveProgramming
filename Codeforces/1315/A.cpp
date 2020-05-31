#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

int main(){
	FIO;
        int n; cin >> n;
        vector<pair<int,int>> v(n);
        for(int i = 0 ; i < n ; i++) cin >> v[i].first;
        for(int i = 0 ; i < n ; i++) cin >> v[i].second;
        sort(v.begin(),v.end());
        multiset<int> st;
        ll sum = 0, res = 0;
        int c = 1;
        for(int i = 0  ; i < n ;){
            while(!st.empty() && v[i].first > c){
                sum -= *(--st.end());
                res += sum;
                st.erase(--st.end());
                c++;
            }
            c = v[i].first;
            while(i < n && v[i].first == c){
                st.insert(v[i].second);
                sum += v[i].second;
                i++;
            }
            sum -= *(--st.end());
            res += sum;
            st.erase(--st.end());
            c++;
        }
        while(!st.empty()){
            sum -= *(--st.end());
            res += sum;
            st.erase(--st.end());
        }
        cout << res << endl;
	return 0;
}