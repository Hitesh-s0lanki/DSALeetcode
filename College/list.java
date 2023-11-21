class ListNode{
    int val;
    ListNode next;
    ListNode prev;
    ListNode(int val){
        this.val = val;
        this.next = null;
        this.prev = null;
    }
}

class list{
    static ListNode head = null;
    static ListNode tail = null;

    static void insertAtTail(int val){
        ListNode temp = new ListNode(val);
        if(head == null){
            head = temp;
        }else{
            tail.next =temp;
            temp.prev = tail;
        }
        tail = temp;
    }

    static void insertAtHead(int val){
        ListNode temp = new ListNode(val);
        if(head == null){
            tail = temp;
        }else{
            temp.next = head;
            head.prev = temp;
        }
        head = temp;
    }

    static void print(){
        ListNode ptr = head;
        while(ptr != null){
            System.out.print(ptr.val+"\t");
            ptr = ptr.next;
        }
        System.out.println();
    }

    static int length(){
        if(head == null) return 0;

        ListNode ptr = head;
        int cnt = 0;

        while(ptr != null){
            cnt++;
            ptr = ptr.next;
        }
        return cnt;
    }

    //after a particular data
    static void particularData(int val,int data){
        ListNode ptr = head;
        while(ptr.val != data && ptr != null){
            ptr = ptr.next;
        }

        if(ptr != null){
            ListNode temp = new ListNode(val);
    
            temp.next = ptr.next;
            ptr.next = temp;

            if(temp.next == null){
                tail = temp;
            }
        }
    }

    static void insertAtParticularPosition(int val,int position){
        if(position == 1){
            insertAtHead(val);
        }else if(position == length() + 1){
            insertAtTail(val);
        }else{
            ListNode ptr = head;
    
            while(position != 2 && ptr != null){
                ptr = ptr.next;
                position--;
            }

            if(ptr != null){
                ListNode temp = new ListNode(val);
        
                temp.next = ptr.next;
                ptr.next = temp;

                
            }
        }
    }

    public static void main(String[] args) {
        insertAtTail(1);
        insertAtTail(4);
        insertAtTail(3);
        insertAtParticularPosition(0, 3);
        particularData(10, 0);
        print();
    }
}