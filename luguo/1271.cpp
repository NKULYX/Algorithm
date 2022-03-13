#include <bits/stdc++.h>
using namespace std;
int a[1005],m,n,num;
int main()
{
    cin>>m>>n;
    for(int i=0;i<n;i++){
        cin>>num;
        a[num]++;
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<a[i];j++){
            cout<<i<<" ";
        }
    }
}
