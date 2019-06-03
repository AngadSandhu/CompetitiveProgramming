#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,count = 0, num = 0;
	map<int,int> m;
	cin >> n;
	
	for(int n = 1 ; n <= 10 ; n++){
		for(int i = 0 ; i < (1 << n); i++){
			num = 0;
			for(int j = 0 ; j < n ; j++){
				if((i>>j)&1){
					num += 7*pow(10,j);
				}else{
					num += 4*pow(10,j);
				}
				
			}
			count++;
			m[num] = count;
		}
	}
	
	cout << m[n] << endl;
	return 0;
}
