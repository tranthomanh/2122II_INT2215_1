#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>>a;
int main() {
    int n, q; cin >> n >> q;
    a.resize(n);
    for(int i=0; i<n; i++)
    {
        int x; cin >> x;
        a[i].resize(x);
        for(int j=0; j<x; j++)cin >> a[i][j];
    }  
    for(int i=1; i<=q; i++)
    {
        int x,y; cin >> x >> y;
        cout << a[x][y]<<'\n';
    }
    return 0;
}