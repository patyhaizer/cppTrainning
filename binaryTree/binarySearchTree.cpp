#include<iostream>

template<class T>
class BinarySearchTree {
    struct Node {
        Node(const T& data) : m_data(data) {}
        T  m_data;
        T* m_left = nullptr;
        T* m_rigth = nullptr;
    };

    void clear(Node* node) {
        if (node->m_left) clear(node->m_left);
        if (node->m_rigth) clear(node->m_rigth);
        delete node;
    }

    Node* insert(const T& data, Node* node) {
        if (!node) return new Node(data);
        if (data < node->data) node->left = insert(data, node->left);
        else if (node->data < data) node->rigth = insert(data, node->rigth);
        return node;
    }

    Node* find(const T& data, Node* node) {
        if (!node) return nullptr;
        if (data < node->data) return find(data, node->left);
        if (node->data < data) return find(data, node->rigth);
        return node;
    }

    void print(Node* node) {
        if (!node) return;
        print(node->left);
        print(node->rigth);
        std::cout << node->data << " ";
    }

    Node* findMin(Node* node) {
        while(node->rigth) {
            node = node->rigth;
        }
        return node; 
    }

    Node* remove(const T& data, Node* node) {
        if (!node) return nullptr;
        if (node->data < data) node->rigth = remove(data, node->rigth);
        else if (data < node->data) node->left = remove(data, node->left);
        else {
            // Found node to be removed
            if (!node->left && !node->rigth) {
                delete node;
                return nullptr;
            }
            if (!node->left) {
                Node* tmp = node;
                node = tmp->rigth;
                delete tmp;
            } else if (!node->rigth) {
                Node* tmp = node;
                node = tmp->left;
                delete tmp;
            } else {
                Node* min = findMin(node->rigth);
                node->data = min->data;
                node->right = remove(min->data, min);
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

  private:
    Node* m_root = nullptr;
};

int main() {
    return 0;
}
