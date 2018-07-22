import source.*;

import java.awt.*;

public class PercolationStats {

    private double mean = 0;
    private double stddev = 0;
    private double halfInterval = 0;

    // perform trials independent experiments on an n-by-n grid
    public PercolationStats(int n, int trials) {
        double[] means = new double[trials];
        for (int i = 0; i < trials; i++) {
            Stopwatch stopwatch = new Stopwatch();
            Percolation percolation = new Percolation(n);
            while (!percolation.percolates()) {
                int row = StdRandom.uniform(n) + 1;
                int col = StdRandom.uniform(n) + 1;
                StdOut.println(row + "==" + col);
                percolation.open(row, col);
                draw(percolation, n);
            }
            means[i] = percolation.numberOfOpenSites() / n * n;
            System.out.println(i + " : " + stopwatch.elapsedTime());
        }
        mean = StdStats.mean(means);
        stddev = StdStats.stddev(means);
        halfInterval = 1.96 * stddev / Math.sqrt(trials);
    }

    // sample mean of percolation threshold
    public double mean() {
        return mean;
    }

    // sample standard deviation of percolation threshold
    public double stddev() {
        return stddev;
    }

    // low  endpoint of 95% confidence interval
    public double confidenceLo() {
        return mean - halfInterval;
    }

    // high endpoint of 95% confidence interval
    public double confidenceHi() {
        return mean + halfInterval;
    }

    // draw n-by-n percolation system
    private void draw(Percolation perc, int n) {
        StdDraw.clear();
        StdDraw.setPenColor(StdDraw.BLACK);
        StdDraw.setXscale(-0.05 * n, 1.05 * n);
        StdDraw.setYscale(-0.05 * n, 1.05 * n);   // leave a border to write text
        StdDraw.filledSquare(n / 2.0, n / 2.0, n / 2.0);

        // draw n-by-n grid
        int opened = 0;
        for (int row = 1; row <= n; row++) {
            for (int col = 1; col <= n; col++) {
                if (perc.isFull(row, col)) {
                    StdDraw.setPenColor(StdDraw.BOOK_LIGHT_BLUE);
                    opened++;
                } else if (perc.isOpen(row, col)) {
                    StdDraw.setPenColor(StdDraw.WHITE);
                    opened++;
                } else
                    StdDraw.setPenColor(StdDraw.BLACK);
                StdDraw.filledSquare(col - 0.5, n - row + 0.5, 0.45);
            }
        }

        // write status text
        StdDraw.setFont(new Font("SansSerif", Font.PLAIN, 12));
        StdDraw.setPenColor(StdDraw.BLACK);
        StdDraw.text(0.25 * n, -0.025 * n, opened + " open sites");
        if (perc.percolates()) StdDraw.text(0.75 * n, -0.025 * n, "percolates");
        else StdDraw.text(0.75 * n, -0.025 * n, "does not percolate");

    }

    // test client (described below)
    public static void main(String[] args) {
        PercolationStats percolationStats = new PercolationStats(20, 100);
        System.out.println("mean: " + percolationStats.mean());
        System.out.println("stddev: " + percolationStats.stddev());
        System.out.println("low endpoint of 95% confidence interval: " + percolationStats.confidenceLo());
        System.out.println("high endpoint of 95% confidence interval: " + percolationStats.confidenceHi());
    }
}


