# Find the maximum total for the equation u - v + w - x 

# Get elements
n = int(input("How many elements in an array: "))
arr = []
for i in range(0, n):
    num = input("Enter a number: ")
    arr.append(num)

# Convert to from string to integer
arr = [int(i) for i in arr]
print(arr)

# Find 2 largest
max1 = max(arr)
max2 = 0
for i in range(0, n):
    if (max2 < arr[i]) and max1 != arr[i]:
        max2 = arr[i]

# Find 2 smallest
min1 = min(arr)
min2 = max1
for i in range(0, n):
    if (min2 > arr[i]) and min1 != arr[i]:
        min2 = arr[i]

# Equation
total = max1 - min1 + max2 - min2
print(max1, " - ", min1, " + ", max2, " - ", min2, " = ", total)