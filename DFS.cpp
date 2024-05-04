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

int n,m,s,t,Trace[N];
vector<int> adj[N];

void DFS(int u) {
    for (auto x : adj[u]) {
        if (Trace[x]==0) {
            Trace[x]=u;
            DFS(x);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n >> m >> s >> t;
    for (int i=1 ; i<=m ; i++) {
        int u,v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    fill(Trace,Trace+n+1,0);
    Trace[s]=-1;
    DFS(s);
    if (Trace[t]!=0) {
        while (s!=t) {
            cout << t << " ";
            t=Trace[t];
        }
        cout << s;
    }


    cerr << "Time elapsed: " << TIME << "s.\n";
    return 0;
}
//-.-. --- -.. . / -... -.-- / -. .. -. ....
