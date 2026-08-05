"""
* * * * *
* * * * *
* * * * *
* * * * *
* * * * *
"""

n = 5

for i in range(n):
    for j in range(n):
        print("*", end=" ")
    print()
    
    
print()
print()
print()

"""
*
* *
* * *
* * * *
* * * * *
"""
n = 5

for i in range(n):
    for j in range(i + 1):
        print("*", end=" ")
    print()
        
print()
print()
print()


"""
1
1 2
1 2 3
1 2 3 4
1 2 3 4 5
"""

n = 5

for i in range(n):
    val = 1
    for j in range(i + 1):
        print(val, end = " ")
        val+=1
    print()
        

print()
print()
print()



"""
1
2 2
3 3 3
4 4 4 4
5 5 5 5 5
"""

n = 5

val = 0
for i in range(n):
    val += 1
    for j in range(i + 1):
        print(val, end=" ")
    print()


print()
print()
print()



"""
* * * * *
* * * *
* * *
* *
*
"""

n = 5

for i in range(n):
    for j in range(n - i):
        print("*", end=" ")
    print()

print()
print()
print()


"""
1 2 3 4 5
1 2 3 4
1 2 3
1 2
1
"""

n = 5

for i in range(n):
    val = 1
    for j in range(n - i):
        print(val, end=" ")
        val += 1
    print()

print()
print()
print()


"""
        *
      * * *
    * * * * *
  * * * * * * *
* * * * * * * * *
"""
n = 5
for i in range(n):
    for j in range(n - i):
        print("", end=" ")

    for k in range(i + 1):
        print("*", end=" ")
    print()


print()
print()
print()


"""
* * * * * * * * *
  * * * * * * *
    * * * * *
      * * *
        *
"""

n = 5
stars = 9

for i in range(n):
    for j in range(i):
        print("", end="  ")
     
    for k in range(stars):
        print("*", end=" ")
    print()
    stars -= 2


print()
print()
print()


"""
        *
      * * *
    * * * * *
  * * * * * * *
* * * * * * * * *
* * * * * * * * *
  * * * * * * *
    * * * * *
      * * *
        *
"""
n = 5
for i in range(n):
    for j in range(n - i):
        print("", end="  ")

    for k in range(i + 1):
        print("*", end="  ")
    print()

stars = 9

for i in range(n):
    for j in range(i):
        print("", end="  ")
     
    for k in range(stars):
        print("*", end=" ")
    print()
    stars -= 2
    
print()
print()
print()



"""
*
* *
* * *
* * * *
* * * * *
* * * *
* * *
* *
*
"""


n = 5

for i in range(n - 1):
    for j in range(i + 1):
        print("*", end=" ")
    print()
    
for i in range(n):
    for j in range(n - i):
        print("*", end=" ")
    print()


print()
print()
print()


"""
1
0 1
1 0 1
0 1 0 1
1 0 1 0 1
"""

n = 5
flag = 0

for i in range(n):
    flag = 0 if flag == 1 else 1
    temp = flag
    for j in range(i + 1):
        print(temp, end=" ")
        temp = 0 if temp == 1 else 1
    print()

print()
print()
print()


"""
1             1
1 2         2 1
1 2 3     3 2 1
1 2 3 4 4 3 2 1
"""

n = 4
spaces = 6

for i in range(n):
    num = 1
    for j in range(i + 1):
        print(num, end=" ")
        num += 1
    
    for k in range(spaces):
        print(" ", end=" ")
    spaces -= 2
    
    num = i + 1
    for l in range(i + 1):
        print(num, end=" ")
        num -= 1
    
    
    print()

print()
print()
print()


"""
1
2  3
4  5  6
7  8  9  10
11 12 13 14 15
"""

n = 5
num = 1

for i in range(n):
    for j in range(i + 1):
        print(num, end=" ")
        num += 1
    print()

print()
print()
print()


"""
A
A B
A B C
A B C D
A B C D E
"""

n = 5

for i in range(n):
    char = 65
    for j in range(i + 1):
        print(chr(char), end=" ")
        char += 1
    print()
    
print()
print()
print()


"""
A B C D E
A B C D
A B C
A B
A
"""

n = 5

for i in range(n, -1, -1):
    char = 65
    for j in range(i):
        print(chr(char), end = " ")
        char += 1
    print()
    
print()
print()
print()


"""
A
B B
C C C
D D D D
E E E E E
"""

n = 5
char = 65

for i in range(n):
    for j in range(i + 1):
        print(chr(char), end=" ")
    char += 1
    print()

    
print()
print()
print()
    

"""
      A
    A B A
  A B C B A
A B C D C B A
"""

n = 4

for i in range(n):
    char = 65
    
    for j in range(n - i):
        print("", end="  ")
    
    for k in range(i + 1):
        print(chr(char), end=" ")
        char += 1
        
    char -= 2
    for l in range(i):
        print(chr(char), end=" ")
        char -= 1
        
    print()
    
    
print()
print()
print()
    
    