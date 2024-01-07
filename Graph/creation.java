import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;

class Node {
    public int val;
    public List<Node> neighbors;

    Node() {
        this.val = 0;
        this.neighbors = new ArrayList<Node>();
    }

    public Node(int _val) {
        this.val = _val;
        this.neighbors = new ArrayList<Node>();
    }

    public Node(int _val, ArrayList<Node> _neighbors) {
        this.val = _val;
        this.neighbors = _neighbors;
    }
};

public class creation {

    static public Node cloneGraph(Node node) {

        if (node == null)
            return null;

        Node head = new Node(node.val, new ArrayList<>(node.neighbors));

        Map<Node, Boolean> visited = new HashMap<>();

        Queue<Node> queue = new LinkedList<>();
        queue.add(head);

        while (!queue.isEmpty()) {
            Node temp = queue.peek();
            queue.remove();

            for (Node i : temp.neighbors) {
                if (!visited.containsKey(i) || !visited.get(i)) {
                    Node newNode = new Node(i.val, new ArrayList<>(i.neighbors));
                    temp.neighbors.add(newNode);
                    queue.add(i);
                    visited.put(temp, true);
                }
            }
        }

        return node;
    }

    static Node creatingGraph(int[][] adj, int node) {
        Node[] nodes = new Node[node + 1];

        // Initialize nodes
        for (int i = 1; i <= node; i++) {
            nodes[i] = new Node(i);
        }

        // Create edges and add neighbors
        for (int[] edge : adj) {
            int from = edge[0];
            int to = edge[1];

            // Adding bidirectional edges
            nodes[from].neighbors.add(nodes[to]);
            nodes[to].neighbors.add(nodes[from]);
        }

        // Printing the adjacency list representation
        for (int i = 1; i <= node; i++) {
            System.out.print("Node " + i + ": ");
            for (Node neighbor : nodes[i].neighbors) {
                System.out.print(neighbor.val + " ");
            }
            System.out.println();
        }

        return nodes[1];
    }

    public static void main(String[] args) {
        int[][] adj = {
                { 2, 4 },
                { 1, 3 },
                { 2, 4 },
                { 1, 3 }
        };

        int node = 4;

        Node ans = creatingGraph(adj, node);

        Node clone = cloneGraph(ans);

        System.out.println(ans.neighbors);
        System.out.println(clone.neighbors);
    }
}