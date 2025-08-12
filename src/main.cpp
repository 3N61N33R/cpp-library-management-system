#include "Library.hpp"
#include <iostream>
#include <memory>

int main()
{
    std::cout << "--- Library Management System Initializing ---" << std::endl;

    // 1. Create a library instance
    Library library;

    // 2. Add books to the library
    library.addBook(Book("The C++ Programming Language", "Bjarne Stroustrup", "978-0321563842"));
    library.addBook(Book("Effective Modern C++", "Scott Meyers", "978-1491903995"));
    library.addBook(Book("A Tour of C++", "Bjarne Stroustrup", "978-0136816485"));
    library.addBook(Book("Clean Code", "Robert C. Martin", "978-0132350884"));
    library.addBook(Book("Design Patterns", "Erich Gamma", "978-0201633610"));

    // 3. Register members
    library.registerMember(std::make_unique<RegularMember>("Alice", 101));
    library.registerMember(std::make_unique<PremiumMember>("Bob", 202));

    // Show initial state
    library.displayStatus();

    // 4. Perform borrowing operations
    std::cout << "\n--- Round 1: Borrowing Books ---" << std::endl;
    library.borrowBook(101, "978-0132350884"); // Alice borrows Clean Code
    library.borrowBook(202, "978-0321563842"); // Bob borrows The C++ Programming Language
    library.borrowBook(101, "978-0136816485"); // Alice borrows A Tour of C++

    // Show state after borrowing
    library.displayStatus();

    // 5. Test borrowing limits
    std::cout << "\n--- Round 2: Testing Borrow Limits ---" << std::endl;
    library.borrowBook(101, "978-1491903995"); // Alice borrows Effective Modern C++ (3rd book, should succeed)
    library.borrowBook(101, "978-0201633610"); // Alice tries to borrow 4th book (should fail)

    // Show state after hitting limits
    library.displayStatus();

    // 6. Perform returning operations
    std::cout << "\n--- Round 3: Returning Books ---" << std::endl;
    library.returnBook(101, "978-0132350884"); // Alice returns Clean Code

    // Now Alice should be able to borrow another book
    library.borrowBook(101, "978-0201633610"); // Alice borrows Design Patterns

    // Show final state
    library.displayStatus();

    std::cout << "\n--- System Shutdown ---" << std::endl;

    return 0;
}