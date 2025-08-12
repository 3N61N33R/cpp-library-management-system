#pragma once // Include guard

#include <string>
#include <memory>

// Forward declarations to avoid circular dependencies
class Book;
class Member;

class AbstractLibrary
{
public:
    // Virtual destructor is crucial for a base class with virtual methods
    virtual ~AbstractLibrary() = default;

    // Pure virtual functions that concrete library classes must implement
    virtual void addBook(const Book &book) = 0;
    virtual void registerMember(std::unique_ptr<Member> member) = 0;
    virtual void borrowBook(int memberId, const std::string &isbn) = 0;
    virtual void returnBook(int memberId, const std::string &isbn) = 0;
};