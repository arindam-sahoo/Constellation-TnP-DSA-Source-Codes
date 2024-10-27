public class CoinChange {
    public static void coinChange(int[] deno, int amt) {
        int[] nums = new int[deno.length];
        for (int i = deno.length - 1; i >= 0; i--) {
            while (amt >= deno[i]) {
                amt -= deno[i];
                nums[i]++;
            }
        }
        System.out.println("The Denominations are:");
        for (int i = deno.length - 1; i >= 0; i--) {
            if (nums[i] > 0) {
                System.out.println(nums[i] + " x " + deno[i]);
            }
        }
    }

    public static void main(String[] args) {
        int[] deno = {1, 2, 5, 10, 20, 50, 100, 200, 500};
        int amt = 2898;

        coinChange(deno, amt);
    }
}
