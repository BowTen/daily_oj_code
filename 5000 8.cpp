#define _CRT_SECURE_NO_WARNINGS
#define _SILENCE_CXX20_CISO646_REMOVED_WARNING
#define BowTen                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

// #include<bits/stdc++.h>
//  using namespace std;
//  typedef long long ll;
//  const int N = 1e6 + 5;
//  int n, q;
//  ll t[N];
//
//  int lowbit(int x) {
//	return x & -x;
// }
//
//  void add(int i, ll val) {
//	while (i <= n) {
//		t[i] += val;
//		i += lowbit(i);
//	}
// }
//
//  ll getsum(int i) {
//	ll ret = 0;
//	while (i >= 1) {
//		ret += t[i];
//		i -= lowbit(i);
//	}
//	return ret;
// }
//
//  int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//
//	cin >> n >> q;
//	for (int i = 1, a[2] = { 0 }; i <= n; i++) {
//		cin >> a[i & 1];
//		add(i, a[i&1] - a[~i&1]);
//	}
//
//	int f, l, r, x;
//	while (q--) {
//		cin >> f >> l;
//		if (f == 1) {
//			cin >> r >> x;
//			add(l, x);
//			add(r + 1, -x);
//		}
//		else
//			cout << getsum(l) << '\n';
//	}
//
//	return 0;
// }

////#include<bits/stdc++.h>
////using namespace std;
////typedef long long ll;
////const int N = 1e6 + 5;
////int n, q;
////ll t1[N], t2[N];
////
////int lowbit(int x) {
////	return x & -x;
////}
////
////void add(int i, ll val) {
////	ll val2 = i * val;
////	while (i <= n) {
////		t1[i] += val;
////		t2[i] += val2;
////		i += lowbit(i);
////	}
////}
////
////ll getsum(int i) {
////	ll s1 = 0, s2 = 0, r = i + 1;
////	while (i >= 1) {
////		s1 += t1[i];
////		s2 += t2[i];
////		i -= lowbit(i);
////	}
////	return r * s1 - s2;
////}
////
////int main()
////{
////	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
////
////	cin >> n >> q;
////	for (int i = 1, a[2] = { 0 }; i <= n; i++) {
////		cin >> a[i & 1];
////		add(i, a[i & 1] - a[~i & 1]);
////	}
////
////	int f, l, r, x;
////	while (q--) {
////		cin >> f >> l >> r;
////		if (f == 1) {
////			cin >> x;
////			add(l, x);
////			add(r + 1, -x);
////		}
////		else
////			cout << getsum(r) - getsum(l-1) << '\n';
////	}
////
////	return 0;
////}

// #include<bits/stdc++.h>
//  using namespace std;
//
//  int main()
//{
//	int t;
//	cin >> t;
//	while (t--) {
//		int n;
//		cin >> n;
//		vector<int>vec;
//		map<int, int>mp;
//		int ans;
//		for (int i = 1, t; i <= n; i++) {
//			cin >> t;
//			vec.push_back(t);
//			mp[t]++;
//		}
//		for(int i = 0;i < n;i++)
//			if (mp[vec[i]] == 1)
//				ans = vec[i];
//		for(int i = 0;i < n;i++)
//			if (vec[i] == ans) {
//				cout << i + 1 << '\n';
//				break;
//			}
//
//	}
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
//  int n, x[3],y[3];
//  char s[410][410];
//
//  void init() {
//	memset(s, 0, sizeof s);
//	memset(x, 0, sizeof x);
//	memset(y, 0, sizeof y);
// }
//
//  int main()
//{
//	int t;
//	cin >> t;
//	while (t--) {
//		init();
//		cin >> n;
//		for (int i = 1, id = 1; i <= n; i++)
//			for (int j = 1; j <= n; j++) {
//				cin >> s[i][j];
//				if (s[i][j] == '*') {
//					x[id] = i;
//					y[id] = j;
//					id = 2;
//				}
//			}
//
//		int a1 = x[1], a2 = x[2], b1 = y[1], b2 = y[2];
//		if (x[1] == x[2]) {
//			if (x[1] == 1) {
//				a1++;
//				a2++;
//			}
//			else {
//				a1--;
//				a2--;
//			}
//		}
//		else if (y[1] == y[2]) {
//			if (y[1] == 1) {
//				b1++;
//				b2++;
//			}
//			else {
//				b1--;
//				b2--;
//			}
//		}
//		else {
//			a1 = x[2];
//			b1 = y[1];
//			a2 = x[1];
//			b2 = y[2];
//		}
//		s[a1][b1] = s[a2][b2] = '*';
//
//		for (int i = 1, id = 1; i <= n; i++) {
//			for (int j = 1; j <= n; j++)
//				cout << s[i][j];
//			cout << '\n';
//		}
//
//	}
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
//  const int N = 2e5 + 5;
//  int n, a, b;
//  string s;
//
//  void init() {
// }
//
//  int main()
//{
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> a >> b;
//		int s1 = b, s0 = a;
//		n = a + b;
//		cin >> s;
//		for (int i = 0; i < n; i++)
//			if (s[i] == '1')
//				s1--;
//			else if (s[i] == '0')
//				s0--;
//		s = " " + s;
//
//
//		for (int q = 1, p = n; q <= p; q++, p--) {
//			if ((s[q] != s[p] && s[q] != '?' && s[p] != '?') || (s1 < 0 || s0 < 0)) {
//				cout << "-1\n";
//				goto ss;
//			}
//
//			if (s[q] == s[p] && s[q] == '?') {
//				if (p == q) {
//					if (s1 > 0) {
//						s1--;
//						s[q] = '1';
//					}
//					else if (s0 > 0) {
//						s0--;
//						s[q] = '0';
//					}
//				}
//				else if (s1 >= 2) {
//					s1 -= 2;
//					s[q] = s[p] = '1';
//				}
//				else if (s0 >= 2) {
//					s0 -= 2;
//					s[q] = s[p] = '0';
//				}
//				else {
//					cout << "-1\n";
//					goto ss;
//				}
//
//				continue;
//			}
//
//			if (s[q] == '?') {
//				if (s[p] == '0') {
//					s[q] = '0';
//					s0--;
//				}
//				else {
//					s[q] = '1';
//					s1--;
//				}
//			}
//
//			if (s[p] == '?') {
//				if (s[q] == '0') {
//					s[p] = '0';
//					s0--;
//				}
//				else {
//					s[p] = '1';
//					s1--;
//				}
//			}
//		}
//		for (int i = 1; i <= n; i++)
//			cout << s[i];
//		cout << '\n';
//	ss:;
//	}
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
//  typedef long long ll;
//  const int N = 2e5 + 5;
//  int n, a, b;
//
//  void init() {
// }
//
//  int main()
//{
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> n;
//		vector<int>num(n+2);
//		for (int i = 0; i < n+2; i++)
//			cin >> num[i];
//
//		sort(num.begin(), num.end());
//		ll s = 0;
//		for (int i = 0; i < n; i++)
//			s += num[i];
//		if (s == num[n]) {
//			for (int i = 0; i < n; i++)
//				cout << num[i] << ' ';
//			cout << '\n';
//			continue;
//		}
//
//		s += num[n];
//		int flag = -1;
//		for(int i = 0;i <= n;i++)
//			if (s - num[i] == num[n + 1]) {
//				flag = i;
//				break;
//			}
//
//		if (flag == -1) {
//			cout << "-1\n";
//			continue;
//		}
//		for (int i = 0; i <= n; i++) {
//			if (i == flag) continue;
//			cout << num[i] << ' ';
//		}
//		cout << '\n';
//	}
//	return 0;
// }

//
// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// const int N = 2e5 + 5;
// int n;
//
// void init() {
//}
//
// int main()
//{
//	int t;
//	cin >> t;
//	while (t--) {
//		int f[4], f2[4], f3[4] = { 0 };
//		cin >> n;
//		for (int i = 0; i < 4; i++) {
//			cin >> f[i];
//			f2[i] = f[i];
//		}
//
//		for (int i = 0; i < 4; i++) {
//			if (f[i] == n) {
//				f3[i + 1 > 3 ? 0 : i + 1]++;
//				f3[i - 1 < 0 ? 3 : i - 1]++;
//			}
//		}
//		for (int i = 0; i < 4; i++) {
//			if (f[i] == n - 1) {
//				if(f3[(i + 1) % 4] < f[(i + 1) % 4])
//					f3[i + 1 > 3 ? 0 : i + 1]++;
//				else
//					f3[i - 1 < 0 ? 3 : i - 1]++;
//			}
//		}
//
//		for (int i = 0; i < 4; i++) {
//			if (f3[i] > f[i]) {
//				cout << "NO\n";
//				goto ss;
//			}
//		}
//		cout << "YES\n";
//	ss:;
//	}
//	return 0;
//}

// #include<bits/stdc++.h>
//  using namespace std;
//  typedef long long ll;
//  const int N = 2e5 + 5;
//  int n;
//
//
//  int main()
//{
//	int t;
//	cin >> t;
//	while (t--) {
//		char a = 'A', b = 'B', c = 'C';
//		int vis[3] = { 0 };
//		map<char, int>ch;
//		map<char, char>fh;
//		map<char, int>num;
//		string s;
//		cin >> s;
//		n = s.length();
//		for (int i = 0; i < n; i++)
//			ch[s[i]]++;
//
//		if ((ch[a] != ch[b] + ch[c] && ch[b] != ch[a] + ch[c] && ch[c] != ch[a] + ch[b]) || s[0] == s[n - 1]) {
//			cout << "NO\n";
//			continue;
//		}
//
//		fh[s[0]] = '(';
//		fh[s[n - 1]] = ')';
//		char les = ch[s[0]] < ch[s[n - 1]] ? '(' : ')';
//		vis[s[0] - 'A'] = 1;
//		vis[s[n - 1] - 'A'] = 1;
//		for (int i = 0; i < 3; i++)
//			if (!vis[i])
//				fh['A' + i] = les;
//
//		for (int i = 0; i < n; i++) {
//			num[fh[s[i]]]++;
//			if (num['('] < num[')']) {
//				cout << "NO\n";
//				goto ss;
//			}
//		}
//		cout << "YES\n";
//	ss:;
//	}
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
//  typedef long long ll;
//  const int N = 2e5 + 5;
//  int n, a, b;
//
//
//  int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> a >> b;
//		n = a + b;
//		string s;
//		cin >> s;
//		for (int i = 0; i < n; i++)
//			if (s[i] == '0')
//				a--;
//			else if (s[i] == '1')
//				b--;
//
//		for (int q = 0, p = n - 1; q <= p; q++, p--) {
//			if (s[q] == '?' && s[p] != '?') {
//				if (s[p] == '0')
//					a--;
//				else
//					b--;
//				s[q] = s[p];
//				continue;
//			}
//
//			if (s[q] != '?' && s[p] == '?') {
//				if (s[q] == '0')
//					a--;
//				else
//					b--;
//				s[p] = s[q];
//			}
//		}
//
//		for (int q = 0, p = n - 1; q <= p; q++, p--) {
//			if (p == q && s[p] == '?') {
//				if (a > 0) {
//					a--;
//					s[p] = '0';
//				}
//				else {
//					b--;
//					s[p] = '1';
//				}
//			}
//			else if (s[q] == s[p] && s[p] == '?') {
//				if (a >= 2) {
//					a -= 2;
//					s[p] = s[q] = '0';
//				}
//				else {
//					b -= 2;
//					s[p] = s[q] = '1';
//				}
//			}
//		}
//		int ans = 1;
//		for (int q = 0, p = n - 1; q <= p && ans; q++, p--) {
//			if (s[q] != s[p])
//				ans = 0;
//		}
//
//		if (ans && a == 0 && b == 0)
//			cout << s << '\n';
//		else
//			cout << "-1\n";
//	}
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
//  typedef long long ll;
//  const int N = 2e5 + 5;
//  int n, a, b;
//
//
//  int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int t;
//	cin >> t;
//	while (t--) {
//		unordered_map<char, int>num;
//		unordered_map<char, char>kh;
//		unordered_map<char, int>word;
//		string s;
//		cin >> s;
//		n = s.length();
//		for (int i = 0; i < n; i++)
//			word[s[i]]++;
//
//
//		kh[s[0]] = '(';
//		kh[s[n - 1]] = ')';
//		char les = word[s[0]] < word[s[n - 1]] ? kh[s[0]] : kh[s[n - 1]];
//		for(int i = 0;i < 3;i++)
//			if ('A' + i != s[0] && 'A' + i != s[n - 1]) {
//				kh['A' + i] = les;
//			}
//
//		if (s[0] == s[n - 1]) {
//			cout << "NO\n";
//			goto ss;
//		}
//
//		for (int i = 0; i < n; i++) {
//			num[kh[s[i]]]++;
//			if (num['('] < num[')']) {
//				cout << "NO\n";
//				goto ss;
//			}
//		}
//
//		if (num['('] != num[')'])
//			cout << "NO\n";
//		else
//			cout << "YES\n";
//	ss:;
//	}
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
//  typedef long long ll;
//  const int N = 2e5 + 5;
//  int n, l, r, s, sm, no;
//  int sum[500];
//
//
//  int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int t;
//	cin >> t;
//	for (int i = 1; i <= 500; i++)
//		sum[i] = sum[i - 1] + i;
//	while (t--) {
//		cin >> n >> l >> r >> s;
//		vector<int>vis(n+1);
//		sm = r - l + 1;
//		for (int i = 1; i <= sm; i++)
//			vis[i] = 1;
//		no = sum[sm];
//
//		if (no > s) {
//			cout << "-1\n";
//			continue;
//		}
//
//		for (int i = 1; i <= sm; i++) {
//			for (int j = n; j > i; j--) {
//				if (vis[j]) continue;
//				if (no + j - i <= s) {
//					no += j - i;
//					vis[i] = 0;
//					vis[j] = 1;
//					break;
//				}
//			}
//		}
//
//		if (no == s) {
//			int cnt = 1, p = 1;
//			for (p; p <= n; p++)
//				if (!vis[p]) {
//					if (cnt >= l)
//						break;
//					cout << p << ' ';
//					cnt++;
//				}
//			for (int i = 1; i <= n; i++)
//				if (vis[i]) cout << i << ' ';
//			for (p; p <= n; p++)
//				if (!vis[p]) cout << p << ' ';
//			cout << '\n';
//		}
//		else
//			cout << "-1\n";
//	}
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
//  typedef long long ll;
//  const int N = 2e5 + 5;
//  ll n, c, a[N], b[N];
//  ll da[N], mo[N], fas[N];
//
//
//  int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--) {
//		scanf("%lld %lld", &n, &c);
//		for (int i = 1; i <= n; i++)
//			scanf("%lld", &a[i]);
//		for (int i = 1; i < n; i++)
//			scanf("%lld", b + i);
//		ll pos = 1, cur = 1, fund = 0;
//		da[1] = mo[1] = 0;
//		fas[pos] = ((c - mo[pos]) / a[pos]) + ((c - mo[pos]) % a[pos] == 0 ? 0 : 1) + da[pos];
//		ll ans = fas[1];
//		for (cur; pos < n; cur++) {
//			if (fund >= b[pos]) {
//				fund -= b[pos];
//				pos++;
//				da[pos] = cur;
//				mo[pos] = fund;
//				fas[pos] = ((c - mo[pos]) / a[pos]) + ((c - mo[pos]) % a[pos] == 0 ? 0 : 1) + da[pos];
//				ans = ans < fas[pos] ? ans : fas[pos];
//			}
//			else {
//				ll t = (b[pos] - fund) / a[pos] + ((b[pos] - fund) % a[pos] == 0 ? 0 : 1);
//				fund += t * a[pos];
//				cur += t - 1;
//			}
//		}
//		printf("%lld\n", ans);
//
//	}
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
//  typedef long long ll;
//  const int N = 1e7 + 5;
//  ll c, b[N], ans[N];
//
//  int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	for (int i = 1; i < N; i++)
//		for (int j = i; j < N; j += i)
//			b[j] += i;
//
//	for (int i = 1; i < N; i++)
//		if (b[i] < N && !ans[b[i]])
//			ans[b[i]] = i;
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> c;
//		if (ans[c])
//			cout << ans[c] << '\n';
//		else
//			cout << "-1\n";
//	}
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
//  int n, m, c, t;
//
//  int main()
//{
//	cin >> n >> m;
//	map<int, pair<int ,int > >mp;
//	for (int i = 1; i <= n; i++) {
//		cin >> c >> t;
//		if (t > mp[c].second) {
//			mp[c] = { i,t };
//		}
//	}
//	for (int i = 1; i <= m; i++) {
//		cout << mp[i].first << ' ';
//	}
//
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
//  const int N = 1e3 + 5;
//  typedef long long ll;
//  struct bug {
//	ll x, y, h, id;
// };
//  vector<bug>b;
//  ll n, ans[N], x, y, atk, h, r, sb, f;
//
//
//  void die(int x) {
//	ans[b[x].id] = 1;
//	b.erase(b.begin() + x);
//	sb--;
// }
//
//
//  int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cin >> f >> x >> y;
//		if (f == 1) {
//			cin >> h;
//			b.push_back({ x,y,h,i });
//			sb++;
//		}
//		else {
//			cin >> atk >> r;
//			if (!sb)
//				continue;
//			ll m = -1, mn = 0;
//			for (int j = 0, si = b.size(); j < si;j++) {
//				ll dis = (b[j].x - x) * (b[j].x - x) + (b[j].y - y) * (b[j].y - y);
//				if (dis < mn || m == -1) {
//					mn = dis;
//					m = j;
//				}
//			}
//
//			x = b[m].x;
//			y = b[m].y;
//			bool flag = 0;
//			for (int j = 0, si = b.size(); j < si; j++) {
//				ll dis = (b[j].x - x) * (b[j].x - x) + (b[j].y - y) * (b[j].y - y);
//				if (dis <= r*r) {
//					b[j].h -= 3 * atk;
//					if (b[j].h <= 0)
//						die(j), j--, si--;
//					else
//						flag = 1;
//				}
//			}
//			if (flag) {
//				ans[i] = 1;
//			}
//		}
//	}
//	for (int i = 1; i <= n; i++)
//		if (ans[i])
//			cout << "NO\n";
//		else
//			cout << "YES\n";
//	return 0;
// }

