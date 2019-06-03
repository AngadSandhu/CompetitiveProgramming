#include<iostream>
#include<math.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	bool isMan[50000];
	int day[50000][2];
	char gen;
	int cant_man[366]{}, cant_woman[366]{};
	int mayor = -1;
	
	for(int i=0; i<n; i++){
		cin >> gen >> day[i][0] >> day[i][1];
		if(gen == 'M')	isMan[i] =true;
	}
	
	for(int i=1; i<=366; i++){
		for(int j = 0; j < n ; j++){
			if(i >= day[j][0] && i <= day[j][1]){
				if(isMan[j]){
					cant_man[i-1]++;
				}else{
					cant_woman[i-1]++;
				}
			}
		}
	}
	
	for(int i = 0; i<366; i++){
		if(min(cant_man[i],cant_woman[i]) > mayor){
			mayor = min(cant_man[i], cant_woman[i]);
		}
	}
	
	cout << 2* mayor;
	
	return 0;
}
