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





//#include<bits/stdc++.h>
//using namespace std;
//vector< pair<int, int> >adj[105];
//int dp[105][105] = { 0 };
//
//int main()
//{
//	memset(dp, 0x3f, sizeof(dp));
//	int n, m;
//	cin >> n >> m;
//	for (int i = 0, a, b, c;i < m;i++)
//	{
//		cin >> a >> b >> c;
//		dp[a][b] = dp[b][a] = c;
//	}
//	for (int k = 1;k <= n;k++)
//		for (int u = 1;u <= n;u++)
//			for (int v = 1;v <= n;v++)
//				dp[u][v] = min(dp[u][v], dp[u][k] + dp[k][v]),dp[u][u] = 0;
//	
//	for (int i = 1;i <= n;i++)
//	{
//		for (int j = 1;j <= n;j++)
//		{
//			cout << dp[i][j];
//			if (j == n) puts("");
//			else cout << ' ';
//		}
//	}
//
//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//struct node
//{
//	int x, y;
//};
//node adj[1010] = { 0 };
//double v1, v2, delt, t = 0;
//int vis[1010] = { 0 };
//double d[1010] = { 0 };
//double tim(int u, int v, double t)
//{
//	double d = sqrt((adj[u].x - adj[v].x) * (adj[u].x - adj[v].x)\
//		+ (adj[u].y - adj[v].y) * (adj[u].y - adj[v].y));
//	if (d > delt + t * v2)
//	{
//
//	}
//	return 
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	for (int i = 1;i <= n;i++)
//		cin >> adj[i].x >> adj[i].y, d[i] = -1;
//	cin >> adj[n+1].x >> adj[n+1].y >> adj[0].x >> adj[0].y >> v1 >> v2;
//	n += 2; delt = v2 * 3.0;
//	d[n - 1] = sqrt((adj[n - 1].x - adj[0].x) * (adj[n - 1].x - adj[0].x)\
//		+(adj[n - 1].y - adj[0].y) * (adj[n - 1].y - adj[0].y)) / v1;
//	d[0] = 0;
//
//	vis[0] = 1;
//	for (int i = 0;i < n;i++)
//	{
//		int u = 0;
//		for (int j = 0;j < n;j++)
//		{
//			if (!vis[j] && d[j] != -1 && (u == 0 || d[j] < d[u])) u = j;
//		}
//		vis[u] = 1;
//		for (int v = 0;v < n;v++)
//		{
//			double tmp = tim(u, v);
//			if (d[v] == -1 || d[v] < d[u] + tmp)
//				d[v] = d[u] + tmp;
//		}
//	}
//	cout << 
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//int n, m, s;
//int ans[500010] = { 0 }, vis[500010] = { 0 }, fa[500010] = { 0 };
//vector<int>son[500010];
//vector< pair<int,int> >q[500010];
//int find(int a)
//{
//	return fa[a] == a ? a : fa[a] = find(fa[a]);
//}
//void merg(int u, int f)
//{
//	u = find(u);
//	f = find(f);
//	if (u != f) fa[u] = f;
//}
//void dfs(int u,int f)
//{
//
//	vis[u] = 1;
//	for (auto& [v, k] : q[u])
//	{
//		if (ans[k]) continue;
//		if (vis[v]) ans[k] = find(v);
//	}
//	for (auto& v : son[u])
//	{
//		if (!vis[v])
//			dfs(v, u);
//	}
//	merg(u, f);
//	
//
//}
//
//int main()
//{
//	cin >> n >> m >> s;
//	for (int i = 1;i <= n;i++) fa[i] = i;
//	for (int i = 0, x, y;i < n - 1;i++)
//	{
//		cin >> x >> y;
//		son[x].push_back(y);
//		son[y].push_back(x);
//	}
//	for (int i = 0, a, b;i < m;i++)
//	{
//		cin >> a >> b;
//		q[a].push_back({ b,i });
//		q[b].push_back({ a,i });
//	}
//
//	dfs(s,s);
//
//	for (int i = 0;i < m;i++)
//		cout << ans[i] << '\n';
//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//const long long N = 500010;
//vector<int>mp[N];
//int n, m, s, dep[N] = { 0 }, par[N][20] = { 0 };
//void dfs(int u, int fa)
//{
//	dep[u] = dep[fa] + 1;
//	par[u][0] = fa;
//	for (int i = 1;i < 20;i++)
//		par[u][i] = par[par[u][i - 1]][i - 1];
//	for (auto& v : mp[u])
//	{
//		if (v == fa)continue;
//		dfs(v, u);
//	}
//}
//int getlca(int u, int v)
//{
//	if (dep[u] < dep[v]) swap(u, v);
//	for (int i = 19;i >= 0;i--)
//	{
//		if (dep[par[u][i]] >= dep[v])
//			u = par[u][i];
//	}
//	if (u == v) return u;
//	for (int i = 19;i >= 0;i--)
//	{
//		if (par[u][i] != par[v][i])
//			u = par[u][i], v = par[v][i];
//	}
//	return par[u][0];
//}
//
//
//int main()
//{
//	scanf("%d %d %d", &n, &m, &s);
//	for (int i = 0,a,b;i < n - 1;i++)
//	{
//		scanf("%d %d", &a, &b);
//		mp[a].push_back(b);
//		mp[b].push_back(a);
//	}
//	dfs(s, 0);
//	for (int i = 0,u,v;i < m;i++)
//	{
//		scanf("%d %d", &u, &v);
//		printf("%d\n", getlca(u, v));
//	}
//
//
//	return 0;
//}



