import random

def creation(n:int) -> list:
    """
    Returns a list of n random integers between 0 and 100.
    """
    return [random.randint(0, 100) for _ in range(n)]

def main():
    """
    In python, Arrays are implemented as lists. They are dynamic in size and can hold elements of different types.
    Here are some common operations on arrays (lists) in Python:
    1. creation: [], list(), copy(), list comprehension
    2. adding elements: append(), extend(), insert()
    3. removing elements: remove(), pop(), clear()
    4. accessing elements: indexing, slicing
    5. sorting: sort(), sorted()
    6. length: len(), count()
    7. iteration: for loop, while loop
    """

    arr = creation(10)
    print(f'Created array: {arr}')

    # Adding elements
    arr.append(101)
    print(f'Array after adding element: {arr}')

    arr.extend([102, 103])
    print(f'Array after extending: {arr}')

    arr.insert(0, 99)
    print(f'Array after inserting at index 0: {arr}')

    # Removing elements
    arr.remove(99)
    print(f'Array after removing element 99: {arr}')    

    popped_element = arr.pop()
    print(f'Popped element: {popped_element}')

    arr2 = arr.copy()
    arr2.clear()
    print(f'Array after clearing: {arr2}')

    # Accessing elements
    print(f'Element at index 0: {arr[0]:<10}')
    print(f'Slice of array from index 1 to 3: {arr[1:4]}')

    # Sorting
    print(f'Array before sorting: {arr}')
    arr.sort()
    print(f'Array after sorting: {arr}')

    print(f'Array sorted using sorted(): {sorted(arr)}')

    # Length
    print(f'Length of array: {len(arr)}')
    print(f'Count of element 101 in array: {arr.count(101)}')


    # Iteration
    print('Iterating through array:')
    for a in arr:
        print(a, end=' ')
    
    print()

    print('Iterating through array using while loop:')
    i = 0
    while i < len(arr):
        print(arr[i], end=' ')
        i += 1
    print()


if __name__ == '__main__':
    main()