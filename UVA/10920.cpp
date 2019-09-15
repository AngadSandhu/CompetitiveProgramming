#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dr[] = {1,0,-1,0},dc[] = {0,-1,0,1};
int main() {
	int n,p;
	while(cin>>n>>p,n>0){
		int r = n/2+1, c = n/2+1;
		int k = 1,st = 1,cnt = 0;
		while(k<p){
			for(int i = 0 ; i < 2 && k<p; i++,cnt++){
				k += st;
				r += st*dr[cnt%4], c += st*dc[cnt%4];
				//cout << r << " " << c << endl;
			}
			st++;
		}
		cnt--;
		while(k>p){
			k--;
			r -= dr[cnt%4], c -= dc[cnt%4];
		}
		printf("Line = %d, column = %d.\n",r,c);
	}
	return 0;
}
