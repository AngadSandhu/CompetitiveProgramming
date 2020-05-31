#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 1005
#define M 10005
#define nodos 26*10000+5
char a[N],b[N];
int sza,szb;
ll sa[N], sb[N];
char d[M][26], s[26];
int dsz[M], val[M], m, len;
int trie[nodos][26], terminal[nodos], nodes = 1;
void add(int id){
    int cur = 0;
    for(int i = 0, c ; i < dsz[id] ; i++){
        c = d[id][i]-'a';
        if(trie[cur][c] == -1) trie[cur][c] = nodes++;
        cur = trie[cur][c];
    }
    terminal[cur] = val[id];
}
ll get(int x){
    int cur = 0;
    ll ret = 0;
    for(int i = 0, c ; i < len ; i++){
        c = s[i] - 'a';
        if(trie[cur][c] == -1) return ret;
        cur = trie[cur][c];
        if(terminal[cur] && i >= x) ret += terminal[cur];
    }
    return ret;
}
int main(){
    memset(trie,-1,sizeof trie);
	int t; scanf("%d",&t);
    while(t--){
        scanf("%s %s",a,b);
        scanf("%d",&m);
        sza = strlen(a), szb = strlen(b);
        for(int i = 0 ; i < m ; i++){
            scanf("%s %d",d[i], &val[i]);
            dsz[i] = strlen(d[i]);
            add(i);
        }
        cout << "A" << endl;
        for(int i = 0 ; i < sza ; i++){
            ll cur = 0;
            for(int j = 0 ; j <= i ; j++){
                len = 0;
                for(int k = j ; k-j+1 <= 26  && k <= i ; k++) s[len++] = a[k];
                cur += get(0);
            }
            sa[i] = cur;
            cout << "i: " << sa[i] << endl;
        }
        cout << "B" << endl;
        for(int i = szb-1 ; i >= 0 ; i--){
            ll cur = 0;
            for(int j = i ; j < szb ; j++){
                len = 0;
                for(int k = j ; k-j+1 <= 26 && k < szb ; k++) s[len++] = b[k];
                cur += get(0);
            }
            sb[i] = cur;
            cout << "i: " << sb[i] << endl;
        }
        ll res = 0;
        for(int i = 0 ; i < sza ; i++){
            for(int j = 0 ; j < szb ; j++){
                ll cur = 0;
                int tm = min(i+1+szb-j,26);
                for(int k = max(0,i-tm+1) ; k <= i ; k++){
                    len = 0;
                    for(int p = k ; p <= i ; p++) s[len++] = a[p];
                    for(int p = j ; p-j+1 <= 26-(i-k+1) && p < szb ; p++) s[len++] = b[p];
                    cur += get(i-k+1);
                }
                cout << "i:" << i << " j:" << j << " " << cur << " " <<endl;
                res = max(res,sa[i] + sb[j] + cur);
            }
        }
        cout << res << "\n";
        for(int i = 0 ; i < nodes ; i++){
            terminal[i] = 0;
            fill(trie[i],trie[i]+26,-1);
        }
        nodes = 1;
    }
	return 0;
}