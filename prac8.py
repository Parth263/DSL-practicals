def accept_array(A): 
   n = int(input("Enter the total no. of student : "))
   for i in range(n):
      x = float(input("Enter the  Second year percentage of student %d : "%(i+1)))
      A.append(x)
   print("Array accepted successfully\n\n");

def display_array(A): 
   n = len(A)
   if(n == 0) :
      print("\nNo records in the database")
   else :
      print("Array of SE Marks : ",end=' ')
      for i in range(n) :
         print("%.2f  "%A[i],end=' ')
      print("\n");


def Insertion_sort(A) :
   n = len(A)
   for i in range(1,n) :
      element = A[i]
      j  = i-1
      while( j >= 0) :
         if (A[j] <= element) :
            break
         else :
            A[j+1] = A[j]
            j = j - 1
      A[j+1] = element


def Insertion_sort_gap(A,n,gap,s) :
   for i in range(s+gap,n,gap) :
      element = A[i]
      j = i - gap
      while( j >=0 ) :
         if(A[j] <= element) :
            break;
         else :
            A[j+gap] = A[j]
            j = j - gap
      A[j+gap] = element;
  
def Shell_sort(A) :
   n = len(A)
   gap = int(n / 2)
   while( gap > 0) :
      for s in range(gap) :
         Insertion_sort_gap(A,n,gap,s)
      gap = int(gap / 2)



def Main() :   
   A = []
   while True :
      print ("\t1 : Accept & Display the SE Marks")
      print ("\t2 : Insertion Sort Ascending order")
      print ("\t3 : Shell sort Ascending order and display top five scores")
      print ("\t4 : Exit")
      ch = int(input("Enter your choice : "))
      if (ch == 4):
         print ("End of Program")
         quit()
      elif (ch==1):
         A = []
         accept_array(A)
         display_array(A)
      elif (ch==2):
         print("Marks before sorting")
         display_array(A)
         Insertion_sort(A)
         print("Marks after sorting")
         display_array(A)
      elif (ch==3):
         print("Marks before sorting")
         display_array(A)
         Shell_sort(A)
         print("Marks after sorting")
         display_array(A)
         n =len(A)
         if(n >= 5) :
            print("Top Five Scores : ")
            for i in range(n-1,n-6,-1) :
               print("\t%.2f"%A[i])
         else :
            print("Top Scorers : ")
            for i in range(n-1,-1,-1) :
               print("\t%.2f"%A[i])                  
      else :
           print ("Wrong choice entered !! Try again")


Main()





# #### Insertion Sort
# **Definition**: 
# Insertion Sort is a simple sorting algorithm that builds the final sorted array (or list) one item at a time. It's similar to the way you might sort playing cards in your hands.

# **How It Works**: 
# 1. **Starting from the Second Element**: The algorithm iteratively takes one element from the unsorted part of the list and finds its correct position in the sorted part.
# 2. **Compare and Insert**: The chosen element (key) is compared with the elements in the sorted part of the list. If the sorted element is larger than the key, it is shifted one position to the right.
# 3. **Place the Key**: Once the correct position is found (where the sorted element is less than or equal to the key), the key is placed at this position.
# 4. **Repeat**: This process is repeated for each element in the list, resulting in a sorted list.

# #### Shell Sort
# **Definition**: 
# Shell Sort, also known as the diminishing increment sort, improves upon the insertion sort by breaking the original list into a number of smaller sublists, each of which is sorted using an insertion sort strategy.

# **How It Works**: 
# 1. **Choose a Gap Sequence**: The list is divided into smaller sublists by choosing a 'gap' size. This gap determines how far apart the elements to be compared will be. The gap is usually reduced with each pass, typically starting at half the size of the list, and eventually reducing to 1.
# 2. **Sorting Sublists**: For each gap size, the list is sorted using a modified insertion sort that compares elements that are a certain distance (gap) apart, rather than adjacent elements.
# 3. **Gradually Reducing the Gap**: Initially, with a large gap, elements are compared and swapped if they are far apart, effectively reducing large-scale disarray quickly. As the gap reduces, the list becomes more sorted until the gap is 1, at which point the list undergoes a final insertion sort pass.
# 4. **Complete When Gap Reaches 1**: The process continues until the gap is reduced to 1, and the list is sorted using standard insertion sort, but by this time, the list is already fairly sorted, making the final sorting much quicker.

# ### Summary
# - **Insertion Sort** is like sorting playing cards in your hand, taking one card at a time and placing it at its correct position. It's excellent for small or nearly sorted lists.
# - **Shell Sort** is an advanced variant of insertion sort that first sorts elements far apart from each other and successively reduces the gap between elements to be compared. It’s more efficient for larger lists.