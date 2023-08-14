package DataStructures;

import org.jetbrains.annotations.NotNull;

import java.util.Arrays;
import java.util.NoSuchElementException;

/**
 * An implementation of a {@link List} using single chain Nodes.
 * @param <E> The type of element to be stored in the List.
 * @author Eduardo Costa de Souza
 * @see List
 * @see ListIterator
 */
public class LinkedList<E> extends AbstractLinkedList<E> implements List<E> {
    private Node<E> first;
    private Node<E> last;
    private int len;

    public LinkedList() {
        len = 0;
        first = null;
        last = null;
    }

    public LinkedList(@NotNull Iterable<? extends E> initList) {
        this();
        for (E item : initList)
            addLast(item);
    }

    @SafeVarargs
    public LinkedList(E ... initList) {
        this(Arrays.asList(initList));
    }

    public void addFirst(E item) {
        Node<E> newNode = new Node<>(item, first);
        if (first != null)
            first = newNode;
        else
            first = last = newNode;
        len++;
    }

    public void add(E item, int index) {
        if (index == 0)   { addFirst(item); return; }
        if (index == len) { addLast(item); return; }
        verifyPositionIndex(index);

        Node<E> beforeNode = node(index - 1);
        beforeNode.next = new Node<>(item, beforeNode.next);
        len++;
    }

    public void addLast(E item) {
        Node<E> newNode = new Node<>(item);
        if (last != null)
            last.next = newNode;
        else
            first = newNode;
        last = newNode;
        len++;
    }

    public E removeFirst() throws NoSuchElementException {
        if (first == null)
            throw new NoSuchElementException();

        Node<E> f = first.next;
        E retVal = first.item;
        unlinkNode(first);
        first = f;
        len--;
        if (f == null || len == 1)
            last = first;
        return retVal;
    }

    public E remove(int index) throws IndexOutOfBoundsException, NoSuchElementException {
        if (index == 0)
            return removeFirst();
        if (len == index + 1)
            return removeLast();
        verifyElementIndex(index);

        Node<E> before = node(index - 1);
        Node<E> remvNode = before.next;
        E retVal = remvNode.item;
        before.next = remvNode.next;
        unlinkNode(remvNode);
        len--;

        return retVal;
    }

    public E removeLast() throws NoSuchElementException {
        if (len == 1)
            return removeFirst();
        if (first == null)
            throw new NoSuchElementException();

        Node<E> newLast = node(--len - 1);
        E retVal = last.item;
        newLast.next = null;
        unlinkNode(last);
        last = newLast;
        if (len == 1)
            first = last;

        return retVal;
    }

    public E getFirst() throws NoSuchElementException {
        if (first == null)
            throw new NoSuchElementException();
        return first.item;
    }

    public E get(int index) throws IndexOutOfBoundsException {
        verifyElementIndex(index);
        return node(index).item;
    }

    public E getLast() throws NoSuchElementException {
        if (first == null)
            throw new NoSuchElementException();
        return last.item;
    }

    public E setFirst(E item) throws NoSuchElementException {
        if (first == null)
            throw new NoSuchElementException();
        return setNode(first, item);
    }

    public E set(E item, int index) throws IndexOutOfBoundsException {
        verifyElementIndex(index);
        return setNode(node(index), item);
    }

    public E setLast(E item) throws NoSuchElementException {
        if (first == null)
            throw new NoSuchElementException();
        return setNode(last, item);
    }

    public int size() {
        return len;
    }

    public LinkedList<E> subList(int first, int last) throws IllegalArgumentException {
        return (LinkedList<E>) subListOfList(first, last, new LinkedList<>());
    }

    public ListIterator<E> iterator() {
        return new IterateLinkedList();
    }

    public ListIterator<E> iterator(int start) {
        verifyPositionIndex(start);
        return new IterateLinkedList(start);
    }

    public ListIterator<E> iterator(int start, int stop) {
        verifyPositionIndex(start);
        if (start > stop)
            throw new IllegalArgumentException(start + " is greater than" + stop);
        return new IterateLinkedList(start, len - stop);
    }

    private class IterateLinkedList implements ListIterator<E> {
        private Node<E> next;
        private Node<E> lastRet = null;
        private int i;
        private final int stopDist;

        IterateLinkedList() {
            this(0);
        }

        IterateLinkedList(int i) {
            this(i, 0);
        }

        IterateLinkedList(int i, int stopDist) {
            this.i = i;
            this.stopDist = stopDist;
            next = i == len ? null : node(i);
        }

        public boolean hasNext() {
            return i != len - stopDist;
        }

        public E next() {
            lastRet = next;
            next = next.next;
            i++;
            return lastRet.item;
        }

        public void remove() {
            if (lastRet == null)
                throw new IllegalStateException();
            LinkedList.this.remove(--i);
            lastRet = null;
        }

        public void add(E item) {
            if (lastRet == null)
                throw new IllegalStateException();

            lastRet.next = new Node<>(item, next);
            if (next == null)
                last = lastRet.next;
            i++;
            len++;
            lastRet = null;
        }

        public int index() {
            return i - 1;
        }

        public int nextIndex() {
            return i;
        }

        public E get() throws IllegalStateException {
            if (lastRet == null)
                throw new IllegalStateException();
            return lastRet.item;
        }

        public E set(E item) throws IllegalStateException {
            if (lastRet == null)
                throw new IllegalStateException();
            E oldItem = lastRet.item;
            lastRet.item = item;
            return oldItem;
        }
    }

    private static class Node<E> {
        Node<E> next;
        E item;

        Node(E val, Node<E> next) {
            this.next = next;
            this.item = val;
        }

        Node(E val) {
            this(val, null);
        }
    }

    private Node<E> node(int index) {
        Node<E> n = first;
        for (int i = 0; i < index; i++)
            n = n.next;
        return n;
    }

    private void unlinkNode(@NotNull Node<E> n) {
        n.next = null;
        n.item = null;
    }

    private E setNode(Node<E> node, E item) {
        final E oldItem = node.item;
        node.item = item;
        return oldItem;
    }
}