//#include<iostream>
//#include<vector>
//using namespace std;
//vector<int>mp[910];
//vector<int>Q[910];
//int n, m, rt, vis[910] = { 0 }, cnt[910] = { 0 }, fa[910] = { 0 };
//int find(int u)
//{
//	return u == fa[u] ? u : fa[u] = find(fa[u]);
//}
//void merg(int u, int f)
//{
//	u = find(u);
//	f = find(f);
//	if (u != f)
//		fa[u] = f;
//}
//void init()
//{
//	memset(vis, 0, sizeof(vis));
//	memset(cnt, 0, sizeof(cnt));
//}
//void dfs(int u, int fa)
//{
//	vis[u] = 1;
//	for (int i = 0;i < Q[u].size();i++)
//	{
//		if (vis[Q[u][i]])
//			cnt[find(Q[u][i])]++;
//	}
//	for (int i = 0;i < mp[u].size();i++)
//	{
//		if (!vis[mp[u][i]])
//			dfs(mp[u][i], u);
//	}
//	merg(u, fa);
//}
//
//int main()
//{
//	while (~scanf("%d", &n))
//	{
//		init();
//		for (int i = 0,k,s;i < n;i++)
//		{
//			scanf("%d:(%d)", &k, &s);
//			mp[k].clear();Q[k].clear();fa[k] = k;
//			for (int j = 0, t;j < s;j++)
//			{
//				scanf("%d", &t);
//				vis[t] = 1;
//				mp[k].push_back(t);
//			}
//		}
//		for (int i = 1;i <= n;i++) if (!vis[i]) rt = i;
//
//		memset(vis, 0, sizeof(vis));
//		scanf("%d", &m);
//		for (int i = 0, u, v;i < m;i++)
//		{
//			scanf(" (%d %d)", &u, &v);
//			Q[u].push_back(v);
//			if(u != v)
//				Q[v].push_back(u);
//		}
//		dfs(rt, 0);
//
//		for (int i = 1;i <= n;i++)
//		{
//			if (cnt[i])
//			{
//				printf("%d:%d\n", i, cnt[i]);
//			}
//		}
//	}
//	return 0;
//}





