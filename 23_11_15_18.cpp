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
//     string a, b;
//     cin >> a >> b;
//     reverse(all(b));
//     a += b;
//     int cnt = 0;
//     for(int i = 0;i < a.size() - 1;i ++){
//         if(a[i] == a[i + 1]) cnt++;
//     }
//     if(cnt <= 1)cout << "YES\n";
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
// int n, m, k;


// void solve(){
//     cin >> n >> k;
//     int L = 0, R = 0;
//     for(int i = 1, l, r;i <= n;i++){
//         cin >> l >> r;
//         if(l == k) L++;
//         if(r == k) R++;
//     }
//     if(L && R) cout << "YES\n";
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
// int n, m, k;


// void solve(){
//     cin >> n;
//     vector<int>a(n + 5);
//     vector<int>b(n + 5);
//     vector<int>pre(n + 5);
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     for(int i = 1;i <= n;i++) {
//         cin >> b[i];
//         pre[i] = b[i];
//         pre[i] += pre[i-1];
//     }

//     vector<int>d(n+5);
//     vector<int>s(n+5);
//     for(int i = 1;i <= n;i++){
//         int l = i - 1, r = n;
//         while(l <= r){
//             int mid = l + r >> 1;
//             if(pre[mid] - pre[i-1] <= a[i]) l = mid + 1;
//             else r = mid - 1;
//         }
//         l = r;
//         // cerr << l << endl;
//         s[i]++;
//         s[l+1]--;
//         d[l+1] += a[i] - (pre[l] - pre[i-1]);
//     }
//     for(int i = 1;i <= n;i++){
//         s[i] += s[i-1];
//         d[i] += s[i] * b[i];
//         cout << d[i] << ' ';
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
// const int mod = 998244353;
// int n, m, k;

// int qpow(int a, int x, int m = mod){
//     int ret = 1;
//     while(x){
//         if(x & 1) ret = ret * a % m;
//         a = a * a % m;
//         x >>= 1;
//     }
//     return ret;
// }
// int inv[N], fac[N];
// void get_inv(){
//     inv[0] = fac[0] = 1;
//     for(int i = 1;i < N;i++){
//         fac[i] = fac[i-1] * i % mod;
//     }
//     inv[N - 1] = qpow(fac[N - 1], mod - 2);
//     for(int i = N - 2;i >= 1;i--){
//         inv[i] = inv[i+1] * (i +1) %mod;
//     }
// }
// int C(int a, int b){
//     return (fac[a] * inv[a-b] % mod) * inv[b] % mod;
// }

// void solve(){
//     cin >> n;
//     int ans = C(n/3, n/6);
//     vector<int>w(n + 5);
//     vector<int>tp;
//     for(int i = 1;i <= n;i++){
//         cin >> w[i];
//         tp.push_back(w[i]);
//         if(i % 3 == 0){
//             sort(all(tp));
//             if(tp[0] != tp[1]){
//                 ;
//             }else if(tp[1] != tp[2]){
//                 ans = ans * 2 % mod;
//             }else{
//                 ans = ans * 3 % mod;
//             }
//             tp.clear();
//         }
//     }
//     cout << ans << endl;
// }

// signed main(){

//     IO;
//     get_inv();
//     int t = 1;
//     // cin >> t;
//     while(t--) solve();
//     // cout << C(4, 2);

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
// int n, m, k;


// void solve(){
//     cin >> n;
//     vector<int>a(n + 5);
//     vector<int>d(n + 5);
//     vector<int>f(n + 5);
//     vector<int>b(n + 5);
//     int sum = 0;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         sum += a[i];
//         d[i] = a[i] - i;
//     }
//     stack<int>st;
//     for(int i = 1;i <= n;i++){
//         while(st.size() && d[st.top()] >= d[i]) st.pop();
//         int j;
//         if(st.empty()){
//             j = max(0ll, i - a[i]);
//             f[i] = (i-j) * (a[i] - (i-j) + 1 + a[i]) / 2;
//         }else{
//             j = st.top();
//             f[i] = f[j] + (i-j) * (a[i] - (i-j) + 1 + a[i]) / 2;
//         }
//         st.push(i);
//     }
//     while(st.size()) st.pop();
//     for(int i = 1;i <= n;i++){
//         d[i] = a[i] + i;
//     }
//     for(int i = n;i >= 1;i--){
//         while(st.size() && d[st.top()] >= d[i]) st.pop();
//         int j;
//         if(st.empty()){
//             j = min(n + 1, i + a[i]);
//             b[i] = (j-i) * (a[i] - (j-i) + 1 + a[i]) / 2;
//         }else{
//             j = st.top();
//             b[i] = b[j] + (j-i) * (a[i] - (j-i) + 1 + a[i]) / 2;
//         }
//         st.push(i);
//     }
//     int mx = 0;
//     for(int i = 1;i <= n;i++){
//         mx = max(mx, f[i] + b[i] - a[i] - a[i]);
//     }
//     cout << sum - mx << endl;
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
// const int mod = 998244353;
// int n, m, k;


// void solve(){
//     int n;
//     cin >> n;
//     vector<int>a(n + 10);
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     int p = 1;
//     for(int i = 1;i < n;i++){
//         if(a[i] < 0 || a[i + 1] < 0) p = i;
//         if(a[i] < 0 && a[i + 1] < 0){
//             p = i;
//             break;
//         }
//     }
//     a[p] *= -1;
//     a[p + 1] *= -1;
//     int sum = 0;
//     for(int i = 1;i <= n;i++) sum += a[i];
//     cout << sum << endl;
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
// const int mod = 998244353;
// int n, m, k, d;


// void solve(){
//     cin >> n >> m >> d;
//     vector<int>p(n + 10);
//     vector<int>pos(n + 10);
//     vector<int>a(m + 10);
//     for(int i = 1;i <= n;i++) cin >> p[i], pos[p[i]] = i;
//     for(int i = 1;i <= m;i++) cin >> a[i];
//     int ans = n;
//     for(int i = 1;i < m;i++){
//         ans = min(ans, max(0ll, pos[a[i+1]] - pos[a[i]]));
//         if(d + 1 < n) ans = min(ans, max(0ll, pos[a[i]] + d + 1 - pos[a[i+1]]));
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
// const int N = 3e5 + 10;
// const int mod = 998244353;
// int n, m, k, d, sz;
// int vis[300];

// void solve(){
//     cin >> n >> k;
//     string a, b;
//     cin >> a >> b;
//     vector<char>c;
//     set<char>st;
//     for(auto e : a){
//         if(!st.count(e)){
//             st.insert(e);
//             c.push_back(e);
//         }
//     }
//     if(k >= c.size()){
//         cout << n * (n + 1) / 2 << endl;
//         return;
//     }
//     sz = c.size();

//     int ans = 0;

//     auto check = [&]() -> int {
//         int len = 0, ret = 0;
//         for(int i = 0;i < n;i++){
//             if(vis[a[i]] || a[i] == b[i]){
//                 len ++;
//             }else{
//                 ret += len * (len + 1) / 2;
//                 len = 0;
//             }
//         }
//         ret += len * (len + 1) / 2;
//         return ret;
//     };
//     auto dfs = [&](auto self, int x, int p) -> void {
//         for(int i = p;i < sz;i++){
//             vis[c[i]] = 1;
//             if(x == k){
//                 ans = max(ans, check());
//             }else if(i + (k - x) < sz){
//                 self(self, x + 1, i + 1);
//             }
//             vis[c[i]] = 0;
//         }
//     };

//     ans = check();
//     dfs(dfs, 1, 0);

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
// const int N = 1010;
// int h[N], n;

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++){
//         cin >> h[i];
//     }

//     auto check = [&](int i) -> int {
//         if(i - 2 < 1 || i + 2 > n) return 0;
//         return h[i-2] < h[i-1] && h[i-1] < h[i] && h[i] > h[i+1] && h[i+1] > h[i+2];
//     };

//     int sum = 0;
//     for(int i = 3;i + 2 <= n;i++){
//         if(check(i)) sum++;
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




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// const int N = 1010;
// int n, m;

// void solve(){
//     cin >> n >> m;
//     vector<int>a(n+1);
//     vector<int>d(n+1);
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     for(int i = 1;i <= n;i++) d[i] = a[i] - a[i-1];
//     int ans = (m - a[n]) * 2;
//     for(int i = 1;i <= n;i++){
//         ans = max(ans, d[i]);
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
// const int N = 1010;
// int n, m;

// void solve(){
//     cin >> n;
//     vector<int>a(n+1);
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     int ans = -1;
//     for(int i = 1;i <= n;i++){
//         if(a[i] <= a[i-1]) continue;
//         ans += a[i] - a[i-1];
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
// const int N = 1010;
// int n, m;

// void solve(){
//     cin >> n;
//     vector<int>a(n+1);
//     int mx = 1, mn = 1;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     for(int i = 1;i <= n;i++){
//         if(a[i] > a[mx]) mx = i;
//         if(a[i] < a[mn]) mn = i;
//     }
//     int cnt = 0;
//     vector<int>op;

//     int e = a[mn], f = a[mx];
//     while(e != f){
//         cnt++;
//         if((f - e) & 1){
//             if(e & 1){
//                 op.push_back(1);
//                 e++;
//                 f++;
//             }else{
//                 op.push_back(0);
//             }
//         }else{
//             op.push_back(0);
//         }
//         e /= 2;
//         f /= 2;
//     }
//     cout << cnt << endl;
//     if(cnt <= n && cnt) {
//         for(auto e : op) cout << e << ' ';
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
// const int N = 3e5 + 10;
// const int PRE = 0;
// const int SUF = 1;
// int n, m, a[N], d[2][N];

// int tr[2][N];
// int lowbit(int x){
//     return x & -x;
// }
// void changep(int x, int p){
//     int* ar = tr[PRE];
//     int* dd = d[PRE];
//     while(x <= n){
//         if(dd[ar[x]] < dd[p]) ar[x] = p;
//         x += lowbit(x);
//     }
// }
// void changes(int x, int p){
//     int* ar = tr[SUF];
//     int* dd = d[SUF];
//     while(x > 0){
//         if(dd[ar[x]] < dd[p]) ar[x] = p;
//         x -= lowbit(x);
//     }
// }
// int getpmx(int x){
//     int* ar = tr[PRE];
//     int* dd = d[PRE];
//     int ret = ar[x];
//     while(x > 0){
//         if(dd[ar[x]] > dd[ret]) ret = ar[x];
//         x -= lowbit(x);
//     }
//     return ret;
// }
// int getsmx(int x){
//     int* ar = tr[SUF];
//     int* dd = d[SUF];
//     int ret = ar[x];
//     while(x <= n){
//         if(dd[ar[x]] > dd[ret]) ret = ar[x];
//         x += lowbit(x);
//     }
//     return ret;
// }

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     for(int i = 1;i <= n;i++){
//         d[PRE][i] = a[i] + N - i;
//         d[SUF][i] = a[i] + N - (n - i);
//     }
//     for(int i = 1;i <= n;i++){
//         changep(i, i);
//         changes(i, i);
//     }

//     int ans = 1e10;
//     for(int i = 1;i <= n;i++){
//         int q = getpmx(i-1);
//         int p = getsmx(i+1);
//         int tmp = max({a[i], a[q]+(n-i)+(i-q), a[p]+(i-1)+(p-i)});
//         // cerr << tmp << ' ' << q << ' ' << p << endl;
//         ans = min(ans, tmp);
//     }
//     cout << ans << endl;

//     // for(int i = 1;i <= n;i++){
//     //     cerr << getsmx(i) << ' ';
//     // }
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
// const int N = 5e5 + 10;
// int n, m, a[N], dp[N], ans;
// vector<int>g[N];

// void dfs(int u, int f){
//     dp[u] = a[u];
//     if(g[u].size() == 2 && u != 1){
//         for(auto v : g[u]) if(v != f){
//             dfs(v, u);
//             ans = max(ans, dp[u] + dp[v]);
//             dp[u] = max(dp[u], dp[v]);
//         }
//         return;
//     }
//     int M = -1e9 - 10;
//     int Z = 0, mx = -1e9 - 10, smx = -1e9 - 10, F = 0, zsum = 0;
//     for(auto v : g[u]) if(v != f){
//         dfs(v, u);
//         M = max(M, dp[v]);
//         if(dp[v] >= 0) zsum += dp[v], Z++;
//         else{
//             F++;
//             smx = max(smx, dp[v]);
//             if(smx > mx) swap(smx, mx);
//         }
//     }

//     if(u == 1){
//         dp[u] += zsum;
//     }else{
//         if(Z > 1){
//             dp[u] += zsum;
//         }else if(Z == 1){
//             dp[u] = max({dp[u], zsum, dp[u] + zsum + mx});
//         }else{
//             dp[u] = max({dp[u], mx, dp[u] + mx + smx});
//         }
//     }
//     dp[u] = max(dp[u], M);
//     ans = max(ans, dp[u]);
// }

// void init(){
//     for(int i = 1;i <= n;i++) {
//         g[i].clear();
//     }
//     ans = 0;
// }

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     for(int i = 1, u, v;i < n;i++){
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }

//     dfs(1, 0);

//     cout << ans << endl;

//     // for(int i = 1;i <= n;i++){
//     //     cerr << dp[i] << endl;
//     // }
//     // cerr << dp[2] << endl;

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
// const int N = 2e5 + 10;
// int n, m, k;

// void solve(){
//     cin >> n;
//     vector<int>a(n + 10);
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//     }
//     if(a[1] == 1) cout << "YES\n";
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
// const int N = 2e5 + 10;
// int n, m, k;

// void solve(){
//     cin >> n;
//     string s;
//     cin >> s;
//     s = ' ' + s;
//     int q = n, p = 0;
//     for(int i = 1;i <= n;i++){
//         if(s[i] == 'A'){
//             q = i;
//             break;
//         }
//     }
//     for(int i = n;i >= 1;i--){
//         if(s[i] == 'B'){
//             p = i;
//             break;
//         }
//     }
//     cout << max(0ll, p - q) << endl;
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
// int n, m, k, ans[N];

// void solve(){
//     cin >> n >> k;
//     vector<int>a(n+10);
//     vector<int>b(n+10);
//     vector<int>id(n+10);
//     iota(id.begin() + 1, id.begin() + 1 + n, 1);
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     for(int i = 1;i <= n;i++) cin >> b[i];
//     sort(id.begin() + 1, id.begin() + 1 + n, [&](int i, int j) -> int {
//         return a[i] < a[j];
//     });
//     sort(a.begin() + 1, a.begin() + 1 + n);
//     sort(b.begin() + 1, b.begin() + 1 + n);
//     for(int i = n - k + 1, j = 1;i <= n;i++, j++){
//         if(a[i] <= b[j]){
//             cout << "NO\n";
//             return;
//         }
//     }
//     for(int i = 1, j = 1 + k;j <= n;j++, i++){
//         if(a[i] > b[j]){
//             cout << "NO\n";
//             return;
//         }
//     }
//     vector<int>c = b;
//     for(int i = n - k + 1, j = 1;i <= n;i++, j++){
//         c[i] = b[j];
//     }
//     for(int i = 1, j = 1 + k;j <= n;j++, i++){
//         c[i] = b[j];
//     }
//     for(int i = 1;i <= n;i++){
//         ans[id[i]] = c[i];
//     }
//     cout << "YES\n";
//     for(int i = 1;i <= n;i++) cout << ans[i] << ' ';
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
// const int N = 2e6 + 10;
// int n;

// int tr[N * 2];
// int lowbit(int x){
//     return x & -x;
// }
// void add(int x, int v){
//     while(x <= 2*n){
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

// void init(){
//     for(int i = 0;i <= 2*n + 5;i++) {
//         tr[i] = 0;
//     }
// }

// void solve(){
//     cin >> n;
//     vector<int>a(n + 10);
//     vector<int>ans(2*n + 10);
//     vector<int>d(2*n + 10);
//     vector<int>v(2*n + 10);
//     vector<vector<int>>q(2*n + 10);
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         d[i] = (a[i] - i + n) % n;
//         q[i + d[i]].push_back(a[i]);
//         v[i] = d[i] + i;
//     }
//     for(int i = 1;i <= n;i++){
//         v[i+n] = d[i] + (i+n);
//     }
//     for(int i = 1;i <= 2*n;i++){
//         add(v[i], 1);
//         if(i <= n) ans[a[i]] = d[i] + getsum(i + d[i]);
//         for(auto id : q[i]){
//             ans[id] -= getsum(i);
//         }
//     }
//     for(int i = 1;i <= n;i++) cout << ans[i] << ' ';
//     cout << endl;
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
// const int N = 2e5 + 10;
// int n;


// void solve(){
//     cin >> n;
//     string s;
//     cin >> s;
//     s = ' ' + s;
//     vector<int>len;
//     int cur = 0;
//     for(int i = 1;i <= n;i++){
//         if(s[i] == '.') cur++;
//         else if(cur){
//             len.push_back(cur);
//             cur = 0;
//         }
//     }
//     if(cur) len.push_back(cur);

//     for(auto e : len) if(e >= 3){
//         cout << "2\n";
//         return;
//     }
//     int ans = 0;
//     for(auto e : len){
//         ans += e;
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
// int n;


// void solve(){
//     int a[4];
//     int b[4];
//     for(int i = 1;i <= 3;i++) cin >> a[i], b[i] = a[i];
//     sort(a + 1, a + 4);
//     if((a[1] == a[2] && a[2] == a[3]) || (a[2] == a[3] && (a[2] - a[1]) % 2 == 0)){
//         cout << "1 1 1\n";
//         return;
//     }
//     if(a[2] == a[3]){
//         if(b[1] == a[1]){
//             cout << "1 0 0\n";
//         }else if(b[2] == a[1]){
//             cout << "0 1 0\n";
//         }else{
//             cout << "0 0 1\n";
//         }
//         return;
//     }
//     if(b[1] == a[3]){
//         cout << "1 0 0\n";
//     }else if(b[2] == a[3]){
//         cout << "0 1 0\n";
//     }else{
//         cout << "0 0 1\n";
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
// int n;


// void solve(){
//     int a, b, c;
//     cin >> a >> b >> c;
//     if(abs(b-c) % 2 == 0) cout << "1 ";
//     else cout << "0 ";
//     if(abs(a-c) % 2 == 0) cout << "1 ";
//     else cout << "0 ";
//     if(abs(b-a) % 2 == 0) cout << "1\n";
//     else cout << "0\n";
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
// int n;

// void solve(){
//     cin >> n;
//     string s;
//     cin >> s;
//     s = ' ' + s;

//     vector<int>f(n + 5);
//     vector<int>l(n + 5);
//     vector<int>r(n + 5);
//     for(int i = 1;i <= n;i++){
//         cin >> l[i] >> r[i];
//     }

//     auto dfs = [&](auto self, int u) -> void {
//         if(!l[u] && !r[u]) return;
//         int L = l[u], R = r[u];
//         if(l[u] && r[u]){
//             self(self, L);
//             self(self, R);
//             if(s[u] == 'U'){
//                 f[u] = min(f[L], f[R]) + 1;
//             }else if(s[u] == 'L'){
//                 f[u] = min(f[L], f[R] + 1);
//             }else{
//                 f[u] = min(f[L] + 1, f[R]);
//             }
//         }else{
//             if(L){
//                 self(self, L);  
//                 if(s[u] == 'L') f[u] = f[L];
//                 else f[u] = f[L] + 1;
//             }else{
//                 self(self, R);
//                 if(s[u] == 'R') f[u] = f[R];
//                 else f[u] = f[R] + 1;
//             }
//         }
//     };

//     dfs(dfs, 1);

//     cout << f[1] << endl;
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
// int n, val[N];

// void solve(){
//     cin >> n;
//     vector<int>a(n + 5);
//     vector<int>cnt(N);
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     sort(a.begin() + 1, a.begin() + 1 + n);

//     int ans = 0;
//     for(int i = 1;i <= n;i++){
//         int sq = sqrt(a[i]);
//         int t, ct = n - i;
//         for(int j = 1;j <= sq;j++){
//             if(a[i] % j == 0){
//                 t = j;
//                 ans += val[t] * cnt[t] * ct;
//                 cnt[t]++;
//                 if(a[i] % (a[i] / j) == 0 && a[i] / j != j){
//                     t = a[i] / j;  
//                     ans += val[t] * cnt[t] * ct;
//                     cnt[t]++;
//                 }
//             }
//         }
//     }

//     cout << ans << endl;
// }   

// signed main(){

//     IO;

//     for(int i = 1;i <= 1e5;i++) val[i] = i;
//     for(int i = 1;i <= 1e5;i++){
//         for(int j = i + i;j <= 1e5;j += i){
//             val[j] -= val[i];
//         }
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
// const int N = 2e5 + 10;
// int n, m, v[N];
// vector<int>g[N];

// //tarjan
// int dfn[N], scc[N], low[N], tot, stot;
// vector<int>sg[N];
// vector<int>sp[N];
// int siz[N], val[N];
// int st[N], top;
// void tarjan(int u){
//     dfn[u] = low[u] = ++tot;
//     st[++top] = u;
//     for(auto v : g[u]){
//         if(!dfn[v]){
//             tarjan(v);
//             low[u] = min(low[u], low[v]);
//         }else if(!scc[v]){
//             low[u] = min(low[u], low[v]);
//         }
//     }
//     if(low[u] == dfn[u]){
//         sp[++stot].push_back(u);
//         scc[u] = stot;
//         val[stot] += v[u];
//         siz[stot]++;
//         while(st[top] != u){
//             sp[stot].push_back(st[top]);
//             scc[st[top]] = stot;
//             val[stot] += v[st[top]];
//             siz[stot]++;
//             top--;
//         }
//         top--;
//     }

// }

// void init(){
//     for(int i = 1;i <= n;i++){
//         g[i].clear();
//         dfn[i] = scc[i] = low[i] = 0;
//     }
//     for(int i = 1;i <= stot;i++){
//         siz[i] = val[i] = 0;
//         sp[i].clear();
//         sg[i].clear();
//     }
//     tot = 0;
//     stot = 0;
// }

// int cmp(array<int, 2> e1, array<int, 2> e2){
//     if(e1[0] == e2[0]) return e1[1] > e2[1];
//     return e1[0] < e2[0];
// }

// void solve(){
//     cin >> n >> m;
//     init();
//     for(int i = 1;i <= n;i++) cin >> v[i];
//     for(int i = 1, u, v;i <= m;i++){
//         cin >> u >> v;
//         g[u].push_back(v);
//     }

//     for(int i = 1;i <= n;i++) if(!dfn[i]){
//         tarjan(i);
//     }

//     int T = 4;
//     vector<int>vis(stot + 5);
//     for(int i = 1;i <= stot;i++){
//         vis[i] = T;
//         for(auto u : sp[i]){
//             for(auto v : g[u]){
//                 if(vis[scc[v]] != T){
//                     sg[i].push_back(scc[v]);
//                     vis[scc[v]] = T;
//                 }
//             }
//         }
//         T++;
//     }

//     array<int, 2>ans = {0}; //len, val;

//     vector<array<int, 2>>f(stot + 5);
//     for(int i = 1;i <= stot;i++){
//         if(sg[i].size() == 0){
//             f[i] = {siz[i], val[i]};
//         }else{
//             for(auto v : sg[i]){
//                 auto e = f[v];
//                 e[0] += siz[i];
//                 e[1] += val[i];
//                 f[i] = max(f[i], e, cmp);
//             }
//         }
//         ans = max(ans, f[i], cmp);
//     }

//     cout << ans[0] << ' ' << ans[1] << endl;
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

// void init(){
//     for(int i = 1;i <= n;i++){
//         tr[i] = 0;
//     }
// }

// void solve(){
//     cin >> n >> m;
//     init();
//     vector<int>a(n + 5);
//     for(int i = 1;i <= n;i++) cin >> a[i];

//     int q = n, p = 0;
//     set<int>pos;
//     for(int i = 1;i <= n;i++){
//         add(i, a[i]);
//         if(a[i] == 1){
//             pos.insert(i);
//         }
//     }
//     int sum = 0;
//     if(pos.size()){
//         q = *pos.begin();
//         p = *pos.rbegin();
//         sum = getsum(p) - getsum(q - 1);
//     }

//     int op, x, y;
//     while(m--){
//         cin >> op;
//         if(op == 1){
//             cin >> x;
//             if(x <= sum){
//                 cout << "YES\n";
//                 continue;
//             }
//             if(q <= p){
//                 if(x % 2 == sum % 2){
//                     if(sum + (n-p)*2 + (q-1)*2 >= x) cout << "YES\n";
//                     else cout << "NO\n";
//                 }else{
//                     if(sum-1 + max((n-p)*2, (q-1)*2) >= x) cout << "YES\n";
//                     else cout << "NO\n";
//                 }
//                 // if(x == 1){
//                 //     cerr << x << endl;
//                 // }
//             }else{
//                 if(x % 2 == 0 && n*2 >= x) cout << "YES\n";
//                 else cout << "NO\n";
//             }
//         }else{
//             cin >> x >> y;
//             if(a[x] == y) continue;

//             a[x] = y;
//             if(y == 2){
//                 add(x, 1);
//                 pos.erase(pos.find(x));
//                 if(pos.size()){
//                     q = *pos.begin();
//                     p = *pos.rbegin();
//                     sum = getsum(p) - getsum(q - 1);
//                 }else{
//                     q = n, p = 0;
//                     sum = 0;
//                 }
//             }else{
//                 add(x, -1);
//                 pos.insert(x);
//                 q = *pos.begin();
//                 p = *pos.rbegin();
//                 sum = getsum(p) - getsum(q - 1);
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
// const int N = 5e5 + 10;
// int n, m, a[N];
// vector<int>g[N];
// int ans, f[N];

// void dfs(int u, int fa){
//     int sum = 0, cnt = 0, mx = -1e16 - 10, smx = -1e16 - 10, cmx = -1e16 - 10;
//     for(auto v : g[u]) if(v != fa){
//         dfs(v, u);
//         if(f[v] >= 0){
//             cnt++;
//             sum += f[v];
//             cmx = max(cmx, f[v]);
//             if(mx < cmx) swap(cmx, mx);
//         }else{
//             smx = max(smx, f[v]);
//         }
//     }
//     if(cnt > 2){
//         ans = max({ans, f[u] + sum, mx + cmx});
//         f[u] = max(f[u] + sum, mx);
//     }else if(cnt == 2){
//         ans = max({ans, f[u] + mx, f[u] + sum + smx, sum});
//         f[u] = max(f[u] + sum, mx);
//     }else if(cnt == 1){
//         ans = max({ans, f[u] + sum, smx + sum});
//         // ans = max({ans, f[u] + sum});
//         f[u] = max({f[u], mx, f[u] + mx + smx});
//     }else{
//         ans = max(ans, f[u]);
//         f[u] = max(f[u], smx);
//     }
//     // cerr << u << ' ' << ans << endl;
// }

// void init(){
//     for(int i = 1;i <= n;i++){
//         g[i].clear();
//     }
//     ans = 0;
// }

// void solve(){
//     cin >> n;
//     init();
//     for(int i = 1;i <= n;i++) cin >> a[i], f[i] = a[i];
//     for(int i = 1, u, v;i < n;i++){
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }
//     dfs(1, 0);
//     cout << ans << endl;

//     // cerr << endl;
//     // for(int i = 1;i <= n;i++) cerr << i << ' '  << f[i] << endl;
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
// int n, m, k, L[N], R[N];

// int tr[2][N];
// int lowbit(int x){
//     return x & -x;
// }
// void add(int x, int v, int f){
//     int* s = tr[f-1];
//     while(x <= n){
//         s[x] += v;
//         x += lowbit(x);
//     }
// }
// int getsum(int x, int f){
//     int* s = tr[f-1];
//     int ret = 0;
//     while(x > 0){
//         ret += s[x];
//         x -= lowbit(x);
//     }
//     return ret;
// }

// void init(){
//     for(int i = 1;i <= n;i++){
//         tr[0][i] = tr[1][i] = 0;
//     }
// }

// void solve(){
//     cin >> n >> m >> k;
//     init();
//     vector<int>pre(n + 10);
//     vector<array<int, 3>>evt;
//     for(int i = 1;i <= m;i++){
//         cin >> L[i] >> R[i];
//         pre[L[i]]++;
//         pre[R[i]+1]--;
//         evt.push_back({L[i], 0, i});
//         evt.push_back({R[i], 1, i});
//     }
//     sort(evt.begin(), evt.end());
//     int ze = 0;
//     for(int i = 1;i <= n;i++){
//         pre[i] += pre[i-1];
//         if(pre[i] <= 2){
//             if(pre[i]){
//                 add(i, 1, pre[i]);
//             }else{
//                 ze++;
//             }
//         }
//     }
//     int mx = 0, smx = 0;
//     for(int i = 1;i <= m;i++){
//         int s = getsum(R[i], 1) - getsum(L[i] - 1, 1);
//         smx = max(smx, s);
//         if(smx > mx) swap(mx, smx);
//     }
    
//     int ans = ze + smx + mx;

//     set<int>st;

//     auto check = [&]() -> int {
//         int i = *st.begin(), j = *st.rbegin();
//         int l = max(L[i], L[j]);
//         int r = min(R[i], R[j]);
//         int ret = getsum(r, 2) - getsum(l-1, 2);
//         ret += getsum(l-1, 1) - getsum(min(L[i], L[j])-1, 1);
//         ret += getsum(max(R[i], R[j]), 1) - getsum(r, 1);
//         return ret;
//     };

//     for(auto [p, op, id] : evt){
//         if(op == 0){
//             st.insert(id);
//         }else{
//             st.erase(st.find(id));
//         }
//         if(st.size() == 2){
//             ans = max(ans, ze + check());
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
// const int N = 1e6 + 10;
// int n;

// void solve(){
//     cin >> n;
//     vector<int>a(n + 10);
//     vector<int>cnt(n + 10);
//     vector<int>lim(n + 10);
//     for(int i = 1;i <= n;i++) {
//         cin >> a[i];
//         cnt[a[i]]++;
//     }
//     for(int i = 1;i <= n;i++){
//         for(int j = i;j <= n;j += i){
//             lim[j] += cnt[i];
//         }
//     }
//     int ans = 0;
//     vector<int>f(n+10);
//     for(int i = n;i;i--){
//         for(int j = i;j <= n;j += i){
//             f[i] += cnt[j];
//         }
//         f[i] = f[i] * (f[i]-1) / 2;
//         for(int j = i*2;j <= n;j += i){
//             f[i] -= f[j];
//         }
//         if(!lim[i]) ans += f[i];
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
// #define ls id << 1
// #define rs id << 1 | 1
// const int N = 2e5 + 10;
// int n, m, a[N];

// struct inf{
//     int l, r, ll, rr, ok = 0, len;
//     // inf() : 
//     inf operator+ (const inf& e) {
//         inf ret;
//         ret.ok = ok | e.ok;
//         ret.l = l;
//         ret.r = e.r;
//         ret.len = len + e.len;
//         if(r == e.l) ret.ok = 1;
//         if(len > 1){
//             ret.ll = ll;
//             if(rr == e.l) ret.ok = 1;
//         }else{
//             ret.ll = e.l;
//         }
//         if(e.len > 1){
//             ret.rr = e.rr;
//             if(e.ll == r) ret.ok = 1;
//         }else{
//             ret.rr = r;
//         }
//         return ret;
//     }
// };
// struct node{
//     inf v;
//     int tag;
// }tr[N << 2];
// void up(int id){
//     tr[id].v = tr[ls].v + tr[rs].v;
// }
// void build(int id, int l, int r){
//     tr[id] = {0};
//     tr[id].v = {0};
//     tr[id].v.ok = 0;
//     if(l == r){
//         tr[id].v.l = tr[id].v.r = a[l];
//         tr[id].v.len = 1;
//         tr[id].v.ok = 0;
//         // cerr << id << ' ' << l << ' ' << r << ' ' << tr[id].v.ok << endl;
//         return;
//     }
//     int mid = l + r >> 1;
//     build(ls, l, mid);
//     build(rs, mid + 1, r);
//     up(id);
//     // cerr << id << ' ' << l << ' ' << r << ' ' << tr[id].v.ok << endl;
// }
// void settag(int id, int x){
//     tr[id].tag = (tr[id].tag + x) % 26;
//     tr[id].v.l = (tr[id].v.l + x) % 26;
//     tr[id].v.ll = (tr[id].v.ll + x) % 26;
//     tr[id].v.r = (tr[id].v.r + x) % 26;
//     tr[id].v.rr = (tr[id].v.rr + x) % 26;
// }
// void down(int id){
//     settag(ls, tr[id].tag);
//     settag(rs, tr[id].tag);
//     tr[id].tag = 0;
// }
// void modify(int id, int l, int r, int ql, int qr, int x){
//     if(ql <= l && r <= qr){
//         settag(id, x);
//         return;
//     }
//     if(tr[id].tag) down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) modify(ls, l, mid, ql, qr, x);
//     else if(ql > mid) modify(rs, mid + 1, r, ql, qr, x);
//     else modify(ls, l, mid, ql, qr, x), modify(rs, mid + 1, r, ql, qr, x);
//     up(id);
// }
// inf query(int id, int l, int r, int ql, int qr){
//     if(ql <= l && r <= qr){
//         // cerr << id << ' ' << l << ' ' << r << ' ' << tr[id].v.ok << endl;
//         return tr[id].v;
//     }
//     if(tr[id].tag) down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) return query(ls, l, mid, ql, qr);
//     else if(ql > mid) return query(rs, mid + 1, r, ql, qr);
//     else return query(ls, l, mid, ql, qr) + query(rs, mid + 1, r, ql, qr);
// }

// void solve(){
//     cin >> n >> m;
//     string s;
//     cin >> s;
//     s = ' ' + s;
//     for(int i = 1;i <= n;i++){
//         a[i] = s[i] - 'a';
//     }
//     build(1, 1, n);
//     int op, l, r, x;
//     while(m--){
//         cin >> op >> l >> r;
//         if(op == 1){
//             cin >> x;
//             x %= 26;
//             modify(1, 1, n, l, r, x);
//         }else{
//             int ret = query(1, 1, n, l, r).ok;
//             cout << (ret ? "NO\n" : "YES\n");
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


// #include <bits/stdc++.h>
// using namespace std;
// #define Zeoy std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)
// #define all(x) (x).begin(), (x).end()
// #define rson id << 1 | 1
// #define lson id << 1
// #define int long long
// #define mpk make_pair
// #define endl '\n'
// typedef long long ll;
// const int inf = 0x3f3f3f3f;
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;
// const double eps = 1e-9;
// const int N = 4e5 + 10, M = 4e5 + 10;
// const int le = 0;
// const int ri = 1;
// int m, pw[N];

// void solve() {
// 	int n;
// 	cin >> n;
// 	vector<int>l(n + 10);
// 	vector<int>r(n + 10);
// 	vector<array<int, 2>>evt;
// 	for(int i = 1;i <= n;i++){
// 		cin >> l[i] >> r[i];
//         evt.push_back({l[i], le});
//         evt.push_back({r[i], ri});
// 	}
//     sort(all(evt));
//     int cnt = 0, ans = 0, last;
//     for(auto [p, op] : evt){
//         if(op == le){
//             if(cnt){
//                 int len = p - last;
//                 ans = (ans + ((pw[cnt] - 1) * (pw[n-cnt] * len % mod) % mod)) % mod;
//             }
//             cnt++;
//             last = p;
//         }else{
//             if(cnt){
//                 int len = p - last;
//                 ans = (ans + ((pw[cnt] - 1) * (pw[n-cnt] * len % mod) % mod)) % mod;
//             }
//             cnt--;
//             last = p;
//         }
//     }
//     cout << ans << endl;
// }
// signed main(void) {
// 	Zeoy;

// 	pw[0] = 1;
// 	for(int i = 1;i < N;i++){
// 		pw[i] = pw[i-1] * 2 % mod;
// 	}

// 	int Test = 1;
// 	// cin >> Test;
// 	while (Test--)
// 		solve();
// 	return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define ls id << 1
// #define rs id << 1 | 1
// const int N = 2e5 + 10;
// int n, m;



// void solve(){
//     string s;
//     cin >> s;
//     int cur = 1;
//     int ans = 0;
//     for(auto c : s){
//         c = c - '0';
//         if(c == 0) c = 10;
//         ans += abs(cur - c) + 1;
//         cur = c;
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
//     cin >> n >> m;
//     vector<int>a(n + 10);
//     vector<int>b(n + 10);
//     a[1] = 1;
//     for(int i = 2;i <= n;i++) cin >> a[i];
//     for(int i = 1;i <= n;i++) cin >> b[i];
//     sort(a.begin() + 1, a.begin() + 1 + n);
//     sort(b.begin() + 1, b.begin() + 1 + n);
//     int ans = 0;
//     int k = 0;
//     for(int i = 1;i <= n;i++){
//         if(a[k+1] < b[i]) k++;
//     }
//     int bp = n - k + 1, ap = k, p = 1;
//     while(a[p] < m && p <= ap){
//         int d = min(m, b[bp+p-1]) - a[p];
//         // if(a[p] + d == m) d++;
//         ans += (bp-1) * d;
//         a[p] += d;
//         // if(a[p] == m) {
//         //     ans += (bp-1);
//         //     break;
//         // }
//         while(p <= ap && p < n && a[p] > a[p+1]) swap(a[p], a[p+1]), p++;
//         while(p <= ap && a[p] >= b[bp+p-1]){
//             ap--;
//             bp++;
//         }
//     }
//     int d = m - a[p] + 1;
//     ans += (bp-1) * d;
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
// int n, m, k;


// void solve(){
//     cin >> n >> k;
//     vector<int>a(n);
//     for(int i = 0;i < n;i++) cin >> a[i];
//     if(is_sorted(a.begin(), a.end()) || k > 1){
//         cout << "YES\n";
//     }else cout << "NO\n";
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
// int n, m, k;


// void solve(){
//     cin >> n;
//     vector<vector<int>>mp(n, vector<int>(n));
//     vector<int>a(n, (1 << 30)-1);
//     for(auto& vec : mp){
//         for(auto& e : vec) cin >> e;
//     }
//     for(int j = 0;j < n;j++){
//         for(int i = 0;i < n;i++) if(i != j) a[j] &= mp[i][j];
//     }
//     for(int i = 0;i < n;i++){
//         for(int j = 0;j < n;j++)if(i != j){
//             if(mp[i][j] != (a[i] | a[j])){
//                 cout << "NO\n";
//                 return;
//             }
//         }
//     }
//     cout << "YES\n";
//     for(auto e : a) cout << e << ' ';
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
// const int N = 2e5 + 10;
// int n, m, q;


// void solve(){
//     cin >> n >> q;
//     vector<int>a(n + 10);
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     while(q--){
//         vector<int>b(a);
//         int k, ans = 0;
//         cin >> k;
//         for(int i = 61;i >= 0;i--){
//             int nd = 0;
//             for(int j = 1;j <= n;j++){
//                 if(!(b[j] & (1ll<<i))) nd += (1ll<<i) - b[j];
//                 if(nd > k) break;
//             }
//             if(k >= nd){
//                 k -= nd;
//                 ans += (1ll<<i);
//                 for(int j = 1;j <= n;j++){
//                     if(!(b[j] & (1ll<<i))) b[j] = 0;
//                 }
//             }
//             for(int j = 1;j <= n;j++){
//                 if(b[j] & (1ll<<i)) b[j] -= (1<<i);
//             }
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
// // #define endl '\n'
// const int N = 2e5 + 10;
// int n;


// void solve(){
//     cin >> n;
//     int st, ed;
//     cin >> st >> ed;
//     st = ((st ^ ed) & 1);
//     int cnt[2] = {0};
//     set<int>t[2];
//     vector<int>u(n+10);
//     vector<int>v(n+10);
//     for(int i = 1;i <= n;i++){
//         cin >> u[i] >> v[i];
//         int op = (u[i]^v[i])&1;
//         cnt[op]++;
//         t[op].insert(i);
//     }

//     int x;
//     int op;
//     if(cnt[st] >= cnt[st^1]){
//         cout << "First" << endl;
//         op = st ^ 1;
//     }else{
//         cout << "Second" << endl;
//         op = st;
//         cin >> x;
//         int bit = (u[x]^v[x])&1;
//         t[bit].erase(t[bit].find(x));
//     }

//     while(t[0].size() + t[1].size()){
//         if(t[op].size()){
//             cout << *t[op].begin() << endl;
//             t[op].erase(t[op].begin());
//         }else{
//             op ^= 1;
//             cout << *t[op].begin() << endl;
//             t[op].erase(t[op].begin());
//             op ^= 1;
//         }
//         if((t[0].size() + t[1].size()) == 0) break;
//         cin >> x;
//         int bit = (u[x]^v[x])&1;
//         t[bit].erase(t[bit].find(x));
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
// int n, m, k;
// mt19937 rnd(time(0));

// void solve(){
//     cin >> n >> m >> k;
//     vector<string>s(n+10);
//     for(int i = 1;i <= n;i++){
//         cin >> s[i];
//         s[i] = ' ' + s[i];
//     }

//     int sumv = 0;
//     vector<int>v(n+10);
//     for(int i = 1;i <= n;i++){
//         v[i] = rnd();
//         sumv += v[i] * k;
//     }
//     vector<vector<int>>cv(4, vector<int>(m+10));
//     for(int i = 'A';i <= 'D';i++){
//         for(int j = 1;j <= m;j++){
//             for(int k = 1;k <= n;k++){
//                 if(s[k][j] == i) cv[i-'A'][j] += v[k];
//             }
//         }
//     }

//     for(int i = 1;i <= n;i++){
//             int sum = 0;
//         for(int j = 1;j <= m;j++){
//             for(int k = 'A';k <= 'D';k++) if(k != s[i][j]){
//                 sum += cv[k-'A'][j];
//             }
//         }
//             if(sum == sumv - v[i] * k){
//                 cout << i << endl;
//                 return;
//             }
//     }
//     // cerr << "_________\n";
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
// int n, m, k;

// void solve(){
//     cin >> n;
//     string s;
//     cin >> s;
//     for(auto c : s) if(c == '0'){
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
// const int N = 2e5 + 10;
// int n, m, k, p, l, t, ts;

// int val(int x){
//     int cnt = min(ts, x*2);
//     return cnt*t + l*x;
// }

// void solve(){
//     cin >> n >> p >> l >> t;
//     ts = (n + 6) / 7;
//     int L = 1, R = n;
//     while(L <= R){
//         int mid = L + R >> 1;
//         if(val(mid) >= p) R = mid - 1;
//         else L = mid + 1;
//     }
//     cout << n-L << endl;
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
// int n;

// void solve(){
//     cin >> n;
//     vector<int>a(n+10);
//     vector<int>d(n+10);
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     if(n == 1){
//         cout << "1\n";
//         return;
//     }

//     sort(a.begin() + 1, a.begin() + 1 + n);
//     set<int>st;
//     for(int i = 1;i < n;i++){
//         d[i] = a[n] - a[i];
//         st.insert(a[i]);
//     }
//     int gc = d[1];
//     for(int i = 2;i < n;i++){
//         gc = __gcd(gc, d[i]);
//     }
//     int ans = 0;
//     for(int i = 1;i < n;i++){
//         ans += d[i] / gc;
//     }
//     int cur = a[n] - gc;
//     int dd = n*gc;
//     while(1){
//         if(!st.count(cur)){
//             dd = min(dd, (a[n] - cur) / gc);
//             break;
//         }
//         cur -= gc;
//     }
//     cout << ans + dd << endl;
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
// const int N = 1e6 + 10;
// int n;

// int son[N][26], cnt[N], idx;

// void insert(const char s[]) //插入字符串
// {
//   int p = 0;
//   for(int i = 0; s[i]; i++)
//   {
//     int ne = s[i] - 'a';
//     if(!son[p][ne]) son[p][ne] = ++idx;
//     p = son[p][ne];
//     cnt[p]++;
//   }
// }

// int query(const char s[]) //查找字符串出现的次数
// {
//   int p = 0, ret = 0;
//   for(int i = 0; s[i]; i++)
//   {
//     int ne = s[i] - 'a';
//     if(!son[p][ne]) return ret;
//     p = son[p][ne];
//     ret += cnt[p];
//   }
//   return ret;
// }

// void solve(){
//     cin >> n;
//     int ans = 0;
//     vector<string>s(n+10);
//     for(int i = 1;i <= n;i++){
//         cin >> s[i];
//         ans += s[i].size() * n * 2;
//         insert(s[i].c_str());
//         reverse(s[i].begin(), s[i].end());
//     }
//     // cerr << ans << endl;
//     for(int i = 1;i <= n;i++){
//         ans -= query(s[i].c_str()) * 2;
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
// int n, q, x[N], y[N], l[N], r[N];
// array<int, 2>pos[N];
// array<int, 2>op[300];
// array<int, 2> operator+(const array<int,2>& a1, const array<int,2>& a2){
//     array<int, 2>ret(a1);
//     ret[0] += a2[0];
//     ret[1] += a2[1];
//     return ret;
// }
// array<int, 2> operator-(const array<int,2>& a1, const array<int,2>& a2){
//     array<int, 2>ret(a1);
//     ret[0] -= a2[0];
//     ret[1] -= a2[1];
//     return ret;
// }

// struct node{
//     node(int id=0, int op=0, int x=0, int y=0):id(id),op(op),x(x),y(y){};
//     int id, op, x, y;
// };


// void solve(){
//     cin >> n >> q;
//     vector<int>ans(q+10);
//     string s;
//     cin >> s;
//     s = ' ' + s;
//     array<int, 2>p = {0, 0};
//     pos[0] = {0, 0};
//     for(int i = 1;i <= n;i++){
//         p = p + op[s[i]];
//         pos[i] = p;
//     }

//     vector<vector<node>>qur(n+10);
//     for(int i = 1;i <= q;i++){
//         cin >> x[i] >> y[i] >> l[i] >> r[i];
//         qur[l[i]-1].push_back({i, 1, x[i], y[i]});
//             qur[r[i]-1].push_back({i, -1, x[i], y[i]});
//             qur[n].push_back({i, 1, x[i], y[i]});
//         array<int,2>d = {x[i], y[i]};
//         d = d - pos[l[i]-1];
//         d[0] = -d[0];
//         d[1] = -d[1];
//         d = d + pos[r[i]];
//         x[i] = d[0];
//         y[i] = d[1];
//         qur[l[i]-1].push_back({i, -1, x[i], y[i]});
//         qur[r[i]].push_back({i, 1, x[i], y[i]});
//     }

//     map<int,map<int,int>>mp;
//     for(int i = 0;i <= n;i++){
//         mp[pos[i][0]][pos[i][1]]++;
//         for(auto [id, op, x, y] : qur[i]){
//             ans[id] += op * (mp[x][y]);
//         }
//     }

//     for(int i = 1;i <= q;i++){
//         if(ans[i]) cout << "YES\n";
//         else cout << "NO\n";
//     }
// }

// signed main(){

//     IO;

//     op['U'] = {0, 1};
//     op['D'] = {0, -1};
//     op['L'] = {-1, 0};
//     op['R'] = {1, 0};

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
// int n;

// void solve(){
//     cin >> n;
//     vector<int>a(n+10);
//     vector<int>p[2];
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         p[a[i]&1].push_back(i);
//     }
//     if(p[1].size() >= 3){
//         cout << "YES\n";
//         for(int i = 0;i < 3;i++) cout << p[1][i] << ' ';
//         cout << endl;
//     }else if(p[1].size()){
//         if(p[0].size() >= 2){
//             cout << "YES\n";
//             cout << p[1][0] << ' ';
//             for(int i = 0;i < 2;i++) cout << p[0][i] << ' ';
//             cout << endl;
//         }else{
//             cout << "NO\n";
//         }
//     }else{
//         cout << "NO\n";
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
// int n;

// void solve(){
//     cin >> n;
//     vector<int>a(n+10);
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         a[i] += a[i-1];
//     }
//     int ans = 1;
//     for(int i = 1;i < n;i++){
//         ans = max(ans, __gcd(a[i], a[n]-a[i]));
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
// // #define endl '\n'
// const int N = 2e5 + 10;
// int n, v[40] = {0};

// void solve(){
//     int ans = 0;
//     cin >> n;
//     int last = n + 1;
//     do {
//         int gs;
//         if(last - n == 1){
//             gs = v[n];
//             last = n;
//         }else{
//             int d = n - last;
//             gs = v[last];
//             for(int i = 1;i <= d;i++){
//                 gs += v[last+i];
//             }
//             gs += v[last-1];
//             last--;
//         }
//         ans += gs;
//         cout << "- " << gs << endl;
//     }while(cin >> n, n);
//     cout << "! " << ans << endl;
// }


// signed main(){

//     IO;
//     for(int i = 1;i <= 31;i++){
//         v[i] = (1ll<<(i-1));
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
// const int N = 2e5 + 10;
// int n;

// void solve(){
//     cin >> n;
//     vector<int>a(n + 10);
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     int ans = 0;
//     for(int i = 2;i <= n;i++){
//         if(a[i]%2 == a[i-1]%2) ans++;
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
// const int mod = 1e9 + 7;
// int n;

// void solve(){
//     cin >> n;
//     int ret = 1;
//     for(int i = 1;i <= n;i++){
//         ret = ret * i % mod;
//     }
//     ret = ret * n % mod;
//     ret = ret * (n-1) % mod;
//     cout << ret << endl;
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
// const int mod = 1e9 + 7;
// int n, m;
// vector<int>fac[N];

// void solve(){
//     cin >> n >> m;
//     vector<int>a(n+10);
//     vector<int>cnt(m+10);
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//     }
//     sort(a.begin() + 1, a.begin() + 1 + n);
//     int cur = 0, l = 1, ans = a[n] + 10;
//     for(int r = 1;r <= n;r++){
//         for(auto e : fac[a[r]]) if(e <= m){
//             cnt[e]++;
//             if(cnt[e] == 1) cur++;
//         }
//         while(cur == m){
//             ans = min(ans, a[r] - a[l]);
//             for(auto e : fac[a[l]]) if(e <= m){
//                 cnt[e]--;
//                 if(!cnt[e]) cur--;
//             }
//             l++;
//         }
//     }
//     if(ans == a[n] + 10) cout << "-1\n";
//     else cout << ans << endl;
// }


// signed main(){

//     IO;
//     for(int i = 1;i < N;i++){
//         for(int j = i;j < N;j += i){
//             fac[j].push_back(i);
//         }
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
// const int N = 1e5 + 10;
// const int mod = 1e9 + 7;
// int n, m;

// void solve(){
//     cin >> n;
//     vector<vector<int>>g(n+10);
//     vector<int>dep(n+10, 1);
//     for(int i = 1, u, v;i < n;i++){
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }

//     int ans = 0;
//     auto dfs = [&](auto self, int u, int f) -> void {
//         for(auto v : g[u]) if(v != f){
//             self(self, v, u);
//             dep[u] = max(dep[u], dep[v] + 1);
//         }
//         ans = (ans + dep[u]) % mod;
//     };
//     dfs(dfs, 1, 0);

//     for(int i = 1;i < n;i++){
//         ans = ans * 2 % mod;
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