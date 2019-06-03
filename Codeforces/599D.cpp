#include<bits/stdc++.h>
using namespace std;

int main(){
	long long int n, count = 0;
	cin >> n;
	float m;
	vector <long long int> res_first;
	vector <long long int> res_second; 
	long long int aux;
	res_first.clear();
	res_second.clear();
	
	for(float i = 1; i*i*i <= 3*n ; i++){
		if(i ==1){
			count ++;
			res_first.push_back(1);
			res_second.push_back(n);
			continue;
		}
		
		m = (n + ((i*i*(i-1))/2) - (i*(i-1)*((2*i)-1)/6))/((i*i) - (i*(i-1)/2));
		aux = m;
		if(i>m) break;
		if(m-aux == 0){
			count ++;
			res_first.push_back(i);
			res_second.push_back(m);
		}
		
	}
	if(res_first[res_first.size()-1] == res_second[res_second.size()-1]){
		cout << 2*count -1 << endl;
	}else{
		cout << 2*count << endl;
	}
	for(int i=0; i<res_first.size(); i++){
		cout << res_first[i] << " " << res_second[i]<< endl;
	}
	for(int i=res_first.size() - 1; i>=0 ; i-- ){
		if(res_first[i] == res_second[i]) continue;
		cout << res_second[i] << " " << res_first[i] << endl;
		
	}
	return 0;
}
