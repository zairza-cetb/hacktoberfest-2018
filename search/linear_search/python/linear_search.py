print("PROGRAM FOR LINEAR SEARCH")

array = [44,1,55,23,54,6546,234,987]  
found = 0

while True: 

    query = int(input("Enter element to search in array:"))

    for i in range(len(array)):
        if array[i]==query:
            print("Element found at index {}".format(i))
            found = 1

    if found==0:
        print("Element not in array")