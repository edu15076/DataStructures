package DataStructures;

import org.jetbrains.annotations.NotNull;

import java.security.InvalidParameterException;
import java.util.Arrays;
import java.util.Collection;
import java.util.NoSuchElementException;

public class DoublyLinkedList<E> extends AbstractLinkedList<E> implements List<E> {
    private Node<E> first;
    private Node<E> last;
    private int len;

    public DoublyLinkedList() {
        len = 0;
        first = null;
        last = null;
    }

    public DoublyLinkedList(@NotNull Collection<? extends E> initList) {
        this();
        for (E item : initList)
            addLast(item);
    }

    @SafeVarargs
    public DoublyLinkedList(E ... initList) {
        this(Arrays.asList(initList));
    }

    public void addFirst(E item) {
        linkFirst(item);
    }

    public void add(E item, int index) throws IndexOutOfBoundsException {
        verifyPositionIndex(index);

        if (index != len)
            linkBefore(item, node(index));
        else
            linkLast(item);
    }

    public void addLast(E item) {
        linkLast(item);
    }

    public E removeFirst() throws NoSuchElementException {
        if (first == null)
            throw new NoSuchElementException();
        return unlinkFirst(first);
    }

    public E remove(int index) throws IndexOutOfBoundsException, NoSuchElementException {
        verifyElementIndex(index);
        return unlink(node(index));
    }

    public E removeLast() throws NoSuchElementException {
        if (last == null)
            throw new NoSuchElementException();
        return unlinkLast(last);
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
        if (last == null)
            throw new NoSuchElementException();
        return last.item;
    }

    public E setFirst(E item) throws NoSuchElementException {
        if (first == null)
            throw new NoSuchElementException();
        return setNode(item, first);
    }

    public E set(E item, int index) throws IndexOutOfBoundsException {
        verifyElementIndex(index);
        return setNode(item, node(index));
    }

    public E setLast(E item) throws NoSuchElementException {
        if (last == null)
            throw new NoSuchElementException();
        return setNode(item, last);
    }

    public int size() {
        return len;
    }

    public DoublyLinkedList<E> subList(int first, int last) throws IllegalArgumentException {
        return (DoublyLinkedList<E>) subListOfList(first, last, new DoublyLinkedList<>());
    }

    public ListIterator<E> iterator() {
        return new DoublyLinkedListIterator();
    }

    public ListIterator<E> iterator(int start) {
        verifyPositionIndex(start);
        return new DoublyLinkedListIterator(start);
    }

    public ListIterator<E> iterator(int start, int stop) {
        verifyPositionIndex(start);
        if (start > stop)
            throw new InvalidParameterException(start + " is greater than " + stop);
        return new DoublyLinkedListIterator(start, len - stop);
    }

    private class DoublyLinkedListIterator implements ListIterator<E> {
        private Node<E> next;
        private Node<E> lastRet = null;
        private int nextI;
        private int lastRetI;
        private final int stopDist;

        DoublyLinkedListIterator() {
            this(0);
        }

        DoublyLinkedListIterator(int i) {
            this(i, 0);
        }

        DoublyLinkedListIterator(int i, int stopDist) {
            lastRetI = nextI = i;
            this.stopDist = stopDist;
            next = i == len ? null : node(i);
        }

        public boolean hasNext() {
            return nextI != len - stopDist;
        }

        public boolean hasPrevious() {
            return nextI != 0;
        }

        public E next() throws NoSuchElementException {
            if (!hasNext())
                throw new NoSuchElementException();
            lastRet = next;
            next = next.next;
            lastRetI = nextI;
            nextI++;
            return lastRet.item;
        }

        public E previous() throws NoSuchElementException {
            if (!hasPrevious())
                throw new NoSuchElementException();
            lastRet = next = next != null ? next.prev : last;
            lastRetI = --nextI;
            return lastRet.item;
        }

        public void remove() throws IllegalStateException {
            if (lastRet == null)
                throw new IllegalStateException();
            if (lastRet != next)
                nextI--;
            else
                next = lastRet.next;
            unlink(lastRet);
            lastRet = null;
        }

