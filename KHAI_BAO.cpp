#include        <bits/stdc++.h>
#define pb      push_back
#define fi      first
#define se      second
#define int     long long 
#define pii     pair<long long, long long>
#define endl    "\n"
#define TIME    (1.0 * clock() / CLOCKS_PER_SEC)
#define rnd(n)    setprecision(n) << fixed
#define FILE(A) freopen(A".INP", "r", stdin); freopen(A".OUT", "w", stdout);

using namespace std;
const int N    = 1e3+3;
const int oo   = 1e16 ;
const int MOD  = 1e9+7;
const int BASE = 31   ;

// MA TRAN KE

/*int n,m;
int adj[N][N];

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i=1 ; i<=m ; i++) {
        int u,v; cin >> u >> v;
        adj[u][v]=1;
    }

    for (int i=1 ; i<=n ; i++) {
        for (int j=1 ; j<=n ; j++) cout << adj[i][j] << " ";
        cout << endl; 
    }

    cerr << "Time elapsed: " << TIME << "s.\n";
    return 0;
}*/

// DANH SACH CANH
/*int n,m;
vector<pii> adj;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i=1 ; i<=m ; i++) {
        int u,v; cin >> u >> v;
        adj.pb({u,v});
    }
    for (auto x : adj) {
        cout << x.fi  << " " << x.se << endl;
    } 

    cerr << "Time elapsed: " << TIME << "s.\n";
    return 0;
}*/

// DANH SACH KE
int n,m;
vector<int > adj[N];

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i=1 ; i<=m ; i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=1 ; i<=n; i++) {
        for (auto it : adj[i]) cout << it << " ";
        cout << endl; 
    }

    cerr << "Time elapsed: " << TIME << "s.\n";
    return 0;
}
//-.-. --- -.. . / -... -.-- / -. .. -. ....
