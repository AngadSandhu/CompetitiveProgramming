#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int main() {
	int n,book[10000],money;
	vector<ii> pos_sol,sol;
	while(cin >> n){
		pos_sol.clear();
		for(int i = 0 ; i < n ;i ++){
			cin >> book[i];
		}
		cin >> money;
		
		sort(book,book+n);
		
		for(int i = 0; i < n-1; i++){
			if(book[i] + book[i+1] > money) break;
			int l = i+1, r = n-1,med;
			while(l < r){
				med = (l+r+1)/2;
				if(book[i] + book[med] <= money){
					l = med;
				}else r = med -1;
			}
			pos_sol.push_back(make_pair(book[i],book[l]));
		}
		for(int i = 0 ; i < pos_sol.size() ; i++){
			if(pos_sol[i].first + pos_sol[i].second == money){
				sol.push_back(make_pair(pos_sol[i].first,pos_sol[i].second));
			}
		}
		cout << "Peter should buy books whose prices are " << sol[sol.size()-1].first << " and " << sol[sol.size()-1].second <<"."<<endl<<endl;
	}
	return 0;
}
