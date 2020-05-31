#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 
string s;
set<char> st;
int main(){
	FIO;
    cin >> s;
    for(int i = 0 ; i < (int)s.size() ; i++) st.insert(s[i]);
    if(st.size()%2==0){
        cout << "CHAT WITH HER!" << endl;
    }else{
        cout << "IGNORE HIM!" << endl;
    }
	return 0;
}