#include <bits/stdc++.h> 
class Stack {
	// Define the data members.
private:
queue<int> q;
int i;
   public:
    Stack() {
        // Implement the Constructor.
        i=0;
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return q.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return q.empty();
    }

    void push(int element) {
        // Implement the push() function.
        q.push(element);
        for(int i=0;i<q.size()-1;i++)
        {
            int k = q.front();
            q.pop();
            q.push(k);
        }
    }

    int pop() {
        // Implement the pop() function.
        if(q.empty()) return -1;
        int k = q.front();
        q.pop();
        return k;
    }

    int top() {
        // Implement the top() function.
        if(q.empty()) return -1;
        return q.front();
    }
};
