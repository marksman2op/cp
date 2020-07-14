#include <bits/stdc++.h>
using namespace std;

// Returns area of a triangle 
double areaTriangle(double x1, double y1, double x2, double y2, double x3, double y3) {
    return abs((x1 * y2 - x2 * y1) + (x2 * y3 - x3 * y2) + (x3 * y1 - x1 * y3)) / 2;
}

// Returns area segment of a circle of radius r and distance between the points of intersection m
double areaSegment(double r, double m){
    return abs(asin(m / (2 * r)) * r * r) - (m * sqrt(r * r - (m * m / 4)) / 2);
}

// Return area of intersection of a circle a origin of radius r and the area between the lines x1, x2, y1, y2 
// (or a rectangle) can be optimised for a square
double calculate(double r, double x1, double x2, double y1, double y2){
    if (x1 == x2 || y1 == y2)
        return 0;
    if (x1 * x2 >= 0 && y1 * y2 >= 0) {
        x1 = abs(x1);
        x2 = abs(x2);
        y1 = abs(y1);
        y2 = abs(y2);
        if (x1 > x2)
            swap(x1, x2);
        if (y1 > y2)
            swap(y1, y2);

        if (r * r >= (x2 * x2 + y2 * y2))
            return (x2 - x1) * (y2 - y1);
        else {
            if (r * r <= (x1 * x1 + y1 * y1))
                return 0;
            else {
                if (r * r <= min((x1 * x1 + y2 * y2), (x2 * x2 + y1 * y1))) {
                    double a = sqrt(r * r - x1 * x1), b = sqrt(r * r - y1 * y1);
                    double d = sqrt((x1 - b) * (x1 - b) + (y1 - a) * (y1 - a));
                    return areaTriangle(x1, y1, x1, a, b, y1) + areaSegment(r, d);
                }
                else {
                    if(r * r >= max((x1 * x1 + y2 * y2), (x2 * x2 + y1 * y1))) {
                        double b = sqrt(r * r - x2 * x2), a = sqrt(r * r - y2 * y2);
                        double d = sqrt((x2 - a) * (x2 - a) + (y2 - b) * (y2 - b));
                        return areaTriangle(x1, y1, x1, y2, a, y2) + areaTriangle(x1, y1, x2, y1, x2, b) + areaTriangle(x1, y1, a, y2, x2, b) + areaSegment(r, d);
                    }

                    if(r * r >= x2 * x2 + y1 * y1) {
                        double b = sqrt(r * r - x2 * x2), a = sqrt(r * r - x1 * x1);
                        double d = sqrt((x1 -x2) * (x1 -x2) + (a - b) * (a - b));
                        return areaTriangle(x1, y1, x2, b, x1, y2) + areaTriangle(x1, y1, x2, b, x1, a) + areaSegment(r, d);
                    }

                    if(r*r >= x1*x1 + y2*y2) {
                        double a = sqrt(r * r - y2 * y2), b = sqrt(r * r - y1 * y1);
                        double d = sqrt((y1 - y2) * (y1 - y2) + (a - b) * (a - b));
                        return areaTriangle(x1, y1, x1, y2, a, y2) + areaTriangle(x1, y1, a, y2, b, y1) + areaSegment(r, d);
                    }
                }
            }
        }
    }
    else {
        if (x1 * x2 >= 0 || y1 * y2 >= 0) {
            if(y1 * y2 >= 0) {
                swap(x1, y1);
                swap(x2, y2);
            }
            x1 = abs(x1);
            x2 = abs(x2);
            if(abs(y1) > abs(y2))
                swap(y1, y2);
            if(x1 > x2)
                swap(x1, x2);

            if(x1 >= r)
                return 0;

            if(r * r >= x2 * x2 + y2 * y2)
                return (x2 - x1) * abs(y2 - y1);

            return calculate(r, x1, x2, 0, abs(y1)) + calculate(r, x1, x2, 0, abs(y2));
        }

        return calculate(r, 0, abs(x1), 0, abs(y1)) + calculate(r, 0, abs(x1), 0, abs(y2)) 
                    + calculate(r, 0, abs(x2), 0, abs(y1)) + calculate(r, 0, abs(x1), 0, abs(y2));
    }
    return 0.0;
}

// Can be optimised further if sides of rectangle are aligned to the axis
double solve(double x, double y, double r, double a1, double b1, double c1, double a2, double b2, double c2, double a3, double b3, double c3, double a4, double b4, double c4) {
    double dx1, dx2, dy1, dy2;
    dx1 = (a1 * x + b1 * y - c1) / (sqrt(a1 * a1 + b1 * b1));
    dx2 = (a3 * x + b3 * y - c3) / (sqrt(a3 * a3 + b3 * b3));
    dy1 = (a2 * x + b2 * y - c2) / (sqrt(a2 * a2 + b2 * b2));
    dy2 = (a4 * x + b4 * y - c4) / (sqrt(a4 * a4 + b4 * b4));
    return calculate(r, dx1, dx2, dy1, dy2);
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        /*
            Input format:
            1. Circle: Centre (x, y), Radius R
            2. 4 adjacent sides of rectangle a1x + b1y = c1, ...
        */
        double x, y, r, a1, b1, c1, a2, b2, c2, a3, b3, c3, a4, b4, c4;
        cin >> x >> y >> r >> a1 >> b1 >> c1 >> a2 >> b2 >> c2 >> a3 >> b3 >> c3 >> a4 >> b4 >> c4;

        double ans = solve(x, y, r, a1, b1, c1, a2, b2, c2, a3, b3, c3, a4, b4, c4);
        cout << ans << '\n';
    }
    
    return 0;
}
