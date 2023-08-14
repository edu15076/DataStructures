///
/// @author Eduardo Costa de Souza
///

#ifndef C_ARRAYLIST_H
#define C_ARRAYLIST_H

#include "ListDefinitions.h"

typedef struct {
    Array list;
    size_t len;
    size_t increment;
} ArrayListRaw;

/**
 * A list of <b>Items</b>. Implemented as a <b>ArrayList</b>.
 */
typedef ArrayListRaw* ArrayList;

/**
 * Creates a new <b>ArrayList</b> with the initial size of <em>size</em>. The <em>increment</em> of the list is half of the size permanently.
 * @param size The size of the new <b>ArrayList</b>.
 * @return The new <b>ArrayList</b>.
 */
ArrayList new_array_list(size_t size);

/**
 * Adds an <b>Item</b> to the end of the <b>ArrayList</b>.
 * @param list The <b>ArrayList</b> to add the <b>Item</b>.
 * @param item The <b>Item</b> to be added.
 * @return Return <b>True</b> if the <b>Item</b> was added else it returns <b>False</b>.
 */
Boolean al_add(ArrayList list, Item item, size_t pos);

/**
 * Adds an <b>Item</b> to the start of the <b>ArrayList</b>.
 * @param list The <b>ArrayList</b> to add the <b>Item</b>.
 * @param item The <b>Item</b> to be added.
 * @return Return <b>True</b> if the <b>Item</b> was added else it returns <b>False</b>.
 */
Boolean al_add_start(ArrayList list, Item item);

/**
 * Adds an <b>Item</b> to the end of the <b>ArrayList</b>.
 * @param list The <b>ArrayList</b> to add the <b>Item</b>.
 * @param item The <b>Item</b> to be added.
 * @return Return <b>True</b> if the <b>Item</b> was added else it returns <b>False</b>.
 */
Boolean al_add_end(ArrayList list, Item item);

/**
 * Removes an <b>Item</b> at a position, <b>pos</b>, of the <b>ArrayList</b>.
 * @param list The <b>ArrayList</b> from where to remove the <b>Item</b>.
 * @param pos The position to remove the <b>Item</b>.
 * @return Returns the <b>Item</b> if it was removed else it returns <b>ERR_INVALID_POSITION</b>.
 */
Item al_remove(ArrayList list, size_t pos);

/**
 * Removes the first <b>Item</b> of the <b>ArrayList</b>.
 * @param list The <b>ArrayList</b> to remove the <b>Item</b> from.
 * @return Returns the <b>Item</b> if it was removed else if the list is empty it returns <b>ERR_EMPTY_LIST</b>.
 */
Item al_remove_first(ArrayList list);

/**
 * Removes the last <b>Item</b> of the <b>ArrayList</b>.
 * @param list The <b>ArrayList</b> to remove the <b>Item</b> from.
 * @return Returns the <b>Item</b> if it was removed else if the list is empty it returns <b>ERR_EMPTY_LIST</b>.
 */
Item al_remove_last(ArrayList list);

/**
 * Gets the <b>Item</b> at the position, <b>pos</b>, of the <b>ArrayList</b>.
 * @param list The <b>ArrayList</b> where to find the <b>Item</b>.
 * @param pos The position of the <b>Item</b>.
 * @return Returns the <b>Item</b> found or <b>ERR_INVALID_POSITION</b> if the position is inaccessible.
 */
Item al_get(ArrayList list, size_t pos);

/**
 * Substitutes the <b>Item</b> at the position, <b>pos</b>, for the <b>new Item</b>, in the <b>ArrayList</b>.
 * @param list The <b>ArrayList</b> to substitute the <b>Item</b>.
 * @param item The new <b>Item</b> to be substituted at the <b>pos</b>.
 * @param pos The position where to substitute the <b>Item</b>.
 * @return Returns <b>True</b> if the position is accessible else returns <b>False</b>.
 */
