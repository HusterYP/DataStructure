public class BubbleSort {
    public static void sort(int[] noSort) {
        if (noSort == null || noSort.length <= 0)
            return;
        int N = noSort.length;
        boolean isChange = true;
        for (int i = N; i > 0 && isChange; i--) {
            isChange = false;
            for (int j = 0; j < i - 1; j++) {
                if (Utils.less(noSort[j + 1], noSort[j])) {
                    Utils.exch(noSort, j, j + 1);
                    isChange = true;
                }
            }
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
