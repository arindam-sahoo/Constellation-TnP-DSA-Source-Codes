def binary_search(arr, target):
    left, right = 0, len(arr) - 1
    
    while left <= right:
        mid = (left + right) // 2
        
        if arr[mid] == target:
            return mid
        elif arr[mid] > target:
            right = mid - 1
        else:
            left = mid + 1
    
    return -1

if __name__ == "__main__":
    arr = [24, 27, 32, 45, 51, 52, 54, 67, 78, 98]
    target = 54

    index = binary_search(arr, target)

    if index > -1:
        print(f"The target value has been found at index {index}.")
    else:
        print("The target value has not been found.")
