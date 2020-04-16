void build_lcp(string const& s){
    int n = s.size();
    for(int i = 0, k = 0; i < n; i++) {
        if(iSA[i] == n - 1){ k = 0; continue; }
        int j = SA[iSA[i] + 1];
        while(i + k < n && j + k < n && s[i+k] == s[j+k]) k++;
        lcp[iSA[i]] = k;
        if(k) k--;
    }
}
