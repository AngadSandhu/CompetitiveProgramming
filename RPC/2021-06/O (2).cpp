#include<bits/stdc++.h>
using namespace std;
#define N 505
int Cx[N],Cy[N],Fx[N],a[N],b[N],c[N];
double integral(int A, int B, int C, double x1, double x2){
    if((x2-x1) < 0) return 0;
    return 1.0*A/3*(1.0*x2*x2*x2 - 1.0*x1*x1*x1) + 1.0*B/2*(1.0*x2*x2 - 1.0*x1*x1) + 1.0*C*(x2-x1);
}
int main(){
    int n,m;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> Cx[i] >> Cy[i];
    cin >> m;
    for(int i = 0; i < m; i++)
        cin >> Fx[i] >> a[i] >> b[i] >> c[i];
    Cx[n] = Fx[m] = (1<<30);
    double last = 0, cur, res = 0;
    int Y,A,B,C;
    for(int i = 0, j = 0; i < n || j < m;last = cur){
        A = a[j], B = b[j], C = c[j] - Cy[i];
        if(Cx[i] <= Fx[j]) cur = Cx[i], i++;
        else if(Cx[i] > Fx[j]) cur = Fx[j], j++;
        double det = 1.0*B*B - 4.0*A*C, I = 0, x1, x2;
        //int t;
        if(A != 0){
            //t = 1;
            if(det <= 0){
                //t = 11;
                I = integral(A,B,C,last,cur);
            }else{
                //t = 13;
                x1 = (-1.0*B-sqrt(det))/(2.0*A), x2 = (-1.0*B+sqrt(det))/(2.0*A);
                if(x1 > x2) swap(x1,x2);
                x2 = max(x2,last); x2 = min(x2,cur);
                x1 = max(x1,last); x1 = min(x1,cur);
                //cout << "x " << x1 << " " << x2 << " ";
                I = abs(integral(A,B,C,last,cur) - 2*integral(A,B,C,x1,x2));
            }
        }else if(B != 0){
            //t = 2;
            x1 = -1.0*C/B;
            if(x1 > last && x1 < cur) I = abs(integral(A,B,C,last,x1)-integral(A,B,C,x1,cur));
            else I = abs(integral(A,B,C,last,cur));
        }else{
            //t = 3;
            I = abs(C*(cur-last));
        }
        //cout << t << " " << last << " " << cur << " " << det << " " << I << endl;
        res += I;
    }
    printf("%.11f\n",res);
    return 0;
}