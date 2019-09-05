#include<bits/stdc++.h>
using namespace std;


int main(){
	int a,b,c;
	cin >> a >> b >> c;
	for(int x = 0 ;x <= b ; x++){
		int y = b - x;
		int z = c - y;
		if(a==(x+z) && x>=0 && y>=0 && z >=0) {cout << x << " " << y << " " << z << endl;return 0;}
	}
	cout << "Impossible" << endl;
	return 0;
}

