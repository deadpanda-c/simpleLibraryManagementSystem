#include <iostream>
#include "Library.hpp"

int main(void)
{
  try {
    Library library;

    library.addBook(std::shared_ptr<Book>(new Book("1984", "George Orwell", "1234-5678", false, "")));
    library.addBook(std::shared_ptr<Book>(new Book("To Kill a Mockingbird", "Harper Lee", "2345-6789", false, "")));
    library.addBook(std::shared_ptr<Book>(new Book("The Great Gatsby", "F. Scott Fitzgerald", "3456-7890", false, "")));

    library.addUser(std::shared_ptr<User>(new User("Toto")));
    library.addUser(std::shared_ptr<User>(new User("Tata")));
    library.addUser(std::shared_ptr<User>(new User("Titi")));

    std::vector<std::array<uint8_t, 16>> userUuids = library.getUserUuids();
    std::vector<std::string> bookisbns = library.getBooks();

    // borrow books
    for (size_t i = 0; i < userUuids.size() && i < bookisbns.size(); ++i) {
      uuid_t userUuid;
      std::copy(userUuids[i].begin(), userUuids[i].end(), userUuid);
      library.borrowBook(userUuid, bookisbns[i]);
    }

    library.displayUsers();
    library.displayBooks();
  } catch (const std::exception& e) {
    Logging::LogError("An error occurred: " + std::string(e.what()));
  }
  return 0;
}
