/**
 * ██╗      █████╗ ████████╗ █████╗ ██╗     ██╗ █████╗
 * ██║     ██╔══██╗╚══██╔══╝██╔══██╗██║     ██║██╔══██╗
 * ██║     ███████║   ██║   ███████║██║     ██║███████║
 * ██║     ██╔══██║   ██║   ██╔══██║██║     ██║██╔══██║
 * ███████╗██║  ██║   ██║   ██║  ██║███████╗██║██║  ██║
 * ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝╚═╝  ╚═╝
 *
 * ╔══════════════════════════════════════════════════════════════╗
 * ║      CODEFORCES C++ TEMPLATE  —  PYTHON-STYLE POWER         ║
 * ╚══════════════════════════════════════════════════════════════╝
 *  Python  →  C++ (this template)
 *  list              →  vec<T>
 *  dict              →  map<K,V> / umap<K,V>
 *  Counter(a)        →  counter(a)
 *  range(n)          →  rep(i,n)
 *  for x in a        →  each(x, a)
 *  for k,v in d      →  each2(k, v, d)
 *  sorted/reversed   →  sorted(a) / reversed(a)
 *  x in a            →  contains(a, x)    ← O(n) vec | O(1) uset | O(log n) contains_sorted
 *  a.index(x)        →  index(a, x)       ← O(n) vec | O(log n) index_sorted (sorted array)
 *  sorted (ints)     →  radix_sort(a)     ← O(n) vs sorted() O(n log n)
 *  [f(x) for x in a] →  transform_to(a, f)
 *  bisect            →  bisect_left / bisect_right
 *  pow(a,b,mod)      →  mpow(a,b,mod)
 *  float('inf')      →  INF
 *
 *  ⚠  contains(vec, x) is O(n)  — use uset<T> for O(1) membership
 *  ⚠  Compiles on C++14 and C++17
 */

#include <bits/stdc++.h>
using namespace std;

// ── Types ──────────────────────────────────────────────────────
using ll=long long; using ld=long double; using ull=unsigned long long;
using ii=pair<int,int>; using ll2=pair<ll,ll>;
using vi=vector<int>; using vl=vector<ll>; using vvi=vector<vi>; using vvl=vector<vl>;
template<class T>         using vec   = vector<T>;
template<class T>         using uset  = unordered_set<T>;
template<class K,class V> using umap  = unordered_map<K,V>;
template<class T>         using pq    = priority_queue<T>;
template<class T>         using pqmin = priority_queue<T,vec<T>,greater<T>>;
template<class T>         using stk   = stack<T>;
template<class T>         using que   = queue<T>;
template<class T>         using deq   = deque<T>;

// ── Constants ──────────────────────────────────────────────────
const ll INF=2e18, MOD=1e9+7, MOD2=998244353;
const int INF32=2e9;
const ld PI=acos((ld)-1);
const int dx4[]={0,0,1,-1}, dy4[]={1,-1,0,0};
const int dx8[]={0,0,1,-1,1,1,-1,-1}, dy8[]={1,-1,0,0,1,-1,1,-1};

// ── Fast I/O ───────────────────────────────────────────────────
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);

// ── Loops ──────────────────────────────────────────────────────
#define rep(i,n)         for(ll i=0;i<(ll)(n);i++)
#define repe(i,s,e)      for(ll i=(ll)(s);i<(ll)(e);i++)
#define repd(i,n)        for(ll i=(ll)(n)-1;i>=0;i--)
#define repde(i,s,e)     for(ll i=(ll)(e)-1;i>=(ll)(s);i--)
#define repstep(i,s,e,k) for(ll i=(ll)(s);i<(ll)(e);i+=(k))
#define each(x,a)        for(auto&x:(a))
// each2: C++14-safe key-value iteration over any map  →  for k,v in d.items()
#define each2(k,v,m)     for(auto&_p:(m))for(bool _b=true;_b;_b=false)for(auto&k=_p.first;_b;_b=false)for(auto&v=_p.second;_b;_b=false)

template<class T,class F> void enumerate(const vec<T>&a,F f){for(int i=0;i<(int)a.size();i++)f(i,a[i]);}
template<class A,class B,class F> void zip(const vec<A>&a,const vec<B>&b,F f){int n=min(a.size(),b.size());for(int i=0;i<n;i++)f(a[i],b[i]);}

