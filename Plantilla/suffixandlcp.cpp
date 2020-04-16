#define RB(x) (x<n?r[x]:0)
void csort(vector<int>& sa, vector<int>& r, int k){
	int n=sa.size();
	vector<int> f(max(255,n),0),t(n);
	for(int i = 0; i < n ; i++)f[RB(i+k)]++;
	for(int i = 0,sum = 0; i < max(255,n) ; i++)f[i]=(sum+=f[i])-f[i];
	for(int i = 0; i < n ; i++)t[f[RB(sa[i]+k)]++]=sa[i];
	sa=t;
}
vector<int> build_sa(string& s){ // O(n logn)
	int n=s.size(),rank;
	vector<int> sa(n),r(n),t(n);
	for(int i = 0 ; i <n ; i++)sa[i]=i,r[i]=s[i];
	for(int k=1 ; k<n ; k*=2){
		csort(sa,r,k);csort(sa,r,0);
		t[sa[0]]=rank=0;
		for(int i = 1 ; i < n ; i++){
			if(r[sa[i]]!=r[sa[i-1]]||RB(sa[i]+k)!=RB(sa[i-1]+k))rank++;
			t[sa[i]]=rank;
		}
		r=t;
		if(r[sa[n-1]]==n-1)break;
	}
	return sa;
}
vector<int> build_lcp(string const& s, vector<int> const& p) {
    int n = s.size();
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++) rank[p[i]] = i;
    vector<int> lcp(n-1, 0);
    for (int i = 0, k = 0; i < n; i++) {
        if (rank[i] == n - 1){ k = 0; continue; }
        int j = p[rank[i] + 1];
        while (i + k < n && j + k < n && s[i+k] == s[j+k])k++;
        lcp[rank[i]] = k;
        if (k) k--;
    }
    return lcp;
}
