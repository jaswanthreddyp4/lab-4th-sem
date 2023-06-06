import java.util.*;

public class SelectionSort {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] a = { 12, 16, 35, 9, 10, 56 };
        int n = a.length;
        for (int i = 0; i < n - 2; i++) {
            int mini = i;
            for (int j = i; j < n - 1; j++) {
                if (a[j] < a[mini])
                    mini = j;
            }
            int temp = a[i];
            a[i] = a[mini];
            a[mini] = temp;
        }
        for (int i = 0; i < a.length; i++) {
            System.out.print(a[i] + " ");
        }
    }
}
