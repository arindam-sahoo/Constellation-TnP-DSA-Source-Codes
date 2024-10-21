public class Insertion {
    public static void InsertionSort(int arr[]) {
        int size = arr.length;
        for (int i = 1; i < size; i++) {
            int key = arr[i];
            int j = i - 1;

            // Shifting the elements of arr[0 till i-1], that are > key to the position ahead of their current position.
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }

            arr[j + 1] = key;
        }
    }

    public static void dispArr(int arr[]) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int arr[] = {37, 86, 91, 12, 32};
        
        System.out.print("Array Before Insertion Sort: ");
        dispArr(arr);

        InsertionSort(arr);
        
        System.out.print("Array After Insertion Sort: ");
        dispArr(arr);
    }
}
