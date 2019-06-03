#include<bits/stdc++.h>
using namespace std;
int n,k;
string s;
bool f(int len){
	int canta=0 , cantb=0; int r = len;
	for(int i = 0 ; i < len ; i++){
		if(s[i] =='a') canta++;
		else cantb++;
	}
	for(int l = 1 ; l <= s.length()-len ; l++,r++){
		if(min(canta,cantb) <= k) return true; 
		if(s[r] =='a') canta++;
		else cantb++;
		if(s[l-1] =='a') canta--;
		else cantb--;
	}
	return (min(canta,cantb) <= k);
}

int main(){
	cin >> n >> k >> s;
	int l = 0 , r = n, med;
	while(l<r){
		med = l + (r-l+1)/2;
		if(f(med)) l = med;
		else r = med-1;
	}
	cout << l << endl;
	return 0;
}
