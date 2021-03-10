#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 100005
int n,m;
struct Book{
	int l, d;
	Book(){};
	void cinBook(){
		cin >> l >> d;
	}
};
Book ar[N];

bool comp(Book b1, Book b2){
	return b1.d < b2.d;
}

bool f(int v){
	int curr = 0, carry=0, dead = 0;
	for(int i = 0 ; i < n ; i++){
		if(curr + (carry+ar[i].l)/v >= ar[i].d){
			dead++;
			continue;
		}
		curr += (carry+ar[i].l)/v;
		carry = (carry + ar[i].l)%v;
	}
	return dead > m;
}

/*
100 5
1 6
1 6
1 6
1 6
1 6
*/


int main(){
	FIO;
	cin >> n >> m;
	for(int i = 0 ; i < n ; i++) ar[i].cinBook();
	sort(ar,ar+n,comp);

	int l = 1, r = 1e9, med;
	while(l < r){
		med = (l+r)/2;
		if(!f(med)) r = med;
		else l = med+1;
	}
	cout << l << endl;
	return 0;
}