//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 1000010;
//ll a[N] = { 0 }, t[N] = { 0 };
//int n, q;
//int lowbit(int x)
//{
//	return x & -x;
//}
//
//void add(int i, int val)
//{
//	while (i <= n)
//	{
//		t[i] += val;
//		i += lowbit(i);
//	}
//}
//
//ll getsum(int x)
//{
//	ll sum = 0;
//	while (x)
//	{
//		sum += t[x];
//		x -= lowbit(x);
//	}
//	return sum;
//}
//
//int main()
//{
//	
//	cin >> n >> q;
//	for (int i = 1;i <= n;i++)
//	{
//		scanf("%d", &a[i]);
//		add(i, a[i]);
//	}
//	int tmp,a,b;
//	while (q--)
//	{
//		scanf("%d %d %d", &tmp, &a, &b);
//		if (tmp == 1) add(a, b);
//		else
//		{
//			printf("%d\n", getsum(b) - getsum(a - 1));
//		}
//	}
//
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 1000010;
//ll t[N] = { 0 };
//int n, q, a[2] = { 0 };
//int lowbit(int x)
//{
//	return x & -x;
//}
//void add(int i, ll val)
//{
//	while (i <= n)
//	{
//		t[i] += val;
//		i += lowbit(i);
//	}
//}
//ll getsum(int x)
//{
//	ll sum = 0;
//	while (x > 0)
//	{
//		sum += t[x];
//		x -= lowbit(x);
//	}
//	return sum;
//}
//
//
//int main()
//{
//	std::ios::sync_with_stdio(false);
//	cin.tie(0);  cout.tie(0);
//
//	cin >> n >> q;
//	for (int i = 1,now = 1,last = 0;i <= n;i++)
//	{
//		cin >> a[now];
//		add(i, a[now] - a[last]);
//		swap(now, last);
//	}
//	int k, b, c, d;
//	while (q--)
//	{
//		cin >> k >> b;
//		if (k == 1)
//		{
//			cin >> c >> d;
//			add(b, d);
//			add(c + 1, -d);
//		}
//		else
//			printf("%lld\n", getsum(b));
//	}
//	return 0;
//}
//




//#include<stdio.h>
//#include<string.h>
//char a[100006], b[100006];
//int main()
//{
//	while (~scanf("%s %s", a, b))
//	{
//		int len = strlen(b), x;
//		scanf("%d", &x);
//		for (int i = 0;i < len;i++)
//		{
//			if (i == x)
//				printf("%s", a);
//			printf("%c", b[i]);
//		}
//		if (x == len)
//			printf("%s", a);
//		puts("");
//	}
//	return 0;
//}




