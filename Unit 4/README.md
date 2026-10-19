# UI Layout Mirroring Engine (Binary Tree - Unit 4 DSA Project)

A C++98 compliant software application that models a user-interface DOM tree, utilizes recursive binary tree algorithms to generate its exact mirror image, and performs structural validation to support Right-to-Left (RTL) language layouts (such as Arabic or Hebrew).

This project was built to fulfill the **Data Structures and Algorithms Unit 4 (CO4) requirements**, focusing on non-linear data structures, binary tree traversal, pointer-based tree cloning, and recursive structural comparisons.

## Syllabus Mapping (Unit 4 - CO4)
* **Non-Linear Data Structures:** Utilizes Binary Trees instead of linear arrays or lists to represent hierarchical UI component nesting.
* **Recursive Tree Operations:** Employs post-order traversal algorithms to visit, clone, and invert left and right child pointers.
* **Structural Equality & Mirror Checking:** Implements recursive logic to evaluate if two distinct binary trees are mirror reflections of each other.
* **Dynamic Memory Management:** Uses heap allocation (`new`) for node creation and post-order destruction (`delete`) via custom class destructors to guarantee zero memory leaks.

## Project Objectives
1. **Practical Application of Unit 4 Trees:** To implement binary tree nodes, pointer manipulation, and recursive traversal algorithms for real-world layout transformations.
2. **RTL UI Adaptation:** To simulate how modern frontend engines generate Right-to-Left layouts (for localized languages) by computing the mirror image of a component tree.
3. **Structural Validation:** To build a robust comparison algorithm that validates whether a generated layout correctly matches its expected mirror specification.
4. **Modular Architecture & Legacy Safety:** To maintain clean separation between headers (`include/`) and sources (`src/`), ensuring 100% compatibility with legacy C++98 academic compilers like Dev-C++ 5.11.

## Basic System Algorithm
* **Step 1:** Start program and initialize the `UILayoutTree` manager.
* **Step 2:** Pre-load the memory heap with a standard Left-to-Right (LTR) UI component tree (`AppWindow` root with `Sidebar` and `MainBody` sub-nodes).
* **Step 3:** Clear the console screen, render the ASCII banner, and display the main interactive menu.
* **Step 4:** Read user `choice`.
* **Step 5:** Execute operations based on `choice`:
  * **If 1:** Print the original LTR tree structure using the 2D visualizer.
  * **If 2:** Invoke `createMirror()` using post-order traversal to swap left and right child pointers, generating the RTL mirror tree.
  * **If 3:** Invoke `areMirrors()` to validate that the generated RTL tree is a perfect structural mirror of the original LTR tree.
  * **If 4:** Run a negative test case comparing the LTR tree against an intentionally corrupted tree to confirm error detection.
  * **If 5:** Proceed to Step 6.
* **Step 6:** Invoke tree destructors (`destroyTree()`) to explicitly `delete` all heap-allocated nodes, clearing all memory.
* **Step 7:** Terminate program safely.

## Project Architecture & File Structure

The project follows a modular architecture, cleanly separating the Abstract Data Type (ADT) interface from its implementation:

```text
├── include/
│   ├── UINode.hpp         # Node structure blueprint for UI components
│   └── UILayoutTree.hpp   # ADT interface for binary tree mirror and comparison algorithms
├── src/
│   ├── UILayoutTree.cpp   # Core recursive pointer logic (Mirroring & Validation)
│   └── main.cpp           # Application driver, ASCII UI, and interactive CLI menu
└── README.md