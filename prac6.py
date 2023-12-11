def accept_array(A): 
   n = int(input("Enter the total no. of student : "))
   print("Input roll numbers in sorted order")
   for i in range(n):
      x = int(input("Enter the  roll no of student %d : "%(i+1)))
      A.append(x)
   print("Student Info accepted successfully\n\n")
   return n

def display_array(A,n): 
   if(n == 0) :
      print("\nNo records in the database")
   else :
      print("Students  Array : ",end=' ')
      for i in range(n) :
         print("%d  "%A[i],end=' ')
      print("\n");


def Recursive_Binary_Search(A,s,l,X) :
   if(s <= l ) :
      mid = int((s + l) / 2)
      if(A[mid] == X) :
         return mid      # Found
      else :
         if(X < A[mid] ) :
            return Recursive_Binary_Search(A,s,mid-1,X)
         else :
            return Recursive_Binary_Search(A,mid+1,l,X)
   return -1 # NOT FOUND



def Iterative_Binary_Search(A,n,X) :
   s = 0
   l = n-1
   while(s <= l ) :
      mid = int((s + l) / 2)
      if(A[mid] == X) :
         return mid       # Found
      else :
         if (X < A[mid] )  :
            l = mid-1
         else :
            s = mid+1
   return -1; #NOT FOUND


#Returns index of x if present,  else returns -1 
def Fibonacci_Search(A,n,X) :
   f1 = 0
   f2 = 1
   f3 = f1 + f2
   offset = -1
   while (f3 < n) :
      f1 = f2
      f2 = f3
      f3  = f1 + f2
   while (f3 > 1) :
      i = min(offset+f1, n-1)
      if(A[i] == X) :
         return i        #Found
      else :
         if (X < A[i] ) :   # left substudent (66 % or 2/3 student)
            f3  = f1
            f2 = f2 - f1
            f1 = f3 - f2
         else :     # right substudent ( 33 % or 1/3 student)
            f3  = f2
            f2 = f1
            f1 = f3 - f2
            offset = i
   if(f2 == 1 and (offset+1) < n and A[offset + 1] == X) :      
      return offset+1      # Found
   return -1    #NOT FOUND


def Main() :   
   A = []
   while True :
      print ("\t1 : Accept & Display Students info ")      
      print ("\t2 : Recursive Binary Search")
      print ("\t3 : Iterative Binary Search")
      print ("\t4 : Fibonacci Search")
      print ("\t5 : Exit")
      ch = int(input("Enter your choice : "))
      if (ch == 5):
         print ("End of Program")
         quit()
      elif (ch==1):
         A = []
         n = accept_array(A)
         display_array(A,n)
      elif (ch==2):
         X = int(input("Enter the roll_no to be searched : "))
         flag  = Recursive_Binary_Search(A,0,n-1,X)
         if(flag == -1) :
            print("\tRoll no to be Searched not Found\n")
         else :
            print("\tRoll no found at location %d"%(flag + 1))
      elif (ch==3):
         X = int(input("Enter the roll_no to be searched : "))
         flag  = Iterative_Binary_Search(A,n,X)
         if(flag == -1) :
            print("\tRoll no to be Searched not Found\n")
         else :
            print("\tRoll no found at location %d"%(flag + 1)) 
      elif (ch==4):
         X = int(input("Enter the roll_no to be searched : "))
         flag  = Fibonacci_Search(A,n,X)
         if(flag == -1) :
            print("\tRoll no to be Searched not Found\n")
         else :
            print("\tRoll no found at location %d"%(flag + 1))            
      else :
           print ("Wrong choice entered !! Try again")


Main()





# Binary Search
# Binary Search is an efficient algorithm for finding an item from a sorted list of items. It works by repeatedly dividing in half the portion of the list that could contain the item, until you've narrowed down the possible locations to just one.

# Iterative Binary Search:
# This approach uses a loop to divide the search interval in half.
# You keep track of the search interval with two indices (start and end).
# In each iteration, you compare the middle element of the interval with the target value. If they match, you've found the item.
# If the target is smaller, you adjust the end index; if larger, you adjust the start index.
# The loop continues until the item is found or the interval is empty.
# Recursive Binary Search:
# This approach uses the same divide-and-conquer strategy but implements it using recursion.
# The function calls itself with a new half of the original list based on whether the target would be in the left or right half.
# The base case occurs when the start index is greater than the end index, indicating the item isn't in the list.
# Fibonacci Search
# Fibonacci Search is another divide-and-conquer algorithm that divides the search space using Fibonacci numbers. It is a method of searching a sorted array using a divide and conquer algorithm that narrows down possible locations with the aid of Fibonacci numbers.

# It uses Fibonacci numbers to identify the indexes to be compared and to split the array.
# Initially, the largest Fibonacci number smaller than or equal to the array size is chosen.
# The array is divided into two parts that are proportional to consecutive Fibonacci numbers.
# It then follows a similar process to binary search, adjusting the search interval based on the comparison but uses Fibonacci numbers to determine the index of the next element to compare.
# This search can be particularly efficient when the size of the array is close to a Fibonacci number.
