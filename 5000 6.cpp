#define _CRT_SECURE_NO_WARNINGS
#define _SILENCE_CXX20_CISO646_REMOVED_WARNING
//#include<bits/stdc++.h>
//using namespace std;

//int fa[1010];
//void init(int n)
//{
//	for (int i = 0;i <= n;i++)fa[i]=i;
//}
//int find(int a)
//{
//	return a == fa[a] ? a : fa[a] = find(fa[a]);
//}
//void merg(int a, int b)
//{
//	int af = find(a);
//	int bf = find(b);
//	if (af != bf) fa[af] = bf;
//}
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n, m, cnt = 0;
//		cin >> n >> m;
//		init(n);
//		while (m--)
//		{
//			int a, b;
//			cin >> a >> b;
//			if (find(a) != find(b))
//				merg(a, b);
//		}
//		for (int i = 1;i <= n;i++)
//			if (i == fa[i])cnt++;
//		cout << cnt << endl;
//	}
//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//vector<int>fa;
//int find(int a)
//{
//	return a == fa[a] ? a : fa[a] = find(fa[a]);
//}
//void merg(int a, int b)
//{
//	int af = find(a);
//	int bf = find(b);
//	if (af != bf) fa[af] = bf;
//}
//
//int main()
//{
//	int n, m;
//	while (scanf("%d",&n), n)
//	{
//		fa.clear(), fa.resize(n+10);
//		for (int i = 1;i <= n;i++)
//			fa[i] = i;
//		scanf("%d", &m);
//		while (m--)
//		{
//			int a, b;
//			scanf("%d %d", &a, &b);
//			if (find(a) != find(b))
//				merg(a, b);
//		}
//		int cnt = 0;
//		for (int i = 1;i <= n;i++)
//			if (fa[i] == i)cnt++;
//		printf("%d\n", cnt-1);
//
//	}
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//
//struct road
//{
//	int a, b, val;
//	bool operator<(const road e)const
//	{
//		return val > e.val;
//	}
//};
//int fa[110] = { 0 };
//inline void init(int m)
//{
//	for (int i = 0;i <= m;i++)fa[i] = i;
//}
//inline int find(int a)
//{
//	return a == fa[a] ? a : fa[a] = find(fa[a]);
//}
//inline void merg(int a, int b)
//{
//	int af = find(a);
//	int bf = find(b);
//	if (af != bf) fa[af] = bf;
//}
//
//int main()
//{
//	int n, m;
//	while (scanf("%d",&n), n)
//	{
//		m = (n * (n - 1)) / 2;
//		init(n);
//		int sum = 0, cnt = 0;
//		priority_queue<road>que;
//		for (int i = 0;i < m;i++)
//		{
//			int a, b, v, f;
//			scanf("%d %d %d %d", &a, &b, &v, &f);
//			if(f && find(a) != find(b))
//				merg(a, b),cnt++;
//			else
//				que.push({ a,b,v });
//		}
//		while (cnt < n - 1)
//		{
//			if (que.empty())
//			{
//				puts("?");
//				break;
//			}
//			int a = que.top().a, b = que.top().b;
//			if (find(a) != find(b))
//			{
//				merg(a, b);
//				sum += que.top().val;
//				cnt++;
//			}
//			que.pop();
//		}
//		if (cnt == n - 1)
//			printf("%d\n", sum);
//	}
//	return 0;
//}




