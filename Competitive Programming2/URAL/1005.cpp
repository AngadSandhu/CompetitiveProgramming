#include<iostream>
#include<math.h>
using namespace std;

int main(){
	int n, w[20], grupo1 = 0, grupo2 = 0, min = 99999999;
	cin >> n;
	for(int i = 0; i < n ; i++){
		cin >> w[i];
	}
	
	for(int i = 0 ; i < (1<<n); i++){
		grupo1 = 0; grupo2 = 0;
		for(int j = 0; j < n ; j++){
			if((i>>j)&1){
				grupo1 += w[j];
			}else{
				grupo2 +=w[j];
			}
		}
		
		if(abs(grupo1 - grupo2) < min){
			min = abs(grupo1 - grupo2);
		}
		
	}
	cout << min << endl;
	return 0;
}
