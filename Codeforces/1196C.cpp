#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ri(x) scanf("%d",&(x))
#define rll(x) scanf("%lld",&(x))
#define N 0	
typedef long long ll;
using namespace std;
struct point{
	int x,y;
	point(){}
	point(int a,int b){x=a; y=b;}
};
const int l = 100000;
int n;
point a[300005];
bool f[300005][4];
int lx, rx,ly,ry;
 
bool solve(){
	for(int i = 0 ; i < n ; i++){
		if(f[i][0]==0) lx = max(lx,a[i].x);
		if(f[i][1]==0) ry = min(ry,a[i].y);
		if(f[i][2]==0) rx = min(rx,a[i].x);
		if(f[i][3]==0) ly = max(ly,a[i].y);
	}
	return rx>=lx && ry>=ly;
}
int main(){
	int t; cin >> t;
	while(t--){
		lx = -l; ly = -l; rx = l; ry = l;
		cin >> n;
		for(int i = 0 ; i < n ;i ++){
			int x,y;
			cin >> x >> y;
			a[i] = point(x,y);
			cin >> f[i][0] >> f[i][1] >> f[i][2] >> f[i][3];
			//cout << a[i].x << " " << a[i].y<< endl;
		}
		if(solve()){
			cout << "1 " <<lx << " " << ly << endl;
		}else{
			cout << 0 << endl;
		}
		//cout << lx << " " << rx << " " << ly << " " << ry << endl;
	}
	return 0;
}

