#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
vector <int> grafo[205];
int w[205];
long long d[205],d_ant[205];
int V;
bool Belmand(int source){
		fill(d , d+V, 1e14);
		d[source] = 0;
		for(int i = 0 ; i < V ; i++)
			for(int u = 0 ; u < V ; u++)
				for(int v : grafo[u])
					d[v] = min(d[v], d[u] + (w[v]-w[u])*(w[v]-w[u])*(w[v]-w[u]));
       	for(int i = 0 ; i < V ; i++) d_ant[i] = d[i];
		
		for(int i = 0 ; i < V ; i++)
			for(int u = 0 ; u < V ; u++)
				for(int v : grafo[u])
					d_ant[v] = min(d_ant[v], d_ant[u] + (w[v]-w[u])*(w[v]-w[u])*(w[v]-w[u]));
		
		for(int i = 0 ; i < V ; i++) if(d_ant[i] != d[i]) d[i] = 2;
					
		return true;
}
int main(){
    int m, a, b, aux, q, cases = 0;
    while(cin >> V){
        for(int i = 0 ; i< V ; i++){
            cin >> w[i];
            grafo[i].clear();
        }
        cin >> m;    
        
        for(int i = 0 ; i < m ; i++){
            cin >> a >> b;
            grafo[--a].push_back(--b);
        }


        bool f = Belmand(0);
        cin >> q;
        printf("Set #%d\n",++cases);
        for(int i = 0 ; i < q ; i++){
            cin >> aux;
            aux--;
            if(d[aux] < 3 || d[aux] > 1e13) cout << '?' << endl;
            else cout << d[aux] << endl;
        
        }
    }
}
