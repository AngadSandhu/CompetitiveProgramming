#include <bits/stdc++.h>
using namespace std;
typedef pair<long long,long long> ii;
ii judges[1005];
ii repos[1005];
ii stores[1005];

bool used_judge[1005];
bool used_repo[1005];
bool used_store[1005];


struct dist{
    bool isRepo;
    int judge, other;
    long long distance;
    dist(int _judge, int _other, long long _distance, bool _isRepo){
        judge = _judge;
        other = _other;
        distance = _distance;
        isRepo = _isRepo;
    }
    bool used(){
        if(isRepo) return used_judge[judge] | used_repo[other];
        return used_judge[judge] | used_store[other];
    }
    void use(){
        used_judge[judge] = 1;
        if(isRepo) used_repo[other] = 1;
        else used_store[other] = 1;
    }
    dist(){};
};

bool operator<(const dist &a, const dist &b){
    if(a.distance != b.distance) return a.distance < b.distance;
    if(a.judge != b.judge) return a.judge < b.judge; 
    return a.other < b.other;
}

vector<dist> s;

long long dis(ii a, ii b){
    return (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
}

int main(){
    double ans = 0;
    int m, n, p;
    cin >> m >> n >> p;
    for(int i = 0 ; i < m ; i++) cin >> judges[i].first >> judges[i].second, used_judge[i] = 0;
    for(int i = 0 ; i < n ; i++) cin >> repos[i].first >> repos[i].second, used_repo[i] = 0;
    for(int i = 0 ; i < p ; i++) cin >> stores[i].first >> stores[i].second, used_store[i] = 0;

    for(int i = 0 ; i < m ; i++){
        for(int j = 0; j < n; j++){
            s.push_back( dist(i,j,dis(judges[i], repos[j]), true) );
        }
    }

    sort(s.begin(), s.end());
    int cont = 0;    
    for(auto i: s){
        if(!i.used()){
            ans += sqrt(i.distance);
            i.use();
            cont++;
        }
        if(cont >= m) break;
    }
    
    s.clear();

    for(int i = 0 ; i < m ; i++){
        used_judge[i] = 0;
        for(int j = 0; j < p; j++){
            s.push_back( dist(i,j,dis(judges[i], stores[j]), false) );
        }
    }


    sort(s.begin(), s.end());
    cont = 0;    
    for(auto i: s){
        if(!i.used()){
            ans += sqrt(i.distance);
            i.use();
            cont ++;
        }
        if(cont >= m) break;
    }

    
    printf("%.6lf\n", ans);

    return 0;
}