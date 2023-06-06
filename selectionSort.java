import java.util.*;

class MergeSort {

    public int[] sortArray(int[] nums) {
        mergeSort(nums, 0, nums.length - 1);
        return nums;

    }

    void merge(int[] arr, int low, int mid, int high) {
        int[] temp = new int[high - low + 1];
        int left = low;
        int right = mid + 1;
        int k = 0;
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp[k] = arr[left];
                left++;
                k++;
            } else {
                temp[k] = arr[right];
                right++;
                k++;
            }
        }
        while (left <= mid) {
            temp[k] = arr[left];
            left++;
            k++;
        }
        while (right <= high) {
            temp[k] = arr[right];
            right++;
            k++;
        }
        for (int i = 0; i < temp.length; i++) {
            arr[i + low] = temp[i];
        }
    }

    void mergeSort(int[] arr, int low, int high) {
        if (low >= high)
            return;
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

public class Demo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        MergeSort ms = new MergeSort();
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        int[] res = new int[n];
        res = ms.sortArray(arr);
        // ms.mergeSort(arr, 0, n - 1);
        // System.out.println("after sorting");
        for (int i = 0; i < n; i++) {
            System.out.print(res[i] + " ");
        }
    }
}