// ── List / Vector ──────────────────────────────────────────────
template<class T> ll   len(const T&a){return(ll)a.size();}
template<class T> void append(vec<T>&a,T x){a.push_back(x);}
template<class T> void extend(vec<T>&a,const vec<T>&b){a.insert(a.end(),b.begin(),b.end());}
template<class T> void insert(vec<T>&a,int i,T x){a.insert(a.begin()+i,x);}
template<class T> T    pop(vec<T>&a,int i=-1){if(i==-1){T v=a.back();a.pop_back();return v;}T v=a[i];a.erase(a.begin()+i);return v;}
template<class T> bool remove_val(vec<T>&a,T x){auto it=find(a.begin(),a.end(),x);if(it==a.end())return false;a.erase(it);return true;}
template<class T> ll   count(const vec<T>&a,T x){return(ll)std::count(a.begin(),a.end(),x);}
template<class T> int  index(const vec<T>&a,T x){auto it=find(a.begin(),a.end(),x);return it==a.end()?-1:(int)(it-a.begin());}

// contains — O(n) for vec, O(1) for uset/set/map  →  x in a
template<class T,class V> bool contains(const vec<T>&a,V x){return find(a.begin(),a.end(),x)!=a.end();}
template<class T,class V> bool contains(const set<T>&a,V x){return a.count(x);}
template<class T,class V> bool contains(const uset<T>&a,V x){return a.count(x);}
template<class K,class V,class Q> bool contains(const map<K,V>&a,Q x){return a.count(x);}
template<class K,class V,class Q> bool contains(const umap<K,V>&a,Q x){return a.count(x);}

template<class T> T   sum(const vec<T>&a){return accumulate(a.begin(),a.end(),T(0));}
template<class T> T   product(const vec<T>&a){return accumulate(a.begin(),a.end(),T(1),multiplies<T>());}
template<class T> T   vmin(const vec<T>&a){return*min_element(a.begin(),a.end());}
template<class T> T   vmax(const vec<T>&a){return*max_element(a.begin(),a.end());}
template<class T> int argmin(const vec<T>&a){return(int)(min_element(a.begin(),a.end())-a.begin());}
template<class T> int argmax(const vec<T>&a){return(int)(max_element(a.begin(),a.end())-a.begin());}

template<class T>         vec<T> sorted(vec<T>a){sort(a.begin(),a.end());return a;}
template<class T,class C> vec<T> sorted(vec<T>a,C c){sort(a.begin(),a.end(),c);return a;}
template<class T>         vec<T> reversed(vec<T>a){reverse(a.begin(),a.end());return a;}
template<class T>         vec<T> slice(const vec<T>&a,int s,int e=-1){if(e<0)e=(int)a.size()+e+1;return vec<T>(a.begin()+s,a.begin()+e);}
template<class T>         vec<T> flatten(const vec<vec<T>>&vv){size_t tot=0;for(auto&v:vv)tot+=v.size();vec<T>r;r.reserve(tot);for(auto&v:vv)r.insert(r.end(),v.begin(),v.end());return r;}
template<class T,class F> auto   transform_to(const vec<T>&a,F f)->vec<decltype(f(a[0]))>{using R=decltype(f(a[0]));vec<R>r(a.size());transform(a.begin(),a.end(),r.begin(),f);return r;}
template<class T,class F> vec<T> filter_to(const vec<T>&a,F f){vec<T>r;copy_if(a.begin(),a.end(),back_inserter(r),f);return r;}
template<class T>         vec<T> unique_vals(vec<T>a){sort(a.begin(),a.end());a.erase(unique(a.begin(),a.end()),a.end());return a;}

// ── Sorted-array variants (require sorted input) ───────────────
// contains_sorted: O(log n) vs contains(vec) O(n) — use on sorted arrays
template<class T> bool contains_sorted(const vec<T>&a,T x){auto it=lower_bound(a.begin(),a.end(),x);return it!=a.end()&&*it==x;}
// index_sorted: O(log n) vs index() O(n) — returns -1 if not found
template<class T> int  index_sorted(const vec<T>&a,T x){auto it=lower_bound(a.begin(),a.end(),x);return(it!=a.end()&&*it==x)?(int)(it-a.begin()):-1;}

