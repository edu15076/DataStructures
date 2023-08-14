package DataStructures;

public class Main {
    public static void main(String[] args) {

        DoublyLinkedList<Long> lk = new DoublyLinkedList<>(10L, 11L, 12L, 13L, 14L, 15L, 16L, 17L, 18L, 19L);

        System.out.println(lk);


        ListIterator<Long> li = lk.iterator(lk.size());
        while (li.hasPrevious()) {
            System.out.println(li.previous() + " " + li.index());
            System.out.println(li.next());
            li.previous();
        }
        System.out.println(lk);
    }
}
