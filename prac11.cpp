#include<iostream>
using namespace std;
class binary;
class node
{	
	node *prev;
	bool n;
	node *next;
public:
	node()
	{
		prev=next=NULL;
	}
	node(bool b) 
	{
		n=b;
		prev=next=NULL;
	}
	friend class binary;
};

class binary
{
	node *start;
	
	public:
		binary()
		{
			start=NULL;
		}
		void generateBinary(int no);
		void displayBinary();
		void onesComplement();
		void twoscomplement();
		binary operator +(binary n1);
	        bool addBitAtBegin(bool val)
	       {
		node *nodee=new node(val);
		 if(start==NULL)
		{
			start=nodee;
		}
		else
		{
			nodee->next=start;
			start->prev=nodee;
			start=nodee;
		}
		return true;
	}
};

void binary::generateBinary(int no)
{
	bool rem;
	node *p;
	rem=no%2;
	start=new node(rem);
	no=no/2;
	while(no!=0)
	{
		rem=no%2;
		no=no/2;
		
	/*
		if(start==NULL)
		{
			start=new node(rem);
		//	cout<<" Start prev: "<<start->prev;
		//	cout<<" Start next: "<<start->next ;
			
		}
		else
		{
		*/
			p=new node(rem);
			p->next=start;
			start->prev=p;
		//	cout<<" Start prev: "<<start->prev->n;
		//	cout<<"   p->n"<<p->n;
			start=p;
			
		//}
	}
}
void binary::displayBinary()
{
	node *t;
	t=start;
	while(t!=NULL)
	{
		cout<<t->n;
		t=t->next;
	}
	
}
void binary::onesComplement()
{
	node *t;
	t=start;
	
	while(t!=NULL)
	{
		if(t->n==0)
			t->n=1;
		else
			t->n=0;
		
		t=t->next;
		
	}
}
binary binary::operator +(binary n1)
{
	binary sum;
	node *a=start;
	node *b=n1.start;
//	bit *s=sum.start;
	bool carry=false;
	while(a->next!=NULL)
		a=a->next;
	while(b->next!=NULL)
		b=b->next;
	
	while(a!=NULL && b!=NULL)
	{
		sum.addBitAtBegin((a->n)^(b->n)^carry);
		carry=((a->n&& b->n) || (a->n&& carry) || (b->n && carry));
		
		a=a->prev;
		b=b->prev;
	}
	while(a!=NULL)
	{
		sum.addBitAtBegin(a->n^carry);
		a=a->prev;
	}
	while(b!=NULL)
	{
		sum.addBitAtBegin(b->n^carry);
		b=b->prev;
	}
	sum.addBitAtBegin(carry);
	return sum;
}
void binary::twoscomplement()
{
	onesComplement();
	bool carry=1;
	node *t;
	t=start;
	while(t->next!=NULL)
	{
		t=t->next;
	}
	while(t!=NULL)
	{
	if(t->n==1&& carry==1)
	{
		t->n=0;
		carry=1;
	}
	else
	if(t->n==0&& carry==1)
	{
		t->n=1;
		carry=0;
	}
	else
	if(carry==0)
	break;
	
	t=t->prev;
}
displayBinary();
}
int main()
{
	int num,num1;
	binary n1,n3,n2;
	int choice=1;
	do
	{
		cout<<"\n\n=========Binary Number Operations========\n";
		cout<<"1. Generate binary\n2.One's Complement\n3.Two's Complement\n4. Addition\n0.Exit\nEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1: cout<<"\nENter Number in decimal form: ";
					cin>>num;
					n1.generateBinary(num);
					cout<<"\nBinary Representation: ";
					n1.displayBinary();
					break;
			case 2:cout<<"\nENter Number in decimal form: ";
					cin>>num;
					n1.generateBinary(num);
					cout<<"\nBinary Representation: ";
					n1.displayBinary();
					cout<<"\nOnes Complement: ";
					n1.onesComplement();
					n1.displayBinary();
					break;
			case 3:cout<<"\nENter Number in decimal form: ";
					cin>>num;
					n1.generateBinary(num);
					cout<<"\nBinary Representation: ";
					n1.displayBinary();
					cout<<"\nTwos complement; ";
					n1.twoscomplement();
					break;
			case 4: cout<<"\nENter Two Numbers: ";
					cin>>num>>num1;
					n1.generateBinary(num);
					n2.generateBinary(num1);
					n1.displayBinary();
					cout<<" + ";
					n2.displayBinary();
					cout<<"= ";
					n3=n1+n2;
					n3.displayBinary();	
                                      }
	}while(choice!=0);
	n1.generateBinary(7);
	cout<<"\nBinary Representation: ";
	n1.displayBinary();
