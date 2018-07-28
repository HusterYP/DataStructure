import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;

import java.util.Iterator;
import java.util.NoSuchElementException;

/**
 * 随机队列
 * 边界条件
 * 1. Throw a java.lang.IllegalArgumentException if the client calls enqueue() with a null argument.
 * 2. Throw a java.util.NoSuchElementException if the client calls either sample() or dequeue() when the randomized queue is empty.
 * 3. Throw a java.util.NoSuchElementException if the client calls the next() method in the iterator when there are no more items to return.
 * 4. Throw a java.lang.UnsupportedOperationException if the client calls the remove() method in the iterator.
 */

public class RandomizedQueue<Item> implements Iterable<Item> {

    private Item[] datas;
    private int n;
    private final int INCREAMENT = 10;

    // construct an empty randomized queue
    public RandomizedQueue() {
        datas = (Item[]) new Object[10];
        n = 0;
    }

    // is the randomized queue empty?
    public boolean isEmpty() {
        return n == 0;
    }

    // return the number of items on the randomized queue
    public int size() {
        return n;
    }

    // add the item
    public void enqueue(Item item) {
        if (item == null) {
            throw new IllegalArgumentException("The argument can not be null");
        }
        if (n >= datas.length) {
            resizing();
        }
        n++;
        datas[n-1] = item;
    }

    // remove and return a random item
    public Item dequeue() {
        if (isEmpty()) {
            throw new NoSuchElementException("No such element");
        }
        int index = StdRandom.uniform(0, n);
        Item curItem = datas[index];
        n--;
        for (int i = index; i < n-1; i++) {
            datas[i] = datas[i+1];
        }
        return curItem;
    }

    // return a random item (but do not remove it)
    public Item sample() {
        if (isEmpty()) {
            throw new NoSuchElementException("No such element");
        }
        return datas[StdRandom.uniform(0, n)];
    }

    private void resizing() {
        Item[] temp = (Item[]) new Object[datas.length + INCREAMENT];
        for (int i = 0; i < datas.length; i++) {
            temp[i] = datas[i];
        }
        datas = temp;
    }

    // return an independent iterator over items in random order
    public Iterator<Item> iterator() {
        return new RadomIterator();
    }

    private class RadomIterator implements Iterator<Item> {

        private int index[] = new int[n];
        private int curIndex = 0;

        // 使用洗牌算法来构造随机序列
        public RadomIterator() {
            for (int i = 0; i < n; i++)
                index[i] = i;
            for (int i = 0; i < n; i++) {
                int radomIndex = StdRandom.uniform(0, i+1);
                int temp = index[i];
                index[i] = index[radomIndex];
                index[radomIndex] = temp;
            }
        }

        @Override
        public boolean hasNext() {
            return curIndex != n;
        }

        @Override
        public Item next() {
            Item item = datas[index[curIndex]];
            curIndex++;
            return item;
        }

        @Override
        public void remove() {
            throw new UnsupportedOperationException("Can not remove item in iterator");
        }
    }

    // unit testing (optional)
    public static void main(String[] args) {
        RandomizedQueue randomizedQueue = new RandomizedQueue();
        for (int i = 0; i < 20; i++) {
            randomizedQueue.enqueue(StdRandom.uniform(0, 100));
        }

        StdOut.println("The size : "+randomizedQueue.size());
        Iterator it1 = randomizedQueue.iterator();
        while (it1.hasNext()) {
            StdOut.print(it1.next()+"  ");
        }

        StdOut.println();
        StdOut.println("===============================");

        Iterator it2 = randomizedQueue.iterator();
        while (it2.hasNext()) {
            StdOut.print(it2.next()+"  ");
        }
    }
}