/* *************************************************
 *  Name: Aaron Ramirez
 *  Assignment: Practice Assignment 8 - Binary Search Tree
 *  Purpose: Implementation of the `BinTree` class
 *           for binary search tree operations.
 ************************************************* */

#include "bintree.h"

// Constructor
BinTree::BinTree() : root(nullptr), count(0) {
    /* **************************
     * Default constructor initializes
     * the binary search tree to an empty
     * state with a null root and a count of 0.
     *
     * @param none
     * @exception none
     * @return void
     ****************************/ 
}

// Destructor
BinTree::~BinTree() {
    /* **************************
     * Destructor ensures that all dynamically
     * allocated nodes are properly deleted by
     * calling the clear() method.
     *
     * @param none
     * @exception none
     * @return void
     ****************************/ 
    clear();
}

// Public Methods

bool BinTree::addNode(int id, const string* info) {
    /* **************************
     * Adds a node with the given ID and
     * information string to the binary search tree.
     * Increments the count if the node is added.
     *
     * @param int : the ID of the node to add
     * @param const string* : pointer to the information string
     * @exception none
     * @return bool : true if the node was added, false otherwise
     ****************************/ 
    bool added = addNode(root, id, info);
    if (added) {
        count++;
    }
    return added;
}

bool BinTree::removeNode(int id) {
    /* **************************
     * Removes a node with the given ID
     * from the binary search tree. Decrements
     * the count if the node is removed.
     *
     * @param int : the ID of the node to remove
     * @exception none
     * @return bool : true if the node was removed, false otherwise
     ****************************/ 
    bool removed = false;
    int initialCount = count;
    root = removeNode(root, id);
    if (count < initialCount) {
        removed = true;
    }
    return removed;
}

bool BinTree::getRootData(Data* data) const {
    /* **************************
     * Retrieves the data stored in the root
     * node of the tree. If the tree is empty,
     * the Data object is set to default values.
     *
     * @param Data* : pointer to a Data object
     *                to store the retrieved data
     * @exception none
     * @return bool : true if root data is retrieved, false otherwise
     ****************************/ 
    bool hasRoot = false;
    if (root != nullptr) {
        *data = root->data;
        hasRoot = true;
    } else {
        data->id = -1;
        data->information = "";
    }
    return hasRoot;
}

bool BinTree::contains(int id) const {
    /* **************************
     * Checks whether a node with the
     * specified ID exists in the binary search tree.
     *
     * @param int : the ID to search for
     * @exception none
     * @return bool : true if the node exists, false otherwise
     ****************************/ 
    bool found = contains(root, id);
    return found;
}

bool BinTree::getNode(Data* data, int id) const {
    /* **************************
     * Retrieves a node with the specified
     * ID from the binary search tree. If the
     * node is found, its data is stored in the
     * provided Data object.
     *
     * @param Data* : pointer to a Data object to store the retrieved data
     * @param int : the ID of the node to retrieve
     * @exception none
     * @return bool : true if the node was found, false otherwise
     ****************************/ 
    bool found = getNode(root, data, id);
    return found;
}

int BinTree::getHeight() const {
    /* **************************
     * Calculates the height of the binary
     * search tree. The height is dynamically
     * calculated each time this method is called.
     *
     * @param none
     * @exception none
     * @return int : the height of the tree
     ****************************/ 
    int height = getHeight(root);
    return height;
}

int BinTree::getCount() const {
    /* **************************
     * Returns the number of nodes
     * currently stored in the binary search tree.
     *
     * @param none
     * @exception none
     * @return int : the total node count
     ****************************/ 
    return count;
}

bool BinTree::isEmpty() const {
    /* **************************
     * Checks whether the binary search tree
     * is empty.
     *
     * @param none
     * @exception none
     * @return bool : true if the tree is empty, false otherwise
     ****************************/ 
    bool empty = (count == 0);
    return empty;
}

