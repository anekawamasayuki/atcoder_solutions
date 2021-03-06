#include <bits/stdc++.h>
// #include "ane.cpp"

const int INF  = 1e9;
const long long INFLL = 1e18;
const int NMAX = 52;
const int MMAX = 100005;
const int KMAX = 1005;
const int MOD  = 1e9 + 7;
using namespace std;

// comment to disable debug functions
#define DEBUG

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


ll N;
double A[NMAX], a[NMAX];
int from[NMAX] = {},
to[NMAX] = {},
cnt;

ll ans = {};
bool check(){
  for (int i = 1; i < N; ++i)
  {
    if (a[i] < a[i-1])
    {
      return false;
    }
  }
  return true;
}
void next(){
  ++to[0];
  for (int i = 0; i < cnt && to[i] >= N; ++i)
  {
    to[i] = 0;
    ++to[i+1];
  }
  if(to[cnt] == 0) return;

  to[cnt] = 0;
  ++from[0];
  for (int i = 0; i < cnt && from[i] >= N; ++i)
  {
    from[i] = 0;
    ++from[i+1];
  }
}
void solve(){
  // main algorithm
  for (cnt = 0; cnt <= 2 * N; ++cnt)
  {
    // DUMP(cnt);
    while(from[cnt] == 0) {
      memcpy(a, A, sizeof(double) * N);
      for (int k = 0; k < cnt; ++k)
        a[to[k]] += a[from[k]];
      // for(int i = 0; i < N; ++i) printf("%d ", (int)a[i]);
      // printf("\n");
      if(check()) return;
      next();
    }
    from[cnt] = 0;
  }
}
void debug(){
  // output debug information

}
void answer(){
  // output answer
  printf("%d\n", cnt);
  for (int k = 0; k < cnt; ++k)
  {
    printf("%d %d\n", from[k] + 1, to[k] + 1);
  }
}
int main(int argc, char const *argv[])
{
  // operate inputs

  // Fill(dp, -1);
  cin >> N;
  for (int i = 0; i < N; ++i)
  {
    scanf("%lf", &A[i]);
  }
  solve();
  #ifdef DEBUG
  debug();
  #endif
  answer();

  return 0;
}