//	
//	cout<<"\nOnes Complement: ";
//	n1.displayBinary();
	cout<<"\nTwos complement; ";
	n1.twoscomplement();
	return 0;
}





// A linked list is a data structure used in computer science to organize and store data. Unlike arrays, which store elements in contiguous memory locations, linked lists consist of nodes where each node contains a data element and a reference (or link) to the next node in the sequence.

// A doubly linked list is a type of linked list where each node contains a data element and two pointers or references. These pointers point to the previous and next nodes in the sequence, forming a bidirectional link between nodes. The structure of a doubly linked list allows for easier traversal in both directions, forward and backward.

// Here's a basic overview of the structure of a doubly linked list node:

// ```plaintext
// +---------------------+
// |      Data           |
// +---------------------+
// |   Previous Pointer  |
// +---------------------+
// |   Next Pointer      |
// +---------------------+
// ```

// - **Data:** This field contains the actual data or value stored in the node.

// - **Previous Pointer:** This pointer/reference points to the previous node in the sequence. For the first node in the list, this pointer typically points to a null or a special value indicating the beginning of the list.

// - **Next Pointer:** This pointer/reference points to the next node in the sequence. For the last node in the list, this pointer typically points to null or a special value indicating the end of the list.

// Advantages of doubly linked lists include the ability to traverse the list in both forward and backward directions, making certain operations more efficient. However, doubly linked lists require more memory than singly linked lists due to the additional storage needed for the previous pointers. The choice between singly linked and doubly linked lists depends on the specific requirements of the application.

// This C++ code defines a program that performs operations on binary numbers using a linked list representation. The program includes a `node` class to represent individual bits in a binary number and a `binary` class to perform operations on binary numbers.

// Let's go through the main components and functionality of the code:

// 1. **Classes:**
//    - **`node` class:**
//      - Represents a node in the doubly linked list, where each node contains a boolean value (`n`) and pointers to the previous and next nodes.
//      - It has two constructors: a default constructor and a parameterized constructor that initializes the boolean value.
//      - The `friend class binary;` declaration allows the `binary` class to access the private members of the `node` class.

//    - **`binary` class:**
//      - Manages binary numbers using a doubly linked list of `node` objects.
//      - Contains member functions for generating binary representations, displaying binary numbers, finding the one's complement, finding the two's complement, and performing binary addition.
//      - Overloads the `+` operator to perform binary addition.

// 2. **Function Descriptions:**
//    - **`generateBinary(int no)`:**
//      - Generates the binary representation of a decimal number `no` and stores it in the doubly linked list.

//    - **`displayBinary()`:**
//      - Displays the binary representation of the number stored in the linked list.

//    - **`onesComplement()`:**
//      - Computes and displays the one's complement of the binary number.

//    - **`operator +(binary n1)`:**
//      - Overloaded `+` operator to perform binary addition of two binary numbers.

//    - **`twoscomplement()`:**
//      - Computes and displays the two's complement of the binary number.

// 3. **`main()` Function:**
//    - The main function creates instances of the `binary` class and allows the user to perform various operations on binary numbers through a menu-driven interface.
//    - The user can input decimal numbers, generate their binary representations, find the one's complement, find the two's complement, and perform binary addition.
//    - The program runs in a loop until the user chooses to exit.

// 4. **Example Usage:**
//    - The `main()` function demonstrates the usage of the `binary` class by allowing the user to input decimal numbers, generate their binary representations, and perform operations like finding the one's complement, two's complement, and binary addition.

// Note: The code seems to have a minor issue in the `twoscomplement()` function where the `displayBinary();` statement is called, but it should be `this->displayBinary();` or `n1.displayBinary();` to refer to the object's member function.