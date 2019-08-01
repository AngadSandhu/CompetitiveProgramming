#include<bits/stdc++.h>
using namespace std;
long long h,l;
int main(){
	cin >> h >> l;
	double teta = 2*atan((double)h/l);
	printf("%.6f\n",abs((double)l/tan(teta)));
	return 0;
}
