#include<bits/stdc++.h>
using namespace std;
#define FIN ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define N 100005
const long long INF = (1ll<<60);
string s;
int f[11][11];
int main(){FIN;
    cin >> s;
    int n = s.size();
    for(int i = 1; i < n; i++)
        f[s[i]-'1'][s[i-1]-'1']++,f[s[i-1]-'1'][s[i]-'1']++;
    int pos[] = {0,1,2,3,4,5,6,7,8};
    long long mini = INF;
    do{
        long long cur = 0;
        for(int i = 0; i < 9; i++)
            for(int j = i+1; j < 9; j++)
                cur += 1ll*f[i][j]*abs(pos[i]-pos[j]);
        cur += pos[s[0]-'1'];
        mini = min(mini,cur);
        // if(mini == 11){
        //     for(int i = 0; i < 9; i++)
        //         cout << pos[i] << " ";
        //     cout << endl;
        //     break;
        // }
    }while(next_permutation(pos,pos+9));
    cout << mini+n << endl;
    return 0;
}