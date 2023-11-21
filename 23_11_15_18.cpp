// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// const int N = 2e5 + 10;


// void solve(){
//     int n;
//     cin >> n;
//     vector<int>a(n + 10);
//     vector<int>b(n + 10);
//     vector<int>ma(n + 10);
//     vector<int>mb(n + 10);
//     int ap = 0, bp = 0, am = N, bm = N;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         if(ap) am = min(am, a[i]);
//         if(a[i] == 1) ap = i;
//     }
//     for(int i = 1;i <= n;i++){
//         cin >> b[i];
//         if(bp) bm = min(bm, b[i]);
//         if(b[i] == 1) bp = i;
//     }
//     ma[1] = mb[1] = n + 1;
//     for(int i = 2;i <= n;i++){
//         ma[i] = min(ma[i-1], a[i-1]);
//         mb[i] = min(mb[i-1], b[i-1]);
//     }
//     int ans = 0;
//     int tmp = min(ap, bp) - 1;
//     ans += (tmp * (tmp + 1)) / 2;
//     if(max(ap, bp) < n - 1){
//         tmp = n - 1 - max(ap, bp);
//         ans += (tmp * (tmp + 1)) / 2;
//     }
//     if(ap != bp){
//         tmp = abs(ap - bp) - 1;
//         ans += (tmp * (tmp + 1)) / 2;
//     }


//     for(int i = 1;i <= n;i++){
//         if(ma[i] == mb[i]) ans++;
//     }
//     // for(int i = 1;i <= n;i++) cerr << ma[i] << ' ';
//     // cerr << endl;
//     // for(int i = 1;i <= n;i++) cerr << mb[i] << ' ';
//     // cerr << endl;
//     // cerr << ans << endl;
//     for(int i = 1;i <= min(ap, bp) && i < n;i++){
//         ma[i] = min(ma[i], am);
//         mb[i] = min(mb[i], bm);
//         if(ma[i] == mb[i]) ans++;
//     }
//     // for(int i = 1;i <= n;i++) cerr << ma[i] << ' ';
//     // cerr << endl;
//     // for(int i = 1;i <= n;i++) cerr << mb[i] << ' ';
//     // cerr << endl;

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
// const int N = 2e5 + 10;


// void solve(){
//     int n;
//     cin >> n;
//     vector<int>a(n + 10);
//     vector<int>b(n + 10);
//     vector<int>pa(n + 10);
//     vector<int>pb(n + 10);
//     int ap = 0, bp = 0, am = N, bm = N;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         pa[a[i]] = i;
//     }
//     for(int i = 1;i <= n;i++){
//         cin >> b[i];
//         pb[b[i]] = i;
//     }
//     int ans = 0, l = min(pa[1], pb[1]), r = max(pa[1], pb[1]);
//     for(int i = 1;i <= n;i++){
//         int m = i + 1;
//         l = min({l, pa[i], pb[i]});
//         r = max({r, pa[i], pb[i]});
//         if((pa[m] >= l && pa[m] <= r) || (pb[m] >= l && pb[m] <= r)) continue;
//         int L = 1, R = n;
//         if(pa[m] < l) L = max(L, pa[m] + 1);
//         if(pb[m] < l) L = max(L, pb[m] + 1);
//         if(pa[m] > r) R = min(R, pa[m] - 1);
//         if(pb[m] > r) R = min(R, pb[m] - 1);
//         ans += (l - L + 1) * (R - r + 1);
//     }
//     int tmp = min(pa[1], pb[1]) - 1;
//     ans += (tmp * (tmp + 1)) / 2;
//     tmp = n - max(pa[1], pb[1]);
//     ans += (tmp * (tmp + 1)) / 2;
//     if(pa[1] != pb[1]){
//         tmp = abs(pa[1] - pb[1]) - 1;
//         ans += (tmp * (tmp + 1)) / 2;
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
// const int N = 2e5 + 10;


// void solve(){
//     int n;
//     cin >> n;
//     vector<int>a(n + 1);
//     int cnt = 0;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         if(a[i] == 2) cnt++;
//     }
//     if(cnt & 1){
//         cout << "-1\n";
//         return;
//     }else{
//         int s = 0;
//         for(int i = 1;i <= n;i++){
//             if(a[i] == 2) s ++;
//             if(s == cnt / 2){
//                 cout << i << endl;
//                 return;
//             }
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
// const int N = 2e5 + 10;


// void solve(){
//     int n, a = 0, b = 0, as = 0, bs = 0, pw = 1;
//     cin >> n;
//     while(n){
//         int d = n % 10, d2 = d / 2;
//         n /= 10;
//         // cerr <<d << ' ' << d2 << endl;
//         a += d2 * pw;
//         b += d2 * pw;
//         as += d2;
//         bs += d2;
//         if(d & 1){
//             if(as < bs){
//                 as++;
//                 a += pw;
//             }else{
//                 bs++;
//                 b += pw;
//             }
//         }
//         // cerr << a << ' ' << b << endl;
//         pw *= 10;
//     }
//     cout << a << ' ' << b << endl;
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


