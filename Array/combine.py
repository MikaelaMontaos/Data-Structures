# Create a new list by combining two lists and removing common elements

lst1 = []
how_many1 = int(input("How many elements in the first array? "))
for i in range(how_many1):
    lst1.append(input("Enter a letter: "))
print(lst1)

lst2 = []
how_many2 = int(input("How many elements in the second array? "))
for i in range(how_many2):
    lst2.append(input("Enter a letter: "))
print(lst2)

combine = [i for i in lst1 if i not in lst2] + [j for j in lst2 if j not in lst1]
print(combine)