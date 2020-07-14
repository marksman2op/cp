#include<bits/stdc++.h>
using namespace std; 
 
int n;
vector<double> x, y, r;
 
// Check if two circles intersect
bool intersect(int i, int j) {
    double d = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
    
    if(d >= r[i] && d >= r[j]) {
        if((r[i] + r[j]) >= d)
            return true;
        else
            return false;
    }
 
    if(d < max(r[i], r[j]) && (d + min(r[i], r[j])) >= max(r[i], r[j]))
        return true;
    else
        return false;
}
 
// Solves for intersection of a circle and a line provided they intersect. (x1, y1) and (x2, y2) are required points
void CircleLineIntersection(int idx, double a, double b, double c, vector<double> & v) {
    double X = x[idx], Y = y[idx], R = r[idx], x1, x2, y1, y2;
 
    if(b) {
        double A = 1 + (a / b) * (a / b), B = -2 * X - 2 * (a / b) * (c / b - Y), C = X * X + (c / b - Y) * (c / b - Y) - R * R;
        x1 = (-B - sqrt(B * B - 4 * A * C)) / (2 * A);
        x2 = (-B + sqrt(B * B - 4 * A * C)) / (2 * A);
        y1 = (c * a - x1) / b;
        y2 = (c * a - x2) / b;
        v = {x1, y1, x2, y2};
    }
    else {
        double A = 1, B = -2 * Y, C = Y * Y + (c / a - X) * (c / a - X) - R * R;
        y1 = (-B - sqrt(B * B - 4 * A * C)) / (2 * A);
        y2 = (-B + sqrt(B * B - 4 * A * C)) / (2 * A);
        x1 = c / a;
        v = {x1, y1, x1, y2};
    }
}
 
double findValue(double X) {
    return (asin(X) + X * sqrt(1 - X * X)) / 2;
}
 
double range(int idx, double lt, double rt, int a) {
    double X = x[idx], Y = y[idx], R = r[idx];
    return Y * (rt - lt) + a * R * R * (findValue((rt - X) / R) - findValue((lt - X) / R));
}
 
double calculate(double lt, double rt) {
    double mid = (lt + rt) / 2;
    vector<pair<int, bool>> pos;
    vector<pair<double, int>> vec;
    int cnt = 0;
    for (int i = 0; i < x.size(); i++) {
        vector<double> ans(4, 0.0);
        if(abs(mid - x[i]) <= r[i]) {
            vector<double> v;
            CircleLineIntersection(i, 1, 0, mid, v);
            vec.push_back({v[1], cnt++});
            pos.push_back({i, false});
            vec.push_back({v[3], cnt++});
            pos.push_back({i, true});
        }
    }
    sort(vec.begin(), vec.end());
    
    double res = 0;
    for (int i = 0; i < vec.size(); i++) {
        int pc = 0, nc = 0, l = pos[vec[i].second].first, h;
        while(pc == 0 || (pc != nc)) {
            if(pos[vec[i].second].second == true) 
                pc++;
            else
                nc++;
            i++;            
        }
        i--;
        h = pos[vec[i].second].first;
        res += abs(range(h, lt, rt, 1) - range(l, lt, rt, -1));
    }
    return res;
}
 
double solve() {
    vector<double> xlim;
    for (int i = 0; i < n; i++) {
        xlim.push_back(x[i] - r[i]);
        xlim.push_back(x[i] + r[i]);
        for (int j = i + 1; j < n; j++) {
            if(intersect(i, j)){
                vector<double> v;
                CircleLineIntersection(i, 2 * (x[j] - x[i]), 2 * (y[j] - y[i]), r[i] * r[i] - r[j] * r[j] + 
                       x[j] * x[j] - x[i] * x[i] + y[j] * y[j] - y[i] * y[i], v);
                xlim.push_back(v[0]);
                xlim.push_back(v[2]);
            }
        }
    }
    sort(xlim.begin(), xlim.end());
    auto ip = unique(xlim.begin(), xlim.end());  
    xlim.resize(distance(xlim.begin(), ip));
 
    double ans = 0;
    for (int i = 1; i < xlim.size(); i++) 
        ans += calculate(xlim[i - 1], xlim[i]);
    return ans;
}
 
// Check whether a circle j lies completely inside the other circle i
bool CheckInside(int j, int i, vector<double>& x, vector<double>& y, vector<double>& r) {
    if (j != i && (sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])) + r[j]) <= r[i]) 
        return true;
    else
        return false;
}
 
signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        cin >> n;
        vector<double> xp(n), yp(n), rp(n);
        for (int i = 0; i < n; i++) 
            cin >> xp[i] >> yp[i] >> rp[i];
 
        vector<bool> in(n, true);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(in[i] && CheckInside(j, i, xp, yp, rp))
                    in[j] = false;
            }
        }
 
        for (int i = 0; i < n; i++) {
            if(in[i]) {
                x.push_back(xp[i]);
                y.push_back(yp[i]);
                r.push_back(rp[i]);
            }
        }
        n = x.size();
 
        cout << fixed << setprecision(8) << solve() << '\n';
    }
    
    return 0;
} 
