public class IndirectRecursion {

    static void func2(int n) {
        if (n <= 5) {
            System.out.print(n + " ");
            func1(n + 1);
        }
    }

    static void func1(int n) {
        if (n <= 5) {
            System.out.print(n + " ");
            func2(n + 1);
        }
    }

    public static void main(String[] args) {
        func1(1);
    }
}
