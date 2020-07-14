#include <bits/stdc++.h>
using namespace std;
 
const double EPS = 1e-9;
const double PI  = acos(-1.0);

class Point {
	public:
	    double x, y;
	    Point() {
	    }
	    Point(double x, double y): x(x), y(y) {
	    }
	 
	    Point operator -() const {
	    	return Point(-x, -y);
	    }
	    Point operator +(const Point &p) const {
	    	return Point(x + p.x, y + p.y);
	    }
	    Point operator -(const Point &p) const {
	    	return Point(x - p.x, y - p.y);
	    }
	    Point operator *(const double &n) const {
	    	return Point(x * n, y * n);
	    }
	    Point operator /(const double &n) const {
	    	return Point(x / n, y / n);
	    }
	    double operator *(const Point &p) const {
	    	return x * p.x + y * p.y;
	    }
	    double operator ^(const Point &p) const {
	    	return x * p.y - y * p.x;
	    }
	 
	    // rotate vector (Right/Left hand)
	    Point  Right(double c, double s) {
	    	return Point(x * c - y * s, y * c + x * s);
	    }
	    Point  Left(double c, double s) {
	    	return Point(x * c + y * s, y * c - x * s);
	    }
	    Point  Right(double a) {
	    	return Right(cos(a), sin(a));
	    }
	    Point  Left(double a) {
	    	return Left(cos(a), sin(a));
	    }
	 
	    double abs2() {
	    	return x * x + y * y;
	    }
	    double abs()  {
	    	return sqrt(abs2());
	    }
	    double ang()  {
	    	return atan2(y, x);
	    }
	    Point ext(double s = 1.0) {
	    	return *this / abs() * s;
	    }
};
int sign(double x) {return x < -EPS ? -1 : x > EPS ? 1 : 0;}

class Line {
	public:
	    Point a, b;
	    Line() {
	    }
	    Line(Point a, Point b): a(a), b(b) {
	    }
};
 
class Circle {
	public:
	    Point o;
	    double r;
	    Circle() {
	    }
	    Circle(Point o, double r): o(o), r(r) {
	    }
	 
	    // (d < R - r)         ----> -2
	    // (d = R - r)         ----> -1
	    // (d = 0)
	    // (R - r < d < R + r) ---->  0
	    // (d = R + r)         ---->  1
	    // (d > R + r)         ---->  2
	    int position(Circle c) {
	        double d = (o - c.o).abs();
	        int in = sign(d - fabs(r - c.r)), ex = sign(d - (r + c.r));
	        return in < 0 ? -2 : in == 0? -1 : ex == 0 ? 1 : ex > 0 ? 2 : 0;
	    }
	    
	    Line chord(Circle c) {
	        Point p = c.o - o;
	        double co = (r * r + p.abs2() - c.r * c.r) / (2 * r * p.abs());
	        double si = sqrt(fabs(1.0 - co * co));
	        return Line(p.Left(co, si).ext(r) + o, p.Right(co, si).ext(r) + o);
	    }
};
 
// -PI <= th <= PI
struct Range {
    double t;
    int evt;
    Point p;
    Range() {
    }
    Range(double t, int evt, Point p) : t(t), evt(evt), p(p) {
    }

    bool operator <(const Range &s) const {
        return sign(t - s.t) < 0 || (sign(t - s.t) == 0 && evt > s.evt);
    }
};
 
 
const int N = 1005;
Circle C[N];
Range R[N << 1];
 
bool comp(const Circle &a, const Circle &b) {
    return a.r > b.r;
}
 
double SegmentArea(double r, double t) {
    return r * r * (t - sin(t)) / 2;
}
 
double UnionCircle(Circle C[], int &n) {
    sort(C, C + n, comp);
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (sign(C[i].r) == 0) 
        	break;
        int j = 0;
        for (j = 0; j < k; j++) {
            if (C[i].position(C[j]) < 0 || !sign((C[i].o - C[j].o).abs()))
                break;
        }
        if (j == k)
            C[k++] = C[i];
    }
    n = k;
 
    double ans = 0;
    for (int i = 0; i < n; ++i) {
        Point p = Point(- C[i].r, 0.0) + C[i].o;
        int nc = 0, rcnt = 0;
        R[rcnt++] = Range(-PI,  1, p);
        R[rcnt++] = Range( PI, -1, p);
        for (int j = 0; j < n; ++ j) {
            if (j == i || C[i].position(C[j])) 
            	continue;
 
            Line l = C[i].chord(C[j]);
            double jR = (l.a - C[i].o).ang(), jL = (l.b - C[i].o).ang();
 
            if (sign(jR - jL) > 0) ++ nc;
            R[rcnt++] = Range(jR,  1, l.a);
            R[rcnt++] = Range(jL, -1, l.b);
        }
        sort(R, R + rcnt);
 
        double pj = -PI;
        Point  pp = p;
        for(int j = 0; j < rcnt; ++ j) {
            nc += R[j].evt;
            if((nc == 2 && R[j].evt > 0) || nc == 0)
                ans += SegmentArea(C[i].r, R[j].t - pj) + (pp ^ R[j].p) / 2;
            pj = R[j].t; pp = R[j].p;
        }
    }
    return ans;
}
 
signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) 
            cin >> C[i].o.x >> C[i].o.y >> C[i].r;
             
        double ans = UnionCircle(C, n);
        cout << fixed << setprecision(3) << ans << '\n';
    }
    
    return 0;
} 
