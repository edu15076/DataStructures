///
/// @author Eduardo Costa de Souza
///

#ifndef C_LINKEDLIST_H
#define C_LINKEDLIST_H

#include "ListDefinitions.h"

typedef struct LINKEDLISTNODE {
    struct LINKEDLISTNODE* next;
    Item item;
} LinkedListNode;

/**
 * Crates a <b>new LinkedListNode</b>.
 *
 * @param item The <b>Item</b> to be inserted in the <b>Node</b>.
 * @param next The next <b>Node</b>.
 * @return The created <b>Node</b>.
 */
LinkedListNode* lk_new_node(Item item, LinkedListNode* next);

/**
 * A literal position of a <b>LinkedList</b>, it can be used in for-of loops.
 */
typedef LinkedListNode* LKPosition;

typedef struct {
    LinkedListNode* first;
    LinkedListNode* last;
    size_t len;
} LinkedListRaw;

/**
 * A list of <b>Items</b>. Implemented as a <b>LinkedList</b>.
 */
typedef LinkedListRaw* LinkedList;

/**
 * Get the <b>Node</b> at the position <b>pos</b>.
 * @param list The <b>LinkedList</b>.
 * @param pos The position of the <b>Node</b>.
 * @return Returns <b>ERR_INVALID_POSITION</b> if the position is invalid else the <b>Node</b>.
 */
LinkedListNode* lk_get_node(LinkedList list, size_t pos);

/**
 * Get the a position, <b>pos</b>, in the <b>LinkedList</b>.
 * @param list The <b>LinkedList</b>.
 * @param pos A position of the <b>LinkedList</b>.
 * @return Returns <b>ERR_INVALID_POSITION</b> if the position is invalid else the <b>LKPosition</b> in the <b>LinkedList</b>.
 */
LKPosition lk_get_position(LinkedList list, size_t pos);

/**
 * Get the next <b>LKPosition</b> based on the parameter <b>position</b>.
 * @param position The starting <b>LKPosition</b>.
 * @return The next <b>LKPosition</b> or <b>ERR_INVALID_POSITION</b> if the <b>LKPosition</b> is invalid.
 */
LKPosition lk_next_position(LKPosition position);

/**
 * Gets the first <b>LKPosition</b> of the <b>LinkedList</b>.
 * @param list The <b>LinkedList</b>.
 * @return The first <b>LKPosition</b> or <b>ERR_EMPTY_LIST</b> if the list is empty.
 */
LKPosition lk_first_position(LinkedList list);

/**
 * Gets the last <b>LKPosition</b> of the <b>LinkedList</b>.
 * @param list The <b>LinkedList</b>.
 * @return The last <b>LKPosition</b> or <b>ERR_EMPTY_LIST</b> if the list is empty.
 */
LKPosition lk_last_position(LinkedList list);

/**
 * Gets the <b>Item</b> at the <b>LKPosition</b>.
 * @param position The <b>LKPosition</b>.
 * @return The <b>Item</b> at the <b>LKPosition</b> or <b>ERR_INVALID_POSITION</b> if the <b>LKPosition</b> is invalid.
 */
Item lk_position_item(LKPosition position);

/**
 * Gets the length of the <b>LinkedList</b>.
 * @param list The <b>LinkedList</b>.
 * @return The length of the <b>LinkedList</b>.
 */
size_t lk_len(LinkedList list);

/**
 * Creates a <b>new LinkedList</b>.
 * @return A <b>new LinkedList</b>.
 */
LinkedList new_linked_list();

/**
 * Deletes a <b>LinkedList</b>.
 * @param list The <b>list</b> to be deleted.
 */
void delete_linked_list(LinkedList list);

/**
 * Adds an <b>Item</b> to a position, <b>pos</b>, at the <b>LinkedList</b>.
 * @param list The <b>LinkedList</b> to add the <b>Item</b>.
 * @param item The <b>Item</b> to be added.
 * @param pos The position to add the <b>Item</b>.
 * @return Return <b>True</b> if <b>pos</b> is accessible else it returns <b>False</b>.
 */
