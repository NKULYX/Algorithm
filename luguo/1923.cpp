#include <bits/stdc++.h>
using namespace std;

int n, k, num[5000000];

void k_th(int begin, int end, int t)
{
    int pivot = num[end];
    int i = begin, j = end - 1;
    while (i < j)
    {
        while (num[i] < pivot && i != j)
            i++;
        while (num[j] >= pivot && i != j)
            j--;
        swap(num[i], num[j]);
    }
    swap(num[end], num[i] >= num[end] ? num[i] : num[end]);
    if (i == t)
    {
        cout << num[i] << endl;
        exit(0);
    }
    else if (i < t)
        return k_th(i + 1, end, t);
    else
        return k_th(begin, i - 1, t);
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> num[i];
    // nth_element(num,num+k,num+n);
    // cout<<num[k]<<endl;
    k_th(0, n - 1, k);
}