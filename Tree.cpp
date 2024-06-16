#ifndef TREE_ITERATORS_TREE
#define TREE_ITERATORS_TREE

#include <queue>
#include "Node.cpp"

template <typename T, unsigned int D = 2>
class Tree {
private:
    Node<T>* root = nullptr;

public:
    ~Tree() { delete root; }

    void addRoot(T nodeValue);
    void addSubNode(T parentValue, T childValue);

    Node<T>* getRoot() const { return root; }
    unsigned int getDegree() const { return D; }

    class BFSIterator {
        std::queue<Node<T>*> nodeQueue;
    public:
        explicit BFSIterator(Node<T>* root = nullptr) {
            if (root != nullptr)
                nodeQueue.push(root);
        }

        BFSIterator& operator++() {
            if (!nodeQueue.empty()) {
                Node<T>* currNode = nodeQueue.front();
                nodeQueue.pop();
                for (auto& child : *currNode)
                    nodeQueue.push(&child);
            }
            return *this;
        }

        bool operator!=(const BFSIterator& other) const {
            return !nodeQueue.empty() || !other.nodeQueue.empty();
        }

        Node<T>& operator*() const {
            return *nodeQueue.front();
        }
    };

    BFSIterator beginBFS() {
        return BFSIterator(root);
    }

    BFSIterator endBFS() {
        return BFSIterator();
    }

    class DFSIterator {
        std::queue<Node<T>*> nodeQueue;
    public:
        explicit DFSIterator(Node<T>* root = nullptr) {
            if (root != nullptr)
                DFS_Visit(root);
        }

        void DFS_Visit(Node<T>* node) {
            for (auto& child : *node)
                DFS_Visit(&child);
            nodeQueue.push(node);
        }

        DFSIterator& operator++() {
            nodeQueue.pop();
            return *this;
        }

        bool operator!=(const DFSIterator& other) const {
            return !nodeQueue.empty() || !other.nodeQueue.empty();
        }

        Node<T>& operator*() const {
            return *nodeQueue.front();
        }
    };

    DFSIterator beginDFS() {
        return DFSIterator(root);
    }

    DFSIterator endDFS() {
        return DFSIterator();
    }

};

template<typename T, unsigned int D>
void Tree<T, D>::addSubNode(T parentValue, T childValue) {
    Node<T>* parent = nullptr;
    for (auto node = beginBFS(); node != endBFS(); ++node) {
        if (**node == childValue)
            throw std::logic_error("The child node already exists in the tree");
        if (**node == parentValue)
            parent = &(*node);
    }
    if (parent == nullptr)
        throw std::logic_error("The parent node does not exist in the tree");
    parent->addChild(new Node<T>(childValue, D));
}

template<typename T, unsigned int D>
void Tree<T, D>::addRoot(T nodeValue) {
    if (root != nullptr)
        throw std::logic_error("The root of the tree has already been set");
    root = new Node<T>(nodeValue, D);
}

#endif // TREE_ITERATORS_TREE
