# Student Management System 🎓

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![License](https://img.shields.io/badge/License-MIT-blue?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Stable%20✅-success?style=for-the-badge)
![Version](https://img.shields.io/badge/Version-1.0.0-important?style=for-the-badge)

A complete and efficient console-based Student Management System written in pure C, demonstrating advanced use of pointers, structures, and file handling.

## ✨ Features

-   **📝 Add New Students:** Input student ID, first name, last name, and average score.
-   **👥 List All Students:** Display all records in a formatted list.
-     **🔍 Search Students:** Find a student by their unique ID.
-   **🗑️ Remove Students:** Delete a student record by ID.
-     **📊 Sort Students:** Sort all students by their average score (ascending order).
-     **💾 Save/Load Data:** Persist data to a text file and load it back on startup.
-   **🎯 Interactive Console Menu:** User-friendly menu-driven interface.

## 🛠️ Tech Stack & Concepts

-   **Language:** C (Standard C11)
-   **Core Concepts:** Structs, Pointers, File I/O (`stdio.h`), String Manipulation (`string.h`)
-   **Data Structures:** Array of Structs
-   **Algorithms:** Insertion Sort
-   **Memory Management:** Stack Allocation (Static Arrays)

## 📦 Installation & Compilation

1.  **Clone the repository:**
    ```bash
    git clone https://github.com/YOUR_USERNAME/student-management-system-c.git
    cd student-management-system-c
    ```

2.  **Compile the source code:**
    ```bash
    gcc -o student_manager main.c
    ```

3.  **Run the executable:**
    ```bash
    ./student_manager
    ```

## 🚀 Usage

1.  Run the program and select an option from the menu.
2.  Use option `2` to add a new student. Enter the details when prompted.
3.  Use option `1` to view all added students.
4.  Use option `4` to search for a student by ID.
5.  Use option `3` to remove a student by ID.
6.  Use option `5` to sort students by average score.
7.  Use option `6` to save the student list to a file (`Student's list.txt`).
8.  Use option `7` to load the student list from the file.
9.  Use option `0` to exit the program.


## 🔮 Future Enhancements

-   [ ] Dynamic memory allocation (malloc/free) for unlimited students.
-   [ ] Linked List data structure for efficient insertions/deletions.
-   [ ] Error handling for user input (e.g., invalid average score).
-   [ ] Search by name or average score range.
-   [ ] GUI version using GTK or similar.

## 👨‍💻 Developer

BEZI - [@BeziKaviani](https://github.com/BeziKaviani)

## 📜 License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

<div align="center">

**⭐ If you find this project useful, please give it a star!**

</div>