// void solve(){
//     int n, m;
//     cin >> n;
//     m = n * 2;
//     int s = m * (1 + m) / 2;
//     s -= n * (n - 1) / 2;
//     if(s % n){
//         cout << "No\n";
//         return;
//     }
//     cout << "Yes\n";
//     int a = s / n;
//     int q = 1, p = a - 1, k = p - 1;;
//     while(p <= m){
//         cout << q << ' ' << p << endl;
//         q++, p++;
//     }
//     q--;
//     p = k;
//     k = q;
//     q += (p - q) / 2;
//     while(q > k){
//         cout << q << ' ' << p << endl;
//         q--;
//         p--;
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
// const int N = 2e5 + 10;
// const int mod = 1e9 + 7;

// int qpow(int a, int x){
//     int ret = 1;
//     while(x > 0){
//         if(x & 1) ret = ret * a % mod;
//         a = a * a % mod;
//         x >>= 1;
//     }
//     return ret;
// }

// void solve(){
//     int n;
//     cin >> n;
//     vector<int>a(n + 10);
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//     }
//     a[0] = -3e9;
//     a[n + 1] = 3e9;
//     int ans = 0;
//     for(int i = 1;i <= n;i++){
//         for(int j = i + 1;j <= n;j++){
//             int d = a[j] - a[i];
//             int l = 0, r = i - 1;
//             while(l <= r){
//                 int mid = l + r >> 1;
//                 int s = a[i] - a[mid];
//                 if(s > d) l = mid + 1;
//                 else r = mid - 1;
//             } 
//             int L = r;
//             l = j + 1, r = n + 1;
//             while(l <= r){
//                 int mid = l + r >> 1;
//                 int s = a[mid] - a[j];
//                 if(s >= d) r = mid - 1;
//                 else l = mid + 1;
//             }
//             int R = l;
//             ans = (ans + qpow(2, L + n - R + 1)) % mod;
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
// const int mod = 1e9 + 7;
// const int inf = 2e9;
// int n;

// int tr[N];
// int lowbit(int x){
//     return x & -x;
// }
// void update(int x, int v){
//     while(x <= n){
//         tr[x] = max(tr[x], v);
//         x += lowbit(x);
//     }
// }
// int getmax(int x){
//     int ret = -inf;
//     while(x){
//         ret = max(ret, tr[x]);
//         x -= lowbit(x);
//     }
//     return ret;
// }

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++) tr[i] = -inf;
//     vector<int>a(n + 10);
//     vector<int>pre(n + 10);
//     vector<int>f(n + 10);
//     vector<int>idx;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         // if(a[i] >= 0) update(i, 0);
//     }
//     for(int i = 1;i <= n;i++){
//         pre[i] = pre[i-1] + a[i];
//         idx.push_back(pre[i]);
//     }
//     sort(all(idx));
//     idx.erase(unique(all(idx)), idx.end());
//     vector<int>id(n + 10);
//     for(int i = 1;i <= n;i++){
//         id[i] = lower_bound(all(idx), pre[i]) - idx.begin() + 1;
//     }

//     for(int i = 1;i <= n;i++){
//         f[i] = max(f[i-1], getmax(id[i]) + i);
//         if(a[i] >= 0) f[i] = max(f[i], 0ll);
//         if(pre[i] >= 0) f[i] = i;
//         update(id[i], f[i] - i);

//         // cerr << f[i] << ' ';
//     }

//     cout << f[n] << endl;
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
// const int mod = 1e9 + 7;
// const int inf = 2e9;
// int n;

// void solve(){
//     cin >> n;
//     int a = 1, b = 0;
//     n--;
//     int d = 2;
//     int p = 0;
//     while(n > 0) {
//         if(p <= 1){
//             b += min(n, d);
//             n -= min(n, d);
//         }else{
//             a += min(n, d);
//             n -= min(n, d);
//         }
//         d++;
//         p = (p + 1) % 4;
//     }
//     cout << a << ' ' << b << endl;
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
// const int mod = 1e9 + 7;
// const int inf = 2e9;
// int n;

// void solve(){
//     cin >> n;
//     int a[2] = {0, 1}, b[2] = {0};
//     n--;
//     int d = 2, st = 2;
//     int p = 0;
//     while(n > 0) {
//         int x = min(n, d);
//         if(p <= 1){
//             b[0] += x / 2;
//             b[1] += x / 2;
//             if(x & 1) b[st & 1]++;
//         }else{
//             a[0] += x / 2;
//             a[1] += x / 2;
//             if(x & 1) a[st & 1]++;
//         }
//         n -= x;
//         st += x;
//         d++;
//         p = (p + 1) % 4;
//     }
//     cout << a[1] << ' ' << a[0] << ' ' << b[1] << ' ' << b[0] << endl;
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
// const int mod = 1e9 + 7;
// const int inf = 2e9;
// int n, w, h;

// void solve(){
//     cin >> n >> w >> h;
//     vector<int>a(n + 10);
//     vector<int>b(n + 10);
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         // cout << '[' << a[i] - w << ", " << a[i] + w << "] ";
//     }
//     // cout << endl;
//     for(int i = 1;i <= n;i++){
//         cin >> b[i];
//         // cout << '[' << b[i] - h << ", " << b[i] + h << "] ";

//     }
//     if(h > w){
//         cout << "NO\n";
//         return;
//     }

//     int l = 0, r = 0;
//     for(int i = 1;i <= n;i++){
//         if(a[i] + w < b[i] + h){
//             r = max(r, (b[i] + h) - (a[i] + w));
//         }
//         if(a[i] - w > b[i] - h){
//             l = max(l, (a[i] - w) - (b[i] - h));
//         }
//     }

