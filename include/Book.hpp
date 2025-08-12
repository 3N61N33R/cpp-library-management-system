// Declare the Book class

#pragma once // Include guard to prevent multiple inclusions

#include <string>   // For std::string
#include <iostream> // For std::ostream

class Book
{
private: // Private member variables
    std::string title;
    std::string author;
    std::string isbn;
    bool is_available;

public: // Public member functions
    // Constructor to initialize a Book object
    Book(const std::string &title = "", const std::string &author = "", const std::string &isbn = "");

    // Function to get the title, author & ISBN of the book, and check availability
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getIsbn() const;
    bool isAvailable() const;

    void setTitle(const std::string &newTitle);
    void setAuthor(const std::string &newAuthor);
    void setIsbn(const std::string &newIsbn);

    // Function to set the availability of the book
    void setAvailable(bool available);

    void display() const; // Function to display book details
};