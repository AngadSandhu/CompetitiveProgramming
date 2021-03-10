#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 
int h,m;
int sz_h, sz_m;
map<char,char> mirror;
bool isValid(string H,string M){
  if (H.find('3')!=std::string::npos) return false;
  if (H.find('4')!=std::string::npos) return false;
  if (H.find('6')!=std::string::npos) return false;
  if (H.find('7')!=std::string::npos) return false;
  if (H.find('9')!=std::string::npos) return false;
  if (M.find('3')!=std::string::npos) return false;
  if (M.find('4')!=std::string::npos) return false;
  if (M.find('6')!=std::string::npos) return false;
  if (M.find('7')!=std::string::npos) return false;
  if (M.find('9')!=std::string::npos) return false;
  return true;
}
string toTime(int t){
  string H = to_string(t/m), M = to_string(t%m);
  while(H.size() < sz_h){
    H = '0' + H;
  }
  while(M.size() < sz_m){
    M = '0' + M;
  }
  return H + ":" + M;
}
bool isMirrorValid(int t){
  string H = to_string(t/m), M = to_string(t%m);
  while(H.size() < sz_h){
    H = '0' + H;
  }
  while(M.size() < sz_m){
    M = '0' + M;
  }
  if(!isValid(H,M)) return false;
  string mH = H, mM = M;
  reverse(mH.begin(),mH.end());
  reverse(mM.begin(),mM.end());

  for(int i = 0 ; i < H.size() ; i++) mH[i] = mirror[mH[i]];
  for(int i = 0 ; i < M.size() ; i++) mM[i] = mirror[mM[i]];
  H = mM, M = mH;

  if(stoi(H) >= h || stoi(M) >= m) return false;
  return true;
}

int main(){
	FIO;
  mirror['0'] = '0';
  mirror['1'] = '1';
  mirror['2'] = '5';
  mirror['5'] = '2';
  mirror['8'] = '8';
	int t; cin >> t;
  while(t--){
    cin >> h >> m;
    sz_h = 2;
    sz_m = 2;
    string look; cin >> look;
    int tLook = 0;
    for(int i = 0 ; i < look.size() ; i++){
      if(look[i]==':'){
        tLook += stoi(look.substr(0,i))*m;
        tLook += stoi(look.substr(i+1));
        break;
      }
    }
    for(int i = 0 ; i < h*m ; i++){
      int t = (tLook + i)%(h*m);
      //cout << toTime(t) << " " << isMirrorValid(t) << endl;
      if(isMirrorValid(t)){
        cout << toTime(t) << endl;
        break;
      }
    }
    
  }
	return 0;
}