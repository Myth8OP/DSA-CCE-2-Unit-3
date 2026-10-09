# Automotive Specification Browser (DSA Unit 3 Project)

A fully software-based C++ backend application designed to model complex automotive catalogs and customer interactions without relying on traditional databases, static arrays, or modern C++ libraries. 

This project focuses entirely on linked organization, abstract data types (ADTs), and dynamic memory allocation. It is fully backwards-compatible with legacy IDEs like Dev-C++ 5.11 and Turbo C++.

## Project Objectives
1. **Practical Application of Unit 3 DSA:** To implement and integrate multiple variations of Linked Lists (Singly, Doubly, Circular) and Abstract Data Types (Stacks, Queues) in a single unified system.
2. **Hierarchical Data Modeling:** To simulate a real-world relational database (Category ➔ Model ➔ Trim) strictly using pointer navigation instead of standard library containers.
3. **Dynamic Memory Management:** To demonstrate safe memory allocation (`new`) and deallocation (`delete`) without relying on automated garbage collection, ensuring zero memory leaks upon program termination.
4. **Legacy Compatibility:** To write strictly compliant standard C++98 code that compiles flawlessly on legacy laboratory software like Dev-C++ 5.11.

## Basic System Algorithm
**Step 1:** Start program.
**Step 2:** Initialize pointers for the Catalog (Circular Linked List), History (Stack), and Bookings (Queue).
**Step 3:** Dynamically allocate and link nodes to pre-populate the automotive database.
**Step 4:** Clear the screen and render the main interactive ASCII menu.
**Step 5:** Read user `choice`.
**Step 6:** Execute corresponding operation based on `choice`:
   * **If 1:** Traverse the Circular Linked List to display vehicle segments.
   * **If 2:** Search the Circular Linked List for a segment, then traverse its attached Singly Linked List to display car models.
   * **If 3:** Traverse to a specific Model, display its Doubly Linked List of variants. 
     * Push the selected variant node to the `SpecStack` (LIFO).
     * Calculate price and spec differences using `prev` and `next` pointers.
   * **If 4:** Pop and display nodes from the `SpecStack` to show browsing history.
   * **If 5:** Enqueue or Dequeue nodes in the `BookingQueue` (FIFO) for test drives.
   * **If 6:** Proceed to Step 7.
**Step 7:** Loop back to **Step 4** until the user inputs `6` (Exit).
**Step 8:** Iterate through all Data Structures, invoking destructors to explicitly `delete` all dynamically allocated nodes.
**Step 9:** Terminate program safely.

## Syllabus Mapping (Unit 3 - CO3)
This project intentionally replaces standard library containers (`std::vector`, `std::list`) with scratch-built data structures to demonstrate fundamental DSA concepts:
* **Linked Organization over Sequential:** Eliminates static array sizing limits by dynamically allocating nodes via C++ `new` (replacing `malloc`/`calloc`) and deallocating via `delete` (replacing `free`) to ensure zero memory leaks.
* **Singly, Doubly, and Circular Linked Lists:** Used to create a multi-tiered hierarchy of vehicles.
* **Stack & Queue ADTs:** Implemented strictly using linked lists for O(1) insertion/deletion overhead.
* **Legacy C++ Compliant:** Uses standard C++98 conventions (e.g., `NULL` instead of `nullptr`) to guarantee cross-compatibility with older lab compilers.

## Architecture & Data Structures

The project is divided into `include/` (header declarations) and `src/` (implementation files). Each file serves a specific DSA structural purpose:

### 1. `SegmentList` (Circular Linked List)
* **Function:** Acts as a continuous carousel for vehicle categories (e.g., Sedan ➔ SUV ➔ Hatchback ➔ Sedan). It ensures the user can endlessly cycle through segments without encountering a null pointer at the end of the list.

### 2. `ModelList` (Singly Linked List)
* **Function:** Stores the linear list of car models (e.g., Slavia ➔ Virtus) within a specific segment. Each node contains a nested pointer to its respective trim levels.

### 3. `VariantList` (Doubly Linked List)
* **Function:** The core analytical tool of the application. It connects car trims (e.g., Base ⇄ Mid ⇄ Top). The `prev` and `next` pointers allow bidirectional traversal to calculate dynamic price and power deltas (upgrades vs. downgrades) on the fly.

### 4. `SpecStack` (Stack using Linked List)
* **Function:** Tracks the user's browsing history (LIFO - Last In, First Out). Every time a user views a specific car trim, its pointer is pushed onto the stack. Users can pop the stack to view their most recently analyzed trims.

### 5. `BookingQueue` (Queue using Linked List)
* **Function:** Manages customer test-drive inquiries (FIFO - First In, First Out). Dealership requests are enqueued at the rear and dequeued from the front to guarantee a strict, fair service pipeline.

### 6. `main.cpp`
* **Function:** The entry point. Initializes the dynamic memory, pre-loads the hierarchical nodes with real-world automotive specifications, and drives the interactive Command Line Interface (CLI) featuring cross-platform screen clearing and structured table formatting.

## Testing/Running Guide (Quick Start)

To test the functionality of all Unit 3 Data Structures, please run the `.exe` file and follow this exact sequence of inputs. 

*(Note: The search inputs are **case-sensitive**, so please type the names exactly as shown below).*

### Test 1: Circular Linked List (Segments)
* **Press `1`** from the main menu.
* **Expected Result:** The system will traverse the Circular Linked List and display the segments: `[Sedan] -> [SUV] -> [Hatchback] -> (Loops back to Sedan)`.

### Test 2: Singly Linked List (Models)
* **Press `2`** from the main menu.
* When prompted for a segment, type: `SUV` and press Enter.
* **Expected Result:** The system locates the SUV node and traverses its internal Singly Linked List to show: `Creta`, `XUV700`, and `Safari`.

### Test 3: Doubly Linked List (Trims & Upgrades)
* **Press `3`** from the main menu.
* When prompted for a segment, type: `Sedan`
* When prompted for a model, type: `Slavia`
* **Expected Result:** The system will traverse down to the Base variant of the Slavia. Because it uses a Doubly Linked List, it will automatically look at the `next` pointer and calculate the exact price and horsepower difference required to upgrade to the Ambition trim. *(Note: This action also silently pushes the Slavia to the SpecStack).*

### Test 4: LIFO Stack (Browsing History)
* **Press `4`** from the main menu.
* **Expected Result:** The stack will pop and display the history. You will see the **Slavia** at the top of the stack, proving the LIFO (Last-In, First-Out) memory structure worked during Test 3.

### Test 5: FIFO Queue (Test Drives)
* **Press `5`** from the main menu, then **Press `1`** to Add a Booking.
* Type a customer name (e.g., `Rahul`) and a car (e.g., `Safari`). 
* **Press `5`** again, and **Press `1`** to add a second booking (e.g., `Priya` for `Creta`).
* **Press `5`** one more time, and **Press `2`** to Process a Booking.
* **Expected Result:** The system will process `Rahul` first, completely validating the Queue's strict FIFO (First-In, First-Out) architecture.

### Test 6: Memory Cleanup
* **Press `6`** to exit the system. 
* **Expected Result:** The system will invoke all custom destructors, safely iterating through every list, stack, and queue to `delete` all dynamically allocated nodes, preventing any memory leaks.


*(Note: This project was built entirely through traditional, hands-on software development without the use of AI generation tools for its core architecture or codebase. While I did use an external AI API for troubleshooting and optimizing my code, its footprint is very minimal and limited strictly to that specific functionality. Thank You :)).*