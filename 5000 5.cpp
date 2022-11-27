
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

typedef long long ll;
ll tre[1000010];

int main()
{
	ll n, m, lon = 0;
	cin >> n >> m;
	for (ll i = 0;i < n;i++)
		cin >> tre[i];
	sort(tre, tre + n);
	ll f = n-1;
	for (ll i = tre[n-1];i >= 1 ;i--)
	{
		while (tre[f] > i)
			f--;
		lon += (n-1-f);
		if (lon >= m)
		{
			cout << i;
			break;
		}
	}
	return 0;
}