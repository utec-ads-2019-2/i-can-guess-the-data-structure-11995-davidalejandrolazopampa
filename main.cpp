//David Lazo
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main() {
    int num, lp, dav;
    while(cin >> num) {
        bool primero = true, segundo = true, tercero = true;
        queue<int> queue1;
        stack<int> stack1;
        priority_queue<int> priorityQueue1;
        while(num--) {
            cin >> lp >> dav;
            if (lp == 1) {
                if (primero) queue1.push(dav);
                if (segundo) stack1.push(dav);
                if (tercero) priorityQueue1.push(dav);
            } else {
                if (!primero) {}
                else {
                    if (queue1.empty() || queue1.front() != dav) primero = false;
                    if (primero) queue1.pop();
                }
                if (!segundo) {}
                else {
                    if (stack1.empty() || stack1.top() != dav) segundo = false;
                    if (segundo) stack1.pop();
                }
                if (!tercero) continue;
                if (!priorityQueue1.empty() && priorityQueue1.top() == dav) {} else tercero = false;
                if (!tercero) continue;
                priorityQueue1.pop();
            }
        }
        if(!primero && !segundo && !tercero)
            cout << "impossible"<<endl;
        else if(primero && !segundo && !tercero)
            cout << "queue"<<endl;
        else if(!primero && segundo && !tercero)
            cout << "stack"<<endl;
        else if(!primero && !segundo && tercero)
            cout << "priority queue"<<endl;
        else cout << "not sure"<<endl;
    }
    return 0;
}