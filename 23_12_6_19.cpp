// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// const int N = 2e5 + 10;
// const int B = 60;
// int n;

// struct LBS{
//     int num[B+1];

//     LBS() : num({0}) {};

//     bool insert(int x){
//         for(int i = B - 1;i >= 0;i--){
//             if((x>>i) & 1){
//                 if(!num[i]){
//                     num[i] = x;
//                     return true;
//                 }
//                 x ^= num[i];
//             }
//         }
//         return false;
//     }
//     int getmax(int x){
//         for(int i = B - 1;i >= 0;i--){
//             x = max(x, x ^ num[i]);
//         }
//         return x;
//     }
// };

// void solve(){
//     LBS T;
//     cin >> n;
//     for(int i = 1;i <= n;i++){
//         int e;
//         cin >> e;
//         T.insert(e);
//     }
//     cout << T.getmax(0) << endl;
// }

// signed main(){

//     IO;
//     int t = 1;
//     // cin >> t;
//     while(t--) solve();

//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// const int N = 2e5 + 10;
// const int B = 60;
// int n, m;

// struct LBS{
//     int num[B+1];

//     LBS() : num({0}) {};

//     bool insert(int x){
//         for(int i = B - 1;i >= 0;i--){
//             if((x>>i) & 1){
//                 if(!num[i]){
//                     num[i] = x;
//                     return true;
//                 }
//                 x ^= num[i];
//             }
//         }
//         return false;
//     }
//     int getmax(int x){
//         for(int i = B - 1;i >= 0;i--){
//             x = max(x, x ^ num[i]);
//         }
//         return x;
//     }
// };

// void solve(){
//     LBS T;
//     cin >> n >> m;
//     vector<vector<array<int, 2>>>g(n+10);
//     vector<int>f(n+10);
//     vector<int>vis(n+10);
//     for(int i = 1, s, t, d;i <= m;i++){
//         cin >> s >> t >> d;
//         g[s].push_back({t, d});
//         g[t].push_back({s, d});
//     }

//     auto dfs = [&](auto self, int u) -> void {
//         vis[u] = 1;
//         for(auto [v, d] : g[u]) {
//             if(!vis[v]){
//                 f[v] = f[u] ^ d;
//                 self(self, v);
//             }else{
//                 T.insert(f[u] ^ d ^ f[v]);
//             }
//         }
//     };

//     dfs(dfs, 1);
//     cout << T.getmax(f[n]) << endl;
// }

// signed main(){

//     IO;
//     int t = 1;
//     // cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// const int N = 2e5 + 10;
// int n, m, mid;
// vector<vector<array<int, 3>>>g(N);

// int dfn[N], low[N], idx, scc[N], cnt, st[N], top, deg[N];
// void tarjan(int u){
// 	dfn[u] = low[u] = ++idx;
// 	st[++top] = u;
// 	for(auto [v, w, rv] : g[u]) {
// 		if(rv && (w > mid)) continue;
// 		if(!dfn[v]){
// 			tarjan(v);
// 			low[u] = min(low[u], low[v]);
// 		}else if(!scc[v]){
// 			low[u] = min(low[u], low[v]);
// 		}
// 	}
// 	if(low[u] == dfn[u]){
// 		++cnt;
// 		while(st[top] != u){
// 			scc[st[top--]] = cnt;
// 		}
// 		scc[st[top--]] = cnt;
// 	}
// }

// void init(){
// 	for(int i = 1;i <= n;i++) {
// 		g[i].clear();
// 	}
// }
// void clc(){
// 	for(int i = 1;i <= n;i++){
// 		dfn[i] = low[i] = scc[i] = deg[i] = 0;
// 	}
// 	idx = cnt = top = 0;
// }

// void solve(){
//     cin >> n >> m;
//     init();
//     int l = 0, r = 1;
//     for(int i = 1, u, v, w;i <= m;i++){
//     	cin >> u >> v >> w;
//     	g[u].push_back({v, w, 0});
//     	g[v].push_back({u, w, 1});
//     	r = max(r, w);
// 	}

// 	while(l <= r){
// 		clc();
// 		mid = l + r >> 1;
//         for(int i = 1;i <= n;i++) if(!dfn[i])
// 		    tarjan(i);
		
// 		int on = 0;
// 		for(int i = 1;i <= n;i++){
// 			for(auto [v, w, rv] : g[i]) if(scc[i] != scc[v]){
// 				if(rv && (w > mid)) continue;;
// 				deg[scc[v]]++;
// 			}
// 		}
// 		for(int i = 1;i <= cnt;i++){
// 			if(deg[i] == 0) on++;
// 		}
// 		if(on == 1) r = mid - 1;
// 		else l = mid + 1;
// 	}
	
// 	mid = l;
// 	clc();
//     for(int i = 1;i <= n;i++) if(!dfn[i])
// 	    tarjan(i);
// 	int on = 0;
// 	for(int i = 1;i <= n;i++){
// 		for(auto [v, w, rv] : g[i]) if(scc[i] != scc[v]){
// 			if(rv && (w > mid)) continue;;
// 			deg[scc[v]]++;
// 		}
// 	}
// 	for(int i = 1;i <= cnt;i++){
// 		if(deg[i] == 0) on++;
// 	}
// 	if(on == 1) cout << l << endl;
// 	else cout << "-1\n";
// }   

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// const int N = 2e5 + 10;
// int n, m;


// void solve(){
//     cin >> n;
//     int ans = 1;
//     while(n){
//         int tmp = n % 10;
//         ans *= (tmp + 1) * (tmp + 2) / 2;
//         n /= 10;
//     }
//     cout << ans << endl;
// }   

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// const int N = 2e5 + 10;
// int n, m;


// void solve(){
//     cin >> n;
//     vector<int>a(n+10);
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     if(is_sorted(a.begin() + 1, a.begin() + 1 + n)){
//         cout << "0\n";
//         return;
//     }
//     reverse(a.begin() + 1, a.begin() + 1 + n);
//     if(is_sorted(a.begin() + 1, a.begin() + 1 + n)){
//         cout << "1\n";
//         return;
//     }
//     reverse(a.begin() + 1, a.begin() + 1 + n);

//     int p;
//     int cnt = 0;
//     for(int i = 2;i <= n;i++){
//         if(a[i] < a[i-1]){
//             p = i;
//             cnt++;
//         }
//     }
//     int ans = 1e9 + 7;
//     if(cnt == 1 && a[n] <= a[1]){
//         ans = min({ans, n - p + 1, p + 1});
//     }
    
//     reverse(a.begin() + 1, a.begin() + 1 + n);
//     cnt = 0;
//     for(int i = 2;i <= n;i++){
//         if(a[i] < a[i-1]){
//             p = i;
//             cnt++;
//         }
//     }
//     if(cnt == 1 && a[n] <= a[1]){
//         ans = min({ans, n - p + 2, p});
//     }

//     if(ans == 1e9 + 7){
//         cout << "-1\n";
//     }else{
//         cout << ans << endl;
//     }
// }   

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// // #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// const int N = 2e5 + 10;
// const int B = 19;
// int n, m, a[N];
// vector<int>g[N];

// struct LBS{
//     int num[B + 1];
//     LBS() : num({0}) {};
//     void insert(int x){
//         while(x){
//             int i = __lg(x);
//                 if(num[i]) x ^= num[i];
//                 else{
//                     num[i] = x;
//                     return;
//                 }
//         }
//     }
//     void merg(const LBS& e){
//         for(int i = B;i >= 0;i--) if(e.num[i]){
//             insert(e.num[i]);
//         }
//     }
//     bool query(int x){
//         for(int i = B;i >= 0;i--) if(num[i]){
//             x = min(x, x ^ num[i]);
//         }
//         return x == 0;
//     }
// };

// LBS merg(const LBS& e1, const LBS& e2){
//     LBS ret(e1);
//     for(int i = B;i >= 0;i--) if(e2.num[i]){
//         ret.insert(e2.num[i]);
//     }
//     return ret;
// }

// int top[N], dep[N], son[N], par[N], siz[N], tot, dfn[N];
// void dfs(int u, int f){
//     dep[u] = dep[f] + 1;
//     par[u] = f;
//     siz[u] = 1;
//     for(auto v : g[u]) if(v != f){
//         dfs(v, u);
//         siz[u] += siz[v];
//         if(siz[v] > siz[son[u]]) son[u] = v;
//     }
// }
// int df_data[N], Log[N];
// LBS f[N][B+1];
// void dfs2(int u, int tp){
//     top[u] = tp;
//     dfn[u] = ++tot;
//     df_data[tot] = a[u];
//     f[tot][0].insert(df_data[tot]);
//     if(son[u]) dfs2(son[u], tp);
//     else return;

//     for(auto v : g[u]) if(v != son[u] && v != par[u]){
//         dfs2(v, v);
//     }
// }


// LBS getlbs(int l, int r){
//     int s = Log[r - l + 1];
//     return merg(f[l][s], f[r - (1 << s) + 1][s]);
// }

// bool query(int u, int v, int k){
//     LBS Q;
//     while(top[u] != top[v]){
//         if(dep[top[u]] < dep[top[v]]) swap(u, v);
//         Q.merg(getlbs(dfn[top[u]], dfn[u]));
//         u = par[top[u]];
//     }
//     if(dep[u] < dep[v]) swap(u, v);
//     Q.merg(getlbs(dfn[v], dfn[u]));
//     return Q.query(k);
// }

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//     }
//     for(int i = 1, u, v;i < n;i++){
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }

//     dfs(1, 0);
//     dfs2(1, 1);

//     for(int j = 1;j <= B;j++){
//         for(int i = 1;i <= n && i + (1 << j) - 1 <= n;i++){
//             f[i][j] = merg(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
//         }
//     }

//     int q, x, y, k;
//     cin >> q;
//     while(q--){
//         cin >> x >> y >> k;
//         if(query(x, y, k)) cout << "YES\n";
//         else cout << "NO\n";
//     }
// }   

// signed main(){

//     IO;
//     for(int i = 2;i < N;i++){  //预处理对数
//         Log[i] = Log[i / 2] + 1;
//     }
//     int t = 1;
//     // cin >> t;
//     while(t--) solve();

//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// int n, m, a[N], d[N], del[N], vis[N];

// void init(){
//     for(int i = 0;i <= n+2;i++){
//         del[i] = vis[i] = d[i] = 0;
//     }
// }

// void solve(){
//     init();
//     cin >> n;
//     string s;
//     cin >> s;
//     s = ' ' + s;
//     int cnt = 0;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         d[a[i]]++;
//         cnt += s[i] == '1';
//     }
//     if(cnt & 1){
//         cout << "-1\n";
//         return;
//     }

//     vector<int>ans;
//     queue<int>que;
//     for(int i = 1;i <= n;i++){
//         if(d[i] == 0){
//             que.push(i);
//         }
//     }
//     while(que.size()){
//         int p = que.front();
//         que.pop();
//         if(s[p] == '1'){
//             ans.push_back(p);
//             s[p] = ((s[p] - '0') ^ 1) + '0';
//             s[a[p]] = ((s[a[p]] - '0') ^ 1) + '0';
//         }
//         del[p] = 1;
//         d[a[p]]--;
//         if(d[a[p]] == 0){
//             que.push(a[p]);
//         }
//     }

//     vector<vector<int>>line;
//     vector<vector<int>>cyc;
//     int T = 1;
//     for(int i = 1;i <= n;i++, T++) if(!vis[i] && !del[i]){
//         int cur = i;
//         vector<int>tmp;
//         int cnt = 0;
//         while(1){
//             cnt += s[cur] == '1';
//             tmp.push_back(cur);
//             vis[cur] = T;
//             cur = a[cur];
//             if(del[cur] || (vis[cur] && vis[cur] != T)) break;
//             if(vis[cur] == T){
//                 vector<int>cc(lower_bound(all(tmp), cur), tmp.end());
//                 for(auto e : cc) cnt -= s[e] == '1';
//                 if(cnt & 1) break;
//                 tmp.erase(lower_bound(all(tmp), cur), tmp.end());
//                 cyc.push_back(cc);
//                 break;
//             }
//         }
//         line.push_back(tmp);
//     }

//     for(auto vec : line){
//         int cnt = 0;
//         for(auto e : vec){
//             cnt += s[e] == '1';
//         }
//         if(cnt & 1){
//             cout << "-1\n";
//             return;
//         }
//     }
//     for(auto vec : cyc){
//         int cnt = 0;
//         for(auto e : vec){
//             cnt += s[e] == '1';
//         }
//         if(cnt & 1){
//             cout << "-1\n";
//             return;
//         }
//     }

//     for(auto vec : line) if(vec.size()){
//         int f = 0;
//         for(auto e : vec){
//             f ^= (s[e] - '0');
//             if(f) ans.push_back(e);
//         }
//     }

//     for(auto vec : cyc) if(vec.size()){
//         int f = 0;
//         vector<int>a1;
//         vector<int>a2;
//         for(auto e : vec){
//             f ^= (s[e] - '0');
//             if(f) a1.push_back(e);
//         }
//         int p;
//         for(int i = 0, len = vec.size();i < len;i++){
//             if(s[vec[i]] == '1'){
//                 p = i;
//                 break;
//             }
//             a2.push_back(vec[i]);
//         }
//         f = 0;
//         for(int i = p + 1, len = vec.size();i < len;i++){
//             f ^= (s[vec[i]] - '0');
//             if(f) a2.push_back(vec[i]);
//         }

