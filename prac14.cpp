#include <iostream>
#define MAX 5
using namespace std;

struct queue {
    int data[MAX];
    int front, rear;
};

class Queue {
    struct queue q;
public:
    Queue() {
        q.front = 0;
        q.rear = -1;
    }
    bool isempty();
    bool isfull();
    void enqueue(int);
    int delqueue();
    void display();
};

bool Queue::isempty() {
    return q.front == (q.rear + 1) % MAX;
}

bool Queue::isfull() {
    return q.front == (q.rear + 2) % MAX;
}

void Queue::enqueue(int x) {
    if (!isfull()) {
        q.rear = (q.rear + 1) % MAX;
        q.data[q.rear] = x;
    } else {
        cout << "\nQueue is overflow";
    }
}

int Queue::delqueue() {
    if (!isempty()) {
        int x = q.data[q.front];
        q.front = (q.front + 1) % MAX;
        return x;
    } else {
        cout << "\nQueue is underflow";
        return -1; // Indicating underflow
    }
}

void Queue::display() {
    cout << "\n";
    if (!isempty()) {
        int i = q.front;
        while (i != q.rear) {
            cout << q.data[i] << " ";
            i = (i + 1) % MAX;
        }
        cout << q.data[i]; // Displaying the last element
    } else {
        cout << "Queue is empty";
    }
}

int main() {
    Queue obj;
    int ch, x;
    do {
        cout << "\n1. Insert job\n2. Delete job\n3. Display\n4. Exit\nEnter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "\nEnter data: ";
                cin >> x;
                obj.enqueue(x);
                break;
            case 2:
                x = obj.delqueue();
                if (x != -1) {
                    cout << "\nDeleted Element = " << x;
                }
                cout << "\nRemaining jobs: ";
                obj.display();
                break;
            case 3:
                cout << "\nQueue contains: ";
                obj.display();
                break;
            case 4:
                cout << "\nExit";
                break;
            default:
                cout << "\nUnknown choice";
        }
    } while (ch != 4);
    return 0;
}





// In C++, a queue is a data structure that follows the First-In-First-Out (FIFO) principle. This means that the first element added to the queue will be the first one to be removed. It's similar to a real-life queue or line, where the first person who joins the line is the first one to be served.

// C++ provides a standard template library (STL) class called std::queue that implements a queue. It is part of the <queue> header. Here's a basic example of how to use a queue in C++:

// cpp
// Certainly! Here's the explanation of the provided C++ code without the code snippets:

// 1. **Include Headers and Define Macro:**
//    - The code includes the `<iostream>` header for input and output operations.
//    - It defines a macro named `MAX` with a value of 5, representing the maximum size of the queue.

// 2. **Define Queue Structure:**
//    - The code defines a structure named `queue` with an array `data` to store elements and two integer variables `front` and `rear` to represent the front and rear of the queue.

// 3. **Define Queue Class:**
//    - The code defines a class named `Queue` that encapsulates the queue operations.
//    - It contains a private member `q` of type `queue` to store the queue data.
//    - The constructor initializes `front` and `rear` to -1.
//    - Member functions include:
//      - `isempty()`: Checks if the queue is empty.
//      - `isfull()`: Checks if the queue is full.
//      - `enqueue(int)`: Adds an element to the queue.
//      - `delqueue()`: Removes and returns an element from the queue.
//      - `display()`: Displays the elements of the queue.

// 4. **Define Member Function `isempty()`:**
//    - Checks if `front` is equal to `rear` to determine if the queue is empty.

// 5. **Define Member Function `isfull()`:**
//    - Checks if `rear` is equal to `MAX - 1` to determine if the queue is full.

// 6. **Define Member Function `enqueue(int)`:**
//    - Increments `rear` and assigns the given value to the corresponding position in the array `data`.

// 7. **Define Member Function `delqueue()`:**
//    - Increments `front` and returns the value from the corresponding position in the array `data`.

// 8. **Define Member Function `display()`:**
//    - Prints the elements of the queue by iterating through the array `data` from `front + 1` to `rear`.

// 9. **Main Function:**
//    - Creates an object `obj` of the `Queue` class.
//    - Uses a `do-while` loop to present a menu for the user to choose operations.
//    - User choices include inserting a job, deleting a job, displaying the queue, and exiting.
//    - Calls the corresponding member functions based on the user's choice.
//    - The loop continues until the user chooses to exit.

// The overall code demonstrates the implementation of a basic queue using a class in C++. It shows how to perform operations such as enqueue, dequeue, and display in a queue data structure.