//     bool f = true;
//     for(int i = 1;i <= n;i++){
//         if(a[i] + w + r < b[i] + h || a[i] - w + r > b[i] - h){
//             f = false;
//             break;
//         }
//     }
//     if(f){
//         cout << "YES\n";
//         return;
//     }
//     f = true;
//     for(int i = 1;i <= n;i++){
//         if(a[i] + w - l < b[i] + h || a[i] - w - l > b[i] - h){
//             f = false;
//             break;
//         }
//     }
//     if(f){
//         cout << "YES\n";
//         return;
//     }
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
// const int N = 2e5 + 10;
// const int mod = 1e9 + 7;
// const int inf = 2e9;
// int n, w, h;

// void solve(){
//     cin >> n;
//     vector<int>a(n);
//     for(auto& e : a) cin >> e;
//     sort(all(a));
//     int ans = 0;
//     int cur = 1;
//     for(int i = 0;i < n;i++){
//         if(a[i] >= cur){
//             ans += a[i] - cur;
//             cur++;
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
// const int mod = 1e9 + 7;
// const int inf = 2e9;
// int n, m;

// void solve(){
//     cin >> n;
//     if(n % 3 == 2 || n % 3 == 1) cout << "First\n";
//     else cout << "Second\n";
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
// const int mod = 1e9 + 7;
// const int inf = 2e9;
// int n, m;

// void solve(){
//     cin >> n;
//     vector<int>a(n + 1);
//     int mx = 0, mn = 1e17;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         mx = max(mx, a[i]);
//         mn = min(mn, a[i]);
//     }
//     int ans = mx - mn;
//     int sq = sqrt(n);
//     for(int i = 2;i <= sq;i++){
//         if(n % i == 0){
//             int tmp = 0;
//             mx = 0, mn = 1e17;
//             for(int j = 1;j <= n;j++){
//                 tmp += a[j];
//                 if(j % i == 0){
//                     mx = max(mx, tmp);
//                     mn = min(mn, tmp);
//                     tmp = 0;
//                 }
//             }
//             ans = max(ans, mx - mn);
//             if(n % (n / i) == 0){
//                 int tt = n / i;
//                 int tmp = 0;
//                 mx = 0, mn = 1e17;
//                 for(int j = 1;j <= n;j++){
//                     tmp += a[j];
//                     if(j % tt == 0){
//                         mx = max(mx, tmp);
//                         mn = min(mn, tmp);
//                         tmp = 0;
//                     }
//                 }
//                 ans = max(ans, mx - mn);
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
// const int mod = 1e9 + 7;
// const int inf = 2e9;
// int n, m;

// void solve(){
//     cin >> n;
//     vector<int>a(n + 1);
//     int ans = -1e15;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         ans = max(ans, a[i]);
//     }
//     int cur = 0, last = -1e15;
//     for(int i = 1;i <= n;i++){
//         if((last == -1e15 || (last & 1) != (a[i] & 1))){
//             cur += a[i];
//             last = a[i];
//             if(cur > 0){
//                 ans = max(ans, cur);
//                 // cerr << i << ' ' << ans << endl;
//             }
//             if(cur <= 0){
//                 cur = 0;
//                 last = -1e15;
//             }
//         }else{
//             if(a[i] <= 0){
//                 cur = 0;
//                 last = -1e15;
//             }else{
//                 cur = last = a[i];
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
// const int mod = 1e9 + 7;
// const int inf = 2e9;
// int n, m;

// void solve(){
//     cin >> n;
//     vector<int>a(n + 1);
//     map<int,int>mp;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         mp[a[i]]++;
//     }
//     int tmp = mp[1] + mp[2];
//     int ans = tmp * (tmp - 1) / 2;
//     for(auto [k, v] : mp){
//         if(k == 1 || k == 2) continue;
//         ans += v * (v - 1) / 2;
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
// const int mod = 1e9 + 7;
// const int inf = 2e9;
// int n, m;

// void solve(){
//     cin >> n;
//     vector<int>a(n + 1);
//     int mn = 1;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         if(a[i] < a[mn]) mn = i;
//     }

//     for(int i = mn + 1;i <= n;i++){
//         if(a[i] < a[i-1]){
//             cout << "-1\n";
//             return;
//         }
//     }
//     cout << mn - 1 << endl;

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
// const int mod = 1e9 + 7;
// const int inf = 2e9;
// int n, q;

// void solve(){
//     cin >> n >> q;
//     vector<int>d(q+1);
//     for(int i = 1;i <= q;i++){
//         cin >> d[i];
//     }
//     for(int i = 1;i < n;i++){
//         cout << i << ' ' << i + 1 << endl;
//     }
//     int cur = n-1;
//     for(int i = 1;i <= q;i++){
//         if(d[i] == cur){
//             cout << "-1 -1 -1\n";
//         }else{
//             cout << n << ' ' << cur << ' ' << d[i] << endl;
//             cur = d[i];
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
// #define ls (tr[id].l)
// #define rs (tr[id].r)
// const int N = 1e5 + 10;
// const int M = N * 50;
// const int mod = 1e9 + 7;
// const int inf = 2e9;
// int n, q;

