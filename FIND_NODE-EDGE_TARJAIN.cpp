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

const int N    = 2e3+3;
const int oo   = 1e16 ;
const int MOD  = 1e9+7;
const int BASE = 31   ;

int n,m,low[N],num[N], cnt;
vector<int> adj[N];
int Edge; // Đếm số cầu
bool Node[N]; // Đánh dấu khớp 

void Tarjain(int u, int p) {
    int child=0;

    low[u] = num[u] = ++cnt;

    for (auto v : adj[u]) {
        if (v!=p) {
            if (num[v]) low[u]=min(low[u], num[v]);
            else {
                Tarjain(v,u);
                low[u]=min(low[u], low[v]);

                if (low[v] >= num[v]) {
                    Edge++; // tim cau
                    cout << v << " " << u << endl;
                }

                child++; // tim khop
                if (u==p) { 
                    if (child>=2) Node[u]=true; 
                }
                else {
                    if (low[v] >= num[u]) Node[u]=true; 
                }
            }     
       } 
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i=1 ; i<=m ; i++) {
        int u,v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    int cntNode=0;
    for (int i=1 ; i<=n ; i++) 
        if (!num[i]) Tarjain(i,i);
    for (int i=1; i <=n ; i++) {
        if (Node[i]) cntNode++;
    }
    cout << cntNode << " " << Edge;

    cerr << "Time elapsed: " << TIME << "s.\n";
    return 0;
}
//-.-. --- -.. . / -... -.-- / -. .. -. ....
