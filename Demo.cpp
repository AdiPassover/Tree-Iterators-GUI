// 326627635 | adi.peisach@gmail.com

#include "Screen.hpp"
#include <string>

using namespace std;

void demonstrateTree();

int main() {
//    demonstrateTree();
    cout << "Binary tree:" << endl;
    Tree<double> tree; // Binary tree that contains doubles.

    tree.addRoot(1.1);
    tree.addSubNode(1.1, 1.2);
    tree.addSubNode(1.1, 1.3);
    tree.addSubNode(1.2, 1.4);
    tree.addSubNode(1.2, 1.5);
    tree.addSubNode(1.3, 1.6);
    tree.addSubNode(1.4, 1.7);

    for (auto& node : tree) {
        cout << *node << " ";
    } cout << endl;
    for (auto node = tree.beginBFS(); node != tree.endBFS(); ++node) {
        cout << **node << " ";
    } cout << endl;
    for (auto node = tree.beginDFS(); node != tree.endDFS(); ++node) {
        cout << **node << " ";
    } cout << endl;
    for (auto node = tree.beginPostOrder(); node != tree.endPostOrder(); ++node) {
        cout << **node << " ";
    } cout << endl;

    tree.display();
    tree.toHeap();
    tree.display();

    Tree<unsigned int, 3> three_ary_tree; // 3-ary tree.
    three_ary_tree.addRoot(1);
    three_ary_tree.addSubNode(1, 2);
    three_ary_tree.addSubNode(1, 3);
    three_ary_tree.addSubNode(1, 4);
    three_ary_tree.addSubNode(2, 5);
    three_ary_tree.addSubNode(2, 51);
    three_ary_tree.addSubNode(2, 52);
    three_ary_tree.addSubNode(3, 6);

//    three_ary_tree.display();

    Tree<string, 3> three_ary_tree2; // 3-ary tree.
    three_ary_tree2.addRoot("1");
    three_ary_tree2.addSubNode("1", "2");
    three_ary_tree2.addSubNode("1", "3");
    three_ary_tree2.addSubNode("1", "4");
    three_ary_tree2.addSubNode("2", "5");
    three_ary_tree2.addSubNode("2", "51");
    three_ary_tree2.addSubNode("2", "52");
    three_ary_tree2.addSubNode("3", "6");

//    three_ary_tree2.display();

    return 0;
}


void demonstrateTree() {
    cout << "Binary tree:" << endl;
    Tree<double> tree; // Binary tree that contains doubles.

    tree.addRoot(1.1);
    tree.addSubNode(1.1, 1.2);
    tree.addSubNode(1.1, 1.3);
    tree.addSubNode(1.2, 1.4);
    tree.addSubNode(1.2, 1.5);
    tree.addSubNode(1.3, 1.6);
    tree.addSubNode(1.4, 1.7);

    // The tree should look like:
    /**
     *       root = 1.1
     *     /       \
     *    1.2      1.3
     *   /  \      /
     *  1.4  1.5  1.6
     *  |
     *  1.7
     */

    cout << "Pre order:" << endl;
    for (auto node = tree.beginPreOrder(); node != tree.endPreOrder(); ++node)
    {
        cout << *node << " ";
    } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
    cout << endl;

    cout << "Post order:" << endl;
    for (auto node = tree.beginPostOrder(); node != tree.endPostOrder(); ++node)
    {
        cout << *node << " ";
    } // prints: 1.7, 1.4, 1.5, 1.2, 1.6, 1.3, 1.1
    cout << endl;

    cout << "In order:" << endl;
    for (auto node = tree.beginInOrder(); node != tree.endInOrder(); ++node)
    {
        cout << *node << " ";
    } // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3
    cout << endl;

    cout << "BFS:" << endl;
    for (auto node = tree.beginBFS(); node != tree.endBFS(); ++node)
    {
        cout << *node << " ";
    } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7
    cout << endl;

    cout << "DFS:" << endl;
    for (auto node = tree.beginDFS(); node != tree.endDFS(); ++node)
    {
        cout << *node << " ";
    } // prints: 1.7, 1.4, 1.5, 1.2, 1.6, 1.3, 1.1
    cout << endl;

//    cout << "heap: " << endl;
//    for (auto node : tree)
//    {
//        cout << node.getValue() << endl;
//    } // same as BFS: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7
//    cout << endl;

//    cout << tree; // Should print the graph using GUI.

    cout << "3-ary tree:" << endl;
    Tree<string, 3> three_ary_tree; // 3-ary tree.
    three_ary_tree.addRoot("1");
    three_ary_tree.addSubNode("1", "2");
    three_ary_tree.addSubNode("1", "3");
    three_ary_tree.addSubNode("1", "4");
    three_ary_tree.addSubNode("2", "5");
    three_ary_tree.addSubNode("3", "6");

    // The tree should look like:
    /**
     *       root = 1
     *     /      |     \
     *    2       3      4
     *   /        |
     *  5         6
     */

    cout << "BFS: " << endl;
    for (auto node = three_ary_tree.beginBFS(); node != three_ary_tree.endBFS(); ++node)
    {
        cout << *node << " ";
    } // prints: 1 2 3 4 5 6
    cout << endl;

}