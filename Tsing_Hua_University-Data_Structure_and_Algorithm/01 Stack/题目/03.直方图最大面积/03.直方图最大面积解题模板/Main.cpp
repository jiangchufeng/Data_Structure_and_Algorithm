#include <bits/stdc++.h>
using namespace std;

// n：意义如题
// height：高度数组，height[i]表示第i列的高度（下标从1开始），数组大小为n+2，其中height[0]和height[n+1]都为0
// 返回值：题目所求答案，即最大面积
int getAnswer(int n, int *height) {
    /* 请在这里设计你的算法，并将答案返回 */
}

int main() {
    int n;
    cin >> n;
    
    int* height = new int[n + 2]();
    
    for (int i = 1; i <= n; ++i)
        cin >> height[i];
    
    cout << getAnswer(n, height) << endl;
    
    delete[] height;
    return 0;
}
