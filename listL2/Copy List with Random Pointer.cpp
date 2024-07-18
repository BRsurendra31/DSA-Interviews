class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> copies;

        Node* h = head;

        // 1st iteration to create map of nodes to new nodes
        while (h) {
            copies[h] = new Node(h->val);
            h = h->next;
        }

        h = head;

        // 2nd iteration to construct new list based on mapped copied nodes
        while (h) {
            Node* new_node = copies[h];
            
            new_node->next = copies[h->next];
            new_node->random = copies[h->random];

            h = h->next;
        }

        return copies[head];
    }
 
};

