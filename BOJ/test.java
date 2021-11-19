import java.util.LinkedList;
import java.util.ListIterator;

class Test {
    public static void main(String[] args) {
        LinkedList<String> li = new LinkedList<>();

        li.add("a");
        li.add("b");

        ListIterator<String> list = li.listIterator();
        while(list.hasNext()) {
            System.out.println(list.nextIndex());
            System.out.println(list.next());
            System.out.println(list.nextIndex());
            System.out.println("dd");
        }

        while(list.hasPrevious()) {
            System.out.println(list.previous());
        }
    }
}