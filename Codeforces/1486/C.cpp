#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 
int n;
int L,R,med;
int ask(int l,int r){
  cout << "? " <<  l << " " << r << endl;
  int ans; cin >> ans;
  return ans;
}
int main(){
	FIO;
	cin >> n;
  L = 1, R = n;
  int next = -1;
  while(L < R){
    if(L+1 == R){
      if(ask(L,R)==L){
        cout << "! " << R << endl;
      }else{
        cout << "! " << L << endl;
      }
      return 0;
    }
    med = (L+R)/2;
    int p = ( next==-1 ? ask(L,R) : next) ;
    if(p <= med){
      int curr = ask(L,med);
      if(p == curr){
        next = curr;
        R = med;
      }else{
        next = -1;
        L = med+1;
      }
    }else{
      int curr = ask(med,R);
      if(p == curr){
        next = curr;
        L = med;
      }else{
        next = -1;
        R = med-1;
      }
    }
  }
  cout << "! " << L << endl;
	return 0;
}