import java.util.LinkedList;

public class addTwoNodes {
	public LinkedList<Integer> addTwoNumbers(LinkedList<Integer> l1, LinkedList<Integer> l2) {
		int carry = 0;
		LinkedList<Integer> l3 = new LinkedList<Integer>();
		while (!l1.isEmpty() || !l2.isEmpty()) {
			int x = l1 != null ? l1.poll() : 0;
			int y = l2 != null ? l2.poll() : 0;
			int sum = carry + x + y;
			carry = sum / 10;
			if (carry == 1) {
				sum = sum % 10;
			}
			l3.add(sum);
			System.out.println("value of l1: " + x + " " + "value of l2: " + y + " " + "Sum of l1 and l2 elements: "
					+ sum + " " + "Carry: " + carry + " " + "Sum after carry==1: " + sum + "");

		}

		return l3;
	}

	public static void main(String[] args) {
		addTwoNodes ob = new addTwoNodes();
		LinkedList<Integer> l1 = new LinkedList<Integer>();
		l1.add(2);
		l1.add(4);
		l1.add(3);
		LinkedList<Integer> l2 = new LinkedList<Integer>();
		l2.add(5);
		l2.add(6);
		l2.add(4);
		System.out.println(l1);
		System.out.println(l2);
		System.out.println(ob.addTwoNumbers(l1, l2));

	}

}
