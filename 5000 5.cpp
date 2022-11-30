
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


//int way[1001][2] = { 0 };
//int main()
//{
//	int n, m,m2;
//	cin >> n >> m;
//	m2 = m;
//	while (m--)
//		cin >> way[m][0] >> way[m][1];
//	int k;
//	cin >> k;
//	while (k--)
//	{
//		int q;
//		cin >> q;
//		set<int>se;
//		while (q--)
//		{
//			int t;
//			cin >> t;
//			se.insert(t);
//		}
//		for(int i = 0;i < m2;i++)
//			if (se.find(way[i][0]) == se.end() && se.find(way[i][1]) == se.end())
//			{
//				cout << "NO" << endl;
//				goto ss;
//			}
//		cout << "YES" << endl;
//	ss:;
//	}
//	return 0;
//}



//int way[201][201] = { 0 };
//
//int main()
//{
//	int n, m,k;
//	cin >> n >> m;
//	for (int i = 0;i < m;i++)
//	{
//		int t1, t2;
//		cin >> t1 >> t2;
//		way[t1][t2] = way[t2][t1] = 1;
//	}
//	cin >> k;
//	while (k--)
//	{
//		int t,jud = 1;
//		cin >> t;
//		if (t != n + 1)
//			jud = 0;
//		queue<int>que;
//		int tmp,first;
//		cin >> first;
//		que.push(first);
//		while (--t)
//		{
//			cin >> tmp;
//			way[tmp][0]++;
//			que.push(tmp);
//			if (!way[que.front()][que.back()])
//				jud = 0;
//			que.pop();
//		}
//		for (int i = 1;i <= n;i++)
//		{
//			if (way[i][0] != 1)
//				jud = 0;
//			way[i][0]=0;
//		}
//		if (first != que.back())
//			jud = 0;
//		if (jud)
//			cout << "YES" << endl;
//		else
//			cout << "NO" << endl;
//	}
//	return 0;
//}





		
//int n, m, t1, t2, t3;
//int way[201][201] = { 0 }, been[201] = { 0 };
//
//int main()
//{
//	cin >> n >> m;
//	for (int i = 0;i < m;i++)
//	{
//		cin >> t1 >> t2 >> t3;
//		way[t1][t2] = way[t2][t1] = t3;
//	}
//	int k,np,mp = 0x0f3f3f3f,max = 0x0f3f3f3f,sum = 0,t;
//	cin >> k;
//	for(int x = 1;x <= k;x++)
//	{
//		int jud = 1, money = 0;
//		cin >> np;
//		if (np != n)
//			jud = 0;
//		queue<int>que;
//		cin >> t;
//		been[t]++;
//		if (way[0][t])
//			money += way[0][t];
//		else
//			jud = 0;
//		que.push(t);
//		while (--np)
//		{
//			cin >> t;
//			been[t]++;
//			que.push(t);
//			if (way[que.front()][que.back()])
//				money += way[que.front()][que.back()];
//			else
//				jud = 0;
//			que.pop();
//		}
//		if (way[t][0])
//			money += way[t][0];
//		else
//			jud = 0;
//		for (int i = 1;i <= n;i++)
//		{
//			if (been[i] != 1)
//				jud = 0;
//			been[i] = 0;
//		}
//		if (jud)
//		{
//			sum++;
//			if (money < max)
//			{
//				mp = x;
//				max = money;
//			}
//		}
//	}
//	cout << sum << endl << mp << " " << max;
//	return 0;
//}




bool way[1001][1001] = { 0 };
bool been[1001] = { 0 };
int road[3001] = { 0 };
int n, m, t1, t2, s,c = 0;
void search(int s,int x)
{
	road[x] = s;
	been[s]++;
	if (been[s] == 1)
		c++;
	if (c == n)
	{
		int i = 0;
		for (i = 0;road[i];i++)
			cout << road[i] << " ";
		for (i--;i >= 0;i--)
			cout << road[i] << " ";
	}
	else
	{
		for (int i = 1;i <= n;i++)
		{
			if (way[s][i])
				search(i,x+1);
		}
	}
}

int main()
{
	cin >> n >> m >> s;
	for (int i = 0;i < m;i++)
	{
		cin >> t1 >> t2;
		way[t1][t2] = way[t2][t1] = 1;
	}
	search(s,0);
	return 0;
}