//         if(a1.size() < a2.size()) {
//             for(auto e : a1) ans.push_back(e);
//         }
//         else {
//             for(auto e : a2) ans.push_back(e);
//         }
//     }
//     cout << ans.size() << endl;
//     for(auto e : ans) cout << e << ' ';
//     cout << endl;
// }   

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// int n, m;
// int op[2] = {-1, 1};

// void solve(){
//     int a[2], x[2], y[2];
//     cin >> a[0] >> a[1] >> x[0] >> y[0] >> x[1] >> y[1];
//     int cnt = 0;

//     map<int, map<int, int>>mp;
//     for(int i = 0;i < 2;i++){
//         for(int j = 0;j < 2;j++){
//             for(int k = 0;k < 2;k++){
//                 int xx = x[0] + op[i] * a[k];
//                 int yy = y[0] + op[j] * a[k^1];
//                 mp[xx][yy];
//             }
//         }
//     }

//     for(auto e : mp){
//         int xx = e.first;
//         for(auto g : e.second){
//             int yy = g.first;
//             int X = abs(x[1] - xx);
//             int Y = abs(yy - y[1]);
//             if((X == a[0] && Y == a[1]) || (X == a[1] && Y == a[0])) cnt++;
//         }
//     }

//     cout << cnt << endl;
// }   

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// int n, m;

// void solve(){
//     cin >> n;
//     vector<int>a(n);
//     for(auto &e : a) cin >> e;
//     vector<int>b(a);
//     vector<int>pre(n);
//     vector<int>idx(n);
//     vector<int>ans(n);
//     iota(all(idx), 0);
//     sort(all(b));
//     sort(all(idx), [&](int i, int j) -> int {return a[i] < a[j];});
//     pre[0] = b[0];
//     for(int i = 1;i < n;i++) pre[i] = pre[i-1] + b[i];
//     int r = 0;
//     for(int i = 0;i < n;i++){
//         r = max(r, i);
//         int sum = pre[r];
//         while(r + 1 < n && sum >= b[r+1]){
//             r++;
//             sum += b[r];
//         }
//         ans[idx[i]] = r;
//     }
//     for(auto e : ans) cout << e << ' ';
//     cout << endl;
// }   

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// int n, k;

// void solve(){
//     cin >> n >> k;
//     vector<int>a(n);
//     for(auto& e : a) cin >> e;
//     vector<int>b(a);
//     sort(all(b));

//     int ans = b[0];
//     if(k >= 3){
//         cout << "0\n";
//         return;
//     }else if(k == 2){
//         for(int i = 0;i < n;i++){
//             for(int j = i + 1;j < n;j++){
//                 int d = abs(b[i] - b[j]);
//                 ans = min(ans, d);
//                 int p = lower_bound(all(b), d) - b.begin();
//                 for(int k = p - 1;k <= p + 1;k++) if(k >= 0 && k < n){
//                     ans = min(ans, abs(b[k] - d));
//                 }
//             }
//         }
//     }else{
//         for(int i = 1;i < n;i++){
//             ans = min(ans, b[i] - b[i-1]);
//         }
//     }
//     cout << ans << endl;
// }   

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define ls id << 1
// #define rs id << 1 | 1
// const int N = 2e5 + 10;
// int n, a[N], b[N];

// struct node{
//     node(int mx = 0, int mn = 0) : mx(mx), mn(mn) {};
//     int mx, mn;
// }tr[N<<2];
// void up(int id){
//     tr[id].mx = max(tr[ls].mx, tr[rs].mx);
//     tr[id].mn = min(tr[ls].mn, tr[rs].mn);
// }
// void build(int id, int l, int r){
//     if(l == r){
//         tr[id] = {a[l], b[l]};
//         return;
//     }
//     int mid = l + r >> 1;
//     build(ls, l, mid);
//     build(rs, mid + 1, r);
//     up(id);
// }
// int getmx(int id, int l, int r, int ql, int qr){
//     if(ql <= l && r <= qr) return tr[id].mx;
//     int mid = l + r >> 1;
//     if(qr <= mid) return getmx(ls, l, mid, ql, qr);
//     else if(ql > mid) return getmx(rs, mid + 1, r, ql, qr);
//     else return max(getmx(ls, l, mid, ql, qr), getmx(rs, mid + 1, r, ql, qr));
// }
// int getmn(int id, int l, int r, int ql, int qr){
//     if(ql <= l && r <= qr) return tr[id].mn;
//     int mid = l + r >> 1;
//     if(qr <= mid) return getmn(ls, l, mid, ql, qr);
//     else if(ql > mid) return getmn(rs, mid + 1, r, ql, qr);
//     else return min(getmn(ls, l, mid, ql, qr), getmn(rs, mid + 1, r, ql, qr));
// }


// void solve(){
//     cin >> n;
//     vector<int>l(n + 10);
//     vector<int>r(n + 10);
//     vector<int>pos(n + 10);
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     for(int i = 1;i <= n;i++) cin >> b[i];
//     build(1, 1, n);
//     for(auto& e : pos) e = -1;
//     for(int i = 1;i <= n;i++){
//         pos[a[i]] = i;
//         l[i] = pos[b[i]];
//     }
//     for(auto& e : pos) e = -1;
//     for(int i = n;i >= 1;i--){
//         pos[a[i]] = i;
//         r[i] = pos[b[i]];
//     }

//     for(int i = 1;i <= n;i++){
//         if(a[i] == b[i]) continue;
//         if(a[i] > b[i]){
//             cout << "NO\n";
//             return;
//         }
//         if(l[i] != -1){
//             if(getmx(1, 1, n, l[i], i) == b[i] && getmn(1, 1, n, l[i], i) == b[i]) continue;
//         }
//         if(r[i] != -1){
//             if(getmx(1, 1, n, i, r[i]) == b[i] && getmn(1, 1, n, i, r[i]) == b[i]) continue;
//         }
//         cout << "NO\n";
//         return;
//     }
//     cout << "YES\n";
// }   

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// int n, mx[N][20], mn[N][20], Log[N], a[N], b[N];

// int gtemx(int l, int r){
//     int s = Log[r - l + 1];
//     return max(mx[l][s], mx[r - (1 << s) + 1][s]);
// }
// int gtemn(int l, int r){
//     int s = Log[r - l + 1];
//     return min(mn[l][s], mn[r - (1 << s) + 1][s]);
// }

// void solve(){
//     cin >> n;
//     vector<int>l(n + 10);
//     vector<int>r(n + 10);
//     vector<int>pos(n+10);
//     for(int i = 1;i <= n;i++) cin >> a[i]; 
//     for(int i = 1;i <= n;i++) cin >> b[i]; 
//     for(auto& e : pos) e = -1;
//     for(int i = 1;i <= n;i++){
//         pos[a[i]] = i;
//         l[i] = pos[b[i]];
//     }
//     for(auto& e : pos) e = -1;
//     for(int i = n;i >= 1;i--){
//         pos[a[i]] = i;
//         r[i] = pos[b[i]];
//     }

//     for(int i = 1;i <= n;i++) mx[i][0] = a[i], mn[i][0] = b[i];
//     for(int j = 1;j < 20 ;j++){
//         for(int i = 1;i <= n && i + (1 << j) - 1 <= n;i++){
//             mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
//             mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
//         }
//     }

//     for(int i = 1;i <= n;i++){
//         if(a[i] == b[i]) continue;
//         if(a[i] > b[i]){
//             cout << "NO\n";
//             return;
//         }
//         if(l[i] != -1){
//             if(gtemx(l[i], i) == b[i] && gtemn(l[i], i) == b[i]) continue;
//         }
//         if(r[i] != -1){
//             if(gtemx(i, r[i]) == b[i] && gtemn(i, r[i]) == b[i]) continue;
//         }
//         cout << "NO\n";
//         return;
//     }
//     cout << "YES\n";
// }   

// signed main(){

//     IO;
//     for(int i = 2;i < N;i++){  //预处理对数
//         Log[i] = Log[i / 2] + 1;
//     }
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// int n, a[N], d[N], vis[N];

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         d[a[i]]++;
//     }
//     queue<int>que;
//     for(int i = 1;i <= n;i++){
//         if(d[i] == 0){
//             que.push(i);
//             vis[i] = 1;
//         }
//     }

//     vector<int>ans;
//     while(que.size()){
//         int u = que.front();
//         que.pop();
//         ans.push_back(u);

//         if(vis[a[u]]) continue;
//         vis[a[u]] = 1; //被删除的点
        
//         int ne = a[a[u]];
//         d[ne]--;
//         if(!vis[ne] && d[ne] == 0){
//             que.push(ne);
//             vis[ne] = 1;
//         }
//     }

//     for(int i = 1;i <= n;i++) if(!vis[i]){
//         vector<int>tmp;
//         int cur = i;
//         do{
//             tmp.push_back(cur);
//             vis[cur] = 1;
//             cur = a[cur];
//         }while(cur != i);
//         if(tmp.size() & 1){
//             cout << "-1\n";
//             return;
//         }
//         for(int j = 0;j < tmp.size();j += 2) ans.push_back(tmp[j]);
//     }

//     cout << ans.size() << endl;
//     sort(all(ans));
//     for(auto e : ans) cout << a[e] << ' ';
//     cout << endl;
// }   

// signed main(){

//     IO;
//     int t = 1;
//     // cin >> t;
//     while(t--) solve();

//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// int n;

// void solve(){
//     cin >> n;
//     string s;
//     cin >> s;
//     int cnt = 0, ze = 0;
//     for(int i = 0, j = n - 1;i < n;i++, j--){
//         if(s[i] != s[j]){
//             cnt++;
//         }else{
//             ze += s[i] == '0';
//         }
//     }
//     cnt /= 2;
//     // ze = (ze + 1) / 2;
//     if(cnt){

//         if(n & 1){
//             if(cnt == 1 && s[n/2] == '0' && ze == 1) cout << "DRAW\n";
//             else cout << "ALICE\n";
//         }else{
//             cout << "ALICE\n";
//         }

//         return;
//     }
//     ze = 0;
//     for(auto e : s) ze += e == '0';
//     if(ze & 1 && ze > 1) cout << "ALICE\n";
//     else cout << "BOB\n";
// }   

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 3e5 + 10;
// int n, a[N], f[N], son[N], leaf;
// vector<int>g[N];

// void dfs(int u){
//     if(g[u].size() == 0){
//         leaf++;
//         son[u] = 1;
//         return;
//     }

//     int mn = N, sum = 0;
//     for(auto v : g[u]){
//         dfs(v);
//         sum += son[v];
//         mn = min(mn, son[v]);
//     }

