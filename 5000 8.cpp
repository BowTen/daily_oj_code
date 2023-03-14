#define _CRT_SECURE_NO_WARNINGS
#define _SILENCE_CXX20_CISO646_REMOVED_WARNING
#define BowTen ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 1e6 + 5;
//int n, q;
//ll t[N];
//
//int lowbit(int x) {
//	return x & -x;
//}
//
//void add(int i, ll val) {
//	while (i <= n) {
//		t[i] += val;
//		i += lowbit(i);
//	}
//}
//
//ll getsum(int i) {
//	ll ret = 0;
//	while (i >= 1) {
//		ret += t[i];
//		i -= lowbit(i);
//	}
//	return ret;
//}
//
//int main()
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
//}



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



//#include<bits/stdc++.h>
//using namespace std;
//
//int main()
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
//}


//#include<bits/stdc++.h>
//using namespace std;
//int n, x[3],y[3];
//char s[410][410];
//
//void init() {
//	memset(s, 0, sizeof s);
//	memset(x, 0, sizeof x);
//	memset(y, 0, sizeof y);
//}
//
//int main()
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
//}



//#include<bits/stdc++.h>
//using namespace std;
//const int N = 2e5 + 5;
//int n, a, b;
//string s;
//
//void init() {
//}
//
//int main()
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
//}




//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 2e5 + 5;
//int n, a, b;
//
//void init() {
//}
//
//int main()
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
//}


//
//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 2e5 + 5;
//int n;
//
//void init() {
//}
//
//int main()
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


//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 2e5 + 5;
//int n;
//
//
//int main()
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
//}




//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 2e5 + 5;
//int n, a, b;
//
//
//int main()
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
//}



//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 2e5 + 5;
//int n, a, b;
//
//
//int main()
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
//}



//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 2e5 + 5;
//int n, l, r, s, sm, no;
//int sum[500];
//
//
//int main()
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
//}



//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 2e5 + 5;
//ll n, c, a[N], b[N];
//ll da[N], mo[N], fas[N];
//
//
//int main()
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
//}



//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 1e7 + 5;
//ll c, b[N], ans[N];
//
//int main()
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
//}


//#include<bits/stdc++.h>
//using namespace std;
//int n, m, c, t;
//
//int main()
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
//}




//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e3 + 5;
//typedef long long ll;
//struct bug {
//	ll x, y, h, id;
//};
//vector<bug>b;
//ll n, ans[N], x, y, atk, h, r, sb, f;
//
//
//void die(int x) {
//	ans[b[x].id] = 1;
//	b.erase(b.begin() + x);
//	sb--;
//}
//
//
//int main()
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
//}

//5
//2 1 0 1 1
//2 1 0 1 1
//2 1 0 1 1
//1 0 0 4
//1 0 1 8




//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 2e3 + 5;
//ll n,x,y,h,ak,f,r,ans[N];
//struct bug {
//	ll x, y, h, id;
//};
//vector<bug>b;
//
//int main()
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
//}

//5
//2 1 0 1 1
//2 1 0 1 1
//1 0 0 3
//2 1 0 1 1
//1 0 1 8



//#include<bits/stdc++.h>
//using namespace std;
//#define endl '\n'
//#define Acode ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
//typedef long long ll;
//const int inf = 0x3f3f3f3f;
//const int N = 1e6 + 20;
//ll n, m;
//ll p[N], d[N];
//ll dp[N];
//int main()
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
//}




//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e6 + 5;
//typedef long long ll;
//ll n, k, s = 1, a[N], b[N], w[N], sub[N << 1], pre[N << 1], len, val[N<<1];
//struct node {
//	ll val, id, f;
//};
//
//
//int main()
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
//}


//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e6 + 5;
//int a,b;
//
//int main()
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
//}




//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e6 + 5;
//typedef long long ll;
//ll n, k, s = 1, a[N], b[N], w[N], sub[N << 1], pre[N << 1], len, val[N << 1];
//struct node {
//	ll val, id, f;
//};
//
//
//int main()
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
//}



//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e6 + 5;
//typedef long long ll;
//ll n, k, s = 1, a[N], b[N], w[N], sub[N << 1], len, val[N << 1];
//vector<ll>num;
//
//int main()
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
//}


//2 2
//1 1 8
//1 1 4




//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 1e5 + 5;
//int T[N], n, q;
//
//int lowbit(int x) {
//	return x & -x;
//}
//
//void add(int i, int val) {
//	while (i <= n) {
//		T[i] += val;
//		i += lowbit(i);
//	}
//}
//
//ll getsum(int i) {
//	ll ret = 0;
//	while (i >= 1) {
//		ret += T[i];
//		i -= lowbit(i);
//	}
//	return ret;
//}
//
//void init() {
//	memset(T, 0, sizeof T);
//}
//
//int main()
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
//}




