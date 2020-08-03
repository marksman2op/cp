//FENWICK TREE aka BIT

// Applicable for associative and inversible functions
// Operations: 1. Add value val at index idx, 2. Find sum from [0, r]

// Sky's the limit :)
#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e6 + 5;

int n, a[N];
int bit[N];
int bit1[N], bit2[N];   
int bit2d[1030][1030];

// Point Update and Range Query
void update(int x, int val) {    // add "val" at index "x"
	while(x <= n) { 
		bit[x] += val;
		x += (x & (-x));
	}
}

int query(int x) {    // returns the sum of first "x" elements in given array a[]
	int sum = 0;      // Sum from l to r is query(r) - query(l - 1);
	while(x > 0) {
		sum += bit[x];
		x -= (x & (-x));
	}
	return sum;
}

// Range Update and Point Query
void range_update(int l, int r, int val) {
    update(l, val);
    update(r + 1, -val);
}

// Range Update and Range Query
void update(int bit[], int x, int val) {    // add "val" at index "x"
    while(x <= n) { 
        bit[x] += val;
        x += (x & (-x));
    }
}

void update_range(int l, int r, int val) {    // To add val in range [l, r]: update(l, val), update(r + 1, -val) in BIT1
    update(bit1, l, val);					  // and update(l, val * (l - 1)), update(r + 1, -val * r) in BIT2
    update(bit1, r + 1, -val);
    update(bit2, l, val * (l - 1));
    update(bit2, r + 1, -val * r);
}

int query(int bit[], int x) {    // returns the sum of first "x" elements in given array a[]
    int sum = 0;
    while(x > 0) {
        sum += bit[x];
        x -= (x & (-x));
    }
    return sum;
}

int range_query(int x) {	// To get sum in range [0, r]: query_BIT1(x) * x - query_BIT2(x);
    return query(bit1, x) * x - query(bit2, x);
}

// Find minimum index with sum greater than or equal to x using Binary Lifting
int find_lower_bound(int x) {   
	int sum = 0, pos = 0;
	for(int i = log2(n); i >= 0; i--) {
		if(pos + (1 << i) < N && sum + bit[pos + (1 << i)] < x) {
			sum += bit[pos + (1 << i)];
			pos += (1 << i);
		}
	}

	return pos + 1;
}

// Find any index with given prefix sum
int find_any(int x) {
	int idx = 0, i = (int)pow(2, (int)log2(n)); 
	while (i != 0) {
		int curr = idx + i; 
		i >>= 1;
		if (curr > n) 
			continue;
		if (x == bit[curr])
			return curr;
		else if (x > bit[curr]) {
			idx = curr; 
			x -= bit[curr];		
		}
	}
	if (x != 0) 
		return -1;
	else
		return idx;
}

// Find greatest index with given prefix sum
int find_greatest(int x) {
	int idx = 0, i = (int)pow(2, (int)log2(n));
	while (i != 0) {
		int curr = idx + i;
		i >>= 1;
		if (curr > n)
			continue;
		if (x >= bit[curr]) {
			idx = curr;
			x -= bit[curr];
		}
	}
	if (x != 0)
		return -1;
	else
		return idx;
}

// 2D BIT
void update2D(int x, int y, int delta) { 
    for (int i = x; i <= n; i = i | (i + 1))
        for (int j = y; j <= n; j = j | (j + 1))
            bit2d[i][j] += delta;
}

int sum(int x, int y) {    // gives result of the rectangle [(0, 0), (x, y)]
    int ret = 0;
    for (int i = x; i > 0; i = (i & (i + 1)) - 1)
        for (int j = y; j > 0; j = (j & (j + 1)) - 1)
            ret += bit2d[i][j];
    return ret;
}

int query2D(int x1, int y1, int x2, int y2) {    // inclusion-exclusion principle to find result of rectangle [(x1, y1), (x2, y2)]
    int ans = 0;
    ans += sum(x2, y2);
    ans -= sum(x2, y1 - 1);
    ans -= sum(x1 - 1, y2);
    ans += sum(x1 - 1, y1 - 1);
    return ans;
}

signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	//int t = 1; cin >> t; while(t--)
	{

	}
	
	cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
	return 0;
}