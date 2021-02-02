'''
Split an array into two with an equal sum of all the elements
1, 3, 2, 1, 2, 1

Output:
array1 = 1, 3, 1
array2 = 2, 2, 1
'''

arr = [1, 3, 2, 1, 2, 1]
print("Array:", end=" ")
for i in range(0, len(arr)):
    print(arr[i], end=" ")

sum = 0
for i in range(0, len(arr)):
    sum += arr[i]
sum /= 2
print("\nSum for each array:", sum)

arr1 = []
arr2 = []
sum1 = 0
sum2 = 0
a = 0
b = 0
for i in range(0, len(arr)):
    if((sum1 + arr[i]) <= sum):
        sum1 += arr[i]
        arr1.append(arr[i])
        a += 1
    elif((sum2 + arr[i]) <= sum):
        sum2 += arr[i]
        arr2.append(arr[i])
        b += 1

for i in range(0, len(arr1)):
    print(arr1[i], end=" ")
print()
for i in range(0, len(arr2)):
    print(arr2[i], end=" ")