#include <iostream>

//template<typename V, template<typename> class N = Node> 
template<typename V> 
class LinkedList {

    // This class represents a node of the linked list
    // It stores the value and the pointer to the next position
    class Node {
      public:
        explicit Node(const V& val) : m_val(val) {}
        const V& getVal() const { return m_val; }
        V& getVal() { return m_val; }
        Node* const getNext() const { return m_next; }
    
        void setVal(const V& val) { m_val = val; }
        void setNext(Node* const next) { m_next = next; }
      private:
        V         m_val;
        Node*     m_next = nullptr;
    };

  public:
    LinkedList() {}
    ~LinkedList() { clear(); }

    bool empty() { return m_head == nullptr; }

    // Methods to remove the elements
    void clear() {
        while(m_head) {
            pop_front();
        }
    }
    void pop_front() {
        if (!empty()) {
            Node* tmp = m_head;
            m_head = m_head->getNext();
            delete tmp;
        }
        if (empty()) {
            m_tail = nullptr;
        }
    }

    // Methods to insert elements in the list
    void insert(const V& val) { push_back(val); }
    void push_back(const V& val) {
        Node* n = new Node(val);
        if (empty()) {
            m_head = n;
            m_tail = n;
        } else {
            m_tail->setNext(n);
            m_tail = n;
        }
    }
    void push_front(const V& val) {
        Node* n = new Node(val);
        if (empty()) {
            m_head = n;
            m_tail = n;
        } else {
            n->setNext(m_head);
            m_head = n;
        }
    }

    // Methods to access elements of the list
    const V& front() {
        return m_head->getVal();
    }
    const V& back() {
        return m_tail->getVal();
    }

    void print() {
        Node* tmp = m_head;
        std::cout << "list content: ";
        while(tmp) {
            std::cout << tmp->getVal() << " ";
            tmp = tmp->getNext();
        }
        std::cout << std::endl;
    }

  private:
    Node* m_head = nullptr;
    Node* m_tail = nullptr;

    // ITERATORS
  public:
    template <bool Const = false>
    class iterator {
      public:
        friend LinkedList;
        iterator& operator=(const iterator& other) {
            m_current = other.m_current;
            return *this;
        }
        iterator& operator++() {
            m_current = m_current->getNext();
            return *this;
        }
        iterator operator++(int) {
            iterator tmp = *this;
            tmp.m_current->getNext();
            return tmp;
        }
        bool operator==(const iterator& rhs) {
            return rhs.m_current = this->m_current;
        }
        bool operator!=(const iterator& rhs) {
            return rhs.m_current != this->m_current;
        }
        V& operator*() {
            return m_current->getVal();    
        }
        V* operator->() {
            return &m_current->getVal();    
        }
      private:
        iterator(Node* n) { m_current = n; }
        Node* m_current;
    };

    iterator<> begin() {
        return iterator<>(m_head);
    }
    iterator<> end() {
        return iterator<>(nullptr);
    }
};

int main() {
    LinkedList<int> test;
    std::cout << "test is empty? " << test.empty() << std::endl;
    std::cout << "insert 2" << std::endl;
    test.insert(2);
    std::cout << "test is empty? " << test.empty() << std::endl;
    test.print();
    test.push_front(3);
    test.print();
    test.push_back(4);
    test.print();
    test.pop_front();
    test.print();
    test.push_back(5);
    std::cout << "outside print" << std::endl;
    LinkedList<int>::iterator<> end = test.end();
    for (LinkedList<int>::iterator<> it = test.begin(); it != end; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    return 0;
}