// struct Q{
//     int id, l, r;
// };

// int tot, rt[N];
// struct node{
//     int l, r;
//     int sum;
// }tr[M];

// int getnd(){
//     ++tot;
//     tr[tot] = {0};
//     return tot;
// }
// void modify(int& id, int l, int r, int x, int v){
//     if(!id) id = getnd();
//     tr[id].sum += v;
//     if(l == r) return;
//     int mid = l + r >> 1;
//     if(x <= mid) modify(ls, l, mid, x, v);
//     else modify(rs, mid + 1, r, x, v);
// }
// void merg(int&x, int y){
//     if(!x || !y) x |= y;
//     else{
//         tr[x].sum += tr[y].sum;
//         merg(tr[x].l, tr[y].l);
//         merg(tr[x].r, tr[y].r);
//     }
// }
// int query(int id, int l, int r, int ql, int qr){
//     if(!id) return 0;
//     if(ql <= l && r <= qr) return tr[id].sum;
//     int mid = l + r >> 1;
//     if(qr <= mid) return query(ls, l, mid, ql, qr);
//     else if(ql > mid) return query(rs, mid + 1, r, ql, qr);
//     else return query(ls,l,mid,ql,qr) + query(rs,mid+1,r,ql,qr);
// }
// int p[N], id[N], ans[N];
// vector<int>g[N];
// vector<Q>qur[N];

// void init(){
//     for(int i = 1;i <= n;i++) {
//         g[i].clear();
//         qur[i].clear();
//         rt[i] = 0;
//     }
//     tot = 0;
// }

// void dfs(int u, int f) {
//     for(auto v : g[u]) if(v != f){
//         dfs(v, u);
//         merg(rt[u], rt[v]);
//     }
//     modify(rt[u], 1, n, id[u], 1);
//     for(auto [id, l, r] : qur[u]){
//         ans[id] = query(rt[u], 1, n, l, r);
//     }
// }

// void solve(){
//     cin >> n >> q;
//     init();
//     for(int i = 1, u, v;i < n;i++){
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }
//     for(int i = 1;i <= n;i++){
//         cin >> p[i];
//         id[p[i]] = i;
//     }

//     for(int i = 1, l, r, x;i <= q;i++){
//         cin >> l >> r >> x;
//         qur[x].push_back({i, l, r});
//     }


//     dfs(1, 0);

//     for(int i = 1;i <= q;i++) {
//         if(ans[i]) cout << "YES\n";
//         else cout << "NO\n";
//     }
//     cout << "\n";
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
// const int mod = 1e9 + 7;
// const int inf = 2e9;
// int n, q;

// struct Q{
//     int id, l, r;
// };

// int tr[N];
// int lowbit(int x){
//     return x & -x;
// }
// void add(int x, int v){
//     while(x <= n){
//         tr[x] += v;
//         x += lowbit(x);
//     }
// }
// int getsum(int x){
//     int ret = 0;
//     while(x > 0){
//         ret += tr[x];
//         x -= lowbit(x);
//     }
//     return ret;
// }

// int p[N], id[N], ans[N];
// vector<int>g[N];
// vector<Q>qur[N];

// void init(){
//     for(int i = 1;i <= n;i++) {
//         g[i].clear();
//         qur[i].clear();
//         tr[i] = 0;
//     }
//     for(int i = 1;i <= q;i++) {
//         ans[i] = 0;
//     }
// }

// void dfs(int u, int f) {
//     for(auto [id, l, r] : qur[u]){
//         ans[id] -= getsum(r) - getsum(l-1);
//     }
//     add(id[u], 1);
//     for(auto v : g[u]) if(v != f){
//         dfs(v, u);
//     }
//     for(auto [id, l, r] : qur[u]){
//         ans[id] += getsum(r) - getsum(l-1);
//     }
// }

// void solve(){
//     cin >> n >> q;
//     init();
//     for(int i = 1, u, v;i < n;i++){
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }
//     for(int i = 1;i <= n;i++){
//         cin >> p[i];
//         id[p[i]] = i;
//     }

//     for(int i = 1, l, r, x;i <= q;i++){
//         cin >> l >> r >> x;
//         qur[x].push_back({i, l, r});
//     }

//     dfs(1, 0);

//     for(int i = 1;i <= q;i++) {
//         if(ans[i]) cout << "YES\n";
//         else cout << "NO\n";
//     }
//     cout << "\n";
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
// const int N = 1e5 + 10;
// int n, m;

// int calc(vector<int>& p, vector<array<int, 2>>& t){
//     if(p.size() == 0) return 0;
//     array<int, 2>z = {0};
//     vector<array<int,2>>f(1<<p.size());
//     for(int i = 1;i < f.size();i++){
//         for(int j = 0;j < p.size();j++) if((1 << j) & i){
//             auto ls = f[i - (1 << j)];
//             int k = ls[0];
//             array<int,2>tmp;
//             if(p[j] <= t[k][1] - ls[1]){
//                 tmp = ls;
//                 tmp[1] += p[j];
//             }else{
//                 k++;
//                 while(k < t.size() && p[j] > t[k][1]) k++;
//                 if(k < t.size()){
//                     tmp = {k, p[j]};
//                 }else{
//                     tmp = {10000000,0};
//                 }
//             }
//             if(f[i] == z) f[i] = tmp;
//             else f[i] = min(f[i], tmp);
//         }
//     }
//     int ret = t[f[(1<<p.size())-1][0]][0] + f[(1<<p.size())-1][1];
// Z    return ret;
// }

