# searching an element X in a array(sorted) using Binary search
# Time Complexity = O(log n) | Space Complexity = O(log n)


def binarySearch(arr, target):
    start = 0
    end = len(arr) - 1
    while start <= end:
        #finding the middle element of arr
        mid = start + (end-start)//2
        if arr[mid] == target:
            return mid
        
        #target is present at left side of mid element
        if arr[mid] > target:
            end = mid - 1
        #target is present at right side of mid element
        else:
            start = mid + 1
    #if target is not present in arr
    return -1


# driver code
arr = [10, 20, 35, 60, 70, 110, 120, 140]
target = 35

result = binarySearch(arr,target)  # our defined function is stored in var result

if result == -1:
    print("Element doesn't exists !!")
else:
    print("Element is at index", result)