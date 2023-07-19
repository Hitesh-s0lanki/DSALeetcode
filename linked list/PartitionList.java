public class PartitionList {
    public class ListNode{
        public int val;
        public ListNode next;
        ListNode(int val){
            this.val = val;
            this.next = null;
        }
    }
    public static void insertAtTail(ListNode head,ListNode tail,int val){
        PartitionList p = new PartitionList();
        ListNode temp = p.new ListNode(val);
        if(head == null){
            head = temp;
            tail = temp;
            return;
        }
        tail.next = temp;
        tail = temp;
    }
    public static void print(ListNode head){
        ListNode temp = head;
        while(temp != null)
            System.out.print(temp.val);
        
        System.out.println();
    }
    public ListNode partition(ListNode head, int x) {
        return head;
    }
    public static void main(String[] args) {
        ListNode head = null;
        ListNode tail = null;
        insertAtTail(head, tail, 1);
        insertAtTail(head, tail, 2);
        insertAtTail(head, tail, 3);
        print(head);
    }
}