// 5
// 2 1 0 1 1
// 2 1 0 1 1
// 2 1 0 1 1
// 1 0 0 4
// 1 0 1 8

// #include<bits/stdc++.h>
//  using namespace std;
//  typedef long long ll;
//  const int N = 2e3 + 5;
//  ll n,x,y,h,ak,f,r,ans[N];
//  struct bug {
//	ll x, y, h, id;
// };
//  vector<bug>b;
//
//  int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cin >> f >> x >> y;
//		if (f == 1) {
//			cin >> h;
//			b.push_back({ x,y,h,i });
//		}
//		else {
//			cin >> ak >> r;
//			if (!b.size())
//				continue;
//
//			ll m = -1, mn = 0;
//			for (int j = 0, si = b.size(); j < si; j++) {
//				ll dis = (b[j].x - x) * (b[j].x - x) + (b[j].y - y) * (b[j].y - y);
//				if (dis < mn || m == -1)
//					mn = dis, m = j;
//			}
//
//			x = b[m].x;
//			y = b[m].y;
//
//			int flag = 0;
//			for (int j = 0, si = b.size(); j < si; j++) {
//				ll dis = (b[j].x - x) * (b[j].x - x) + (b[j].y - y) * (b[j].y - y);
//				if (dis <= r * r) {
//					b[j].h -= ak * 3;
//					if (b[j].h <= 0) {
//						ans[b[j].id] = 1;
//						b.erase(b.begin() + j);
//						j--;
//						si--;
//					}
//					else
//						flag = 1;
//				}
//			}
//			if (flag)
//				ans[i] = 1;
//		}
//	}
//	for (int i = 1; i <= n; i++)
//		if (ans[i])
//			cout << "NO\n";
//		else
//			cout << "YES\n";
//
//	return 0;
// }

// 5
// 2 1 0 1 1
// 2 1 0 1 1
// 1 0 0 3
// 2 1 0 1 1
// 1 0 1 8

// #include<bits/stdc++.h>
//  using namespace std;
// #define endl '\n'
// #define Acode ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
//  typedef long long ll;
//  const int inf = 0x3f3f3f3f;
//  const int N = 1e6 + 20;
//  ll n, m;
//  ll p[N], d[N];
//  ll dp[N];
//  int main()
//{
//	scanf("%lld %lld", &n, &m);
//	for (int i = 1; i <= n; ++i)
//		scanf("%lld", p+i);
//	for (int i = 1; i <= n; ++i)
//		scanf("%lld", d + i);
//	for (int i = 1; i <= n; i++)
//		for (int j = 0; j <= m; j++)
//			dp[j] = max(dp[j*d[i]]+j*d[i]*p[i], dp[j]);
//	printf("%lld\n", dp[m]);
//
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
//  const int N = 1e6 + 5;
//  typedef long long ll;
//  ll n, k, s = 1, a[N], b[N], w[N], sub[N << 1], pre[N << 1], len, val[N<<1];
//  struct node {
//	ll val, id, f;
// };
//
//
//  int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	cin >> n >> k;
//	vector<node>num(n << 1);
//	for (int i = 1,j = 0; i <= n; i++) {
//		cin >> a[i] >> b[i] >> w[i];
//		num[j++] = { a[i],i,1 };
//		num[j++] = { b[i],i,2 };
//	}
//	sort(num.begin(), num.end(), [](node e1, node e2)->int {return e1.val < e2.val; });
//	ll s = 1;
//	for (int i = 0, si = num.size(); i < si; i++) {
//		if (i < si - 1 && num[i].val == num[i + 1].val)
//			num[i].val = s;
//		else
//			num[i].val = s++;
//		if (num[i].f == 1) a[num[i].id] = num[i].val;
//		else b[num[i].id] = num[i].val;
//	}
//	len = s;
//	for (int i = 1; i <= n; i++) {
//		sub[a[i]]++;
//		sub[b[i] + 1]--;
//		for (int j = a[i]; j <= b[i]; j++)
//			val[j] ^= w[i];
//	}
//	for (int i = 1; i <= len; i++) {
//		sub[i] += sub[i-1];
//	}
//	int ans = -1;
//	for (int i = 1; i <= len; i++) {
//		if (sub[i] >= k && (ans == -1 || val[i] > ans))
//			ans = val[i];
//	}
//
//	cout << ans;
//
//
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
//  const int N = 1e6 + 5;
//  int a,b;
//
//  int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> a >> b;
//		if (abs(a) == abs(b))
//			cout << max(abs(a), abs(b))*2 << '\n';
//		else
//			cout << max(abs(a), abs(b))*2 - 1 << '\n';
//	}
//
//
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
//  const int N = 1e6 + 5;
//  typedef long long ll;
//  ll n, k, s = 1, a[N], b[N], w[N], sub[N << 1], pre[N << 1], len, val[N << 1];
//  struct node {
//	ll val, id, f;
// };
//
//
//  int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	cin >> n >> k;
//	vector<node>num(n << 1);
//	for (int i = 1, j = 0; i <= n; i++) {
//		cin >> a[i] >> b[i] >> w[i];
//		num[j++] = { a[i],i,1 };
//		num[j++] = { b[i],i,2 };
//	}
//	sort(num.begin(), num.end(), [](node e1, node e2)->int {return e1.val < e2.val; });
//	ll s = 1;
//	for (int i = 0, si = num.size(); i < si; i++) {
//		if (i < si - 1 && num[i].val == num[i + 1].val)
//			num[i].val = s;
//		else
//			num[i].val = s++;
//		if (num[i].f == 1) val[num[i].val] ^= w[num[i].id], sub[num[i].val]++;
//		else val[num[i].val + 1] ^= w[num[i].id], sub[num[i].val + 1]--;
//	}
//	len = s;
//	for (int i = 1; i <= len; i++) {
//		sub[i] += sub[i - 1];
//		val[i] ^= val[i - 1];
//	}
//	int ans = -1;
//	for (int i = 1; i <= len; i++) {
//		if (sub[i] >= k && (ans == -1 || val[i] > ans))
//			ans = val[i];
//	}
//
//	cout << ans;
//
//
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
//  const int N = 1e6 + 5;
//  typedef long long ll;
//  ll n, k, s = 1, a[N], b[N], w[N], sub[N << 1], len, val[N << 1];
//  vector<ll>num;
//
//  int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	cin >> n >> k;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i] >> b[i] >> w[i];
//		num.push_back(a[i]);
//		num.push_back(b[i]+1);
//	}
//	sort(num.begin(), num.end());
//	num.erase(unique(num.begin(), num.end()), num.end());
//	for (int i = 1; i <= n; i++) {
//		ll ai = lower_bound(num.begin(), num.end(), a[i]) - num.begin() + 1;
//		ll bi = lower_bound(num.begin(), num.end(), b[i]+1) - num.begin() + 1;
//		sub[ai]++;
//		sub[bi]--;
//		val[ai] ^= w[i];
//		val[bi] ^= w[i];
//	}
//	len = num.size();
//	ll s = 0, v = 0, ans = -1;
//	for (int i = 1; i <= len; i++) {
//		sub[i] += sub[i-1];
//		val[i] ^= val[i-1];
//		if (sub[i] >= k && (val[i] > ans || ans == -1))
//			ans = val[i];
//	}
//	cout << ans;
//
//	return 0;
// }

// 2 2
// 1 1 8
// 1 1 4