//#include<bits/stdc++.h>
//#include<iostream>
//
//using namespace std;
//
//int mp[105][105] = { 0 }, dis[105] = {0},vis[105] = {0};
//void init()
//{
//	memset(dis, 0, sizeof(dis));
//	memset(vis, 0, sizeof(vis));
//	memset(mp, 0, sizeof(mp));
//}
//
//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		init();
//		int n, m;
//		scanf("%d %d", &n, &m);
//		while (m--)
//		{
//			int a, b, v;
//			scanf("%d %d %d", &a, &b, &v);
//			mp[a][b] = mp[b][a] = v;
//		}
//		dis[1] = 0;
//		vis[1] = 1;
//		for (int i = 2;i <= n;i++)
//			if(mp[i][1])
//				dis[i] = mp[i][1];
//		int cnt = 1,ans = 0;
//		while (cnt < n)
//		{
//			int x = 0;
//			for (int i = 2;i <= n;i++)
//			{
//				if (vis[i])continue;
//				if (dis[i] && (x == 0 || dis[i] < dis[x]))
//					x = i;
//			}
//			vis[x] = 1;
//			cnt++;
//			ans += dis[x];
//			for (int i = 2;i <= n;i++)
//			{
//				if (vis[i] || mp[i][x]==0)continue;
//				if (dis[i] && dis[i] == mp[i][x])
//				{
//					puts("Not Unique!");
//					goto ss;
//				}
//				if (dis[i] == 0 || dis[i] > mp[i][x])
//					dis[i] = mp[i][x];
//			}
//		}
//		printf("%d\n", ans);
//	ss:;
//	}
//	return 0;
//}






//#include<iostream>
//using namespace std;
//int n, m;
//struct node
//{
//	int x, y;
//};
//node city[755] = { 0 };
//int mp[755][755] = { 0 }, vis[755] = { 0 };
//pair<int, int>dis[755];
//inline void updatedis(int a)
//{
//	for (int i = 1;i <= n;i++)
//	{
//		if (vis[i])continue;
//		if (mp[a][i] && (mp[a][i] < dis[i].first || !dis[i].first))
//		{
//			dis[i].first = mp[a][i], dis[i].second = a;
//		}
//	}
//}
//
//int main()
//{
//	memset(dis, 0, sizeof(dis));
//	cin >> n;
//	for (int i = 1;i <= n;i++)
//		cin >> city[i].x >> city[i].y;
//	for (int i = 1;i <= (n + 1) >> 1;i++)
//		for (int j = 1;j <= n;j++)
//		{
//			int dx = city[i].x - city[j].x, dy = city[i].y - city[j].y;
//			mp[i][j] = mp[j][i] = pow((dx * dx) + (dy * dy), 0.5);
//		}
//	int cnt = 0;
//	cin >> m;
//	while (m--)
//	{
//		int a, b;
//		cin >> a >> b;
//		if (!vis[a])vis[a] = 1, updatedis(a), cnt++;
//		if (!vis[b])vis[b] = 1, updatedis(b), cnt++;
//	}
//	while (cnt < n)
//	{
//		int x = 0;
//		for (int i = 1;i <= n;i++)
//		{
//			if (vis[i])continue;
//			if (dis[i].first && (x == 0 || dis[x].first > dis[i].first))
//				x = i;
//		}
//		cout << dis[x].second << " " << x << endl;
//		cnt++;
//		vis[x] = 1;
//		updatedis(x);
//	}
//	return 0;
//}




//#include<bits/stdc++.h>
//#include<iostream>
//#include<queue>
//using namespace std;
//struct node
//{
//	int x, y;
//};
//node city[755] = { 0 };
//struct road
//{
//	int a, b, val;
//	bool operator<(const road e)const
//	{
//		return val > e.val;
//	}
//};
//int fa[755] = { 0 };
//void init(int m)
//{
//	for (int i = 0;i <= m;i++)fa[i] = i;
//}
//int find(int a)
//{
//	return a == fa[a] ? a : fa[a] = find(fa[a]);
//}
//void merg(int a, int b)
//{
//	int af = find(a);
//	int bf = find(b);
//	if (af != bf) fa[af] = bf;
//}
//
//int main()
//{
//	int n, m;
//	cin >> m;
//	for (int i = 1;i <= m;i++)
//	{
//		cin >> city[i].x >> city[i].y;
//	}
//	init(m);
//	int cnt = 0;
//	priority_queue<road>que;
//	for (int i = 1;i <= (m+1)>>1;i++)
//		for (int j = 1;j <= m;j++)
//		{
//			if (i == j)continue;
//			int dx = city[i].x - city[j].x, dy = city[i].y - city[j].y;
//			int v = pow((dx * dx) + (dy * dy), 0.5);
//			que.push({ i,j,v });
//		}
//	cin >> n;
//	while (n--)
//	{
//		int a, b;
//		cin >> a >> b;
//		if (find(a) != find(b))
//		{
//			merg(a, b);
//			cnt++;
//		}
//	}
//	while (cnt < m - 1)
//	{
//		if (que.empty())
//		{
//			puts("?");
//			break;
//		}
//		int a = que.top().a, b = que.top().b;
//		if (find(a) != find(b))
//		{
//			cout << a << " " << b << endl;
//			merg(a, b);
//			cnt++;
//		}
//		que.pop();
//	}
//	return 0;
//}





