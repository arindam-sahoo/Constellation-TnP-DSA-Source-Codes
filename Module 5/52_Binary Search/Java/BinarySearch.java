public class BinarySearch {

    public static int binarySearch(int[] arr, int target) {
        int left = 0, right = arr.length - 1;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            
            if (arr[mid] == target)
                return mid;
            else if (arr[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        
        return -1;
    }

    public static void main(String[] args) {
        int[] arr = {24, 27, 32, 45, 51, 52, 54, 67, 78, 98};
        int target = 54;

        int index = binarySearch(arr, target);

        if (index > -1)
            System.out.println("The target value has been found at index " + index + ".");
        else
            System.out.println("The target value has not been found.");
    }
}
