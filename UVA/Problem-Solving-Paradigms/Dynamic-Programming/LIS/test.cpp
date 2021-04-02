#include <iostream>
using namespace std;
int arr1[10000],arr2[10000];
int lcs( int *X, int *Y, int m, int n )
{
    int L[m+1][n+1];
    int i, j;
    
        for (i=0; i<=m; i++)
    {
        for (j=0; j<=n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            
            else if (X[i-1] == Y[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }
    
    
    return L[m][n];
}


int main()
{
    int n,i,j,k;
    
    cin>>n;
    //int arr1[n],arr2[n];
    for (i=0; i<n; i++) {
        cin>>arr1[i];
    }
    for (j=0;j<n-1;j++){
        
    for (k=0; k<n; k++) {
        cin>>arr2[k];
    }
        
        cout<<"\n"<<lcs(arr1,arr2,n,n);
        
    } 
    return 0;
}