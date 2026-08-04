# Factorial of N numbers

def solve(num):
    if num == 0:
        return 0
    if num == 1:
        return 1
    
    return num * solve(num  - 1)

ans = solve(4)

print(ans)
