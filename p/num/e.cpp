#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> num;
map<int,int> n;
int cnt = 0;
int BIT[200000];
bool freq[200000];
void upd(int x,int val){
	while(x<=200000){
		BIT[x] += val;
		x += (x & -x);
	}
}
int red(int x){
	int ret = 0;
	while(x>0){
		ret += BIT[x];
		x -= (x & -x);
	}
	return ret;
}
int main(){
	int q; scanf("%d",&q);
	cin.ignore();
	pair<char,int> query[q];
	char a; int x;
	for(int i = 0 ; i < q ; i++){
		scanf("%c %d",&a,&x);
		cin.ignore();
		query[i].first = a,query[i].second = x;
		if(a=='I') num.push_back(x);
	}
	sort(num.begin(),num.end());
	num.resize(unique(num.begin(),num.end())-num.begin());
	for(int i = 0 ; i < num.size() ; i++){
		n[num[i]] = i+1;
	}
	for(auto v : query){
		if(v.first=='I' && freq[n[v.second]]==0){
			upd(n[v.second],1);
			freq[n[v.second]]=1;
			cnt++;
		}
		if(v.first=='D' && n.find(v.second)!=n.end() && freq[n[v.second]]==1){
			upd(n[v.second],-1);
			freq[n[v.second]]= 0;
			cnt--;
		}
		if(v.first=='K'){
			int l = 1, r = num.size(), med;
			while(l<=r){
				med = (r+l)/2;
				if(red(med)>=v.second) r = med-1;
				else l = med+1;
			}
			if(l>num.size()){
				printf("invalid\n");
			}else printf("%d\n",num[l-1]);
		}
		if(v.first=='C'){
			//cout << "C" << endl;
			int L = lower_bound(num.begin(),num.end(),v.second)-num.begin()-1;
			printf("%d\n",red(L));
		}
	}
	return 0;
}