Boolean lk_add(LinkedList list, Item item, size_t pos);

/**
 * Adds an <b>Item</b> to the end of the <b>LinkedList</b>.
 * @param list The <b>LinkedList</b> to add the <b>Item</b>.
 * @param item The <b>Item</b> to be added.
 * @return Return <b>True</b> if the <b>Item</b> was added else it returns <b>False</b>.
 */
Boolean lk_add_end(LinkedList list, Item item);

/**
 * Adds an <b>Item</b> to the start of the <b>LinkedList</b>.
 * @param list The <b>LinkedList</b> to add the <b>Item</b>.
 * @param item The <b>Item</b> to be added.
 * @return Return <b>True</b> if the <b>Item</b> was added else it returns <b>False</b>.
 */
Boolean lk_add_start(LinkedList list, Item item);

/**
 * Removes an <b>Item</b> at a position, <b>pos</b>, of the <b>LinkedList</b>.
 * @param list The <b>LinkedList</b> from where to remove the <b>Item</b>.
 * @param pos The position to remove the <b>Item</b>.
 * @return Returns the <b>Item</b> if it was removed else it returns <b>ERR_INVALID_POSITION</b>.
 */
Item lk_remove(LinkedList list, size_t pos);

/**
 * Removes the last <b>Item</b> of the <b>LinkedList</b>.
 * @param list The <b>LinkedList</b> to remove the <b>Item</b>.
 * @return Returns the <b>Item</b> if it was removed else if the list is empty it returns <b>ERR_EMPTY_LIST</b>.
 */
Item lk_remove_last(LinkedList list);

/**
 * Removes the first <b>Item</b> of the <b>LinkedList</b>.
 * @param list The <b>LinkedList</b> to remove the <b>Item</b>.
 * @return Returns the <b>Item</b> if it was removed else if the list is empty it returns <b>ERR_EMPTY_LIST</b>.
 */
Item lk_remove_first(LinkedList list);

/**
 * Gets the <b>Item</b> at the position, <b>pos</b>, of the <b>LinkedList</b>.
 * @param list The <b>LinkedList</b> where to find the <b>Item</b>.
 * @param pos The position of the <b>Item</b>.
 * @return Returns the <b>Item</b> found or <b>ERR_INVALID_POSITION</b> if the position is inaccessible.
 */
Item lk_get(LinkedList list, size_t pos);

/**
 * Substitutes the <b>Item</b> at the position, <b>pos</b>, for the <b>new Item</b>, in the <b>LinkedList</b>.
 * @param list The <b>LinkedList</b> to substitute the <b>Item</b>.
 * @param subs_item The new <b>Item</b> to be substituted at the <b>pos</b>.
 * @param pos The position where to substitute the <b>Item</b>.
 * @return Returns <b>True</b> if the position is accessible else returns <b>False</b>.
 */
Boolean lk_substitute(LinkedList list, Item subs_item, size_t pos);

/**
 * Prints the <b>LinkedList</b>.
 * @param list The list to be printed.
 * @param print_item A function to print the first <b>Item</b> of the list.
 * @param print_first A function to print a <b>Item</b> of the list.
 * @param print_last A function to print the last <b>Item</b> of the list.
 */
void lk_print(LinkedList list, void (*print_item)(Item item), void (*print_first)(Item item), void (*print_last)(Item item));

LinkedListNode* lk_new_node(Item item, LinkedListNode* next) {
    LinkedListNode* new_node = (LinkedListNode*) malloc(sizeof(LinkedListNode));
    new_node->item = item;
    new_node->next = next;
    return new_node;
}

LinkedListNode* lk_get_node(LinkedList list, size_t pos) {
    if (pos >= list->len)
        return ERR_INVALID_POSITION;

    LinkedListNode* node = list->first;
    for ( ; pos > 0; node = node->next, pos--);
    return node;
}

