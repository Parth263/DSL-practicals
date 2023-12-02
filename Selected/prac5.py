def accept_array(A): 
   n = int(input("Enter the total no. of student : "))
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


def Linear_Search(A,n,X) :
   for i in range(n) :
      if(A[i] == X) :
         return i      # found so returning the position i.e index
   return -1       # Not  found


def Sentinel_Search(A,n,X) :
   last = A[n-1]
   i = 0
   A[n-1] = X    # Here X is the roll_no to be searched.
   while(A[i] != X) :
      i  = i  +1
   A[n-1] = last
   if( (i < n-1) or (X == A[n-1]) ) :
      return i    #roll_no found at location i
   else :
      return -1    # roll_no not found"


def Main() :   
   A = []
   while True :
      print ("\t1 : Accept & Display Students info ")      
      print ("\t2 : Linear Search")
      print ("\t3 : Sentinel Search")
      print ("\t4 : Exit")
      ch = int(input("Enter your choice : "))
      if (ch == 4):
         print ("End of Program")
         quit()
      elif (ch==1):
         A = []
         n = accept_array(A)
         display_array(A,n)
      elif (ch==2):
         X = int(input("Enter the roll_no to be searched : "))
         flag  = Linear_Search(A,n,X)
         if(flag == -1) :
            print("\tRoll no to be Searched not Found\n")
         else :
            print("\tRoll no found at location %d"%(flag + 1))
      elif (ch==3):
         X = int(input("Enter the roll_no to be searched : "))
         flag  = Sentinel_Search(A,n,X)
         if(flag == -1) :
            print("\tRoll no to be Searched not Found\n")
         else :
            print("\tRoll no found at location %d"%(flag + 1))            
      else :
           print ("Wrong choice entered !! Try again")


Main()




# Linear search and sentinel search are both algorithms used to find the position of a target element within a list or array.

# 1. **Linear Search:**
#    - **Description:** Linear search, also known as sequential search, is a simple method of finding a target element within a list. It checks each element in the list one by one until a match is found or the entire list has been searched.
#    - **Algorithm:**
#      1. Start from the beginning of the list.
#      2. Compare each element with the target element.
#      3. If a match is found, return the index of the element; otherwise, continue searching.
#      4. If the end of the list is reached without finding a match, return a special value (e.g., -1) to indicate that the target element is not in the list.
#    - **Time Complexity:** O(n), where n is the number of elements in the list.

# 2. **Sentinel Search:**
#    - **Description:** Sentinel search is an optimization of the linear search algorithm. In this approach, a sentinel (a special value) is placed at the end of the list. This eliminates the need to check for the end of the list during each iteration.
#    - **Algorithm:**
#      1. Place a sentinel value at the end of the list (e.g., set the last element to the target value).
#      2. Start from the beginning of the list.
#      3. Compare each element with the target element.
#      4. If a match is found, return the index of the element; otherwise, continue searching.
#      5. Since the sentinel value is guaranteed to be found, there's no need to explicitly check for the end of the list.
#    - **Time Complexity:** O(n), same as linear search, but with a slight constant factor improvement.

# While sentinel search can provide a small performance improvement over a basic linear search, it may not be as significant for small lists. For larger lists or when the cost of comparisons is high, more advanced algorithms like binary search on a sorted list may be preferred.