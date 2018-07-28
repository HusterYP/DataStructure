import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Iterator;
import java.util.Scanner;

public class Permutation {
    public static void main(String[] args) throws FileNotFoundException {
//        int count = Integer.parseInt(args[0]);
        RandomizedQueue<String> randomizedQueue = new RandomizedQueue();
        FileInputStream inputStream = new FileInputStream(args[0]);
        Scanner scanner = new Scanner(inputStream);
        while (scanner.hasNext()) {
            randomizedQueue.enqueue(scanner.next());
        }
        Iterator it = randomizedQueue.iterator();
        while (it.hasNext()) {
            StdOut.print(it.next() + "  ");
        }
    }
}
