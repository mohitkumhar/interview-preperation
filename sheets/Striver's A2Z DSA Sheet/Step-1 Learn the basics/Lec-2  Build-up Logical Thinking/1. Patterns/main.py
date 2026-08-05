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

