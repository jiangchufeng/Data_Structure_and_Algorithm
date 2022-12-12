#include <bits/stdc++.h>
using namespace std;

// n����������
// height���߶����飬height[i]��ʾ��i�еĸ߶ȣ��±��1��ʼ���������СΪn+2������height[0]��height[n+1]��Ϊ0
// ����ֵ����Ŀ����𰸣���������
int getAnswer(int n, int* height) {
    /* ���������������㷨�������𰸷��� */
    int res = 0;
    
    // ����ջ����¼������h�����е�λ�ã�ջ������Ӧ�ĸ߶�����ߵģ�Ҳ���ǵ�������
    stack<int> myStack;
    
    // ��ʼ������ջ����ǰѹ��һ���ڱ���������ǰ�������ڱ����ֱ���h[0]��h[n+1]���߶ȶ���0
    myStack.push(0);
    
    // ���尴����i��ֵ���αȽϣ�������λ��Ϊֹ��������,�൱�ڹ̶����±꣬�ƶ����±꣬����ȥ�Ƚ�
    // ��ǰ����Ϊֹ�����resֻ��height[i-1]��i�й�ϵ
    // ����ջ����, ��1��n+1, ���һ��Ҳ��һ���ڱ�0, ����ѭ��n+1��
    for (int i = 1; i <= n + 1; ++i) {         
        // ����ĸ߶�*��ĵױ�
        while (height[myStack.top()] > height[i]) {// ���ջ��Ԫ�ظ߶ȴ��ڵ�ǰԪ�صĸ߶�ʱ���򵯳�ջ��
            
            // ��¼ջ��Ԫ�ظ߶�
            int nowHeight = height[myStack.top()];
            // ����ջ��
            myStack.pop();
            // �Ƚ�������
            res = max(res, (i - myStack.top() - 1) * nowHeight);  // �������΢��
        }
        // ����ǰ�±����ջ��
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