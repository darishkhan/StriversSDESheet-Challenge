#include <bits/stdc++.h> 
class Queue {
private:
    int arr[5000];
    int fr, back;
public:
    Queue() {
        // Implement the Constructor
        fr=-1, back=-1;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(back==-1) return true;
        return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(isEmpty()) fr=0;
        back++;
        arr[back]=data;
    }

    int dequeue() {
        // Implement the dequeue() function
        if(isEmpty()) return -1;
        int k = arr[fr];
        for(int i=fr;i<back;i++) arr[i]=arr[i+1];
        back--;
        return k;

    }

    int front() {
        // Implement the front() function
        if(isEmpty()) return -1;
        return arr[fr];
    }
};
