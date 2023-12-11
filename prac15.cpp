#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
typedef struct n {    // node declaration 
   int p;
   int info;
   struct n *l;
}n1;

class Priority_Queue 
{
   private:
      			//Declare a front pointer f and initialize it to NULL.
      n1 *f;
   public:
   Priority_Queue() //constructor 
     {
         f = NULL;
      }
     
   void insert(int i, int p) 
     {
         n1 *t, *q;
         t = new n;
         t->info = i;
         t->p = p;
         if (f == NULL || p < f->p) 
	{
            t->l= f;
            f = t;
         } 
	else 
	{
            q = f;
            while (q->l != NULL && q->l->p <= p)
               q = q->l;
               t->l = q->l;
               q->l = t;
         }
      }
    void del() 
    {
         n1 *t;
         if(f == NULL) //if queue is null
            cout<<"Queue Underflow\n";
         else 
          {
            t = f;
            cout<<"Deleted item is: "<<t->info<<endl;
            f = f->l;
            free(t);
         }
      }
      void show() //print queue 
      { 
	 n1 *ptr;
         ptr = f;
         if (f == NULL)
            cout<<"Queue is empty\n";
         else
          {
            cout<<"Queue is :\n";
            cout<<"Priority Item\n";
            while(ptr != NULL) {
               cout<<ptr->p<<" "<<ptr->info<<endl;
               ptr = ptr->l;
            }
         }
      }
};
int main() {
   int c, i, p;
   Priority_Queue pq;
   do //perform switch opeartion
   {
      cout<<"1.Insert\n";
      cout<<"2.Delete\n";
      cout<<"3.Display\n";
      cout<<"4.Exit\n";
      cout<<"Enter your choice : ";
      cin>>c;
      switch(c) {
         case 1:
            cout<<"Input the item value to be added in the queue : ";
            cin>>i;
            cout<<"Enter its priority : ";
            cin>>p;
            pq.insert(i, p);
            break;
         case 2:
            pq.del();
            break;
         case 3:
            pq.show();
            break;
         case 4:
            break;
         default:
         cout<<"Wrong choice\n";
      }
   }
   while(c != 4);
   return 0;
}












// Code Explanation
// Structure Definition: n

// Defines a node structure n1 with three members:
// p: An integer to store the priority of the node.
// info: An integer to store the actual value or information of the node.
// l: A pointer to the next node in the list.
// Class Definition: Priority_Queue

// Encapsulates the operations of a priority queue.
// Constructor
// Initializes the f (front) pointer to NULL.
// Function: insert(int i, int p)
// Inserts a new node with value i and priority p.
// If the queue is empty or the new node's priority is higher than the front node's priority, the new node is added at the beginning.
// Otherwise, it finds the correct position and inserts the node based on its priority.
// Function: del()
// Deletes the node from the front of the queue (the node with the highest priority).
// Prints the deleted item's value.
// Handles the case when the queue is empty.
// Function: show()
// Displays the elements of the priority queue along with their priorities.
// If the queue is empty, it prints a message.
// Main Function

// Provides an interactive interface to the user with options to perform enqueue (insert), dequeue (delete), display the queue, or exit the application.
// The user can insert elements with a specified priority. The program then places these elements in the correct position in the queue based on their priority.
// Switch Cases in main()
// Case 1 - Insert: User inputs a value and its priority, which are then inserted into the queue.
// Case 2 - Delete: Deletes the element from the front of the queue (the highest priority element).
// Case 3 - Display: Shows the elements in the queue along with their priorities.
// Case 4 - Exit: Exits the loop and ends the program.