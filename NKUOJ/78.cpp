#include <bits/stdc++.h>
using namespace std;
int dp[2005][2];
int main()
{
    string str1,str2;
    getline(cin,str1);
    getline(cin,str2);
    int len1=str1.size(),len2=str2.size(),k;
    cin>>k;
    for(int i=0;i<=len1;i++)
        dp[i][0] = k*i;
    for(int i=1;i<=len2;i++){
        for(int j=0;j<=len1;j++)
            if(j==0)
                dp[j][1] = i*k;
            else
                dp[j][1] = min(min(dp[j][0],dp[j-1][1])+k,(dp[j-1][0]+abs(str1[j-1]-str2[i-1])));
        for(int j=0;j<=len1;j++)
            dp[j][0]=dp[j][1];
    }
    cout<<dp[len1][0]<<endl;
}   