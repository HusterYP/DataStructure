public class InsertSort {
    public static void sort(int[] noSort) {
        if (noSort == null || noSort.length <= 0)
            return;
        int N = noSort.length;
        for (int i = 1; i < N; i++) {
            int index = i;
            while (index > 0 && Utils.less(noSort[index], noSort[index - 1])) {
                Utils.exch(noSort, index, index - 1);
                index--;
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
