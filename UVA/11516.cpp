#include <bits/stdc++.h>
using namespace std;
int cantwifi, n , house[100005];
bool posiblewifi(int dis){
	int used = 1, fin = house[0] + dis;
	for(int i = 1 ; i < n ; i++){
		if(fin < house[i]){
			fin = house[i] + dis;
			used++;
		}
	}
	return used <= cantwifi;
}

int main() {
	int T; cin >> T;
	while(T--){
		cin >> cantwifi >> n;
		for(int i = 0 ; i < n ; i++){
			cin >> house[i];
			house[i]*=10;
		}
		if(cantwifi >= n){
			cout << "0.0\n";
			continue;
		}
		sort(house,house+n);
		int l = 0 , r = 10000005, med;
		for(int i = 0 ; i < 22 ; i++){
			med = (r+l)/2;
			if(posiblewifi(2*med)) r = med;
			else l = med+1;
		}
		if(abs(med%10 - 5) <= 2) med = med - med%10 +5;
		if(med%10 > 5) med += 10 - med%10;
		if(med%10 < 5) med -= med%10;
		printf("%d.%d\n",med/10,med%10);
		
		
	}
	return 0;
}
