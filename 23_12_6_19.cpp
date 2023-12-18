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



#include<bits/stdc++.h>
using namespace std;
#define int long long
#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const int N = 1e6 + 10;
int n, m, a[N];

void solve(){

}

signed main(){

    IO;
    int t = 1;
    cin >> t;
    while(t--) solve();

    return 0;
}