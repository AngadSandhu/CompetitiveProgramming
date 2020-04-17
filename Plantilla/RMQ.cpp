int rmq[N][25];
int n;
void build_rmq(){
	for(int i = 0 ; i < n ; i++) rmq[i][0] = lcp[i];
	for(int j = 1 ; (1<<j) <= n ; j++){
		for(int i = 0 ; i + (1<<j) <= n; i++){
			rmq[i][j] = min(rmq[i+(1<<(j-1))][j-1],rmq[i][j-1]);	
		}
	}
}
int query_rmq(int i,int j){
	int b = 31-__builtin_clz(j-i+1);
	return min(rmq[i][b],rmq[j+1-(1<<b)][b]);
}
