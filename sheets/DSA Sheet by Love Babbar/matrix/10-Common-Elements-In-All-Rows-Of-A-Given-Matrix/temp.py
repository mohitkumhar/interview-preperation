hate1 = "I hate it"
hate2 = "I hate that"

love1 = "I love it"
love2 = "I love that"

n = int(input())

feelings = []

for i in range(1, n + 1):
    if i % 2 == 1:
        feelings.append("I hate")
    else:
        feelings.append("I love")
    
ans = " that ".join(feelings) + " it"

print(ans)
    


