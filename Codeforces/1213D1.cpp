
 #include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
typedef long long ll;
 
using namespace std;
int f(int n,int m){
	int ret = 0;
	while(n>=m){
		if(n==m) return ret;
		n/=2;
		ret++;
	}
	return -1;
}
int main(){
	int n,k; cin >> n >> k;
	vector<int> a(n);
	for(int &i : a) cin>> i;
	sort(all(a));
	int res = INT_MAX;
	for(int i = 1 ; i <= 2*100000; i++){
		int s = 0,c =0 ;
		for(int j = 0 ; j < n ; j++){
			if(c>=k) break;
			//cout << i << " " << f(a[j],i) << endl;
			if(f(a[j],i)!=-1) s += f(a[j],i) ,c++;
		}
		//cout << s << endl;
		if(c==k) res = min(res,s);
	}
	cout << res << endl;
	return 0;
}