//
//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 1000010;
//ll t[N] = { 0 }, t2[N] = { 0 };
//int n, q, a[2] = { 0 }, b[2] = { 0 };
//int lowbit(int x)
//{
//	return x & -x;
//}
//void add(int i, ll val)
//{
//	ll val2 = val * i;
//	while (i <= n)
//	{
//		t[i] += val;
//		t2[i] += val2;
//		i += lowbit(i);
//	}
//}
//ll getsum(int x)
//{
//	ll sum = 0, sum2 = 0, i = x;
//	while (x > 0)
//	{
//		sum += t[x];
//		sum2 += t2[x];
//		x -= lowbit(x);
//	}
//	return (i+1)*sum - sum2;
//}
//
//
//int main()
//{
//	std::ios::sync_with_stdio(false);
//	cin.tie(0);  cout.tie(0);
//
//	cin >> n >> q;
//	for (int i = 1, now = 1, last = 0;i <= n;i++)
//	{
//		cin >> a[now];
//		b[now] = a[now] - a[last];
//		add(i, b[now] - b[last]);
//		swap(now, last);
//	}
//	int f, l, r, k, d;
//	while (q--)
//	{
//		cin >> f;
//		if (f == 1)
//		{
//			cin >> l >> r >> k >> d;
//			add(l,k);
//			add(l + 1, d-k);
//			add(r+1, -d-k-((r-l)*d));
//			add(r + 2, k+(r-l)*d);
//		}
//		else
//		{
//			cin >> r;
//			printf("%lld\n", getsum(r));
//		}
//	}
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//struct Info
//{
//	int pre, suf, ans;
//	Info operator+(const Info& e)const
//	{
//		Info ret = { 0 };
//		ret.ans = ans + e.ans;
//		int merg = min(pre, e.suf);
//		ret.ans += merg << 1;
//		ret.pre = pre + e.pre - merg;
//		ret.suf = suf + e.suf - merg;
//		return ret;
//	}
//};
//struct node
//{
//	int l, r;
//	Info val;
//};
//string s;
//const int N = 4e6 + 10;
//int q, a, b;
//node t[N] = { 0 };
//void up(int k)
//{
//	t[k].val.ans += t[k << 1].val.ans + t[k << 1 | 1].val.ans;
//	int pre = t[k << 1].val.pre, suf = t[k << 1 | 1].val.suf;
//	int merg = min(pre, suf);
//	t[k].val.ans += merg << 1;
//	t[k].val.pre = pre - merg + t[k<<1|1].val.pre;
//	t[k].val.suf = suf - merg + t[k<<1].val.suf;
//}
//void build(int k, int ql, int qr)
//{
//	t[k].l = ql;
//	t[k].r = qr;
//	if (ql == qr)
//	{
//		if (s[ql] == '(') t[k].val.pre = 1;
//		else if (s[ql] == ')') t[k].val.suf = 1;
//	}
//	else
//	{
//		int mid = (ql + qr) >> 1;
//		build(k << 1, ql, mid);
//		build(k << 1 | 1, mid + 1, qr);
//		up(k);
//	}
//}
//Info query(int k,int ql, int qr)
//{
//	if (t[k].l >= ql && t[k].r <= qr)
//		return t[k].val;
//	int mid = (t[k].l+t[k].r) >> 1;
//	if (qr <= mid)	return query(k << 1, ql, qr);
//	else if (ql > mid)	return query(k << 1 | 1, ql, qr);
//	else return query(k << 1, ql, qr) + query(k << 1 | 1, ql, qr);
//}
//
//int main()
//{
//	cin >> s;
//	s = "?" + s;
//	build(1,1,s.size());
//	cin >> q;
//	while (q--)
//	{
//		cin >> a >> b;
//		cout << query(1, a, b).ans << '\n';
//	}
//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//struct node
//{
//	int l, r, val;
//};
//const int N = 1e5 + 10;
//int t, n, q, a[N], k,don;
//node seg[N << 2];
//void init()
//{
//	memset(a, 0, sizeof(a));
//	memset(seg, 0, sizeof(seg));
//}
//void up(int k)
//{
//	seg[k].val = seg[k << 1].val + seg[k << 1 | 1].val;
//}
//void build(int id, int ql, int qr)
//{
//	seg[id].l = ql;
//	seg[id].r = qr;
//	if (ql == qr)
//	{
//		seg[id].val = a[ql];
//	}
//	else
//	{
//		int mid = (ql + qr) >> 1;
//		build(id << 1, ql, mid);
//		build(id << 1 | 1, mid + 1, qr);
//		up(id);
//	}
//}
//void change(int id, int qi, int qv)
//{
//	int l = seg[id].l, r = seg[id].r;
//	if (l == r)
//	{
//		if (!qv)	don = seg[id].val, seg[id].val = 0;
//		else	seg[id].val += qv;
//		return;
//	}
//	int mid = (l + r) >> 1;
//	if (qi <= mid) change(id << 1, qi, qv);
//	else change(id << 1 | 1, qi, qv);
//	up(id);
//}
//int query(int id, int ql, int qr)
//{
//	int l = seg[id].l;
//	int r = seg[id].r;
//	if (l >= ql && r <= qr) return seg[id].val;
//	int mid = (l + r) >> 1;
//	if (qr <= mid) return query(id << 1, ql, qr);
//	else if (ql > mid) return query(id << 1 | 1, ql, qr);
//	else return query(id << 1, ql, qr) + query(id << 1 | 1, ql, qr);
//}
//
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
//	
//	cin >> t;
//	for(int num = 1;num <= t;num++)
//	{
//		cout << "Case " << num << ":\n";
//		init();
//		cin >> n >> q;
//		for (int i = 0;i < n;i++)
//			cin >> a[i];
//		build(1,0,n-1);
//		int i, v, j;
//		while (q--)
//		{
//			cin >> k;
//			if (k == 1)
//			{
//				cin >> i;
//				change(1, i, 0);
//				cout << don << '\n';
//			}
//			else if (k == 2)
//			{
//				cin >> i >> v;
//				change(1, i, v);
//			}
//			else
//			{
//				cin >> i >> j;
//				cout << query(1, i, j) << '\n';
//			}
//		}
//	}
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 2e5 + 5;
//struct node
//{
//	int l, r, Max;
//};
//node seg[N << 2];
//int m, p, last = 0,len = 0;
//ll t;
//char k;
//void add(int t)
//{
//	seg[len].Max = t;
//	seg[len].l = 
//}
//
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	cin >> m >> p;
//	while (m--)
//	{
//		getchar();
//		cin >> k >> t;
//		if (k == 'A')
//		{
//			len++;
//			add((t + last) % p);
//		}
//		else if (k == 'Q')
//		{
//
//		}
//	}
//	return 0;
//}




