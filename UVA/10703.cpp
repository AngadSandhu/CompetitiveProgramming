#include<bits/stdc++.h>
using namespace std;
int n,m,q;
bool ar[505][505];
void pintar(int r,int c,int rr,int cc){
	for(int i = min(r,rr) ; i <= max(r,rr); i ++){
		for(int j = min(c,cc) ; j <= max(c,cc) ; j++){
			ar[i][j] = 1;
		}
	}
}
int main(){
	while(cin >> n >> m >> q, n > 0){
		memset(ar,0,sizeof(ar));
		while(q--){
			int x1,y1,x2,y2;
			cin >> x1 >> y1 >> x2 >> y2;
			pintar(--y1,--x1,--y2,--x2);
		}
		int res = 0;
		for(int i = 0 ; i < m; i ++){
			for(int j = 0 ; j < n ; j++){
				res+= ar[i][j]==0;
			}
		}
		if(res==0) cout << "There is no empty spots." << endl;
		else if(res==1) cout << "There is one empty spot." << endl;
		else cout << "There are "<<res<<" empty spots."<<endl;
	}
	return 0;
}
