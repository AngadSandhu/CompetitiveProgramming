#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, a[100005], b[100005];
long long f(int mediana){
	long long c = 0;
	for(int i = 0 ; i < n; i++){
		if(a[i]<mediana) c += mediana-a[i];
	}
	for(int i = 0 ; i < m ; i++){
		if(b[i]>mediana) c += b[i]-mediana;
	}
	return c;
}

int main(){
	cin >> n >> m;
	for(int i = 0 ; i < n ; i++){
		scanf("%d",&a[i]);
	}
	for(int i = 0 ; i < m ; i++){
		scanf("%d",&b[i]);
	}
	int l = 0, r = 1e9, m1,m2;
	long long mini=1e18;
	while((r-l)>3){
		m1 = l + (r-l)/3;
		m2 = r - (r-l)/3;
		if( f(m1) > f(m2) ) l = m1;
		else r = m2;
	}
	for(int i = l ; i <= r ;i++){
			mini = min(mini,f(i));
	}
	cout << mini << endl;
	return 0;
}