//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//struct node {
//	ll sum;
//	int l, r;
//};
//const int N = 1e5 + 5;
//int n, q, a[N];
//node T[N << 2];
//
//void up(int id) {
//	T[id].sum = T[id << 1].sum + T[id << 1 | 1].sum;
//}
//
//void build(int id, int ql, int qr) {
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
//}
//
//void change(int id, int x, int val) {
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
//}
//
//ll query(int id, int ql, int qr) {
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
//}
//
//void init() {
//	memset(T, 0, sizeof T);
//	memset(a, 0, sizeof a);
//}
//
//int main()
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
//}




//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 5e4 + 5;
//int n, q, a[N];
//struct node {
//	int max, l, r;
//};
//node seg[N << 2];
//
//void up(int id) {
//	seg[id].max = max(seg[id << 1].max, seg[id << 1 | 1].max);
//}
//
//void build(int id, int ql, int  qr) {
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
//}
//
//void change(int id, int x, int val) {
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
//}
//
//int getmax(int id, int ql, int qr) {
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
//}
//
//
//int main()
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
//}




//#include<bits/stdc++.h>
//using namespace std;
//const int N = 2e5 + 5;
//typedef long long ll;
//ll n, q, a[N];
//ll getans(ll x) {
//	return x * (x + 1) / 2;
//}
//struct node {
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
//};
//node t[N << 2];
//
//
//
//void up(ll id) {
//	t[id] = t[id << 1] + t[id << 1 | 1];
//}
//
//void build(ll id, ll ql, ll qr) {
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
//}
//
//void change(ll id, ll x, ll val) {
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
//}
//
//node query(ll id, ll ql, ll qr) {
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
//}
//
//int main()
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
//}



//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 1e5 + 5;
//struct node {
//	ll l, r, lazy, sum, son;
//};
//node t[N << 2];
//ll n, q, a[N], sta[N];
//
//void up(int id) {
//	t[id].sum = t[id << 1].sum + t[id << 1 | 1].sum;
//	t[id].son = t[id << 1].son + t[id << 1 | 1].son;
//}
//
//void settag(int id, ll val) {
//	t[id].sum += t[id].son * val;
//	t[id].lazy += val;
//}
//
//void down(int id) {
//	settag(id << 1, t[id].lazy);
//	settag(id << 1 | 1, t[id].lazy);
//	t[id].lazy = 0;
//}
//
//void build(int id, int ql, int qr) {
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
//}
//
//void changesta(int id, int x, ll s) {
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
//}
//
//void modify(int id, int ql, int qr, ll val) {
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
//}
//
//ll query(int id, int ql, int qr) {
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
//}
//
//int main()
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
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define BowTen ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//#define mp make_pair
//typedef long long ll;
//typedef pair<int, int> hashv;
//const int mod1 = 1e9 + 7;
//const int mod2 = 1e9 + 9;
//const int N = 4e5 + 5;
//hashv pw[N], h[N];
//hashv base = mp(131, 29);
//string s;
//
//
//hashv operator+ (hashv a, hashv b) {
//	return mp((a.first + b.first) % mod1, (a.second + b.second) % mod2);
//}
//hashv operator- (hashv a, hashv b) {
//	return mp((a.first - b.first) < 0 ? (a.first - b.first) + mod1 : (a.first - b.first), \
//		     (a.second - b.second) < 0 ? (a.second - b.second)+mod2 : (a.second - b.second));
//}
//hashv operator* (hashv a, hashv b) {
//	return mp((1ll * a.first * b.first) % mod1, (1ll * a.second * b.second) % mod2);
//}
//hashv getsub(int l, int r) {
//	return h[r] - h[l - 1] * pw[r - l + 1];
//}
//void init() {
//	memset(pw, 0, sizeof pw);
//	memset(h, 0, sizeof h);
//	pw[0] = mp(1, 1);
//}
//
//int main()
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
//}




//#include<bits/stdc++.h>
//using namespace std;
//
//
//int main()
//{
//
//	int t;
//	cin >> t;
//	while (t--) {
//		cout << 22;
//	}
//	return 0;
//}



//#include<iostream>
//using namespace std;
//#define BowTen ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//#define mp make_pair
//typedef long long ll;
//typedef pair<int, int> hashv;
//const int N = 5e4 + 5;
//const int mod1 = 1e9 + 9;
//const int mod2 = 1e9 + 7;
//hashv pw[N], h[N], base = mp(33,131);
//string s;
//
//hashv operator+(hashv a, hashv b) {
//	return mp((a.first + b.first) % mod1, (a.second + b.second) % mod2);
//}
//hashv operator-(hashv a, hashv b) {
//	return mp((a.first - b.first) < 0 ? (a.first - b.first) + mod1 : (a.first - b.first), \
//		(a.second - b.second) < 0 ? (a.second - b.second) + mod2 : (a.second - b.second));
//}
//hashv operator*(hashv a, hashv b) {
//	return mp((1ll * a.first * b.first) % mod1, (1ll * a.second * b.second) % mod2);
//}
//hashv getsub(int l, int r) {
//	return h[r] - h[l - 1] * pw[r - l + 1];
//}
//void init() {
//	memset(pw, 0, sizeof pw);
//	memset(h, 0, sizeof h);
//	pw[0] = mp(1, 1);
//}
//
//
//int main() {
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
//}