// #include<bits/stdc++.h>
//  using namespace std;
//  typedef long long ll;
//  const int N = 1e5 + 5;
//  int T[N], n, q;
//
//  int lowbit(int x) {
//	return x & -x;
// }
//
//  void add(int i, int val) {
//	while (i <= n) {
//		T[i] += val;
//		i += lowbit(i);
//	}
// }
//
//  ll getsum(int i) {
//	ll ret = 0;
//	while (i >= 1) {
//		ret += T[i];
//		i -= lowbit(i);
//	}
//	return ret;
// }
//
//  void init() {
//	memset(T, 0, sizeof T);
// }
//
//  int main()
//{
//	int t;
//	cin >> t;
//	for (int i = 1; i <= t;i++) {
//		cout << "Case " << i << ":\n";
//		init();
//		cin >> n >> q;
//		for (int j = 1, val; j <= n; j++) {
//			cin >> val;
//			add(j, val);
//		}
//		int f, a, b;
//		while (q--) {
//			cin >> f;
//			if (f == 1) {
//				cin >> a;
//				a++;
//				ll sum = getsum(a) - getsum(a - 1);
//				add(a, -sum);
//				cout << sum << '\n';
//			}
//			else if (f == 2) {
//				cin >> a >> b;
//				a++;
//				add(a, b);
//			}
//			else {
//				cin >> a >> b;
//				a++;
//				b++;
//				cout << getsum(b) - getsum(a - 1) << '\n';
//			}
//		}
//		//for (int j = 1; j <= n; j++)
//		//	cout << getsum(j) << " ";
//	}
//
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
//  typedef long long ll;
//  struct node {
//	ll sum;
//	int l, r;
// };
//  const int N = 1e5 + 5;
//  int n, q, a[N];
//  node T[N << 2];
//
//  void up(int id) {
//	T[id].sum = T[id << 1].sum + T[id << 1 | 1].sum;
// }
//
//  void build(int id, int ql, int qr) {
//	T[id].l = ql;
//	T[id].r = qr;
//	if (ql == qr) {
//		T[id].sum = a[ql];
//		return;
//	}
//	int mid = (ql + qr) >> 1;
//	build(id << 1, ql, mid);
//	build(id << 1 | 1, mid + 1, qr);
//	up(id);
// }
//
//  void change(int id, int x, int val) {
//	int l = T[id].l;
//	int r = T[id].r;
//	if (l == r) {
//		T[id].sum += val;
//		return;
//	}
//	int mid = (l+r) >> 1;
//	if (x <= mid)
//		change(id << 1, x, val);
//	else
//		change(id << 1 | 1, x, val);
//	up(id);
// }
//
//  ll query(int id, int ql, int qr) {
//	int l = T[id].l;
//	int r = T[id].r;
//	if (ql <= l && qr >= r)
//		return T[id].sum;
//	int mid = (l + r) >> 1;
//	if (qr <= mid)
//		return query(id << 1, ql, qr);
//	else if (ql > mid)
//		return query(id << 1 | 1, ql, qr);
//	else
//		return query(id << 1, ql, qr) + query(id << 1 | 1, ql, qr);
// }
//
//  void init() {
//	memset(T, 0, sizeof T);
//	memset(a, 0, sizeof a);
// }
//
//  int main()
//{
//	int t, cnt = 1;;
//	cin >> t;
//	while (t--) {
//		init();
//		cout << "Case " << cnt++ << ":\n";
//		cin >> n >> q;
//		for (int i = 0; i < n; i++)
//			cin >> a[i];
//		build(1, 0, n - 1);
//
//		int f, t1, t2;
//		while (q--) {
//			cin >> f;
//			if (f == 1) {
//				cin >> t1;
//				ll sm = query(1, t1, t1);
//				cout << sm << "\n";
//				change(1, t1, -sm);
//			}
//			else if(f == 2) {
//				cin >> t1 >> t2;
//				change(1, t1, t2);
//			}
//			else {
//				cin >> t1 >> t2;
//				cout << query(1, t1, t2) << '\n';
//			}
//		}
//	}
//
//
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
//  typedef long long ll;
//  const int N = 5e4 + 5;
//  int n, q, a[N];
//  struct node {
//	int max, l, r;
// };
//  node seg[N << 2];
//
//  void up(int id) {
//	seg[id].max = max(seg[id << 1].max, seg[id << 1 | 1].max);
// }
//
//  void build(int id, int ql, int  qr) {
//	seg[id].l = ql;
//	seg[id].r = qr;
//	if (ql == qr) {
//		seg[id].max = a[ql];
//		return;
//	}
//	int mid = (ql + qr) >> 1;
//	build(id << 1, ql, mid);
//	build(id << 1 | 1, mid + 1, qr);
//	up(id);
// }
//
//  void change(int id, int x, int val) {
//	int l = seg[id].l;
//	int r = seg[id].r;
//	if (l == r) {
//		seg[id].max = val;
//		return;
//	}
//	int mid = (l + r) >> 1;
//	if (x <= mid)
//		change(id << 1, x, val);
//	else if (x > mid)
//		change(id << 1 | 1, x, val);
//	up(id);
// }
//
//  int getmax(int id, int ql, int qr) {
//	int l = seg[id].l;
//	int r = seg[id].r;
//	if (ql <= l && qr >= r)
//		return seg[id].max;
//	int mid = (l + r) >> 1;
//	if (qr <= mid)
//		return getmax(id << 1, ql, qr);
//	else if (ql > mid)
//		return getmax(id << 1 | 1, ql, qr);
//	else
//		return max(getmax(id << 1, ql, qr), getmax(id << 1 | 1, ql, qr));
// }
//
//
//  int main()
//{
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//		cin >> a[i];
//	build(1, 1, n);
//
//	int f, x, y;
//	cin >> q;
//	while (q--) {
//		cin >> f >> x >> y;
//		if (f) {
//			cout << getmax(1, x, y) << '\n';
//		}
//		else {
//			change(1, x, y);
//		}
//	}
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
//  const int N = 2e5 + 5;
//  typedef long long ll;
//  ll n, q, a[N];
//  ll getans(ll x) {
//	return x * (x + 1) / 2;
// }
//  struct node {
//	ll l, r, ans, fi, la, pre, end, isa;
//	node operator+(const node& e2) {
//		node ret;
//		ret.l = l;
//		ret.r = e2.r;
//		ret.isa = 0;
//		ret.fi = fi;
//		ret.la = e2.la;
//		ret.pre = pre;
//		ret.end = e2.end;
//		ret.ans = ans + e2.ans;
//		if (la <= e2.fi) {
//			ret.ans -= getans(end) + getans(e2.pre);
//			ret.ans += getans(end + e2.pre);
//			if (isa && e2.isa) {
//				ret.isa = 1;
//				ret.pre = ret.end = pre + e2.pre;
//			}
//			else if (isa) {
//				ret.pre = pre + e2.pre;
//			}
//			else if (e2.isa) {
//				ret.end = e2.end + end;
//			}
//		}
//		return ret;
//	}
// };
//  node t[N << 2];
//
//
//
//  void up(ll id) {
//	t[id] = t[id << 1] + t[id << 1 | 1];
// }
//
//  void build(ll id, ll ql, ll qr) {
//	t[id].l = ql;
//	t[id].r = qr;
//	if (ql == qr) {
//		t[id].fi = t[id].la = a[ql];
//		t[id].ans = t[id].pre = t[id].end = t[id].isa = 1;
//		return;
//	}
//	int mid = (ql + qr) >> 1;
//	build(id << 1, ql, mid);
//	build(id << 1 | 1, mid + 1, qr);
//	up(id);
// }
//
//  void change(ll id, ll x, ll val) {
//	ll l = t[id].l;
//	ll r = t[id].r;
//	if (l == r) {
//		t[id].la = val;
//		t[id].fi = val;
//		return;
//	}
//	ll mid = (l + r) >> 1;
//	if (x <= mid)
//		change(id << 1, x, val);
//	else if(x > mid)
//		change(id << 1 | 1, x, val);
//	up(id);
// }
//
//  node query(ll id, ll ql, ll qr) {
//	ll l = t[id].l;
//	ll r = t[id].r;
//	if (ql <= l && r <= qr)
//		return t[id];
//	ll mid = l + r >> 1;
//	if (qr <= mid)
//		return query(id << 1, ql, qr);
//	else if (ql > mid)
//		return query(id << 1 | 1, ql, qr);
//	else
//		return query(id << 1, ql, qr) + query(id << 1 | 1, ql, qr);
// }
//
//  int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	cin >> n >> q;
//	for (int i = 1; i <= n; i++)
//		cin >> a[i];
//	build(1, 1, n);
//
//
//	ll f, x, y;
//	while (q--) {
//		cin >> f >> x >> y;
//		if (f == 1) {
//			change(1, x, y);
//		}
//		else {
//			cout << query(1, x, y).ans << "\n";
//		}
//	}
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
//  typedef long long ll;
//  const int N = 1e5 + 5;
//  struct node {
//	ll l, r, lazy, sum, son;
// };
//  node t[N << 2];
//  ll n, q, a[N], sta[N];
//
//  void up(int id) {
//	t[id].sum = t[id << 1].sum + t[id << 1 | 1].sum;
//	t[id].son = t[id << 1].son + t[id << 1 | 1].son;
// }
//
//  void settag(int id, ll val) {
//	t[id].sum += t[id].son * val;
//	t[id].lazy += val;
// }
//
//  void down(int id) {
//	settag(id << 1, t[id].lazy);
//	settag(id << 1 | 1, t[id].lazy);
//	t[id].lazy = 0;
// }
//
//  void build(int id, int ql, int qr) {
//	t[id].l = ql;
//	t[id].r = qr;
//	if (ql == qr) {
//		t[id].sum = a[ql];
//		t[id].son = sta[ql];
//		return;
//	}
//	int mid = ql + qr >> 1;
//	build(id << 1, ql, mid);
//	build(id << 1 | 1, mid + 1, qr);
//	up(id);
// }
//
//  void changesta(int id, int x, ll s) {
//	int l = t[id].l;
//	int r = t[id].r;
//	if (l == r) {
//		t[id].son = s;
//		return;
//	}
//	down(id);
//	int mid = r + l >> 1;
//	if (x <= mid)
//		changesta(id << 1, x, s);
//	else
//		changesta(id << 1 | 1, x, s);
//	up(id);
// }
//
//  void modify(int id, int ql, int qr, ll val) {
//	ll l = t[id].l;
//	ll r = t[id].r;
//	if (ql <= l && qr >= r) {
//		settag(id, val);
//		return;
//	}
//	down(id);
//	int mid = l + r >> 1;
//	if (qr <= mid)
//		modify(id << 1, ql, qr, val);
//	else if (ql > mid)
//		modify(id << 1 | 1, ql, qr, val);
//	else {
//		modify(id << 1, ql, qr, val);
//		modify(id << 1 | 1, ql, qr, val);
//	}
//	up(id);
// }
//
//  ll query(int id, int ql, int qr) {
//	int l = t[id].l;
//	int r = t[id].r;
//	if (ql <= l && qr >= r)
//		return t[id].sum;
//	down(id);
//	int mid = l + r >> 1;
//	if (qr <= mid)
//		return query(id << 1, ql, qr);
//	else if (ql > mid)
//		return query(id << 1 | 1, ql, qr);
//	else
//		return query(id << 1, ql, qr) + query(id << 1 | 1, ql, qr);
// }
//
//  int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	cin >> n >> q;
//	for (int i = 1; i <= n; i++)
//		cin >> a[i];
//	for (int i = 1; i <= n; i++)
//		cin >> sta[i];
//
//	build(1, 1, n);
//
//	ll f, l, r, x;
//	while (q--) {
//		cin >> f;
//		if (f == 1) {
//			cin >> x;
//			changesta(1, x, 0);
//		}
//		else if (f == 2) {
//			cin >> x;
//			changesta(1, x, 1);
//		}
//		else if (f == 3) {
//			cin >> l >> r >> x;
//			modify(1, l, r, x);
//		}
//		else {
//			cin >> l >> r;
//			cout << query(1, l, r) << '\n';
//		}
//	}
//
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
// #define BowTen ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
// #define mp make_pair
//  typedef long long ll;
//  typedef pair<int, int> hashv;
//  const int mod1 = 1e9 + 7;
//  const int mod2 = 1e9 + 9;
//  const int N = 4e5 + 5;
//  hashv pw[N], h[N];
//  hashv base = mp(131, 29);
//  string s;
//
//
//  hashv operator+ (hashv a, hashv b) {
//	return mp((a.first + b.first) % mod1, (a.second + b.second) % mod2);
// }
//  hashv operator- (hashv a, hashv b) {
//	return mp((a.first - b.first) < 0 ? (a.first - b.first) + mod1 : (a.first - b.first), \
//		     (a.second - b.second) < 0 ? (a.second - b.second)+mod2 : (a.second - b.second));
// }
//  hashv operator* (hashv a, hashv b) {
//	return mp((1ll * a.first * b.first) % mod1, (1ll * a.second * b.second) % mod2);
// }
//  hashv getsub(int l, int r) {
//	return h[r] - h[l - 1] * pw[r - l + 1];
// }
//  void init() {
//	memset(pw, 0, sizeof pw);
//	memset(h, 0, sizeof h);
//	pw[0] = mp(1, 1);
// }
//
//  int main()
//{
//	BowTen;
//	while (cin >> s) {
//		init();
//		int n = s.length();
//		s = ' ' + s;
//		for (int i = 1; i <= n; i++) {
//			pw[i] = pw[i - 1] * base;
//			h[i] = h[i - 1] * base + mp(s[i], s[i]);
//		}
//		for (int i = 1; i <= n; i++) {
//			if (h[i] == getsub(n-i+1,n))
//				cout << i << ' ';
//		}
//		cout << '\n';
//	}
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
//
//
//  int main()
//{
//
//	int t;
//	cin >> t;
//	while (t--) {
//		cout << 22;
//	}
//	return 0;
// }

// #include<iostream>
//  using namespace std;
// #define BowTen ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
// #define mp make_pair
//  typedef long long ll;
//  typedef pair<int, int> hashv;
//  const int N = 5e4 + 5;
//  const int mod1 = 1e9 + 9;
//  const int mod2 = 1e9 + 7;
//  hashv pw[N], h[N], base = mp(33,131);
//  string s;
//
//  hashv operator+(hashv a, hashv b) {
//	return mp((a.first + b.first) % mod1, (a.second + b.second) % mod2);
// }
//  hashv operator-(hashv a, hashv b) {
//	return mp((a.first - b.first) < 0 ? (a.first - b.first) + mod1 : (a.first - b.first), \
//		(a.second - b.second) < 0 ? (a.second - b.second) + mod2 : (a.second - b.second));
// }
//  hashv operator*(hashv a, hashv b) {
//	return mp((1ll * a.first * b.first) % mod1, (1ll * a.second * b.second) % mod2);
// }
//  hashv getsub(int l, int r) {
//	return h[r] - h[l - 1] * pw[r - l + 1];
// }
//  void init() {
//	memset(pw, 0, sizeof pw);
//	memset(h, 0, sizeof h);
//	pw[0] = mp(1, 1);
// }
//
//
//  int main() {
//	BowTen;
//	while (cin >> s) {
//		init();
//		int n = s.length();
//		s = ' ' + s;
//		for (int i = 1; i <= n; i++) {
//			pw[i] = pw[i-1] * base;
//			h[i] = h[i - 1] *base + mp(s[i], s[i]);
//		}
//		for (int i = 1; i <= n; i++)
//			if (h[i] == getsub(n - i + 1, n))
//				cout << i << ' ';
//		cout << '\n';
//	}
//
//
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
//  string s;
//
//
//  int main()
//{
//	while (cin >> s) {
//		int n = s.length();
//		s = ' ' + s;
//		vector<int>ne(n+1);
//		for (int i = 2, j = 0; i <= n; i++) {
//			while (j && s[j + 1] != s[i]) j = ne[j];
//			if (s[j + 1] == s[i]) j++;
//			ne[i] = j;
//		}
//		sort(ne.begin(), ne.end());
//		cout << ne[0] << ' ';
//		for (int i = 1; i <= n; i++) {
//			if (ne[i] == ne[i - 1]) continue;
//			cout << ne[i] << ' ';
//		}
//		cout << '\n';
//	}
//
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
//  typedef unsigned long long ull;
//  const int N = 4e5 + 5;
//  const int mod = 1e9 + 9;
//  string s;
//  ull h[N], pw[N], base = 131;
//
//  ull getson(int l, int r) {
//	return h[r] - h[l - 1] * pw[r - l + 1];
// }
//
//
//  int main()
//{
//	pw[0] = 1;
//	while (cin >> s) {
//		int n = s.length();
//		s = ' ' + s;
//		for (int i = 1; i <= n; i++) {
//			pw[i] = (pw[i - 1] * base);
//			h[i] = (h[i - 1] * base + s[i]);
//		}
//		for (int i = 1; i <= n; i++) {
//			if (h[i] == getson(n - i + 1, n))
//				cout << i << ' ';
//		}
//		cout << '\n';
//	}
//
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
//  typedef unsigned long long ull;
//  const int N = 1e6 + 5;
//  const int mod = 1e9 + 9;
//  string s1, s2;
//  ull h1, h2[N], pw[N], base = 131;
//
//  ull getson(int l, int r) {
//	return h2[r] - h2[l - 1] * pw[r - l + 1];
// }
//
//  void init() {
//	h1 = 0;
// }
//
//  int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int t;
//	cin >> t;
//	pw[0] = 1;
//	while (t--) {
//		init();
//		cin >> s1 >> s2;
//		int n1 = s1.length();
//		int n2 = s2.length();
//		s1 = ' ' + s1;
//		s2 = ' ' + s2;
//		for (int i = 1; i <= n1; i++)
//			h1 = h1 * base + s1[i];
//		for (int i = 1; i <= n2; i++) {
//			pw[i] = pw[i - 1] * base;
//			h2[i] = h2[i - 1] * base + s2[i];
//		}
//		int ans = 0;
//		for (int i = n1;i <= n2; i++) {
//			if (h1 == getson(i - n1 + 1, i))
//				ans++;
//		}
//		cout << ans << '\n';
//	}
//
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
// #define mp make_pair
//  typedef pair<int, int> hashv;
//  typedef unsigned long long ull;
//  const int N = 1e6 + 5;
//  const int mod1 = 1e9 + 9, mod2 = 1e9+7;
//  string s1, s2;
//  hashv h1, h2[N], pw[N], base = mp(33, 131);
//
//  hashv operator+(const hashv a, const hashv b) {
//	return mp((a.first + b.first) % mod1, (a.second + b.second) % mod2);
// }
//  hashv operator-(const hashv a, const hashv b) {
//	return mp((a.first - b.first) < 0 ? (a.first - b.first) + mod1 : (a.first - b.first),\
//		  (a.second - b.second) < 0 ? (a.second - b.second) + mod2 : (a.second - b.second));
// }
//  hashv operator*(const hashv a, const hashv b) {
//	return mp((1ull * a.first * b.first) % mod1, (1ull * a.second * b.second) % mod2);
// }
//  hashv getson(int l, int r) {
//	return h2[r] - h2[l - 1] * pw[r - l + 1];
// }
//
//  void init() {
//	h1 = mp(0, 0);
// }
//
//  int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int t;
//	cin >> t;
//	pw[0] = mp(1, 1);
//	while (t--) {
//		init();
//		cin >> s1 >> s2;
//		int n1 = s1.length();
//		int n2 = s2.length();
//		s1 = ' ' + s1;
//		s2 = ' ' + s2;
//		for (int i = 1; i <= n1; i++)
//			h1 = h1 * base + mp(s1[i], s1[i]);
//		for (int i = 1; i <= n2; i++) {
//			pw[i] = pw[i - 1] * base;
//			h2[i] = h2[i - 1] * base + mp(s2[i], s2[i]);
//		}
//		int ans = 0;
//		for (int i = n1; i <= n2; i++) {
//			if (h1 == getson(i - n1 + 1, i))
//				ans++;
//		}
//		cout << ans << '\n';
//	}
//
//	return 0;
// }

