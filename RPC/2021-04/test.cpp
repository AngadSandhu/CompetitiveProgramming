#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

int main(){
	FIO;
	srand(time(NULL));
  int n = 8;
  vector<int> a(n);
  for(int i = 0 ; i < n ;i++){
    a[i] = i+1;
  }
  random_shuffle (a.begin(), a.end());
  cout << n << endl;
  for(int i =0 ; i < n ; i++) cout << a[i] << endl;
	return 0;
}