//#include<bits/stdc++.h>
//using namespace std;
//char mp[10][10] = { 0 };
//int n, k, sum = 0, vis[10][10] = { 0 }, row[10],col[10];
//void search(int x,int cnt)
//{
//	if (cnt >= k)
//		sum++;
//	else
//	{
//		for (int i = x;i <= n;i++)
//			for (int j = 1;j <= n;j++)
//			{
//				if (mp[i][j] == '#' && !vis[i][j] && !row[i] && !col[j])
//				{
//					row[i] = col[j] = vis[i][j] = 1;
//					search(i+1, cnt+1);
//					row[i] = col[j] = vis[i][j] = 0;
//				}
//			}
//	}
//}
//void init()
//{
//	sum = 0;
//	memset(mp, 0, sizeof(mp));
//	memset(vis, 0, sizeof(vis));
//	memset(row, 0, sizeof(row));
//	memset(col, 0, sizeof(col));
//}
//
//int main()
//{
//	while (cin >> n >> k, (n != -1 && k != -1))
//	{
//		init();
//		for (int i = 1;i <= n;i++)
//			for (int j = 1;j <= n;j++)
//				cin >> mp[i][j];
//		search(1,0);
//		cout << sum << endl;
//	}
//	return 0;
//}





//#include<iostream>
//#include<queue>
//#include<stack>
//using namespace std;
//int mp[7][7] = { 0 }, vis[7][7] = { 0 };
//pair< int, int > fa[7][7];
//queue< pair<int, int> > que;
//
//int main()
//{
//	for (int j = 0;j <= 6;j++)mp[6][j] = mp[j][6] = mp[0][j] = mp[j][0] = 1;
//	for (int i = 1;i <= 5;i++)
//		for (int j = 1;j <= 5;j++)cin >> mp[i][j];
//	que.push({ 1,1 });
//	vis[1][1] = 1;
//	while (que.size())
//	{
//		int x = que.front().first, y = que.front().second;
//		que.pop();
//		for (int i = x - 1, j = y;i <= x + 1;i++)
//		{
//			if (!mp[i][j] && !vis[i][j])
//			{
//				que.push({ i,j });
//				vis[i][j] = 1;
//				fa[i - 1][j - 1] = { x - 1,y - 1 };
//				if (i == 5 && j == 5)
//					goto ss;
//			}
//		}
//		for (int j = y - 1, i = x;j <= y + 1;j++)
//		{
//			if (!mp[i][j] && !vis[i][j])
//			{
//				que.push({ i,j });
//				vis[i][j] = 1;
//				fa[i - 1][j - 1] = { x - 1,y - 1 };
//				if (i == 5 && j == 5)
//					goto ss;
//			}
//		}
//	}
//ss:;
//	int x = 4, y = 4;
//	stack< pair<int, int> > sta;
//	sta.push({ x,y });
//	while (x != 0 || y != 0)
//	{
//		pair<int, int>t = fa[x][y];
//		sta.push(t);
//		x = t.first, y = t.second;
//	}
//	while (sta.size())
//	{
//		printf("(%d, %d)\n", sta.top().first, sta.top().second);
//		sta.pop();
//	}
//	return 0;
//}