// #include<iostream>
//  using namespace std;
//  typedef unsigned long long ull;
//  const int N = 1e6 + 5, N2 = 1e4 + 5;;
//  string s1, s2;
//  int ne[N2];
//
//  void init() {
//	memset(ne, 0, sizeof ne);
// }
//
//  int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int t;
//	cin >> t;
//	while (t--) {
//		init();
//		cin >> s1 >> s2;
//		int n1 = s1.length();
//		int n2 = s2.length();
//		s1 = ' ' + s1;
//		s2 = ' ' + s2;
//		for (int i = 2, j = 0; i <= n1; i++) {
//			while (j && s1[j + 1] != s1[i]) j = ne[j];
//			if (s1[j + 1] == s1[i]) j++;
//			ne[i] = j;
//		}
//		int ans = 0;
//		for (int i = 1, j = 0; i <= n2; i++) {
//			while (j && s1[j + 1] != s2[i]) j = ne[j];
//			if (s1[j + 1] == s2[i]) j++;
//			if (j == n1) {
//				ans++;
//				j = ne[j];
//			}
//		}
//		cout << ans << '\n';
//	}
//
//	return 0;
// }

// #include<iostream>
//  using namespace std;
//  typedef unsigned long long ull;
//  const int N = 1e6 + 5, N2 = 1e4 + 5;;
//  string s1, s2;
//  int ne[N2];
//
//  void init() {
//	memset(ne, 0, sizeof ne);
// }
//
//  int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int t;
//	cin >> t;
//
//
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
//  const int N = 1e6 + 5;
//  string s1, s2;
//  int ne[N], n, m;
//
//  int main() {
//
//	cin >> s1 >> s2;
//	n = s1.length();
//	m = s2.length();
//	s1 = ' ' + s1;
//	s2 = ' ' + s2;
//	for (int i = 2, j = 0; i <= m; i++) {
//		while (j && s2[j + 1] != s2[i]) j = ne[j];
//		if (s2[j + 1] == s2[i]) j++;
//		ne[i] = j;
//	}
//	for (int i = 1, j = 0; i <= n; i++) {
//		while (j && s1[i] != s2[j + 1]) j = ne[j];
//		if (s2[j + 1] == s1[i]) j++;
//		if (j == m) {
//			cout << i - m + 1 << '\n';
//			j = ne[j];
//		}
//	}
//	for (int i = 1; i <= m; i++)
//		cout << ne[i] << ' ';
//
//  	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
//  const int N = 1e6 + 5;
//  int a[110], n ,d ;
//
//  int main() {
//
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> n >> d;
//		for (int i = 0; i < n; i++)
//			cin >> a[i];
//		sort(a, a + n);
//		if (a[0] + a[1] <= d || a[n-1] <= d)
//			cout << "YES\n";
//		else
//			cout << "NO\n";
//	}
//
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
//  const int N = 1e6 + 5;
//  string s1, s2;
//
//  int main() {
//
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> s1 >> s2;
//		int n1 = s1.length(), n2 = s2.length();
//		if (gcd(n1,n2) <= 1) {
//			for (int i = 0; i < n1; i++)
//				if (s1[i] != s2[0]) {
//					cout << "-1\n";
//					goto ss;
//				}
//			for (int i = 0; i < n2; i++)
//				if (s2[i] != s2[0]) {
//					cout << "-1\n";
//					goto ss;
//				}
//			for (int i = 0; i < n1 * n2; i++)
//				cout << s1[0];
//			cout << '\n';
//		}
//		else {
//			int f = 1;
//			for (int i = 0, j = 0; i <= n1, j <= n2; i++, j++) {
//				if (i == n1)
//					if (f)
//						i = f = 0;
//					else
//						break;
//				if (j == n2)
//					if (f)
//						j = f = 0;
//					else
//						break;
//				if (s1[i] != s2[j]) {
//					cout << "-1\n";
//					goto ss;
//				}
//			}
//			int cnt = ((n1 * n2) / gcd(n1, n2))/max(n1,n2);
//			for (int i = 0; i < cnt; i++)
//				cout << (n1 > n2 ? s1 : s2);
//			cout << '\n';
//		}
//
//	ss:;
//	}
//
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
//  const int N = 1e6 + 5;
//  int a, b, c;
//
//  int main() {
//
//	int t;
//	cin >> t;
//	while (t--) {
//		int n;
//		cin >> n;
//		b = (n + 3) / 3;
//		if ((n + 3) % 3)
//			b++;
//		a = (n - b) / 2;
//			a++;
//		c = n-a-b;
//		cout << a << ' ' << b << ' ' << c << '\n';
//	}
//
//	return 0;
// }

//
// #include<bits/stdc++.h>
// using namespace std;
// const int N = 5e4 + 5;
// int a[N], b[N];
//
// int main() {
//
//	int t;
//	cin >> t;
//	while (t--) {
//		int n;
//		cin >> n;
//		int m1 = 0, m2 = 0, mx;
//		for (int i = 0; i < n; i++) {
//			cin >> a[i];
//			m1 = max(m1, a[i]);
//		}
//		for (int i = 0; i < n; i++) {
//			cin >> b[i];
//			m2 = max(m2, b[i]);
//		}
//		int ans = 1;
//		mx = m1 - m2;
//		for (int i = 0; i < n; i++) {
//			a[i] -= min(mx, a[i]);
//			if (a[i] != b[i])
//				ans = 0;
//		}
//		if (ans && mx >= 0)
//			cout << "YES\n";
//		else
//			cout << "NO\n";
//	}
//
//	return 0;
//}

// #include<bits/stdc++.h>
//  using namespace std;
//  const int N = 1e6 + 5;
//  string s1, s2;
//
//  int main() {
//
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> s1 >> s2;
//		int n1 = s1.length(), n2 = s2.length();
//		if (gcd(n1, n2) <= 1) {
//			for (int i = 0; i < n1; i++)
//				if (s1[i] != s2[0]) {
//					cout << "-1\n";
//					goto ss;
//				}
//			for (int i = 0; i < n2; i++)
//				if (s2[i] != s2[0]) {
//					cout << "-1\n";
//					goto ss;
//				}
//			for (int i = 0; i < n1 * n2; i++)
//				cout << s1[0];
//			cout << '\n';
//		}
//		else {
//			int mx = max(n1, n2);
//			for (int i = 0; i < mx; i++) {
//				if (s1[i % n1] != s2[i % n2]) {
//					cout << "-1\n";
//					goto ss;
//				}
//			}
//			int cnt = ((n1 * n2) / gcd(n1, n2)) / max(n1, n2);
//			for (int i = 0; i < cnt; i++)
//				cout << (n1 > n2 ? s1 : s2);
//			cout << '\n';
//		}
//
//	ss:;
//	}
//
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
//  const int N = 2e5 + 5;
//  int n, a[N], b[N], ans[N], st[N], ed[N];
//
//  int main() {
//
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> n;
//		/*int cur = 0, fini = 0, tim;
//		queue<pair<int,int> >task;
//		for (int i = 0, tmp; i < n; i++) {
//			cin >> tmp;
//			task.push({tmp,i});
//		}
//		for (int i = 0; i < n; i++)
//			cin >> ed[i];
//
//		while (!task.empty()) {
//			while ((!cur && task.front().first >= fini) {
//				cur = task.front().second
//			}
//		}*/
//
//		for (int i = 1; i <= n; i++)
//			cin >> a[i];
//		for (int i = 1; i <= n; i++)
//			cin >> ed[i];
//		int cur = 1, tim = a[1];
//		st[1] = a[1];
//		while (cur <= n) {
//			ans[cur] = ed[cur] - st[cur];
//			tim = max(ed[cur], a[cur + 1]);
//			st[++cur] = tim;
//		}
//		for (int i = 1; i <= n; i++)
//			cout << ans[i] << ' ';
//		cout << '\n';
//	}
//
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
//  const int N = 2e5 + 5;
//  int n, k;
//
//  int main() {
//
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int t;
//	cin >> t;
//	while (t--) {
//		string s;
//		cin >> n >> k >> s;
//		int ans = k;
//		int p = 0, q = 0, w = 0;
//		for (p = 0; p <= k - 1; p++) {
//			if (s[p] == 'W')
//				w++;
//		}
//		ans = min(ans, w);
//		for (p = k,q = 1; p < n; p++, q++) {
//			if (s[q - 1] == 'W')
//				w--;
//			if (s[p] == 'W')
//				w++;
//			ans = min(ans, w);
//		}
//		cout << ans << '\n';
//	}
//
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
//  typedef long long ll;
//  const int N = 2e5 + 5;
//  int n, k;
//
//  int main() {
//
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> n >> k;
//		ll sum = 0;
//		for (ll i = 0, t = 0; i < n; i++) {
//			cin >> t;
//			sum += t;
//		}
//		cout << sum / k << '\n';
//	}
//
//	return 0;
// }

//
// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// const int N = 2e5 + 5;
// int n, k;
//
// int main() {
//
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> n >> k;
//		int f = 2 * k - n;
//		for (int i = 1; i < f; i++)
//			cout << i << ' ';
//		for (int i = k; i >= f; i--)
//			cout << i << ' ';
//		cout << '\n';
//	}
//
//	return 0;
//}

// #include<bits/stdc++.h>
//  using namespace std;
//  typedef long long ll;
//  const int N = 2e5 + 5;
//  int n, k;
//
//  int main() {
//
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> n >> k;
//		vector<int>a(n);
//		ll sum = 0;
//		for (int i = 0, tmp; i < n; i++) {
//			cin >> tmp;
//			sum += tmp / k;
//			a[i] = tmp % k;
//		}
//		sort(a.begin(), a.end());
//		for (int q = 0, p = n - 1; p > q; p--, q++) {
//			while (a[q] + a[p] < k && q < p) q++;
//			if (q >= p)
//				break;
//			sum++;
//		}
//		cout << sum << '\n';
//	}
//
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
//  typedef long long ll;
//  const int N = 2e5 + 5;
//  int n, m;
//  string s;
//  struct val {
//	int l = 0, r = 0, x = 0;
//	const val operator+(const val& e) {
//		val ret;
//		ret.l = min(l, e.l + x);
//		ret.r = max(r, e.r + x);
//		ret.x = x + e.x;
//		return ret;
//	}
// };
//  struct node {
//	int l, r;
//	val v;
//
// };
//  node seg[N << 2];
//
//  void up(int id) {
//	seg[id].v = seg[id << 1].v + seg[id << 1 | 1].v;
// }
//
//  void build(int id, int ql, int qr) {
//	seg[id].l = ql;
//	seg[id].r = qr;
//	if (ql == qr) {
//		seg[id].v.l = seg[id].v.r = 0;
//		if (s[ql] == '-')
//			seg[id].v.l = seg[id].v.x = -1;
//		else
//			seg[id].v.r = seg[id].v.x = 1;
//		return;
//	}
//	int mid = ql + qr >> 1;
//	build(id << 1, ql, mid);
//	build(id << 1 | 1, mid + 1, qr);
//	up(id);
// }
//
//  val query(int id, int ql, int qr) {
//	if (ql > qr)
//		return {0,0,0};
//	int l = seg[id].l;
//	int r = seg[id].r;
//	if (ql <= l && qr >= r)
//		return seg[id].v;
//	int mid = l + r >> 1;
//	if (qr <= mid)
//		return query(id << 1, ql, qr);
//	else if (ql > mid)
//		return query(id << 1 | 1, ql, qr);
//	else
//		return query(id << 1, ql, qr) + query(id << 1 | 1, ql, qr);
// }
//
//  int main() {
//
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> n >> m >> s;
//		s = ' ' + s;
//		build(1, 1, n);
//		int l, r;
//		while (m--) {
//			cin >> l >> r;
//			val ans = (query(1, 1, l-1) + query(1, r+1, n));
//			cout << ans.r - ans.l + 1 << '\n';
//		}
//	}
//
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
//  typedef unsigned long long ll;
//  const int N = 210;
//  int n, a[N];
//  string s;
//
//
//  int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> n >> s;
//		vector<bool>vis(n + 1);
//		vector<vector<char>>ss(1);
//		for (int i = 1; i <= n; i++)
//			cin >> a[i];
//		int siz = 1;
//		for (int cnt = 0, p = 1; cnt < n;) {
//			if (!vis[p]) {
//				vis[p] = true;
//				ss[siz-1].push_back(s[a[p]-1]);
//				p = a[p];
//				cnt++;
//			}
//			else {
//				ss.resize(++siz);
//				while (vis[++p]);
//			}
//		}
//		vector<ll>ans(siz);
//		for (int x = 0, si; x < siz; x++) {
//			si = ss[x].size();
//			vector<int>ne(si+1);
//			for (int i = 2, j = 0; i <= si; i++) {
//				while (j && ss[x][j] != ss[x][i - 1]) j = ne[j];
//				if (ss[x][j] == ss[x][i - 1]) j++;
//				ne[i] = j;
//			}
//			if (si % (si - ne[si]) == 0)
//				ans[x] = si - ne[si];
//			else
//				ans[x] = si;
//		}
//		for (int i = 1; i < siz; i++) {
//			ans[i] = (ans[i] * ans[i - 1]) / gcd(ans[i], ans[i - 1]);
//		}
//		cout << ans[siz - 1] << '\n';
//	}
//
//
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
//  typedef unsigned long long ll;
//  const int N = 1e5+5;
//  int n, m, a[N], k, d;
//
//
//  int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> n >> m;
//		map<int, int>head;
//		int cur = INT_MAX;
//		for (int i = 1; i <= n; i++) {
//			cin >> a[i];
//			if (a[i] < cur)
//				head[i] = a[i], cur = a[i];
//		}
//		while (m--) {
//			cin >> k >> d;
//			if (head.find(k) != head.end()) {
//				head[k] -= d;
//				vector<int>delet;
//				for (auto p = ++head.find(k), ed = head.end(); p != ed; p++) {
//					if (p->second >= head[k]) {
//						delet.push_back(p->first);
//					}
//				}
//				for (auto p : delet)
//					head.erase(p);
//			}
//			else {
//				a[k] -= d;
//				head[k] = a[k];
//				if ((--head.find(k))->second <= a[k]) {
//					head.erase(k);
//					cout << head.size() << ' ';
//					continue;
//				}
//				vector<int>delet;
//				for (auto p = ++head.find(k), ed = head.end(); p != ed; p++) {
//					if (p->second >= head[k]) {
//						delet.push_back(p->first);
//					}
//				}
//				for (auto p : delet)
//					head.erase(p);
//			}
//		cout << head.size() << ' ';
//		}
//		cout << '\n';
//	}
//
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
//  typedef unsigned long long ll;
//  const int N = 1e5 + 5;
//  int n, m, a[N], k, d;
//
//
//  int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> n >> m;
//		map<int, int>head;
//		int last = INT_MAX;
//		for (int i = 1; i <= n; i++) {
//			cin >> a[i];
//			head[i] = a[i];
//			auto p = head.find(i);
//			if (p != head.begin() && prev(p)->second <= head[i])
//				head.erase(p);
//			else while (next(p) != head.end() && next(p)->second >= head[i])
//				head.erase(next(p));
//		}
//		while (m--) {
//			cin >> k >> d;
//			a[k] -= d;
//			head[k] = a[k];
//			auto p = head.find(k);
//			if (p != head.begin() && prev(p)->second <= head[k])
//				head.erase(p);
//			else while (next(p) != head.end() && next(p)->second >= head[k])
//				head.erase(next(p));
//			cout << head.size() << ' ';
//		}
//		cout << '\n';
//
//	}
//
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
//  typedef unsigned long long ll;
//  const int N = 1e5 + 5;
//  int n, m, a[N], k, d;
//
//  bool isPrime(int n) {
//	for (int i = 2; i < n; i++)
//		if (n % i == 0)
//			return false;
//	return true;
// }
//
//  template<typename t1, typename t2>
//
//  int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	while (cin >> n) {
//		cout << isPrime(n) << '\n';
//	}
//
//	return 0;
// }

