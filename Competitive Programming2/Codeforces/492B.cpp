#include <bits/stdc++.h>
using namespace std;
#define N 1000000000

int n,long_calle,lamp[1000],mayord = -1;
double epsilon = 0.000000001;
bool alumbra(double d);
int main() {
	
	cin >> n >> long_calle;
	for(int i = 0 ; i < n; i++){
		cin >> lamp[i];
	}
	sort(lamp,lamp+n);
	for(int i = 0 ; i < n -1 ; i++){
		if(lamp[i+1]-lamp[i] > mayord)
		mayord = lamp[i+1]-lamp[i];
	}
	double l = 0, r = long_calle, med;
	while(l < r){
		med = (l+r)/2;
		if(med - l < epsilon) break;
		if(alumbra(med)){
			if(r -med < epsilon)break;
		 r = med;	
		}
		else l = med;
	}
	cout <<fixed << showpoint << setprecision(9)<< med << endl;
	return 0;
}
bool alumbra(double d){
	bool yes = true;
	if(!(lamp[0] - d <= 0)) yes = false;
	if(!(lamp[n-1] + d >= long_calle)) yes = false;
	if(!(2*d >= mayord)) yes = false;
	return yes;
}
