#include <bits/stdc++.h> 
// Stack class.
class Stack {
private:
    int arr[10000];
    int t, bottom, cap;
public:
    
    Stack(int capacity) {
        // Write your code here.
        t=-1;bottom=-1;cap=capacity;
    }

    void push(int num) {
        // Write your code here.
        if(isFull()==1) return;
        if(isEmpty()) bottom=0;
        t++;
        arr[t]=num;
    }

    int pop() {
        // Write your code here.
        if(isEmpty()) return -1;
        t--;
        return arr[t+1];
    }
    
    int top() {
        // Write your code here.
        if(!isEmpty()) return arr[t];
        return -1;
    }
    
    int isEmpty() {
        // Write your code here.
        if(t==-1) return true;
        return false;
    }
    
    int isFull() {
        // Write your code here.
        if(t==cap-1) return 1;
        return 0;
    }
    
};