//
// #include<bits/stdc++.h>
// using namespace std;
// const int N = 2e5 + 5;
// int n, dep[N], par[N][20], mn[N][20], mx[N][20], q;
// vector<vector<pair<int,int>>>mp;
//
// void dfs(int u, int fa, int val) {
//	dep[u] = dep[fa] + 1;
//	par[u][0] = fa;
//	mn[u][0] = val;
//	mx[u][0] = val;
//	for (int i = 1; i < 20; i++) {
//		par[u][i] = par[par[u][i - 1]][i - 1];
//		mn[u][i] = min(mn[u][i - 1], mn[par[u][i - 1]][i - 1]);
//		mx[u][i] = max(mx[u][i - 1], mx[par[u][i - 1]][i - 1]);
//	}
//	for (auto& [v, w] : mp[u]) if (v != fa) {
//		dfs(v, u, w);
//	}
//}
//
// pair<int, int> query(int u, int v) {
//	if (dep[u] < dep[v]) swap(u, v);
//	int r1 = mn[u][0], r2 = mx[u][0];
//	for (int i = 19; i >= 0; i--) if (dep[par[u][i]] >= dep[v]) {
//		r1 = min(r1, mn[u][i]);
//		r2 = max(r2, mx[u][i]);
//		u = par[u][i];
//	}
//	if (u == v)
//		return make_pair(r1, r2);
//	for (int i = 19; i >= 0; i--) if (par[u][i] != par[v][i]) {
//		r1 = min({ r1, mn[u][i], mn[v][i] });
//		r2 = max({ r2, mx[u][i], mx[v][i] });
//		u = par[u][i];
//		v = par[v][i];
//	}
//	r1 = min({ r1, mn[u][0], mn[v][0] });
//	r2 = max({ r2, mx[u][0], mx[v][0] });
//	return make_pair(r1, r2);
//}
//
// void init() {
//	mp.clear();
//	mp.resize(n+1);
//	memset(dep, 0, sizeof dep);
//	memset(par, 0, sizeof par);
//	memset(mn, 0, sizeof mn);
//	memset(mx, 0, sizeof mx);
//}
//
// int main()
//{
//	int  t;
//	cin >> t;
//	for (int x = 1; x <= t;x++) {
//		cout << "Case " << x << ":\n";
//		cin >> n;
//		init();
//
//		for (int i = 1, u, v, w; i < n; i++) {
//			cin >> u >> v >> w;
//			mp[u].push_back({ v,w });
//			mp[v].push_back({ u,w });
//		}
//		dfs(1, 0, 0);
//
//		cin >> q;
//		int q1, q2;
//		while (q--) {
//			cin >> q1 >> q2;
//			pair<int, int>ans = query(q1, q2);
//			cout << ans.first << ' ' << ans.second << '\n';
//		}
//	}
//
//
//	return 0;
//}

// #include<bits/stdc++.h>
//  using namespace std;
//  const int N = 5e4 + 5;
//  int n, k, a[N], dep[N], par[N][20], ans;
//  vector<int>mp[N];
//
//  void dfs(int u, int fa) {
//	for (auto& v : mp[u]) if (v != fa)
//		dfs(v, u);
//	a[fa] += a[u];
//	ans = max(ans, a[u]);
// }
//
//  void pre_dfs(int u, int fa) {
//	dep[u] = dep[fa] + 1;
//	par[u][0] = fa;
//	for (int i = 1; i < 20; i++)
//		par[u][i] = par[par[u][i - 1]][i - 1];
//	for (auto& v : mp[u]) if (v != fa)
//		pre_dfs(v, u);
// }
//
//  int getlca(int u, int v) {
//	if (dep[u] < dep[v]) swap(u, v);
//	for (int i = 19; i >= 0; i--) if (dep[par[u][i]] >= dep[v])
//		u = par[u][i];
//	if (u == v)
//		return u;
//	for (int i = 19; i >= 0; i--) if (par[u][i] != par[v][i]) {
//		u = par[u][i];
//		v = par[v][i];
//	}
//	return par[u][0];
// }
//
//  int main()
//{
//	cin >> n >> k;
//	for (int i = 1, u, v; i < n; i++) {
//		cin >> u >> v;
//		mp[u].push_back(v);
//		mp[v].push_back(u);
//	}
//
//	pre_dfs(1, 0);
//
//	int s, e, f;
//	while (k--) {
//		cin >> s >> e;
//		a[s]++;
//		a[e]++;
//		f = getlca(s, e);
//		a[f]--;
//		a[par[f][0]];
//	}
//	dfs(1, 0);
//	cout << ans;
//
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
//  typedef long long ll;
//  const int N = 1e6 + 5;
//  ll n, m, r, a[N], tot, L[N], R[N], t[N];
//  vector<int>mp[N];
//
//  void pre_dfs(int u, int fa) {
//	L[u] = ++tot;
//	for (auto& v : mp[u]) if (v != fa)
//		pre_dfs(v, u);
//	R[u] = tot;
// }
//
//  int lowbit(int x) {
//	return x & -x;
// }
//
//  void add(int i, int val) {
//	while (i <= n) {
//		t[i] += val;
//		i += lowbit(i);
//	}
// }
//
//  ll getsum(int i) {
//	ll ret = 0;
//	while (i > 0) {
//		ret += t[i];
//		i -= lowbit(i);
//	}
//	return ret;
// }
//
//
//  int main()
//{
//	cin >> n >> m >> r;
//	for (int i = 1; i <= n; i++)
//		cin >> a[i];
//	for (int i = 1, u, v; i < n; i++) {
//		cin >> u >> v;
//		mp[u].push_back(v);
//		mp[v].push_back(u);
//	}
//	pre_dfs(r, 0);
//	for (int i = 1; i <= n; i++)
//		add(L[i], a[i]);
//	int f, q1, q2;
//	while (m--) {
//		cin >> f;
//		if (f == 1) {
//			cin >> q1 >> q2;
//			add(L[q1], q2);
//		}
//		else {
//			cin >> q1;
//			cout << getsum(R[q1]) - getsum(L[q1] - 1) << '\n';
//		}
//	}
//
//	return 0;
// }

// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>
//  const int N = 110;
//  char num[N][N];
//  int n;
//
//  int cmp(const void* s1, const void* s2) {
//	return -strcmp((char*)s1, (char*)s2);
// }
//
//  int main() {
//
//	scanf("%d",&n);
//	getchar();
//	for (int i = 1; i <= n; i++)
//		scanf("%s", num[i]);
//	qsort(num + 1, n, sizeof(num[0]), cmp);
//	for (int i = 1; i <= n; i++)
//		printf("%s", num[i]);
//
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
//  const int N = 2e5+5;
//  int n, ne[N], k;
//  string m = " mihoyo";
//  string s;
//
//
//  int main()
//{
//	cin >> n >> k >> s;
//	s = ' ' + s;
//	for (int i = 2, j = 0; i <= 6; i++) {
//		while (j && m[i] != m[j + 1]) j = ne[j];
//		if (m[i] == m[j + 1]) j++;
//		ne[j] = i;
//	}
//	int cnt = 0;
//	vector<int>left;
//	vector<pair<int, int>>ans;
//	for (int i = 1, j = 0; i <= n; i++) {
//		while (j && s[i] != m[j + 1]) j = ne[j];
//		if (s[i] == m[j + 1]) j++;
//		if (j == 6) {
//			left.push_back(i - 6);
//			cnt++;
//			j = ne[j];
//			if (cnt >= k) {
//				ans.push_back({ left[ans.size()],i - 1});
//			}
//		}
//	}
//	sort(ans.begin(), ans.end(), [](pair<int, int>e1, pair<int, int>e2)->int {
//		return e1.second - e1.first < e2.second - e2.first;
//		});
//	if (!ans.size())
//		cout << 0;
//	else
//		cout << ans[0].first << ' ' << ans[0].second;
//
//
//
//	return 0;
// }0 1 2 2 3 3 4 4 1 9 10 10 9 13 13

// #include<bits/stdc++.h>
// #define int long long
//  using namespace std;
//  const int N = 2e5 + 5;
//  int n, fa[N];
//  vector<vector<int>>mp;
//
//  void init() {
//	mp.clear();
//	mp.resize(n+1);
// }
//
//  int dfs(int u, int fa) {
//	int ret = 1;
//	if (mp[u].size() >= 3)
//		ret = 2;
//	else if (mp[u].size() == 1)
//		return 1;
//	int cnt = 0;
//	for (auto v : mp[u]) if (v != fa) {
//		int delt = dfs(v, u);
//		if (cnt && delt >= ret)
//			ret++;
//		if (delt >= ret)
//			ret = delt;
//		cnt++;
//	}
//	return ret;
// }
//
//  signed main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> n;
//		init();
//		int rt;
//		for (int i = 1; i <= n; i++) {
//			cin >> fa[i];
//			if (!fa[i])
//				rt = i;
//			mp[i].push_back(fa[i]);
//			mp[fa[i]].push_back(i);
//		}
//		cout << dfs(rt, 0) << '\n';
//	}
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
// #define int long long
//  const int N = 2e5 + 5;
//  int n, fa[N], ans, ned, s[N];
//  vector<vector<int>>mp;
//
//  void init() {
//	memset(s, 0, sizeof s);
//	mp.clear();
//	mp.resize(n + 1);
//	ned = 1;
// }
//
//  int dfs(int u, int fa) {
//	if (u && mp[u].size() == 1)
//		return 1;
//	s[u] = 1;
//	int ret = 1;
//	for (auto v : mp[u]) if (v != fa) {
//		int delt = dfs(v, u);
//		if (s[u] == 0 && delt >= ret)
//			ret++;
//		if (delt >= ret) {
//			ret = delt;
//			s[u] = 0;
//		}
//	}
//	return ret;
// }
//
//  signed main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> n;
//		init();
//		int rt;
//		for (int i = 1; i <= n; i++) {
//			cin >> fa[i];
//			if (!fa[i])
//				rt = i;
//			mp[i].push_back(fa[i]);
//			mp[fa[i]].push_back(i);
//		}
//		cout << dfs(rt, 0) << '\n';
//	}
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
//  typedef long long ll;
//  const int N = 2e5+5;
//  ll n;
//  vector<vector<int>>mp;
//
//  ll dfs(ll u, ll fa) {
//	if (mp[u].size() <= 1)
//		return 1;
//	map<ll, ll>ump;
//	for (auto v : mp[u]) if (v != fa) {
//		ump[dfs(v, u)]++;
//	}
//	ll ret = prev(ump.end())->first;
//	if (ump[ret] > 1)
//		return ret + 1;
//	return ret;
// }
//
//
//  void init() {
//	mp.clear();
//	mp.resize(n + 1);
// }
//
//  int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> n;
//		init();
//		ll rt;
//		for (ll i = 1, tmp; i <= n; i++) {
//			cin >> tmp;
//			if (tmp == 0)
//				rt = i;
//			mp[i].push_back(tmp);
//			mp[tmp].push_back(i);
//		}
//		cout << dfs(rt, 0) << '\n';
//	}
//
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
//  typedef long long ll;
//  const int N = 2e5 + 5;
//  int n, k;
//  string s;
//
//  int main() {
//	int t;
//	cin >> t;
//	int a, b, c;
//	while (t--) {
//		cin >> a >> b >> c;
//		if (a + b == c)
//			cout << "+\n";
//		else
//			cout << "-\n";
//	}
//
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
//  typedef long long ll;
//  const int N = 2e5 + 5;
//  int n;
//  string s;
//
//  int main() {
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int T;
//	cin >> T;
//	while (T--) {
//		cin >> n;
//		int a = 0, b = 0;
//		for (int i = 0, t; i < n; i++) {
//			cin >> t;
//			if (t % 2)
//				b += t;
//			else
//				a += t;
//		}
//		if (a > b)
//			cout << "YES\n";
//		else
//			cout << "NO\n";
//	}
//
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
//  typedef long long ll;
//  const int N = 2e5 + 5;
//  int n;
//  string s;
//
//  int main() {
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int T;
//	cin >> T;
//	while (T--) {
//		cin >> n;
//		cin >> s;
//		unordered_map<char, int>mp;
//		for (int i = 0; i < n; i++)
//			if (!mp[s[i]])
//				mp[s[i]] = i & 1;
//		for (auto [c, v] : mp) {
//			for (int i = 0; i < n; i++) if (s[i] == c && (i & 1) != v) {
//				cout << "NO\n";
//				goto ss;
//			}
//		}
//		cout << "YES\n";
//	ss:;
//	}
//
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
//  typedef long long ll;
//  const int N = 2e5 + 5;
//  ll n, q, pre[N];
//  string s;
//
//  int main() {
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int T;
//	cin >> T;
//	while (T--) {
//		cin >> n >> q;
//		for (int i = 1; i <= n; i++) {
//			cin >> pre[i];
//			pre[i] += pre[i - 1];
//		}
//		ll l, r, k, sum = pre[n];
//		while (q--) {
//			cin >> l >> r >> k;
//			if ((sum - pre[r] + pre[l - 1] + (r - l + 1) * k) % 2)
//				cout << "YES\n";
//			else
//				cout << "NO\n";
//		}
//	}
//
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
//  typedef long long ll;
//  const int N = 2e5 + 5;
//  ll n, q, a[N];
//  string s;
//
//  int main() {
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int T;
//	cin >> T;
//	while (T--) {
//		cin >> n;
//		for (int i = 1; i <= n; i++)
//			cin >> a[i];
//		sort(a + 1, a + n + 1);
//		if (a[1] != 1) {
//			cout << "NO\n";
//			goto ss;
//		}
//		for (int i = 1; i <= n; i++) {
//			a[i] += a[i - 1];
//		}
//		for (int i = n; i > 1; i--) {
//			if (a[i] > 2*a[i - 1]) {
//				cout << "NO\n";
//				goto ss;
//			}
//		}
//		cout << "YES\n";
//	ss:;
//	}
//
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
//  typedef long long ll;
//  const int N = 2e5 + 5;
//  ll n, q, a[N], pre[N];
//  string s;
//
//  bool check(int l, int mid) {
//	cout << "? " << mid - l + 1 << ' ';
//	for (int i = l; i <= mid; i++)
//		cout << i << ' ';
//	cout << '\n';
//	ll ret;
//	cin >> ret;
//	if (ret > pre[mid] - pre[l - 1])
//		return true;
//	return false;
// }
//
//  int main() {
//	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	fflush(stdout);
//	int T;
//	cin >> T;
//	while (T--) {
//		cin >> n;
//		for (int i = 1; i <= n; i++) {
//			cin >> a[i];
//			pre[i] = a[i];
//			pre[i] += pre[i - 1];
//		}
//
//
//		ll l = 1, r = n, mid;
//		while (l < r) {
//			mid = l + r >> 1;
//			if (check(l, mid))
//				r = mid;
//			else
//				l = mid + 1;
//		}
//		cout << "! " << r << '\n';
//	}
//
//	return 0;
// }

