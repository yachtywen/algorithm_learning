//#include"iostream"
//#include"vector"
//using namespace std;
////二分法适用于寻找哪侧“必有”某某，不一定必须是有序数组。
//int main() {
//	vector<int> arr;
//	int left = 0, right = arr.size(), middle = 0;
//	int num;
//	//寻找num
//	while (left<=right) {
//		middle = (left + right) / 2;
//		if (arr[middle] < num) left = middle + 1;
//		else if (arr[middle] > num) right = middle - 1;
//		else {
//			return true;
//		}
//	}
//	return false;
//	//寻找>=num最左
//	int ans = -1;
//	while (left <= right) {
//		middle = (left + right) / 2;
//		if (arr[middle] < num) left = middle + 1;
//		else if (arr[middle] >= num) {
//			right = middle - 1;
//			ans = arr[middle];
//		}
//	}
//	return ans;
//	//寻找<=num最右
//	int ans = -1;
//	while (left <= right) {
//		middle = (left + right) / 2;
//		if (arr[middle] < num) {
//			left = middle + 1;
//			ans = middle;
//		}
//		else if(arr[middle] >= num) right = middle - 1;
//		
//	}
//	return ans;
//}