public class Selection {

    public static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void selectionSort(int[] arr) {
        int n = arr.length;
        int min;

        for(int i = 0; i < n; i++) {
            min = i;

            for(int j = i + 1; j < n; j++) {
                if(arr[j] < arr[min]) {
                    min = j;
                }
            }
            swap(arr, min, i);
        }
    }

    public static void displayArray(int[] arr) {
        for(int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
    }

    public static void main(String[] args) {
        int[] arr = {91, 32, 86, 37, 12};

        System.out.println("Unsorted Array");
        displayArray(arr);
        System.out.println();

        selectionSort(arr);
        System.out.println("Sorted Array");
        displayArray(arr);
    }
}
