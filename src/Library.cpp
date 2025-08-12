#include "Library.hpp"
#include <iostream>

void Library::addBook(const Book &book)
{
    // Insert the book into the map using its ISBN as the key.
    book_repository.insert({book.getIsbn(), book});
    std::cout << "[INFO] Book '" << book.getTitle() << "' added to the library." << std::endl;
}

void Library::registerMember(std::unique_ptr<Member> member)
{
    int id = member->getMemberId();
    std::cout << "[INFO] Member '" << member->getName() << "' registered with ID: " << id << std::endl;
    // Move the unique_ptr into the map, transferring ownership to the library.
    members[id] = std::move(member);
}

void Library::borrowBook(int memberId, const std::string &isbn)
{
    // Find the member by their ID
    auto member_it = members.find(memberId);
    if (member_it == members.end())
    {
        std::cerr << "[ERROR] Member with ID " << memberId << " not found." << std::endl;
        return;
    }

    // Find the book by its ISBN
    auto book_it = book_repository.find(isbn);
    if (book_it == book_repository.end())
    {
        std::cerr << "[ERROR] Book with ISBN " << isbn << " not found." << std::endl;
        return;
    }

    // Get pointers to the actual objects to work with them
    Member *member = member_it->second.get();
    Book *book = &book_it->second;

    // Check all conditions before allowing the loan
    if (!book->isAvailable())
    {
        std::cout << "[FAIL] '" << member->getName() << "' failed to borrow '" << book->getTitle() << "'. Book is currently unavailable." << std::endl;
    }
    else if (!member->canBorrow())
    {
        std::cout << "[FAIL] '" << member->getName() << "' failed to borrow '" << book->getTitle() << "'. Borrowing limit reached." << std::endl;
    }
    else
    {
        // Process the loan
        book->setAvailable(false);
        member->borrowBook(book);
        std::cout << "[SUCCESS] '" << member->getName() << "' successfully borrowed '" << book->getTitle() << "'." << std::endl;
    }
}

void Library::returnBook(int memberId, const std::string &isbn)
{
    auto member_it = members.find(memberId);
    if (member_it == members.end())
    {
        std::cerr << "[ERROR] Member with ID " << memberId << " not found." << std::endl;
        return;
    }

    auto book_it = book_repository.find(isbn);
    if (book_it == book_repository.end())
    {
        std::cerr << "[ERROR] Book with ISBN " << isbn << " not found." << std::endl;
        return;
    }

    Member *member = member_it->second.get();
    Book *book = &book_it->second;

    // Process the return
    book->setAvailable(true);
    member->returnBook(book);
    std::cout << "[SUCCESS] '" << member->getName() << "' successfully returned '" << book->getTitle() << "'." << std::endl;
}

void Library::displayStatus() const
{
    std::cout << "\n--- Library Status ---" << std::endl;
    std::cout << "Books in Repository:" << std::endl;
    if (book_repository.empty())
    {
        std::cout << "  No books in the library." << std::endl;
    }
    else
    {
        for (const auto &pair : book_repository)
        {
            pair.second.display();
        }
    }

    std::cout << "\nRegistered Members:" << std::endl;
    if (members.empty())
    {
        std::cout << "  No members registered." << std::endl;
    }
    else
    {
        for (const auto &pair : members)
        {
            std::cout << " - Member: " << pair.second->getName() << " (ID: " << pair.second->getMemberId() << ")" << std::endl;
            pair.second->displayBorrowedBooks();
        }
    }
    std::cout << "----------------------" << std::endl;
}