//#include<iostream>
//#include<queue>
//#include<stack>
//using namespace std;
//pair<int, int>tmpl[4];
//int mp[6][6] = { 0 };
//int vis[6][6] = { 0 };
//queue< pair<int,int> > que;
//pair<int, int>fa[6][6];
//
//int main()
//{
//	tmpl[0].first = 1, tmpl[0].second = 0;
//	tmpl[1].first = 0, tmpl[1].second = 1;
//	tmpl[2].first = -1, tmpl[2].second = 0;
//	tmpl[3].first = 0, tmpl[3].second = -1;
//	for (int i = 0;i < 5;i++)
//		for (int j = 0;j < 5;j++)
//			cin >> mp[i][j];
//	que.push( pair<int,int>(0,0) );
//	vis[0][0] = 1;
//	while (que.size())
//	{
//		pair<int, int> t = que.front();
//		que.pop();
//		for (int i = 0;i < 4;i++)
//		{
//			int a = t.first + tmpl[i].first, b = t.second + tmpl[i].second;
//			if (a >= 0 && a < 5 && b >= 0 && b < 5 && !vis[a][b] && mp[a][b] == 0)
//			{
//				fa[a][b] = t;
//				que.push(pair<int, int>(a, b));
//				vis[a][b] = 1;
//				if (a == 4 && b == 4)
//					goto ss;
//			}
//		}
//	}
//ss:;
//	stack< pair<int, int> >sta;
//	int x = 4, y = 4;
//	sta.push( pair<int, int>(4, 4) );
//	while (x != 0 || y != 0)
//	{
//		pair<int, int>t = fa[x][y];
//		sta.push(t);
//		x = t.first, y = t.second;
//	}
//	while (sta.size())
//	{
//		printf("(%d, %d)\n", sta.top().first, sta.top().second);
//		sta.pop();
//	}
//	return 0;
//}





//#include<iostream>
//#include<queue>
//using namespace std;
//struct node
//{
//	int z, x, y;
//	node(int a, int b, int c)
//	{
//		z = a, x = b, y = c;
//	}
//};
//char mp[31][31][31] = { 0 };
//char vis[31][31][31] = { 0 };
//
//void init()
//{
//	memset(mp, 0, sizeof(mp));
//	memset(vis, 0, sizeof(vis));
//}
//
//int main()
//{
//	int l, r, c;
//	while (cin >> l >> r >> c, l && r && c)
//	{
//		init();
//		int Z = 0, X = 0, Y = 0;
//		for (int i = 0;i < l;i++)
//		{
//			for (int x = 0;x < r;x++)
//				for (int y = 0;y < c;y++)
//				{
//					cin >> mp[i][x][y];
//					if (mp[i][x][y] == 'S')
//					{
//						Z = i, X = x, Y = y;
//					}
//				}
//			getchar();
//		}
//		int ans = -2;
//		queue< pair<node,int> >que;
//		que.push(make_pair(node(Z, X, Y), 0) );
//		vis[Z][X][Y] = 1;
//		while (que.size())
//		{
//			node tmp = que.front().first;
//			int cnt = que.front().second;
//			ans = cnt + 1;
//			que.pop();
//			for (int x = tmp.x - 1;x <= tmp.x + 1;x++)
//			{
//				if (x < 0 || x >= r)continue;
//				if (mp[tmp.z][x][tmp.y] == 'E')
//					goto ss;
//				if (mp[tmp.z][x][tmp.y] == '.' && !vis[tmp.z][x][tmp.y])
//				{
//					vis[tmp.z][x][tmp.y] = 1;
//					que.push( make_pair( node( tmp.z, x, tmp.y ),cnt+1) );
//				}
//			}
//			for (int y = tmp.y - 1;y <= tmp.y + 1;y++)
//			{
//				if (y < 0 || y >= c)continue;
//				if (mp[tmp.z][tmp.x][y] == 'E')
//					goto ss;
//				if (mp[tmp.z][tmp.x][y] == '.' && !vis[tmp.z][tmp.x][y])
//				{
//					vis[tmp.z][tmp.x][y] = 1;
//					que.push( make_pair( node( tmp.z, tmp.x, y ),cnt+1) );
//				}
//			}
//			for (int z = tmp.z - 1;z <= tmp.z + 1;z++)
//			{
//				if (z < 0 || z >= l)continue;
//				if (mp[z][tmp.x][tmp.y] == 'E')
//					goto ss;
//				if (mp[z][tmp.x][tmp.y] == '.' && !vis[z][tmp.x][tmp.y])
//				{
//					vis[z][tmp.x][tmp.y] = 1;
//					que.push( make_pair( node( z, tmp.x, tmp.y ),cnt+1) );
//				}
//			}
//		}
//		cout << "Trapped!\n";
//		continue;
//	ss:;
//		cout << "Escaped in " << ans << " minute(s).\n";
//
//	}
//	return 0;
//}