// ── Radix Sort — O(n) for non-negative integers ────────────────
// Use instead of sorted() when values are non-negative ints/ll
// sorted() = O(n log n),  radix_sort() = O(n)  — massive win for large n
void radix_sort(vi&a){
    if(a.empty())return;
    int mx=*max_element(a.begin(),a.end());
    vi buf(a.size());
    for(int exp=1;(ll)mx/exp>0;exp*=16){
        int cnt[16]={};
        for(int x:a)cnt[(x/exp)&15]++;
        for(int i=1;i<16;i++)cnt[i]+=cnt[i-1];
        for(int i=(int)a.size()-1;i>=0;i--)buf[--cnt[(a[i]/exp)&15]]=a[i];
        a=buf;
    }
}
void radix_sort(vl&a){
    if(a.empty())return;
    ll mx=*max_element(a.begin(),a.end());
    vl buf(a.size());
    for(ll exp=1;mx/exp>0;exp*=16){
        int cnt[16]={};
        for(ll x:a)cnt[(x/exp)&15]++;
        for(int i=1;i<16;i++)cnt[i]+=cnt[i-1];
        for(int i=(int)a.size()-1;i>=0;i--)buf[--cnt[(a[i]/exp)&15]]=a[i];
        a=buf;
    }
}

vi zeros(int n){return vi(n,0);} vi ones(int n){return vi(n,1);}
vl lzeros(int n){return vl(n,0LL);}
vi iota_vec(int n){vi a(n);iota(a.begin(),a.end(),0);return a;}
template<class T> void rotate_left (vec<T>&a,int k){k%=(int)a.size();rotate(a.begin(),a.begin()+k,a.end());}
template<class T> void rotate_right(vec<T>&a,int k){k%=(int)a.size();rotate(a.begin(),a.begin()+(int)a.size()-k,a.end());}
template<class T,class F> bool all (const vec<T>&a,F f){return all_of (a.begin(),a.end(),f);}
template<class T,class F> bool any (const vec<T>&a,F f){return any_of (a.begin(),a.end(),f);}
template<class T,class F> bool none(const vec<T>&a,F f){return none_of(a.begin(),a.end(),f);}

// ── Dict / Map ─────────────────────────────────────────────────
template<class K,class V> V get(const map<K,V>&d,const K&k,V def=V()){auto it=d.find(k);return it==d.end()?def:it->second;}
template<class K,class V> V get(const umap<K,V>&d,const K&k,V def=V()){auto it=d.find(k);return it==d.end()?def:it->second;}
template<class K,class V> vec<K> keys(const map<K,V>&d){vec<K>r;for(auto&p:d)r.push_back(p.first);return r;}
template<class K,class V> vec<V> values(const map<K,V>&d){vec<V>r;for(auto&p:d)r.push_back(p.second);return r;}
template<class T> map<T,int>  counter (const vec<T>&a){map<T,int>c;for(auto&x:a)c[x]++;return c;}
template<class T> umap<T,int> ucounter(const vec<T>&a){umap<T,int>c;for(auto&x:a)c[x]++;return c;}
template<class T> pair<T,int> most_common(const vec<T>&a){
    // ucounter = O(n) avg  vs  counter = O(n log n) — same result, faster
    auto c=ucounter(a);
    return *max_element(c.begin(),c.end(),[](const pair<T,int>&x,const pair<T,int>&y){return x.second<y.second;});
}

// ── Set ops ────────────────────────────────────────────────────
template<class T> set<T> union_set(const set<T>&a,const set<T>&b){set<T>r=a;r.insert(b.begin(),b.end());return r;}
template<class T> set<T> intersection(const set<T>&a,const set<T>&b){set<T>r;set_intersection(a.begin(),a.end(),b.begin(),b.end(),inserter(r,r.end()));return r;}
template<class T> set<T> difference(const set<T>&a,const set<T>&b){set<T>r;set_difference(a.begin(),a.end(),b.begin(),b.end(),inserter(r,r.end()));return r;}
template<class T> set<T> to_set(const vec<T>&a){return set<T>(a.begin(),a.end());}
template<class T> vec<T> to_vec(const set<T>&s){return vec<T>(s.begin(),s.end());}

