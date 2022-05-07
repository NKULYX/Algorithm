#include <bits/stdc++.h>
#include <sys/time.h>
#include <algorithm>
using namespace std;

typedef struct{
    double x;
    double y;
} node;

int n;
node nodeList[40000];
vector<int> X;
vector<int> Y;

double nearestPair(int, int, vector<int>);
double distance(node, node);

bool cmpX(int i1,int i2)
{
    return (nodeList[i1].x == nodeList[i2].x && nodeList[i1].y < nodeList[i2].y) || (nodeList[i1].x < nodeList[i2].x);
}

bool cmpY(int i1,int i2)
{
    return (nodeList[i1].y == nodeList[i2].y && nodeList[i1].x < nodeList[i2].x) || (nodeList[i1].y < nodeList[i2].y);
}

int main()
{
    cin >> n;
    if(n == 0)
    {
        printf("%.2f", 0.00);
        return 0;
    }
    for(int i = 0; i < n; i++)
    {
        cin >> nodeList[i].x >> nodeList[i].y;
        X.push_back(i);
        Y.push_back(i);
    }
    sort(X.begin(),X.end(),cmpX);
    sort(Y.begin(),Y.end(),cmpY);
    double min = nearestPair(0,n-1,Y);
    printf("%.2lf",min);
    system("pause");
}

double distance(node n1, node n2)
{
    return (n1.x-n2.x)*(n1.x-n2.x) + (n1.y-n2.y)*(n1.y-n2.y);
}

double nearestPair(int begin, int end, vector<int> y)
{
    // 如果集合中点的个数小于等于3，则直接计算最近点对
    if(end - begin <= 10)
    {
        double min =1e9;
        for(int i = begin; i < end; i++)
        {
            for(int j = i+1; j <= end; j++)
            {
                double dis = distance(nodeList[X[i]],nodeList[X[j]]);
                if(dis < min)
                    min = dis;
            }
        }
        return min;
    }
    // 否则，进行分治
    else
    {
        int mid = (begin + end) / 2;
        double min = 1e9;
        vector<int> yL, yR;
        // 划分左右两部分的 y
        for(int i = 0; i < int(y.size()); i++)
            if(nodeList[y[i]].x <= nodeList[X[mid]].x || ( nodeList[y[i]].x == nodeList[X[mid]].x && nodeList[y[i]].y <= nodeList[X[mid]].y))
                yL.push_back(y[i]);
            else
                yR.push_back(y[i]);
        // 左右两部分分治
        double minLeft = nearestPair(begin, mid, yL);
        double minRight = nearestPair(mid+1, end, yR);
        min = minRight < minLeft ? minRight : minLeft;
        // 计算在中间区域的最小值
        vector<int> yMid;
        // 寻找在中间区域的点
        for(int i = 0; i < int(y.size()); i++)
            if(abs(nodeList[y[i]].x-nodeList[X[mid]].x)<min)
                yMid.push_back(y[i]);
        for(int i = 0; i < int(yMid.size()) - 1; i++)
            for(int j = i + 1; j < int(yMid.size()) && j <= 16; j++)
                if(distance(nodeList[yMid[i]],nodeList[yMid[j]])<min)
                    min = distance(nodeList[yMid[i]],nodeList[yMid[j]]);
        return min;
    }
}