// void solve(){
//     cin >> n >> m;
//     vector<int>d[3];
//     vector<array<int, 2>>t[3];
//     for(int i = 1, x, y;i <= n;i++){
//         cin >> x >> y;
//         x++;
//         d[x].push_back(y);
//     }
//     for(int i = 1, a, b, c;i <= m;i++){
//         cin >> a >> b >> c;
//         c++;
//         t[c].push_back({a, b});
//     }
//     int ans = max({calc(d[0],t[0]), calc(d[1],t[1]), calc(d[2],t[2])});
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
// const int N = 1e5 + 10;
// int n, m, q;
// int f[N][20], Log[N];

// void solve(){
//     cin >> n;
//     vector<int>a(n + 1);
//     vector<int>b(n + 1);
//     vector<int>pa(n + 1);
//     vector<int>pb(n + 1);
//     vector<int>d(n + 1);
//     for(int i = 1;i <= n;i++) cin >> a[i], pa[i] += pa[i-1] + a[i];
//     for(int i = 1;i <= n;i++) cin >> b[i], pb[i] += pb[i-1] + b[i], d[i] = pa[i] - pb[i-1];
//     for(int i = 1;i <= n;i++) f[i][0] = i;

//     auto maxx = [&](int i, int j) -> int {
//         if(d[i] > d[j]) return i;
//         return j;
//     };
//     auto mxpos = [&](int l, int r) -> int {
//         int s = Log[r - l + 1];
//         return maxx(f[l][s], f[r - (1 << s) + 1][s]); 
//     };

//     for(int j = 1;j < 20 ;j++){
//         for(int i = 1;i <= n && i + (1 << j) - 1 <= n;i++){
//             f[i][j] = maxx(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
//         }
//     }
//     for(int i = 2;i <= n;i++){  //预处理对数
//         Log[i] = Log[i / 2] + 1;
//     }

//     cin >> q;
//     while(q--){
//         int l, r;
//         cin >> l >> r;
//         int pos = mxpos(l, r);
//         int ans = max(0ll, (pb[r] - pb[pos-1]) - (pa[r] - pa[pos]));
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
// const int N = 1e5 + 10;
// int n, k, q;

// void solve(){
//     cin >> n >> k;
//     string s;
//     cin >> s;
//     s = ' ' + s;
//     int sum = 0;
//     for(int i = 1;i <= n;i++){
//         if(s[i] == 'B') sum++;
//     }
//     if(sum == k){
//         cout << "0\n";
//         return;
//     }
//     cout << "1\n";
//     for(int i = 1;i <= n;i++){
//         if(s[i] == 'B') sum--;
//         if(sum == k){
//             cout << i << ' ' << "A\n";
//             return;
//         }
//         if(i + sum == k){
//             cout << i << ' ' << "B\n";
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
// const int N = 1e5 + 10;
// int n, k, q;

// void solve(){
//     cin >> n;
//     vector<int>a(n+1);
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     int ls = 1e9 + 10;
//     int ans = 0;
//     for(int i = n;i >= 1;i--){
//         if(a[i] > ls){
//             int d = (a[i] + ls - 1) / ls;
//             ans += d - 1;
//             ls = a[i] / d;
//         }else{
//             ls = a[i];
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
// const int N = 1e5 + 10;
// int n, k, m;

// int mpr[20][20], mpc[20][20];

// void solve(){
//     cin >> n >> m >> k;
//     mpr[n][m-1] = 0;
//     mpr[n-1][m-1] = 0;
//     mpc[n-1][m] = 1;
//     mpc[n-1][m-1] = 1;
//     for(int i = n-2;i >= 1;i--){
//         mpc[i][m-1] = mpc[i+1][m-1] ^ 1;
//     }
//     mpr[1][m-1] = mpc[1][m-1];
//     for(int i = m-2;i >= 1;i--){
//         mpr[1][i] = mpr[1][i+1] ^ 1;
//     }
//     for(int i = 1;i <= n-1;i++){
//         mpc[i][m] = mpc[i][m-2] = mpc[i][m-1] ^ 1;
//     }
//     if(n + m - 1 > k){
//         cout << "NO\n";
//         return;
//     }
//     int tmp = (k - ((m - 2) + (n - 2))) % 4;
//     if(!(tmp == 2 || tmp == 3 || tmp == 0)){
//         cout << "NO\n";
//         // cerr << tmp << endl;
//         return;
//     }

//     cout << "YES\n";
//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j < m;j++){
//             cout << (mpr[i][j] ? 'R' : 'B') << ' ';
//         }
//         cout << endl;
//     }
//     for(int i = 1;i < n;i++){
//         for(int j = 1;j <= m;j++){
//             cout << (mpc[i][j] ? 'R' : 'B') << ' ';
//         }
//         cout << endl;
//     }
//     // for(int i = 1;i <= n;i++){
//     //     for(int j = 1;j < m;j++){
//     //         if(j & 1) cout << "R ";
//     //         else cout << "B ";
//     //     }
//     //     cout << endl;
//     // }
//     // for(int i = 1;i < n;i++){
//     //     for(int j = 1;j <= m;j++){
//     //         if(i & 1){
//     //             if(j & 1) cout << "R ";
//     //             else cout << "B ";
//     //         }else{
//     //             if(!(j & 1)) cout << "R ";
//     //             else cout << "B ";

