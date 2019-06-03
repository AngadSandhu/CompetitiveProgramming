#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,c,pos[1000005];
bool f(int d){
	int used = 1 , fin = pos[0]+d;
	for(int i = 1 ; i < n ; i ++){
		if(pos[i] >= fin){
			used++;
			fin = pos[i] + d;
		}
	}
	return used >= c;
}
int main(){
	int t; scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&c);
		for(int i = 0 ; i < n ; i++){
			scanf("%d",&pos[i]);
		}
		sort(pos,pos+n);
		int l = 0, r = (1e9)+5, m;
		for(int i = 0 ; i < 32 ; i++){
			m = l + (r-l+1)/2;
			if(f(m)) l = m;
			else r = m-1;
		}
		printf("%d\n",l);
	}
}	