//
//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 1e6 + 5;
//struct node
//{
//	ll l, r;
//	ll tag, sum;
//};
//node seg[N << 2];
//ll n, q, a[N] = { 0 }, f,qa,qb,x;
//void up(ll k)
//{
//	seg[k].sum = seg[k << 1].sum + seg[k << 1 | 1].sum;
//}
//void build(ll id, ll ql, ll qr)
//{
//	seg[id].l = ql;
//	seg[id].r = qr;
//	if (ql == qr)
//	{
//		seg[id].sum = a[ql];
//		return;
//	}
//	ll mid = (ql + qr) >> 1;
//	build(id << 1, ql, mid);
//	build(id << 1 | 1, mid + 1, qr);
//	up(id);
//}
//void settag(ll id,ll x)
//{
//	seg[id].sum += (seg[id].l - seg[id].r + 1) * x;
//	seg[id].tag += x;
//}
//void down(ll k)
//{
//	if (!seg[k].tag) return;
//	ll tag = seg[k].tag;
//	seg[k].tag = 0;
//	settag(k << 1, tag);
//	settag(k << 1 | 1, tag);
//}
//ll query(ll id, ll ql, ll qr)
//{
//	ll l = seg[id].l;
//	ll r = seg[id].r;
//	if (l >= ql && r <= qr) return seg[id].sum;
//	ll mid = (l + r) >> 1;
//	if (seg[id].tag) down(id);
//	if (qr <= mid) return query(id << 1, ql, qr);
//	else if (ql > mid) return query(id << 1 | 1, ql, qr);
//	else return query(id << 1, ql, qr) + query(id << 1 | 1, ql, qr);
//}
//void modify(ll id,ll ql,ll qr,ll x)
//{
//	ll l = seg[id].l;
//	ll r = seg[id].r;
//	if (l >= ql && r <= qr)
//	{
//		settag(id,x);
//		return;
//	}
//	ll mid = (l + r) >> 1;
//	if (seg[id].tag) down(id);
//	if (qr <= mid) modify(id << 1, ql, qr, x);
//	else if (ql > mid) modify(id << 1 | 1, ql, qr, x);
//	else modify(id << 1, ql, qr, x), modify(id << 1 | 1, ql, qr, x);
//	up(id);
//}
//
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	cin >> n >> q;
//	for (ll i = 1;i <= n;i++)
//		cin >> a[i];
//	build(1, 1, n);
//	while (q--)
//	{
//		cin >> f >> qa >> qb;
//		if (f == 1)
//		{
//			cin >> x;
//			modify(1,qa,qb,x);
//		}
//		else
//		{
//			cout << query(1, qa, qb) << '\n';
//		}
//	}
//	return 0;
//}