//     if(a[u]) son[u] = mn;
//     else son[u] = sum;
// }

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     for(int i = 2;i <= n;i++){
//         cin >> f[i];
//         g[f[i]].push_back(i);
//     }

//     dfs(1);

//     cout << leaf - son[1] + 1 << endl;
// }   

// signed main(){

//     IO;
//     int t = 1;
//     // cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 3e5 + 10;
// int n, u[N], s[N];


// void solve(){
//     cin >> n;
//     vector<vector<int>>vec(n + 5);
//     vector<int>ans(n+5);
//     for(int i = 1;i <= n;i++) cin >> u[i];
//     for(int i = 1;i <= n;i++) cin >> s[i], ans[1] += s[i];
//     for(int i = 1;i <= n;i++){
//         vec[u[i]].push_back(s[i]);
//     }
//     for(int i = 1;i <= n;i++) if(vec[i].size()){
//         sort(all(vec[i]));
//         for(int j = 1;j < vec[i].size();j++){
//             vec[i][j] += vec[i][j-1];
//         }
//     }
//     for(int i = 1;i <= n;i++) if(vec[i].size()){
//         // for(auto e : vec[i]) cerr << e << ' ';
//         // cerr << endl;
//         for(int j = 1, sz = vec[i].size();j <= sz;j++){
//             int s = sz % j;
//             if(!s) continue;
//             int d = vec[i][s-1];
//             ans[j] -= d;
//             ans[j+1] += d;
//         }
//         ans[vec[i].size() + 1] -= vec[i].back();
//     }

//     for(int i = 1;i <= n;i++){
//         ans[i] += ans[i-1];
//         cout << ans[i] << ' ';
//     }
//     cout << endl;

// }   

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 3e5 + 10;
// const int L = 0;
// const int R = 1;
// int n, x[N], dir[N], m;

// void solve(){
//     cin >> n >> m;
//     for(int i = 1;i <= n;i++) cin >> x[i];
//     for(int i = 1;i <= n;i++){
//         char c;
//         cin >> c;
//         if(c == 'R') dir[i] = R;
//         else dir[i] = L;
//     }
//     vector<int>a[2];
//     vector<int>vis(n+5);
//     for(int i = 1;i <= n;i++){
//         a[x[i] & 1].push_back(i);
//     }
//     sort(all(a[0]), [&](int i, int j) -> int {return x[i] < x[j];});
//     sort(all(a[1]), [&](int i, int j) -> int {return x[i] < x[j];});

//     vector<int>ans(n+5);

//     for(int o = 0;o < 2;o++){
//         auto& vec = a[o];

//         //相向而行
//         for(int i = 1, sz = vec.size();i < sz;i++) if(!vis[vec[i]] && !vis[vec[i-1]] && dir[vec[i]] == L && dir[vec[i-1]] == R){
//             vis[vec[i]] = vis[vec[i-1]] = 1;
//             ans[vec[i]] = ans[vec[i-1]] = (x[vec[i]] - x[vec[i-1]]) / 2;
//             int q = i-2, p = i+1;
//             // cerr << x[vec[q]] << ' ' << x[vec[p]] << endl;
//             // cerr << x[vec[i-1]] << ' ' << x[vec[i]] << endl;
//             while(q >= 0 && p < vec.size() && !vis[vec[q]] && !vis[vec[p]] && dir[vec[q]] == R && dir[vec[p]] == L){
//                 vis[vec[q]] = vis[vec[p]] = 1;
//                 ans[vec[q]] = ans[vec[p]] = (x[vec[p]] - x[vec[q]]) / 2;
//                 q--;
//                 p++;
//             }
//             i++;
//         }
//         //L
//         int q = 0, p = 1;
//         while(p < vec.size()){
//             while(q < vec.size() && (vis[vec[q]])) q++;
//             if(q >= vec.size()) break;
//             p = q + 1;
//             while(p < vec.size() && (vis[vec[p]])) p++;
//             if(p >= vec.size() || dir[vec[p]] == R) break;
//             vis[vec[q]] = vis[vec[p]] = 1;
//             ans[vec[q]] = ans[vec[p]] = x[vec[q]] + (x[vec[p]] - x[vec[q]]) / 2;
//         }
//         q = vec.size()-1, p = vec.size()-1;
//         //R
//         while(p < vec.size()){
//             while(q >= 0 && (vis[vec[q]])) q--;
//             if(q < 0) break;
//             p = q - 1;
//             while(p >= 0 && (vis[vec[p]])) p--;
//             if(p < 0 || dir[vec[p]] == L) break;
//             vis[vec[q]] = vis[vec[p]] = 1;
//             ans[vec[q]] = ans[vec[p]] = (m - x[vec[q]]) + (x[vec[q]] - x[vec[p]]) / 2;
//         }
//         //反向
//         q = 0, p = vec.size() - 1;
//         while(q < vec.size() && (vis[vec[q]] || dir[vec[q]] == R)) q++;
//         while(p >= 0 && (vis[vec[p]] || dir[vec[p]] == L)) p--;
//         if(q < p){
//             // cerr << x[vec[q]] << ' ' << x[vec[p]] << endl;
//             vis[vec[q]] = vis[vec[p]] = 1;
//             ans[vec[q]] = ans[vec[p]] = (2*m - (x[vec[p]] - x[vec[q]]))/2;
//         }
//     }

//     for(int i = 1;i <= n;i++){
//         if(ans[i]) cout << ans[i] << ' ';
//         else cout << "-1 ";
//     }
//     cout << endl;
// }   

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 3e5 + 10;
// const int L = 0;
// const int R = 1;
// int n, x[N], dir[N], m, idx[N];

// struct node{
//     node(int x = 0, int d = 0, int id = 0) : x(x), d(d), id(id) {};
//     int x, d, id;
// };

// void solve(){
//     cin >> n >> m;
//     vector<int>ans(n+5);
//     for(int i = 1;i <= n;i++) cin >> x[i];
//     for(int i = 1;i <= n;i++){
//         idx[i] = i;
//         char c;
//         cin >> c;
//         if(c == 'R') dir[i] = R;
//         else dir[i] = L;
//     }

//     sort(idx + 1, idx + 1 + n, [&](int i, int j) -> int {return x[i] < x[j];});
//     stack<node>stt[2];
//     for(int ii = 1;ii <= n;ii++){
//         int i = idx[ii];
//         // cerr << x[i] << ' ' << dir[i] << endl;
//         auto& st = stt[x[i] & 1];
//         if(dir[i] == R){
//             st.push({x[i], 0, i});
//         }else{
//             if(st.size()){
//                 auto left = st.top();
//                 st.pop();
//                 int d = (x[i] - left.d - left.x) / 2 + left.d;
//                 ans[left.id] = ans[i] = d;
//             }else{
//                 st.push({0, x[i], i});
//             }
//         }
//     }for(int i = 0;i < 2;i++){
//         auto& st = stt[i];
//         while(st.size() >= 2){
//             auto r = st.top();
//             st.pop();
//             auto l = st.top();
//             st.pop();
//             int mx = max(l.d, r.d);
//             int d = (m - (r.x + (mx - r.d))) + ((r.x + (mx - r.d)) - (l.x + (mx - l.d))) / 2 + mx;
//             ans[l.id] = ans[r.id] = d;
//         }
//     }

//     for(int i = 1;i <= n;i++){
//         cout << (ans[i] ? ans[i] : -1) << ' ';
//     }
//     cout << endl;
// }   

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// // #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 1e6 + 10;
// const int Q = 1e5 + 10;
// const int M = Q * 60;
// int n, m, q, n2;

// int rt[Q], sum[M], ls[M], rs[M], tot;

// void build(int &id, int l, int r){
//     id = ++tot;
//     if(l == r) return;
//     int mid = l + r >> 1;
//     build(ls[id], l, mid);
//     build(rs[id], mid + 1, r);
// }
// void add(int &id, int pre, int l, int r, int x, int v){
//     id = ++tot;
//     sum[id] = sum[pre] + v;
//     ls[id] = ls[pre];
//     rs[id] = rs[pre];
//     if(l == r) return;
//     int mid = l + r >> 1;
//     if(x <= mid) add(ls[id], ls[pre], l, mid, x, v);
//     else add(rs[id], rs[pre], mid + 1, r, x, v);
// }
// int get(int id, int l, int r, int x){
//     if(l == r) return sum[id];
//     int mid = l + r >> 1;
//     if(x <= mid) return get(ls[id], l, mid, x);
//     else return get(rs[id], mid + 1, r, x);
// }

// int prt[Q], tot2, L[M], R[M], rv[M], st[M];
// void build2(int &id, int l, int r){
//     id = ++tot2;
//     if(l == r) return;
//     int mid = l + r >> 1;
//     build2(L[id], l, mid);
//     build2(R[id], mid + 1, r);
// }
// void push(int &id, int pre, int l, int r, int x){
//     id = ++tot2;
//     L[id] = L[pre];
//     R[id] = R[pre];
//     st[id] = st[pre];
//     rv[id] = rv[pre];
//     if(l == r){
//         st[id] ^= 1;
//         return;
//     }
//     int mid = l + r >> 1;
//     if(x <= mid) push(L[id], L[pre], l, mid, x);
//     else push(R[id], R[pre], mid + 1, r, x);
// }
// int query(int id, int l, int r, int x){
//     if(l == r){
//         return st[id] ^ rv[id];
//     }
//     int mid = l + r >> 1;
//     if(x <= mid) return query(L[id], l, mid, x) ^ rv[id];
//     else return query(R[id], mid + 1, r, x) ^ rv[id];
// }
// void rev(int &id, int pre, int l, int r, int ql, int qr){
//     id = ++tot2;
//     L[id] = L[pre];
//     R[id] = R[pre];
//     st[id] = st[pre];
//     rv[id] = rv[pre];
//     if(ql <= l && r <= qr){
//         rv[id] ^= 1;
//         return;
//     }
//     int mid = l + r >> 1;
//     if(qr <= mid) rev(L[id], L[pre], l, mid, ql, qr);
//     else if(ql > mid) rev(R[id], R[pre], mid + 1, r, ql, qr);
//     else rev(L[id], L[pre], l, mid, ql, qr), rev(R[id], R[pre], mid + 1, r, ql, qr);
// }

// void solve(){
//     cin >> n >> m >> q;
//     n2 = n * m;
//     build(rt[0], 1, n);
//     build2(prt[0], 1, n2);
//     int op, x, y, k;
//     for(int i = 1;i <= q;i++){
//         cin >> op;
//         if(op == 1){
//             cin >> x >> y;
//             k = (x - 1) * m + y;
//             int d = query(prt[i-1], 1, n2, k);
//             if(!d){
//                 add(rt[i], rt[i-1], 1, n, x, 1);
//                 push(prt[i], prt[i-1], 1, n2, k);
//             }else{
//                 rt[i] = rt[i-1];
//                 prt[i] = prt[i-1];
//             }
//         }else if(op == 2){
//             cin >> x >> y;
//             k = (x - 1) * m + y;
//             int d = query(prt[i-1], 1, n2, k);
//             if(d == 1){
//                 add(rt[i], rt[i-1], 1, n, x, -1);
//                 push(prt[i], prt[i-1], 1, n2, k);
//             }else{
//                 rt[i] = rt[i-1];
//                 prt[i] = prt[i-1];
//             }
//         }else if(op == 3){
//             cin >> x;
//             int d = get(rt[i-1], 1, n, x);
//             add(rt[i], rt[i-1], 1, n, x, (m-d)-d);
//             rev(prt[i], prt[i-1], 1, n2, (x-1)*m+1, x*m);
//         }else{
//             cin >> k;
//             rt[i] = rt[k];
//             prt[i] = prt[k];
//         }
//         cout << sum[rt[i]] << '\n';
//     }
// }   

// signed main(){

//     IO;
//     int t = 1;
//     // cin >> t;
//     while(t--) solve();
//     // n = 2;
//     // n2 = n * n;
//     // build(rt[0], 1, n);
//     // build2(prt[0], 1, n2);

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define ls id << 1
// #define rs id << 1 | 1
// const int N = 1e5 + 10;
// int n, m, x, a[N];

// struct val{
//     vector<array<int, 2>>pre, suf;
//     int ans;
//     val(int v = 0) : pre(1, {v, 1}), suf(1, {v, 1}), ans(v >= x ? 1 : 0) {}

//     val operator+(const val &e) const {
//         val ret(*this);
//         ret.ans += e.ans;
//         int l = 0, r = e.pre.size() - 1;
//         int sum = e.pre.back()[1];
//         while(l < suf.size()){
//             while(r > 0 && (e.pre[r-1][0] | suf[l][0]) >= x) {
//                 r--;
//                 sum += e.pre[r][1];
//             }
//             if((e.pre[r][0] | suf[l][0]) >= x) ret.ans += suf[l][1] * sum;
//             l++;
//         }
//         vector<array<int, 2>>tmp(e.suf);
//         for(auto [v, len] : suf){
//             if((v | tmp.back()[0]) == tmp.back()[0]) tmp.back()[1] += len;
//             else tmp.push_back({(v | tmp.back()[0]), len});
//         }
//         ret.suf = tmp;
//         for(auto [v, len] : e.pre){
//             if((v | ret.pre.back()[0]) == ret.pre.back()[0]) ret.pre.back()[1] += len;
//             else ret.pre.push_back({(v | ret.pre.back()[0]), len});
//         }
//         return ret;
//     }
// }tr[N << 2];

// void up(int id){
//     tr[id] = tr[ls] + tr[rs];
// }
// void build(int id, int l, int r){
//     if(l == r){
//         tr[id] = val(a[l]);
//         return;
//     }
//     int mid = l + r >> 1;
//     build(ls, l, mid);
//     build(rs, mid + 1, r);
//     up(id);
// }
// void change(int id, int l, int r, int x, int v){
//     if(l == r){
//         tr[id] = val(v);
//         return;
//     }
//     int mid = l + r >> 1;
//     if(x <= mid) change(ls, l, mid, x, v);
//     else change(rs, mid + 1, r, x, v);
//     up(id);
// }
// val query(int id, int l, int r, int ql, int qr){
//     if(ql <= l && r <= qr) return tr[id];
//     int mid = l + r >> 1;
//     if(qr <= mid) return query(ls, l, mid, ql, qr);
//     else if(ql > mid) return query(rs, mid + 1, r, ql, qr);
//     else return query(ls, l, mid, ql, qr) + query(rs, mid + 1, r, ql, qr);
// }

// void solve(){
//     cin >> n >> m >> x;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     build(1, 1, n);

//     int op, x, y;
//     while(m--){
//         cin >> op >> x >> y;
//         if(op == 1){
//             change(1, 1, n, x, y);
//         }else{
//             cout << query(1, 1, n, x, y).ans << endl;
//         }
//     }
// }   

// signed main(){

//     IO;
//     int t = 1;
//     // cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// int n, a[N];

// int lowbit(int x){
//     return x & -x;
// }
// int nebit(int x){
//     int ret = x * 2;
//     while(x){
//         ret = x * 2;
//         x -= lowbit(x);
//     }
//     return ret;
// }

// void solve(){
//     cin >> n;
//     int av = 0;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         av += a[i];
//     }
//     if(av % n){
//         cout << "No\n";
//         return;
//     }
//     av /= n;
//     map<int,int>mp;
//     for(int i = 1;i <= n;i++) if(a[i] < av){
//         int d = av - a[i];
//         if(d & 1){
//             if(a[i] == 0){
//                 if(d == 1) mp[1]--;
//                 else{
//                     cout << "No\n";
//                     return;
//                 }
//             }else{
//                 mp[1]++;
//                 d++;
//                 if(d != lowbit(d)){
//                     cout << "No\n";
//                     return;
//                 }
//                 mp[d]--;
//             }
//         }else{
//             if(d == lowbit(d)){
//                 mp[d]--;
//             }else{
//                 int d2 = nebit(d) - d;
//                 if(d2 != lowbit(d2)){
//                     cout << "No\n";
//                     return;
//                 }
//                 mp[d2]++;
//                 mp[d2+d]--;
//             }   
//         }
//     }
//     //     for(auto [k, v] : mp) {
//     //         cerr << k << ' ' << v << endl;
//     //     // if(v){
//     //     //     cout << "No\n";
//     //     //     return;
//     //     // }
//     // }
//     // cerr << endl;
//     for(int i = 1;i <= n;i++) if(a[i] > av){
//         int d = a[i] - av;
//         if(d & 1){
//             if(d == 1){
//                 if(mp[1] < 0) mp[1]++;
//                 else{
//                     mp[1]--;
//                     mp[2]++;
//                 }
//             }else{
//                 if(d+1 != lowbit(d+1)){
//                     cout << "No\n";
//                     return;
//                 }
//                 mp[1]--;
//                 mp[d+1]++;
//             }
//         }else{
//             if(d == lowbit(d)){
//                 mp[d]++;
//             }else{
//                 int d2 = nebit(d) - d;
//                 mp[d2]--;
//                 mp[d2+d]++;
//             }   
//         }
//     }

//     // cerr << av << endl;
//     for(auto &[k, v] : mp) {
//             // cerr << k << ' ' << v << endl;
//         if(v){
//             while(v >= 2 && mp[k<<1] < 0){
//                 v -= 2;
//                 mp[k<<1]++;
//             }
//             while(v <= -2 && mp[k<<1] > 0){
//                 v += 2;
//                 mp[k<<1]--;
//             }
//             if(v){
//                 cout << "No\n";
//                 return;
//             }
//         }
//     }
//     cout << "Yes\n";
// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// int n, m;

// void solve(){
//     cin >> n >> m;
//     cout << (n - 9) * 60 + m << endl;
// }

// signed main(){

//     IO;
//     int t = 1;
//     // cin >> t;
//     while(t--) solve();

//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// int n, m;

// void solve(){
//     map<string, double>mp;
//     map<double, string>mp2;
//     cin >> n;
//     string tmp;
//     double pt, pu, rt, ru, f;
//     for(int i = 1;i <= 6;i++){
//         cin >> tmp >> pt >> pu >> rt >> ru >> f;
//         mp[tmp] = 0.56*ru + 0.24*rt + 0.14*pu + 0.06*pt + 0.3*f;
//         mp2[mp[tmp]] = tmp;
//     }
//     int cnt = 6;
//     for(auto [v, s] : mp2){
//         if(s == "Taiwan") break;
//         cnt--;
//     }
//     cout << n / 6 + ((n % 6) >= cnt);
// }

// signed main(){

//     IO;
//     int t = 1;
//     // cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// int n, m;

// void solve(){
//     string s;
//     cin >> s;
//     int ans = 0;
//     for(int i = 0, len = s.size();i < len - 1;i++){
//         int d = ((s[i]-'0')*10 + (s[i+1]-'0')) / 6;
//         if(d >= 10){
//             s[i] = '1';
//             d -= 10;
//             s[i+1] = d + '0';
//             i--;
//         }else{
//             s[i+1] = d + '0';
//         }
//         ans++;
//     }
//     int d = s.back()-'0';
//     while(d){
//         ans++;
//         d /= 6;
//     }
//     cout << max(1ll, ans) << endl;
// }

// signed main(){

//     IO;
//     int t = 1;
//     // cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 210;
// const int M = 1010;
// int n, m, a[N], b[N], f[N][M];

// void solve(){
//     cin >> n >> m;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     for(int i = 1;i <= n;i++) cin >> b[i];

//     for(int j = 0;j <= m;j++){
//         int d = m - j;
//         int mx = (b[1] ? (a[1] + b[1] - 1) / b[1] : d);
//         d = min(d, mx);
//         f[n+1][j] = f[1][j] = d * (a[1] + a[1] - (d-1)*b[1]) / 2;
//     }
//     int ans = f[1][0];
    
//     for(int i = 2;i <= n;i++){
//         for(int j = 0;j <= m;j++){
//             f[i][j] = 0;
//             if(m - j < i - 1){
//                 f[i][j] = -1e15;
//                 continue;
//             }
//             for(int k = j + 1;k <= m;k++){
//                 if(f[i-1][k] == -1e15) continue;
//                 int d = k - 1 - j;
//                 int mx = (b[i] ? (a[i] + b[i] - 1) / b[i] : d);
//                 d = min(d, mx);
//                 f[i][j] = max(f[i][j], d * (a[i] + a[i] - (d-1)*b[i]) / 2 + f[i-1][k]);
//             }
//             ans = max(ans, f[i][j]);
//         }
//     }
//     for(int i = n;i >= 2;i--){
//         for(int j = 0;j <= m;j++){
//             f[i][j] = 0;
//             if(m - j < n - i + 1){
//                 f[i][j] = -1e15;
//                 continue;
//             }
//             for(int k = j + 1;k <= m;k++){
//                 if(f[i+1][k] == -1e15) continue;
//                 int d = k - 1 - j;
//                 int mx = (b[i] ? (a[i] + b[i] - 1) / b[i] : d);
//                 d = min(d, mx);
//                 f[i][j] = max(f[i][j], d * (a[i] + a[i] - (d-1)*b[i]) / 2 + f[i+1][k]);
//             }
//             ans = max(ans, f[i][j]);
//         }
//     }

//     cout << ans << endl;
// }

// signed main(){

//     IO;
//     int t = 1;
//     // cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// int n, m;

// void solve(){
//     cin >> n >> m;
//     cout << max(n, m) << endl;
// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// int n, m;

// void solve(){
//     cin >> n;
//     vector<vector<int>>g(n+5);
//     for(int i = 1, u, v;i < n;i++){
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }
//     int ans = 0; 
//     for(int i = 1;i <= n;i++) {
//         ans += g[i].size() == 1;
//     }