LKPosition lk_get_position(LinkedList list, size_t pos) {
    return lk_get_node(list, pos);
}

LKPosition lk_next_position(LKPosition position) {
    if (!position)
        return ERR_INVALID_POSITION;

    return position->next;
}

LKPosition lk_first_position(LinkedList list) {
    return list->first;
}

LKPosition lk_last_position(LinkedList list) {
    return list->last;
}

Item lk_position_item(LKPosition position) {
    if (!position)
        return ERR_INVALID_POSITION;

    return position->item;
}

size_t lk_len(LinkedList list) {
    return list->len;
}

LinkedList new_linked_list() {
    LinkedList list = (LinkedList) malloc(sizeof(LinkedListRaw));
    list->len = 0;
    list->first = list->last = NULL;
    return list;
}

void delete_linked_list(LinkedList list) {
    LinkedListNode* node_remove;
    for (LinkedListNode* i = list->first; i; ) {
        node_remove = i;
        i = i->next;
        free(node_remove);
    }

    free(list);
}

Boolean lk_add(LinkedList list, Item item, size_t pos) {
    if (pos > list->len)
        return False;

    LinkedListNode* node_before = lk_get_node(list, pos - 1);
    LinkedListNode* node_next = node_before ? node_before->next : list->first;

    LinkedListNode* new_node = lk_new_node(item, node_next);
    if (node_before)
        node_before->next = new_node;
    else
        list->first = new_node;

    if (!node_next)
        list->last = new_node;

    list->len++;

    return True;
}

Boolean lk_add_end(LinkedList list, Item item) {
    LinkedListNode* new_node = lk_new_node(item, NULL);

    if (list->len)
        list->last->next = new_node;
    else
        list->first = new_node;

    list->last = new_node;
    list->len++;

    return True;
}

Boolean lk_add_start(LinkedList list, Item item) {
    LinkedListNode* new_node = lk_new_node(item, list->first);

    if (!list->len)
        list->last = new_node;

    list->first = new_node;
    list->len++;

    return True;
}

Item lk_remove(LinkedList list, size_t pos) {
    if (!pos)
        return lk_remove_first(list);

    if (pos >= list->len)
        return ERR_INVALID_POSITION;

    LinkedListNode* node_before = lk_get_node(list, pos - 1);
    LinkedListNode* delete_node = node_before->next;
    Item removed_item = delete_node->item;
    node_before->next = delete_node->next;
    free(delete_node);
    list->len--;

    if (!node_before->next) {
        list->last = node_before;

        if (!(list->len - 1))
            list->first = node_before;
    }

    return removed_item;
}

Item lk_remove_last(LinkedList list) {
    return lk_remove(list, list->len - 1);
}

Item lk_remove_first(LinkedList list) {
    if (!list->len)
        return ERR_EMPTY_LIST;

    LinkedListNode* delete_node = list->first;
    list->first = delete_node->next;
    list->len--;
    Item removed_item = delete_node->item;
    free(delete_node);
    if (!(list->len - 1) || !list->len)
        list->last = list->first;

    return removed_item;
}

Item lk_get(LinkedList list, size_t pos) {
    if (pos >= list->len)
        return ERR_INVALID_POSITION;

    return lk_get_node(list, pos)->item;
}

Boolean lk_substitute(LinkedList list, Item subs_item, size_t pos) {
    if (pos >= list->len)
        return False;

    lk_get_node(list, pos)->item = subs_item;

    return True;
}

void lk_print(LinkedList list, void (*print_item)(Item item), void (*print_first)(Item item), void (*print_last)(Item item)) {
    LinkedListNode* node = list->first;
    if (!node)
        return;
    if (!node->next) {
        print_last(node->item);
        return;
    }

    print_first(node->item);
    for (node = node->next; node->next; node = node->next)
        print_item(node->item);
    print_last(node->item);
}

#endif //C_LINKEDLIST_H
