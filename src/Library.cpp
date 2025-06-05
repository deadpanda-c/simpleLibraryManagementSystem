#include "Library.hpp"

Library::Library()
{
  Logging::Log("Library initialized.");
}

Library::~Library()
{
  Logging::Log("Library destroyed.");
}

void Library::addBook(std::shared_ptr<Book> book)
{
  if (std::find(_books.begin(), _books.end(), book) != _books.end())
    throw LibraryException(BOOK_ALREADY_EXISTS);
  _books.push_back(book);
  Logging::LogWarning("Book added: " + book->getTitle());
}

void Library::removeBook(std::shared_ptr<Book> book)
{
  auto it = std::find(_books.begin(), _books.end(), book);
  if (it == _books.end())
    throw LibraryException(BOOK_NOT_FOUND);
  _books.erase(it);
  Logging::LogWarning("Book removed: " + book->getTitle());
}

std::shared_ptr<Book> Library::findBook(const std::string& title) const
{
  for (const auto& book : _books)
    if (book->getTitle() == title)
      return book;
  throw LibraryException(BOOK_NOT_FOUND);
}

void Library::addUser(std::shared_ptr<User> user)
{
  if (std::find(_users.begin(), _users.end(), user) != _users.end())
    throw LibraryException(USER_ALREADY_EXISTS);
  _users.push_back(user);
  Logging::LogWarning("User added: " + user->getName());
}

void Library::removeUser(std::shared_ptr<User> user)
{
  auto it = std::find(_users.begin(), _users.end(), user);
  if (it == _users.end())
    throw LibraryException(USER_NOT_FOUND);
  _users.erase(it);
  Logging::LogWarning("User removed: " + user->getName());
}

std::shared_ptr<User> Library::findUser(const std::string& name) const
{
  for (const auto& user : _users)
    if (user->getName() == name)
      return user;
  throw LibraryException(USER_NOT_FOUND);
}

std::shared_ptr<Book> Library::findBookByISBN(const std::string& isbn) const
{
  for (const auto& book : _books)
    if (book->getISBN() == isbn)
      return book;
  throw LibraryException(BOOK_NOT_FOUND);
}

std::shared_ptr<User> Library::findUserById(uuid_t userId) const
{
  for (const auto& user : _users)
    if (uuid_compare(user->getUuid().data(), userId) == 0)
      return user;
  throw LibraryException(USER_NOT_FOUND);
}

void Library::borrowBook(uuid_t userId, const std::string &isbn)
{
  auto user = findUserById(userId);
  auto book = findBookByISBN(isbn);

  if (book->isBorrowed())
    throw LibraryException(BOOK_ALREADY_BORROWED);

  book->setBorrowed(true);
  book->setBorrower(user->getName());
  user->borrowBook(isbn);

  Logging::LogWarning("Book borrowed: " + book->getTitle() + " by " + user->getName());
}
