package DataStructures;

import org.jetbrains.annotations.NotNull;

import java.util.Collection;
import java.util.NoSuchElementException;

/**
 * A pretty much generic interface for any {@code List}
 * @param <E> The type of element to be stored in the List.
 * @author Eduardo Costa de Souza
 * @see ListIterator
 * @see Iterable
 */
public interface List<E> extends Collection<E> {
    /**
     * Inserts an item in the first index of the List.
     * @param item The item to be inserted.
     */
    void addFirst(E item);

    /**
     * Inserts an item at the given index of the List.
     * @param item The item to be inserted.
     * @param index The index in which the item will be inserted.
     * @throws IndexOutOfBoundsException
     */
    void add(E item, int index) throws IndexOutOfBoundsException;

    /**
     * Appends an item at the end of the List.
     * @param item The item to be appended.
     */
    void addLast(E item);

    /**
     * Removes the first item of the List.
     * @return The removed item.
     * @throws NoSuchElementException If the List is empty.
     */
    E removeFirst() throws NoSuchElementException;

    /**
     * Removes an item at the specified index of the List.
     * @param index The index of the item to be removed.
     * @return The removed item.
     * @throws IndexOutOfBoundsException If index is out of bounds.
     * @throws NoSuchElementException If the List is empty.
     */
    E remove(int index) throws IndexOutOfBoundsException, NoSuchElementException;

    /**
     * Removes the last item of the List.
     * @return The removed item.
     * @throws NoSuchElementException If the List is empty.
     */
    E removeLast() throws NoSuchElementException;

    /**
     * Get the first item of the List.
     * @return The item.
     * @throws NoSuchElementException If the list is empty.
     */
    E getFirst() throws NoSuchElementException;

    /**
     * Get the item at the specified index.
     * @param index The index of the item to be got.
     * @return The item at the index.
     * @throws IndexOutOfBoundsException If index is out of bounds.
     */
    E get(int index) throws IndexOutOfBoundsException;

    /**
     * Get the last item of the List.
     * @return The item.
     * @throws NoSuchElementException If the list is empty.
     */
    E getLast() throws NoSuchElementException;

    /**
     * Replaces the item at the first position of the List for the given item.
     * @param item The item to be stored at the start of the list.
     * @return The previous item at the position;
     * @throws NoSuchElementException If the List is empty.
     */
    E setFirst(E item) throws NoSuchElementException;

    /**
     * Replaces the item at the specified position for the given item.
     * @param item The item to be stored at the specified index.
     * @param index The index of the item to be replaced.
     * @return The previous item at the position;
     * @throws IndexOutOfBoundsException If the index is inaccessible.
     */
    E set(E item, int index) throws IndexOutOfBoundsException;

    /**
     * Replaces the item at the end of the List for the given item.
     * @param item The item to be stored at the end of the list.
     * @return The previous item at the position;
     * @throws NoSuchElementException If the List is empty.
     */
    E setLast(E item) throws NoSuchElementException;

    /**
     * Gets the size of the List.
     * @return The size.
     */
    int size();

    /**
     * Returns an iterator over elements of type E.
     * @return A {@link ListIterator}.
     *
     * @see ListIterator
     */
    ListIterator<E> iterator();

    /**
     * Returns an iterator over elements of type E starting at start.
     * <p>Note that {@code start} only sets a start position giving the possibility to use
     * {@link ListIterator#previous()} to getLast the previous item.</p>
     * @param start The starting position of the iterator.
     * @return A {@link ListIterator}.
     * @see ListIterator
     */
    ListIterator<E> iterator(int start);

    /**
     * Returns an iterator over elements of type E starting at {@code start} and ending at {@code stop}.
     * <p>Note that {@code stop} limits the range of the List for greater indexes whereas {@code start} only sets a
     * start position giving the possibility to use {@link ListIterator#previous()} to getLast the previous item.</p>
     * @param start The starting position of the iterator.
     * @param stop The ending position of the iterator.
     * @return A {@link ListIterator}.
     * @see ListIterator
     */
    ListIterator<E> iterator(int start, int stop);

    /**
     * Tells if the List is empty.
     * @return {@code true} the List is empty.
     */
    boolean isEmpty();

    /**
     * If the List contains an item.
     * @param o The item.
     * @return {@code true} if the List contains {@code o}.
     */
    boolean contains(Object o);

    /**
     * Appends an item at the end of the List.
     * @param e The item to be appended.
     * @return {@code true} if e was added.
     */
    boolean add(E e);

    /**
     * Removes the first occurrence of an item {@code o}, if in the List.
     * @param o element to be removed from this List, if present.
     * @return {@code true} if the element was removed.
     */
    boolean remove(Object o);

    /**
     * Asserts that the List contains all elements in {@code c}.
     * @param c collection to be checked for containment in this List.
     * @return {@code true} if the List contains all elements in {@code c}.
     */
    boolean containsAll(@NotNull Collection<?> c);

    /**
     * Appends all elements of the collection {@code c} to the List.
     * @param c collection containing elements to be added to this collection
     * @return
     */
    boolean addAll(Collection<? extends E> c);

    /**
     * Removes all items present in {@code c} from the List, such that after this method is executed there will be
     * no equality between this List and {@code c}.
     * @param c collection containing elements to be removed from this List.
     * @return {@code true} if changes have been made to the List.
     */
    boolean removeAll(@NotNull Collection<?> c);

    /**
     * Remove all item from the List but the items in {@code c}.
     * @param c collection containing elements to be retained in this List.
     * @return {@code true} if changes have been made.
     */
    boolean retainAll(@NotNull Collection<?> c);

    /**
     * Empties the List.
     */
    void clear();

    /**
     * Compares this List to an {@code Object o}, this object must implement {@code Collection} in order to this
     * method have any possibility of returning {@code true}, if it does the size of both this List and {@code o}
     * will be compared and if they are equal the items will be compared sequentially.
     * @param o object to be compared for equality with this List.
     * @return {@code true} if {@code o} is equal to this List.
     */
    boolean equals(Object o);

    /**
     * @return The hash code value for this List.
     */
    int hashCode();

    /**
     * Returns the string representation of the list.
     * @return The string representation of the list.
     */
    String toString();

    /**
     * Transforms the List to array of type Object with the size of {@link #size()}.
     * @return The new array.
     */
    Object[] toArray();

    /**
     * 
     * @param a the array into which the elements of this collection are to be
     *        stored, if it is big enough; otherwise, a new array of the same
     *        runtime type is allocated for this purpose.
     * @return
     * @param <T>
     */
    <T> T[] toArray(T[] a);

    /**
     * Creates a copy of a sub List of the instanced List from {@code first} to {@code last} and returns it.
     * @param first The first position.
     * @param last The last position.
     * @return The sub list.
     * @throws IllegalArgumentException If the {@code first} or {@code last} is out of range or if {@code first} is
     * greater than {@code last}.
     */
    List<E> subList(int first, int last) throws IllegalArgumentException;
}
