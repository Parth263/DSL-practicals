#include<iostream>
#include<string.h>
#define MAX 100
using namespace std;

 struct stack
 {
     char data[MAX];
     int top;
 };

 void init(stack *stck)
 {
     int i;
     for(i=0;i<MAX;i++)
     {
         stck->data[i]='\0';
         stck->top=-1;
     }
 }

 void print(stack stck)
 {
     int i;
     cout<<"\n Stack elements are";
     for(i=0;i<MAX;i++)
     {
         cout<<"stck.data[i]";
         cout<<"\t top="<<stck.top;
     }
 }

 int isempty(stack stck)
 {
     return stck.top==-1?1:0;
 }

 int isfull(stack stck)
 {
     return stck.top==MAX-1?1:0;

 }

 void push(stack *stck,char data[MAX])
 {
     int i;
     for(i=0;data[i]!='\0';i++)
     {
     stck->top+=1;
     stck->data[stck->top]=data[i];
     }
 }

 void push1(stack *stck,char data[MAX])
 {
     int i;
     for(i=0;data[i]!='\0';i++)
     {
       if(data[i]!=' ')
       {
     stck->top+=1;
     stck->data[stck->top]=data[i];
       }
     }
 }


 void pop(stack *stck)
 {
     char rev[MAX];
     int i=0;
     while(!isempty(*stck))
     {
     rev[i]=stck->data[stck->top];
     stck->top-=1;
     i++;
     }
     rev[i]='\0';
     cout<<"\n Original string is="<<stck->data;
     cout<<"\n reverse string is=";
     cout<<rev;
     if(strcmp(rev,stck->data))
     {
     cout<<"\n string is not palindrome";
     }
     else
     {
     cout<<"\n String is palindrome";
     }
 }

 int main()
 {
     stack stck;
     char data[MAX]={'E','v','a',',',' ','c','a','n',' ','I',' ','s','e','e',' ','b','e','e','s',' ','i','n',' ','a',' ','c','a','v','e','\0'};

     init(&stck);
     int ch,i,j=0;

     while(ch!=3)
     {
     cout<<"\n1.Push the string;Print reverse string & check palindrome or not(pop)";

     cout<<"\n2.Remove blank space,convert upperspace into lowercase,push the string & check palindrome or not";

     cout<<"\n3.Exit";

     cout<<"\n Enter your choice";
     cin>>ch;

     switch(ch)
     {
     case 1:
         if(isfull(stck))
         {
         cout<<"\n Stack is full";
         }
         else
         {
         push(&stck,data);
         }
         if(isempty(stck))
         {
         cout<<"\n Stack is empty";
         }
         else
         {
         pop(&stck);
         }
         break;

     case 2:
         init(&stck);
         if(isfull(stck))
         {
         cout<<"\n Stack is full";
         }
         else
         {
         for(i=0;data[i]!='\0';i++)
          {
            if(data[i]!=' ')
            {
             if(data[i]>=65 && data[i]<=90)
              {
                data[i]=data[i]+32;
              }

            }
          }
        push1(&stck,data);

         }
         pop(&stck);
         break;
         }
     }
     return (0);
 }

















//  Struct Definition: stack
// Defines a stack structure with:
// data[MAX]: An array of char to store the stack elements.
// top: An integer to track the top of the stack.
// Functions Defined
// init(stack *stck): Initializes the stack by setting all elements to \0 and top to -1.
// print(stack stck): Prints the elements of the stack and the current top index (though, there's a mistake in the print statement).
// isempty(stack stck): Returns 1 (true) if the stack is empty, 0 (false) otherwise.
// isfull(stack stck): Returns 1 (true) if the stack is full, 0 (false) otherwise.
// push(stack *stck, char data[MAX]): Pushes a string onto the stack.
// push1(stack *stck, char data[MAX]): Similar to push, but it ignores spaces.
// pop(stack *stck): Pops elements from the stack to form a reversed string, checks if the reversed string is the same as the original (palindrome check).
// Main Function
// Stack and String Initialization:
// A stack object stck and a char array data are created. data is initialized with a specific string.
// Menu-Driven Interface:
// The user is presented with options to push the string onto the stack, check for palindrome, and exit.
// Case 1:
// Pushes the string onto the stack and then pops it to check if it's a palindrome.
// Case 2:
// First, spaces are removed from data, and uppercase letters are converted to lowercase.
// Then, the modified string is pushed onto the stack and checked for palindrome.
// Code Analysis and Issues
// The print function is not correctly implemented. cout << "stck.data[i]" should be cout << stck.data[i].
// There's no input to change ch inside the loop in main(), so it might result in an infinite loop.
// The pop function compares the reversed string with the original incorrectly. It should compare with a copy of the original, as the stack's data array is altered during the pop operation.
// The program uses global variable MAX to define the stack size. It's a common practice to use constants for fixed sizes, but it lacks flexibility.
// The stack implementation is basic and tailored to the specific needs of this program (like palindrome checking). It's not a general-purpose stack.
