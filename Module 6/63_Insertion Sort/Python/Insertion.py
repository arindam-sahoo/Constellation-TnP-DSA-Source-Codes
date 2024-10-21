def InsertionSort(arr):
    size = len(arr)
    for i in range(1, size):
        key = arr[i]
        j = i - 1

        # Shifting the elements of arr[0 till i-1], that are > key to the position ahead of their current position.
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1

        arr[j + 1] = key

def dispArr(arr):
    for element in arr:
        print(element, end=" ")
    print()

def main():
    arr = [37, 86, 91, 12, 32]
    
    print("Array Before Insertion Sort:", end=" ")
    dispArr(arr)

    InsertionSort(arr)
    
    print("Array After Insertion Sort:", end=" ")
    dispArr(arr)

if __name__ == "__main__":
    main()
