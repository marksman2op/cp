// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

// 3D Geometry
struct point3d {
    double x, y, z;
    point3d() {}
    point3d(double x, double y, double z): x(x), y(y), z(z) {}
    point3d& operator+=(const point3d &t) {
        x += t.x;
        y += t.y;
        z += t.z;
        return *this;
    }
    point3d& operator-=(const point3d &t) {
        x -= t.x;
        y -= t.y;
        z -= t.z;
        return *this;
    }
    point3d& operator*=(double t) {
        x *= t;
        y *= t;
        z *= t;
        return *this;
    }
    point3d& operator/=(double t) {
        x /= t;
        y /= t;
        z /= t;
        return *this;
    }
    point3d operator+(const point3d &t) const {
        return point3d(*this) += t;
    }
    point3d operator-(const point3d &t) const {
        return point3d(*this) -= t;
    }
    point3d operator*(double t) const {
        return point3d(*this) *= t;
    }
    point3d operator/(double t) const {
        return point3d(*this) /= t;
    }
};
point3d operator*(double a, point3d b) {
    return b * a;
}
double dot(point3d a, point3d b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
double abs(point3d a) {
    return dot(a, a);
}
double abs(point3d a) {
    return sqrt(abs2(a));
}
double Projection(point3d a, point3d b) {
    return dot(a, b) / abs(b);
}
double AngleBetween(point3d a, point3d b) {
    return acos(dot(a, b) / abs(a) / abs(b));
}
point3d cross(point3d a, point3d b) {
    return point3d(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}
double TripleProduct(point3d a, point3d b, point3d c) {
    return dot(a, cross(b, c));
}
point3d PlaneIntersect(point3d a1, point3d n1, point3d a2, point3d n2, point3d a3, point3d n3) {
    point3d x(n1.x, n2.x, n3.x);
    point3d y(n1.y, n2.y, n3.y);
    point3d z(n1.z, n2.z, n3.z); 
    point3d d(dot(a1, n1), dot(a2, n2), dot(a3, n3));
    return point3d(TripleProduct(d, y, z), TripleProduct(x, d, z), TripleProduct(x, y, d)) / TripleProduct(n1, n2, n3);
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        
    }
    
    return 0;
}
