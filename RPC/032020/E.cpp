#include <bits/stdc++.h>
using namespace std;
vector <int> cv, shuf;
int sor = 0;
int sor_init = INT_MAX;
int shufi = 0;
int shuf_init = INT_MAX;
void print(vector <int> a){
    for(int i: a) cout<< i << " ";
    cout << endl;
}
void read_expression();
void shuffle(){
    sort(cv.begin() + shuf_init, cv.end());
    if(cv.back() != cv[shuf_init]){
        shuf.push_back(shuf_init);
        shuf.push_back(cv.size());
    }
}
void sorty(){
    sort(cv.begin() + sor_init, cv.end());
}
void read_array(){
    char c = 'x';
    int aux = 0;
    while(1){
        aux = 0;
        cin >> c;   
        while(c != ',' && c!= ']'){
            aux = 10*aux + (c-'0');
            cin >> c;
        }
        cv.push_back(aux);
        if(c == ']') break;
    }
}
void read_sorty(){
    sor_init = min(sor_init, (int) cv.size());
    sor++;
    char c;
    for(int i = 0 ; i < 5 ; i++) cin >> c;
    read_expression();
    cin >> c;
    sor--;
    if(sor + shufi == 0) sorty();
    if(sor == 0) sor_init = INT_MAX;
}
void read_concat(){
    char c;
    for(int i = 0 ; i < 6 ; i++) cin >> c;
    read_expression();
    cin >> c;
    read_expression();
    cin >> c;
}
void read_shuffle(){
    shuf_init = min(shuf_init, (int) cv.size());
    shufi++;
    char c;
    for(int i = 0 ; i < 6 ; i++) cin >> c;
    read_expression();
    cin >> c;
    shufi--;
    if(shufi + sor == 0) shuffle();
    if(shufi == 0) shuf_init = INT_MAX;
}
void read_expression(){
    char c;
    cin >> c;
    if(c == '['){
        read_array();
    }
    if(c == 's'){
        cin >> c;
        if(c == 'o') read_sorty();
        else read_shuffle();
    } 
    if(c == 'c'){
        read_concat();
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    read_expression();
    vector<int> a = cv;
    vector<int> as = shuf;
    cv.clear();
    shuf.clear();
    read_expression();
    vector<int> b = cv;
    vector<int> bs = shuf;
    bool flag = true;
    if(a.size() == b.size()){
        for(int i = 0 ; i< a.size() ; i++){
            if(a[i] != b[i]){
                flag = false; break;
            }
        }
    }
    if(as.size() == bs.size()){
        for(int i = 0 ; i< as.size() ; i++){
            if(as[i] != bs[i]){
                flag = false; break;
            }
        }
    }
    if(a.size() != b.size() || as.size() != bs.size()) flag=  false;
    cout << (flag? "equal":"not equal") << endl;
    return 0;
}