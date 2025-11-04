//#include"iostream"
//#include"algorithm"
//using namespace std;
//int main() {
//	int arr[10];
//	
//	for (int i = 0; i < 10; i++) {
//		cin >> arr[i];
//	}
//	//selection sort
//
//	for (int i = 0; i < 10; i++) {
//	   int minindex = i;
//	   for (int j = i + 1; j < 10; j++) {
//		   if (arr[minindex] > arr[j]) {
//			   minindex = j;
//		   }
//		}
//	   swap(arr[i], arr[minindex]);
//	}
//	//bubble sort
//	for (int i = 0; i < 10; i++) {
//		for (int j = i + 1; j < 10; j++) {
//			if (arr[i] > arr[j]) {
//				swap(arr[i], arr[j]);
//			}
//		}
//	}
//	//insertion sort
//	for (int i = 1; i < 10; i++) {
//		for (int j = i - 1; arr[j] > arr[j + 1]&&j>=0; j--) {
//			swap(arr[j], arr[j + 1]);
//		}
//	}
//}