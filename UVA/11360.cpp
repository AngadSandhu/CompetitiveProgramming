#include<bits/stdc++.h>
using namespace std;
int n,m,t;
int ar[15][15];
void row(int a,int b){
	vector<int> v;
	for(int i = 0 ; i < n ; i++) v.push_back(ar[a][i]);
	for(int i = 0 ; i < n ;i++) ar[a][i] = ar[b][i];
	for(int i = 0 ; i < n ;i++) ar[b][i] = v[i];	
}
void col(int a,int b){
	vector<int> v;
	for(int i = 0 ; i < n ; i++) v.push_back(ar[i][a]);
	for(int i = 0 ; i < n ;i++) ar[i][a] = ar[i][b];
	for(int i = 0 ; i < n ;i++) ar[i][b] = v[i];	
}
void inc(){
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j ++){
			ar[i][j] = (ar[i][j]+1)%10;
		}
	}
}
void dec(){
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j ++){
			ar[i][j] = (ar[i][j]+9)%10;
		}
	}
}
void transpose(){
	int c[15][15];
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j ++){
			c[j][i] = ar[i][j];
		}
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j ++){
			ar[i][j] = c[i][j];
		}
	}
}
int main(){
	cin >> t;
	int p = 0;
	while(t--){
		p++;
		cin >> n;
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j ++){
				char x;cin>>x;
				ar[i][j] = x-'0';
			}
		}
		cin >> m;
		int ax1,ax2;
		while(m--){
			string s;cin >> s;
			if(s=="row"){
				cin >> ax1 >> ax2; ax1--;ax2--;
				row(ax1,ax2);
			}else if(s=="col"){
				cin >> ax1 >> ax2; ax1--;ax2--;
				col(ax1,ax2);
			}else if(s=="inc"){
				inc();
			}else if(s=="dec"){
				dec();
			}else{
				transpose();
			}
		}
		printf("Case #%d\n",p);
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j ++){
				cout << ar[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}
