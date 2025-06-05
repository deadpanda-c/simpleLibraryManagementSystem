#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <memory>
#include <vector>
#include <algorithm>

#include "User.hpp"
#include "Book.hpp"
#include "Logging.hpp"

#define BOOK_ALREADY_EXISTS "Book already exists in the library."
#define BOOK_NOT_FOUND "Book not found in the library."

#define USER_ALREADY_EXISTS "User already exists in the library."
#define USER_NOT_FOUND "User not found in the library."
#define BOOK_ALREADY_BORROWED "Book is already borrowed by another user."

class Library {
  public:
    class LibraryException : public std::exception {
      public:
        explicit LibraryException(const std::string& message) : msg_(message) {}
        virtual const char* what() const noexcept override {
            return msg_.c_str();
        }
      private:
        std::string msg_;
    };

    Library();
    ~Library();

    void addBook(std::shared_ptr<Book> book);
    void removeBook(std::shared_ptr<Book> book);
    std::shared_ptr<Book> findBook(const std::string& bookName) const;
    std::shared_ptr<Book> findBookByISBN(const std::string& isbn) const;

    void addUser(std::shared_ptr<User> user);
    void removeUser(std::shared_ptr<User> user);
    std::shared_ptr<User> findUser(const std::string& userName) const;
    std::shared_ptr<User> findUserById(uuid_t userId) const;

    void borrowBook(uuid_t userId, const std::string& isbn);

    // get all user uuid
    std::vector<std::array<uint8_t, 16>> getUserUuids() const {
      std::vector<std::array<uint8_t, 16>> userUuids;

      for (const auto& user : _users) {
        std::array<uint8_t, 16> uuidArray;
        std::memcpy(uuidArray.data(), user->getUuid().data(), 16);
        userUuids.push_back(uuidArray);
      }
      return userUuids;
    }

    std::vector<std::string> getBooks() const {
      std::vector<std::string> bookNames;

      for (const auto& book : _books)
        bookNames.push_back(book->getISBN());
      return bookNames;
    }

    void displayUsers() const {
      for (const auto& user : _users)
        user->display();
    }

    void displayBooks() const {
      for (const auto& book : _books)
        book->display();
    }
  private:
    std::vector<std::shared_ptr<User>> _users;
    std::vector<std::shared_ptr<Book>> _books;
};
