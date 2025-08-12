#include "Book.hpp" // Include the header file for the Book class

Book::Book(const std::string &title, const std::string &author, const std::string &isbn)
    : title(title), author(author), isbn(isbn), is_available(true) {}

// Getters for title, author, and ISBN
std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
std::string Book::getIsbn() const { return isbn; }
bool Book::isAvailable() const { return is_available; }

// Setters
void Book::setTitle(const std::string &newTitle) { title = newTitle; }
void Book::setAuthor(const std::string &newAuthor) { author = newAuthor; }
void Book::setIsbn(const std::string &newIsbn) { isbn = newIsbn; }
void Book::setAvailable(bool available) { is_available = available; }

void Book::display() const
{
    std::cout << "  - Title: " << title << ", Author: " << author
              << ", ISBN: " << isbn << ", Available: "
              << (is_available ? "Yes" : "No") << std::endl;
}