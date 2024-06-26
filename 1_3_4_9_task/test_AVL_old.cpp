#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "AVL.hpp"

using namespace std;

TEST(UnitTest, start_empty) {
    AVLTree tree;
    ASSERT_TRUE(tree.isEmpty());
}

TEST(UnitTest, correct_insert) {
    AVLTree tree;
    tree.insert(7);
    tree.insert(8);
    tree.insert(9);
    tree.insert(10);
    tree.insert(11);
    tree.insert(12);
    ASSERT_TRUE(tree.isBalanced());
}

TEST(UnitTest, correct_remove) {
    AVLTree tree;
    tree.insert(7);
    tree.insert(8);
    tree.insert(9);
    tree.insert(10);
    tree.insert(11);
    tree.insert(12);
    ASSERT_TRUE(tree.isBalanced());
    tree.remove(10);
    ASSERT_TRUE(tree.isBalanced());
}

TEST(UnitTest, correct_find) {
    AVLTree tree;
    int a = 10;
    tree.insert(a);
    tree.insert(8);
    tree.insert(9);
    tree.insert(7);
    ASSERT_TRUE(tree.find(a));
}


TEST(UnitTest, find_not_exist_elem) {
    AVLTree tree;
    int a = 11;
    tree.insert(7);
    tree.insert(8);
    tree.insert(9);
    tree.insert(10);
    ASSERT_FALSE(tree.find(a));
}


TEST(UnitTest, remove_not_exist_elem) {
    AVLTree tree;
    tree.insert(7);
    tree.remove(8);
    ASSERT_TRUE(tree.isBalanced());
}

TEST(UnitTest, copy_constructor_diff_tree) {
    AVLTree tree;
    tree.insert(7);
    tree.insert(8);
    AVLTree tree_1(tree);
    tree_1.insert(9);

    ASSERT_FALSE(tree.find(9));
    ASSERT_TRUE(tree_1.find(9));
}

TEST(UnitTest, copy_constructor_diff_tree_remove_elem) {
    AVLTree tree;
    tree.insert(7);
    tree.insert(8);
    tree.insert(9);
    AVLTree tree_1(tree);
    tree.remove(7);
 
    ASSERT_TRUE(tree_1.find(7));
    ASSERT_FALSE(tree.find(7));
}


TEST(UnitTest, copy_assignment_operator_diff_tree) {
    AVLTree tree;
    AVLTree tree_1;
    tree.insert(7);
    tree.insert(8);
    tree_1.insert(9);
    tree_1.insert(10);
    tree_1 = tree;
    tree_1.insert(11);

    ASSERT_TRUE(tree_1.find(7));
    ASSERT_TRUE(tree_1.find(8));
    ASSERT_FALSE(tree_1.find(9));

    ASSERT_TRUE(tree_1.find(11));
    ASSERT_FALSE(tree.find(11));
}

TEST(UnitTest, move_constructor) { 
    AVLTree tree;
    tree.insert(1);
    tree.insert(2);
    AVLTree tree_1(std::move(tree));
    ASSERT_TRUE(tree_1.find(2));
}


TEST(UnitTest, move_assignment_operator) { 
    AVLTree tree;
    tree.insert(1);
    tree.insert(2);
    AVLTree tree_1;
    tree_1.insert(3);
    tree_1 = std::move(tree);
    ASSERT_TRUE(tree_1.find(2));
    ASSERT_FALSE(tree_1.find(3));
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}