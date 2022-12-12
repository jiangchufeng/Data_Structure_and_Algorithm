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
    // ������У�auto��c++11��ʹ��
    for (auto i = answer.rbegin(); i != answer.rend(); ++i)
        cout << *i << endl;
    return 0;
}

// myStack������ջ��ջ�е�����Ԫ�ؼ��Ǵ������Ԫ��
// ����ֵ�����ջ�������������У������ջ����ջ��Ϊ����
stack<int> sorting(stack<int> myStack) {
    /* ���������������㷨�� */
    stack<int> result; // result��ŷ���ֵ�������ջ

    // �����ж�����ջ�Ƿ�Ϊ�ա�
    if (myStack.empty()) return result;

    // ��¼��һ��Ҫ����resultջ�е�����Ҳ��������ջ��ջ����cpp����pop�󲻻᷵�أ�ͨ��pop��ȡջ��Ԫ��
    int tmp = myStack.top();

    // ����ջ����ջ��Ԫ�ر�����tmp��
    myStack.pop();

    // 1 myStack�����ǿյģ��յľ�ֹͣѭ������ 
    // 2.1 result�����ǿյģ�����ǿյ�������ѭ����ֱ�Ӱ�myStack��ջ��ѹ��result
    // 2.2 result��Ϊ�ղ��� myStack��ջ��Ԫ�ر�result��ջ��Ԫ��С����ô��Ҫ��myStack��ջ�����뵽result�ĺ��ʵ�λ��

    while (!myStack.empty() || (!result.empty() && tmp < result.top())) {
        
        //�ж�ʲôʱ��ֱ��ѹ��ջ
        if (result.empty() || result.top() <= tmp) {  //���result�ǿյģ�����result��ջ����tmpС������ѹ��tmp���Ǹ�����ջ
            result.push(tmp); //ѹ��myStack��ջ�����Ǹ�����ջ

            //׼����һ�αȽ�
            tmp = myStack.top(); 
            myStack.pop();
        }
		//�ж�ʲôʱ��result�����Ҫ�Ȼ�myStack
        else {
            //��ʱtmp��result��ջ��С��ֱ��ѹ���ƻ����Σ�����Ҫ���µ���
            //myStack��ջ���Ѿ���tmp��¼����ȡ��
            myStack.push(result.top()); // ��result������Ӷ�����ѹ��myStack�����ѣ�
            result.pop(); //������ֱ��result.top() <= tmp
        }
    }

    // ����ջmyStack�������ˣ��������һ��Ԫ��tmp�������ջresult��ջ��Ԫ��
    result.push(tmp); //���ջresult�����ǿյģ�����ǿյ�ֱ�Ӱ�tmpѹջ
    return result;

}