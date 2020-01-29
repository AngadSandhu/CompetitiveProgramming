#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[9][10];
int main(){
	int t;cin >> t;
	while(t--){
		memset(a,-1,sizeof a);
		for(int i = 0; i < 9; i+=2){
			for(int j = 0 ; j < i+1; j+=2){
				cin>> a[i][j];
			}
		}
		for(int i = 1 ; i < 9 ; i+=2){
			a[8][i] = (a[6][i-1] - a[8][i-1] - a[8][i+1])/2;
		}
		for(int i = 7; i >=0; i--){
			for(int j = 0 ; j < i+1; j++){
				if(a[i][j]!=-1) continue;
				a[i][j] = a[i+1][j]+a[i+1][j+1];
			}
		}
		for(int i = 0; i < 9; i++){
			for(int j = 0 ; j < i+1; j++){
				cout << a[i][j];
				if(j!=i) cout << " ";
			}
			cout << endl;
		}
	}
}
