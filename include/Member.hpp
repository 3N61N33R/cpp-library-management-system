#pragma once

#include <string>
#include <vector>
#include <iostream>
#include "Book.hpp" // Member class uses the Book class

class Member
{
protected:
    std::string name;
    int member_id;
    std::vector<Book *> borrowed_books;

public:
    Member(const std::string &name, int member_id);
    virtual ~Member() = default; // Use default for simple virtual destructors

    std::string getName() const;
    int getMemberId() const;
    int getBorrowedCount() const;

    void borrowBook(Book *book);
    void returnBook(Book *book);
    void displayBorrowedBooks() const;

    virtual bool canBorrow() const = 0;
};

class RegularMember : public Member
{
public:
    RegularMember(const std::string &name, int member_id);
    bool canBorrow() const override;
};

class PremiumMember : public Member
{
public:
    PremiumMember(const std::string &name, int member_id);
    bool canBorrow() const override;
};