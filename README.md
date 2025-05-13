# 🗂️ To-Do List Manager in C (Hash Table with Linear Probing)

## 📌 Overview

This project is a **To-Do List Manager** implemented in the **C programming language**, designed for efficient task storage and management using a **Hash Table** with **Linear Probing**. Users can interact with a menu-driven interface to add, delete, and view tasks using unique task IDs.

---

## 🚀 Features

- 📥 **Add Task** – Insert a new task by providing a unique ID and a description.
- 🗑️ **Delete Task** – Remove a task from the table using its ID.
- 📃 **Display Tasks** – Show all active tasks currently stored in the hash table.
- ⚙️ **Collision Resolution** – Linear probing handles hash collisions effectively.
- ❌ **Deleted Slot Marking** – Deleted entries are marked (`-1`) to preserve probe chains.
- ✅ **Duplicate Check** – Prevents inserting duplicate task IDs.

---

## 🧠 How It Works

Tasks are stored in an array-based hash table. The ID is hashed using a modulo operation:

## 📈 Future Enhancements

These are potential improvements to extend the functionality of the program:

🔍 Search Task by ID – Add the ability to look up a task by its unique ID.

✏️ Update Task Description – Allow modifying the description of existing tasks.

📦 Dynamic Table Resizing – Rehash the table when the load factor increases to maintain performance.

💾 File Storage Support – Persist tasks using text or binary file input/output.

🔁 Improved Deletion Logic – Implement double hashing or rehashing for better deletion efficiency.

🧪 Unit Testing – Create a suite of tests to validate core functionality.

🧩 Command-line Arguments – Allow users to perform actions via CLI for scripting and automat




