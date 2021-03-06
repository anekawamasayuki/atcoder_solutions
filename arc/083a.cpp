#include <bits/stdc++.h>
// #include "ane.cpp"

const int INF  = 1e9;
const long long INFLL = 1e18;
const int NMAX = 100005;
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


ll N,M,K,A,B,C,D,E,F;
llp dp[35][3005];
string S;
vec v;

llp ans;

//return llp{wdater / 100, sugar}
llp solve(ll nowW, ll nowS){
  // main algorithm
  if(nowW * 100 + nowS > F || nowW * E < nowS) return llp{-1,0};
  if(dp[nowW][nowS] != llp{0,0}) {
    // debug("hit\n");
    return dp[nowW][nowS];
  }
  debug("%d %d\n", nowW, nowS);
  double cand = (nowW == 0 && nowS == 0 ? 0 : nowS / (double)(nowW * 100 + nowS));
  llp ret = llp{nowW,nowS};
  // A
  llp pA = solve(nowW + A, nowS);
  if (pA.second / (double)(100 * pA.first + pA.second) > cand)
  {
    cand = pA.second / (double)(100 * pA.first + pA.second);
    ret = pA;
  }
  // B
  llp pB = solve(nowW + B, nowS);
  if (pB.second / (double)(100 * pB.first + pB.second) > cand)
  {
    cand = pB.second / (double)(100 * pB.first + pB.second);
    ret = pB;
  }
  // C
  llp pC = solve(nowW, nowS + C);
  if (pC.second / (double)(100 * pC.first + pC.second) > cand)
  {
    cand = pC.second / (double)(100 * pC.first + pC.second);
    ret = pC;
  }
  // D
  llp pD = solve(nowW, nowS + D);
  if (pD.second / (double)(100 * pD.first + pD.second) > cand)
  {
    cand = pD.second / (double)(100 * pD.first + pD.second);
    ret = pD;
  }
  // debug("cand water: %d, sugar: %d\n", ret.first, ret.second);
  // cout << cand << " " << ret.first << ", " << ret.second << endl;
  return dp[nowW][nowS] = ret;
}
void debug(){
  // output debug information
}
void answer(){
  // output answer
  cout << ans.first * 100 + ans.second << " " << ans.second << endl;
}
int main(int argc, char const *argv[])
{
  // operate inputs

  cin >> A >> B >> C >> D >> E >> F;
  Fill(dp, llp{0, 0});
  ans = solve(0,0);
  #ifdef DEBUG
  debug();
  #endif
  answer();

  return 0;
}