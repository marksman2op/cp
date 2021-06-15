// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
// #define int long long
 
/*
    char array n * m
    # sand
    . empty

    array of size m
    a[i] = num of sands in column m
*/

// DEBUGGING TEMPLATES
/*
Alternative for g++ -D LOCAL filenmae.cpp
Codeforces defines an ONLINE_JUDGE macro for C/C++ programs. Therefore it is possible to 
write a template where the debugging output works on a local machine, and turns into nothing 
on Codeforces. A very simple implementation:

#ifndef ONLINE_JUDGE
#  define LOG(x) (cerr << #x << " = " << (x) << endl)
#else
#  define LOG(x) 0
#endif
Then just write LOG(i); in the program.

*/

/*
// https://codeforces.com/blog/entry/68809
void __print(int x) {cout << x;}
void __print(long x) {cout << x;}
void __print(long long x) {cout << x;}
void __print(unsigned x) {cout << x;}
void __print(unsigned long x) {cout << x;}
void __print(unsigned long long x) {cout << x;}
void __print(float x) {cout << x;}
void __print(double x) {cout << x;}
void __print(long double x) {cout << x;}
void __print(char x) {cout << '\'' << x << '\'';}
void __print(const char *x) {cout << '\"' << x << '\"';}
void __print(const string &x) {cout << '\"' << x << '\"';}
void __print(bool x) {cout << (x ? "true" : "false");}


template<typename T, typename V>
void __print(const pair<T, V> &x) {cout << '{'; __print(x.first); cout << ", "; __print(x.second); cout << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cout << '{'; for (auto &i : x) cout << (f++ ? ", " : ""), __print(i); cout << "}";}
void _print() {cout << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
#define debug(x...) cout << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
*/

/*
// neal
// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
 
 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
*/


/*
// https://codeforces.com/blog/entry/91347
#define SFINAE(x, ...)             \
    template <class, class = void> \
    struct x : std::false_type {}; \
    template <class T>             \
    struct x<T, std::void_t<__VA_ARGS__>> : std::true_type {}

SFINAE(DefaultIO, decltype(std::cout << std::declval<T &>()));
SFINAE(IsTuple, typename std::tuple_size<T>::type);
SFINAE(Iterable, decltype(std::begin(std::declval<T>())));

template <class T>
constexpr char Space(const T &) {
    return (Iterable<T>::value or IsTuple<T>::value) ? '\n' : ' ';
}

template <auto &os>
struct Writer {
    template <class T>
    void Impl(T const &t) const {
        if constexpr (DefaultIO<T>::value) os << t;
        else if constexpr (Iterable<T>::value) {
            int i = 0;
            for (auto &&x : t) ((i++) ? (os << Space(x), Impl(x)) : Impl(x));
        } else if constexpr (IsTuple<T>::value)
            std::apply([this](auto const &... args) {
                    int i = 0;
                    (((i++) ? (os << ' ', Impl(args)) : Impl(args)), ...);
                }, t);
        else static_assert(IsTuple<T>::value, "No matching type for print");
    }
    template <class F, class... Ts>
    auto &operator()(F const &f, Ts const &... ts) const {
        return Impl(f), ((os << ' ', Impl(ts)), ...), os << '\n', *this;
    }
};

#ifndef ONLINE_JUDGE
    #define debug(args...)                                    \
        {                                                     \
            std::string _s = #args;                           \
            std::replace(_s.begin(), _s.end(), ',', ' ');     \
            std::stringstream _ss(_s);                        \
            std::istream_iterator<std::string> _it(_ss);      \
            std::cerr << "Line " << __LINE__ << "\n";         \
            err(_it, args);                                   \
        }

void err(std::istream_iterator<std::string> it) {
    std::ignore = it;
}

template <typename T, typename... Args>
void err(std::istream_iterator<std::string> it, T a, Args... args) {
    std::cerr << *it << " = ";
    Writer<std::cerr>{}(a);
    err(++it, args...);
}

    #define ASSERT(...) \
        if (not(__VA_ARGS__)) throw runtime_error(#__VA_ARGS__)
#else
    #define debug(...) 0
    #define ASSERT(...) 0
#endif
*/


/*
// Errichto
// https://codeforces.com/blog/entry/67830
// https://github.com/Errichto/youtube/blob/master/reply_code_warsaw_kodziaki.cpp
// Usage
// debug() << imie(c * 2) imie(min(a, b)) imie(a != b);
// debug() << "add" imie(i) imie(A) imie(diff);
// debug() << imie(V); // V is a vector
// debug() << imie(a) imie(h1) imie(h2) imie(my_dist) imie(path) imie(vertices); // int a,h1,h2; vector path;
// debug() << "Zlaczacz::Ogarnij(" imie(a) imie(b) ") = " << res; // pair<vector<int>, vector<int>> res; int a,b;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
*/


/*
// tourist
// https://codeforces.com/blog/entry/65311
// https://codeforces.com/blog/entry/76087
string to_string(string s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
*/


/*
// tnowak 
// https://codeforces.com/blog/entry/67830
// To debug, you'll overload cout
// For eg. to debug vector from(n + 1, vector<tuple<int, int, int>>(10, {-1, -1, -1}));
// ostream& operator<<(ostream &o, tuple<int, int, int> &t) {
//     return o << vector{get<0>(t), get<1>(t), get<2>(t)};
// }
template<class A, class B> auto& operator<<(ostream &o, pair<A, B> p) {
    return o << '(' << p.first << ", " << p.second << ')';
}
template<class T> auto operator<<(ostream &o, T x) -> decltype(x.end(), o) {
    o << '{'; int i = 0; for(auto e : x) o << (", ")+2*!i++ << e; return o << '}';
}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" #x "]: ", [](auto... $) {((cerr << $ << "; "), ...); }(x), cerr << '\n'
#else
#define debug(...) {}
#endif
*/

void run_case() {
    
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int T = 1;
    // cin >> T;
    for (int t = 1; t <= T; t++) {
        // cout << "Case #" << t << ": ";
        run_case();
    }
    
    return 0;
}
