public class example2 {

    public static void WholeNos(int n) {
        if (n <= 5) {
            WholeNos(n + 1);
            System.out.print(n + " ");
        }
    }

    public static void main(String[] args) {
        WholeNos(1);
    }
}
