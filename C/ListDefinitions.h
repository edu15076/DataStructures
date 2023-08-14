///
/// @author Eduardo Costa de Souza
///

#ifndef C_LISTDEFINITIONS_H
#define C_LISTDEFINITIONS_H

#include "Boolean.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


#define ERR_INVALID_POSITION NULL
#define ERR_EMPTY_LIST NULL
#define LIST_END NULL

/**
 * A general <b>Item</b> as it can point to any type.
 *
 * You always have to call <em>new_item()</em> to insert an <b>Item</b> in a <b>List</b> or <b>Array</b>.
 */
typedef void* Item;

/**
 * An array of <b>Item</b>.
 */
typedef Item* Items;

/**
 * Copy the <b>item</b> parameter to a new space of the memory.
 *
 * You always have to call this function to insert an <b>Item</b> in a <b>List</b> or <b>Array</b>.
 * @param item The <b>Item</b> to be copied.
 * @param size The size of the <b>Item</b>.
 * @return The new <b>Item</b>.
 */
Item new_item(Item item, size_t size);

/**
 * Create an array of <b>Item</b> with the size of <b>size</b>.
 * @param size The size of the array.
 * @return The <b>Items</b>.
 */
Items new_items(size_t size);

Item new_item(Item item, size_t size) {
    Item new_i = malloc(size);
    memcpy(new_i, item, size);
    return new_i;
}

Items new_items(size_t size) {
    Items new_items_c = (Items) malloc(size * sizeof(Item));
    return new_items_c;
}

void realloc_items(Items* items, size_t new_size) {
    *items = (Items) realloc(*items, new_size * sizeof(Item));
}

typedef struct {
    Items arr;
    size_t size;
} ArrayRaw;

/**
 * The <b>Array</b> type contains an array of <b>Item</b> and the size of this array.
 *
 * This type is supposed to be a generic type array that can be almost as fast as a normal array, in space it does have
 * a bigger space complexity as it contains extra 4 bytes for every <b>Item</b> allocated.
 */
typedef ArrayRaw* Array;

/**
 * Creates a new <b>Array</b>.
 * @param size The <b>size</b> of the new <b>Array</b>.
 * @return The new <b>Array</b>
 */
Array new_array(size_t size);

/**
 * Reallocs the <b>Array</b> to a new size.
 * @param arr The <b>Array</b> to be realloced.
 * @param new_size The new size of the <b>Array</b>.
 */
void arr_realloc(Array arr, size_t new_size);

/**
 * Move <b>Items</b>, delimited by <em>first</em> and <em>last</em>, by <em>move</em>.
 * This function does not verify if the array fits the <em>move</em> of the <b>Items</b>.
 * @param arr The <b>Array</b> to be moved.
 * @param first The first <b>Item</b> to be moved.
 * @param last The last <b>Item</b> to be moved.
 * @param move The number of spaces the <b>Items</b> will move within the array.
 */
void arr_move(Array arr, size_t first, size_t last, int move);

Array new_array(size_t size) {
    Array arr = (Array) malloc(sizeof(ArrayRaw));
    arr->arr = new_items(size);
    arr->size = size;
    return arr;
}

void arr_realloc(Array arr, size_t new_size) {
    realloc_items(&arr->arr, new_size);
    arr->size = new_size;
}

void swap(void* item1, void* item2, size_t size) {
    void* temp = malloc(size);
    memcpy(temp, item1, size);
    memmove(item1, item2, size);
    memmove(item2, temp, size);
    free(temp);
}

void bb_sort(Array arr, size_t len, Boolean (*cmp)(Item item1, Item item2), size_t size) {
    for (int i = 0; i < len; i++)
        for (int j = 0; j < len - i - 1; j++)
            if (cmp(arr->arr[j], arr->arr[j + 1]))
                swap(&arr->arr[j], &arr->arr[j + 1], size);
}

void arr_move(Array arr, size_t first, size_t last, int move) {
    if (move < 0)
        for (size_t i = first + move; i < last; i -= move)
            arr->arr[i] = arr->arr[i + 1];
    else
        for (size_t i = last + move; i > first; i -= move)
            arr->arr[i] = arr->arr[i - 1];
}

void delete_array(Array arr) {
    for (int i = 0; i < arr->size; i++)
        if (arr->arr[i])
            free(arr->arr[i]);
    free(arr);
}

/**
 * Print a <b>int</b> in a <b>List</b>.
 * @param item The <b>Item</b> to be printed.
 */
void print_int_list(Item item);

/**
 * Print the last <b>int</b> in a <b>List</b>.
 * @param item The <b>Item</b> to be printed.
 */
void print_int_list_end(Item item);

/**
 * Parse an item, of any type since it is stored in a <b>void*</b>, to <b>int</b>.
 * @param val The <b>void*</b> to be converted.
 * @return The converted <b>int</b>.
 */
int parse_int(void* val);

Boolean compare_int(Item a, Item b) {
    return parse_int(a) > parse_int(b);
}

void print_int_list(Item item) {
    int n = parse_int(item);
    printf("%d, ", n);
}

void print_int_list_end(Item item) {
    int n = parse_int(item);
    printf("%d\n", n);
}

int parse_int(void* val) {
    if (!val)
        return 0;

    return *((int*) val);
}

#endif //C_LISTDEFINITIONS_H
