#include<iostream>
#include<stdlib.h>
#include<unistd.h>
using namespace std;

int front=0,rear=-1;
int cnt=0;
int data[5];


void enque(int no)
{
rear=(rear+1)%5;
data[rear]=no;
cnt++;
}

int isfull()
{
if(cnt==5)
return 1;
else
return 0;
}

void display()
{
int i;
for(i=front;i!=rear;i=(i+1)%5)
{
cout<<"\nOrder of table no  has been served"<<data[i];
sleep(2);
}
cout<<"\nOrder of table no has been served"<<data[i];
sleep(2);
}

int main()
{
int ch,n;
cout<<"\nMaximum orders served are 5";
do
{
cout<<"\n\nMenu\n1.Place an order\n2.Display the serving list";
cin>>ch;

switch(ch)
{
case 1: if(!isfull())
	{
		
	
		cout<<"\nEnter your table no.";
		cin>>n;
		enque(n);
			
        }
	else
	cout<<"\nOrders Full!!!!";

	break;

case 2: display();
	break;
}
}while(ch!=3);
return 0;
}














// This C++ program implements a basic circular queue using an array. It simulates a simple restaurant order system where orders are placed (enqueued) and served (displayed). Let's break down the code and explain what a circular queue is:

// What is a Circular Queue?
// A circular queue is a linear data structure that follows FIFO (First In First Out) principle but overcomes the limitation of a linear queue. In a linear queue, once the rear reaches the end of the array, it can't be used to insert new elements even if there are free spaces at the beginning. A circular queue connects the end of the array back to the front, forming a circle, making it a more efficient use of storage.

// Code Explanation
// Global Variables

// front, rear: Integer variables to keep track of the front and rear of the queue.
// cnt: Counts the number of elements in the queue.
// data[5]: Array to store the queue elements.
// Function: enque(int no)

// Adds a new order (denoted by no, representing a table number) to the queue.
// The rear is updated in a circular manner using modular arithmetic.
// cnt is incremented to reflect the new order's addition.
// Function: isfull()

// Checks if the queue is full. Returns 1 (true) if cnt is 5, else 0 (false).
// Function: display()

// Displays the orders in the queue from front to rear.
// Uses a loop with modular arithmetic for the circular traversal.
// Includes a sleep(2) call to pause for 2 seconds between serving each order.
// main() Function

// Provides a menu-driven interface to place orders or display the serving list.
// Case 1 allows placing an order if the queue is not full.
// Case 2 displays the current serving list.
// Circular Queue in the Program
// The queue is "circular" because of how the rear index is updated (rear = (rear + 1) % 5) and how the queue is traversed in the display() function (i = (i + 1) % 5). This approach ensures that the rear wraps around to the beginning of the array when it reaches the end, effectively utilizing the entire array.
// Key Points in the Code
// The program simulates a simple order management system using a circular queue.
// The queue can hold a maximum of 5 orders at a time.
// Orders are served in the order they were placed.
// The program lacks a method to dequeue or remove served orders from the queue. As a result, once 5 orders are placed, no new orders can be added, and served orders are not cleared.
// Summary
// The program demonstrates the basic principles of a circular queue using an array in C++. It's a simple model for understanding how circular queues can be used in practical applications like order management systems. However, for a complete implementation, dequeue functionality should be added to remove served orders from the queue.
