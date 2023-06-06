import java.util.*;

class Demo {
    static void bubbleSort(int[] a, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (a[j] > a[j + 1]) {
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
    }

    static void bubbleSort2(int[] a, int n) {
        for (int i = n - 1; i > 1; i--) {
            for (int j = 0; j < i; j++) {
                if (a[j] > a[j + 1]) {
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
    }

    static void insertionSort(int[] a, int n) {
        for (int i = 0; i < n; i++) {// for selecting each element and comparing with left conti array
            int j = i;
            while (j > 0 && a[j - 1] > a[j]) {
                int temp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = temp;
                j--;
            }
        }
    }
}

public class BubbleSort {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("enter size of array");
        int n = sc.nextInt();
        System.out.println("enter array elements");
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        Demo.bubbleSort(a, n);
        for (int i = 0; i < n; i++) {
            System.out.print(a[i] + " ");
        }
        System.out.println();
        Demo.bubbleSort2(a, n);
        for (int i = 0; i < n; i++) {
            System.out.print(a[i] + " ");
        }
        System.out.println();
        Demo.insertionSort(a, n);
        for (int i = 0; i < n; i++) {
            System.out.print(a[i] + " ");
        }
    }
}