//#include<iostream>
//using namespace std;
//int fa[110] = { 0 };
//int find(int a)
//{
//	return a == fa[a] ? a : fa[a] = find(fa[a]);
//}
//void merg(int a, int b)
//{
//	int af = find(a);
//	int bf = find(b);
//	fa[af] = bf;
//}
//
//int main()
//{
//	for (int i = 1;i < 110;i++)fa[i] = i;
//	int n, m;
//	cin >> n >> m;
//	while (m--)
//	{
//		int a, b;
//		cin >> a >> b;
//		if (find(a) != find(b))
//			merg(a, b);
//	}
//	int ans = 0;
//	for (int i = 1;i <= n;i++)
//		if (fa[i] == i)ans++;
//	cout << ans;
//	return 0;
//}



//
//#include<iostream>
//#include<algorithm>
//#include<queue>
//using namespace std;
//vector<int>sub[110];
//int du[110] = {0},vis[110] = {0};
//struct node
//{
//	int id, ti;
//};
//node tim[110] = { 0 };
//bool cmp(node e1, node e2)
//{
//	return e1.ti < e2.ti;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	for (int i = 1;i <= n;i++)
//	{
//		tim[i].id = i;
//		int t;
//		while (cin >> t, t)
//		{
//			sub[i].push_back(t);
//			du[t]++;
//		}
//	}
//	queue<int>que;
//	for (int i = 1;i <= n;i++)
//	{
//		if (!du[i])
//		{
//			que.push(i);
//			vis[i] = 1;
//			tim[i].ti = 0;
//		}
//	}
//	while (que.size())
//	{
//		int x = que.front();
//		que.pop();
//		for (int i = 0;i < sub[x].size();i++)
//			du[sub[x][i]]--;
//		for (int i = 0;i < sub[x].size();i++)
//		{
//			int t = sub[x][i];
//			if (du[t] == 0 && vis[t] == 0)
//			{
//				que.push(t);
//				vis[t] = 1;
//				tim[t].ti = tim[x].ti + 1;
//			}
//		}
//	}
//	sort(tim + 1, tim + 1 + n,cmp);
//	for (int i = 1;i <= n;i++)
//		cout << tim[i].id << " ";
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//int pre[10][10][10][10] = { 0 };
//
//int main()
//{
//	int a[4];
//	for(a[0] = 0;a[0] <= 9;a[0] ++)
//		for(a[1] = 0;a[1] <=9;a[1]++)
//			for(a[2] = 0;a[2] <= 9;a[2]++)
//				for (a[3] = 0;a[3] <= 9;a[3]++)
//				{
//					int t[4] = { 0 }, sum = 0,last = 0,f = 1;
//					while (f)
//					{
//						f = 0;
//						for (int i = 0;i < 4;i++)
//						{
//							if (t[i] < a[i])
//							{
//								t[i]++;
//								f = 1;
//								if (!last)
//									sum++;
//								last = 1;
//							}
//							else
//								last = 0;
//						}
//					}
//					pre[a[0]][a[1]][a[2]][a[3]] = sum;
//
//					//sum = last = t[0] = t[1] = t[2] = t[3] = 0; f = 1;
//					//while (f)
//					//{
//					//	f = 0;
//					//	for (int i = 0;i < 4;i++)
//					//	{
//					//		if (t[i] < 10-a[i])
//					//		{
//					//			t[i]++;
//					//			f = 1;
//					//			if (!last)
//					//				sum++;
//					//			last = 1;
//					//		}
//					//		else
//					//			last = 0;
//					//	}
//					//}
//					//if (pre[a[0]][a[1]][a[2]][a[3]] > sum) pre[a[0]][a[1]][a[2]][a[3]] = sum;
//				}
//	int t;
//	cin >> t;
//	while(t--)
//	{
//		char a[5] = { 0 }, b[5] = { 0 };
//		cin >> a >> b;
//		int m = 20;
//		for (int i = 0;i < 4;i++)
//		{
//			a[i] = b[i] - a[i];
//			if (a[i] < 0) a[i] += 10;
//		}
//		cout << min(pre[a[0]][a[1]][a[2]][a[3]], pre[10 - a[0]][10 - a[1]][10 - a[2]][10 - a[3]]) << endl;
//	}
//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//
//int main()
//{
//	string a, b;
//	while (cin >> a >> b)
//	{
//		int al = a.size(), bl = b.size();
//		vector< vector<int> >dp(al+1);
//		dp[0].resize(bl + 1);
//		for (int i = 1;i <= al; i++)
//		{
//			dp[i].resize(bl+1);
//			for (int j = 1;j <= bl;j++)
//			{
//				if (a[i-1] == b[j-1]) dp[i][j] = dp[i - 1][j - 1] + 1;
//				else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//			}
//		}
//		cout << dp[al][bl] << endl;
//	}
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//int dp[1011] = { 0 }, val[1011] = { 0 }, w[1011] = { 0 };
//void init()
//{
//	memset(w, 0, sizeof(w));
//	memset(dp, 0, sizeof(dp));
//	memset(val, 0, sizeof(val));
//}
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		init();
//		int n, v;
//		cin >> n >> v;
//		for (int i = 1;i <= n;i++) cin >> val[i];
//		for (int j = 1;j <= n;j++) cin >> w[j];
//		for (int i = 1;i <= n;i++)
//		{
//			for (int j = v;j >= 0;j--)
//			{
//				if (w[i] <= j) dp[j] = max(dp[j], dp[j - w[i]] + val[i]);
//			}
//		}
//		cout << dp[v] << endl;
//	}
//	return 0;
//}