// ── Strings ────────────────────────────────────────────────────
vec<string> split(const string&s,char d=' '){vec<string>r;stringstream ss(s);string t;while(getline(ss,t,d))if(!t.empty())r.push_back(t);return r;}
string join(const vec<string>&a,const string&s=" "){string r;for(int i=0;i<(int)a.size();i++){if(i)r+=s;r+=a[i];}return r;}
template<class T> string join(const vec<T>&a,const string&s=" "){string r;for(int i=0;i<(int)a.size();i++){if(i)r+=s;r+=to_string(a[i]);}return r;}
string strip(string s){while(!s.empty()&&isspace((unsigned char)s.front()))s.erase(s.begin());while(!s.empty()&&isspace((unsigned char)s.back()))s.pop_back();return s;}
string upper(string s){for(char&c:s)c=toupper(c);return s;}
string lower(string s){for(char&c:s)c=tolower(c);return s;}
bool startswith(const string&s,const string&p){return s.rfind(p,0)==0;}
bool endswith(const string&s,const string&p){return s.size()>=p.size()&&s.compare(s.size()-p.size(),p.size(),p)==0;}
string replace_all(string s,const string&f,const string&t){size_t p=0;while((p=s.find(f,p))!=string::npos){s.replace(p,f.size(),t);p+=t.size();}return s;}
int str_find(const string&s,const string&p){size_t p2=s.find(p);return p2==string::npos?-1:(int)p2;}
int str_find(const string&s,char c){size_t p2=s.find(c);return p2==string::npos?-1:(int)p2;}  // s.index(c)
int str_rfind(const string&s,const string&p){size_t p2=s.rfind(p);return p2==string::npos?-1:(int)p2;} // last occurrence

// str_contains(s, sub/char)  →  sub in s  — O(n)
bool str_contains(const string&s,const string&sub){return s.find(sub)!=string::npos;}
bool str_contains(const string&s,char c){return s.find(c)!=string::npos;}

// str_slice(s, i, j)  →  s[i:j]  — supports negative indices like Python
// str_slice(s, 1, 4)  → s[1:4]
// str_slice(s, -3)    → s[-3:]   (last 3 chars)
// str_slice(s, 0, -1) → s[:-1]   (all but last)
string str_slice(const string&s,int i,int j=INT_MAX){
    int n=(int)s.size();
    if(i<0)i=max(0,n+i);
    if(j==INT_MAX)j=n;
    else if(j<0)j=max(0,n+j);
    i=min(i,n);j=min(j,n);
    if(i>=j)return "";
    return s.substr(i,j-i);
}
string repeat(const string&s,int n){string r;while(n--)r+=s;return r;}
string bin_str(ll n){if(!n)return"0b0";string s="0b";int b=63-__builtin_clzll(n);for(int i=b;i>=0;i--)s+=(char)('0'+((n>>i)&1));return s;}
bool is_digit(const string&s){return!s.empty()&&all_of(s.begin(),s.end(),::isdigit);}
bool is_alpha(const string&s){return!s.empty()&&all_of(s.begin(),s.end(),::isalpha);}

// ── Bisect ─────────────────────────────────────────────────────
template<class T> int bisect_left (const vec<T>&a,T x){return(int)(lower_bound(a.begin(),a.end(),x)-a.begin());}
template<class T> int bisect_right(const vec<T>&a,T x){return(int)(upper_bound(a.begin(),a.end(),x)-a.begin());}
template<class T> void insort(vec<T>&a,T x){a.insert(a.begin()+bisect_left(a,x),x);}
template<class F> ll bs_first(ll lo,ll hi,F c){while(lo<hi){ll m=(lo+hi)/2;if(c(m))hi=m;else lo=m+1;}return c(lo)?lo:-1;}
template<class F> ll bs_last (ll lo,ll hi,F c){while(lo<hi){ll m=(lo+hi+1)/2;if(c(m))lo=m;else hi=m-1;}return c(lo)?lo:-1;}

