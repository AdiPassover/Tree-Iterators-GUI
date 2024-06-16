// 326627635 | adi.peisach@gmail.com
/**
 * Demo app for Ex4
 */
#include "Tree.cpp"

using namespace std;

int main()
{

    cout << "started demo" << endl;
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

//    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node)
//    {
//        cout << *node << endl;
//    } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6

//    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
//    {
//        cout << node->getValue() << endl;
//    } // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1
//
//    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
//    {
//        cout << node->getValue() << endl;
//    } // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3

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

//    for (auto node : tree)
//    {
//        cout << node.getValue() << endl;
//    } // same as BFS: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
//
//    cout << tree; // Should print the graph using GUI.
//
//    Tree<double,3> three_ary_tree; // 3-ary tree.
//    three_ary_tree.addRoot(root_node);
//    three_ary_tree.addSubNode(root_node, n1);
//    three_ary_tree.addSubNode(root_node, n2);
//    three_ary_tree.addSubNode(root_node, n3);
//    three_ary_tree.addSubNode(n1, n4);
//    three_ary_tree.addSubNode(n2, n5);
//
//    // The tree should look like:
//    /**
//     *       root = 1.1
//     *     /      |     \
//     *    1.2    1.3    1.4
//     *   /        |
//     *  1.5      1.6
//     */

    return 0;
}