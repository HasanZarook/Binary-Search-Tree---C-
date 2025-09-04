
# 🌳 C++ Binary Search Tree (BST)

This project implements a **Binary Search Tree (BST)** in C++ with support for standard operations including insertion, traversal, search, deletion, and finding predecessors/successors.

---

## 📝 Features

* ✅ Insert nodes into the BST
* ✅ **Inorder**, **Preorder**, and **Postorder** traversals
* ✅ Search for a node by value
* ✅ Find **minimum** and **maximum** node values
* ✅ Find **predecessor** and **successor** of a node
* ✅ Delete a node from the BST
* ✅ Maintains **parent pointers** for easier traversal and deletion

---

## ⚡ Components

### Classes

| Class      | Description                                                                                        |
| ---------- | -------------------------------------------------------------------------------------------------- |
| `treeNode` | Represents a node in the BST with `left`, `right`, `parent` pointers and `data`                    |
| `BST`      | Implements all BST operations such as insert, traverse, search, delete, predecessor, and successor |

---

### Traversals

* **Inorder**: Left → Root → Right
* **Preorder**: Root → Left → Right
* **Postorder**: Left → Right → Root

---

### Node Operations

* **Insert**: Adds a node while maintaining BST property
* **Search**: Returns a pointer to the node containing the value
* **Delete**: Removes a node and re-links the tree correctly
* **Predecessor**: Finds the previous node in inorder traversal
* **Successor**: Finds the next node in inorder traversal
* **Min/Max**: Returns the smallest/largest value in the tree

---

## 🔧 Usage Example

```cpp
BST St;
St.insert("pat");
St.insert("use");
St.insert("zoo");

St.InorderTraverse(St.root); // Output: pat use zoo

cout << "Min: " << St.TreeMin() << endl; // Min value
cout << "Max: " << St.TreeMax() << endl; // Max value

treeNode* pred = St.Predecessor("use");
cout << "Predecessor of use: " << pred->data << endl;

St.deleteNode("pat");
St.InorderTraverse(St.root); // Updated tree
```

---

## ⚠️ Notes

* The BST stores **string values** in this implementation.
* All operations maintain proper **parent links** for easier tree navigation.
* Deletion uses the **successor node** for nodes with two children.
* Traversals can be used to display tree contents in different orders.


