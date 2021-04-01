int lis(vector<int> const& a) {
    int n = a.size();
    vector<int> d;
    for (int i = 0; i < n; i++) {
        int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if(j==d.size()) d.pb(a[i]);
        else d[j] = a[i];
    }
    return d.size();
}
