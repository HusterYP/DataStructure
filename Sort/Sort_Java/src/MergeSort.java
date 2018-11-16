public class MergeSort {
    private static int[] aux; // 辅助数组

    public static void sort(int[] noSort) {
        if (noSort == null || noSort.length <= 0)
            return;
        aux = new int[noSort.length];
        sort(noSort, 0, noSort.length - 1);
    }

    public static void merge(int[] noSort, int low, int mid, int high) {
        int i = low;
        int j = mid + 1;
        for (int k = low; k <= high; k++) {
            aux[k] = noSort[k];
        }

        for (int k = low; k <= high; k++) {
            if (i > mid)
                noSort[k] = aux[j++]; // 如果左边用完
            else if (j > high)
                noSort[k] = aux[i++]; // 如果右边用完
            else if (Utils.less(aux[j], aux[i]))
                noSort[k] = aux[j++];
            else
                noSort[k] = aux[i++];
        }
    }

    // 自顶向下归并
    public static void sort(int[] noSort, int low, int high) {
        if (high <= low)
            return;
        int mid = low + (high - low) / 2;
        sort(noSort, low, mid); // 将左半边数组排序
        sort(noSort, mid + 1, high); // 将右半边数组排序
        merge(noSort, low, mid, high); // 将数组归并
    }

    // 自底向上归并
    public static void sortBU(int[] noSort) {
        int N = noSort.length;
        aux = new int[N];
        for (int sz = 1; sz < N; sz = sz + sz) {
            for (int low = 0; low < N - sz; low += sz + sz)
                merge(noSort, low, low + sz - 1, Math.min(low + sz + sz - 1, N - 1));
        }
    }

    public static void main(String[] args) {
        Utils.createRandomElement();
        int[] noSort = Utils.getRandomElement(Utils.NO_SORT);
        sortBU(noSort);
        Utils.writeSortResult(noSort);
        Utils.printSortResult(null);
    }
}
