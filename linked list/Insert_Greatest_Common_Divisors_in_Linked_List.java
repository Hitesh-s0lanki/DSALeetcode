class ListNode{
    int val;
    ListNode next;
    ListNode(int val){
        this.val = val;
        this.next = null;
    }
    
}

public class Insert_Greatest_Common_Divisors_in_Linked_List {
    static ListNode head = null;
    static ListNode tail = null;

    static public void insertAtTail(int val){
        ListNode temp = new ListNode(val);
        if(head == null){
            head = temp;
        }else{
            tail.next = temp;
        }
        tail = temp;
    }

    static public void print(){
        ListNode temp = head;
        while(temp != null){
            System.out.print(temp.val + "\t");
            temp = temp.next;
        }
        System.out.println();
    }

    

    public static void main(String[] args) {
        insertAtTail(18);
        insertAtTail(6);
        insertAtTail(10);
        insertAtTail(3);

        print();


        class Solution {
            public int GCD(int a, int b){
                while(b != 0){
                    int temp = b;
                    b = a % b;
                    a = temp;
                }
                return a;
            }
            public ListNode insertGreatestCommonDivisors(ListNode head) {
                if(head == null || head.next == null){
                    return head;
                }

                ListNode ptr1 = head;
                ListNode ptr2 = head.next;

                while(ptr2 != null){
                    int gcdValue = GCD(ptr1.val, ptr2.val);
                    ListNode temp = new ListNode(gcdValue);

                    temp.next = ptr1.next;
                    ptr1.next = temp;

                    ptr1 = ptr2;
                    ptr2 = ptr2.next;
                }

                return head;
            }
        }

        Solution s = new Solution();
        s.insertGreatestCommonDivisors(head);

        print();
    }
}