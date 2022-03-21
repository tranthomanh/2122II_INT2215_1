#include <bits/stdc++.h>

#define ii pair<int,int>
#define fi first
#define se second
using namespace std;
const int oo = 1e9;
const int dx[] = {1, 1, 1};
const int dy[] = {0,1, -1};
int n, m, Time[1005][1005], a[1005][1005];
bool ok(int i, int j)
{
    if(i < 1 || j < 1 || i> n || j > m || a[i][j])return 0;
    return 1;
}

int main() {
    cin >> n >> m;
    swap(n,m);
    int st, ed;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            char ch; cin >> ch;
            if(ch == 'E')a[i][j] = 0;
            else if(ch == 'R')a[i][j] = 1;
            else st = j;
            Time[i][j] = oo;
        }
    Time[1][1] = a[1][1] == 0 ? 1 : oo;
    Time[1][2] = a[1][2] == 0 ? 1 : oo;
    queue<pair<int,ii>>s;
    if(n == 1 && (!a[1][1] || !a[1][2]))
    {
        cout << "YES";
        return 0;
    }
    for(int i=0; i<=2; i++)
    {
        int ni = st+dy[i];
        if(ok(1,ni))s.push({1,{1,ni}});
    }
    while(s.size())
    {
        pair<int,ii> x = s.front(); s.pop();
        int t = x.fi, i = x.se.fi, j = x.se.se;
        //cerr<<t<<" "<<i<<" "<<j<<'\n';
        if(i == n && t == n)
        {
            cout << "YES";
            return 0;
        }
        for(int k=0; k<=2; k++)
        {
            int ni = i + dx[k], jj = j + dy[k];
            if(!ok(ni,jj))continue;
            if(k > 0)
            {
                if(a[ni-1][jj])continue;
            }
            int nt = t + dx[k];
            if(Time[ni][jj]==oo)
            {
                Time[ni][jj] = nt;
                s.push({nt,{ni,jj}});
                continue;
            }
        }
    }
    cout << "NO";
}