void BinTree::displayTree() const {
    /* **************************
     * Displays the statistics and traversals
     * of the binary search tree, including its
     * height, node count, and traversal results
     * (in-order, pre-order, post-order). Includes
     * whether the tree is empty or not.
     *
     * @param none
     * @exception none
     * @return void
     ****************************/ 
    cout << "DISPLAY TREE" << endl;
    cout << "==============================================" << endl;

    if (isEmpty()) {
        cout << "Tree is empty" << endl;
        cout << "Height: 0" << endl;
        cout << "Node count: 0" << endl;
        cout << endl;  // Blank line after Node Count

        cout << "Pre-Order Traversal" << endl;
        cout << endl;  // Blank line between traversals
        cout << "In-Order Traversal" << endl;
        cout << endl;  // Blank line between traversals
        cout << "Post-Order Traversal" << endl;
        cout << "==============================================" << endl;  // No blank line here

        cout << endl;  // Blank line before Testing removeNode()
    } else {
        cout << "Tree is NOT empty" << endl;
        cout << "Height: " << getHeight() << endl;
        cout << "Node count: " << getCount() << endl;
        cout << endl;  // Blank line after Node Count

        cout << "Pre-Order Traversal" << endl;
        displayPreOrder();
        cout << endl;  // Blank line between traversals

        cout << "In-Order Traversal" << endl;
        displayInOrder();
        cout << endl;  // Blank line between traversals

        cout << "Post-Order Traversal" << endl;
        displayPostOrder();  // No blank line after Post-Order Traversal
        cout << "==============================================" << endl;  // Directly after Post-Order Traversal

        cout << endl;  // Blank line before Testing removeNode()
    }
}

void BinTree::displayInOrder() const {
    /* **************************
     * Performs an in-order traversal of the
     * binary search tree and prints the node
     * data in sorted order.
     *
     * @param none
     * @exception none
     * @return void
     ****************************/ 
    displayInOrder(root);
    cout << endl;
}

void BinTree::displayPreOrder() const {
    /* **************************
     * Performs a pre-order traversal of the
     * binary search tree and prints the node
     * data in pre-order sequence.
     *
     * @param none
     * @exception none
     * @return void
     ****************************/ 
    displayPreOrder(root);
    cout << endl;
}

void BinTree::displayPostOrder() const {
    /* **************************
     * Performs a post-order traversal of the
     * binary search tree and prints the node
     * data in post-order sequence.
     *
     * @param none
     * @exception none
     * @return void
     ****************************/ 
    displayPostOrder(root);
    cout << endl;
}

void BinTree::clear() {
    /* **************************
     * Deletes all nodes in the binary
     * search tree and resets the tree to
     * an empty state.
     *
     * @param none
     * @exception none
     * @return void
     ****************************/ 
    clear(root);
    root = nullptr;
    count = 0;
}

// Private Recursive Methods

bool BinTree::addNode(DataNode*& node, int id, const string* info) {
    /* **************************
     * Recursively adds a node with the given ID
     * and information string to the binary search tree.
     *
     * @param DataNode*& : reference to the current node
     * @param int : the ID of the node to add
     * @param const string* : pointer to the information string
     * @exception none
     * @return bool : true if the node was added, false otherwise
     ****************************/ 
    bool added = false;
    if (!node) {
        node = new DataNode{{id, *info}, nullptr, nullptr};
        added = true;
    } else if (id < node->data.id) {
        added = addNode(node->left, id, info);
    } else if (id > node->data.id) {
        added = addNode(node->right, id, info);
    }
    return added;
}

BinTree::DataNode* BinTree::removeNode(DataNode* node, int id) {
    /* **************************
     * Recursively removes a node with the given ID
     * from the binary search tree.
     *
     * @param DataNode* : pointer to the current node
     * @param int : the ID of the node to remove
     * @exception none
     * @return DataNode* : pointer to the updated node
     ****************************/ 
    DataNode* updatedNode = node;

    if (!node) {
        updatedNode = nullptr;
    } else if (id < node->data.id) {
        node->left = removeNode(node->left, id);
    } else if (id > node->data.id) {
        node->right = removeNode(node->right, id);
    } else {
        if (!node->left) {
            DataNode* temp = node->right;
            delete node;
            count--;
            updatedNode = temp;
        } else if (!node->right) {
            DataNode* temp = node->left;
            delete node;
            count--;
            updatedNode = temp;
        } else {
            DataNode* minNode = findMin(node->right);
            node->data = minNode->data;
            node->right = removeNode(node->right, minNode->data.id);
        }
    }
    return updatedNode;
}

