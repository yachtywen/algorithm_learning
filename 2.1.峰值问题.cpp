//#include"iostream"
//#include"vector"
//using namespace std;
//int main(){
//	vector<int> arr;
//	int left = 1, right = arr.size() - 2, middle = 0;
//	if (arr.size() == 1) {
//		cout << arr[0];
//	}
//	else {
//		if (arr[0] > arr[left]) cout << arr[0];
//		else if (arr[arr.size()-1] > arr[right]) cout << arr[arr.size()-1];
//		else {
//			while (left<=right) {
//				middle = (left + right) / 2;
//				if (arr[middle] < arr[middle + 1]) left = middle + 1;
//				else if (arr[middle] < arr[middle - 1]) right = middle - 1;
//				else {
//					cout << arr[middle];
//					break;
//				}
//			}
//		}
//	}
//}