//     //         }
//     //     }
//     //     cout << endl;
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
// const int N = 1e5 + 10;
// int n, k, m;


// void solve(){
//     cin >> n;
//     vector<array<int, 2>>vec(n + 1);
//     int ans = 0;
//     for(int i = 1;i <= n;i++) cin >> vec[i][0];
//     for(int i = 1;i <= n;i++){
//         cin >> vec[i][1];
//         ans += abs(vec[i][0] - vec[i][1]);
//     }
//     int mn = 1e9, mx = 0;
//     for(int i = 1;i <= n;i++){
//         mx = max(mx, min(vec[i][0], vec[i][1]));
//         mn = min(mn, max(vec[i][0], vec[i][1]));
//     }
//     ans += max(0ll, (mx - mn) * 2);
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
// const int N = 1e5 + 10;
// int n, k, m;

// int mph[20][20], mpl[20][20];

// void solve(){
//     cin >> n >> m >> k;
//     k -= (n - 1) + (m - 1);
//     if(k < 0 || (k % 4) & 1){
//         cout << "NO\n";
//         return;
//     }
//     for(int i = 1;i < n;i++){
//         mpl[i][1] = i & 1;
//     }
//     mph[n][1] = mpl[n-1][1] ^ 1;
//     for(int i = 2;i < m;i++){
//         mph[n][i] = mph[n][i-1] ^ 1;
//     }
//     if(k % 4 == 0){
//         mph[n-1][m-1] = mph[n][m-1];
//         mpl[n-1][m] = mpl[n-1][m-1] = mph[n][m-1] ^ 1;
//     }else{
//         mph[n-1][m-1] = mph[n][m-1] = mph[n][m-2];
//         mpl[n-1][m] = mpl[n-1][m-1] = mph[n][m-1] ^ 1;
//     }

//     cout << "YES\n";
//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j < m;j++){
//             cout << (mph[i][j] ? 'R' : 'B') << ' ';
//         }
//         cout << endl;
//     }
//     for(int i = 1;i < n;i++){
//         for(int j = 1;j <= m;j++){
//             cout << (mpl[i][j] ? 'R' : 'B') << ' ';
//         }
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
// const int N = 2e5 + 10;
// int n, k, m;


// void solve(){
//     cin >> n >> m;
//     string s, t, tp;
//     cin >> tp >> t;
//     vector<int>vis(310);
//     for(auto c : t) vis[c] = 1;
//     for(auto c : tp) if(vis[c]) s.push_back(c);

//     if(s.size() < t.size()){
//         cout << "NO\n";
//         return;
//     }

//     n = s.size();
//     s = ' ' + s;
//     vector<int>sum(310);
//     vector<int>cur(310);
//     vector<vector<array<int, 30>>>gt(310);
//     vector<int>p(310);

//     auto getar = [&]() -> array<int, 30> {
//         array<int, 30>ret;
//         for(int i = 'a';i <= 'z';i++) if(vis[i]){
//             ret[i - 'a'] = sum[i];
//         }
//         return ret;
//     };

//     for(int i = 0;i < m;i++){
//         gt[t[i]].push_back(getar());
//         sum[t[i]]++;
//     }

//     auto check = [&](array<int, 30>& a, char c) -> int {
//         // cerr << c << endl;
//         for(int i = c + 1;i <= 'z';i++) if(vis[i]){
//                 // cerr << c << ' ' << (char)(i) <<  ' ' << cur[i] << ' ' << a[i-'a'] << endl;                
//             if(cur[i] < a[i-'a']){
//                 return 0;
//             }
//         }
//         return 1;
//     };

//     for(int i = 1;i <= n;i++){
//         if(p[s[i]] < gt[s[i]].size() && check(gt[s[i]][p[s[i]]], s[i]) ){
//             p[s[i]]++;
//             cur[s[i]]++;
//         }
//     }
//     for(int i = 'a';i <= 'z';i++) if(vis[i]){
//         if(p[i] < gt[i].size()) {
//             cout << "NO\n";
//             return;
//         }
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
// const int N = 2e5 + 10;
// int n, k, m;


// void solve(){
//     cin >> n >> k;
//     string s;
//     cin >> s;
//     map<char, int>mp;
//     for(auto c : s) mp[c]++;
//     int cnt = 0;
//     for(auto [k, v] : mp){
//         if(v & 1) cnt++;
//     }    
//     if((n - k) & 1){
//         k -= cnt - 1;
//     }else{
//         k -= cnt;
//     }
//     if(k < 0 || (k & 1)){
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
// const int N = 2e5 + 10;
// int n, k, m;


// void solve(){
//     cin >> n >> k;
//     vector<int>a(n);
//     for(auto& e : a) cin >> e;
//     int ans = 5;
//     if(k == 4) ans = 2;
//     int o = 0;
//     for(auto e : a){
//         if(e % 2 == 0) o++;
//         int tmp = e % k;
//         if(tmp) tmp = k - tmp;
//         ans = min(ans, tmp);
//     }
//     if(k == 4){
//         ans = min(ans, max(0ll, 2 - o));
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
// int n, k, m, L[N], R[N];