//#include<bits/stdc++.h>
//using namespace std;
//int dp[10010], v[510], w[510];
//void init()
//{
//	memset(dp, 0x3f, sizeof(dp));
//	dp[0] = 0;
//}
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		init();
//		int e, f, m, n;
//		cin >> e >> f;
//		m = f - e;
//		cin >> n;
//		for (int i = 1;i <= n;i++) cin >> v[i] >> w[i];
//		for(int j = 0;j <= m;j++)
//			for (int i = 1;i <= n;i++)
//				if (j >= w[i]) dp[j] = min(dp[j], dp[j - w[i]] + v[i]);
//		if (dp[m] == 0x3f3f3f3f) cout << "This is impossible.\n";
//		else cout << "The minimum amount of money in the piggy-bank is " << dp[m] << ".\n";
//	}
//	return 0;
//}

//
//#include<bits/stdc++.h>
//using namespace std;
//struct node
//{
//	int w, s, k, dp;
//};
//int pre[1010];
//bool cmp(node e1, node e2)
//{
//	return e1.w < e2.w;
//}
//
//int main()
//{
//	vector<node>vec;
//	vec.push_back({ 0,0,0,0 });
//	for (int a, b, i = 1;cin >> a >> b;i++)
//		pre[i] = i, vec.push_back({ a,b,i,0 });
//	sort(vec.begin(), vec.end(),cmp);
//	int n = -1+vec.size();
//	int m = 0;
//	for (int i = 1;i <= n;i++)
//	{
//		for (int j = 0;j <= n;j++)
//		{
//			if (vec[i].w > vec[j].w && vec[i].s < vec[j].s && vec[i].dp <= vec[j].dp)
//			{
//				vec[i].dp = vec[j].dp + 1;
//				pre[vec[i].k] = vec[j].k;
//			}
//		}
//		if (vec[i].dp > vec[m].dp) m = i;
//	}
//	cout << vec[m].dp+1 << '\n';
//	stack<int>sta;
//	while (m != pre[m])
//	{
//		sta.push(m);
//		m = pre[m];
//	}
//	sta.push(m);
//	while (sta.size())
//	{
//		cout << sta.top() << '\n';
//		sta.pop();
//	}
//	return 0;
//}





