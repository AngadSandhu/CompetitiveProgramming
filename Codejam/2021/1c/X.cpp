#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

int main(){
	FIO;
	int cnt = 0;
  int i = 1;
  while(cnt < 1e9){
    cnt += log10(i)+1;
    i++;
  }
  cout << i << endl;
	return 0;
}