// struct node{
//     int mn, cnt, tag;
// }tr[N << 2];
// void up(int id){
//     tr[id].mn = min(tr[ls].mn, tr[rs].mn);
//     tr[id].cnt = 0;
//     if(tr[id].mn == tr[ls].mn) tr[id].cnt += tr[ls].cnt;
//     if(tr[id].mn == tr[rs].mn) tr[id].cnt += tr[rs].cnt;
// }
// void build(int id, int l, int r){
//     tr[id] = {0};
//     if(l == r){
//         tr[id].mn = 0;
//         tr[id].cnt = 1;
//         return;
//     }
//     int mid = l + r >> 1;
//     build(ls, l, mid);
//     build(rs, mid + 1, r);
//     up(id);
// }
// void settag(int id, int x){
//     tr[id].mn += x;
//     tr[id].tag += x;
// }
// void down(int id){
//     settag(ls, tr[id].tag);
//     settag(rs, tr[id].tag);
//     tr[id].tag = 0;
// }
// void modify(int id, int l, int r, int ql, int qr, int v){
//     if(ql <= l && r <= qr){
//         settag(id, v);
//         return;
//     }
//     if(tr[id].tag) down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) modify(ls, l, mid, ql, qr, v);
//     else if(ql > mid) modify(rs, mid + 1, r, ql, qr, v);
//     else modify(ls, l, mid, ql, qr, v), modify(rs, mid + 1, r, ql, qr, v);
//     up(id);
// }

// void solve(){
//     cin >> n >> m >> k;
//     build(1, 1, n);
//     vector<array<int, 3>>evt;
//     for(int i = 1;i <= m;i++){
//         cin >> L[i] >> R[i];
//         modify(1, 1, n, L[i], R[i], 1);
//         evt.push_back({L[i], 0, i});
//         evt.push_back({R[i], 1, i});
//     }
//     sort(all(evt));
//     int ans = (tr[1].mn ? 0 : tr[1].cnt);
//     for(auto [p, op, id] : evt){
//         if(op){
//             modify(1, 1, n, L[id], R[id], -1);
//         }else{
//             modify(1, 1, n, L[id], R[id], 1);
//         }
//         ans = max(ans, (tr[1].mn ? 0 : tr[1].cnt));
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
// int n, k, m, L[N], R[N];


// void solve(){
//     cin >> n >> m >> k;
//     vector<int>s(n + 10);
//     vector<int>s1(n + 10);
//     vector<int>s2(n + 10);
//     vector<array<int, 2>>g;
//     for(int i = 1;i <= m;i++){
//         cin >> L[i] >> R[i];
//         g.push_back({L[i], R[i]});
//         s[L[i]]++;
//         s[R[i] + 1]--;
//         // cerr << L[i] << ' ' << R[i] << endl;
//     }
//     int ze = 0;
//     for(int i = 1;i <= n;i++){
//         s[i] += s[i-1];
//         s1[i] += s1[i-1];
//         s2[i] += s2[i-1];
//         if(s[i] == 1){
//             s1[i]++;
//         }else if(s[i] == 0){
//             ze++;
//         }else if(s[i] == 2){
//             s2[i]++;
//         }
//         // cerr << i << ' '<< s[i] << endl;
//     }
//     int mx = 0, smx = 0;
//     for(int i = 1;i <= m;i++){
//         int d = s1[R[i]] - s1[L[i]-1];
//         smx = max(smx, d);
//         if(mx < smx) swap(mx, smx);
//     }
//     sort(all(g));
//     int ls[2] = {0, 1};
//     auto check = [&](int i, int j) -> int {
//         if(g[i][0] > g[j][1] || g[j][0] > g[i][1]) return 0;
//         vector<int>t;
//         t.push_back(g[i][0]);
//         t.push_back(g[i][1]);
//         t.push_back(g[j][0]);
//         t.push_back(g[j][1]);
//         sort(all(t));
//         int ret = s2[t[2]] - s2[t[1]-1];
//         ret += s1[t[3]] - s1[t[2]-1];
//         ret += s1[t[1]] - s1[t[0]-1];
//         return ret;
//     };
//     int to = check(0, 1);
//     for(int i = 2;i < g.size();i++){
//         if(check(ls[0], i)){
//             to = max(to, check(ls[0], i));
//             ls[1] = i;
//         }else if(check(ls[1], i)){
//             to = max(to, check(ls[1], i));
//             ls[0] = i;
//         }else{
//             ls[0] = ls[1] = i;
//         }
//     }
//     int ans = ze + max(to, mx + smx);
//     // cerr << to << endl;
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
// int n;


