public class Bubble {

    public static void bubbleSort(int[] arr) {
        int n = arr.length;
        int swapped;

        for (int i = 0; i < n - 1; i++) {
            swapped = 0;
            for (int j = 0; j < n - 1 - i; j++) {
                if (arr[j] > arr[j + 1]) {
                    // Swap without using a temporary variable
                    arr[j] = arr[j] + arr[j + 1];
                    arr[j + 1] = arr[j] - arr[j + 1];
                    arr[j] = arr[j] - arr[j + 1];
                    swapped = 1;
                }
            }
            if (swapped == 0) {
                break; // If no elements were swapped, the array is already sorted
            }
        }
    }

    public static void displayArray(int[] arr) {
        for (int value : arr) {
            System.out.print(value + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int[] arr = {91, 32, 86, 37, 12};
        System.out.println("Unsorted Array");
        displayArray(arr);

        bubbleSort(arr);
        System.out.println("Sorted Array");
        displayArray(arr);
    }
}
