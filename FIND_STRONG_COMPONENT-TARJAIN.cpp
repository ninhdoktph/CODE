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

int n,m,low[N],num[N],cnt,res;
vector<int> adj[N];
stack<int> st;

void Tarjain(int u) {
    low[u] = num[u] = ++cnt;
    st.push(u);
    for (auto v : adj[u]) {
        if (num[v]) low[u]=min(low[u],num[v]);
        else {
            Tarjain(v);
            low[u]=min(low[u],low[v]);
        }
    }

    // Đếm số đỉnh chốt để tìm tplt mạnh
    if (low[u]==num[u]) {
        res++;
        // Loại bỏ đỉnh chốt khỏi đồ thị
        int tmp;
        cout << res << ": " ;
        do {
            tmp=st.top();
            cout << tmp << " ";
            st.pop();
            num[tmp]=low[tmp]=oo;
        } while (tmp!=u);
        cout << endl;
    }

}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n >> m ;
    for (int i=1 ; i<=m ; i++) {
        int u,v; cin >> u >> v;
        adj[u].pb(v);
    }
    
    for (int i=1 ; i<=n ; i++) {
        if (!num[i]) Tarjain(i);
    }
    // cout << res;

    cerr << "Time elapsed: " << TIME << "s.\n";
    return 0;
}
//-.-. --- -.. . / -... -.-- / -. .. -. ....