        public void add(E item) throws IllegalStateException {
            if (lastRet == null)
                throw new IllegalStateException();
            if (next != null)
                linkBefore(item, next);
            else
                linkLast(item);
            nextI++;
            lastRet = null;
        }

        public int index() {
            return lastRetI;
        }

        public int nextIndex() {
            return nextI;
        }

        public int prevIndex() {
            return nextI - 1;
        }

        public E get() throws IllegalStateException {
            if (lastRet == null)
                throw new IllegalStateException();
            return lastRet.item;
        }

        public E set(E item) throws IllegalStateException {
            if (lastRet == null)
                throw new IllegalStateException();
            return setNode(item, lastRet);
        }
    }

    private static class Node<E> {
        E item;
        Node<E> next, prev;

        Node(Node<E> prev, E item, Node<E> next) {
            this.item = item;
            this.next = next;
            this.prev = prev;
        }

        Node(E item, Node<E> next) {
            this(null, item, next);
        }

        Node(Node<E> prev, E item) {
            this(prev, item, null);
        }
    }

    private Node<E> node(int index) {
        // assert isElementIndex(index);

        Node<E> n;
        if (index < len >> 2) {
            n = first;
            for (int i = 0; i < index; i++)
                n = n.next;
        } else {
            n = last;
            for (int i = len - 1; i > index; i--)
                n = n.prev;
        }
        return n;
    }

    /**
     * Link a node containing e to the first position of the List.
     */
    private void linkFirst(E e) {
        final Node<E> f = first;
        first = new Node<>(e, f);
        if (f == null)
            last = first;
        else
            f.prev = first;
        len++;
    }

    /**
     * Link a node containing e to the last position of the List.
     */
    private void linkLast(E e) {
        final Node<E> l = last;
        last = new Node<>(l, e);
        if (l == null)
            first = last;
        else
            l.next = last;
        len++;
    }

    private void linkBefore(E e, Node<E> next) {
        final Node<E> prev = next.prev;
        final Node<E> newNode = new Node<>(prev, e, next);
        next.prev = newNode;
        if (prev != null)
            prev.next = newNode;
        else
            first = newNode;
        len++;
    }

    /**
     * Link a node containing e after the specified node.
     */
    private void linkAfter(E e, Node<E> prev) {
        // assert prev != null
        final Node<E> next = prev.next;
        final Node<E> newNode = new Node<>(prev, e, next);
        prev.next = newNode;
        if (next != null)
            next.prev = newNode;
        else
            last = newNode;
        len++;
    }

    /**
     * Unlinks the first node of the list, f, passed as parameter and returns the removed item.
     */
    private E unlinkFirst(Node<E> f) {
        // assert f != null && f == first
        first = f.next;
        final E remE = f.item;
        f.next = null;
        f.item = null;
        if (first != null)
            first.prev = null;
        else
            last = null;
        len--;
        return remE;
    }

    /**
     * Unlinks the last node of the list, l, passed as parameter and returns the removed item.
     */
    private E unlinkLast(Node<E> l) {
        // assert l != null && l == last
        last = l.prev;
        final E remE = l.item;
        l.prev = null;
        l.item = null;
        if (last != null)
            last.next = null;
        else
            first = null;
        len--;
        return remE;
    }

    /**
     * Unlinks the node passed as parameter and returns the removed item.
     */
    private E unlink(Node<E> node) {
        // assert node != null
        final Node<E> prev = node.prev;
        final Node<E> next = node.next;
        final E remE = node.item;
        node.item = null;

        if (next != null) {
            next.prev = prev;
            node.next = null;
        } else
            last = prev;

        if (prev != null) {
            prev.next = next;
            node.prev = null;
        } else
            first = next;
        len--;
        return remE;
    }

    /**
     * Sets the item of a node to the given item.
     */
    private E setNode(E item, Node<E> node) {
        // assert node != null
        final E oldItem = node.item;
        node.item = item;
        return oldItem;
    }
}
