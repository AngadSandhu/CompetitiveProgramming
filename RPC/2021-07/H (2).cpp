#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
#define N 100005
#define FIFO ios::sync_with_stdio(false)
#define cout3(x, y, z) cout << x << " " << y << " " << z << endl
#define cout2(x, y) cout << x << " " << y << endl
#define INF (1<<30)
#define MOD 1000000007
#define ones(x) __builtin_popcountll(x)

using namespace std;

int main(){

	FIFO;

	int s, n, d;
	cin >> s >> n;
	
	string str;
	vector<int>nopaper, paper, aux;
	for(int i = 0; i < n; i++){
		
		cin >> d >> str;
		if(str == "y")paper.pb(d);
		else nopaper.pb(d);
	}
	
	sort(all(nopaper));
	sort(all(paper));
	
	aux.pb(paper.back());
	int cnt = 0;
	bool ok = true;
	
	for(int i = paper.size() - 2; i >= 0; i--){
		
		if(paper[i] == paper[i + 1])cnt++;
		else cnt = 0;
		
		if(paper[i] - cnt >= aux.back() || paper[i] - cnt <= 0)ok = false;
		aux.pb(paper[i] - cnt);
	}
	
	reverse(all(aux));
	paper = aux;
	
	/*cout << "paper" << endl;
	for(auto v: paper)cout << v << endl;
	cout << "paper" << endl;
	*/
	
	if(ok){
		
		for(int i = 0, count; i < nopaper.size(); i++){
			count = i + 1;
			count += upper_bound(all(paper), nopaper[i]) - paper.begin();
			//cout2(count, nopaper[i]);
			if((count + s - 1)/s > nopaper[i])ok = false;
		}
		
		if(ok)cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	else cout << "No" << endl;

}

