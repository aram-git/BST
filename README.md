## Assignment 8: Binary Search Tree Implementation
### Author: Aaron Ramirez
### Purpose: Binary Search Tree Implementation

---

### **Summary Introduction**
This project implements a dynamic Binary Search Tree (BST) in C++ to store and manage nodes containing unique integer IDs and associated string values. The program adheres to the specified assignment requirements by supporting various operations such as insertion, deletion, search, tree traversal (in-order, pre-order, post-order), and dynamic height calculation. The focus is on efficient memory management, recursion, and proper formatting of outputs as specified by the assignment guidelines.

---

### **Logic of the Binary Search Tree**
A Binary Search Tree (BST) is a hierarchical data structure that organizes data for efficient operations such as searching, insertion, and deletion. The key property of a BST is that for each node:
- **Left Subtree:** Contains nodes with values less than the node’s value.
- **Right Subtree:** Contains nodes with values greater than the node’s value.

This property ensures traversal of the tree can be done in sorted order, and operations like search and insertion have a time complexity of O(log n) in the average case.

---

### **Program Logic**
The program is structured into a class-based approach, with all operations encapsulated in the `BinTree` class. The class includes public methods for tree operations and private recursive helper functions for efficient traversal and manipulation. The program follows the principles of:

- Dynamic Memory Management: Nodes are dynamically allocated and deallocated to prevent memory leaks.

- Recursion: Traversals and operations like insertion and deletion use recursion to navigate the tree. Recursive logic is used for processing data. Recursive logic is particularly useful in binary trees for several reasons. Recursive functions can be more straightforward and easier to understand than their iterative counterparts. For example, traversing a binary tree (in-order, pre-order, or post-order) is naturally recursive because each node's subtrees are themselves binary trees. Recursive solutions often lead to cleaner and more readable code. For instance, a recursive function to calculate the height of a binary tree is more concise than an iterative one. Binary trees are inherently recursive structures. Each node can be thought of as the root of its own subtree. Recursive algorithms can naturally exploit this property to solve problems by breaking them down into smaller subproblems. Recursive functions can easily backtrack, which is useful for certain tree operations like finding paths or checking conditions that require exploring all possible branches. 

- Traversals: In-order, pre-order, and post-order traversals display the tree in sorted, structural, and memory-cleanup orders, respectively.
The program ensures strict adherence to the required output formatting as per the assignment.

Below is a summary of the program’s core logic:

1. **Binary Search Tree (BST):**
   - The BST uses a linked list structure with nodes represented by the `DataNode` struct.  
     Each `DataNode` contains:
     - Data (ID and information string)
     - Pointers to the left and right child nodes.

2. **Recursive Methods:**
   - All major tree operations, such as `addNode`, `removeNode`, `getNode`, and traversals, use recursion to navigate through the tree efficiently.
   - Each public method calls a private recursive helper function to handle the actual logic.

3. **Memory Management:**
   - Nodes are dynamically allocated when added to the tree and deallocated when removed or cleared.
   - The destructor ensures all nodes are deleted to prevent memory leaks.

4. **Traversals:**
   - **In-Order Traversal:** Visits the left subtree, the current node, and then the right subtree.
   - **Pre-Order Traversal:** Visits the current node, the left subtree, and then the right subtree.
   - **Post-Order Traversal:** Visits the left subtree, the right subtree, and then the current node.

5. **Height Calculation:**
   - The height of the tree is calculated dynamically by recursively finding the maximum height between the left and right subtrees.

6. **Node Insertion and Deletion:**
   - Nodes are inserted based on their ID values. Smaller IDs go to the left subtree, and larger IDs go to the right subtree.
   - Node removal accounts for cases with no children, one child, or two children (replacing the node with its in-order successor).

---

### **Core Operations**
1. **Insertion:**
   - Starts from the root and recursively moves left or right depending on comparisons with the current node’s value.
   - Inserts the value at the appropriate empty location.

2. **Search:**
   - Recursively traverses the tree to locate a node by its ID. Returns `true` if found, otherwise `false`.

3. **Deletion:**
   - Recursively removes a node by adjusting pointers and handling cases like no children, one child, or two children (replacing the node with its in-order successor).

4. **Traversals:**
   - **In-order Traversal:** Produces nodes in sorted order.
   - **Pre-order Traversal:** Useful for copying the tree.
   - **Post-order Traversal:** Useful for deleting the tree.

5. **Height Calculation:** Dynamically computes the maximum depth of the tree.

6. **Clear Tree:** Recursively deletes all nodes using post-order traversal to ensure proper memory management.

---

### **Key Properties**
- The BST is dynamic and can grow or shrink as nodes are added or removed.
- Efficient search, insertion, and deletion operations are implemented, ensuring correctness and proper memory management.

---

### **Assignment Requirements**
The following list maps each requirement to the corresponding function(s) in the program:

1. **Constructor for initializing root and count:**
   - `BinTree::BinTree()`

2. **Destructor that calls clearTree():**
   - `BinTree::~BinTree()`
   - `BinTree::clear()`

3. **Check if the tree is empty:**
   - `BinTree::isEmpty()`

4. **Return the total number of nodes in the tree:**
   - `BinTree::getCount()`

5. **Retrieve root data if the tree is not empty:**
   - `BinTree::getRootData(Data* data)`

6. **Display all tree statistics and traversal methods:**
   - `BinTree::displayTree()`

7. **Clear the tree and reset it to an empty state:**
   - `BinTree::clear()`

8. **Add a node with a unique ID and associated string:**
   - `BinTree::addNode(int, const string*)`
   - Private helper: `BinTree::addNode(DataNode*&, int, const string*)`

9. **Remove a node by ID:**
   - `BinTree::removeNode(int)`
   - Private helper: `BinTree::removeNode(DataNode*, int)`

10. **Check if a node with a specific ID exists:**
    - `BinTree::contains(int)`
    - Private helper: `BinTree::contains(DataNode*, int)`

11. **Retrieve a node’s data using its ID:**
    - `BinTree::getNode(Data*, int)`
    - Private helper: `BinTree::getNode(DataNode*, Data*, int) const`

12. **Dynamically calculate the height of the tree:**
    - `BinTree::getHeight()`
    - Private helper: `BinTree::getHeight(DataNode*)`

13. **Perform in-order traversal:**
    - `BinTree::displayInOrder()`
    - Private helper: `BinTree::displayInOrder(DataNode*)`

14. **Perform pre-order traversal:**
    - `BinTree::displayPreOrder()`
    - Private helper: `BinTree::displayPreOrder(DataNode*)`

15. **Perform post-order traversal:**
    - `BinTree::displayPostOrder()`
    - Private helper: `BinTree::displayPostOrder(DataNode*)`

16. **Find the node with the minimum ID (used internally for remove):**
    - `BinTree::findMin(DataNode*)`

---

### **Compilation and Execution**
#### **Compilation:**

g++ -o bintree main.cpp bintree.cpp functions.cpp main.h bintree.h functions.h data.h
### Execution:

./bintree

### Conclusion
This program implements a dynamic Binary Search Tree (BST) with efficient storage, retrieval, and deletion of nodes. The design adheres to clean, reusable class principles with a focus on recursion for key operations. The tree is displayed using traversal methods, and all memory is cleared safely upon program termination. The project highlights essential BST concepts, ensuring correctness, dynamic memory management, and reusable design.