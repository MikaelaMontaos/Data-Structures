'''
Display the next bigger value for each element in a stack
stack = 5 3 2 10 6 8 1 4 12 7 4
'''

stack = []

stack.append(5)
stack.append(3)
stack.append(2)
stack.append(10)
stack.append(6)
stack.append(8)
stack.append(1)
stack.append(4)
stack.append(12)
stack.append(7)
stack.append(4)
print(stack)

length = len(stack)
for i in range(length):
    j = i + 1
    prev = stack[i]
    if(j == length):
        print(prev, "-> None")
        break
    cur = stack[j]
    
    if(prev < cur):
        print(prev, "->", cur)
    else:
        while(prev > cur and j != length):
            cur = stack[j]
            j = j + 1
        if(prev < cur):
            print(prev, "->", cur)
        else:
            print(prev, "-> None")
        