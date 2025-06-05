#pragma once

#include <iostream>
#include <string>
#include <exception>

#include "Logging.hpp"

#define NO_BORROWER "Error, no borrower specified"

class Book
{
  public:
    class BookException : public std::exception {
      public:
        BookException(const std::string &message) : _message(message) {}
        virtual const char* what() const noexcept override {
            return _message.c_str();
        }
      private:
        std::string _message;
    };
    Book(const std::string &title, const std::string &author, const std::string &isbn, bool isBorrowed, const std::string &borrower);
    ~Book();

    const std::string &getTitle() const;
    const std::string &getAuthor() const;
    const std::string &getISBN() const;
    bool isBorrowed() const;
    const std::string &getBorrower() const;

    void setBorrowed(bool isBorrowed, const std::string &borrower = "");
    void setTitle(const std::string &title);
    void setAuthor(const std::string &author);
    void setISBN(const std::string &isbn);
    void setBorrower(const std::string &borrower);

    void display() const;
  private:
    std::string _title;
    std::string _author;
    std::string _isbn;
    bool _isBorrowed;
    std::string _borrower;
};
