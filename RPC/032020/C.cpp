#include <bits/stdc++.h>
using namespace std;
#define eps 1e-8
int t;
/*
    ^
    |       vel > 0 , dir 0
    ->      vel > 0, dir 1
    <-      vel < 0, dir 1
    |       vel < 0, dir 0
    v
*/
// Vayan haciendo ambos casos, se entiende la estructu
//usaremos el struct o wat
// carro
// sisi yo lo lleno 
// y llamo a sus fucniones
// gerardo colineales
// gonzalo perpendiculares
// 
struct carro{
    double x, y, w ,l, dir;
    double vel;
};
carro c1,c2;
bool colineales(){
    // 1 : chocan
    // 0 : no chocan
    double te, vm, ini, fin;
    if(c1.dir){
        if(2*c1.y+c1.w < 2*c2.y-c2.w || 2*c1.y-c1.w > 2*c2.y+c2.w){
            return 0;
        }else{
            if(c1.x >= c2.x){
                ini = c2.x+c2.l/2;
                fin = c1.x-c1.l/2;
                vm = c2.vel-c1.vel;
            }else{
                ini = c1.x+c1.l/2;
                fin = c2.x-c2.l/2;
                vm = c1.vel-c2.vel;
            }
        }
    }else{
        if(2*c1.x+c1.w < 2*c2.x-c2.w || 2*c1.x-c1.w > 2*c2.x+c2.w){
            return 0;
        }else{
            if(c1.y >= c2.y){
                ini = 2*c2.y+c2.l;
                fin = 2*c1.y-c1.l;
                vm = c2.vel-c1.vel;
            }else{
                ini = 2*c1.y+c1.l;
                fin = 2*c2.y-c2.l;
                vm = c1.vel-c2.vel;
            }
        }
    }
    te = (fin-ini)/vm;
    if(te <= 2*t && te >= 0) return 1;
    else return 0;
}
bool perpendiculares(){
    if(c1.dir == 0) swap(c1,c2);
    int signo1 = (c1.vel > 0 ? 1 : -1); 
    double c1t1 = ((2*c2.x - c2.w)- (2*c1.x + signo1*c1.l))/ c1.vel;   
    double c1t2 = ((2*c2.x + c2.w)- (2*c1.x - signo1*c1.l))/ c1.vel;
    int signo2 = (c2.vel > 0 ? 1 : -1);
    double c2t1 = ((2*c1.y - c1.w) - (2*c2.y + signo2*c2.l))/ c2.vel;   
    double c2t2 = ((2*c1.y + c1.w) - (2*c2.y - signo2*c2.l))/ c2.vel;
    double tr = min(c1t2, c2t2), tl = max(c1t1, c2t1);
    if(tr < tl || tr < 0 || tl > 2*t) return 0;
    else return 1;
}
int main(){
    char dir;
    int x,y,s,w,l;
    cin >> t;
    cin >> dir;
    if(dir == 'N' || dir == 'S') c1.dir = 0;
    else c1.dir = 1;
    cin >> c1.x >> c1.y >> c1.vel >> c1.w >> c1.l;
    if(dir == 'W' || dir == 'S') c1.vel *= -1;
    cin >> dir;
    if(dir == 'N' || dir == 'S') c2.dir = 0;
    else c2.dir = 1;
    cin >> c2.x >> c2.y >> c2.vel >> c2.w >> c2.l;
    if(dir == 'W' || dir == 'S') c2.vel *= -1;
    bool ans;
    if(c1.dir == c2.dir) ans = colineales();
    else ans = perpendiculares();
    cout << (ans ? "crash" : "safe") << endl;
}