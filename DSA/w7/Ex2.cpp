/*
 * Author: H.T.Phong
 * Date: August 6, 2024
 *
 * Description:
 * This program implements a phonebook for the Monster family using a hash table
 * with linear probing for collision resolution.
 */

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

struct Entry {
  std::string name;
  std::string phone;
  bool isOccupied;
};

class PhoneBook {
 private:
  std::vector<Entry> table;
  int tsize;

  int hashCode(const std::string& key) {
    int hash = 0;
    for (char ch : key) {
      hash = (hash * 31 + ch) % tsize;
    }
    return hash;
  }

  int linearProbe(int index) { return (index + 1) % tsize; }

 public:
  PhoneBook(int size) : tsize(size), table(size) {}

  void add(const std::string& name, const std::string& phone) {
    int index = hashCode(name);
    int start_index = index;
    do {
      if (!table[index].isOccupied) {
        table[index].name = name;
        table[index].phone = phone;
        table[index].isOccupied = true;
        return;
      }
      index = linearProbe(index);
    } while (index != start_index);

    throw std::runtime_error("Hash table is full");
  }

  void remove(const std::string& name) {
    int index = hashCode(name);
    int start_index = index;
    do {
      if (table[index].isOccupied && table[index].name == name) {
        table[index].isOccupied = false;
        return;
      }
      index = linearProbe(index);
    } while (index != start_index);

    throw std::runtime_error("Monster not found in the phone book");
  }

  void update(const std::string& name, const std::string& phone) {
    int index = hashCode(name);
    int start_index = index;
    do {
      if (table[index].isOccupied && table[index].name == name) {
        table[index].phone = phone;
        return;
      }
      index = linearProbe(index);
    } while (index != start_index);

    throw std::runtime_error("Monster not found in the phone book");
  }

  std::string find(const std::string& name) {
    int index = hashCode(name);
    int start_index = index;
    do {
      if (table[index].isOccupied && table[index].name == name) {
        return table[index].phone;
      }
      index = linearProbe(index);
    } while (index != start_index);

    throw std::runtime_error("Monster not found in the phone book");
  }
};

int main() {
  PhoneBook phoneBook(10);

  try {
    phoneBook.add("Loch Ness", "191-235-2460");
    phoneBook.add("Big Foot", "288-888-8888");
    phoneBook.add("Godzilla", "312-345-987");
    phoneBook.add("Werewolf", "999-666-9999");

    std::cout << "Loch Ness: " << phoneBook.find("Loch Ness") << std::endl;
    std::cout << "Big Foot: " << phoneBook.find("Big Foot") << std::endl;

    phoneBook.update("Big Foot", "123-456-7890");
    std::cout << "Big Foot (updated): " << phoneBook.find("Big Foot")
              << std::endl;

    phoneBook.remove("Godzilla");
    std::cout << "Godzilla removed." << std::endl;

    // This will throw an error because Godzilla was removed
    std::cout << "Godzilla: " << phoneBook.find("Godzilla") << std::endl;

  } catch (const std::runtime_error& e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}