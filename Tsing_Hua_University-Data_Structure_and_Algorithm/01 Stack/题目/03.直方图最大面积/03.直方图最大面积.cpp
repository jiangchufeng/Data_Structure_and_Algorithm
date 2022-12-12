#include <bits/stdc++.h>
using namespace std;

// n：意义如题
// height：高度数组，height[i]表示第i列的高度（下标从1开始），数组大小为n+2，其中height[0]和height[n+1]都为0
// 返回值：题目所求答案，即最大面积
int getAnswer(int n, int* height) {
    /* 请在这里设计你的算法，并将答案返回 */
    int res = 0;
    
    // 单调栈，记录的是在h数组中的位置，栈顶所对应的高度是最高的，也就是单调递增
    stack<int> myStack;
    
    // 初始化单调栈，提前压入一个哨兵，总体有前后两个哨兵，分别是h[0]和h[n+1]，高度都是0
    myStack.push(0);
    
    // 整体按索引i的值依次比较，求到索引位置为止的最大面积,相当于固定右下标，移动左下标，挨个去比较
    // 当前索引为止，面积res只与height[i-1]及i有关系
    // 进行栈过滤, 从1到n+1, 最后一个也是一个哨兵0, 可以循环n+1次
    for (int i = 1; i <= n + 1; ++i) {         
        // 找最矮的高度*最长的底边
        while (height[myStack.top()] > height[i]) {// 如果栈顶元素高度大于当前元素的高度时，则弹出栈顶
            
            // 记录栈顶元素高度
            int nowHeight = height[myStack.top()];
            // 弹出栈顶
            myStack.pop();
            // 比较最大面积
            res = max(res, (i - myStack.top() - 1) * nowHeight);  // 这个语句很微妙
        }
        // 将当前下标插入栈中
        myStack.push(i);
    }
    return res;

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