//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int M = 2e5 + 10;
//struct node
//{
//	int l, r, Max;
//}seg[M << 2];
//int m, len = 0;
//ll t, last = 0, p;
//char f;
//
//void up(int k)
//{
//	seg[k].Max = max(seg[k << 1].Max, seg[k << 1 | 1].Max);
//}
//
//void build(int id, int ql, int qr)
//{
//	seg[id].l = ql;
//	seg[id].r = qr;
//	if (qr == ql)
//	{
//		seg[id].Max = 0;
//		return;
//	}
//		int mid = (qr + ql) >> 1;
//		build(id << 1, ql, mid);
//		build(id << 1 | 1, mid + 1, qr);
//}
//
//void change(int id, int i, int val)
//{
//	int l = seg[id].l;
//	int r = seg[id].r;
//	if (l == r)
//	{
//		seg[id].Max = val;return;
//	}
//	int mid = (l + r) >> 1;
//	if (i <= mid) change(id << 1, i, val);
//	else change(id << 1 | 1, i, val);
//	up(id);
//}
//
//int query(int id, int ql,int qr)
//{
//	int l = seg[id].l;
//	int r = seg[id].r;
//	if (l >= ql && r <= qr) return seg[id].Max;
//	int mid = (l + r) >> 1;
//	if (qr <= mid) return query(id << 1, ql,qr);
//	else if (ql > mid) return query(id << 1 | 1, ql,qr);
//	else return max(query(id << 1, ql,qr), query(id << 1 | 1, ql,qr));
//}
//
//
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	build(1, 1, M);
//	cin >> m >> p;
//	while (m--)
//	{
//		cin >> f >> t;
//		if (f == 'A')
//		{
//			len++;
//			change(1, len, (t + last) % p);
//		}
//		else
//		{
//			last = query(1, len + 1 - t, len);
//			cout << last << '\n';
//		}
//	}
//	return 0;
//}





#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
struct node
{
	int l, r;
	ll sum, tag;
}seg[N<<2];
int n, q, a[N] = { 0 };

void up(int id)
{
	seg[id].sum = seg[id << 1].sum + seg[id << 1 | 1].sum;
}

void settag(int id, ll val)
{
	int l = seg[id].l;
	int r = seg[id].r;
	seg[id].sum += (r - l + 1) * val;
	seg[id].tag += val;
}

void down(int id)
{
	if (seg[id].tag == 0) return;
	ll tag = seg[id].tag;
	seg[id].tag = 0;
	settag(id << 1, tag);
	settag(id << 1 | 1, tag);
}

void build(int id, int ql, int qr)
{
	seg[id].l = ql;
	seg[id].r = qr;
	if (qr == ql)
	{
		seg[id].sum = a[ql];
		return;
	}
	int mid = (qr + ql) >> 1;
	build(id << 1, ql, mid);
	build(id << 1 | 1, mid + 1, qr);
	up(id);
}

void modify(int id, int ql, int qr, ll val)
{
	int l = seg[id].l;
	int r = seg[id].r;
	if (l > qr || r < ql) return;
	if (l >= ql && r <= qr)
	{
		settag(id, val);
		return;
	}
	down(id);
	modify(id << 1, ql, qr, val);
	modify(id << 1 | 1, ql, qr, val);
	up(id);
}

ll query(int id, int ql, int qr)
{
	int l = seg[id].l;
	int r = seg[id].r;
	if (l >= ql && r <= qr) return seg[id].sum;
	int mid = (l + r) >> 1;
	down(id);
	if (qr <= mid) return query(id << 1, ql, qr);
	else if (ql > mid) return query(id << 1 | 1, ql, qr);
	else return query(id << 1, ql, qr) + query(id << 1 | 1, ql, qr);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1;i <= n;i++) cin >> a[i];
	build(1, 1, n);
	int f, l, r, x;
	while (q--)
	{
		cin >> f >> l >> r;
		if (f == 1)
		{
			cin >> x;
			modify(1,l,r,x);
		}
		else if(f == 2)
		{
			cout << query(1,l,r) << endl;
		}
	}
	return 0;
}