#include "User.hpp"

User::User(const std::string &name)
  : _name(name)
{
  uuid_generate(_uuid);
  Logging::Log("User created: " + _name + " with UUID: " + getStringUuid());
}

User::~User()
{
  Logging::Log("User destroyed: " + _name + " with UUID: " + getStringUuid());
}

std::string User::getStringUuid() const
{
  char uuidStr[37];
  uuid_unparse(_uuid, uuidStr);

  return std::string(uuidStr);
}

std::array<uint8_t, 16> User::getUuid() const
{
  std::array<uint8_t, 16> uuidCopy;
  std::memcpy(uuidCopy.data(), _uuid, 16);
  return uuidCopy;
}

std::string User::getName() const
{
  return _name;
}

void User::display() const
{
  Logging::Log("Displaying user: " + _name + " with UUID: " + getStringUuid());
  std::cout << "User Name: " << _name << std::endl;
  std::cout << "User UUID: " << getStringUuid() << std::endl;
  std::cout << "Borrowed Books ISBNs: " << std::endl;
  for (const auto &isbn : _borrowedBooksISBNs) {
    std::cout << "- " << isbn << std::endl;
  }
}

void User::borrowBook(const std::string &isbn)
{
  _borrowedBooksISBNs.push_back(isbn);
  Logging::Log("Book with ISBN: " + isbn + " borrowed by user: " + _name);
}
