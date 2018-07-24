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

    bool insert(const T& data, Node* node) {
        if (data < node->data) {
            if (node->left) {
                return insert(data, node->left);
            }
            node->left = new Node(data);
            return true;
        } else if (node->data < data) {
            if (node->rigth) {
                return insert(data, node->rigth);
            }
            node->rigth = new Node(data);
            return true;
        }
        return false;
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

    Node* findRigthMostChildren(Node* node) {
        while(node->rigth) {
            node = node->rigth;
        }
        return node; 
    }

    void remove(Node* node) {
        if (!node->left && !node->rigth) delete node;
        Node* newValue = node->left ? findRigthMostChildren(node->left) : node->rigth;
        node->data = newValue->data;
        remove(newValue);
    }

  public:
    BinarySearchTree() {}
    ~BinarySearchTree() { clear(); }

    void clear() {
        clear(m_root);
    }

    // Future: return iterator
    bool insert(const T& data) {
        if (!m_root) {
            Node* n = new Node(data);
            m_root = n;
            return true;
        } 
        return insert(data, m_root);
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

    bool remove(const T& data) {
        Node* node = find(data, m_root);
        if (!node) return false;
        remove(node);
        return true;
    }

  private:
    Node* m_root = nullptr;
};

int main() {
    return 0;
}
