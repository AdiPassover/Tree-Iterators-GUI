// 326627635 | adi.peisach@gmail.com

#ifndef TREE_ITERATORS_NODE_CPP
#define TREE_ITERATORS_NODE_CPP
#include <memory>
#include <vector>
#include <stdexcept>

using std::unique_ptr;
using std::vector;

template <typename T>
class Node {
    T value;
    vector<unique_ptr<Node<T>>> children;
    unsigned int maxDeg = 0;
    unsigned int currChild = 0;

public:
    Node(T value) : value(value) { children.resize(0); }
    Node(T value, unsigned int degree) : value(value) { setDegree(degree); }
    ~Node() = default;

    void setDegree(unsigned int degree);

    T getValue() const { return value; }
    void setValue(T newValue) { this->value = newValue; }

    void addChild(unique_ptr<Node<T>> child);

    T operator*() const { return value; }

    class Iterator {
        vector<Node<T>*>& children;
        size_t index;
    public:
        explicit Iterator(vector<unique_ptr<Node<T>>>& c, size_t index = 0) : index(index) {
            children.reserve(c.size());
            for (auto& child : c) {
                children.push_back(child.get());
            }
        }

        Iterator& operator++() {
            ++index;
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return index != other.index;
        }

        Node<T>& operator*() const {
            return *children[index];
        }
    };

    Iterator begin() {
        return Iterator(children);
    }

    Iterator end() {
        return Iterator(children, currChild);
    }

};

template<typename T>
void Node<T>::addChild(unique_ptr<Node<T>> child) {
    if (currChild >= maxDeg)
        throw std::out_of_range("The node has reached its maximum degree");
    children[currChild++] = std::move(child);
}

template<typename T>
void Node<T>::setDegree(unsigned int degree) {
    if (maxDeg != 0)
        throw std::logic_error("The degree of the node has already been set");
    maxDeg = degree;
    children.resize(degree);
}


#endif //TREE_ITERATORS_NODE_CPP