//
// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// const int N = 2e5 + 5;
// ll n, m, i1, i2, jj1, j2, vi, vj, cnt;
// string s;
// map<pair<int,int>, int>mp;
//
// void upv() {
//	if (s[0] == 'U')
//		vi = -1;
//	else
//		vi = 1;
//	if (s[1] == 'L')
//		vj = -1;
//	else
//		vj = 1;
//}
//
// void _bou() {
//	if (i1 == 1)
//		vi = 1;
//	else if (i1 == m)
//		vi = -1;
//	else if (jj1 == 1)
//		vj = 1;
//	else
//		vj = -1;
//}
//
// bool mov() {
//	if ((i2 - i1) / vi == (j2 - jj1) / vj && (i2 - i1) * vi >= 0)
//		return false;
//	ll ti, tj;
//	if (vi > 0)
//		ti = m - i1;
//	else
//		ti = i1 - 1;
//	if (vj > 0)
//		tj = n - jj1;
//	else
//		tj = jj1 - 1;
//	if (ti == tj) {
//		if (n == m && i2 != j2) {
//			cnt = -1;
//			return false;
//		}
//		else {
//			vi *= -1;
//			vj *= -1;
//			return true;
//		}
//	}
//	ll tt = min(ti, tj);
//	i1 = tt * vi + i1;
//	jj1 = tt * vj + jj1;
//	if (tt == ti)
//		vi *= -1;
//	else
//		vj *= -1;
//	return true;
//}
//
// int main() {
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int T;
//	cin >> T;
//	while (T--) {
//		cin >> m >> n >> i1 >> jj1 >> i2 >> j2 >> s;
//		mp.clear();
//		upv();
//		cnt = 0;
//		mp[make_pair(i1, jj1)]++;
//		while (mov()) {
//			if (mp[make_pair(i1, jj1)]++ > 3) {
//				cnt = -1;
//				break;
//			}
//			cnt++;
//		}
//		cout << cnt << '\n';
//	}
//
//	return 0;
//}

//
//
// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// const int N = 2e5 + 5;
// ll n, m, ii, jj, i2, j2, vi, vj;
// string s;
//
// void initv() {
//	if (s[0] == 'U')
//		vi = -1;
//	else
//		vi = 1;
//	if (s[1] == 'L')
//		vj = -1;
//	else
//		vj = 1;
//}
//
// void turn() {
//	int ni = ii + vi;
//	if (ni < 1 || ni > n)
//		vi *= -1;
//	else
//		vj *= -1;
//}
//
// bool mov() {
//	if ((i2 - ii) / vi == (j2 - jj) / vj && (i2 - ii) * vi >= 0)
//		return false;
//	int ti, tj, tt;
//	if (vi > 0)
//		ti = n - ii;
//	else
//		ti = ii - 1;
//	if (vj > 0)
//		tj = m - jj;
//	else
//		tj = jj - 1;
//	tt = min(ti, tj);
//	ii += tt * vi;
//	jj += tt * vj;
//	if(ti == tj)
//		vi *= -1, vj *= -1;
//	else
//		turn();
//	return true;
//}
//
// int main() {
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	int T;
//	cin >> T;
//	while (T--) {
//		cin >> n >> m >> ii >> jj >> i2 >> j2 >> s;
//		initv();
//		ll cnt = 0;
//		map<pair<int, int>, int>mp;
//		while (mov()) {
//			if (mp[{ii, jj}]++ > 3) {
//				cnt = -1;
//				break;
//			}
//			cnt++;
//		}
//
//		cout << cnt << '\n';
//
//	}
//
//	return 0;
//}

// #include<bits/stdc++.h>
//  using namespace std;
//  typedef long long ll;
//  const int N = 1e5 + 5;
//  ll n, m, s, d[N], vis[N];
//  vector<pair<int,int> >mp[N];
//
//  int main() {
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	cin >> n >> m >> s;
//	for (int i = 0, u, v, w; i < m; i++) {
//		cin >> u >> v >> w;
//		mp[u].push_back({ v,w });
//	}
//	queue<int>que;
//	que.push(s);
//	vis[s] = 1;
//	for (int i = 0; i <= n; i++)
//		d[i] = LLONG_MAX;
//	d[s] = 0;
//	while (!que.empty()) {
//		int u = que.front();
//		que.pop();
//		vis[u] = 0;
//		for (auto [v, w] : mp[u]) if(d[v] > d[u] + w) {
//			d[v] = d[u] + w;
//			if (!vis[v]) {
//				que.push(v);
//				vis[v] = 1;
//			}
//		}
//	}
//	for (int i = 1; i <= n; i++)
//		cout << d[i] << ' ';
//
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
//  typedef long long ll;
//  const int N = 1e5 + 5;
//  int n, m, s, d[N], vis[N];
//  vector<pair<int, int> >mp[N];
//
//  int main() {
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	cin >> n >> m >> s;
//	for (int i = 0, u, v, w; i < m; i++) {
//		cin >> u >> v >> w;
//		mp[u].push_back({ v,w });
//	}
//	priority_queue< pair<int, int>, vector<pair<int,int>>,greater<pair<int,int>> >que;
//	que.push({0,s});
//	memset(d, 0x3f, sizeof d);
//	d[s] = 0;
//	while (!que.empty()) {
//		int u = que.top().second;
//		que.pop();
//		if (vis[u]) continue;
//		vis[u] = 1;
//		for (auto& [v, w] : mp[u]) {
//			if (d[v] > d[u] + w) {
//				d[v] = d[u] + w;
//				que.push({ d[v],v });
//			}
//		}
//	}
//	for (int i = 1; i <= n; i++)
//		cout << d[i] << ' ';
//
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
//  typedef long long ll;
//  const int N = 2e2 + 5;
//  int n, m, s, d[N], vis[N], ac[N], q;
//  vector<pair<int, int> >mp[N];
//
//  void krustar(int x, int t) {
//	memset(d, 0x3f, sizeof d);
//	memset(vis, 0, sizeof vis);
//	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > que;
//	que.push({ 0,x });
//	d[x] = 0;
//	while (que.size()) {
//		int u = que.top().second;
//		que.pop();
//		if (vis[u]) continue;
//		vis[u] = 1;
//		for (auto [v, w] : mp[u]) {
//			if (d[v] > d[u] + w && ac[u] <= t && ac[v] <= t) {
//				d[v] = d[u] + w;
//				que.push({ d[v],v });
//			}
//		}
//	}
// }
//
//
//  int main() {
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	cin >> n >> m;
//	for (int i = 0; i < n; i++)
//		cin >> ac[i];
//	for (int i = 0, u, v, w; i < m; i++) {
//		cin >> u >> v >> w;
//		mp[u].push_back({ v,w });
//		mp[v].push_back({ u,w });
//	}
//	int x, y, t;
//	cin >> q;
//	while (q--) {
//		cin >> x >> y >> t;
//		if (ac[x] > t || ac[y] > t) {
//			cout << "-1\n";
//			continue;
//		}
//		krustar(x, t);
//		if (d[y] == 0x3f3f3f3f)
//			cout << "-1\n";
//		else
//			cout << d[y] << '\n';
//	}
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
//  typedef long long ll;
//  const int N = 1e3 + 5;
//  int n, m, s, d[N], vis[N], q, sum;
//  vector<pair<int, int> >mp1[N];
//  vector<pair<int, int> >mp2[N];
//
//  void krustar() {
//	memset(d, 0x3f, sizeof d);
//	d[1] = 0;
//	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>que;
//	que.push({0,1});
//	while (que.size()) {
//		int u = que.top().second;
//		que.pop();
//		if (vis[u]) continue;
//		vis[u] = 1;
//		for (auto [v, w] : mp1[u]) {
//			if (d[v] > d[u] + w) {
//				d[v] = d[u] + w;
//				que.push({ d[v],v });
//			}
//		}
//	}
//	for (int i = 2; i <= n; i++)
//		sum += d[i];
//	memset(d, 0x3f, sizeof d);
//	memset(vis, 0, sizeof vis);
//	d[1] = 0;
//	que.push({ 0,1 });
//	while (que.size()) {
//		int u = que.top().second;
//		que.pop();
//		if (vis[u]) continue;
//		vis[u] = 1;
//		for (auto [v, w] : mp2[u]) {
//			if (d[v] > d[u] + w) {
//				d[v] = d[u] + w;
//				que.push({ d[v],v });
//			}
//		}
//	}
//	for (int i = 2; i <= n; i++)
//		sum += d[i];
// }
//
//  int main() {
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	cin >> n >> m;
//	for (int i = 0, u, v, w; i < m; i++) {
//		cin >> u >> v >> w;
//		mp1[u].push_back({ v,w });
//		mp2[v].push_back({ u,w });
//	}
//	krustar();
//	cout << sum;
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
//  typedef long long ll;
//  const int N = 1e6 + 5;
//  const int mod = 100003;
//  int n, m, s, d[N], vis[N], cnt[N];
//  vector<int>mp[N];
//
//  void krustar() {
//	memset(d, 0x3f, sizeof d);
//	d[1] = 0;
//	cnt[1] = 1;
//	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>que;
//	que.push({ 0,1 });
//	while (que.size()) {
//		int u = que.top().second;
//		que.pop();
//		if (vis[u]) continue;
//		vis[u] = 1;
//		for (auto v : mp[u]) {
//			if (d[v] == d[u] + 1)
//				cnt[v] += cnt[u];
//			else if (d[v] > d[u] + 1) {
//				d[v] = d[u] + 1;
//				cnt[v] = cnt[u];
//				que.push({ d[v],v });
//			}
//			cnt[v] %= mod;
//		}
//	}
// }
//
//  int main() {
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	cin >> n >> m;
//	for (int i = 0, u, v; i < m; i++) {
//		cin >> u >> v;
//		mp[u].push_back(v);
//		mp[v].push_back(u);
//	}
//	krustar();
//	for (int i = 1; i <= n; i++)
//		cout << cnt[i] <<'\n';
//	return 0;
// }

//
// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// const int N = 1e4 + 5;
// #define int long long
// int n, m, b, blod[N], vis[N], f[N];
// vector<pair<int, int> >mp[N];
//
// bool check(int mid) {
//	if (f[1] > mid)
//		return false;
//	memset(vis, 0, sizeof vis);
//	for (int i = 1; i <= n; i++)
//		blod[i] = -1;
//	priority_queue<pair<int, int>>que;
//	que.push({ b,1 });
//	blod[1] = b;
//	while (que.size()) {
//		int u = que.top().second;
//		que.pop();
//		if (vis[u]) continue;
//		vis[u] = 1;
//		for (auto [v, w] : mp[u]) {
//			if (w <= blod[u] && f[v] <= mid) {
//				blod[v] = blod[u] - w;
//				que.push({blod[v],v});
//			}
//		}
//	}
//	return blod[n] != -1;
//}
//
// signed main() {
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	cin >> n >> m >> b;
//	for (int i = 1; i <= n; i++)
//		cin >> f[i];
//	for (int i = 0, u, v, w; i < m; i++) {
//		cin >> u >> v >> w;
//		mp[u].push_back({ v,w });
//		mp[v].push_back({ u,w });
//	}
//	if (!check(INT_MAX)) {
//		cout << "AFK";
//		return 0;
//	}
//	int l = 0, r = INT_MAX;
//	while (l <= r) {
//		int mid = (l + r) >> 1;
//		if (check(mid))
//			r = mid - 1;
//		else
//			l = mid + 1;
//	}
//	cout << l;
//
//
//	return 0;
//}

//
// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// const int N = 1e4 + 5;
////#define int long long
// int n, m, b, blod[N], vis[N], f[N], cnt, head[N];
// vector<pair<int, int> >mp[N];
// struct node {
//	int x, to, next;
// };
////node edge[10 * N];
//
////void add_edge(int u, int v, int w) {
////	edge[cnt].x = w;
////	edge[cnt].to = v;
////	edge[cnt].next = head[u];
////	head[u] = cnt++;
////}
//
// bool check(int mid) {
//	if (f[1] > mid || f[n] > mid)
//		return false;
//	memset(vis, 0, sizeof vis);
//	for (int i = 1; i <= n; i++)
//		blod[i] = -1;
//	blod[1] = b;
//	priority_queue<pair<int, int>>que;
//	que.push({ b,1 });
//
//	while (que.size()) {
//		int u = que.top().second;
//		que.pop();
//		if (vis[u]) continue;
//		vis[u] = 1;
//		for (auto [v, w] : mp[u]) {
//			if (f[v] <= mid && w <= blod[u]) {
//				blod[v] = blod[u] - w;
//				que.push({ blod[v],v });
//			}
//		}
//	}
//	return blod[n] != -1;
//}
//
//
// signed main() {
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	cin >> n >> m >> b;
//	for (int i = 1; i <= n; i++)
//		cin >> f[i], head[i] = -1;
//	for (int i = 0, u, v, w; i < m; i++) {
//		cin >> u >> v >> w;
//		mp[u].push_back({ v,w });
//		mp[v].push_back({ u,w });
//	}
//	int l = 0, r = INT_MAX;
//	if (!check(r)) {
//		cout << "AFK";
//		return 0;
//	}
//	while (l <= r) {
//		int mid = l + r >> 1;
//		if (check(mid))
//			r = mid - 1;
//		else
//			l = mid + 1;
//	}
//	cout << l;
//
//	return 0;
//}

