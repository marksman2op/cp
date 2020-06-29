// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long
 
const int N = 2e5 + 5;
 
int n, a[N];

int _mergeSort(int arr[], int temp[], int left, int right); 
int merge(int arr[], int temp[], int left, int mid, int right); 

int mergeSort(int a[], int n) { 
    int temp[n]; 
    return _mergeSort(a, temp, 0, n - 1); 
} 
  
int _mergeSort(int arr[], int temp[], int left, int right) { 
    int cnt = 0; 
    if(right > left) { 
        int mid = (left + right) / 2; 
        cnt += _mergeSort(arr, temp, left, mid); 
        cnt += _mergeSort(arr, temp, mid + 1, right); 
        cnt += merge(arr, temp, left, mid + 1, right); 
    } 

    return cnt; 
} 
  
int merge(int arr[], int temp[], int left, int mid, int right) { 
    int i = left;    // index for left subarray
    int j = mid;    // index for right subarray
    int k = left;    // index for resultant merged subarray
    int cnt = 0;
    while((i <= mid - 1) && (j <= right)) { 
        if (arr[i] <= arr[j]) 
            temp[k++] = arr[i++]; 
        else { 
            temp[k++] = arr[j++]; 
            cnt += (mid - i); 
        } 
    } 
    
    while (i <= mid - 1)    // Copy left subarray 
        temp[k++] = arr[i++]; 
    while (j <= right)    // Copy right subarray
        temp[k++] = arr[j++]; 
  
    for(i = left; i <= right; i++) // Copy merged elements to original array 
        arr[i] = temp[i]; 
  
    return cnt; 
} 
 
signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> a[i];
 
        cout << mergeSort(a, n) << '\n';
    }
    
    return 0;
}
