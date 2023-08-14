package DataStructures;

import java.util.Iterator;
import java.util.NoSuchElementException;

/**
 * A specification of an {@link Iterator} for Lists.
 * <p>
 * Note that {@link #get()}, {@link #set(Object)}, {@link #add(Object)} and {@link #remove()} all operate
 * on the last returned item of either {@link #next()} or {@link #previous()} and after using either {@link #add(Object)}
 * or {@link #remove()} the last return will be ignored and any other operation that uses this return will throw an
 * {@link IllegalStateException}.
 * </p>
 *
 * <p>
 * No other method that method that modifies the list should be used. Otherwise it might throw an error.
 * </p>
 *
 * @param <E> The type of item to be iterated.
 * @author Eduardo Costa de Souza
 * @see Iterator
 */
public interface ListIterator<E> extends Iterator<E> {
    /**
     * Returns the index of the last position returned by {@link #next()} or {@link #previous()}.
     *
     * @return The index of the last position.
     */
    int index();

    /**
     * Returns the index of the item that {@link #next()} would return if it was called.
     *
     * @return The index of {@link #next()}.
     */
    int nextIndex();

    /**
     * Returns the index of the item that {@link #previous()} would return if it was called.
     *
     * @return The index of {@link #previous()}.
     */
    default int prevIndex() {
        throw new UnsupportedOperationException();
    }

    /**
     * Get the item from the previous position.
     *
     * @return The previous item.
     * @throws NoSuchElementException If there is no previous item.
     * @throws UnsupportedOperationException If {@code previous} was not implemented.
     */
    default E previous() throws UnsupportedOperationException, NoSuchElementException {
        throw new UnsupportedOperationException();
    }

    /**
     * Returns whether there is a previous item or not.
     * @return whether there is a previous item or not.
     * @throws UnsupportedOperationException If {@code hasPrevious} was not implemented.
     */
    default boolean hasPrevious() throws UnsupportedOperationException {
        throw new UnsupportedOperationException();
    }

    /**
     * @return The last item returned by {@link #next()} or {@link #previous()} at the iteration.
     * @throws IllegalStateException If the List was modified by {@link #remove()} or {@link #add(Object)}.
     */
    E get() throws IllegalStateException;

    /**
     * Replaces the last item returned by {@link #next()} or {@link #previous()} for the given item.
     *
     * @param item The item to replace.
     * @return The replaced item.
     * @throws IllegalStateException If the List was modified.
     */
    E set(E item) throws IllegalStateException;

    /**
     * Removes the last item returned by {@link #next()} or {@link #previous()}. If the next item is the returned
     * item the next item will take the place of the one after that.
     */
    void remove();

    /**
     * Adds an item before the current {@link #next()}.
     * @param item The item to be inserted.
     */
    void add(E item);
}
