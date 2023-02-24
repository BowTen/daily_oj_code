#define _CRT_SECURE_NO_WARNINGS
#define _SILENCE_CXX20_CISO646_REMOVED_WARNING
#define BowTen ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 5;
struct node {
	ll l, r, min, tag;
}seg[N << 2];
ll n, q, rd[N], ans = 0;

struct ques {
	ll l, r;
}que[N];

void settag(ll id, ll val) {
	seg[id].min += val;
	seg[id].tag += val;
}

void down(ll id) {
	if (seg[id].tag == 0) return;
	settag(id << 1, seg[id].tag);
	settag(id << 1 | 1, seg[id].tag);
	seg[id].tag = 0;
}

void modify(ll id, ll ql, ll qr, ll val) {
	ll l = seg[id].l, r = seg[id].r;
	if (r < ql || l > qr) return;
	if (l >= ql && r <= qr) {
		settag(id, val);
		return;
	}
	down(id);
	ll mid = (l + r) >> 1;
	if (qr <= mid) {
		modify(id << 1, ql, qr, val);
	}
	else if (ql > mid) {
		modify(id << 1 | 1, ql, qr, val);
	}
	else {
		modify(id << 1, ql, qr, val);
		modify(id << 1 | 1, ql, qr, val);
	}
	seg[id].min = min(seg[id << 1].min, seg[id << 1 | 1].min);
}

void built(ll id, ll l, ll r) {
	seg[id].l = l;
	seg[id].r = r;
	if (l == r) {
		seg[id].min = rd[l];
		return;
	}
	ll mid = (l + r) >> 1;
	built(id << 1, l, mid);
	built(id << 1 | 1, mid + 1, r);
	seg[id].min = min(seg[id << 1].min, seg[id << 1 | 1].min);
}

ll getmin(ll id, ll ql, ll qr) {
	ll l = seg[id].l, r = seg[id].r;
	if (l >= ql && r <= qr)
		return seg[id].min;
	down(id);
	ll mid = (l + r) >> 1;
	if (qr <= mid)
		return getmin(id << 1, ql, qr);
	else if (ql > mid)
		return getmin(id << 1 | 1, ql, qr);
	else
		return min(getmin(id << 1, ql, qr), getmin(id << 1 | 1, ql, qr));
}

ll cmp(ques e1, ques e2) {
	/*if ((e1.r - e1.l) < (e2.r - e2.l))
		return 1;
	else if ((e1.r - e1.l) > (e2.r - e2.l))
		return 0;
	return e1.l < e2.l;*/

	if (e1.r == e2.r)
		return e1.l < e2.l;
	return e1.r < e2.r;
}

int main()
{
	BowTen;

	cin >> n >> q;
	for (ll i = 1;i < n;i++)
		cin >> rd[i];

	built(1, 1, n);

	for (ll i = 0;i < q;i++) {
		cin >> que[i].l >> que[i].r;
		if (que[i].l > que[i].r)
			swap(que[i].l, que[i].r);
		que[i].l += 1;
	}
	sort(que, que + q, cmp);

	for (ll i = 0, m;i < q;i++) {
		m = getmin(1, que[i].l, que[i].r);
		if (m == 0)
			continue;
		ans += m;
		modify(1, que[i].l, que[i].r, -m);
	}

	cout << ans;

	return 0;
}