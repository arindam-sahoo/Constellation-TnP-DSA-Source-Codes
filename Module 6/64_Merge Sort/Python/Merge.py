def Merge(arr, left, mid, right):
    n1 = mid - left + 1
    n2 = right - mid

    # Creating temporary arrays
    L = arr[left:left + n1]
    R = arr[mid + 1:mid + 1 + n2]

    # Merging the temp arrays back into arr
    i, j, k = 0, 0, left
    while i < n1 and j < n2:
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1

    # Copying the remaining elements of L[]
    while i < n1:
        arr[k] = L[i]
        i += 1
        k += 1

    # Copying the remaining elements of R[]
    while j < n2:
        arr[k] = R[j]
        j += 1
        k += 1

def MergeSort(arr, left, right):
    if left < right:
        mid = left + (right - left) // 2

        # Sorting the first and the second halves recursively
        MergeSort(arr, left, mid)
        MergeSort(arr, mid + 1, right)

        # Merging the two sorted halves
        Merge(arr, left, mid, right)

def dispArr(arr):
    for element in arr:
        print(element, end=" ")
    print()

def main():
    arr = [37, 86, 91, 12, 32]
    
    print("Array Before Merge Sort:", end=" ")
    dispArr(arr)

    MergeSort(arr, 0, len(arr) - 1)
    
    print("Array After Merge Sort:", end=" ")
    dispArr(arr)

if __name__ == "__main__":
    main()
