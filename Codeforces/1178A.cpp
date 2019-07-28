#include<bits/stdc++.h>
using namespace std;
int a[105];
vector<int>pos;
int main(){
int n;
cin >> n;
	for(int i = 0 ; i< n ; i ++){
		scanf("%d",&a[i]);
	}
	int sumt = a[0],sum = a[0];
	pos.clear();
	pos.push_back(1);
	for(int i = 1 ; i < n ; i++){
		if(2*a[i]<=a[0]){pos.push_back(i+1); sum+=a[i]; }
		sumt+=a[i];
	}
	if(2*sum>sumt){
		cout << pos.size() << endl;
		for(int i = 0 ; i < pos.size(); i++) cout << pos[i] << " ";
	}else{
		cout << 0 << endl;
	}
	return 0;
}
