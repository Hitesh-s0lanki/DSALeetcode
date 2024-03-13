import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

class ListNode {
    public int val;
    public ListNode next;

    ListNode(int val) {
        this.val = val;
        this.next = null;
    }
}

public class RemoveZeroSumConsecutiveNodesfromLinkedList {

    static ListNode head = null;
    static ListNode tail = null;

    public ListNode solve(ListNode head) {

        boolean found = true;

        while (found) {
            found = false;

            // pointer
            ListNode ptr = head;

            ListNode startNode = null;
            ListNode endNode = null;

            int sum = 0;
            int maxLen = 0;
            Map<Integer, Integer> mapSum = new HashMap<>();
            Map<Integer, ListNode> mapNode = new HashMap<>();

            for (int i = 0; ptr != null; i++, ptr = ptr.next) {
                sum += ptr.val;

                if (sum == 0) {
                    found = true;
                    maxLen = Math.max(maxLen, i + 1);
                    startNode = head;
                    endNode = ptr;
                }

                if (mapSum.containsKey(sum)) {
                    found = true;
                    if (i - mapSum.get(sum) > maxLen) {
                        maxLen = i - mapSum.get(sum);
                        startNode = mapNode.get(sum);
                        endNode = ptr;
                    }
                } else {
                    mapSum.put(sum, i);
                    mapNode.put(sum, ptr);
                }
            }

            if (startNode != null && endNode != null) {
                sum = 0;
                ListNode check = startNode;

                while (check != endNode) {
                    sum += check.val;
                    check = check.next;
                }

                if (startNode == head && sum + endNode.val == 0) {
                    head = endNode.next;
                } else {
                    startNode.next = endNode.next;
                }
            }
        }

        return head;
    }

    public ListNode removeZeroSumSublists(ListNode head) {

        return solve(head);
    }

    static void insertAtTail(int val) {
        ListNode temp = new ListNode(val);
        if (head == null) {
            head = temp;
        } else {
            tail.next = temp;
        }
        tail = temp;
    }

    static void print(ListNode head) {
        ListNode ptr = head;
        while (ptr != null) {
            System.out.print(ptr.val + "\t");
            ptr = ptr.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int arr[] = { 1, 2, -3, 3, 1 };

        for (int i : arr) {
            insertAtTail(i);
        }

        RemoveZeroSumConsecutiveNodesfromLinkedList obj = new RemoveZeroSumConsecutiveNodesfromLinkedList();

        print(obj.removeZeroSumSublists(head));
    }
}