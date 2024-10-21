public class LinearSearch {
    public static int linearSearch(int arr[], int target) {
        for(int i = 0; i < arr.length; i++) {
            if (arr[i] == target) {
                return i;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        int arr[] = {27, 45, 32, 98, 78, 67, 54, 24, 51, 52};
        int target = 54;

        int index = linearSearch(arr, target);

        if (index > -1)
            System.out.println("The target value has been found at index " + index + ".");
        else
            System.out.println("The target value has not been found.");
    }
}
