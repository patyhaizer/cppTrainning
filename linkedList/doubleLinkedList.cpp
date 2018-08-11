class MyLinkedList {
private:
    struct Node {
        int m_val;
        Node* m_next = nullptr;
        Node* m_prev = nullptr;

        Node(int val) : m_val(val) {}
    };
public:
    /** Initialize your data structure here. */
    MyLinkedList() {}
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        Node* n = m_head;
        while (index > 0 && n) {
            n = n->m_next;
            index--;
        }
        if (n) {
            return n->m_val;
        }
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* n = new Node(val);
        if (!m_head) {
            m_head = n;
            m_tail = n;
        } else {
            n->m_next = m_head;
            m_head->m_prev = n;
            m_head = n;
        }
        m_size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* n = new Node(val);
        if (!m_head) {
            m_head = n;
            m_tail = n;
        } else {
            n->m_prev = m_tail;
            m_tail->m_next = n;
            m_tail = n;
        }
        m_size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index == 0) {
            return addAtHead(val);
        } else if (index == m_size) {
            return addAtTail(val);
        }
        Node* n = m_head;
        while (index > 0 && n) {
            n = n->m_next;
            index--;
        }
        if (n) {
            Node* newNode = new Node(val);
            newNode->m_prev = n->m_prev;
            newNode->m_next = n;
            n->m_prev->m_next = newNode;
            n->m_prev = newNode;
            m_size++;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        Node* n = m_head;
        while (index > 0 && n) {
            n = n->m_next;
            index--;
        }
        if (n) {
            if (n == m_head) {
                n->m_next->m_prev = nullptr;
                m_head = n->m_next;
            }  else if (n == m_tail) {
                n->m_prev->m_next = nullptr;
                m_tail = n->m_prev;
            } else {
                n->m_prev->m_next = n->m_next;
                n->m_next->m_prev = n->m_prev;
            }
            delete n;
            m_size--;
        }
    }
private:
    Node* m_head = nullptr;
    Node* m_tail = nullptr;
    unsigned int m_size = 0;
};

int main() {
    return 0;
}

