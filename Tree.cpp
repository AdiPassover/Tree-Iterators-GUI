// 326627635 | adi.peisach@gmail.com

#ifndef TREE_ITERATORS_TREE_CPP
#define TREE_ITERATORS_TREE_CPP

#include <queue>
#include "Node.cpp"

template <typename T, unsigned int D = 2>
class Tree {
private:
    unique_ptr<Node<T>> root = nullptr;
    unsigned int currChild = 0;

public:
    void addRoot(Node<T>& node);
    void addSubNode(Node<T>& parent, Node<T>& child);

    Node<T> getRoot() const { return root; }
    unsigned int getDegree() const { return D; }

    class PreOrderIterator {
    };

    class PostOrderIterator {
    };

    class InOrderIterator {

    };

    class BFSIterator {
        std::queue<Node<T>*> nodeQueue;
    public:
        explicit BFSIterator(Node<T>* root = nullptr) {
            if (root != nullptr)
                nodeQueue.push(root);
        }

        BFSIterator& operator++() {
            if (!nodeQueue.empty()) return *this;
            Node<T>* currNode = nodeQueue.front();
            nodeQueue.pop();
            for (auto& child : currNode->begin())
                nodeQueue.push(&child);
            return *this;
        }

        bool operator!=(const BFSIterator& other) const {
            return !nodeQueue.empty() || !other.nodeQueue.empty();
        }

        Node<T>& operator*() const {
            return *nodeQueue.front();
        }
    };

    class DFSIterator {
    };

    BFSIterator beginBFSScan() {
        return BFSIterator(root.get());
    }
    BFSIterator endBFSScan() {
        return BFSIterator();
    }

};



template<typename T, unsigned int D>
void Tree<T, D>::addSubNode(Node<T>& parent, Node<T>& child) {
    parent.addChild(std::make_unique<Node<T>>(child)); // TODO check if parent is in the tree?
}

template<typename T, unsigned int D>
void Tree<T, D>::addRoot(Node<T>& node) {
    if (root != nullptr)
        throw std::logic_error("The root of the tree has already been set");
    root = std::make_unique<Node<T>>(node.getValue(), D);
}


#endif //TREE_ITERATORS_TREE_CPP
