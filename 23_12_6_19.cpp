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
