#include<iostream>
#include<math.h>
using namespace std;

int main(){
	int n = 0, aux = 0,count = 0, minum = 99999;
	bool res = false;
	char a;
	for(int i = 0 ; i < 16 ; i++){
		cin >> a;
		if(a == 'b'){
			n += (1<<i);
		}
	}
	
	for(int i = 0; i < (1<<16) ; i++){
		count = 0;
		aux = n;
		for(int j = 0; j < 16 ; j++){
			if((i>>j)&1){
				count++;
				aux = (aux^(1<<j));
			}
			if((j == 0) && ((i>>j)&1)){
				aux = (aux^(1<<(j+1)));
				aux = (aux^(1<<(j+4)));
			}
			if((j == 3) && ((i>>j)&1)){
				aux = (aux^(1<<(j-1)));
				aux = (aux^(1<<(j+4)));
			}
			if((j == 12) && ((i>>j)&1)){
				aux = (aux^(1<<(j-4)));
				aux = (aux^(1<<(j+1)));
			}
			if((j == 15) && ((i>>j)&1)){
				aux = (aux^(1<<(j-4)));
				aux = (aux^(1<<(j-1)));
			}
			if((j == 1||j==2) && ((i>>j)&1)){
				aux = (aux^(1<<(j-1)));
				aux = (aux^(1<<(j+1)));
				aux = (aux^(1<<(j+4)));
			}
			if((j == 4||j==8) && ((i>>j)&1)){
				aux = (aux^(1<<(j-4)));
				aux = (aux^(1<<(j+1)));
				aux = (aux^(1<<(j+4)));
			}
			if((j == 7||j==11) && ((i>>j)&1)){
				aux = (aux^(1<<(j-4)));
				aux = (aux^(1<<(j-1)));
				aux = (aux^(1<<(j+4)));
			}
			if((j == 13||j==14) && ((i>>j)&1)){
				aux = (aux^(1<<(j-4)));
				aux = (aux^(1<<(j-1)));
				aux = (aux^(1<<(j+1)));
			}
			if((j == 5||j==6||j==9||j==10) && ((i>>j)&1)){
				aux = (aux^(1<<(j-1)));
				aux = (aux^(1<<(j+1)));
				aux = (aux^(1<<(j-4)));
				aux = (aux^(1<<(j+4)));
			}
		}
		
		if(aux == 65535 || aux == 0){
			res = true;
			if(count<minum){
				minum = count;
			}
		}
		
	}
	if(res){
		cout << minum << endl;
	}else{
		cout << "Impossible" << endl;
	}
	return 0;
}
