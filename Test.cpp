// 326627635 | adi.peisach@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Screen.hpp"

TEST_CASE("Test BFS") {

    Tree<double> tree;

    tree.addRoot(1.1);
    tree.addSubNode(1.1, 1.2);
    tree.addSubNode(1.1, 1.3);
    tree.addSubNode(1.2, 1.4);
    tree.addSubNode(1.2, 1.5);
    tree.addSubNode(1.3, 1.6);
    tree.addSubNode(1.4, 1.7);

    vector<double> bfs1;
    for (auto node = tree.beginBFS(); node != tree.endBFS(); ++node) {
        bfs1.push_back(**node);
    }
    vector<double> expected1 = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7};
    CHECK((bfs1 == expected1));

    Tree<unsigned int, 4> tree2;

    tree2.addRoot(1);
    tree2.addSubNode(1, 2);
    tree2.addSubNode(1, 3);
    tree2.addSubNode(1, 4);
    tree2.addSubNode(2, 5);
    tree2.addSubNode(2, 51);
    tree2.addSubNode(2, 52);
    tree2.addSubNode(3, 6);

    vector<unsigned int> bfs2;
    for (auto node = tree2.beginBFS(); node != tree2.endBFS(); ++node) {
        bfs2.push_back(**node);
    }
    vector<unsigned int> expected2 = {1, 2, 3, 4, 5, 51, 52, 6};
    CHECK((bfs2 == expected2));

}

TEST_CASE("Test DFS") {

    Tree<double> tree;

    tree.addRoot(1.1);
    tree.addSubNode(1.1, 1.2);
    tree.addSubNode(1.1, 1.3);
    tree.addSubNode(1.2, 1.4);
    tree.addSubNode(1.2, 1.5);
    tree.addSubNode(1.3, 1.6);
    tree.addSubNode(1.4, 1.7);

    vector<double> dfs1;
    for (auto node = tree.beginDFS(); node != tree.endDFS(); ++node) {
        dfs1.push_back(**node);
    }
    vector<double> expected1 = {1.7, 1.4, 1.5, 1.2, 1.6, 1.3, 1.1};
    CHECK((dfs1 == expected1));

    Tree<unsigned int, 4> tree2;

    tree2.addRoot(1);
    tree2.addSubNode(1, 2);
    tree2.addSubNode(1, 3);
    tree2.addSubNode(1, 4);
    tree2.addSubNode(2, 5);
    tree2.addSubNode(2, 51);
    tree2.addSubNode(2, 52);
    tree2.addSubNode(3, 6);

    vector<unsigned int> dfs2;
    for (auto node = tree2.beginDFS(); node != tree2.endDFS(); ++node) {
        dfs2.push_back(**node);
    }
    vector<unsigned int> expected2 = {5, 51, 52, 2, 6, 3, 4, 1};
    CHECK((dfs2 == expected2));

}

TEST_CASE("Test Preorder") {

    Tree<double> tree1;

    tree1.addRoot(1.1);
    tree1.addSubNode(1.1, 1.2);
    tree1.addSubNode(1.1, 1.3);
    tree1.addSubNode(1.2, 1.4);
    tree1.addSubNode(1.2, 1.5);
    tree1.addSubNode(1.3, 1.6);
    tree1.addSubNode(1.4, 1.7);

    vector<double> preorder1;
    for (auto node = tree1.beginPreOrder(); node != tree1.endPreOrder(); ++node) {
        preorder1.push_back(**node);
    }
    vector<double> expected1 = {1.1, 1.2, 1.4, 1.7, 1.5, 1.3, 1.6};
    CHECK((preorder1 == expected1));

    Tree<unsigned int, 4> tree2;

    tree2.addRoot(1);
    tree2.addSubNode(1, 2);
    tree2.addSubNode(1, 3);
    tree2.addSubNode(1, 4);
    tree2.addSubNode(2, 5);
    tree2.addSubNode(2, 51);
    tree2.addSubNode(2, 52);
    tree2.addSubNode(3, 6);

    vector<unsigned int> preorder2;
    for (auto node = tree2.beginPreOrder(); node != tree2.endPreOrder(); ++node) {
        preorder2.push_back(**node);
    }
    vector<unsigned int> expected2 = {5, 51, 52, 2, 6, 3, 4, 1}; // same as DFS
    CHECK((preorder2 == expected2));

}

TEST_CASE("Test Inorder") {

    Tree<double> tree1;

    tree1.addRoot(1.1);
    tree1.addSubNode(1.1, 1.2);
    tree1.addSubNode(1.1, 1.3);
    tree1.addSubNode(1.2, 1.4);
    tree1.addSubNode(1.2, 1.5);
    tree1.addSubNode(1.3, 1.6);
    tree1.addSubNode(1.4, 1.7);

    vector<double> inorder1;
    for (auto node = tree1.beginInOrder(); node != tree1.endInOrder(); ++node) {
        inorder1.push_back(**node);
    }
    vector<double> expected1 = {1.7, 1.4, 1.2, 1.5, 1.1, 1.6, 1.3};
    CHECK((inorder1 == expected1));

    Tree<unsigned int, 4> tree2;

    tree2.addRoot(1);
    tree2.addSubNode(1, 2);
    tree2.addSubNode(1, 3);
    tree2.addSubNode(1, 4);
    tree2.addSubNode(2, 5);
    tree2.addSubNode(2, 51);
    tree2.addSubNode(2, 52);
    tree2.addSubNode(3, 6);

    vector<unsigned int> inorder2;
    for (auto node = tree2.beginInOrder(); node != tree2.endInOrder(); ++node) {
        inorder2.push_back(**node);
    }
    vector<unsigned int> expected2 = {5, 51, 52, 2, 6, 3, 4, 1}; // same as DFS
    CHECK((inorder2 == expected2));

}

TEST_CASE("Test Postorder") {

    Tree<double> tree1;

    tree1.addRoot(1.1);
    tree1.addSubNode(1.1, 1.2);
    tree1.addSubNode(1.1, 1.3);
    tree1.addSubNode(1.2, 1.4);
    tree1.addSubNode(1.2, 1.5);
    tree1.addSubNode(1.3, 1.6);
    tree1.addSubNode(1.4, 1.7);

    vector<double> postorder1;
    for (auto node = tree1.beginPostOrder(); node != tree1.endPostOrder(); ++node) {
        postorder1.push_back(**node);
    }
    vector<double> expected1 = {1.7, 1.5, 1.4, 1.6, 1.3, 1.2, 1.1};
    CHECK((postorder1 == expected1));

}