// https://leetcode.com/problems/create-maximum-number/
class Solution {
public:
    // Maximum number from given array of size m
    vector<int> select(vector<int> &v, int m) {
        int n = v.size();
        vector<int> res;
        for (int i = 0; i < n; i++) {
            while(!res.empty()) {
                if (res.back() < v[i] && ((int)res.size() - 1) + (n - i) >= m)
                    res.pop_back();
                else
                    break;
            }
            
            if (res.size() < m)
                res.push_back(v[i]);
        }
        
        return res;
    }
    
    bool compare(vector<int> &va, int i, vector<int> &vb, int j) {
        while (i < va.size() && j < vb.size() && va[i] == vb[j]) {
            i++;
            j++;
        }
        
        if (j == vb.size())
            return true;
        return i < va.size() && va[i] > vb[j];
    }

    // Greater element comes first if they are equal, compare next
    vector<int> merge(vector<int> &va, vector<int> &vb, int k) {
        vector<int> res;
        int i = 0, j = 0;
        
        while (res.size() < k) {
            int x = compare(va, i, vb, j) ? va[i++] : vb[j++];
            res.push_back(x);
        }
        
        return res;
    }
    
    vector<int> maxNumber(vector<int>& a, vector<int>& b, int k) {
        vector<int> ans;
        int na = a.size(), nb = b.size();
        for (int i = 0; i <= k; i++) {   
            if (na < i || nb < k - i)
                continue;
            
            auto va = select(a, i);
            auto vb = select(b, k - i);
            auto temp = merge(va, vb, k);
            
            ans = max(ans, temp);
        }
        
        return ans;
    }
};