Boolean al_substitute(ArrayList list, Item item, size_t pos);

/**
 * Gets the length of the <b>ArrayList</b>.
 * @param list The <b>ArrayList</b>.
 * @return The length of the <b>ArrayList</b>.
 */
size_t al_len(ArrayList list);

/**
 * Prints the <b>ArrayList</b>.
 * @param list The list to be printed.
 * @param print_item A function to print the first <b>Item</b> of the list.
 * @param print_first A function to print a <b>Item</b> of the list.
 * @param print_last A function to print the last <b>Item</b> of the list.
 */
void al_print(ArrayList list, void (*print_item)(Item item), void (*print_first)(Item item), void (*print_last)(Item item));


ArrayList new_array_list(size_t size) {
    if (size < 2)
        size = 2;

    ArrayList new_al = (ArrayList) malloc(sizeof(ArrayListRaw));
    new_al->list = new_array(size);
    new_al->len = 0;
    new_al->increment = size / 2;
    return new_al;
}

Boolean al_add(ArrayList list, Item item, size_t pos) {
    if (pos > list->len)
        return False;

    list->len++;
    if (list->len > list->list->size)
        arr_realloc(list->list, list->list->size + list->increment);

    arr_move(list->list, pos, list->len - 2, 1);

    list->list->arr[pos] = item;

    return True;
}

Boolean al_add_start(ArrayList list, Item item) {
    list->len++;
    if (list->len > list->list->size)
        arr_realloc(list->list, list->list->size + list->increment);

    arr_move(list->list, 0, list->len - 2, 1);
    list->list->arr[0] = item;

    return True;
}

Boolean al_add_end(ArrayList list, Item item) {
    if (list->len + 1 > list->list->size)
        arr_realloc(list->list, list->list->size + list->increment);

    list->list->arr[list->len] = item;
    list->len++;

    return True;
}

Item al_remove(ArrayList list, size_t pos) {
    if (pos >= list->len)
        return ERR_INVALID_POSITION;

    Item removed_item = list->list->arr[pos];
    arr_move(list->list, pos + 1, list->len - 1, -1);
    list->len--;
    if (list->list->size / list->increment > list->len / list->increment + 2)
        arr_realloc(list->list, list->list->size - list->increment);

    return removed_item;
}

Item al_remove_first(ArrayList list) {
    return al_remove(list, 0);
}

Item al_remove_last(ArrayList list) {
    if (!list->len)
        return ERR_EMPTY_LIST;

    Item removed_item = list->list->arr[list->len - 1];
    list->len--;
    if (list->list->size / list->increment > list->len / list->increment + 2)
        arr_realloc(list->list, list->list->size - list->increment);

    return removed_item;
}

Item al_get(ArrayList list, size_t pos) {
    if (pos >= list->len)
        return ERR_INVALID_POSITION;

    return list->list->arr[pos];
}

Boolean al_substitute(ArrayList list, Item item, size_t pos) {
    if (pos >= list->len)
        return False;

    list->list->arr[pos] = item;

    return True;
}

size_t al_len(ArrayList list) {
    return list->len;
}

void delete_array_list(ArrayList list) {
    delete_array(list->list);
    free(list);
}

void al_bubble_sort(ArrayList list, Boolean (*cmp)(Item a, Item b), size_t item_size) {
    bb_sort(list->list, list->len, cmp, item_size);
}

void al_print(ArrayList list, void (*print_item)(Item item), void (*print_first)(Item item), void (*print_last)(Item item)) {
    if (!list->len)
        return;
    if (!(list->len - 1)) {
        print_last(list->list->arr[0]);
        return;
    }

    print_first(list->list->arr[0]);
    for (int i = 1; i < list->len - 1; i++)
        print_item(list->list->arr[i]);
    print_last(list->list->arr[list->len - 1]);
}

#endif //C_ARRAYLIST_H