// ── Math ───────────────────────────────────────────────────────
ll pw(ll a,ll b){ll r=1;while(b>0){if(b&1)r*=a;a*=a;b>>=1;}return r;}
ll mpow(ll a,ll b,ll mod=MOD){ll r=1;a%=mod;while(b>0){if(b&1)r=r*a%mod;a=a*a%mod;b>>=1;}return r;}
ll modinv(ll a,ll mod=MOD){return mpow(a,mod-2,mod);}
ll gcd(ll a,ll b){while(b){a%=b;swap(a,b);}return a;}  // iterative — no stack overflow
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
pair<ll,ll> divmod(ll a,ll b){return{a/b,a%b};}
template<class T> int  sign(T x){return(x>0)-(x<0);}
template<class T> T    clamp(T x,T lo,T hi){return max(lo,min(hi,x));}
template<class T> bool chmin(T&a,T b){if(b<a){a=b;return true;}return false;}
template<class T> bool chmax(T&a,T b){if(b>a){a=b;return true;}return false;}
bool is_prime(ll n){if(n<2)return false;if(n==2||n==3)return true;if(n%2==0||n%3==0)return false;for(ll i=5;i*i<=n;i+=6)if(n%i==0||n%(i+2)==0)return false;return true;}
vi sieve(int n){vector<bool>p(n+1,true);p[0]=p[1]=false;for(int i=2;i*i<=n;i++)if(p[i])for(int j=i*i;j<=n;j+=i)p[j]=false;vi r;for(int i=2;i<=n;i++)if(p[i])r.push_back(i);return r;}
map<ll,int> prime_factors(ll n){map<ll,int>f;for(ll i=2;i*i<=n;i++)while(n%i==0){f[i]++;n/=i;}if(n>1)f[n]++;return f;}
vi divisors(int n){vi d;for(int i=1;(ll)i*i<=n;i++)if(n%i==0){d.push_back(i);if(i!=n/i)d.push_back(n/i);}sort(d.begin(),d.end());return d;}
int popcount(ll n){return __builtin_popcountll(n);}
int bit_length(ll n){return n==0?0:64-__builtin_clzll(n);}
bool is_pow2(ll n){return n>0&&!(n&(n-1));}

// ── Combinatorics ──────────────────────────────────────────────
namespace Comb{
    const int MX=2000005; vl fact(MX),inv_fact(MX); bool ok=false;
    void init(ll mod=MOD){ok=true;fact[0]=1;for(int i=1;i<MX;i++)fact[i]=fact[i-1]*i%mod;inv_fact[MX-1]=mpow(fact[MX-1],mod-2,mod);for(int i=MX-2;i>=0;i--)inv_fact[i]=inv_fact[i+1]*(i+1)%mod;}
    ll C(ll n,ll r,ll mod=MOD){if(!ok)init(mod);if(r<0||r>n)return 0;return fact[n]%mod*inv_fact[r]%mod*inv_fact[n-r]%mod;}
    ll P(ll n,ll r,ll mod=MOD){if(!ok)init(mod);if(r<0||r>n)return 0;return fact[n]%mod*inv_fact[n-r]%mod;}
}
void init_comb(){Comb::init();}

// ── Prefix Sum ─────────────────────────────────────────────────
vl prefix_sum(const vl&a){vl ps(a.size()+1,0);for(int i=0;i<(int)a.size();i++)ps[i+1]=ps[i]+a[i];return ps;}
ll range_sum(const vl&ps,int l,int r){return ps[r+1]-ps[l];}
vec<vl> prefix_sum2d(const vec<vl>&a){int n=a.size(),m=a[0].size();vec<vl>ps(n+1,vl(m+1,0));for(int i=0;i<n;i++)for(int j=0;j<m;j++)ps[i+1][j+1]=a[i][j]+ps[i][j+1]+ps[i+1][j]-ps[i][j];return ps;}
ll range_sum2d(const vec<vl>&ps,int r1,int c1,int r2,int c2){return ps[r2+1][c2+1]-ps[r1][c2+1]-ps[r2+1][c1]+ps[r1][c1];}

// ── Coordinate Compression ─────────────────────────────────────
template<class T> struct Compress{
    vec<T>vals;
    Compress(vec<T>a):vals(unique_vals(a)){}
    int encode(T x){return(int)(lower_bound(vals.begin(),vals.end(),x)-vals.begin());}
    T   decode(int i){return vals[i];}
    int size(){return(int)vals.size();}
};

