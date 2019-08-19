#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;
 
int n;
int a[100005];
int q;
 
int main(){
	cin >> n;
	int mx = INT_MIN;
	int id =0 ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i];
		mx = max(mx,max(a[i],-a[i]-1));
		if(a[i]==mx|| (-a[i]-1)==mx) id = i;
	}
	if(n%2==0){
		for(int i= 0; i < n; i++){
			if(a[i]>=0) cout << (-a[i]) - 1 << " ";
			else cout << a[i] << " " ;
		}
	}else{
		for(int i= 0; i < n ; i++){
			if(id==i){ cout<< mx<<endl; continue; }
			if(a[i]>=0) cout << (-a[i]) - 1 << " ";
			else cout << a[i] << " ";
		}
	}
	cout << endl;
	return 0;
}
