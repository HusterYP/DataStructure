public class SelectSort {
    public static void sort(int[] noSort) {
        if (noSort == null || noSort.length <= 0)
            return;
        int N = noSort.length;
        for (int i = 0; i < N; i++) {
            int min = i;
            for (int j = i + 1; j < N; j++) {
                if (!Utils.less(noSort[min], noSort[j]))
                    min = j;
            }
            Utils.exch(noSort, i, min);
        }
    }

    public static void main(String[] args) {
        int[] noSort = Utils.getRandomElement(Utils.NO_SORT);
        sort(noSort);
        Utils.writeSortResult(noSort);
        Utils.printSortResult(null);
    }
}