// ── DSU ────────────────────────────────────────────────────────
struct DSU{
    vi par,rnk,sz;
    DSU(int n):par(n),rnk(n,0),sz(n,1){iota(par.begin(),par.end(),0);}
    // iterative find with full path compression — no stack overflow on deep chains
    int  find(int x){int r=x;while(par[r]!=r)r=par[r];while(par[x]!=r){int nx=par[x];par[x]=r;x=nx;}return r;}
    bool unite(int x,int y){x=find(x);y=find(y);if(x==y)return false;if(rnk[x]<rnk[y])swap(x,y);par[y]=x;sz[x]+=sz[y];if(rnk[x]==rnk[y])rnk[x]++;return true;}
    bool same(int x,int y){return find(x)==find(y);}
    int  size(int x){return sz[find(x)];}
    int  components(){int c=0;for(int i=0;i<(int)par.size();i++)if(find(i)==i)c++;return c;}
};

// ── Fenwick Tree ───────────────────────────────────────────────
struct Fenwick{
    int n;vl t;
    Fenwick(int n):n(n),t(n+1,0){}
    void update(int i,ll d){for(i++;i<=n;i+=i&-i)t[i]+=d;}
    ll prefix(int i){ll s=0;for(i++;i>0;i-=i&-i)s+=t[i];return s;}
    ll query(int l,int r){return prefix(r)-(l?prefix(l-1):0);}
};

// ── Segment Tree ───────────────────────────────────────────────
struct SegTree{
    int n;vl t;
    SegTree(int n):n(n),t(4*n,0){}
    SegTree(const vl&a):n(a.size()),t(4*a.size(),0){build(a,1,0,n-1);}
    void build(const vl&a,int nd,int s,int e){if(s==e){t[nd]=a[s];return;}int m=(s+e)/2;build(a,2*nd,s,m);build(a,2*nd+1,m+1,e);t[nd]=t[2*nd]+t[2*nd+1];}
    void upd(int i,ll v,int nd,int s,int e){if(s==e){t[nd]=v;return;}int m=(s+e)/2;if(i<=m)upd(i,v,2*nd,s,m);else upd(i,v,2*nd+1,m+1,e);t[nd]=t[2*nd]+t[2*nd+1];}
    ll qry(int l,int r,int nd,int s,int e){if(r<s||e<l)return 0;if(l<=s&&e<=r)return t[nd];int m=(s+e)/2;return qry(l,r,2*nd,s,m)+qry(l,r,2*nd+1,m+1,e);}
    void update(int i,ll v){upd(i,v,1,0,n-1);}
    ll   query(int l,int r){return qry(l,r,1,0,n-1);}
};

// ── Sparse Table ───────────────────────────────────────────────
struct SparseTable{
    int n;vi lg;vvl tb;
    SparseTable(const vl&a):n(a.size()),lg(a.size()+1){
        lg[1]=0;for(int i=2;i<=n;i++)lg[i]=lg[i/2]+1;
        int k=lg[n]+1;tb.assign(k,vl(n));tb[0]=a;
        for(int j=1;j<k;j++)for(int i=0;i+(1<<j)<=n;i++)tb[j][i]=min(tb[j-1][i],tb[j-1][i+(1<<(j-1))]);
    }
    ll qmin(int l,int r){int k=lg[r-l+1];return min(tb[k][l],tb[k][r-(1<<k)+1]);}
    ll qmax(int l,int r){int k=lg[r-l+1];return max(tb[k][l],tb[k][r-(1<<k)+1]);}
};

// ── Graph ──────────────────────────────────────────────────────
using Graph=vec<vi>; using WGraph=vec<vec<pair<int,ll>>>;
Graph  new_graph (int n){return Graph(n);}
WGraph new_wgraph(int n){return WGraph(n);}
void add_edge(Graph&g,int u,int v,bool d=false){g[u].push_back(v);if(!d)g[v].push_back(u);}
void add_edge(WGraph&g,int u,int v,ll w,bool d=false){g[u].push_back({v,w});if(!d)g[v].push_back({u,w});}

