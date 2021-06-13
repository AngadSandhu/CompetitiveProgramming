#include<bits/stdc++.h>
using namespace std;
#define N 400005
string s,p[8];
map<int,bool> vis;
int conv(string &a){
    int res = 0;
    for(int i = 0; i < a.size(); i++){
        res = 27*res + a[i]-'A'+1;
    }
    return res;
}
int main(){
    int n;
    cin >> n;
    getline(cin,s);
    for(int i = 0; i < n; i++){
        getline(cin,s);
        istringstream in(s);
        int m = 0;
        while(in >> p[m]) m++;
        for(int j = 0; j < m-2; j++){
            if(vis.find(conv(p[j])) == vis.end()){
                cout << i+1 << endl;
                return 0;
            }
        }
        vis[conv(p[m-1])] = 1;
    }
    cout << "correct" << endl;
    return 0;
}