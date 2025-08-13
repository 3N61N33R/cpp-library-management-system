# C++ Library Management System

This project is a simplified, command-line Library Management System built in C++, created as part of an academic course to demonstrate core Object-Oriented Programming (OOP) principles practically. It models books, members, and basic library operations like borrowing and returning books.

---

## OOP Concepts Demonstrated

* **📦 Encapsulation**: The `Book` class safely bundles its data (title, author, etc.) with the methods that operate on that data, using private attributes and public getters/setters.

* **👪 Inheritance**: A base `Member` class defines common attributes, while `RegularMember` and `PremiumMember` subclasses inherit from it and provide specialized behavior (different borrowing limits).

* **🎨 Abstraction**: An abstract `AbstractLibrary` class defines a common interface (`addBook`, `borrowBook`, etc.), ensuring any concrete library implementation follows a consistent contract.

* **🔗 Composition, Aggregation, and Association**:

    * The `Library` class is **composed** of a collection of `Book` objects.
    * It **aggregates** a collection of `Member` objects.
    * A temporary **association** is formed when a `Member` borrows a `Book`.

---

## 📂 Project Structure

The project utilises a clean and standard directory structure, separating interface files (`.hpp`) from implementation files (`.cpp`).
```
.
├── build/
├── include/
│   ├── AbstractLibrary.hpp
│   ├── Book.hpp
│   ├── Library.hpp
│   └── Member.hpp
├── src/
│   ├── Book.cpp
│   ├── Library.cpp
│   ├── main.cpp
│   └── Member.cpp
├── .gitignore
├── CMakeLists.txt
└── README.md
```
---

## 🚀 Getting Started

To get a copy of the project up and running on your local machine for development and testing.

### Prerequisites

You will need the following tools installed on your system:

* **Git**: To clone the repository.
* **CMake**: Version 3.10 or higher.
* **A C++ Compiler**: A modern compiler that supports the C++17 standard (e.g., GCC, Clang, MSVC).

### Building and Running

1.  **Clone the repository**
    ```sh
    git clone git@github.com:3N61N33R/cpp-library-management-system.git
    cd cpp-library-management-system
    ```

2.  **Configure the project with CMake**
   
    This command generates the build files (e.g., Makefiles) in a `build` directory.
    ```sh
    cmake -B build
    ```

4.  **Compile the project**
    This command invokes your compiler to build the executable.
    ```sh
    cmake --build build
    ```

5.  **Run the application**
    The final executable will be located inside the `build` directory.
    ```sh
    ./build/library
    ```

---

## 🤝 How to Contribute & Fork

Since this is a learning project, you are highly encouraged to fork it and experiment! Feel free to add new features, fix bugs, or refactor the code.

The standard GitHub workflow:

1.  **Fork** the project by clicking the "Fork" button in the top-right corner of the repository page.
2.  **Clone** your forked repository to your local machine.
3.  Create a new **branch** for your changes (`git checkout -b feature/add-new-feature`).
4.  Make your changes and **commit** them with a clear message.
5.  **Push** your changes to your fork on GitHub.
6.  Create a **Pull Request** to merge your changes back into the original repository.

---

## 👤 3N61N33R
