#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define max3(x,y,z) max(x,max(y,z))
#define min3(x,y,z) min(x,min(y,z))
#define fori(x,n) for(int i = x; i < n; i++)
#define forj(y,m) for(int j = y; j < m; j++)
#define fork(z,p) for(int k = z; k < p; k++)
#define ii pair<int,int>
#define N 0
typedef long long ll;
 
using namespace std;
 
int n,m;
int a[300005][2];
bool p = 0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	fori(0,m){
		cin>>a[i][0]>>a[i][1];
	}
	int x;
	fori(0,2){
		x = a[0][i];
		vector<int>freq(n);
		int c = 0;
		forj(1,m){
			if(a[j][0]!=x && a[j][1]!=x) {
				freq[a[j][0]]++, freq[a[j][1]]++, c++;
			}
		}
		if(*max_element(all(freq))==c){ p = 1; break;}
	}
	cout << (p?"YES":"NO")<<endl;
	return 0;
}
