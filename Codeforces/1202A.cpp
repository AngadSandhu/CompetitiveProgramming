#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ri(x) scanf("%d",&(x))
#define rll(x) scanf("%lld",&(x))
#define N 0
using namespace std;
 
 
int n;
string a,b;
int f1, f2;
int main(){
	int n; cin >> n;
	while(n--){
		cin >> a >> b;
		f1=0;f2=0;
		for(int i = 0; i<b.size(); i++){
			if(b[i]=='1') f2= b.size()-i-1;
		}
		for(int i = a.size()-f2-1; i>=0;i--){
			if(a[i]=='1'){f1 = a.size()-i-1;break;}
		}
		//cout << f1 << " " << f2 << endl;
		cout << max(f1-f2,0) << endl;
	}
	
	
	return 0;
}
