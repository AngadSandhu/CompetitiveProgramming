#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 
int lis(vector<int> const &a)
{
    int n = a.size();
    vector<int> d;
    for (int i = 0; i < n; i++)
    {
        int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (j == d.size())
            d.pb(a[i]);
        else
            d[j] = a[i];
    }
    return d.size();
}
vector<int> lisWithConstruction(vector<int> const &v)
{
    vector<int> lis;
    vector<vector<int>> lisIndex;
    for (int i = 0; i < v.size(); i++)
    {
        int j = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
        if (j == lis.size())
        {
            lis.pb(v[i]);
            vector<int> newV(1, i);
            lisIndex.pb(newV);
        }
        else
        {
            lis[j] = v[i];
            lisIndex[j].pb(i);
        }
    }
    vector<int> lisConstruction;
    int last = lisIndex[lis.size() - 1].back();
    lisConstruction.pb(last);
    for (int i = lis.size() - 2; i >= 0; i--)
    {
        int j = lisIndex[i].size() - 1;
        while (j > 0 && lisIndex[i][j] >= last)
            j--;
        last = lisIndex[i][j];
        lisConstruction.pb(last);
    }
    reverse(lisConstruction.begin(), lisConstruction.end());
    for(auto &i : lisConstruction) i = v[i];
    return lisConstruction;
}
int main(){
	int t; cin >> t;
  cin.ignore();
  string s;
  getline(cin,s);
  while(t--){
    vector<int> ar;
    while(getline(cin,s)){
      if(s.empty()) break;
      stringstream in(s);
      int temp;
      in >> temp;
      ar.pb(temp);
    }
    vector<int> lis = lisWithConstruction(ar);
    printf("Max hits: %d\n",(int)lis.size());
    for(auto i : lis) cout << i << endl;
    if(t) cout << endl;
  }
	return 0;
}