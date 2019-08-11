#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ri(x) scanf("%d",&(x))
#define rll(x) scanf("%lld",&(x))
#define N 100005
#define first fi
#define second se
using namespace std;
typedef long long ll;
const int week = 100800;
string s,ss;
int l,m;
string maq[105];
int p[105],c[105],t[105],r[105];
vector<int>res;
vector<string> v;
int main(){
	cin >> l >> m;
	getline(cin,s);
	for(int i = 0 ; i < m ;i++){
		v.clear();
		getline(cin,s);
		for(int j = 0 ; j < s.size(); j++){
			if(s[j]==',') s[j] = ' ';
		}
		istringstream in(s);
		while(in>>ss){ v.push_back(ss); }
		s="";
		for(int j = 0 ; j < v.size()-4; j++){
			if(j!=0)s+=" ";
			s+=v[j];
		}
		p[i] = stoi(v[v.size()-4]);
		c[i] = stoi(v[v.size()-3]);
		t[i] = stoi(v[v.size()-2]);
		r[i] = stoi(v[v.size()-1]);
		maq[i] = s;
	}
	/*for(int i =0 ; i < m ; i++){
		cout << maq[i] << " " << p[i] << " " << c[i] << " " << t[i] << " " <<r[i]<<endl;
	}*/
	int cnt = 0,times = 0,mini = INT_MAX;
	for(int i = 0 ; i < m ; i++){
		cnt = 0; times = 0;
		for(int j = 0 ; j < week ;){
			cnt += c[i]*(min(t[i],week-j));
			j += min(t[i],week-j);
			j += min(r[i],week-j);
			if(cnt>=l) times+=cnt/l,cnt %=l;
		}
		//cout << times << endl;
		if(times>=10){ res.push_back(i); mini = min(mini,p[i]); }
	}
	if(res.size()==0) cout << "no such mower" << endl;
	else 
	for(auto vv : res){
		if(p[vv]==mini) cout << maq[vv] << endl;
	}
	//cout << mini << endl;
	return 0;
}



