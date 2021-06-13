#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    printf("%.9lf\n",n+m-hypot(n,m));
    return 0;
}