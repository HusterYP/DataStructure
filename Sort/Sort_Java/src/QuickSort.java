public class QuickSort {

    public static void sort(int[] noSort) {
        if (noSort == null || noSort.length <= 0)
            return;
        sort(noSort, 0, noSort.length - 1);
    }

    private static void sort(int[] noSort, int low, int high) {
        if (high <= low)
            return;
        int j = partition(noSort, low, high);
        sort(noSort, low, j - 1);
        sort(noSort, j + 1, high);
    }

    private static int partition(int[] noSort, int low, int high) {
        int i = low;
        int j = high + 1;
        int temp = noSort[low];
        while (true) {
            while (Utils.less(noSort[++i], temp))
                if (i == high)
                    break;
            while (Utils.less(temp, noSort[--j]))
                if (j == low)
                    break;
            if (i >= j)
                break;
            Utils.exch(noSort, i, j);
        }
        Utils.exch(noSort, low, j);
        return j;
    }

    // 三向切分, 避免重复值计入递归
    public static void sort3Way(int[] noSort, int low, int high) {
        if (high <= low)
            return;
        int lt = low;
        int i = low + 1;
        int gt = high;
        int temp = noSort[low];
        while (i < gt) { // 找出重复元素
            if (noSort[i] < temp)
                Utils.exch(noSort, lt++, i++);
            else if (noSort[i] > temp)
                Utils.exch(noSort, i, gt--);
            else
                i++;
        }
        sort3Way(noSort, low, lt - 1);
        sort3Way(noSort, gt + 1, high);
    }

    public static void main(String[] args) {
        Utils.createRandomElement();
        int[] noSort = Utils.getRandomElement(Utils.NO_SORT);
//        sort(noSort);
        sort3Way(noSort, 0, noSort.length - 1);
        Utils.writeSortResult(noSort);
        Utils.printSortResult(null);
    }
}
