import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;

import java.util.Iterator;
import java.util.NoSuchElementException;

/**
 * 实现双端队列
 * 边界条件
 * 1. Throw a java.lang.IllegalArgumentException if the client calls either addFirst() or addLast() with a null argument.
 * 2. Throw a java.util.NoSuchElementException if the client calls either removeFirst() or removeLast when the deque is empty.
 * 3. Throw a java.util.NoSuchElementException if the client calls the next() method in the iterator when there are no more items to return.
 * 4. Throw a java.lang.UnsupportedOperationException if the client calls the remove() method in the iterator.
 */
public class Deque<Item> implements Iterable<Item> {
    private int count = 0;
    private Node head;
    private Node rear;

    private class Node {
        private Item data;
        private Node next;
        private Node pre;
    }

    // construct an empty deque
    public Deque() {
        count = 0;
        head = new Node();
        rear = new Node();
        head.next = rear;
        head.pre = null;
        rear.pre = head;
        rear.next = null;
    }

    // is the deque empty?
    public boolean isEmpty() {
        return count == 0;
    }

    // return the number of items on the deque
    public int size() {
        return count;
    }

    // add the item to the front
    public void addFirst(Item item) {
        if (item == null) {
            throw new IllegalArgumentException("The argument must not be null");
        }
        Node node = new Node();
        node.data = item;
        Node curHead = head.next;
        head.next = node;
        node.pre = head;
        node.next = curHead;
        curHead.pre = node;
        count++;
    }

    // add the item to the end
    public void addLast(Item item) {
        if (item == null) {
            throw new IllegalArgumentException("The argument must not be null");
        }
        Node node = new Node();
        node.data = item;
        Node curRear = rear.pre;
        rear.pre = node;
        node.next = rear;
        curRear.next = node;
        node.pre = curRear;
        count++;
    }

    // remove and return the item from the front
    public Item removeFirst() {
        if (isEmpty()) {
            throw new NoSuchElementException("No such element");
        }
        Node curNode = head.next;
        head.next = curNode.next;
        curNode.next.pre = head;
        count--;
        return curNode.data;
    }

    // remove and return the item from the end
    public Item removeLast() {
        if (isEmpty()) {
            throw new NoSuchElementException("No such element");
        }
        Node curNode = rear.pre;
        rear.pre = curNode.pre;
        curNode.pre.next = rear;
        count--;
        return curNode.data;
    }

    // return an iterator over items in order from front to end
    public Iterator<Item> iterator() {
        return new DequeIterator();
    }

    private class DequeIterator implements Iterator<Item> {
        private Node current = head.next;

        @Override
        public boolean hasNext() {
            return current != rear;
        }

        @Override
        public Item next() {
            Item item = current.data;
            current = current.next;
            return item;
        }

        @Override
        public void remove() {
            throw new UnsupportedOperationException("can not remote item in iterator");
        }
    }

    // unit testing (optional)
    public static void main(String[] args) {
        Deque<Integer> deque = new Deque<>();

        for (int i = 0; i < 10; i++) {
            int random = StdRandom.uniform(0, 100);
            deque.addLast(random);
        }

        for (int i = 0; i < 10; i++) {
            int random = StdRandom.uniform(0, 100);
            deque.addFirst(random);
        }

        StdOut.println("The size is : "+deque.size());
        Iterator it = deque.iterator();
        while (it.hasNext()) {
            StdOut.print(it.next()+"  ");
        }
    }
}
