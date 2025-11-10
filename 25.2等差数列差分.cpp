#include<iostream>
using namespace std;
static const int MAXN = 10001;
int arr[MAXN];
int n=MAXN;
//left,right,start,end,¹«²î
void setRange(int l, int r, int s, int e, int d) {
    arr[l] += s;
    arr[l + 1] += d - s;
    arr[r + 1] -= d + e;
    arr[r + 2] += e;
}
void build() {
    for (int i = 1; i <= n; i++) {
        arr[i] += arr[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        arr[i] += arr[i - 1];
    }