//     cout << (ans + 1) / 2 << endl;
// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// int n, m, mx[N];
// string s;

// int cmp(int i, int j){
//     return s[i] < s[j];
// }

// void solve(){
//     cin >> n;
//     cin >> s;
//     if(is_sorted(s.begin(), s.end())){
//         cout << "0\n";
//         return;
//     }

//     for(int i = 0;i < n;i++) mx[i] = i;
//     for(int i = n-2;i >= 0;i--){
//         mx[i] = max(mx[i], mx[i+1], cmp);
//     }

//     vector<int>ans;
//     ans.push_back(mx[0]);
//     while(ans.back() < n - 1){
//         ans.push_back(mx[ans.back()+1]);
//     }

//     int d = 0;
//     for(auto e : ans) d += s[e] == s[ans[0]];
        
//     vector<int>idx(ans);
//     string ss(s);
//     sort(idx.begin(), idx.end(), cmp);
//     for(int i = 0, len = ans.size();i < len;i++){
//         s[ans[i]] = ss[idx[i]];
//     }
//     if(is_sorted(s.begin(), s.end())){
//         cout << ans.size()-d << endl;
//     }else{
//         cout << "-1\n";
//     }
// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// // #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 1e6 + 10;
// int n, m, f[N*2][22], Log[N], p[N], a[N * 2], pos;

// int cmp(int i, int j){
//     return a[i] < a[j];
// }
// int query(int l, int r){
//     int s = Log[r - l + 1];
//     return min(f[l][s], f[r - (1 << s) + 1][s], cmp);
// }

// int check(int x){
//     int cur = n, ed = 2*n - x, ret = n;
//     while(cur < ed){
//         int ne = query(cur + 1, ed);
//         ret += (ne - cur) * a[ne];
//         cur = ne;
//     }
//     return ret;
// }

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++){
//         cin >> p[i];
//         if(p[i] == 0) pos = i;
//         f[i][0] = i;
//     }
//     int tmp = n;
//     for(int i = 1;i <= n;i++){
//         a[tmp--] = p[pos--];
//         if(pos < 1) pos = n;
//     }
//     for(int i = n + 1;i <= n * 2;i++){
//         a[i] = a[i-n];
//         f[i][0] = i;
//     }
//     for(int j = 1;j < 22;j++){
//         for(int i = 1;i <= n*2 && i + (1 << j) - 1 <= n*2;i++){
//             f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1], cmp);
//         }
//     }

//     int l = 2, r = n-1;
//     while(l < r){
//         int mid = l + r >> 1;
//         int e1 = check(mid - 1), e2 = check(mid), e3 = check(mid + 1);
//         if(e2 > e1 && e2 > e3){
//             l = mid;
//             break;
//         }else if(e3 > e2){
//             l = mid + 1;
//         }else if(e1 > e2){
//             r = mid - 1;
//         }
//     }
//     l = min(n, l);
//     int ans = max(check(1), check(l));
//     cout << ans << endl;
//     // cerr << l << endl;
//     // for(int i = 1;i <= n;i++){
//     //     cerr << i << ' ' << check(i) << endl;
//     // }
//     // cerr << check()
//     cerr << check(10);
// }

// signed main(){

//     IO;

//     for(int i = 2;i < N;i++){  //预处理对数
//         Log[i] = Log[i / 2] + 1;
//     }

//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 1e6 + 10;
// int n, m, f[N*2][22], Log[N], p[N], a[N * 2], pos;

// int cmp(int i, int j){
//     return a[i] < a[j];
// }
// int query(int l, int r){
//     int s = Log[r - l + 1];
//     return min(f[l][s], f[r - (1 << s) + 1][s], cmp);
// }

// int check(int x){
//     int cur = n, ed = 2*n - x, ret = n;
//     while(cur < ed){
//         int ne = query(cur + 1, ed);
//         ret += (ne - cur) * a[ne];
//         cur = ne;
//     }
//     return ret;
// }

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++){
//         cin >> p[i];
//         if(p[i] == 0) pos = i;
//         f[i][0] = i;
//     }
//     int tmp = n;
//     for(int i = 1;i <= n;i++){
//         a[tmp--] = p[pos--];
//         if(pos < 1) pos = n;
//     }
//     for(int i = n + 1;i <= n * 2;i++){
//         a[i] = a[i-n];
//         f[i][0] = i;
//     }
//     for(int j = 1;j < 22;j++){
//         for(int i = 1;i <= n*2 && i + (1 << j) - 1 <= n*2;i++){
//             f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1], cmp);
//         }
//     }

//     int ed;
//     for(int i = 2*n - 1;i >= n;i--){
//         if(a[i] == n-1){
//             ed = i;
//             break;
//         }
//     }
//     // cerr << ed << endl;

//     int l = 2, r = 2*n - ed;
//     while(l < r){
//         int mid = l + r >> 1;
//         int e1 = check(mid), e2 = check(mid + 1);
//         if(e2 > e1){
//             l = mid + 1;
//         }else{
//             r = mid;
//         }
//     }
//     l = min(l, n);
//     int ans = max({check(1), check(r), check(l), check(2), check(2*n - ed)});
//     cout << ans << endl;

//     // for(int i = 1;i <= n;i++) cerr << check(i) << ' ';
//     // cerr << endl;
// }

// signed main(){

//     IO;

//     for(int i = 2;i < N;i++){  //预处理对数
//         Log[i] = Log[i / 2] + 1;
//     }

//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 1e6 + 10;
// int n, m, a[N];

// void solve(){
//     cin >> n;
//     int p;
//     for(int i = 0;i < n;i++){
//         cin >> a[i];
//         if(a[i] == 0) p = i;
//     }

//     int ans = 0, cur = 0;
//     stack<array<int, 2>>st;
//     for(int i = 1;i <= n;i++){
//         int cnt = 0;
//         while(st.size() && st.top()[0] > a[p]){
//             cur -= st.top()[0] * st.top()[1];
//             cnt += st.top()[1];
//             st.pop();
//         }
//         if(cnt){
//             st.push({a[p], cnt});
//             cur += a[p] * cnt;
//         }
//         st.push({n, 1});
//         cur += n;
//         ans = max(ans, cur);
//         p = (p + 1) % n;
//     }
//     cout << ans << endl;
// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int unsigned long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 1e6 + 10;
// const int mod = 998244353;
// int n, m, ans, RET;
// unordered_map<int, int>v;
// unordered_map<int, list<int>>ls;

// int qpow(int a, int x){
//     int ret = 1;
//     while(x){
//         if(x & 1) ret = ret * a % mod;
//         a = a * a % mod;
//         x >>= 1;
//     }
//     return ret;
// }

// void dfs2(int id, int l, int r){
//     int d = r - l + 1;
//     if(v[d]){
//         RET = (RET + v[d]) % mod;
//         id--;
//         for(auto e : ls[d]){
//             RET = (RET + (e * id % mod)) % mod;
//             id = (id << 1) % mod;
//         }
//         return;
//     }
//     int mid = l + r >> 1;
//     dfs2((id << 1) % mod, l, mid);
//     dfs2((id << 1 | 1) % mod, mid + 1, r);

//     //更新ans
//     RET = (RET + (id * ls[d].front() % mod)) % mod;
// }

// void dfs(int id, int l, int r){
//     int d = r - l + 1;
//     if(v[d]){
//         ans = (ans + v[d]) % mod;
//         id--;
//         for(auto e : ls[d]){
//             ans = (ans + (e * id % mod)) % mod;
//             id = (id << 1) % mod;
//         }
//         return;
//     }
//     int mid = l + r >> 1;
//     dfs((id << 1) % mod, l, mid);
//     dfs((id << 1 | 1) % mod, mid + 1, r);

//     int ld = mid - l + 1, rd = r - mid;
    
//     //更新ls    
//     list<int>lst(ls[ld]);
//     auto it = lst.begin();
//     auto Rs = ls[rd].begin();
//     int cnt = ls[rd].size();
//     while(cnt--){
//         *it = (*it + *Rs) % mod;
//         Rs++;
//         it++;
//     }
//     lst.push_front( (qpow(2, ld) - 1) * (qpow(2, rd) - 1) % mod);
//     ls[d] = lst;

//     //更新ans
//     ans = (ans + (id * ls[d].front() % mod) ) % mod;

//     //更新v
//     RET = 0;
//     dfs2(1, 1, d);
//     v[d] = RET;
// }

// void init(){
//     RET = ans = 0;
// }

// void solve(){
//     cin >> n;
//     init();
//     dfs(1, 1, n);

//     cout << ans << endl;
// }

// signed main(){

//     IO;

//     v[1] = 1;
//     ls[1] = list<int>({1});

//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int unsigned long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 1e6 + 10;
// const int mod = 998244353;
// int n, m, a[N];

// void solve(){
//     cin >> n;
//     int cnt = 0;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         cnt += (a[i] == 1);
//     }
//     cout << n - (cnt / 2) << endl;

// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int unsigned long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 1e6 + 10;
// const int mod = 998244353;
// int n, m, a[N];

// void solve(){
//     int a1, a2, a3, a4;
//     cin >> a1 >> a2 >> a3 >> a4;
//     if(a1){
//         int ans = a1;
//         int d = min(a2, a3);
//         ans += d * 2;
//         a2 -= d;
//         a3 -= d;

//         a4 += a2 + a3;
//         ans += min(a4, a1 + 1);
//         cout << ans << endl;
//     }else{
//         cout << "1\n";
//     }
// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 1e6 + 10;
// const int mod = 998244353;
// int n, m, a[N], p[N];

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++) cin >> a[i], p[a[i]] = i;
//     if(is_sorted(a + 1, a + 1 + n)){
//         cout << "0\n";
//         return;
//     }
//     int l = n / 2, r = (n + 1) / 2 + 1;
//     if(n & 1){
//         if(p[l + 1] < p[l] || p[r - 1] > p[r]){
//             cout << n / 2 << endl;
//             return;
//         }
//     }
//     if(p[l] > p[r]){
//         cout << n / 2 << endl;
//         return;
//     }
//     while(l > 1 && (p[l-1] < p[l] && p[r] < p[r+1] && p[l] < p[r])){
//         l--;
//         r++;
//     }
//     int ans = l;
//     if(p[l] < p[r]) ans--;
//     cout << ans << endl;

// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 5e4 + 10;
// int n, m, a[N][12], b[N][12];

// int tr[N * 12][12], tot, v[N * 12];
// void insert(const int *s){
//     int p = 0;
//     for(int i = 1;i <= m;i++){
//         if(!tr[p][s[i]]) tr[p][s[i]] = ++tot;
//         p = tr[p][s[i]];
//         v[p]++;
//     }
// }
// void remove(const int *s){
//     int p = 0;
//     for(int i = 1;i <= m;i++){
//         p = tr[p][s[i]];
//         v[p]--;
//     }
// }
// int find(const int* s){
//     int p = 0, ret = 0;
//     for(int i = 1;i <= m;i++){
//         p = tr[p][s[i]];
//         if(v[p]) ret++;
//         else return ret;
//     }
//     return ret;
// }

// void solve(){
//     cin >> n >> m;
//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++) cin >> a[i][j], b[i][a[i][j]] = j;
//         insert(b[i]);
//     }
//     for(int i = 1;i <= n;i++){
//         cout << find(a[i]) << ' ';
//     }
//     cout << endl;
//     for(int i = 1;i <= n;i++) remove(b[i]);
// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 1e6 + 10;
// int n, m, a[N];

// void solve(){
//     string s, a, b;
//     cin >> s;
//     n = s.size();
//     int f = 0;
//     a.push_back(s[0]);
//     for(int i = 1;i < n;i++){
//         if(s[i] != '0' && !f){
//             f = 1;
//         }
//         if(!f) a.push_back(s[i]);
//         else b.push_back(s[i]);
//     }
//     int A = atoi(a.c_str());
//     int B = 0;
//     if(b.size()) B = atoi(b.c_str());
//     if(A < B){
//         cout << A << " " << B << endl;
//     }else{
//         cout << "-1\n";
//     }
// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 1e6 + 10;
// int n, m, a[N];

// void solve(){
//     string s;
//     cin >> s;
//     int c[2] =  {0};
//     for(auto e : s) c[e-'0']++;
//     int len = 0;
//     for(auto e : s){
//         if(c[(e-'0') ^ 1])c[(e-'0') ^ 1]--;
//         else break;
//         len++;
//     }
//     cout << s.size() - len << endl;

// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 1e6 + 10;
// int n, m, pw[40];

// void solve(){

//     map<int,int>c;
//     int t, v;
//     cin >> m;
//     while(m--){
//         cin >> t >> v;
//         if(t == 1){
//             c[v]++;
//         }else{  
//             auto it = c.rbegin();
//             while(it != c.rend()){
//                 int x = it->first, cnt = it->second;
//                 int d = v / pw[x];
//                 v -= min(d, cnt) * pw[x];
//                 it++;
//             }
//             if(v) cout << "NO\n";
//             else cout << "YES\n";
//         }
//     }

// }

// signed main(){

//     IO;
//     int t = 1;
//     pw[0] = 1;
//     for(int i = 1;i <= 30;i++){
//         pw[i] = pw[i-1] * 2;
//     }
//     // cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 3e5 + 10;
// const int mod = 998244353;
// int n, m, a[N], f[N], ls[N], bg[N];

