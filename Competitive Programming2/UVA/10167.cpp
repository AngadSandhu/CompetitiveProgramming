#include<iostream>
using namespace std;
 
int main(){
	int n, coord[100][2];
	int a,b, up = 0, down = 0;
	bool linea = false;
	bool res = false;
 
	while(cin >> n){
		if(n==0) break;
		for(int i =0; i<2*n; i++){
		cin >> coord[i][0] >> coord[i][1];
		}
	res = false;
 
	for(a = -500; a<=500; a++){
		for(b = -500; b<=500; b++){
			up = 0;
			down = 0;
			linea = false;
 
			for(int i =0; i < 2*n; i++){
				if((a * coord[i][0] + b * coord[i][1]) > 0){
					up++;
				}
				if((a * coord[i][0] + b * coord[i][1]) < 0){
					down++;
				}
				if((a * coord[i][0] + b * coord[i][1]) == 0){
					linea = true;
					break;
				}
			}
 
			if(up == down && up!= 0 && !linea){
				cout << a << " " << b <<endl;
				res = true;
				break;
			}
		}
		if(res) break;
	}	
	}
	return 0;
}
