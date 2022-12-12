#include <bits/stdc++.h>
using namespace std;

stack<int> sorting(stack<int>);

int main() {
    int n;
    cin >> n;
    stack<int> myStack;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        myStack.push(tmp);
    }
    stack<int> result = sorting(myStack);
    vector<int> answer;
    while (!result.empty()) {
        answer.push_back(result.top());
        result.pop();
    }
    // 这里可行，auto在c++11中使用
    for (auto i = answer.rbegin(); i != answer.rend(); ++i)
        cout << *i << endl;
    return 0;
}

// myStack：输入栈，栈中的所有元素即是待排序的元素
// 返回值：输出栈，即排序后的序列，满足从栈底至栈顶为升序
stack<int> sorting(stack<int> myStack) {
    /* 请在这里设计你的算法！ */
    stack<int> result; // result存放返回值，即输出栈

    // 首先判断输入栈是否为空。
    if (myStack.empty()) return result;

    // 记录下一个要插入result栈中的数，也就是输入栈的栈顶。cpp语言pop后不会返回，通过pop获取栈顶元素
    int tmp = myStack.top();

    // 弹出栈顶，栈顶元素保留在tmp中
    myStack.pop();

    // 1 myStack不能是空的，空的就停止循环；或 
    // 2.1 result不能是空的，如果是空的则不跳过循环，直接把myStack的栈顶压入result
    // 2.2 result不为空并且 myStack的栈顶元素比result的栈顶元素小，那么就要把myStack的栈顶插入到result的合适的位置

    while (!myStack.empty() || (!result.empty() && tmp < result.top())) {
        
        //判断什么时候直接压入栈
        if (result.empty() || result.top() <= tmp) {  //如果result是空的，或者result的栈顶比tmp小，即，压入tmp就是个升序栈
            result.push(tmp); //压入myStack的栈顶就是个升序栈

            //准备下一次比较
            tmp = myStack.top(); 
            myStack.pop();
        }
		//判断什么时候result里的数要先回myStack
        else {
            //此时tmp比result的栈顶小，直接压入破坏队形，所以要重新调整
            //myStack的栈顶已经被tmp记录并且取出
            myStack.push(result.top()); // 把result里的数从顶到底压人myStack（回窝）
            result.pop(); //弹出，直到result.top() <= tmp
        }
    }

    // 输入栈myStack迭代空了，且其最后一个元素tmp大于输出栈result的栈顶元素
    result.push(tmp); //输出栈result不能是空的，如果是空的直接把tmp压栈
    return result;

}