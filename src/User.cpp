#include "User.hpp"

User::User(const std::string &name, uuid_t uuid, std::vector<std::string> borrowedBooksISBNs)
  : _name(name), _borrowedBooksISBNs(borrowedBooksISBNs)
{
  std::memcpy(_uuid, uuid, sizeof(uuid_t));
  Logging::Log("User created: " + _name + " with UUID: " + getUuid());
}

User::~User()
{
  Logging::Log("User destroyed: " + _name + " with UUID: " + getUuid());
}

std::string User::getUuid() const
{
  char uuidStr[37];
  uuid_unparse(_uuid, uuidStr);

  return std::string(uuidStr);
}

void User::display() const
{
  Logging::Log("Displaying user: " + _name + " with UUID: " + getUuid());
  std::cout << "User Name: " << _name << std::endl;
  std::cout << "User UUID: " << getUuid() << std::endl;
  std::cout << "Borrowed Books ISBNs: " << std::endl;
  for (const auto &isbn : _borrowedBooksISBNs) {
    std::cout << "- " << isbn << std::endl;
  }
}
