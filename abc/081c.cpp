#include <bits/stdc++.h>
// #include "ane.cpp"

const int INF  = 1e9;
const long long INFLL = 1e18;
const int NMAX = 200005;
const int MMAX = 100005;
const int KMAX = 1005;
const int MOD  = 1e9 + 7;
using namespace std;

// comment to disable debug functions
// #define DEBUG

// frequently used macros

#if __cplusplus >= 201103L
#define ALL(v) begin(v),end(v)
#define SORT(v) sort(begin(v), end(v))
#define FIND(v,x) find(begin(v), end(v), (x))
#else
#define ALL(v) (v).begin(),(v).end()
#define SORT(v) sort(v.begin(), v.end())
#define FIND(v,x) find(v.begin(), v.end(), (x))
#endif

#define MEMNEXT(from, to) do{ memmove((to), (from), sizeof(from)); \
memset((from), 0, sizeof(from)); } while(0)
#ifdef DEBUG
#define DUMP(x) do{ std::cerr << (#x) << ": " << x << std::endl; }while(0)
#else
#define DUMP(x) do{}while(0)
#endif

// frequent used aliases
typedef long long ll;
typedef pair<int, int> p;
typedef pair<ll, int> lp;
typedef pair<ll, ll> llp;
typedef vector<int> vec;
typedef vector<ll> vecll;
typedef vector<vec> mat;
typedef vector<vecll> matll;

// frequently used constants
static const int di[] = {-1, 0, 1, -1, 1, -1, 0, 1};
static const int dj[] = {-1, -1, -1, 0, 0, 1, 1, 1};

// frequently used structs
struct edge{
  int to,cost;
};

// printf for debug
#ifndef DEBUG
void debug(const char* format, ...){}
#else
void debug(const char* format, ...){
  va_list arg;
  va_start(arg, format);
  vprintf(format, arg);
  va_end(arg);
}
#endif

// dump vector
#ifdef DEBUG
#define DUMPV(v, c) do{       \
  printf("%s: ", #v);         \
  for (int i = 0; i < (c); ++i) \
  {                           \
  cout << (v)[i] << " ";      \
  }                           \
  cout << endl;               \
} while(0)
#else
#define DUMPV(v,c)
#endif

// std::fill of multi dimensions
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
  std::fill( (T*)array, (T*)(array+N), val );
}

// binary search
ll BSearch(ll _begin, ll _end, bool (*f)(ll)){
  ll mid;
  while(_end - _begin > 1LL) {
  mid = _begin + (_end - _begin) / 2LL;
  if(f(mid)) {
    debug("BSearch: f(%d) == true\n", mid);
    _end = mid;
  }
  else
  {
    debug("BSearch: f(%d) == false\n", mid);
    _begin = mid;
  }
  }
  return _end;
}


ll N,M,K,A[NMAX],B,C,D,E;
int to_delete;
map<ll, int> mp;

using value_type = pair<ll, int>;
struct second_order {
  bool operator()(const value_type& x, const value_type& y) const {
    return x.second > y.second;
  }
};
priority_queue<value_type, vector<value_type>, second_order> que;
vector<value_type> v;
vec vv;
ll ans = {};

bool check(ll x){
  int deleted = 0;
  for(auto&& p: v){
    DUMP(p.first);
    DUMP(p.second);
    deleted++;
    x -= p.second;
    if(x < 0) return false;
    if(deleted >= to_delete) return true;
  }
}
void solve(){
  // main algorithm
  if(N == K){
    ans = 0;
    return;
  }

  for (int i = 0; i < N; ++i)
  {
    mp[A[i]]++;
  }
  to_delete =  mp.size() - K;
  if(to_delete <= 0){
    ans = 0;
    return;
  }
  for(auto&& p : mp) {
    que.push(p);
  }
  while(!que.empty()){
    v.push_back(que.top());
    vv.push_back(que.top().second);
    que.pop();
  }
  ans = accumulate(vv.begin(), vv.begin() + to_delete, 0LL);
}
void debug(){
  // output debug information
  cout << "v DUMP:\n";
  for(auto&& p : v) {
    cout << p.first << ": " << p.second << endl;
  }
}
void answer(){
  // output answer
  cout << ans << endl;
}
int main(int argc, char const *argv[])
{
  // operate inputs

  // Fill(dp, -1);
  cin >> N >> K;
  for (int i = 0; i < N ; ++i)
  {
    scanf("%lld", &A[i]);
  }
  solve();
  #ifdef DEBUG
  debug();
  #endif
  answer();

  return 0;
}