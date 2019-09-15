#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	while(cin >> n,n>0){
		string s;
		getline(cin,s);
		while(getline(cin,s)){
			bool b = 1;
			stack<int> st,q;
			vector<int>res;
			res.push_back(INT_MAX);
			if(s=="0") break;
			stringstream in(s);
			int x;
			while(in>>x) q.push(x);	
			while(!q.empty()){
				while(!q.empty()&&(st.empty()||q.top()>st.top())){
					st.push(q.top());
					q.pop();
				}
				if(res.back()<st.top()) b = 0;
				res.push_back(st.top());
				st.pop();
			}
			cout << (b?"Yes":"No") << endl;
		}
		cout << endl;
	}
	return 0;
}
