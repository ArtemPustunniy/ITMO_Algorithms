#include<iostream>
#include<algorithm>

using namespace std;

const long long N=10000000 + 5;

long long n, L, W, hd[N], xnt, to[N << 1], nxt[N << 1], w[N << 1];
long long mn, rt, f[N], l, r, siz[N], lm;
long long ans;
bool vis[N];
struct Sta{
    long long w,len;
    Sta(long long w=0,long long l=0):
    w(w),len(l) {}
    bool operator< (const Sta &b)const{return w == b.w? len < b.len:w < b.w;}
}sta[N];

void add(long long x,long long y,long long z)
{
    to[++xnt] = y; nxt[xnt] = hd[x]; w[xnt] = z;hd[x] = xnt;
    to[++xnt] = x; nxt[xnt] = hd[y];w[xnt] = z;hd[y] = xnt;
}

void getrt(long long cr,long long fa,long long s)
{
    siz[cr] = 1; long long mx = 0;
    for(long long i = hd[cr], v; i; i = nxt[i]){
        if(!vis[v = to[i]]&&v != fa){
            getrt(v,cr,s); siz[cr] += siz[v];
            mx = max(mx, siz[v]);
        }
    }
    mx = max(mx,s - siz[cr]);
    if(mx < mn){
        mn = mx;
        rt = cr;
    }
}

void add(long long x,long long k){
    x++;
    for(;x <= lm; x += (x&-x))
        f[x] += k;}
long long query(long long x){
    x++;
    long long ret=0;
    for(;x;x-=(x&-x))
        ret+=f[x];
    return ret;
}
void dfs(long long cr,long long fa,long long pw,long long pl)
{
    if(pw > W || pl > L)return;
    sta[++r] = Sta(pw,pl);
    add(sta[r].len,1);
    for(long long i = hd[cr], v; i; i = nxt[i])
        if(!vis[v = to[i]]&&v != fa)
            dfs(v,cr,pw + w[i],pl + 1);
}

long long calc(long long cr,long long pw,long long pl){
    l = 1;
    r = 0;
    dfs(cr,0, pw, pl);
    sort(sta + l,sta + r + 1);
    long long ret = 0;
    while(l < r){
        if(sta[l].w + sta[r].w > W)
            add(sta[r--].len,-1);
        else ret += query(L - sta[l].len) - (sta[l].len <= L - sta[l].len),
                    add(sta[l++].len,-1);
    }
    if(l == r){
        add(sta[l].len,-1);
    }
    return ret;
}

void solve(long long cr,long long s)
{
    vis[cr] = 1;
    ans += calc(cr,0,0);
    for(long long i = hd[cr], v; i; i = nxt[i])
        if(!vis[v = to[i]]){
            ans -= calc(v,w[i],1);
            long long ts = (siz[cr] > siz[v] ? siz[v]:s - siz[cr]);
            mn = N;
            getrt(v,0,ts); solve(rt,ts);
        }
}
int main()
{
    cin >> n >> L >> W;
    lm = L + 1;
    for(long long i = 2,y ,z;i <= n; i++)
    {
        cin >> y >> z;
        add(i,y,z);
    }
    mn = N; getrt(1,0,n);
    solve(rt,n);
    cout << ans;
    return 0;
}
