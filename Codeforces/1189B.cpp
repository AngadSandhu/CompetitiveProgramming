#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int main(){
	cin >> n;
	for(int i = 0; i < n ; i++) scanf("%d",&a[i]);
	sort(a,a+n);
	bool pos = 1;
	int aux;
	for(int i = 0 ; i < n ; i++) 
		if(a[i]>=(a[(i+1+n)%n]+a[(i-1+n)%n])) pos = 0;
	if(pos){
		cout << "YES"  << endl;
		for(int i = 0 ; i < n ; i++) cout << a[i] << " ";
		cout << endl;
	}else{
		for(int i = n-2 ; i>0 ; i--){
			if(a[n-1]<(a[i]+a[i-1])){
				aux = i;
				pos = 1;
				break;
			}
		}
		if(pos){
			cout << "YES" << endl;
			for(int i =0 ; i < n-1 ; i++){
				if(i==aux) cout << a[n-1] << " ";
				cout << a[i] << " ";
			}
			cout << endl;
		}else cout << "NO" <<endl;
	}
	return 0;
}