vl bfs(const Graph&g,int src){int n=g.size();vl dist(n,-1);que<int>q;dist[src]=0;q.push(src);while(!q.empty()){int u=q.front();q.pop();for(int v:g[u])if(dist[v]==-1){dist[v]=dist[u]+1;q.push(v);}}return dist;}
vl dijkstra(const WGraph&g,int src){int n=g.size();vl dist(n,INF);pqmin<pair<ll,int>>pq;dist[src]=0;pq.push({0,src});while(!pq.empty()){ll d=pq.top().first;int u=pq.top().second;pq.pop();if(d>dist[u])continue;for(int i=0;i<(int)g[u].size();i++){int v=g[u][i].first;ll w=g[u][i].second;if(dist[u]+w<dist[v]){dist[v]=dist[u]+w;pq.push({dist[v],v});}}}return dist;}
vi dfs_order(const Graph&g,int src){int n=g.size();vi vis(n,0),order;stk<int>st;st.push(src);while(!st.empty()){int u=st.top();st.pop();if(vis[u])continue;vis[u]=1;order.push_back(u);for(int v:g[u])if(!vis[v])st.push(v);}return order;}
vi topo_sort(const Graph&g){int n=g.size();vi indeg(n,0);for(int u=0;u<n;u++)for(int v:g[u])indeg[v]++;que<int>q;for(int i=0;i<n;i++)if(!indeg[i])q.push(i);vi order;while(!q.empty()){int u=q.front();q.pop();order.push_back(u);for(int v:g[u])if(--indeg[v]==0)q.push(v);}return order;}

// ── String Algorithms ──────────────────────────────────────────
vi kmp_search(const string&text,const string&pat){string s=pat+"#"+text;int n=s.size(),m=pat.size();vi fail(n,0);for(int i=1;i<n;i++){int j=fail[i-1];while(j&&s[i]!=s[j])j=fail[j-1];fail[i]=j+(s[i]==s[j]);}vi res;for(int i=m+1;i<n;i++)if(fail[i]==(int)m)res.push_back(i-2*m);return res;}
vi z_function(const string&s){int n=s.size();vi z(n,0);z[0]=n;for(int i=1,l=0,r=0;i<n;i++){if(i<r)z[i]=min(r-i,z[i-l]);while(i+z[i]<n&&s[z[i]]==s[i+z[i]])z[i]++;if(i+z[i]>r){l=i;r=i+z[i];}}return z;}

// ── Debug ──────────────────────────────────────────────────────
#ifdef LOCAL
    template<class T> void _dbg(const char*n,T v){cerr<<n<<" = "<<v<<"\n";}
    template<class T> void _dbgv(const char*n,const vec<T>&v){cerr<<n<<" = [";for(int i=0;i<(int)v.size();i++){if(i)cerr<<", ";cerr<<v[i];}cerr<<"]\n";}
    #define dbg(x)      _dbg(#x,x)
    #define dbgv(a)     _dbgv(#a,a)
    #define dbg2(x,y)   cerr<<#x"="<<(x)<<", "#y"="<<(y)<<"\n"
    struct Timer{chrono::time_point<chrono::high_resolution_clock>s;Timer(){s=chrono::high_resolution_clock::now();}double elapsed(){return chrono::duration<double>(chrono::high_resolution_clock::now()-s).count();}};
    #define TIMER Timer __t;
    #define TIME  cerr<<"Time: "<<__t.elapsed()<<"s\n";
#else
    #define dbg(x)
    #define dbgv(a)
    #define dbg2(x,y)
    #define TIMER
    #define TIME
#endif

// ── Macros ─────────────────────────────────────────────────────
#define all(x)   (x).begin(),(x).end()
#define rall(x)  (x).rbegin(),(x).rend()
#define sz(x)    (int)(x).size()
#define fi       first
#define se       second
#define pb       push_back
#define mp       make_pair
#define yes      cout<<"YES\n"
#define no       cout<<"NO\n"
#define endl     "\n"

// ══════════════════════════════════════════════════════════════
void solve(){

}

int main(){
    FASTIO
    TIMER
    int t = 1;
    cin >> t;
    while(t--) solve();
    TIME
    return 0;
}
