#include <iostream>
using namespace std;

int main(){
	int n, c = 1234567, b = 123456, a = 1234;
	cin >> n;
	bool posible = false;
	
	if(n%a == 0){
		posible = true;
	}else{
		for(int i = n/a; i>=0; i--){
			
			if(posible) break;
			
			if((n - i*a)%b == 0){
				posible = true;
				break;
			}else{
				for(int j = (n-i*a)/b ; j>=0 ; j--){
					if((n - i*a - j*b) % c == 0){
						posible = true;
						break;
					}
				}
			}
		}
	}
	
	if(posible){
		cout << "YES";
	}else{
		cout << "NO";
	}
	return 0;
}
