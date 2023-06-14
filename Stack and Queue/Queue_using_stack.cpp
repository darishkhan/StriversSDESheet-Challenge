#include<bits/stdc++.h>
class Queue {
    // Define the data members(if any) here.
    stack<int> s1, s2;
    int k;
    public:
    Queue() {
        // Initialize your data structure here.
        k=0;
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        while(!s1.empty())
        {
            k=s1.top();
            s1.pop();
            s2.push(k);
        }
        s2.push(val);
        while(!s2.empty()) 
        {
            k=s2.top();
            s2.pop();
            s1.push(k);
        }
    }

    int deQueue() {
        // Implement the dequeue() function.
        if(s1.empty()) return -1;
        k=s1.top();
        s1.pop();
        return k;
    }

    int peek() {
        // Implement the peek() function here.
        if(s1.empty()) return -1;
        return s1.top();

    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        return s1.empty();
    }
};