// #include<bits/stdc++.h>
//  using namespace std;
//  typedef long long ll;
//  const int N = 1e5 + 5;
//  const int M = 2e5 + 5;
//// #define int long long
// int n, m, s, cnt, head[N], d[N], vis[N];
// struct node {
//	int x, to, next;
// };
// node edge[M];
//
// void add_edge(int u, int v, int w) {
//	edge[++cnt].x = w;
//	edge[cnt].to = v;
//	edge[cnt].next = head[u];
//	head[u] = cnt;
// }
//
// void dij(int s) {
//	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>que;
//	que.push({ 0,s });
//	memset(d, 0x3f, sizeof d);
//	memset(vis, 0, sizeof vis);
//	d[s] = 0;
//	while (que.size()) {
//		int u = que.top().second;
//		que.pop();
//		if (vis[u]) continue;
//		vis[u] = 1;
//		for (int v = head[u], w; v; v = edge[v].next) {
//			w = edge[v].x;
//			if (d[edge[v].to] > d[u] + w) {
//				d[edge[v].to] = d[u] + w;
//				que.push({ d[edge[v].to],edge[v].to });
//			}
//		}
//	}
// }
//
// signed main() {
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	cin >> n >> m >> s;
//	for (int i = 0, u, v, w; i < m; i++) {
//		cin >> u >> v >> w;
//		add_edge(u, v, w);
//	}
//	dij(s);
//	for (int i = 1; i <= n; i++)
//		cout << d[i] << ' ';
//
//	return 0;
// }

//
// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// const int N = 5005;
// const int M = 2e5 + 5;
// int n, m, cnt, dis[N], head[N], vis[N];
// ll sum;
//
//
////int find(int x) {
////	return fa[x] == x ? x : fa[x] = find(fa[x]);
////}
////
////void merg(int a, int b) {
////	a = find(a);
////	b = find(b);
////	fa[a] = b;
////}
//
////struct node{
////	int w, u, v;
////	const int operator<(const node e) {
////		return w < e.w;
////	}
////}edge[M];
////
////void krustar() {
////	for (int i = 1; i <= n; i++)
////		fa[i] = i;
////	for (int i = 0, u, v, w; i < m; i++) {
////		cin >> edge[i].u >> edge[i].v >> edge[i].w;
////	}
////	sort(edge, edge + m);
////	for (auto [w, u, v] : edge) {
////		if (find(u) != find(v)) {
////			sum += w;
////			merg(u, v);
////			cnt++;
////		}
////	}
////	if (cnt < n - 1)
////		cout << "orz";
////	else
////		cout << sum;
////}
// struct nod {
//	int to, w, next;
// }edge[M*2];
//
// void add_edge(int u, int v, int w) {
//	edge[++cnt].w = w;
//	edge[cnt].to = v;
//	edge[cnt].next = head[u];
//	head[u] = cnt;
// }
//
// void prim() {
//	for (int i = 1; i <= n; i++)
//		dis[i] = -1;
//	dis[0] = INT_MAX;
//	dis[1] = 0;
//	for (int i = 0; i <= n - 1; i++) {
//		int x = 0;
//		for (int j = 1; j <= n; j++) {
//			if (!vis[j] && dis[j] >= 0 && dis[j] < dis[x])
//				x = j;
//		}
//		if (!x) {
//			cout << "orz";
//			return;
//		}
//		vis[x] = 1;
//		sum += dis[x];
//		for (int id = head[x], v, w; id; id = edge[id].next) {
//			v = edge[id].to;
//			w = edge[id].w;
//			if (dis[v] == -1 || w < dis[v])
//				dis[v] = w;
//		}
//	}
//	cout << sum;
// }
//
//
// int main() {
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	cin >> n >> m;
//	for (int i = 0, u, v, w; i < m; i++) {
//		cin >> u >> v >> w;
//		add_edge(u, v, w);
//		add_edge(v, u, w);
//	}
//	//krustar();
//	prim();
//
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
//  typedef long long ll;
//  const int N = 5005;
//  const int M = 2e5 + 5;
//  int n, m;
//
//
//
//  int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int n;
//		cin >> n;
//		string s;
//		cin >> s;
//		for (int i = 0; i <= n - 11; i++) {
//			if (s[i] == '8') {
//				cout << "YES\n";
//				goto ss;
//			}
//		}
//		cout << "NO\n";
//	ss:;
//	}
//
//
//	return 0;
// }
//

//
// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// const int N = 5005;
// const int M = 2e5 + 5;
// int n, m, a[7], num[7] = {0,4,8,15,16,23,42};
//
//
//
// int main() {
//	map<int, int>mp;
//	for (int i = 1; i < 7; i++)
//		mp[num[i]]++;
//
//	//int t;
//	//cout << "? 1 1\n";
//	//fflush(stdout);
//	//cin >> t;
//	//a[1] = sqrt(t);
//	//mp.erase(a[1]);
//
//	//cout << "? 2 2\n";
//	//fflush(stdout);
//	//cin >> t;
//	//a[2] = sqrt(t);
//	//mp.erase(a[2]);
//
//	int t1, t2, m1[2], m2[2];
//
//	cout << "? 1 2\n";
//	fflush(stdout);
//	cin >> t1;
//	for (auto [k, v] : mp) {
//		if (t1 % k == 0) {
//			m1[0] = t1 / k, m1[1] = k;
//			mp.erase(m1[0]);
//			mp.erase(m1[1]);
//			break;
//		}
//	}
//	int i = 0, j = 0;
//
//	cout << "? 2 3\n";
//	fflush(stdout);
//	cin >> t2;
//	for (auto [k, v] : mp) {
//		if (t2 % k == 0) {
//			m2[0] = t2 / k, m2[1] = k;
//			for (i = 0; i < 2; i++) {
//				for (j = 0; j < 2; j++) {
//					if (m1[i] == m2[j])
//						goto ss;
//				}
//			}
//		ss:;
//			mp.erase(m2[j ^ 1]);
//			break;
//		}
//	}
//
//	a[1] = m1[i ^ 1];
//	a[3] = m2[j ^ 1];
//	a[2] = m1[i];
//
//
//	cout << "? 4 5\n";
//	fflush(stdout);
//	cin >> t1;
//	for (auto [k, v] : mp) {
//		if (t1 % k == 0) {
//			m1[0] = t1 / k, m1[1] = k;
//			mp.erase(m1[0]);
//			mp.erase(m1[1]);
//			break;
//		}
//	}
//	//int i = 0, j = 0;
//
//	cout << "? 5 6\n";
//	fflush(stdout);
//	cin >> t2;
//	for (auto [k, v] : mp) {
//		if (t2 % k == 0) {
//			m2[0] = t2 / k, m2[1] = k;
//			for (i = 0; i < 2; i++) {
//				for (j = 0; j < 2; j++) {
//					if (m1[i] == m2[j])
//						goto sss;
//				}
//			}
//		sss:;
//			mp.erase(m2[j ^ 1]);
//			break;
//		}
//	}
//
//
//	a[4] = m1[i ^ 1];
//	a[6] = m2[j ^ 1];
//	a[5] = m1[i];
//
//	cout << "! ";
//	for (int i = 1; i <= 6; i++)
//		cout << a[i] << ' ';
//	cout << '\n';
//	fflush(stdout);
//	/*for (int i = 1; i <= 6; i++) {
//		for (int j = 1; j <= 6; j++) {
//			if(i >= j)
//			cout << num[i] * num[j] << ' ';
//		}
//		cout << '\n';
//	}*/
//
//	return 0;
//}

// 64
// 16
// 240
// 672

// #include<bits/stdc++.h>
//  using namespace std;
//  const int N = 5e5 + 5;
//  int n, m, fa[N], ans[N];
//
//  int find(int x) {
//	return fa[x] == x ? x : fa[x] = find(fa[x]);
// }
//
//  void merg(int a, int b) {
//	a = find(a);
//	b = find(b);
//	fa[a] = b;
// }
//
//
//  int main() {
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)
//		fa[i] = i;
//	for (int id, t[2], k, i = 0; i < m; i++) {
//		cin >> k;
//		if (!k) continue;
//		k--;
//		cin >> t[0];
//		id = 1;
//		while (k-- > 0) {
//			cin >> t[id];
//			merg(t[id], t[id ^ 1]);
//			id = id ^ 1;
//		}
//	}
//	for (int i = 1; i <= n; i++)
//		ans[find(i)]++;
//	for (int i = 1; i <= n; i++) {
//		cout << ans[fa[i]] << ' ';
//	}
//
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
//  const int N = 2e5 + 5;
//  int n, m, a[N];
//  vector<int>L;
//  vector<int>R;
//  string s;
//
//  int main() {
//	cin >> n;
//	cin >> s;
//	for (int i = 0; i < n; i++) {
//		if (s[i] == '(')
//			L.push_back(i);
//		else
//			R.push_back(i);
//	}
//	int len = L.size();
//	for (int i = 0, cl = 0; i < len; i++) {
//		a[L[i]] = a[R[i]] = cl;
//		cl = cl ^ 1;
//	}
//	for (int i = 0; i < n; i++)
//		cout << a[i];
//
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
//  const int N = 2e5 + 5;
//  int n, m, a[N];
//  vector<int>L;
//  vector<int>R;
//  string s;
//
//  int main() {
//	cin >> n;
//	while (n--) {
//		int s, c;
//		cin >> c >> s;
//		if (c >= s) {
//			cout << s << '\n';
//			continue;
//		}
//		int ans = 0;
//		m = s % c;
//		ans += (m) * (((s +c-m) / c) * ((s +c- m) / c));
//		ans += (c-m) * ((s / c) * (s / c));
//		cout << ans << '\n';
//	}
//
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
// #define int long long
//  const int N = 2e5 + 5;
//  int n;
//  int a, b;
//
//  signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> a >> b;
//		if (a > b)
//			swap(a, b);
//		if (!a && !b) {
//			cout << "YES\n";
//			continue;
//		}
//		if ((a * 2 < b) || a < 0 || b < 0) {
//			cout << "NO\n";
//			continue;
//		}
//		if ((a + b) % 3 == 0)
//			cout << "YES\n";
//		else
//			cout << "NO\n";
//	}
//
//	return 0;
// }

// #include<bits/stdc++.h>
//  using namespace std;
// #define int long long
//  int num[7] = { 0,4,8,15,16,23,42 }, a[7], t;
//  map<int, int>mp;
//  map<int, int>mp2;
//
//  signed main() {
//
//	for (int i = 1; i <= 6; i++)
//		mp2[num[i]] = mp[num[i]] = 1;
//
//	int m1[2], m2[2];
//	printf("? 1 2\n");
//	fflush(stdout);
//	scanf("%d", &t);
//	if (!t)
//		return 0;
//	for (auto [k, v] : mp) {
//		if (t% k == 0 && mp2[t / k]) {
//			m1[0] = k;
//			m1[1] = t / k;
//			mp.erase(m1[0]);
//			mp.erase(m1[1]);
//			break;
//		}
//	}
//	printf("? 2 3\n");
//	fflush(stdout);
//	scanf("%d", &t);
//	if (!t)
//		return 0;
//	for (auto [k, v] : mp) {
//		if (t % k == 0 && mp2[t / k]) {
//			m2[0] = k;
//			m2[1] = t / k;
//			mp.erase(m2[0]);
//			mp.erase(m2[1]);
//			break;
//		}
//	}
//	int p1, p2;
//	for (int i = 0; i < 2; i++)
//		for(int j = 0;j < 2;j++)
//			if (m1[i] == m2[j]) {
//				p1 = i;
//				p2 = j;
//				goto ss;
//			}
//  ss:;
//	a[1] = m1[1 ^ p1];
//	a[2] = m1[p1];
//	a[3] = m2[1 ^ p2];
//
//	printf("? 4 5\n");
//	fflush(stdout);
//	scanf("%d", &t);
//	if (!t)
//		return 0;
//	for (auto [k, v] : mp) {
//		if (t % k == 0 && mp2[t / k]) {
//			m1[0] = k;
//			m1[1] = t / k;
//			mp.erase(m1[0]);
//			mp.erase(m1[1]);
//			break;
//		}
//	}
//	printf("? 5 6\n");
//	fflush(stdout);
//	scanf("%d", &t);
//	if (!t)
//		return 0;
//	for (auto [k, v] : mp) {
//		if (t % k == 0 && mp2[t / k]) {
//			m2[0] = k;
//			m2[1] = t / k;
//			mp.erase(m2[0]);
//			mp.erase(m2[1]);
//			break;
//		}
//	}
//	for (int i = 0; i < 2; i++)
//		for (int j = 0; j < 2; j++)
//			if (m1[i] == m2[j]) {
//				p1 = i;
//				p2 = j;
//				goto sss;
//			}
//  sss:;
//	a[4] = m1[1 ^ p1];
//	a[5] = m1[p1];
//	a[6] = m2[1 ^ p2];
//
//	printf("! ");
//	for (int i = 1; i <= 6; i++) {
//		printf("%d",a[i]);
//		if (i != 6)
//			printf(" ");
//		else
//			printf("\n");
//	}
//
//
//	return 0;
// }

// 32
// 128
// 630
// 966

// 966
// 630
// 128
// 32

// #include <bits/stdc++.h>
// #define int long long
// using namespace std;

// signed main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int r, b, k;
//         cin >> r >> b >> k;
//         if (r > b)
//             swap(r, b);
//         int g = __gcd(r, b);
//         r /= g;
//         b /= g;
//         if ((b - 1) / r >= k)
//         {
//             cout << "REBEL\n";
//             continue;
//         }
//         cout << "OBEY\n";
//     }
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int r, b, k;
//         cin >> r >> b >> k;
//         if (r > b)
//             swap(r, b);
//         int delt = __gcd(r, b);
//         if ((int)ceil((b - delt) / (double)r) >= k)
//         {
//             cout << "REBEL\n";
//             continue;
//         }
//         cout << "OBEY\n";
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// const int M = 2e5 + 5;
// const int N = 2e5 + 5;
// int spe[M], a[N + 1];
// vector<int> st[N + 1];
// vector<int> ed[N + 1];
// int n, m, k, t;

// bool check(int sp)
// {
//     int cnt = 0;
//     for (int i = 0; i <= n + 1; i++)
//     {
//         if (a[i] > sp)
//             cnt++;
//     }
//     if (n + 1 + (2 * cnt) <= t)
//         return true;
//     return false;
// }

// int main()
// {
//     cin >> m >> n >> k >> t;
//     for (int i = 0; i < m; i++)
//         cin >> spe[i];
//     sort(spe, spe + m);
//     for (int i = 0, l, r, w; i < k; i++)
//     {
//         cin >> l >> r >> w;
//         st[l].push_back(w);
//         ed[r + 1].push_back(w);
//     }
//     priority_queue<int> sq;
//     priority_queue<int> eq;
//     for (int i = 0; i <= n; i++)
//     {
//         for (auto s : st[i])
//             sq.push(s);
//         for (auto e : ed[i])
//             eq.push(e);
//         while (!sq.empty() && !eq.empty() && sq.top() == eq.top())
//         {
//             sq.pop();
//             eq.pop();
//         }
//         if (!sq.empty())
//             a[i] = sq.top();
//     }
//     // for (int i = 0; i <= n; i++)
//     //     cout << a[i] << ' ';
//     int l = 0, r = m - 1;
//     while (l <= r)
//     {
//         int mid = l + r >> 1;
//         if (check(spe[mid]))
//             r = mid - 1;
//         else
//             l = mid + 1;
//     }
//     cout << m - l;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e6 + 5;
// int n, x, a[N], l[N], r[N], ll[N], rr[N], pl, pr;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     memset(l, 0x3f, sizeof l);
//     memset(r, 0, sizeof r);
//     cin >> n >> x;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> a[i];
//         l[a[i]] = min(l[a[i]], i);
//         r[a[i]] = max(r[a[i]], i);
//     }
//     // for (int i = 1; i <= x; i++)
//     //     rr[i] = max(rr[i - 1], r[i]);
//     // for (int i = x; i >= 1; i--)
//     //     ll[i] = min(ll[i + 1], l[i]);
//     pl = 1;
//     pr = x;
//     while (pl <= x && r[pl] < l[pl + 1])
//         pl++;
//     while (pr >= 1 && l[pr] > r[pr - 1])
//         pr--;
//     int ans = 0;
//     for (int i = 1, j = pr - 1; i <= pl + 1; i++)
//     {
//         while (j <= x && (r[i - 1] > l[j + 1] || j < i))
//             j++;
//         ans += x - j + 1;
//     }
//     cout << ans;
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e6 + 5;
// int n;

