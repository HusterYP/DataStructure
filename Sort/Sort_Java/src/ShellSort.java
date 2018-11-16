public class ShellSort {
    public static void sort(int[] noSort) {
        if (noSort == null || noSort.length <= 0)
            return;
        int N = noSort.length;
        int h = 1;
        while (h < N / 3)
            h = h * 3 + 1;
        while (h >= 1) {
            for (int i = h; i < N; i++) {
                for (int j = i; j >= h && Utils.less(noSort[j], noSort[j - h]); j -= h)
                    Utils.exch(noSort, j, j - h);
            }
            h = h / 3;
        }
    }

    public static void main(String[] args) {
        Utils.createRandomElement();
        int[] noSort = Utils.getRandomElement(Utils.NO_SORT);
        sort(noSort);
        Utils.writeSortResult(noSort);
        Utils.printSortResult(null);
    }
}
