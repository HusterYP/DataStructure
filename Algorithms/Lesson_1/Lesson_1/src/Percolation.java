import source.WeightedQuickUnionUF;

/**
 * 对Percolation进行建模
 * row, col都是1 -- n
 * 需要使用WeightedUnionUF, 所以需要将二维映射到一维
 **/
public class Percolation {

    private WeightedQuickUnionUF uf;
    private WeightedQuickUnionUF uf_backwash;
    private boolean isOpen[];
    private int sizeOpen = 0;
    private int n;

    /**
     * create n-by-n grid, with all sites blocked
     *
     * @param n the row and col
     */
    public Percolation(int n) {
        if (n <= 0) {
            throw new IllegalArgumentException("n must be more than 0");
        }
        this.n = n;
        isOpen = new boolean[n * n + 2];
        uf = new WeightedQuickUnionUF(n * n + 2);
        uf_backwash = new WeightedQuickUnionUF(n * n + 1);
        for (int i = 1; i <= n; i++) {
            isOpen[i] = false;
        }
        isOpen[0] = true;
        isOpen[n + 1] = true;
    }

    // open site (row, col) if it is not open already

    /**
     * 将arrays状态置为OPEN的同时,还需要将WeightedQuickUnionUF对应映射为Union
     *
     * @param row 1 -- n
     * @param col 1 -- n
     */
    public void open(int row, int col) {
        exceptionDetc(row, col);
        isOpen[xyTo1D(row, col)] = true;
        if (isFull(row, col))
            return;
        if (row == 1) {
            uf.union(0, xyTo1D(row, col));
            uf_backwash.union(0, xyTo1D(row, col));
        } else if (isOpen[xyTo1D(row - 1, col)]) {
            uf.union(xyTo1D(row, col), xyTo1D(row - 1, col));
            uf_backwash.union(xyTo1D(row, col), xyTo1D(row - 1, col));
        }

        if (row == n) {
            uf.union(n * n + 1, xyTo1D(row, col));
        } else if (isOpen[xyTo1D(row + 1, col)]) {
            uf.union(xyTo1D(row, col), xyTo1D(row + 1, col));
            uf_backwash.union(xyTo1D(row, col), xyTo1D(row + 1, col));
        }

        if (col != 1 && isOpen[xyTo1D(row, col - 1)]) {
            uf.union(xyTo1D(row, col), xyTo1D(row, col - 1));
            uf_backwash.union(xyTo1D(row, col), xyTo1D(row, col - 1));
        }

        if (col != n && isOpen[xyTo1D(row, col + 1)]) {
            uf.union(xyTo1D(row, col), xyTo1D(row, col + 1));
            uf_backwash.union(xyTo1D(row, col), xyTo1D(row, col + 1));
        }
    }

    // is site (row, col) open?
    public boolean isOpen(int row, int col) {
        exceptionDetc(row, col);
        return isOpen[xyTo1D(row, col)];
    }

    // is site (row, col) full?
    public boolean isFull(int row, int col) {
        exceptionDetc(row, col);
        return uf_backwash.connected(0, xyTo1D(row, col));
    }

    // number of open sites
    public int numberOfOpenSites() {
        return sizeOpen;
    }

    // does the system percolate?
    public boolean percolates() {
        return uf.connected(0, n * n + 1);
    }

    /**
     * translate 2D to 1D
     *
     * @param x 1 -- n
     * @param y 1 -- n
     */
    private int xyTo1D(int x, int y) {
        return (x - 1) * n + y;
    }

    private void exceptionDetc(int row, int col) {
        if (row < 0 || row > n || col < 0 || row > n) {
            throw new IllegalArgumentException("row or col is illegal");
        }
    }

    // test client (optional)
    public static void main(String[] args) {
    }
}
