#include <bits/stdc++.h>
using namespace std;
	int n, num[10005];
	double k,eps = 0.00000001;

bool f(double equal){
	double s1 = 0, s2 = 0; 
	for(int i = 0 ; i < n ; i++){
		if(num[i] - equal < eps){
			s1 += equal - num[i];
		}else{
			s2 += ((double)num[i] - equal)*(100-k)/100;
		}
	}
	return s2 -s1 >= eps;
	
}



int main() {
	cin >> n >> k;
	for(int i = 0 ; i < n ; i++){
		scanf("%d",&num[i]);
	}
	sort(num,num+n);
	double l = 0, r = 1e3,med;
	for(int i = 0 ; i < 40; i++){
		med = (l+r)/2;
		if(f(med)) l = med; 
		else r = med;
	}
	printf("%.6f",med);
	return 0;
}
