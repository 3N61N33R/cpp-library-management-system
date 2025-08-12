#include "Member.hpp"

// --- Member Base Class Implementation ---
Member::Member(const std::string &name, int member_id)
    : name(name), member_id(member_id) {}

std::string Member::getName() const { return name; }
int Member::getMemberId() const { return member_id; }
int Member::getBorrowedCount() const { return borrowed_books.size(); }

void Member::borrowBook(Book *book)
{
    borrowed_books.push_back(book);
}

void Member::returnBook(Book *book)
{
    for (auto it = borrowed_books.begin(); it != borrowed_books.end(); ++it)
    {
        if ((*it)->getIsbn() == book->getIsbn())
        {
            borrowed_books.erase(it);
            break;
        }
    }
}

void Member::displayBorrowedBooks() const
{
    std::cout << "  Borrowed books (" << getBorrowedCount() << "):" << std::endl;
    if (borrowed_books.empty())
    {
        std::cout << "    None." << std::endl;
    }
    else
    {
        for (const auto *book : borrowed_books)
        {
            std::cout << "    - " << book->getTitle() << " (ISBN: " << book->getIsbn() << ")" << std::endl;
        }
    }
}

// --- RegularMember Implementation ---
RegularMember::RegularMember(const std::string &name, int member_id)
    : Member(name, member_id) {}

bool RegularMember::canBorrow() const
{
    return borrowed_books.size() < 3;
}

// --- PremiumMember Implementation ---
PremiumMember::PremiumMember(const std::string &name, int member_id)
    : Member(name, member_id) {}

bool PremiumMember::canBorrow() const
{
    return borrowed_books.size() < 5;
}