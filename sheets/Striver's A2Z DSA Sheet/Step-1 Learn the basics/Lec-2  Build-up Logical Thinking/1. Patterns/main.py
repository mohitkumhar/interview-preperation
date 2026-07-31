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
