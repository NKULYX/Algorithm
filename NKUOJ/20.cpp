#include <bits/stdc++.h>
using namespace std;
#define ull long long int 
priority_queue<ull,vector<ull> ,greater<ull>> huffman;
ull n,cnt,sum;
int main()
{
    scanf("%lld",&n);
    for(int i=0;i<n;i++)
    {
        ull tmp;
        scanf("%lld",&tmp);
        cnt+=tmp;
        huffman.push(tmp);
    }

    while(huffman.size() > 1)
    {
        ull a = huffman.top();
        huffman.pop();
        ull b = huffman.top();
        huffman.pop();
        sum+=(a+b);
        huffman.push(a+b);
    }
    printf("%.2f\n",(double)sum/cnt);
    return 0;
}