// void init(){
//     for(int i = 0;i <= n + 5;i++){
//         f[i] = ls[i] = bg[i] = 0;
//     }
//     f[2] = 2;
//     f[1] = 1;
//     bg[1] = 1;
//     if(a[2] < a[1]) ls[2] = 2, bg[2] = 2;
//     else ls[2] = 1, bg[2] = 0;
//     ls[1] = 1;
// }

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     if(n == 1){
//         cout << "1\n";
//         return;
//     }  
//     init();

//     stack<array<int, 3>>st;
//     st.push({a[1], ls[1], bg[1]});
//     int sum = ls[1];
//     if(a[2] < st.top()[0]){
//         sum -= st.top()[1];
//         st.pop();
//     }
//     st.push({a[2], ls[2], bg[2]});
//     sum += ls[2];

//     int mn = min(a[1], a[2]);
//     for(int i = 3;i <= n;i++){
//         // if(a[i] < mn){
//         //     mn = a[i];
//         //     int d;
//         //     while(st.size()){
//         //         d = st.top()[1];
//         //         st.pop();
//         //     }
//         //     ls[i] = f[i] = (f[i-1] + d) % mod;
//         //     st.push({a[i], ls[i]});
//         //     sum = ls[i];
//         // }else{
//             int d = 0;
//             while(st.size() && a[i] < st.top()[0]) {
//                 d = (d + st.top()[2]) % mod;
//                 sum -= st.top()[1];
//                 if(sum < 0) sum += mod;
//                 st.pop();
//             }
//             ls[i] = (f[i-1] + d) % mod;
//             f[i] = (f[i-1] + sum + d) % mod;
//             bg[i] = f[i] - sum * 2;
//             while(bg[i] < 0)  bg[i] += mod;
//             st.push({a[i], ls[i], bg[i]});
//             sum = (ls[i] + sum) % mod;
//         // }
//     }

//     cout << f[n] << endl;

//     // for(int i = 1;i <= n;i++) cerr << f[i] << ' ' << ls[i] << ' ' << bg[i] << endl;

// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 1e6 + 10;
// int n, m, k, a[N], fa[N];
// set<int>g[N];

// struct node{
//     int l, r;
//     node(int l, int r) : l(l), r(r) {}
// };
// vector<node>seg;

// void insert(int f, int s){
//     if(a[f] == a[s]) return;
//     if(!fa[s]){
//         g[f].insert(s);
//         fa[s] = f;
//     }else{
//         if(a[f] > a[s]){
//             if(a[fa[s]] < a[s] || a[fa[s]] > a[f]){
//                 g[fa[s]].erase(g[fa[s]].find(s));
//                 g[f].insert(s);
//                 fa[s] = f;
//             }
//         }else{
//             if(a[fa[s]] < a[s] && a[fa[s]] > a[f]){
//                 g[fa[s]].erase(g[fa[s]].find(s));
//                 g[f].insert(s);
//                 fa[s] = f;
//             }
//         }
//     }
// }

// int root;
// void dfs(int u, int val){
//     if(g[u].empty()){
//         seg.push_back({root, val});
//         return;
//     }
//     for(auto v : g[u]){
//         if(a[v] > a[u]) dfs(v, val - a[u] + a[v]);
//         else dfs(v, val + k - a[u] + a[v]);
//     }
// }

// void init(){
//     seg.clear();
//     for(int i = 0;i <= n + 10;i++){
//         fa[i] = 0;
//         g[i].clear();
//     }
// }

// void solve(){
//     cin >> n >> m >> k;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     for(int i = 1, u, v;i <= m;i++){
//         cin >> u >> v;
//         insert(u, v);
//     }

//     for(int i = 1;i <= n;i++) if(!fa[i]){
//         root = a[i];
//         dfs(i, a[i]);        
//     }

//     int mr = 0;
//     for(auto [l, r] : seg){
//         mr = max(mr, r);
//     }
//     sort(all(seg), [&](const node& e1, const node& e2) -> int {
//         if(e1.l == e2.l) return e1.r < e2.r;
//         return e1.l < e2.l;
//     });

//     int ans = mr;
//     for(auto [l, r] : seg){
//         ans = min(ans, mr - l);
//         mr = max(mr, r + k);
//     }
//     cout << ans << endl;
//     init();

// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();
    
//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 1e6 + 10;
// int n, m, k, deg[N];
// array<int, 2>a[N];
// vector<int>g[N];


// void init(){
//     for(int i = 1;i <= n;i++){
//         deg[i] = 0;
//         g[i].clear();
//     }
// } 

// void solve(){
//     cin >> n >> m >> k;
//     for(int i = 1;i <= n;i++) cin >> a[i][0], a[i][1] = i;
//     while(m--){
//         int u, v;
//         cin >> u >> v;
//         deg[v]++;
//         g[u].push_back(v);
//     }
//     vector<int>q;
//     for(int i = 1;i <= n;i++){
//         if(deg[i] == 0) q.push_back(i);
//     }
//     for(int i = 0;i < n;i++){
//         int u = q[i];
//         for(auto v : g[u]){
//             if(--deg[v] == 0) q.push_back(v);
//         }
//     }
//     vector<int>dp(n+5);
//     for(int i = n - 1;i >= 0;i--){
//         int u = q[i];
//         for(auto v : g[u]){
//             dp[u] = max(dp[u], dp[v] + ((a[v][0] - a[u][0] + k) % k));
//         }
//     }
//     for(int i = 1;i <= n;i++) dp[i] += a[i][0];
//     int mr = *max_element(all(dp));
//     sort(a + 1, a + 1 + n);
//     int ans = mr;
//     for(int i = 1;i <= n;i++){
//         ans = min(ans, mr - a[i][0]);
//         mr = max(mr, dp[a[i][1]] + k);
//     }

//     cout << ans << endl;
//     init();

// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();
    
//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 1e5 + 10;
// const int inf = 1e17;
// int n, m, cl, ce, V, q;


// void solve(){
//     cin >> n >> m >> cl >> ce >> V;
//     vector<int>sta(cl), ele(ce);
//     for(auto &e : sta) cin >> e;
//     for(auto &e : ele) cin >> e;
//     cin >> q;
//     while(q--){
//         int x, y, u, v;
//         cin >> x >> y >> u >> v;
//         if(u == x){
//             cout << abs(y - v) << endl;
//         } else{
//             auto ps = upper_bound(all(sta), y);
//             auto pe = upper_bound(all(ele), y);
//             int cs = inf, ce = inf;
//             if(sta.size()){
//                 int p1;
//                 if(ps != sta.begin()){
//                     p1 = *prev(ps);
//                     // cerr << p1 << ' ';
//                     cs = abs(y - p1) + abs(x - u) + abs(v - p1);
//                 }
//                 if(ps != sta.end()){
//                     p1 = *ps;
//                     // cerr << p1 << ' ';
//                     cs = min(cs, abs(y - p1) + abs(x - u) + abs(v - p1));
//                 }
//             }
//             if(ele.size()){
//                 int p1;
//                 if(pe != ele.begin()){
//                     p1 = *prev(pe);
//                     // cerr << p1 << ' ';
//                     ce = abs(y - p1) + (abs(x - u)+V-1)/V + abs(v - p1);
//                 }
//                 if(pe != ele.end()){
//                     p1 = *pe;
//                     // cerr << p1 << '\n';
//                     ce = min(ce, abs(y - p1) + (abs(x - u)+V-1)/V + abs(v - p1));
//                 }
//             }
//             cout << min(cs, ce) << endl;
//         }
//     }
// }

// signed main(){

//     IO;
//     int t = 1;
//     // cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 3e5 + 10;
// const int inf = 1e17;
// int n, k, tot;
// vector<int>op[N];
// vector<int>vec[N];

// list<unordered_map<int, int>>res;

// void solve(){
//     string s;
//     cin >> n >> k >> s;
//     s = ' ' + s;
//     map< vector<int>, int>hmp;
//     for(int i = 1, sz;i <= k;i++){
//         cin >> sz;
//         vector<int>tmp(sz);
//         for(auto &e : tmp) cin >> e;
//         if(hmp[tmp]++ == 0) vec[++tot] = tmp;
//     }

//     for(int i = 1;i <= tot;i++){
//         for(auto e : vec[i]) op[e].push_back(i);
//     }

//     int ans = inf;
//     if(s[1] == '1'){
//         if(op[1].size() == 2){
//             res.push_back(unordered_map<int,int>());
//             (*res.begin())[op[1][0]] = 1;
//             (*res.begin())[op[1][1]] = 1;
//         }
//         res.push_back(unordered_map<int,int>());
//         ans = 0;
//     }else{
//         res.push_back(unordered_map<int,int>());
//         (*res.begin())[op[1][0]] = 1;
//         if(op[1].size() == 2){
//             res.push_back(unordered_map<int,int>());
//             (*res.rbegin())[op[1][1]] = 1;
//         }
//         ans = 1;
//     }

//     cout << ans << endl;
//     for(int i = 2;i <= n;i++){
//         ans = inf;
//         if(s[i] == '1'){
//             if(op[i].size() == 2){
//                 auto it = res.begin();
//                 while(it != res.end()){
//                     if(it->count(op[i][0])){
//                         if(vec[op[i][1]][0] == i) (*it)[op[i][1]] = 1;
//                         else if(!(it->count(op[i][1]))){
//                             it++;
//                             res.erase(prev(it));
//                             continue;
//                         }
//                     }else if(it->count(op[i][1])){
//                         if(vec[op[i][0]][0] == i) (*it)[op[i][0]] = 1;
//                         else{
//                             it++;
//                             res.erase(prev(it));
//                             continue;
//                         }
//                     }
//                     it++;
//                 }
//             }else if(op[i].size() == 1){
//                 auto it = res.begin();
//                 while(it != res.end()){
//                     if(it->count(op[i][0])){
//                         it++;
//                         res.erase(prev(it));
//                         continue;
//                     };
//                     it++;
//                 }
//             }
//             for(auto &mp : res) ans = min(ans, (int)mp.size());
//         }else{
//             if(op[i].size() == 2){
//                 auto it = res.begin();
//                 while(it != res.end()){
//                     int cnt = 0;
//                     if((*it).count(op[i][0])) cnt++;
//                     if((*it).count(op[i][1])) cnt++;
//                     if(cnt == 0){
//                         if(vec[op[i][0]][0] == i){
//                             res.push_back(*it);
//                             (*res.rbegin())[op[i][0]] = 1;
//                         }
//                         if(vec[op[i][1]][0] == i){
//                             res.push_back(*it);
//                             (*res.rbegin())[op[i][1]] = 1;
//                         }
//                         it++;
//                         res.erase(prev(it));
//                         continue;
//                     }else if(cnt == 2){
//                         it++;
//                         res.erase(prev(it));
//                         continue;
//                     };
//                     it++;
//                 }
//             }else if(op[i].size() == 1){
//                 auto it = res.begin();
//                 while(it != res.end()){
//                     if((*it).count(op[i][0])) {}
//                     else{
//                         if(vec[op[i][0]][0] == i){
//                             res.push_back(*it);
//                             (*res.rbegin())[op[i][0]] = 1;
//                         }
//                         it++;
//                         res.erase(prev(it));
//                         continue;
//                     }
//                     it++;
//                 }
//             }
//             for(auto &mp : res) ans = min(ans, (int)mp.size());
//         }
//         cout << ans << endl;
//     }
// }

// signed main(){

//     IO;
//     int t = 1;
//     // cin >> t;
//     while(t--) solve();

//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 5e4 + 10;
// const int inf = 1e17;
// int n, k, fa[N * 3];

// int find(int x){
//     return fa[x] == x ? x : fa[x] = find(fa[x]);
// }
// void merg(int a, int b){
//     a = find(a);
//     b = find(b);
//     fa[a] = b;
// }

// void solve(){
//     cin >> n >> k;
//     for(int i = 1;i <= n*3;i++) fa[i] = i;
//     int ans = 0;
//     while(k--){
//         int op, a, b;
//         cin >> op >> a >> b;
//         if(a > n || b > n){
//             ans++;
//             continue;
//         }
//         if(op == 1){
//             if(find(a) == find(b + n) || find(a) == find(b + n*2)) {
//                 ans++;
//                 continue;
//             }
//             merg(a, b), merg(a + n, b + n), merg(a + n*2, b + n*2);
//         }else{
//             if(find(a) == find(b) || find(a + 2*n) == find(b)){
//                 ans++;
//                 continue;
//             }
//             merg(a+n, b), merg(a, b+2*n), merg(b+n, a+2*n);
//         }
//     }
//     cout << ans << endl;
// }

// signed main(){

//     IO;
//     int t = 1;
//     // cin >> t;
//     while(t--) solve();

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 5e4 + 10;
// const int inf = 1e17;
// int n, k;


// void solve(){
//     cin >> n;
//     string s;
//     cin >> s;
//     int cnt[30] = {0};
//     for(auto e : s) cnt[e - 'A' + 1] ++;
//     int ans = 0;
//     for(int i = 'A';i <= 'Z';i++) if(cnt[i-'A'+1] >= i-'A'+1) ans++;
//     cout << ans << endl;
// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 5e4 + 10;
// const int inf = 1e17;
// int n, k;


// void solve(){
//     cin >> n >> k;
//     if(k){
//         cout << 1 << ' ';
//         for(int i = n - k + 1;i <= n;i++) cout << i << ' ';
//         for(int i = n - k;i > 1;i--) cout << i << ' ';
//         cout << endl;
//     }else{
//         for(int i = n;i >= 1;i--) cout << i << ' ';
//         cout << endl;
//     }
// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// const int inf = 1e17;
// int n, k, a[N], b[N], pre[N], mx[N];


// void solve(){
//     cin >> n >> k;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i], pre[i] = a[i] += pre[i-1];
//         mx[i] = max(a[i], mx[i-1]);
//     }
//     for(int i = 1;i <= n;i++){
//         cin >> b[i];
//         mx[i] = max(b[i], mx[i-1]);
//     }
//     int ans = 0;
//     for(int i = 1;i <= min(n, k);i++){
//         ans = max(ans, pre[i] + mx[i] * (k - i));
//     }
//     cout << ans << endl;
// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// const int inf = 1e17;
// int n, k, a[N], b[N], c[N];


// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     for(int i = 1;i <= n;i++) cin >> b[i];
//     for(int i = 1;i <= n;i++) cin >> c[i];
//     vector<int>ida(n), idb(n), idc(n);
//     iota(all(ida), 1);
//     iota(all(idb), 1);
//     iota(all(idc), 1);
//     sort(all(ida), [&](int i, int j) -> int {return a[i] > a[j];});
//     sort(all(idb), [&](int i, int j) -> int {return b[i] > b[j];});
//     sort(all(idc), [&](int i, int j) -> int {return c[i] > c[j];});

//     // for(auto e : ida) cerr << a[e] << ' ';
//     // cerr << endl;
//     // for(auto e : idb) cerr << b[e] << ' ';
//     // cerr << endl;
//     // for(auto e : idc) cerr << c[e] << ' ';
//     // cerr << endl;

//     int ans = 0;
//     for(int i = 0;i < 3;i++){
//         for(int j = 0;j < 3;j++){
//             if(ida[i] == idb[j]) continue;
//             for(int k = 0;k < 3;k++){
//                 if(ida[i] == idc[k] || idb[j] == idc[k]) continue;
//                 ans = max(ans, a[ida[i]] + b[idb[j]] + c[idc[k]]);
//             }
//         }
//     }
//     cout << ans << endl;
// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// const int inf = 1e17;
// int n, k;


// void solve(){
//     cin >> n;
//     vector<int>a(n), b(n), idx(n);
//     for(auto &e : a) cin >> e;
//     for(auto &e : b) cin >> e;
//     iota(all(idx), 0);
//     sort(all(idx), [&](int i, int j) -> int {return a[i] + b[i] > a[j] + b[j];});
//     int ans = 0;
//     for(int i = 0;i < n;i++){
//         if(i & 1){ //Bob
//             ans -= b[idx[i]] - 1;
//         }else{ //Alice
//             ans += a[idx[i]] - 1;
//         }
//     }
//     cout << ans << endl;

//     // for(auto e : idx) cerr << e << ' ';
//     // cerr << endl;
// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// const int inf = 1e17;
// int n, k, p[N], f[N], son[N];
// vector<int>g[N];

// void dfs(int u){
//     son[u] = 1;
//     if(g[u].empty()) return;
//     vector<array<int, 2>>vec;
//     int sum = 0;
//     for(auto v : g[u]){
//         dfs(v);
//         sum += f[v];
//         vec.push_back({son[v], f[v]});
//     }
//     sort(all(vec));
//     int liv = vec.size() - 1;
//     for(int i = vec.size() - 2;i >= 0;i--){
//         int d = min(vec[i][0], vec[liv][0]);
//         f[u] += d;
//         vec[i][0] -= d;
//         vec[liv][0] -= d;
//         if(vec[liv][0] == 0) liv = i;
//     }
//     sum -= vec[liv][1];
//     if(sum && vec[liv][0]){
//         int s = vec[liv][0];
//         int d = min(s ^ (s&1), sum * 2);
//         f[u] += d;
//         vec[liv][0] -= d;
//         sum -= d / 2;
//     }
//     sum += vec[liv][1];
//     f[u] += sum;
//     son[u] += vec[liv][0];
// }

// void init(){
//     for(int i = 1;i <= n;i++) {
//         g[i].clear();
//         son[i] = f[i] = 0;
//     }
// }

// void solve(){
//     cin >> n;
//     init();
//     for(int i = 2;i <= n;i++){
//         cin >> p[i];
//         g[p[i]].push_back(i);
//     }
//     dfs(1);
//     cout << f[1] << endl;

//     // for(int i = 1;i <= n;i++){
//     //     cerr << f[i] << ' ' << son[i] << endl;
//     // }
// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// const int inf = 1e17;
// int n, k;

// void solve(){
//     cin >> n;
//     vector<vector<int>>g(n+1);
//     vector<int>siz(n+1);
//     for(int i = 2, p;i <= n;i++){
//         cin >> p;
//         g[p].push_back(i);
//     }

//     auto dfs1 = [&](auto self, int u) -> void {
//         siz[u] = 1;
//         for(auto v : g[u]){
//             self(self, v);
//             siz[u] += siz[v];
//         }
//     };
//     dfs1(dfs1, 1);

//     auto dfs = [&](auto self, int u) -> int {
//         int mx = 0;
//         for(auto v : g[u]) mx = max(mx, siz[v]);
//         if(mx * 2 > siz[u] - 1) {
//             for(auto v : g[u]) if(siz[v] == mx){
//                 int d = self(self, v);
//                 return d + min(siz[u] - 1 - mx, (siz[u] - 1 - d * 2) / 2);
//             }
//         }else {
//             return (siz[u] - 1) / 2;
//         }
//     };

//     cout << dfs(dfs, 1) << endl;
// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 2000 + 10;
// const int inf = 1e17;
// int n, x, r, p, k;
// string s;

// void solve(){
//     cin >> n >> x >> r >> p >> k >> s;
//     int ans = n * x;
//     vector<int>vec;
//     for(int i = 0;i < n;i++){
//         vec.push_back((n - i) * p);
//         if(s[i] == '1'){
//             ans -= (n - i) * r;
//             vec.back() += (n - i) * r;
//         }
//     }
//     sort(all(vec));
//     for(int i = n - 1;i >= max(0ll, n - k);i--){
//         ans += vec[i];
//     }
//     cout << ans << endl;
// }

// signed main(){

//     IO;
//     int t = 1;
//     // cin >> t;
//     while(t--) solve();

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 2000 + 10;
// const int inf = 1e17;
// int n, m, k;

// void solve(){
//     cin >> n >> m >> k;
//     if((2 * k - 1) >= m) cout << "Yuto\n";
//     else if((n * m) & 1) cout << "Yuto\n";
//     else cout << "Platina\n";
// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 610;
// const int inf = 1e17;
// int n, m, k, l[N], r[N], d[N], f[N][N], x[N];

// void solve(){
//     cin >> n;
//     int top = 0;
//     vector<int>idx;
//     for(int i = 1;i <= n;i++){
//         cin >> l[i] >> r[i] >> d[i];
//         x[++top] = l[i], x[++top] = r[i];
//         idx.push_back(l[i]);
//         idx.push_back(r[i]);
//     }
//     sort(all(idx));
//     idx.erase(unique(all(idx)), idx.end());
//     sort(x + 1, x + 1 + top);
//     int M = unique(x + 1, x + 1 + top) - x - 1;
//     for(int i = 1;i <= n;i++){
//         l[i] = lower_bound(x + 1, x + 1 + M, l[i]) - x;
//         r[i] = lower_bound(x + 1, x + 1 + M, r[i]) - x;
//     }
//     for(int len = 1;len <= M;len++){
//         for(int st = 1;st + len - 1 <= M;st++){
//             int mx = 0;
//             int L = st, R = st + len - 1;
//             f[L][R] = inf;
//             for(int i = 1;i <= n;i++){
//                 if(L <= l[i] && r[i] <= R){
//                     if(mx == 0 || d[i] > d[mx]) mx = i;
//                 }
//             }
//             if(mx == 0){
//                 f[L][R] = 0;
//             }else{
//                 for(int i = l[mx];i <= r[mx];i++){
//                     if(i-1 >= L && i+1 <= R)
//                     f[L][R] = min(f[L][R], d[mx] + f[L][i-1] + f[i+1][R]);
//                 }
//             }
//         }
//     }

//     cout << f[1][M] << endl;
// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// const int inf = 1e17;
// int n, m;

// void solve(){
//     cin >> n;
//     map<int,int>mp;
//     for(int i = 1;i <= n;i++){
//         int x, y;
//         cin >> x >> y;
//         if(x > 0) mp[1]++;
//         else if(x < 0) mp[2]++;
//         if(y > 0) mp[3]++;
//         else if(y < 0) mp[4]++;
//     }
//     if(mp.size() <= 3) cout << "YES\n";
//     else cout << "NO\n";
// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// const int inf = 1e17;
// int n, m;

// void solve(){
//     cin >> n;
//     vector<int>a(n);
//     set<int>st;
//     for(auto& e : a){
//         cin >> e;
//         st.insert(e & 1);
//     }
//     if(n == 2){
//         cout << (int)(1e18) << endl;
//         return;
//     }
//     if(st.size() == 2){
//         cout << "2\n";
//         return;
//     }

//     for(int pw = 2; 1; pw <<= 1){
//         set<int>st;
//         for(auto e : a){
//             st.insert(e % pw);
//             if(st.size() > 2) break;
//         }
//         if(st.size() == 2){
//             cout << pw << endl;
//             return;
//         }
//     }    
// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// const int inf = 1e17;
// int n, m;

// void solve(){
//     cin >> n;
//     vector<array<int, 2>>a(n * 2);
//     for(int i = 0;i < n;i++){
//         cin >> a[i][0];
//         a[i][1] = 0;
//     }
//     for(int i = n;i < n * 2;i++){
//         cin >> a[i][0];
//         a[i][1] = 1;
//     }
//     vector<int>c(n);
//     for(int i = 0;i < n;i++) cin >> c[i];
//     sort(all(a));
//     stack<int>st;

//     vector<int>seg;
//     for(auto [p, op] : a){
//         if(op){
//             seg.push_back(p - st.top());
//             st.pop();
//         }else{
//             st.push(p);
//         }
//     }

//     sort(all(seg));
//     sort(all(c));
//     int ans = 0;
//     for(int i = 0;i < n;i++){
//         ans += seg[i] * c[n-1-i];
//     }
//     cout << ans << endl;
// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// const int inf = 1e17;
// int n, m, k;

// int lowbit(int x){
//     if(x == 0) return 0; 
//     return x & -x;
// }

// void solve(){
//     cin >> n >> k;
//     vector<int>a(n);
//     set<int>st;
//     for(auto &e : a){
//         cin >> e;
//         if(e > k) st.insert(1);
//         else if(e == k) st.insert(0);
//         else st.insert(-1);
//     }
//     if(st.size() > 1){
//         cout << "-1\n";
//         return;
//     }

//     st.clear();
//     for(auto e : a) st.insert(e);
//     if(st.size() == 1){
//         cout << "0\n";
//         return;
//     }

//     vector<int>d(n);
//     for(auto e : a) d.push_back(abs(e - k));
//     int gc = d.front();
//     for(auto e : d) gc = __gcd(gc, e);
//     int ans = -n;
//     for(auto e : d) ans += e / gc;
//     cout << ans << endl;
// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// const int inf = 1e17;
// int n, m, k;

// string s;

// void solve(){

//     vector<array<int, 2>>seg;
//     char last = 0;
//     for(auto c : s){
//         if(c == last){
//             seg.back()[1]++;
//         }else{
//             seg.push_back({c, 1});
//             last = c;
//         }
//     }

//     int id = -1;
//     char tmp[50] = {0};

//     for(int j = 0;j < seg.size();j++){
//         auto [c, v] = seg[j];
//         if(v == 1){
//             if(j + 1 < seg.size() && c > seg[j+1][0]){
//                 id = j;
//                 break;
//             }
//         }
//     }

//     if(id == -1){
//         for(int j = seg.size() - 1;j >= 0;j--){
//             auto [c, v] = seg[j];
//             itoa(v, tmp, 16);
//             if(v <= 2){
//                 id = j;
//                 break;
//             }
//             if(tmp[0] == '1'){
//                 int ok = 1;
//                 for(int i = 1;tmp[i];i++){
//                     if(tmp[i] != '0'){
//                         ok = 0;
//                         break;
//                     }
//                 }
//                 if(ok){
//                     id = j;
//                     break;
//                 }
//             }
//         }
//     }

//     if(id != -1){
//         seg[id][1]--;
//     }else{
//         seg[0][1]--;
//     }

//     for(auto [c, v] : seg) if(v){
//         if(v >= 2){
//             cout << (char)c;
//             itoa(v, tmp, 16);
//             for(int i = 0;tmp[i];i++){
//                if(tmp[i] >= 'a' && tmp[i] <= 'z') tmp[i] += 'A' - 'a';
//                cout << tmp[i];
//             }
//         }else{
//             cout << (char)c;
//         }
//     }

//     cout << endl;
// }

// signed main(){

//     IO;
//     int t = 1;
//     // cin >> t;
//     while(cin >> s) solve();

//     // cerr << (int)'A' << ' ' << (int)'9';

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// const int inf = 1e17;
// int n, m, k;

// void solve(){
//     cin >> n;
//     vector<int>a(n + 5);
//     int f = 0, cnt = 0;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         if(a[i] < 0) cnt++;
//         if(a[i] == 0) f = 1;
//     }
//     if(f || (cnt & 1)){
//         cout << "0\n";
//         return;
//     }

//     cout << "1\n1 0\n";
// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// const int inf = 1e17;
// int n, m, k;

// void solve(){
//     cin >> n;
//     string s;
//     cin >> s;
//     set<char>st;
//     int ans = 1;
//     st.insert(s[0]);
//     for(int i = 1;i < n;i++){
//         st.insert(s[i]);
//         ans += st.size();
//     }
//     cout << ans << endl;
// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// const int inf = 1e17;
// int n, m, k, d;

// void solve(){
//     cin >> n >> k >> d;
//     vector<int>a(n + 5); 
//     vector<int>v(k + 5); 
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     for(int i = 1;i <= k;i++) cin >> v[i];

//     int ans = 0, p = 1;
//     for(int i = 1;i <= min(max(n+1, k * 2+2), d);i++){
//         int tmp = 0;
//         for(int j = 1;j <= n;j++) tmp += (a[j] == j);
//         ans = max(ans, tmp + (d - i) / 2);

//         for(int j = 1, val = v[p];j <= val;j++) a[j]++;
//         p++;
//         if(p > k) p = 1;
//     }

//     cout << ans << endl;

// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 4e5 + 10;
// const int inf = 1e17;
// const int mod = 998244353;
// int n, m;

// int lowbit(int x){
//     return x & -x;
// }
// struct BIT{
//     vector<int>tr;
//     int n;

//     BIT(int x) : tr(x + 5), n(x) {}

//     void add(int x, int v){
//         while(x <= n){
//             tr[x] += v;
//             x += lowbit(x);
//         }
//     }
//     int getsum(int x){
//         int ret = 0;
//         while(x > 0){
//             ret += tr[x];
//             x -= lowbit(x);
//         }
//         return ret;
//     }
// };

// void solve(){
//     cin >> n >> m;
//     vector<int>p(n), q(m);
//     for(auto &e : p) cin >> e;
//     for(auto &e : q){
//         cin >> e;
//         e++;
//     }

//     int ans = 0;
//     BIT tr(m);
//     for(int i = m-1;i >= 0;i--){
//         ans = (ans + tr.getsum(q[i])) % mod;
//         tr.add(q[i], 1);
//     }
//     ans = ans * n % mod;

//     int all = m*(m+1)/2;
//     for(int i = 0;i < m && i <= 18;i++) all -= m - i;

//     tr = BIT(n << 1);
//     for(int i = n-1;i >= 0;i--){
//         for(int j = -18;j <= 18;j++){
//             if(abs(j) >= m) continue;
//             int d = (j > 0 ? (p[i] << j) : ((p[i] >> -j)));
//             d = min(d, 2*n);
//             d = tr.getsum(d);
//             ans = (ans + (m-abs(j)) * d % mod) % mod;
//         }   
//         ans = (ans + tr.getsum(2*n) * all % mod) % mod;
//         tr.add(p[i], 1);
//     }

//     cout << ans << endl;
// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 4e5 + 10;
// const int inf = 1e17;
// const int mod = 998244353;
// int n, m;

// void solve(){
//     cin >> n;
//     vector<int>h(n);
//     vector<array<int, 2>>b;
//     for(auto &e : h) cin >> e;
//     int mx = 0;
//     for(int i = n-1;i >= 0;i--){
//         if(h[i] >= mx) b.push_back({h[i], i}), mx = h[i];
//     }
//     reverse(all(b));

//     auto find = [&](auto self, int ql, int qr, int l, int r) -> int {
//         if(l > r) return 0;
//         int ret = 0;
//         if(l == r){
//             for(int i = ql;i <= qr && i < b[l][1];i++){
//                 ret = max(ret, (b[l][0] + h[i]) * (b[l][1] - i));
//             }
//             return ret;
//         }
        
//         int mid = (l + r) >> 1, s;
//         for(int i = ql;i <= qr && i < b[mid][1];i++){
//             if((b[mid][0] + h[i]) * (b[mid][1] - i) > ret){
//                 ret = (b[mid][0] + h[i]) * (b[mid][1] - i);
//                 s = i;
//             }
//         }

//         return max({self(self, ql, s, l, mid-1), self(self, s, qr, mid+1, r), ret});

//     };

//     m = b.size();
//     // cerr << m << endl;
//     // for(auto [v,id] : b) cerr << v << ' ';

//     cout << find(find, 0, n-1, 0, m-1);

// }

// signed main(){

//     IO;
//     int t = 1;
//     // cin >> t;
//     while(t--) solve();

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 4e5 + 10;
// const int inf = 1e17;
// const int mod = 998244353;
// int n, m;

// void solve(){
//     cin >> n;
//     vector<int>c(2*n + 5);
//     for(int i = 1;i <= 2*n;i++) cin >> c[i];
//     vector<array<int, 2>>p;
//     vector<int>len;
//     int lst = 1;
//     for(int i = 2;i <= 2*n;i++){
//         if(c[i] > c[lst]){
//             p.push_back({lst, i-1});
//             len.push_back(i-lst);
//             lst = i;
//         }
//         if(i == 2*n){
//             p.push_back({lst, i});
//             len.push_back(i-lst+1);
//         }
//     }
//     if(len[0] == n){
//         for(int i = 1;i <= n;i++) cout << c[i] << ' ';
//         cout << endl;
//         for(int i = n + 1;i <= 2*n;i++) cout << c[i] << ' ';
//         cout << endl;
//         return;
//     }

//     // for(auto [l, r] : p) cout << l << ' ' << r << endl;

//     vector<bitset<1024>>f(n+5);
//     f[0][len[0]] = 1;
//     for(int i = 1;i < len.size();i++){
//         f[i] = ((f[i-1]<<len[i]) | f[i-1]);

//         // for(int j = 0;j <= 10;j++) cerr << f[i][j];
//         // cerr << endl;

//         if(f[i][n]){
//             vector<int>ans(p.size() + 5);
//             int nd = n;
//             for(int j = i;j >= 1;j--){
//                 if(!f[j-1][nd]){
//                     ans[j] = 1;
//                     nd -= len[j];
//                 }
//                 // cerr << nd << endl;
//             }
//             if(nd) ans[0] = 1;

//             vector<int>arr[2];
//             for(int i = 0;i < p.size();i++){
//                 for(int k = p[i][0];k <= p[i][1];k++){
//                     arr[ans[i]].push_back(c[k]);
//                 }
//             }
//             for(auto e : arr[1]) cout << e << ' ';
//             cout << endl;
//             for(auto e : arr[0]) cout << e << ' ';
//             cout << endl;
//             return;
//         }
//     }

//     cout << "-1\n";
// }

// signed main(){

//     IO;
//     int t = 1;
//     // cin >> t;
//     while(t--) solve();

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 4e5 + 10;
// const int inf = 1e17;
// const int mod = 998244353;
// int n, m;

// void solve(){
//     string s;
//     cin >> s;
//     for(int i = 0;i < 3;i++)
//     for(int j = i + 1;j < 3;j++){
//         swap(s[i], s[j]);
//         if(s == "abc"){
//             cout << "YES\n";
//             return;
//         }
//         swap(s[i], s[j]);
//     }
//         if(s == "abc"){
//             cout << "YES\n";
//             return;
//         }
//     cout << "NO\n";
// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 4e5 + 10;
// const int inf = 1e17;
// const int mod = 998244353;
// int n, m;

// void solve(){
//     cin >> n;
//     vector<int>a(n);
//     for(auto & e : a) cin >> e;
//     sort(all(a));
//     a[0]++;
//     for(int i = 1;i < n;i++){
//         a[i] *= a[i-1];
//     }
//     cout << a[n-1] << endl;
// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }





// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 4e5 + 10;
// const int inf = 1e17;
// const int mod = 998244353;
// int n, m;

// void solve(){
//     vector<string>s(10);
//     for(auto& e : s) cin >> e;
//     int ans = 0;
//     for(int i = 0;i < 10;i++){
//         for(int j = 0;j < 10;j++) if(s[i][j] == 'X'){
//             int d = min({i+1, j+1, 10-i, 10-j});
//             ans += d;
//         }
//     }
//     cout << ans << endl;
// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 4e5 + 10;
// const int inf = 1e17;
// const int mod = 998244353;
// int n, m, k;

// void solve(){
//     cin >> n >> k;
//     string s;
//     cin >> s;
//     s = ' ' + s;
//     int ans = 0;
//     for(int i = 1;i <= n;i++) if(s[i] == 'B'){
//         ans++;
//         i += k-1;
//     }
//     cout << ans << endl;
// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 4e5 + 10;
// const int inf = 1e17;
// const int mod = 998244353;
// int n, m, k, x;

// void solve(){
//     cin >> n >> x;
//     vector<int>a(n);
//     for(auto& e : a) cin >> e;
//     int l = 1, r = 1e9+10;

//     auto check = [&](int h) -> int {
//         int ret = 0;
//         for(int i = 0;i < n;i++){
//             ret += max(0ll, h - a[i]);
//         }
//         return ret;
//     };

//     while(l <= r){
//         int mid = l + r >> 1;
//         if(check(mid) <= x) l = mid + 1;
//         else r = mid - 1;
//     }
//     cout << r << endl;
// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 4e5 + 10;
// const int inf = 1e17;
// const int mod = 998244353;
// int n, m, k, x;

// void solve(){
//     cin >> n;
//     vector<int>a(n);
//     unordered_map<int,int>pre;
//     unordered_map<int,int>suf;
//     for(int i = 0;i < n;i++) cin >> a[i], suf[a[i]]++;
//     int ans = 0;
//     for(int i = 0;i < n;i++){
//         suf[a[i]]--;
//         for(auto [k, v] : pre){
//             ans += v * suf[(a[i]-k)+a[i]];
//         }
//         pre[a[i]]++;
//     }
//     cout << ans << endl;
// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 4e5 + 10;
// const int inf = 1e17;
// const int mod = 1e9 + 7;
// int n, m, k, x;

// int __log(int a, int b){
//     if(a == 1) return 0;
//     double pw = a;
//     int ret = 0;
//     while(pw <= b){
//         ret++;
//         pw *= a;
//     }
//     return ret;
// }

// int add(int a, int b){
//     return ((a%mod) + (b%mod)) % mod;
// }
// int mul(int a, int b){
//     return (a%mod) * (b%mod) % mod;
// }
// int _div(int a, int b){
//     a -= b;
//     while(a < 0) a += mod;
//     return a;
// }

// void solve(){
//     cin >> n >> k;

//     int ans = max(0ll, k-n) % mod;
//     // int ans = k % mod;
//     // cerr << ans << endl;
    
//     // int L, R;
//     // for (L = 1; L <= k && L <= n; L = R + 1)
//     // {
//     //     R = min(k, n / (n / L));
//     //     ans = add(ans, mul((n / L), (R - L + 1)) );
//         // cerr << L << '~' << R << ':' << n / L << '\n';
//     // }
//     // cerr << ans << endl;

//     for (int l = 1, r; l <= n && l <= k; l = r + 1) {
//         int t = (n + l - 1) / l;
//         r = min(k, t == 1 ? n : (n - 1) / (t - 1));
//         ans = add(ans, mul((r - l + 1), t));
//     } 
//     cerr << ans << endl;

//     for(int i = 2;i <= min(n, k);i++){
//         int d = __log(i, n);
//         ans = add(ans, d);
//         if(d == 1){
//             ans = add(ans, min(n, k)-i);
//             break;
//         }
//     }

//     // for(int i = 1;i * i <= n && i <= k;i++){
//     //     if(n % i == 0){
//     //         ans = _div(ans, 1);
//     //         if(n % (n/i) == 0 && (n/i) <= k && (n/i) != i){
//     //             ans = _div(ans, 1);
//     //         }
//     //     }
//     // }
//     // cerr << ans << endl;

//     cout << ans%mod << endl;

//     // int tmp = 0;
//     // for(int i = 1;i <= k;i++){
//         // for(int j = 1;j <= n;j+=i) tmp = add(tmp, 1);
//         // if(i != 1) for(int j = i;j <= n;j*=i) tmp = add(tmp, 1);
//     //     tmp = add(tmp, n/i);
//     //     if(n % i) tmp = add(tmp, 1ll);
//     //     tmp = add(tmp, __log(i, n)); 
//     // }
//     // cout << tmp << endl;
//     // // cerr << tmp << endl;

//     // if(tmp != ans){
//         // cout << n << ' ' << k << ' ' << ans << ' ' << tmp << endl;
//     // }
// }

// signed main(){

//     IO;
//     // int t = 1;
//     // while(t--) solve();

//     // for(int i = 1;i <= 100;i++){
//     //     for(int j = 1;j <= 100;j++){
//     //         n = i, k = j;
//             solve();
//     //     }
//     // }
//     // cerr << __log(2, 10);

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 4e5 + 10;
// const int inf = 1e17;
// const int mod = 1e9 + 7;
// int n, m, k, x;

// int add(int a, int b){
//     return ((a%mod) + (b%mod)) % mod;
// }
// int mul(int a, int b){
//     return (a%mod) * (b%mod) % mod;
// }
// int _div(int a, int b){
//     a -= b;
//     while(a < 0) a += mod;
//     return a;
// }

// void solve(){
//     cin >> n >> k;

//     int ans = max(0ll, k-n) % mod;
//     // cerr << ans << endl;

//     int L, R;
//     for (L = 1; L <= k && L <= n; L = R + 1)
//     {
//         R = min(k, n / (n / L));
//         ans = add(ans, mul((n / L), (R - L + 1)) );
//         // cerr << L << '~' << R << ':' << n / L << '\n';
//     }
//     // cerr << ans << endl;

//     for (int l = 1, r; l <= n && l <= k; l = r + 1) {
//         int t = (n + l - 1) / l;
//         r = min(k, t == 1 ? n : (n - 1) / (t - 1));
//         ans = add(ans, mul((r - l + 1), t));
//     }
//     ans = _div(ans, n);

//     cout << ans%mod << endl;
// }

// signed main(){

//     IO;
//     solve();

//     return 0;
// }





// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 4e5 + 10;
// const int inf = 1e17;
// const int mod = 1e9 + 7;
// int n, m, k, x;


// void solve(){
//     cin >> n;
//     vector<array<int, 3>>p(n*2);
//     vector<int>vis(n*2);
//     for(auto &[x, y, c] : p) cin >> x >> y;
//     for(int i = n;i < 2*n;i++) p[i][2] = 1;
//     sort(all(p), [&](const array<int, 3>& e1, const array<int,3>e2) -> int {
//         return e1[1] < e2[1];
//     });

//     vector<array<int, 2>>ans;
//     for(int i = 1;i <= n;i++){
//         int ls;
//         for(int j = 0;j < 2*n;j++){
//             if(!vis[j]){
//                 ls = j;
//                 break;
//             }
//         }
//         for(int j = ls + 1;j < 2*n;j++) if(!vis[j]){
//             if(p[ls][2] == p[j][2]) ls = j;
//             else {
//                 ans.push_back({ls, j});
//                 vis[ls] = vis[j] = 1;
//                 break;
//             }
//         }
//     }

//     int x = 500;
//     for(auto [a, b] : ans){
//         cout << "4\n";
//         cout << p[a][0] << ' ' << p[a][1] << endl;
//         cout << x << ' ' << p[a][1] << endl;
//         cout << x << ' ' << p[b][1] << endl;
//         cout << p[b][0] << ' ' << p[b][1] << endl;
//         x += 2;
//     }
// }   

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// using ll = long long;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// const int inf = 1e17;
// const int mod = 1e9 + 7;
// int n, val[N], ans[N];
// vector<array<int, 2>>g[N];

// using i64 = long long;
// struct Line {
// 	mutable i64 k, b, p;
// 	bool operator<(const Line &o) const { return k < o.k; }
// 	bool operator<(i64 x) const { return p < x; }
// };
// struct LineContainer : multiset<Line, less<>> {
//     static const int DOWN = 0;
//     static const int UP = 1;
//     bool MOD;
//     void setmod(int m){
//         MOD = m;
//     }
// 	static constexpr i64 INF = numeric_limits<i64>::max();
// 	i64 div(i64 a, i64 b) {
// 		return a / b - ((a ^ b) < 0 && a % b);
// 	}
// 	bool isect(iterator x, iterator y) {
// 		if (y == end()) return x->p = INF, 0;
// 		if (x->k == y->k) x->p = x->b > y->b ? INF : -INF;
// 		else x->p = div(y->b - x->b, x->k - y->k);
// 		return x->p >= y->p;
// 	}
//     // Insert f(x) = kx + b
// 	void add(i64 k, i64 b) {
//         if(MOD) k = -k, b = -b;
// 		auto z = insert({k, b, 0}), y = z++, x = y;
// 		while (isect(y, z)) z = erase(z);
// 		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
// 		while ((y = x) != begin() && (--x)->p >= y->p)
// 			isect(x, erase(y));
// 	}
//     // Query max(f(x))
// 	i64 query(i64 x) {
// 		if (empty()) return -INF;
// 		auto l = *lower_bound(x);
//         i64 ret = l.k * x + l.b;
//         if(MOD) ret = -ret;
// 		return ret;
// 	}
// };

// int del[N];
// int sz[N], dep[N], path[N];
// int k;

// void calc(int u){
//     LineContainer lc;
//     lc.setmod(lc.UP);
//     auto dfs = [&](auto self, int u, int f) -> void {
//         lc.add(val[u], path[u]);
//         for(auto [v, w] : g[u]) if(!del[v] && v != f){
//             path[v] = path[u] + w; 
//             self(self, v, u);
//         }
//     };
//     path[u] = 0;
//     dfs(dfs, u, 0);
//     auto dfs2 = [&](auto self, int u, int f) -> void {
//         ans[u] = min(ans[u], lc.query(val[u]) + path[u]);
//         for(auto [v, w] : g[u]) if(!del[v] && v != f){
//             self(self, v, u);
//         }
//     };
//     dfs2(dfs2, u, 0);
// }

// void dfs(int u, int s){
//     int ms = s + 1, root = -1;
//     //求重心，最大子树最小
//     auto getroot = [&](auto self, int u, int f) -> void {
//         sz[u] = 1;
//         int mx = 0;
//         for(auto [v, w] : g[u]) if(!del[v] && v != f){
//             self(self, v, u);
//             sz[u] += sz[v];
//             mx = max(mx, sz[v]);
//         }   
//         mx = max(mx, s - sz[u]);
//         if(mx < ms) ms = mx, root = u;
//     };
//     getroot(getroot, u, 0);

//     calc(root);
//     del[root] = 1;
//     for(auto [v, w] : g[root]) if(!del[v]){
//         dfs(v, sz[v]);
//     }
// }   

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++) cin >> val[i], ans[i] = inf;
//     for(int i = 1, u, v, w;i < n;i++){
//         cin >> u >> v >> w;
//         g[u].push_back({v, w});
//         g[v].push_back({u, w});
//     }

//     dfs(1, n);

//     int sum = 0;
//     for(int i = 1;i <= n;i++){
//         sum += ans[i];
//         // cerr << ans[i] << endl;
//     }

//     cout << sum << endl;
// }   

// signed main(){

//     IO;
//     int t = 1;
//     // cin >> t;
//     while(t--) solve();

//     return 0;
// }