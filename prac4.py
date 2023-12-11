def construct_magic_square_matrix(M,n) :    
    for i in range(n) :
       A = []
       for j in range (n) :
          A.append(int(-1))
       M.append(A)
    i = 0
    j = int((n - 1) / 2)
    s = 1
    count = 0
    while(count < (n * n)) :
        M[i][j] = s
        s = s + 1
        count = count + 1
        
        if(i == 0) :
            ni = n - 1
        else:
            ni = i - 1;
        if(j == 0) :
            nj = n - 1
        else:
            nj = j - 1;
        if(M[ni][nj] != -1) :
            ni = int((i + 1 ) % n)
            nj = j
        i = ni
        j = nj
        
    print("\nMagic Square Matrix constructed successfully\n")


def display_matrix(M,n): 
   print("Magic Square Matrix (%d,%d) : "%(n,n))
   for i in range(n) :
      print("\t\t",end=' ')
      for j in range(n):
          print("%2d"%M[i][j],end='   ')
      print("")	
   print("Sum in each row & each column = %d"%int(n*(n*n+1)/2)) 

       

def main():
   
   while True :
       print("\t\t\t1: Find Magic Square");
       print("\t\t\t2: Exit");
       ch = int(input("Enter your choice : "))       
       if (ch == 2):
           print ("End of Program")
           break
       elif (ch==1):
           M = []
           n = int(input("\nEnter the order of the Square Matrix (n,n) : "))
           construct_magic_square_matrix(M,n);
           display_matrix(M,n)	
       else :
           print ("Wrong choice entered !! Try again")

main()
quit()



# Sure, let's break down the code function by function and then discuss what a magic square matrix is.

# ### `construct_magic_square_matrix(M, n):`
# ```python
# def construct_magic_square_matrix(M, n):
#     for i in range(n):
#         A = []
#         for j in range(n):
#             A.append(int(-1))
#         M.append(A)
#     i = 0
#     j = int((n - 1) / 2)
#     s = 1
#     count = 0
#     while count < (n * n):
#         M[i][j] = s
#         s = s + 1
#         count = count + 1
#         if i == 0:
#             ni = n - 1
#         else:
#             ni = i - 1
#         if j == 0:
#             nj = n - 1
#         else:
#             nj = j - 1
#         if M[ni][nj] != -1:
#             ni = int((i + 1) % n)
#             nj = j
#         i = ni
#         j = nj
#     print("\nMagic Square Matrix constructed successfully\n")
# ```

# **Explanation:**
# - This function constructs a magic square matrix of order `n`. The magic square is a square matrix where the sum of every row, column, and both main diagonals is the same.
# - The matrix `M` is initialized as an empty list of lists.
# - The outer loop initializes the matrix `M` with each element set to -1.
# - The initial position `(i, j)` is set at the top center of the matrix.
# - The while loop continues until all cells in the matrix are filled.
# - At each step, the current position is set to the current value of `s`.
# - The next position is determined based on the current position, and adjustments are made to wrap around if needed.
# - If the next position is already filled, it moves down one row.
# - Finally, the loop updates the current position to the next position.
# - The function prints a message indicating that the magic square matrix has been successfully constructed.

# ### `display_matrix(M, n):`
# ```python
# def display_matrix(M, n):
#     print("Magic Square Matrix (%d,%d) : " % (n, n))
#     for i in range(n):
#         print("\t\t", end=' ')
#         for j in range(n):
#             print("%2d" % M[i][j], end='   ')
#         print("")
#     print("Sum in each row & each column = %d" % int(n * (n * n + 1) / 2))
# ```

# **Explanation:**
# - This function displays the magic square matrix `M` in a formatted manner.
# - It prints each element of the matrix and calculates and prints the sum of each row and each column.
# - The sum of each row and each column in a magic square should be the same.

# ### `main():`
# ```python
# def main():
#     while True:
#         print("\t\t\t1: Find Magic Square")
#         print("\t\t\t2: Exit")
#         ch = int(input("Enter your choice : "))
#         if ch == 2:
#             print("End of Program")
#             break
#         elif ch == 1:
#             M = []
#             n = int(input("\nEnter the order of the Square Matrix (n,n) : "))
#             construct_magic_square_matrix(M, n)
#             display_matrix(M, n)
#         else:
#             print("Wrong choice entered !! Try again")
# ```

# **Explanation:**
# - This is the main function where the user interacts with the program.
# - It provides a menu with two options: finding a magic square or exiting the program.
# - If the user chooses option 2, it prints a message and breaks out of the loop, ending the program.
# - If the user chooses option 1, it initializes an empty matrix `M`, prompts the user for the order of the matrix, constructs the magic square using `construct_magic_square_matrix`, and displays the matrix using `display_matrix`.
# - If an invalid choice is entered, it prints a message prompting the user to try again.

# ### Magic Square Matrix:
# A magic square is a square matrix where the sum of every row, column, and both main diagonals is the same. The sum is known as the "magic constant." In the context of this program, the magic square is constructed using the Siamese method, where numbers are placed in a specific order to create the magic square property. The program then displays the constructed magic square and the sum of each row and column.