#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 
int up,low,n;
string s;
int main(){
	FIO;
	cin >> s;
    n = s.size();
    for(int i = 0 ; i< n ; i++){
        if(islower(s[i])) low++;
        else up++;
    }
    if(low >= up){
        for(auto &i : s) i = tolower(i);
    }else{
        for(auto &i : s) i = toupper(i);
    }
    cout << s << endl;
	return 0;
}