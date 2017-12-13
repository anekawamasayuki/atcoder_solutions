#include <bits/stdc++.h>
// #include "ane.cpp"

const int INF  = 1e9;
const long long INFLL = 1e18;
const int NMAX = 505;
const int MMAX = 505;
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


ll N,M,K,A,B,C,D,E;
int dp[NMAX] = {};

int S[NMAX] = {};
vec v;
bool flag = true;
int ans[NMAX][MMAX] = {};

void calcS(int rows, int div){
  for (int i = 0; ;++i)
  {
    if(i * div > rows) break;
    S[i * div] = -i;
  }
  for (int i = 0; ; ++i)
  {
    if(rows - i * div < 0) break;
    S[rows - i * div] = i + 1;
  }
  for (int i = 0; i < rows + 1; ++i)
  {
    if(i && S[i] == 0) S[i] = S[i-1];
  }
}
void solve(){
  // main algorithm
  if(! (N % A) && ! (M % B)){
    flag = false;
    return;
  }

  bool trans = ! (M % B);
  if(trans) {
    calcS(N, A);
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < M; ++j)
        ans[i+1][j+1] = S[i+1] - S[i];
  }
  else {
    calcS(M, B);
    for(int i = 0; i < N; ++i)
      for(int j = 0; j < M; ++j)
        ans[i+1][j+1] = S[j+1] - S[j];
  }
}
void debug(){
  // output debug information

}
void answer(){
  // output answer
  if(flag) {
    cout << "Yes\n";
    for (int i = 0; i < N; ++i)
    {
      for (int j = 0; j < M; ++j)
      {
        printf("%d ", ans[i+1][j+1]);
      }
      printf("\n");
    }
  }
  else {
    cout << "No\n";
  }
}
int main(int argc, char const *argv[])
{
  // operate inputs

  // Fill(dp, -1);
  cin >> N >> M >> A >> B;
  solve();
  #ifdef DEBUG
  debug();
  #endif
  answer();

  return 0;
}