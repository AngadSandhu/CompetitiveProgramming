#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 105
int n,m;
string a[N];
void move(int x, int y){
  string curra = a[x], currb = a[y];
  for(int i = x ; i < y ; i++){
    a[i] = a[i+1];
  }
  a[y] = curra;
}
int find(string s){
  for(int i = 0 ; i < n ; i++){
    if(s == a[i]) return i;
  }
  return 0;
}
int main(){
	FIO;
	cin >> n >> m;
  for(int i = 0; i < n ; i++) a[i] = 'T' + to_string(i+1);
  for(int i = 0 ; i < m ; i++){
    string x,y; cin >> x >> y;
    int posX = find(x), posY = find(y);
    if(posX < posY) continue;
    move(posY,posX);
  }
  for(int i = 0 ;i < n ; i++){
    if(i) cout << " ";
    cout << a[i];
  }
  cout << endl;
	return 0;
}