// void solve(){
//     cin >> n;
//     vector<int>a(n + 10);
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     for(int i = 1;i <= n;i++){
//         if(a[i] <= i){
//             cout << "YES\n";
//             return;
//         }
//     }
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
// const int N = 2e5 + 10;
// int n;


// void solve(){
//     cin >> n;
//     if(n % 2 == 0){
//         cout << "-1\n";
//         return;
//     }
//     stack<int>st;
//     while(n != 1){
//         if(((n + 1) / 2) & 1){
//             st.push(1);
//             n = (n + 1) / 2;
//         }else if(((n - 1) / 2) & 1){
//             st.push(2);
//             n = (n - 1) / 2;
//         }else{
//             cout << "-1\n";
//             return;
//         }
//     }
//     cout << st.size() << endl;
//     while(st.size()){
//         cout << st.top() << ' ';
//         st.pop();
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
// const int N = 2e5 + 10;
// int n, c, d;


// void solve(){
//     cin >> n >> c >> d;
//     vector<int>a(n);
//     for(auto& e : a) cin >> e;
//     sort(all(a));
//     a.erase(unique(all(a)), a.end());
//     int ans = (n - a.size()) * c;
//     n = a.size();
//     int mn = n * c + d;
//     if(a[0] == 1) mn -= c + d;
//     for(int i = 0;i < n;i++){
//         int tmp;
//         tmp = (n - i - 1) * c + (a[i] - 1 - i) * d;
//         mn = min(mn, tmp);
//     }
//     ans += mn;
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
// int q;

// void solve(){
//     cin >> q;
//     int op, a, b, d;
//     int L = 0, R = 0;

//     while(q--){
//         cin >> op >> a >> b;
//         if(op == 1){
//             cin >> d;
//             int ls = (d - 1) * (a - b);
//             int r = ls + a, l = 1;
//             if(ls) l = ls + b + 1;
//             if(L == 0 || (l <= R && r >= L)){
//                 cout << "1 ";
//                 if(L == 0){
//                     L = l;
//                     R = r;
//                 }else{
//                     L = max(L, l);
//                     R = min(R, r);
//                 }
//             }else{
//                 cout << "0 ";
//             }
//         }else{
//             if(L == 0 || (a <= R - L)){
//                 cout << "-1 ";
//                 continue;
//             }
//             if(a >= R){
//                 cout << "1 ";
//                 continue;
//             }
//             int t = L - 1 - b;
//             if(t <= 0){
//                 cout << "-1 ";
//                 continue;
//             }
//             t -= t % (a - b);
//             if(t < 0){
//                 cout << "-1 ";
//                 continue;
//             }
//             if(t + a >= R){
//                 cout << t / (a - b) + 1 << ' ';
//             }else{
//                 cout << "-1 ";
//             }
//         }
//         // cerr << L << ' ' << R << endl;
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
// const int N = 2e5 + 10;
// int n, m;

// int fa[N], siz[N];
// int find(int x){
//     return x == fa[x] ? x : fa[x] = find(fa[x]);
// }
// void merg(int a, int b){
//     a = find(a);
//     b = find(b);
//     if(a == b) return;
//     fa[a] = b;
//     siz[b] += siz[a];
// }

// void init(){
//     for(int i = 1;i <= n;i++){
//         fa[i] = i;
//         siz[i] = 1;
//     }
// }

// void solve(){
//     cin >> n >> m;
//     init();
//     vector<int>d(n + 5);
//     vector<int>vis(n + 5);
//     vector<vector<int>>g(n + 5);
//     for(int i = 1;i <= n;i++) cin >> d[i];
//     for(int i = 1, u, v;i <= m;i++){
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }
//     queue<int>q;
//     q.push(1);
//     int cnt = 1;
//     vis[1] = 1;
//     while(q.size()){
//         int u = q.front();
//         q.pop();
//         for(auto v : g[u]) if(!vis[v]){
//             q.push(v);
//             vis[v] = 1;
//             cnt++;
//         }
//     }
//     if(cnt != n){
//         cout << "NO\n";
//         return;
//     }
//     for(int i = 1;i <= n;i++) vis[i] = 0;

//     auto bfs = [&](int st) {
//         priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>>q;
//         q.push({0, st});
//         while(q.size()){

//         }
//     };

//     for(int i = 1;i <= n;i++) if(!vis[i] || !d[i]){

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
// int n, m;

// int fa[N], siz[N];
// int find(int x){
//     return x == fa[x] ? x : fa[x] = find(fa[x]);
// }
// void merg(int a, int b){
//     a = find(a);
//     b = find(b);
//     if(a == b) return;
//     fa[a] = b;
//     siz[b] += siz[a];
// }

// void init(){
//     for(int i = 0;i <= n;i++){
//         fa[i] = i;
//         siz[i] = 1;
//     }
// }

// void solve(){
//     cin >> n >> m;
//     init();
//     vector<int>a(n);
//     vector<vector<int>>g(n);
//     for(auto& e : a) cin >> e;
//     for(int i = 1, u, v;i <= m;i++){
//         cin >> u >> v;
//         u--, v--;
//         if(pair(a[u], u) < pair(a[v], v)) swap(v, u);
//         g[u].push_back(v);
//     }
//     vector<int>s(n);
//     iota(all(s), 0);
//     sort(all(s), [&](int i, int j) -> int {
//         return pair(a[i], i) < pair(a[j], j);
//     });
    
//     vector<bool>vis(n);
//     for(auto u : s){
//         vis[u] = a[u] == 0;
//         for(auto v : g[u]){
//             v = find(v);
//             if(vis[v] && siz[v] >= a[u]){
//                 vis[u] = true;
//             }
//             merg(v, u);
//         }
//     }

//     for(int i = 0;i < n;i++){
//         if(find(i) != find(0)) {
//             cout << "NO\n";
//             return;
//         }
//     }
//     if(vis[find(0)]) cout << "YES\n";
//     else cout << "NO\n";
// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }