//#include<bits/stdc++.h>
//using namespace std;
//#define int long long


//void solve(){
//	int n, m;
//	cin >> n >> m;
//	cout << min(2ll, n) << ' ' << min(2ll, m) << '\n';
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//#define int long long


//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5), b(n+5);
//	for(int i = 1;i <= n;i++) cin >> b[i];
//	for(int i = 1;i <= n;i++){
//		a[i] = a[i-1] + b[i];
//		if(b[i] && a[i-1] - b[i] >= 0){
//			cout << "-1\n";
//			return;
//		}
//	}
//	for(int i = 1;i <= n;i++) cout << a[i] << ' ';
//	cout << '\n';
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//#define int long long


//void solve(){
//	int n, k;
//	cin >> n >> k;
//	vector<vector<int>>g(n+5);
//	for(int i = 2, p;i <= n;i++){
//		cin >> p;
//		g[p].push_back(i);
//	}

//	auto check = [&](int d) -> int {
//		vector<int>len(n+5);
//		int cnt = 0;
//		auto dfs = [&](auto self, int u, int fa) -> void {
//			len[u] = 1;
//			for(auto v : g[u]){
//				self(self, v, u);
//				if(len[v] == d && u != 1){
//					len[v] = 0;
//					cnt++;
//				}else{
//					len[u] = max(len[u], len[v]+1);
//				}
//			}
//		};
//		dfs(dfs, 1, 0);
//		return cnt <= k;
//	};

//	int l = 1, r = n-1;
//	while(l <= r){
//		int mid = l + r >> 1;
//		if(check(mid)) r = mid-1;
//		else l = mid+1;
//	}
//	cout << l << '\n';

//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long

//const int mod = 998244353;
//const int N = 63;
//int fac[N], inv[N];
//int qpow(int a, int b){
//	int ret = 1;
//	while(b){
//		if(b & 1) ret = ret * a % mod;
//		a = a * a % mod;
//		b >>= 1;
//	}
//	return ret;
//}
//void init(){
//	fac[0] = inv[0] = 1;
//	for(int i = 1;i < N;i++) fac[i] = fac[i-1] * i % mod;
//	inv[N-1] = qpow(fac[N-1], mod-2);
//	for(int i = N-2;i >= 1;i--) inv[i] = inv[i+1] * (i+1) % mod;
//}
//int C(int a, int b){
//	return (fac[a] * inv[a-b] % mod) * inv[b] % mod;
//}

//void solve(){
//	int n;
//	cin >> n;
//	int a = 0, b = C(n, n/2), c = 1;
//	//for(int i = 1;i*2 <= n;i++){
//	//	int s = n/2 - i-1;
//	//	if(s > 0) (a += C(n-i*2, s)) %= mod;
//	//	if(i & 1){
//	//		s = n/2 - i;
//	//		(a += C(n-i*2, s)) %= mod;
//	//	}
//	//}
//	for(int i=1;i<=n/2;i++) {
//		if(i&1) a=(a+C(n-2*i+1,n/2-i))%mod;
//		else a=(a+C(n-2*i,n/2-i-1))%mod;
//		//cerr<<a<<endl;
//	}
//	b -= a + c;
//	while(b < 0) b += mod;
//	cout << a << ' ' << b << ' ' << c << '\n';
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	init();
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//#define int long long


//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5);
//	int mx = 1;
//	for(int i = 1;i <= n;i++) {
//		cin >> a[i];
//		if(a[i] > a[mx]) mx = i;
//	}
//	cout << mx << '\n';
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//#define int long long


//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5);
//	int p = 1;
//	for(int i = n-2;i >= 1;i--) a[p++] = i;
//	a[p++] = n-1;
//	a[p++] = n;
//	if(n&1){
//		swap(a[n-3], a[n-4]);
//	}
//	for(int i = 1;i <= n;i++) cout << a[i] << ' ';
//	cout << '\n';
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//#define int long long

//int f(int x){
//	int ret = 0;
//	while(x){
//		ret++;
//		x /= 10;
//	}
//	return ret;
//}

//void solve(){
//	int n;
//	cin >> n;
//	map<int,int>ma, mb;
//	for(int i = 1;i <= n;i++){
//		int x;
//		cin >> x;
//		ma[x]++;
//	}
//	for(int i = 1;i <= n;i++){
//		int x;
//		cin >> x;
//		if(ma.count(x) && ma[x] > 0) ma[x]--;
//		else mb[x]++;
//	}

//	int ans = 0;
//	vector<int>ca(10), cb(10);
//	for(auto [k, v] : ma) {
//		if(k > 9){
//			ans += v;
//			ca[f(k)] += v;
//		}else{
//			ca[k] += v;
//		}
//	}
//	for(auto [k, v] : mb) {
//		if(k > 9){
//			ans += v;
//			cb[f(k)] += v;
//		}else{
//			cb[k] += v;
//		}
//	}
//	//cerr << ans << '\n';

//	for(int i = 2;i <= 9;i++){
//		ans += abs(ca[i] - cb[i]);
//		//cerr << ca[i] << ' ' << cb[i] << '\n';
//	}

//	cout << ans << '\n';
//}

//signed main(){

//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}


#include<bits/stdc++.h>
using namespace std;
#define int long long

const int inf = 1e15;

int exgcd(int a, int b, int &x, int &y){
	if(b == 0){
		x = 1, y = 0;
		return a;
	}
	int x0, y0;
	int d = exgcd(b, a%b, x0, y0);
	x = y0;
	y = x0 - (a/b)*y0;
	return d;
}

void solve(){
	int n, m;
	cin >> n;
	vector<int>a(n+5), b(n+5), c(n+5);
	int sum = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> b[i];
		sum += a[i];
		c[i] = b[i] - a[i];
	}
	sort(c.begin()+1, c.begin()+1+n, greater<int>());
	for(int i = 1;i <= n;i++) c[i] += c[i-1];

	cin >> m;
	while(m--){
		int x, y;
		cin >> x >> y;
		if(n % gcd(x, y)) {
			cout << "-1\n";
			continue;
		}
		int p1, p2;
		int gc = exgcd(x, y, p1, p2);
		p1 *= n/gc;
		p2 *= n/gc;
		int d1 = y/gc, d2 = x/gc;

		int k = 0;
		if(p2 < 0){
			k = -(0-p2 + d2-1)/d2;
		}else{
			k = p2/d2;
		}

		p1 += d1*k;
		p2 -= d2*k;
		if(p1 < 0){
			cout << "-1\n";
			continue;
		}

		k = p1/d1;
		int l = 0, r = k;
		while(r-l > 2){
			int mid = l + r >> 1;
			int i1 = (mid*d2+p2)*y, i2 = ((mid+1)*d2+p2)*y;
			if(c[i2] > c[i1]) l = mid+1;
			else r = mid;
		}
		int ans = -inf;
		for(int i = l;i <= r;i++){
			ans = max(ans, c[(p2+i*d2)*y]);
		}

		cout << sum + ans << '\n';
	}
}

signed main(){

	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t = 1;
	//cin >> t;
	while(t--) solve();

	return 0;
}