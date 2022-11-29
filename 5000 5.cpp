
#include<bits/stdc++.h>
using namespace std;
//typedef long long ll;
//
//ll a[200010];
//map<ll,ll>m;
//int main()
//{
//	ll n, c,sum = 0;
//	cin >> n >> c;
//	for (ll i = 0;i < n;i++)
//	{
//		cin >> a[i];
//		m[a[i]]++;
//		a[i] -= c;
//	}
//	for (ll i = 0;i < n;i++)
//		sum += m[a[i]];
//	cout << sum;
//
//	return 0;
//}
//
//typedef long long ll;
//ll tre[1000010];
//
//int main()
//{
//	ll n, m, lon = 0;
//	cin >> n >> m;
//	for (ll i = 0;i < n;i++)
//		cin >> tre[i];
//	sort(tre, tre + n);
//	ll f = n-1;
//	for (ll i = tre[n-1];i >= 1 ;i--)
//	{
//		while (tre[f] > i)
//			f--;
//		lon += (n-1-f);
//		if (lon >= m)
//		{
//			cout << i;
//			break;
//		}
//	}
//	return 0;
//}

//double a, b, c, d,l,r,m;
//inline double f(double x)
//{
//	return a * x * x * x + b * x * x + c * x + d;
//}
//
//int main()
//{
//	int count = 0;
//	cin >> a >> b >> c >> d;
//	for (l = -100;l < 100;l++)
//	{
//		r = l + 1;
//		m = (l + r) / 2;
//		if (f(l) == 0)
//		{
//			count++;
//			printf("%.2lf ",l);
//		}
//		else while(f(r) * f(l) < 0)
//		{
//			if (r - l < 0.001)
//			{
//				printf("%.2lf ", r);
//			}
//			if (f(m) == 0)
//			{
//				count++;
//				printf("%.2lf ",m);
//				break;
//			}
//			else if (f(m) * f(r) < 0)
//				l = m;
//			else if (f(m) * f(l) < 0)
//				r = m;
//		}
//		if (count == 3)
//			break;
//	}
//	return 0;
//}


//int school[100010];
//
//int main()
//{
//	int m, n, sum = 0,t;
//	cin >> m >> n;
//	for (int i = 0;i < m;i++)
//		cin >> school[i];
//	sort(school, school + m);
//	while (n--)
//	{
//		cin >> t;
//		int a = *lower_bound(school, school + m, t),
//			b = *(lower_bound(school, school + m, t) - 1);
//		b = b == 0 ? a : b;
//		sum += min(abs(t-a),abs(b-t));
//	}
//	cout << sum;
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//
//inline void m_strcpy(char* a, const char* b)
//{
//	while (*a++ = *b++);
//}
//
//unsigned int m_strlen(const char* a)
//{
//	const char* p = a;
//	while (*++a);
//	return a - p;
//}
//
//int main()
//{
//	char a[] = "holle!";
//	char b[] = "what";
//	m_strcpy(a, b);
//	cout << a << endl;
//
//	cout << m_strlen(a);
//	return 0;
//}


//int main()
//{
//	int m, n;
//	cin >> m >> n;
//	set<int>scho;
//	for (int i = 0;i < m;i++)
//	{
//		int t;
//		cin >> t;
//		scho.insert(t);
//	}
//	int sum = 0;
//	while (n--)
//	{
//		int t,a,b;
//		cin >> t;
//		auto p = scho.lower_bound(t);
//		if (p == scho.end())
//		{
//			p--;
//			b = a = *p;
//		}
//		else if(p == scho.begin())
//		{
//			a = *p;
//			p++;
//			b = *p;
//		}
//		else
//		{
//			a = *p;
//			p--;
//			b = *p;
//		}
//		sum += min(abs(a - t), abs(b - t));
//	}
//	cout << sum;
//	return 0;
//}

//int arr[100010];
//int n, k;
//int f(int m)
//{
//	int s = 0;
//	for (int i = 0;i < n;i++)
//		s += arr[i] / m;
//	return s - k;
//}
//int main()
//{
//	cin >> n >> k;
//	int max  = 0;
//	for (int i = 0;i < n;i++)
//	{
//		cin >> arr[i];
//		max = max > arr[i] ? max : arr[i];
//	}
//	int l = 0, r = 100000001, m = 0, flag;
//	while (r-1 > l)
//	{
//		m = (l + r) >> 1;
//		flag = f(m);
//		if (flag >= 0)
//			l = m;
//		else
//			r = m;
//	}
//	cout << l;
//	return 0;
//}




//int node[1010] = { 0 };
//int way[1001][1001] = { 0 };
//int been[1001] = { 0 };
//	int n, m,t1,t2;
//void dfs(int x)
//{
//	been[x] = 1;
//	for (int i = 1;i <= n;i++)
//		if (way[x][i] && !been[i])
//			dfs(i);
//}
//
//
//int main()
//{
//	if (n == 2 && m % 2 == 0)
//	{
//		cout << 1;
//		return 0;
//	}
//	cin >> n >> m;
//	while (m--)
//	{
//		cin >> t1 >> t2;
//		way[t1][t2] = way[t2][t1] = 1;
//		node[t1]++;
//		node[t2]++;
//	}
//	for (int i = 1;i <= n;i++)
//		if (node[i] % 2 == 1)
//		{
//			cout << 0;
//			return 0;
//		}
//	dfs(1);
//	for(int i = 1;i <= n;i++)
//		if(!been[i])
//		{
//			cout << 0;
//			return 0;
//		}
//	cout << 1;
//	return 0;
//}


//int n, m, k;
//int way[10001][10001] = { 0 };
//void f(int np)
//{
//	int v;
//	cin >> v;
//	for (int i = 1;i <= n;i++)
//	{
//		if (way[i][v] == 1)
//			way[i][v]++;
//		if (way[v][i] == 1)
//			way[v][i]++;
//	}
//	if(np != 1)
//	f(np - 1);
//	else
//	{
//		for (int i = 1;i <= n;i++)
//		{
//			for(int j = 1;j <= n;j++)
//				if (way[i][j] == 1)
//				{
//					cout << "NO" << endl;
//					goto ss;
//				}
//		}
//		cout << "YES" << endl;
//	ss:;
//	}
//	for (int i = 1;i <= n;i++)
//	{
//		if (way[i][v] == 2)
//			way[i][v]--;
//		if (way[v][i] == 2)
//			way[v][i]--;
//	}
//}
//
//int main()
//{
//	cin >> n >> m;
//	while (m--)
//	{
//		int t1, t2;
//		cin >> t1 >> t2;
//		way[t1][t2] = way[t2][t1] = 1;
//	}
//	cin >> k;
//	while (k--)
//	{
//		int np;
//		cin >> np;
//		f(np);
//	}
//	return 0;
//}


int way[1001][2] = { 0 };
int main()
{
	int n, m,m2;
	cin >> n >> m;
	m2 = m;
	while (m--)
		cin >> way[m][0] >> way[m][1];
	int k;
	cin >> k;
	while (k--)
	{
		int q;
		cin >> q;
		set<int>se;
		while (q--)
		{
			int t;
			cin >> t;
			se.insert(t);
		}
		for(int i = 0;i < m2;i++)
			if (se.find(way[i][0]) == se.end() && se.find(way[i][1]) == se.end())
			{
				cout << "NO" << endl;
				goto ss;
			}
		cout << "YES" << endl;
	ss:;
	}
	return 0;
}