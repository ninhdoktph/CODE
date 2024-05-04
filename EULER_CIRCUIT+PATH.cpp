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

int n,m;
stack<int> st;
vector<int> EC;
set<int> adj[N];

void Euler_Circuit (int v) {
    st.push(v);
    while (!st.empty()) {
        int x=st.top();
        if (adj[x].size() != 0) {
            int y=*adj[x].begin();
            st.push(y);
            adj[x].erase(y);
            adj[y].erase(x);
        } else {
            EC.pb(x);
            st.pop();
        }
    }
    reverse(EC.begin(), EC.end());
    for (auto it : EC) cout << it << " ";
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i=1 ; i<=m ; i++) {
        int u,v; cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    Euler_Circuit(1);
    // Sử dụng điều kiện có đường đi để tìm Euler_Path tương tự.

    cerr << "Time elapsed: " << TIME << "s.\n";
    return 0;
}
//-.-. --- -.. . / -... -.-- / -. .. -. ....
