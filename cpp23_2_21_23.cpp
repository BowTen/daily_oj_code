// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// // #define ls id << 1
// // #define rs id << 1 | 1
// const int N = 1e6 + 10;
// const int M = N * 50;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;

// int qpow(int a, int b){
// 	int ret = 1;
// 	while(b){
// 		if(b & 1) ret = ret * a % mod;
// 		a = a * a % mod;
// 		b >>= 1;
// 	}
// 	return ret;
// }

// int fac[N], inv[N];
// void init(){
// 	fac[0] = inv[0] = 1;
// 	for(int i = 1;i < N;i++) fac[i] = fac[i-1] * i % mod;
// 	inv[N-1] = qpow(fac[N-1], mod - 2);
// 	for(int i = N - 2;i >= 1;i--) inv[i] = inv[i+1] * (i+1) % mod;
// }

// int C(int a, int b){
// 	return (fac[a] * inv[a-b] % mod) * inv[b] % mod;
// }


// void solve(){
//     int n;
//     cin >> n;
//     for(int k = 1;k <= (n-1) / 2;k++){
// 		int ans = 1;
// 		for(int x = n-2*k;x >= 1;x -= 2*k){
// 			ans = (ans + ((C(n, x) - C(x + 2*k-1, 2*k-1) + mod) % mod)) % mod;
// 		}
// 		cout << ans << ' ';
//     }
// 	cout << endl;
// }


// signed main(){

// 	IO;

// 	init();

// 	int T = 1;
// 	cin >> T;
// 	while(T--) solve();

// 	return 0;
// }