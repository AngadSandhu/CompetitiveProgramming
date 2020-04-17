#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
#define RB(x) (x<n?r[x]:0)
int SA[N], iSA[N], lcp[N];
void csort(vector<int>& sa, vector<int>& r, int k){
	int n=sa.size();
	vector<int> f(max(255,n),0),t(n);
	fore(i,0,n)f[RB(i+k)]++;
	int sum=0;
	fore(i,0,max(255,n))f[i]=(sum+=f[i])-f[i];
	fore(i,0,n)t[f[RB(sa[i]+k)]++]=sa[i];
	sa=t;
}
void build_sa(string& s){ // sa (0,n-1)
	s += "#";
	int n=s.size(),rank;
	vector<int> sa(n),r(n),t(n);
	fore(i,0,n)sa[i]=i,r[i]=s[i];
	for(int k=1;k<n;k*=2){
		csort(sa,r,k);csort(sa,r,0);
		t[sa[0]]=rank=0;
		fore(i,1,n){
			if(r[sa[i]]!=r[sa[i-1]]||RB(sa[i]+k)!=RB(sa[i-1]+k))rank++;
			t[sa[i]]=rank;
		}
		r=t;
		if(r[sa[n-1]]==n-1)break;
	}
	fore(i,1,n) SA[i-1] = sa[i], iSA[sa[i]] = i-1;
	s.erase(s.size()-1);
}
void build_lcp(string const& s){ // lcp[i] = lcp(sa[i-1],sa[i]) , (0,n-1)
    int n = s.size();
    for(int i = 0, k = 0; i < n; i++) {
        if(iSA[i] == n - 1){ k = 0; continue; }
        int j = SA[iSA[i] + 1];
        while(i + k < n && j + k < n && s[i+k] == s[j+k]) k++;
        lcp[iSA[i]] = k;
        if(k) k--;
    }
    for(int i = n-1 ; i >= 0 ; i--) lcp[i+1] = lcp[i];
    lcp[0] = 0; 
}
