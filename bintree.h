/* *************************************************
 *  Name: Aaron Ramirez
 *  Assignment: 8 - Binary Search Tree
 *  Purpose: Declaration of the `BinTree` class for managing
 *           binary search tree operations with attributes and methods.
 ************************************************* */

#ifndef BINTREE_H
#define BINTREE_H

 // Standard Libraries
#include <iostream>
#include <string>

// Local Files
#include "data.h"

using std::cout;
using std::endl;
using std::string;

class BinTree {
public:
    /**********************
     Constructors/Destructor
    ***********************/
    BinTree();                                    // Constructor
    ~BinTree();                                   // Destructor

    /**********************
     Getters/Accessors
    ***********************/
    bool getRootData(Data*) const;                // Retrieve root data
    bool contains(int) const;                     // Check if a node exists
    bool getNode(Data*, int) const;               // Retrieve a node by ID
    int getHeight() const;                        // Get height of the tree
    int getCount() const;                         // Get number of nodes
    bool isEmpty() const;                         // Check if the tree is empty

    /**********************
     Setters/Mutators
    ***********************/
    bool addNode(int, const string*);             // Add a node
    bool removeNode(int);                         // Remove a node
    void clear();                                 // Clear the tree

    /**********************
     Display/Printing Methods
    ***********************/
    void displayTree() const;                     // Display tree statistics
    void displayInOrder() const;                  // Display in-order traversal
    void displayPreOrder() const;                 // Display pre-order traversal
    void displayPostOrder() const;                // Display post-order traversal

private:
    /**********************
     Attributes
    ***********************/
    DataNode* root;                               // Root node of the tree
    int count;                                    // Number of nodes in the tree

    /**********************
     Private Recursive Methods
    ***********************/
    bool addNode(DataNode*&, int, const string*); // Add node recursively
    DataNode* removeNode(DataNode*, int);         // Remove node recursively
    bool getNode(DataNode*, Data*, int) const;    // Retrieve node recursively
    bool contains(DataNode*, int) const;          // Check if node exists recursively
    int getHeight(DataNode*) const;               // Calculate height recursively
    void displayInOrder(DataNode*) const;         // In-order traversal recursively
    void displayPreOrder(DataNode*) const;        // Pre-order traversal recursively
    void displayPostOrder(DataNode*) const;       // Post-order traversal recursively
    void clear(DataNode*&);                       // Clear the tree recursively
    DataNode* findMin(DataNode*) const;           // Find minimum node in the tree
};

#endif // BINTREE_H
