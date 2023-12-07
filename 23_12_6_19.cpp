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



#include<bits/stdc++.h>
using namespace std;
#define int long long
#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
const int N = 2e5 + 10;
int n, m;


void solve(){
    cin >> n;

}   

signed main(){

    IO;
    int t = 1;
    cin >> t;
    while(t--) solve();

    return 0;
}