//#include<bits/stdc++.h>
//using namespace std;
//vector< pair<int,int> >adj[100010];
//priority_queue< pair<int, int> ,vector<pair<int,int> >, greater< pair<int,int> > >que;
//int vis[100010] = { 0 }, dp[100010];
//int main()
//{
//	memset(dp, 0x3f, sizeof(dp));
//	int n, m, s;
//	cin >> n >> m >> s;
//	for (int i = 1, a, b, c;i <= m;i++)
//	{
//		cin >> a >> b >> c;
//		adj[a].push_back({ b,c });
//	}
//	que.push({ 0,s });
//	dp[s] = 0;
//	while (que.size())
//	{
//		int u = que.top().second;que.pop();
//		if (vis[u]) continue;
//		vis[u] = 1;
//		for (auto [v, w] : adj[u])
//		{
//			dp[v] = min(dp[v], dp[u] + w);
//			que.push({ dp[v],v });
//		}
//	}
//	for (int i = 1;i <= n;i++)
//		cout << dp[i] << ' ';
//	return 0;
//}





//#include<bits/stdc++.h>
//using namespace std;
//int n, m, M, sum = 0;
//vector< pair<int, int> >adj[2010];
//int dp[2010], vis[2010], cnt[2010] = { 0 };
//void init(int n)
//{
//	memset(vis, 0, sizeof(vis));
//	memset(dp, 0x3f, sizeof(dp));
//	dp[1] = 0;
//	for (int i = 1;i <= n;i++)
//		adj[i].clear();
//}
//
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//
//		cin >> n >> m; M = m;
//		init(n);
//		for (int i = 0, a, b, c;i < m;i++)
//		{
//			cin >> a >> b >> c;
//			adj[a].push_back({ b,c });
//			if (c >= 0)
//				adj[b].push_back({ a,c }),M++;
//		}
//		queue<int>que;
//		que.push(1);vis[1] = 1,cnt[1] = 0;
//		while (que.size())
//		{
//			int u = que.front();
//			if (cnt[u] > n)
//			{
//				cout << "YES\n";
//				goto ss;
//			}
//			vis[u] = 0;que.pop();
//			for (auto [v, w] : adj[u])
//			{
//				if (dp[v] > dp[u] + w)
//				{
//					dp[v] = dp[u] + w;
//					cnt[v] = cnt[u] + 1;
//					if (!vis[v])
//						que.push(v);
//				}
//			}
//		}
//		cout << "NO\n";
//	ss:;
//	}
//	return 0;
//}





#include<bits/stdc++.h>
using namespace std;
vector< pair<int, int> >adj[105];
int dp[105][105] = { 0 };

int main()
{
	memset(dp, 0x3f, sizeof(dp));
	int n, m;
	cin >> n >> m;
	for (int i = 0, a, b, c;i < m;i++)
	{
		cin >> a >> b >> c;
		dp[a][b] = dp[b][a] = c;
	}
	for (int k = 1;k <= n;k++)
		for (int u = 1;u <= n;u++)
			for (int v = 1;v <= n;v++)
				dp[u][v] = min(dp[u][v], dp[u][k] + dp[k][v]),dp[u][u] = 0;
	
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			cout << dp[i][j];
			if (j == n) puts("");
			else cout << ' ';
		}
	}

	return 0;
}