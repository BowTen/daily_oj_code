#include<bits/stdc++.h>
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
const ll MAXN =  1e5+7;
const ll mod = 1e9+7;
const ll inf = 0x3f3f3f3f;
const int N =1e7+3;
vector<int> phi[MAXN];
int k=16;
int a[MAXN];
int tot=0;
int val[MAXN*100];
int ls[MAXN*100];
int rs[MAXN*100];
int rt[MAXN];
int pre[MAXN];
void insert(int &id,int now,int l,int r,int pos) {
        id=++tot;
    ls[id]=ls[now];
    rs[id]=rs[now];
    val[id]=val[now];
    if(l==r) {
        val[id]+=1;
        return;
    }
    int mid=l+r>>1;
    if(pos<=mid) insert(ls[id],ls[now],l,mid,pos);
    else insert(rs[id],rs[now],mid+1,r,pos);
    val[id]=val[ls[id]]+val[rs[id]];
}
int Query(int id,int now,int l,int r,int pos) {
    if(!id) return 0;
    if(l==r) return val[id]-val[now];
    int mid=l+r>>1;
    if(pos<=mid) return Query(ls[id],ls[now],l,mid,pos);
    else return Query(rs[id],rs[now],mid+1,r,pos);
}
bool bj(array<int,2> p,array<int,2> q) {
    if(p[1]!=q[1]) return p[1]>q[1];
    else return p[0]>q[0];
}
struct Info {
    vector<array<int,2>> vec;
};
Info operator +(const Info &a,const Info &b) {
    Info c;
    c=a;
    for(auto &p:b.vec) {
        int flag=0;
        for(auto &q:c.vec) {
            if(q[0]==p[0]) {
                q[1]+=p[1];
                flag=1;
                break;
            }
        }
        if(!flag) c.vec.push_back(p);
    }
    sort(c.vec.begin(),c.vec.end(),bj);
    while(c.vec.size()>k) {
        for(auto &p:c.vec) {
            p[1]-=(*c.vec.rbegin())[1];
        }
        c.vec.pop_back();
    }
    return c;
}
struct node {
    Info val;
} seg[MAXN<<2];
void up(int id) {
    seg[id].val=seg[id<<1].val+seg[id<<1|1].val;
}
void build(int id,int l,int r) {
    if(l==r) {
        for(auto &v:phi[l])
            seg[id].val.vec.push_back({v,1});
        return;
    }
    int mid=l+r>>1;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    up(id);
}
Info query(int id,int l,int r,int ql,int qr) {
    if(ql==l&&r==qr) {
        return seg[id].val;
    }
    int mid=l+r>>1;
    if(qr<=mid) return query(id<<1,l,mid,ql,qr);
    else if(ql>mid) return query(id<<1|1,mid+1,r,ql,qr);
    else return query(id<<1,l,mid,ql,mid)+query(id<<1|1,mid+1,r,mid+1,qr);
}

void solve() {
    int n,q;
    cin>>n>>q;
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++) {
        int ta=a[i];
        for(int j=2; j*j<=a[i]; j++) {
            if(ta%j!=0) continue;
            int cnt=0;
            while(ta%j==0) {
                cnt++;
                ta/=j;
            }
            if(cnt%2==1) phi[i].push_back(j);
        }
        if(ta!=1) phi[i].push_back(ta);
        pre[i]=pre[i-1]+phi[i].size();
    }
    build(1,1,n);
    for(int i=1; i<=n; i++) {
        if(phi[i].size())
            for(int j=0; j<phi[i].size(); j++)
                if(j==0)
                    insert(rt[i],rt[i-1],1,N,phi[i][j]);
                else
                    insert(rt[i],rt[i],1,N,phi[i][j]);
        else
            rt[i]=rt[i-1];
    }
    int lastans=0;
    for(int i=1; i<=q; i++) {
        int l,r;
        cin>>l>>r;
        l^=lastans;
        r^=lastans;
        if(l>r) swap(l,r);
        auto tmp = query(1,1,n,l,r).vec;
        int sum=pre[r]-pre[l-1];
        int len=r-l+1;
        for(auto &v:tmp) {
            int cnt=Query(rt[r],rt[l-1],1,N,v[0]);
            if(cnt*2>len) {
                sum-=cnt;
                sum+=len-cnt;
            }
        }
        lastans=sum;
        cout<<sum<<"\n";
    }

}
signed main() {
    close;
    solve();
}
/*
10 4
2 4 6 8 10 9 2 4 1 7
1 4
2 5
1 9
2 10

*/