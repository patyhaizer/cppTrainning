#include<iostream>
#include<stack>

template<class T>
class BinarySearchTree {
    struct Node {
        Node(const T& data) : m_data(data) {}
        T  m_data;
        Node* m_left = nullptr;
        Node* m_rigth = nullptr;
    };

    void clear(Node* node) {
        if (!node) return;
        if (node->m_left) clear(node->m_left);
        if (node->m_rigth) clear(node->m_rigth);
        delete node;
    }

    Node* insert(const T& data, Node* node) {
        if (!node) return new Node(data);
        if (data < node->m_data) node->m_left = insert(data, node->m_left);
        else if (node->m_data < data) node->m_rigth = insert(data, node->m_rigth);
        return node;
    }

    Node* find(const T& data, Node* node) {
        if (!node) return nullptr;
        if (data < node->m_data) return find(data, node->m_left);
        if (node->m_data < data) return find(data, node->m_rigth);
        return node;
    }

    void print(Node* node) {
        if (!node) return;
        print(node->m_left);
        print(node->m_rigth);
        std::cout << node->m_data << " ";
    }

    Node* findMin(Node* node) {
        while(node->m_rigth) {
            node = node->m_rigth;
        }
        return node; 
    }

    Node* remove(const T& data, Node* node) {
        if (!node) return nullptr;
        if (node->m_data < data) node->m_rigth = remove(data, node->m_rigth);
        else if (data < node->m_data) node->m_left = remove(data, node->m_left);
        else {
            // Found node to be removed
            if (!node->m_left && !node->m_rigth) {
                delete node;
                return nullptr;
            }
            if (!node->m_left) {
                Node* tmp = node;
                node = tmp->m_rigth;
                delete tmp;
            } else if (!node->m_rigth) {
                Node* tmp = node;
                node = tmp->m_left;
                delete tmp;
            } else {
                Node* min = findMin(node->m_rigth);
                node->m_data = min->m_data;
                node->m_rigth = remove(min->m_data, min);
            }
        }
        return node;
    }

  public:
    BinarySearchTree() {}
    ~BinarySearchTree() { clear(); }

    void clear() {
        clear(m_root);
    }

    // Future: return iterator
    void insert(const T& data) {
        if (!m_root) {
            Node* n = new Node(data);
            m_root = n;
        } 
        insert(data, m_root);
    }

    // Future: return iterator
    bool find(const T& data) {
        return find(data, m_root);
    }

    void print() {
        print(m_root);
        if (m_root) {
            std::cout << std::endl;
        }
    }

    void remove(const T& data) {
        remove(data, m_root);
    }

    bool empty() {
        return m_root;    
    }

  private:
    Node* m_root = nullptr;

    class Iterator {
      public:
        friend BinarySearchTree;
        Iterator& operator++() {
            if (m_next.empty()) return *this;
            m_next.pop();
            if (m_current->m_rigth) {
                m_current = getNextMin(m_current->m_rigth);
            }
            m_current = m_next.empty() ? nullptr : m_next.top();
            return *this;
        }

        bool hasNext() {
            if (!m_current) return false;
            Node* tmp = m_next.top();
            m_next.pop();
            bool ret = !m_next.empty() || tmp->m_left;
            m_next.push(tmp);
            return ret;
        }

        bool operator==(Iterator rhs) {
            return m_current == rhs.m_current;
        }

        bool operator!=(Iterator rhs) {
            return m_current != rhs.m_current;
        }

        Iterator& operator=(Iterator other) {
            m_current = other.current;
            m_next = other.next;
            return *this;
        }

        T& operator*() {
            return m_current->m_data;
        }

        T* operator->() {
            return &m_current->m_data;
        }

      private:
        Iterator(Node* root) {
            m_current = getNextMin(root);
        }

        Node* getNextMin(Node* root) {
            if (!root) return nullptr;
            while (root) {
                m_next.push(root);
                root = root->m_left;
            }
            return m_next.top();
        }

        Node* m_current;
        std::stack<Node*> m_next;
  };
  public:
    Iterator begin() {
        return Iterator(m_root);
    }

    Iterator end() {
        return Iterator(nullptr);
    }

};

int main() {
    BinarySearchTree<int> tree;
    std::cout << "Tree is empty? " << tree.empty() << std::endl;
    tree.insert(20);
    tree.insert(13);
    tree.insert(45);
    tree.insert(5);
    tree.insert(34);
    tree.print();
    tree.remove(34);
    std::cout << "remove 34" << std::endl;
    tree.print();
    std::cout << "has 50? " << tree.find(50) << std::endl;
    std::cout << "has 5? " << tree.find(5) << std::endl;
    BinarySearchTree<int> tree2;
    tree2.insert(5);
    auto end = tree.end();
    std::cout << "Print in order" << std::endl;
    for (auto it = tree.begin(); it != end; ++it) {
        std::cout << *it << " has next? " << it.hasNext() << std::endl;;
    }
    return 0;
}
