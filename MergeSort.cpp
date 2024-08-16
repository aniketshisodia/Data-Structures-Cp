#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr , int low , int mid , int high ) {
    vector<int> temp;
    int i = low;
    int j = mid + 1;
    while(i <= mid && j <= high) {
        if(arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        }
        else {
            temp.push_back(arr[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        temp.push_back(arr[i++]);
    }
    
    while (j <= high)
    {
        temp.push_back(arr[j++]);
    }
    for(int i = low ; i <= high ; i++) {
        arr[i] = temp[i - low];
    }
}
// 1 2 3 4 5 6 7 8
// low , mid , high

void mergeSort(vector<int> &arr , int low , int high) {
    if(low >= high) return;
    int mid = (low + high) / 2;
    mergeSort(arr , low , mid);
    mergeSort(arr , mid + 1 , high);
    merge(arr , low , mid , high);      
}

int main() {
    int n;
    cin>>n;
    vector<int> arr;
    arr = {2,3,5,-1,0,2,4,5,1};
    mergeSort(arr , 0 , arr.size() - 1);
    for(auto it : arr) cout<<it<<" ";
}
