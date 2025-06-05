#include "Book.hpp"

Book::Book(const std::string &title, const std::string &author, const std::string &isbn, bool isBorrowed, const std::string &borrower)
    : _title(title), _author(author), _isbn(isbn), _isBorrowed(isBorrowed)
{
  if (isBorrowed && borrower.empty()) {
    throw BookException(NO_BORROWER);
  }
  Logging::Log("Book created: " + title + " by " + author);
}

Book::~Book()
{
  Logging::Log("Book destroyed: " + _title);
}

const std::string &Book::getTitle() const
{
  return _title;
}

const std::string &Book::getAuthor() const
{
  return _author;
}

const std::string &Book::getISBN() const
{
  return _isbn;
}

bool Book::isBorrowed() const
{
  return _isBorrowed;
}

const std::string &Book::getBorrower() const
{
  return _borrower;
}

void Book::setBorrowed(bool isBorrowed, const std::string &borrower)
{
  _isBorrowed = isBorrowed;
  _borrower = borrower;
  Logging::LogWarning("Book " + _title + " borrow status changed to " + (isBorrowed ? "borrowed" : "available"));
}

void Book::setTitle(const std::string &title)
{
  _title = title;
  Logging::LogWarning("Book title changed to: " + title);
}

void Book::setAuthor(const std::string &author)
{
  _author = author;
  Logging::LogWarning("Book author changed to: " + author);
}

void Book::setISBN(const std::string &isbn)
{
  _isbn = isbn;
  Logging::LogWarning("Book ISBN changed to: " + isbn);
}

void Book::setBorrower(const std::string &borrower)
{
  _borrower = borrower;
  Logging::LogWarning("Book borrower changed to: " + borrower);
}

void Book::display() const
{
  // display book details
  Logging::Log("Book title: " + _title);
  Logging::Log("Book author: " + _author);
  Logging::Log("Book ISBN: " + _isbn);
  Logging::Log("Book is " + std::string(_isBorrowed ? "borrowed" : "available"));
  if (_isBorrowed) {
    Logging::LogWarning("Book borrower: " + _borrower);
  } else {
    Logging::Log("Book is available for borrowing.");
  }

}
