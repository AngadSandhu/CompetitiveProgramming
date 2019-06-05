#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,s;
	cin >> n;
	while(n--){
		cin>>s;
		int sum =0;
		for(int i = 1; i<=s;i++){
			int t; cin >> t;
			for(int j= 0; j<t; j++){
				sum^=i;
			}
		}
		if(sum) cout << "Tom Wins" <<endl;
		else cout << "Hanks Wins"<<endl;
	}
}
