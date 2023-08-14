package DataStructures;

import org.jetbrains.annotations.NotNull;

import java.util.Arrays;
import java.util.Collection;
import java.util.Iterator;
import java.util.NoSuchElementException;

public abstract class AbstractList<E> implements List<E> {
    AbstractList() {
    }

    public void addFirst(E item) {
        throw new UnsupportedOperationException();
    }

    public void add(E item, int index) throws IndexOutOfBoundsException {
        throw new UnsupportedOperationException();
    }

    public void addLast(E item) {
        throw new UnsupportedOperationException();
    }

    public E removeFirst() throws NoSuchElementException {
        throw new UnsupportedOperationException();
    }

    public E remove(int index) throws IndexOutOfBoundsException, NoSuchElementException {
        throw new UnsupportedOperationException();
    }

    public E removeLast() throws NoSuchElementException {
        throw new UnsupportedOperationException();
    }

    public E getFirst() throws NoSuchElementException {
        throw new UnsupportedOperationException();
    }

    public E get(int index) throws IndexOutOfBoundsException {
        throw new UnsupportedOperationException();
    }

    public E getLast() throws NoSuchElementException {
        throw new UnsupportedOperationException();
    }

    public E setFirst(E item) throws NoSuchElementException {
        throw new UnsupportedOperationException();
    }

    public E set(E item, int index) throws IndexOutOfBoundsException {
        throw new UnsupportedOperationException();
    }

    public E setLast(E item) throws NoSuchElementException {
        throw new UnsupportedOperationException();
    }

    public int size() {
        throw new UnsupportedOperationException();
    }

    public ListIterator<E> iterator() {
        throw new UnsupportedOperationException();
    }

    public ListIterator<E> iterator(int start) {
        throw new UnsupportedOperationException();
    }

    public ListIterator<E> iterator(int start, int stop) {
        throw new UnsupportedOperationException();
    }

    public final boolean isEmpty() {
        return size() == 0;
    }

    public boolean contains(Object o) {
        for (E e : this)
            if (e.equals(o))
                return true;
        return false;
    }

    public boolean add(E e) {
        addLast(e);
        return true;
    }

    public boolean remove(Object o) {
        ListIterator<E> listIterator = iterator();
        while (listIterator.hasNext())
            if (listIterator.next().equals(o)) {
                listIterator.remove();
                return true;
            }
        return false;
    }

    public boolean containsAll(@NotNull Collection<?> c) {
        if (c.size() > size())
            return false;
        for (Object o : c)
            if (!contains(o))
                return false;
        return true;
    }

    public boolean addAll(@NotNull Collection<? extends E> c) {
        boolean mod = false;
        for (E o : c) {
            addLast(o);
            mod = true;
        }
        return mod;
    }

    public boolean removeAll(@NotNull Collection<?> c) {
        boolean mod = false;
        ListIterator<E> thisIterator = iterator();
        for (Object o : c) {
            while (thisIterator.hasNext())
                if (thisIterator.next().equals(o))
                    thisIterator.remove();
            mod = true;
        }
        return mod;
    }

    public boolean retainAll(@NotNull Collection<?> c) {
        return removeIf(e -> !c.contains(e));
    }

    public void clear() {
        ListIterator<E> listIterator = iterator();
        while (listIterator.hasNext()) {
            listIterator.next();
            listIterator.remove();
        }
    }

    public boolean equals(Object o) {
        if (o == this)
            return true;
        if (!(o instanceof Collection<?> oList))
            return false;

        if (oList.size() != size())
            return false;
        Iterator<?> oItereator = oList.iterator();
        ListIterator<E> thisIterator = iterator();
        while (oItereator.hasNext())
            if (!thisIterator.next().equals(oItereator.next()))
                return false;
        return true;
    }

    public int hashCode() {
        int code = 1;
        for (E e : this)
            code += 31 * code + (e != null ? e.hashCode() : 0);
        return code;
    }

    public String toString() {
        if (size() == 0)
            return "[]";
        String thisAsString = "[";
        ListIterator<E> thisIterator = iterator();
        while (thisIterator.nextIndex() < size() - 1)
            thisAsString = thisAsString.concat(thisIterator.next() + ", ");
        return thisAsString.concat(getLast() + "]");
    }

    public Object[] toArray() {
        Object[] arr = new Object[size()];
        ListIterator<E> listIterator = iterator();
        while (listIterator.hasNext())
            arr[listIterator.nextIndex()] = listIterator.next();
        return arr;
    }

    @SuppressWarnings("unchecked")
    public <T> T[] toArray(T[] a) {
        if (a.length < size())
            return (T[]) Arrays.copyOf(toArray(), size(), a.getClass());
        System.arraycopy(toArray(), 0, a, 0, size());
        return a;
    }

    public List<E> subList(int first, int last) throws IllegalArgumentException {
        throw new UnsupportedOperationException();
    }

    protected List<E> subListOfList(int first, int last, List<E> list) throws IllegalArgumentException {
        if (first > last || isNotPositionIndex(first) || isNotPositionIndex(last))
            throw new IllegalArgumentException();
        ListIterator<E> linkedListIterator = iterator(first, last);
        while (linkedListIterator.hasNext())
            list.addLast(linkedListIterator.next());
        return list;
    }

    protected boolean isNotElementIndex(int index) {
        return index < 0 || index >= size();
    }

    protected boolean isNotPositionIndex(int index) {
        return index < 0 || index > size();
    }

    protected String outOfBoundsMsg(int index) {
        return "Index: " + index + ", Size: " + size();
    }

    protected void verifyElementIndex(int index) {
        if (isNotElementIndex(index))
            throw new IndexOutOfBoundsException(outOfBoundsMsg(index));
    }

    protected void verifyPositionIndex(int index) {
        if (isNotPositionIndex(index))
            throw new IndexOutOfBoundsException(outOfBoundsMsg(index));
    }
}