// int main()
// {
//     ios::sync_with_stdio(false);
//     int a, b, c, d, f = 0, chi = 0;
//     cin >> a >> b >> c >> d;
//     if (c >= b || d >= b)
//         f = 1;
//     if (c < a || d < a)
//         chi = 1;
//     cout << c << '-';
//     if (c < a)
//     {
//         if (f)
//             cout << "Y ";
//         else
//             cout << "N ";
//     }
//     else
//         cout << "Y ";
//     cout << d << '-';
//     if (d < a)
//     {
//         if (f)
//             cout << "Y\n";
//         else
//             cout << "N\n";
//     }
//     else
//         cout << "Y\n";

//     if (f && chi)
//     {
//         printf("qing %d zhao gu hao %d", (c > d ? 1 : 2), (c < d ? 1 : 2));
//         return 0;
//     }
//     if (!chi)
//     {
//         cout << "huan ying ru guan";
//         return 0;
//     }
//     if (c < a && d < a)
//     {
//         cout << "zhang da zai lai ba";
//         return 0;
//     }
//     if (d > a)
//     {
//         cout << "2: huan ying ru guan";
//     }
//     else
//         cout << "1: huan ying ru guan";

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e6 + 5;
// int n;

// int main()
// {
//     ios::sync_with_stdio(false);
//     int a, b, c;
//     cin >> a >> b;
//     c = a + b;
//     long long ans = 1;
//     for (int i = 1; i <= c; i++)
//         ans *= i;
//     cout << ans;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e6 + 5;
// int n;

// int main()
// {
//     ios::sync_with_stdio(false);
//     int a[7], n, ans[7];
//     int vis[7][7] = {0};
//     for (int i = 1; i <= 6; i++)
//         cin >> a[i], vis[i][a[i]] = 1;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 1; j <= 6; j++)
//         {
//             for (int x = 6; x >= 1; x--)
//             {
//                 if (!vis[j][x])
//                 {
//                     ans[j] = x;
//                     vis[j][x] = 1;
//                     break;
//                 }
//             }
//         }
//     }
//     for (int i = 1; i <= 6; i++)
//         cout << ans[i] << ' ';
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e6 + 5;
// int n;

// int main()
// {
//     ios::sync_with_stdio(false);
//     int a[7], n, ans[7];
//     int vis[7][7] = {0};
//     for (int i = 1; i <= 6; i++)
//         cin >> a[i], vis[i][a[i]] = 1;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 1; j <= 6; j++)
//         {
//             for (int x = 6; x >= 1; x--)
//             {
//                 if (!vis[j][x])
//                 {
//                     ans[j] = x;
//                     vis[j][x] = 1;
//                     break;
//                 }
//             }
//         }
//     }
//     for (int i = 1; i <= 6; i++)
//         cout << ans[i] << ' ';
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 5;
// int n, k, s;
// pair<int, int> a[N];

// int cmp(pair<int, int> e1, pair<int, int> e2)
// {
//     if (e1.first == e2.first)
//         return e1.second < e2.second;
//     return e1.first > e2.first;
// }

// void pta()
// {
//     for (int i = 0; i < n; i++)
//     {
//         cout << a[i].first << ' ' << a[i].second << '\n';
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin >> n >> k >> s;
//     list<pair<int, int>> st;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i].first >> a[i].second;
//     }
//     sort(a, a + n, cmp);
//     for (int i = 0; i < n; i++)
//         st.push_back(a[i]);
//     int ans = 0;
//     while (k--)
//     {
//         int last = -1;
//         for (auto p = st.begin(); p != st.end(); p++)
//         {
//             if (p->first >= 175)
//             {
//                 if (p->first != last || p->second >= s)
//                 {
//                     last = p->first;
//                     ans++;
//                     p = prev(p);
//                     st.erase(next(p));
//                 }
//             }
//         }
//     }
//     cout << ans;
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 5;
// int n, k, s;
// string s1, s2, a1, a2;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> s1 >> s2;
//     for (int i = 1; i < s1.length(); i++)
//     {
//         if ((s1[i] - '0') % 2 == (s1[i - 1] - '0') % 2)
//         {
//             a1 += max(s1[i], s1[i - 1]);
//         }
//     }
//     for (int i = 1; i < s2.length(); i++)
//     {
//         if ((s2[i] - '0') % 2 == (s2[i - 1] - '0') % 2)
//         {
//             a2 += max(s2[i], s2[i - 1]);
//         }
//     }
//     if (a1 == a2)
//         cout << a1;
//     else
//         cout << a1 << '\n'
//              << a2;
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 5;
// int n, m, q, vis[2][N];

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> n >> m >> q;
//     int cr[2] = {0}, t, c;
//     while (q--)
//     {
//         cin >> t >> c;
//         if (!vis[t][c])
//         {
//             vis[t][c] = 1;
//             cr[t]++;
//         }
//     }

//     cout << m * n - ((cr[0] * m + cr[1] * n) - cr[0] * cr[1]);
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 5;
// int n;
// struct node
// {
//     int a, b, c, e1, e2, e3;
// };
// node sc[N];

// int cmp(node e1, node e2)
// {
//     if (e1.a == e2.a)
//     {
//         if (e1.b == e2.b)
//             return e1.c < e2.c;
//         return e1.b < e2.b;
//     }
//     return e1.a < e2.a;
// }

// int main()
// {
//     // ios::sync_with_stdio(false);
//     // cin.tie(0);
//     // cout.tie(0);
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d:%d:%d - %d:%d:%d", &sc[i].a, &sc[i].b, &sc[i].c, &sc[i].e1, &sc[i].e2, &sc[i].e3);
//         // printf("%02d:%02d:%02d - %02d:%02d:%02d\n", sc[i].a, sc[i].b, sc[i].c, sc[i].e1, sc[i].e2, sc[i].e3);
//     }
//     sort(sc, sc + n, cmp);
//     sc[n] = {23, 59, 59, 23, 59, 59};
//     // for (int i = 0; i < n; i++)
//     // {
//     //     printf("%02d:%02d:%02d - %02d:%02d:%02d\n", sc[i].a, sc[i].b, sc[i].c, sc[i].e1, sc[i].e2, sc[i].e3);
//     // }
//     int qa = 0, qb = 0, qc = 0;
//     for (int i = 0; i <= n; i++)
//     {
//         if (qa != sc[i].a || qb != sc[i].b || qc != sc[i].c)
//         {
//             printf("%02d:%02d:%02d - %02d:%02d:%02d\n", qa, qb, qc, sc[i].a, sc[i].b, sc[i].c);
//         }
//         qa = sc[i].e1, qb = sc[i].e2, qc = sc[i].e3;
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e3 + 5;
// int n, m, k, cnt, ts[N];
// vector<vector<int>> ans;
// stack<int> st;

// int main()
// {
//     cin >> n >> m >> k;
//     for (int i = 0, t; i < n; i++)
//         cin >> ts[i];
//     for (int i = 0; i < n;)
//     {
//         if (cnt >= ans.size())
//         {
//             ans.resize(cnt + 1);
//             if (!st.empty())
//             {
//                 ans[cnt].push_back(st.top());
//                 st.pop();
//             }
//             else
//             {
//                 ans[cnt].push_back(ts[i++]);
//             }
//             continue;
//         }
//         if (ans[cnt].size() >= k)
//         {
//             cnt++;
//             continue;
//         }
//         if (!st.empty() && st.top() <= ans[cnt].back())
//         {
//             ans[cnt].push_back(st.top());
//             st.pop();
//         }
//         else
//         {
//             if (ts[i] <= ans[cnt].back())
//             {
//                 ans[cnt].push_back(ts[i++]);
//             }
//             else
//             {
//                 if (st.size() < m)
//                     st.push(ts[i++]);
//                 else
//                     cnt++;
//             }
//         }
//     }
//     while (!st.empty())
//     {
//         if (cnt >= ans.size())
//         {
//             ans.resize(cnt + 1);
//             ans[cnt].push_back(st.top());
//             st.pop();
//             continue;
//         }
//         if (ans[cnt].size() >= k)
//         {
//             cnt++;
//             continue;
//         }
//         if (st.top() <= ans[cnt].back())
//         {
//             ans[cnt].push_back(st.top());
//             st.pop();
//         }
//         else
//             cnt++;
//     }
//     for (int i = 0, len = ans.size(); i < len; i++)
//     {
//         for (int j = 0, le = ans[cnt].size(); j < le;j++){
//             cout << ans[i][j];
//             if(j != le-1)
//                 cout << ' ';
//         }
//         cout << '\n';
//     }
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e3 + 5;
// int n, m, k, cnt, ts[N];
// vector<vector<int>> ans;
// stack<int> st;

// int main()
// {

//     srand(time(0));
//     int t = rand() % 2;
//     cout << t;
//     return 0;
// }

// #include <bits/stdc++.h>
// #define int long long
// using namespace std;
// const int INF = INT_MAX;
// const int N = 1e6 + 5;
// int n, x, r[N], l[N], rr[N], ll[N];

// signed main()
// {
//     cin >> n >> x;
//     for (int i = 0; i <= x + 1; ++i)
//     {
//         l[i] = INF;
//         r[i] = -INF;
//         ll[i] = INF;
//         rr[i] = -INF;
//     }
//     for (int i = 1, t; i <= n; i++)
//     {
//         cin >> t;
//         l[t] = min(l[t], i);
//         r[t] = max(r[t], i);
//     }
//     for (int i = 1; i <= x; i++)
//         rr[i] = max(rr[i - 1], r[i]);
//     for (int i = x; i >= 1; i--)
//         ll[i] = min(ll[i + 1], l[i]);
//     int ql = 1, qr = x;
//     while (ql <= x && rr[ql - 1] <= l[ql])
//         ql++;
//     while (qr >= 1 && ll[qr + 1] >= r[qr])
//         qr--;
//     int ans = 0;
//     // cout << ql << ' ' << qr << '\n';
//     // cout << r[0] << '\n';
//     for (int i = 1, j = qr; i <= ql; i++)
//     {
//         while (j <= x && (j < i || rr[i - 1] > ll[j + 1]))
//             j++;
//         // cout << x - j + 1 << ' ';
//         ans += x - j + 1;
//     }
//     cout << ans;
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e6 + 5;
// int n, x, r[N], l[N];

// int main()
// {
//     memset(l, 0x3f, sizeof l);
//     cin >> n >> x;
//     for (int i = 0; i <= x + 1; i++)
//     {
//         l[i] = INT_MAX;
//         r[i] = -INT_MAX;
//     }
//     for (int i = 1, t; i <= n; i++)
//     {
//         cin >> t;
//         l[t] = min(l[t], i);
//         r[t] = max(r[t], i);
//     }
//     int ql = 1, qr = x;
//     while (ql <= x && r[ql - 1] < l[ql])
//         ql++;
//     while (qr >= 1 && l[qr + 1] > r[qr])
//         qr--;
//     int ans = 0;
//     // cout << ql << ' ' << qr << '\n';
//     // cout << r[0] << '\n';
//     for (int i = 1, j = qr; i <= ql && i <= x; i++)
//     {
//         while (j <= x && (j < i || r[i - 1] >= l[j + 1]))
//             j++;
//         // cout << x - j + 1 << ' ';
//         ans += x - j + 1;
//     }
//     cout << ans;
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     vector<int> a({9, 6});
//     vector<int> b({2, 3, 4});
//     // a = a + b;
//     a.insert(a.end(), b.begin(), b.end());
//     a = b;
//     vector<int> c(b);
//     for (auto p : c)
//         cout << p << ' ';
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// int b = 40;
// void p()
// {
//     static int b = 5;
//     b++;
//     cout << b;
// }
// int main()
// {
//     // int cnt = 1000;
//     // while (cnt--)
//     // {
//     //     int a = (rand() % 41) + 10;
//     //     if (a > 50 || a < 10)
//     //         cout << a << '\n';
//     // }
//     // double a = 48;
//     // cout << a;
//     string s = "0002023";
//     long long a = stoll(s);
//     cout << a;
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e2 + 5;
// const int M = 2e5 + 5;
// int n, m, s, cnt, head[N], dis[N], vis[N], d[N][N];
// struct node
// {
//     int v, w, next;
// } edge[M];
// void add(int u, int v, int w)
// {
//     edge[++cnt].v = v;
//     edge[cnt].w = w;
//     edge[cnt].next = head[u];
//     head[u] = cnt;
// }

// void dij()
// {
//     memset(dis, 0x3f, sizeof dis);
//     dis[s] = 0;
//     dis[0]++;
//     for (int i = 0; i < n; i++)
//     {
//         int x = 0;
//         for (int j = 1; j <= n; j++)
//         {
//             if (!vis[j] && dis[j] < dis[x])
//                 x = j;
//         }
//         vis[x] = 1;
//         // cout << x << ' ';
//         for (int id = head[x], v, w; id; id = edge[id].next)
//         {
//             v = edge[id].v;
//             w = edge[id].w;
//             dis[v] = min(dis[v], dis[x] + w);
//         }
//     }
// }

// void dij_pro()
// {
//     memset(dis, 0x3f, sizeof dis);
//     dis[s] = 0;
//     dis[0]++;
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
//     q.push({0, s});
//     while (q.size())
//     {
//         int u = q.top().second;
//         q.pop();
//         if (vis[u])
//             continue;
//         vis[u] = 1;
//         for (int id = head[u], v, w; id; id = edge[id].next)
//         {
//             v = edge[id].v;
//             w = edge[id].w;
//             if (dis[u] + w < dis[v])
//             {
//                 dis[v] = dis[u] + w;
//                 q.push({dis[v], v});
//             }
//         }
//     }
// }

// void floyd()
// {
//     for (int k = 1; k <= n; k++)
//         for (int u = 1; u <= n; u++)
//             for (int v = 1; v <= n; v++)
//                 d[u][v] = min(d[u][v], d[u][k] + d[k][v]);
// }

// int main()
// {
//     cin >> n >> m >> s;
//     for (int i = 0, u, v, w; i < m; i++)
//     {
//         cin >> u >> v >> w;
//         // add(u, v, w);
//         d[u][v] = d[v][u] = w;
//     }
//     // dij();
//     // dij_pro();
//     // cout << '\n';
//     // for (int i = 1; i <= n; i++)
//     //     cout << dis[i] << ' ';
//     floyd();
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//             cout << d[i][j] << ' ';
//         cout << '\n';
//     }
//     return 0;
// }