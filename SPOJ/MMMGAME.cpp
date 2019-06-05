#include<bits/stdc++.h>
using namespace std;
int p[50];
int main(){
	int t;
	cin >> t;
	while(t--){
		int n,nim=0;
		cin >> n;
		bool f=1;
		for(int i =0 ; i < n ;i++){
			cin>>p[i];
			if(p[i]>1) f=0;
			nim^=p[i];
		}
		bool lf=0;
		if(f) lf = nim ? 1:0;
		else lf = nim ? 0:1;
		string r = lf ? "Brother":"John";
		cout <<r<<endl;
	}
}
