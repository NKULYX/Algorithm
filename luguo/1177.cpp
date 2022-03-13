#include <bits/stdc++.h>
using namespace std;

int a[100001],n;

void quick_sort(int *arr,int begin,int end)
{
    if(begin>=end){
        return ;
    }
    int pivot = rand() % (end-begin+1) + begin;
    swap(arr[end],arr[pivot]);
    int indexL = begin, indexR = end;
    while(indexL<indexR){
        while(arr[indexL]<arr[end]&&indexL!=indexR){
            indexL++;
        }
        while(arr[indexR]>=arr[end]&&indexL!=indexR){
            indexR--;
        }
        swap(arr[indexL],arr[indexR]);
    }
    swap(arr[end],arr[indexL]);
    quick_sort(arr,begin,indexL-1);
    quick_sort(arr,indexR+1,end);
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    quick_sort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}