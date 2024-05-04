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

int n,m,s,t;
vector<int> adj[N];
int d[N],c[N][N],parent[N];
bool Flag;

void init() {
    for (int i=1 ; i<=n; i++) {
        for (int j=1 ; j<=n ; j++){
            if (i==j) c[i][j]=0;
            else c[i][j]=oo;
        }
    }
    for (int i=1 ; i<=n ; i++) d[i]=oo;
    d[s]=0;   
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n >> m >> s >> t;

    init();

    for (int i=1 ; i<=m ; i++) {
        int u,v,w; 
        cin >> u >> v >> w;
        c[u][v]=w;
    }

    for (int cntloop=1; cntloop<n ; cntloop++) {
        Flag=false;
        for (int u=1 ; u<=n ; u++)
            for (int v=1 ; v<=n ; v++)
                if (d[v] > d[u] + c[u][v]) {
                    d[v]=d[u]+c[u][v];
                    parent[v]=u;
                    Flag=true;
                }      
        if (!Flag) break;
    }
 
    if (d[t]==oo) cout << "NO" << endl;
    else {
        cout << d[t] << endl;
        while (s!=t) {
            cout << t << " ";
            t=parent[t];
        }
        cout << s;
    }



    cerr << "Time elapsed: " << TIME << "s.\n";
    return 0;
}
//-.-. --- -.. . / -... -.-- / -. .. -. ....
