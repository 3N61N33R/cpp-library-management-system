#pragma once

#include "AbstractLibrary.hpp"
#include "Book.hpp"
#include "Member.hpp"
#include <map>
#include <string>
#include <memory>

class Library : public AbstractLibrary
{
private:
    // Composition: The library owns its collection of books.
    std::map<std::string, Book> book_repository;

    // Aggregation: The library manages a collection of members.
    std::map<int, std::unique_ptr<Member>> members;

public:
    // Override the pure virtual functions from the abstract base class
    void addBook(const Book &book) override;
    void registerMember(std::unique_ptr<Member> member) override;
    void borrowBook(int memberId, const std::string &isbn) override;
    void returnBook(int memberId, const std::string &isbn) override;

    // Helper function to show the current status of the library
    void displayStatus() const;
};