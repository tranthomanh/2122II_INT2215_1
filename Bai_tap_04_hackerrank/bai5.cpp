#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n, a[105], d[105];
int main() {
    cin >> n;
    for(int i=1; i<=n; i++)cin >> a[i], d[a[i]]++;
    for(int i=1; i<=n+1; i++)
    {
        int x; cin >> x; d[x] --;
        if(d[x] < 0)cout << x;
    }
}
