#include <bits/stdc++.h>
// #include "ane.cpp"

const int INF  = 1e9;
const long long INFLL = 1e18;
const int NMAX = 100005;
const int MMAX = 100005;
const int QMAX = 100005;
const int MOD  = 1e9 + 7;
using namespace std;

// comment to disable debug functions
#de fine DEBUG

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
typedef pair<ll, int> pl;
typedef pair<ll, ll> pll;
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
ll BSearch(ll _begin, ll _end, bool (*f)(int)){
  ll mid;
  while(_end - _begin > 1LL) {
  mid = (_begin + _end) / 2LL;
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


ll N,A[QMAX],B[QMAX],X[NMAX],L,Q;
int dp[35][NMAX] = {};

string S;
vec v;

ll ans = 0;

int f(int a, int b, int k){
  int d = dp[k][a];
  if (d > a)
  {
    return f(a, b, k-1);
  }

}

void solve(){
  // main algorithm
  // fill dp
  int logN = (int)log2(N) + 1;
  for (int i = 0; i < N - 1; ++i)
  {
    dp[0][i] = distance(X, upper_bound(X + i, X + N, X[i] + L)) - 1;
  }
  for (int k = 1; k < logN; ++k)
  {
    for (int i = 0; i < N; ++i)
    {
      dp[k][i] = dp[k-1][dp[k][i]];
    }
  }
  // query
  for (int i = 0; i < Q; ++i)
  {
    printf("%d\n", f(min(A[i], B[i]), max(A[i], B[i]), logN));
  }
}
void debug(){
  // output debug information

}
void answer(){
  // output answer
  // printf("%lld\n", ans);
}
int main(int argc, char const *argv[])
{
  // operate inputs

  // Fill(dp, -1);
  scanf("%lld", &N);
  for (int i = 0; i < N; ++i)
  {
    scanf("%lld", &X[i]);
  }
  cin >> L >> Q;
  for (int i = 0; i < Q; ++i)
  {
    scanf("%lld%lld", &A[i], &B[i]);
  }
  solve();
  #ifdef DEBUG
  debug();
  #endif
  answer();

  return 0;
}