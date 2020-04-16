#define RB(x) (x<n?r[x]:0)
void csort(vector<int>& sa, vector<int>& r, int k){
	int n=sa.size();
	vector<int> f(max(255,n),0),t(n);
	for(int i = 0; i < n ; i++)f[RB(i+k)]++;
	int sum=0;
	for(int i = 0; i < max(255,n) ; i++)f[i]=(sum+=f[i])-f[i];
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
vector<int> build_lcp(string& s, vector<int>& sa){
	int n=s.size(),L=0;
	vector<int> lcp(n),plcp(n),phi(n);
	phi[sa[0]]=-1;
	for(int i = 1 ; i < n ; i++)phi[sa[i]]=sa[i-1];
	for(int i = 0 ; i < n ; i++){
		if(phi[i]<0){plcp[i]=0;continue;}
		while(s[i+L]==s[phi[i]+L])L++;
		plcp[i]=L;
		L=max(L-1,0);
	}
	for(int i= 0 ; i < n ; i++)lcp[i]=plcp[sa[i]];
	return lcp; // lcp[i]=LCP(sa[i-1],sa[i])
}