BinTree::DataNode* BinTree::findMin(DataNode* node) const {
    /* **************************
     * Finds the node with the minimum ID
     * in the binary search tree.
     *
     * @param DataNode* : pointer to the current node
     * @exception none
     * @return DataNode* : pointer to the node with the minimum ID
     ****************************/ 
    DataNode* current = node;
    while (current && current->left) {
        current = current->left;
    }
    return current;
}

bool BinTree::getNode(DataNode* node, Data* data, int id) const {
    /* **************************
     * Recursively retrieves a node with the given ID
     * from the binary search tree and stores its data.
     *
     * @param DataNode* : pointer to the current node
     * @param Data* : pointer to a Data object to store the retrieved data
     * @param int : the ID of the node to retrieve
     * @exception none
     * @return bool : true if the node was found, false otherwise
     ****************************/ 
    bool found = false;
    if (node) {
        if (id == node->data.id) {
            *data = node->data;
            found = true;
        } else if (id < node->data.id) {
            found = getNode(node->left, data, id);
        } else {
            found = getNode(node->right, data, id);
        }
    }
    return found;
}

bool BinTree::contains(DataNode* node, int id) const {
    /* **************************
     * Recursively checks whether a node with the given ID
     * exists in the binary search tree.
     *
     * @param DataNode* : pointer to the current node
     * @param int : the ID to search for
     * @exception none
     * @return bool : true if the node exists, false otherwise
     ****************************/ 
    bool found = false;
    if (node) {
        if (id == node->data.id) {
            found = true;
        } else if (id < node->data.id) {
            found = contains(node->left, id);
        } else {
            found = contains(node->right, id);
        }
    }
    return found;
}

int BinTree::getHeight(DataNode* node) const {
    /* **************************
     * Recursively calculates the height of the binary search tree
     * from the given node.
     *
     * @param DataNode* : pointer to the current node
     * @exception none
     * @return int : the height of the subtree
     ****************************/ 
    int height = 0;
    if (node) {
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        height = 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    }
    return height;
}

void BinTree::displayInOrder(DataNode* node) const {
    /* **************************
     * Recursively performs an in-order traversal of the binary
     * search tree and prints the node data in sorted order.
     *
     * @param DataNode* : pointer to the current node
     * @exception none
     * @return void
     ****************************/ 
    if (node) {
        displayInOrder(node->left);
        cout << node->data.id << " " << node->data.information << endl;
        displayInOrder(node->right);
    }
}

void BinTree::displayPreOrder(DataNode* node) const {
    /* **************************
     * Recursively performs a pre-order traversal of the binary
     * search tree and prints the node data in pre-order sequence.
     *
     * @param DataNode* : pointer to the current node
     * @exception none
     * @return void
     ****************************/ 
    if (node) {
        cout << node->data.id << " " << node->data.information << endl;
        displayPreOrder(node->left);
        displayPreOrder(node->right);
    }
}

void BinTree::displayPostOrder(DataNode* node) const {
    /* **************************
     * Recursively performs a post-order traversal of the binary
     * search tree and prints the node data in post-order sequence.
     *
     * @param DataNode* : pointer to the current node
     * @exception none
     * @return void
     ****************************/ 
    if (node) {
        displayPostOrder(node->left);
        displayPostOrder(node->right);
        cout << node->data.id << " " << node->data.information << endl;
    }
}

void BinTree::clear(DataNode*& node) {
    /* **************************
     * Recursively deletes all nodes in the binary
     * search tree starting from the given node and
     * sets the node pointer to null.
     *
     * @param DataNode*& : reference to the current node
     * @exception none
     * @return void
     ****************************/ 
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
        node = nullptr;
    }
}