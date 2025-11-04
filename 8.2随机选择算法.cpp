//#include"iostream"
//#include"cstdlib"
//#include"vector"
//using namespace std;
////题目要求：找出数列中第k大的数
//class Solution {
//public:
//    int findKthLargest(vector<int>& arr, int k) {
//        //第k大==第（sum-k）小的数
//        int chosen = arr.size() - k; 
//        return RandomizedSelect(arr, 0, arr.size() - 1, chosen);
//    }
//
//    void swapArr(vector<int>& arr, int i, int j) {
//        int tmp = arr[i];
//        arr[i] = arr[j];
//        arr[j] = tmp;
//    }
// 
//    int RandomizedSelect(vector<int>& arr, int l, int r, int chosen) {
//        if (l == r) return arr[l];
//        int pivot = arr[l + rand() % (r - l + 1)];
//        int first = l;
//        int last = r;
//        int i = l;
//
//        while (i <= last) {
//            if (arr[i] < pivot) {
//                swapArr(arr, i++, first++);
//            }
//            else if (arr[i] > pivot) {
//                swapArr(arr, i, last--);
//            }
//            else {
//                i++;
//            }
//        }
//
//        if (chosen < first)
//            return RandomizedSelect(arr, l, first - 1, chosen);
//        else if (chosen > last)
//            return RandomizedSelect(arr, last + 1, r, chosen);
//        else
//            return pivot;
//    }
//};
