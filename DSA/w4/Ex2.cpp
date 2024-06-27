#include <fstream>
#include <iostream>
struct Student {
  std::string id;
  std::string name;
  std::string birthdate;
  bool status;
};

void PrintStudent(const Student *s) {
  std::cout << "Id: " << s->id << '\n';
  std::cout << "Name: " << s->name << '\n';
  std::cout << "Birthdate: " << s->birthdate << '\n';
  std::cout << "Graduated: " << (s->status ? "true" : "false") << '\n';
}

class SchoolClass {
 private:
  struct Node {
    Student *data;
    Node *left;
    Node *right;

    Node(Student *s);
  };
  Node *idRoot;
  Node *nameRoot;

  Node *InsertIdHelper(Node *&root, Student *student);
  void InsertNameHelper(Node *&root, Student *student);
  Student *FindHelper(Node *&root, const std::string &id);
  Student *RemoveIdHelper(Node *&root, const std::string &id);
  void RemoveNameHelper(Node *&root, Student *student);
  void PrintGraduatedHelper(Node *&root);
  void PrintAllHelper(Node *&root);
  void DeleteHelper(Node *&root);
  Node *FindMax(Node *&root);
  int SaveHelper(Node *&root, std::fstream &file);
  void RemoveGraduatedHelper(Node *&root);

 public:
  SchoolClass();
  ~SchoolClass();
  bool Insert(const Student &student);
  Student *Find(const std::string &id);
  void PrintAll();
  void PrintGraduated();
  bool Remove(const std::string &id);
  void RemoveGraduated();
  bool Save(const char *path);
};

SchoolClass::Node::Node(Student *s) : data(s), left(nullptr), right(nullptr) {}

SchoolClass::SchoolClass() : idRoot(nullptr), nameRoot(nullptr) {}

SchoolClass::~SchoolClass() {
  DeleteHelper(idRoot);
  DeleteHelper(nameRoot);
}

void SchoolClass::DeleteHelper(Node *&root) {
  if (root != nullptr) {
    DeleteHelper(root->left);
    DeleteHelper(root->right);
    delete root;
  }
}

void SchoolClass::RemoveGraduated() {
  RemoveGraduatedHelper(idRoot);
  RemoveGraduatedHelper(nameRoot);
}

void SchoolClass::RemoveGraduatedHelper(Node *&root) {
  if (root != nullptr) {
    RemoveGraduatedHelper(root->left);
    RemoveGraduatedHelper(root->right);
    if (root->data->status) Remove(root->data->id);
  }
}

bool SchoolClass::Save(const char *path) {
  std::fstream ofile(path, std::ios::out);
  if (ofile.is_open()) {
    ofile << '\n';
    int c = SaveHelper(nameRoot, ofile);
    ofile.seekp(0, std::ios::beg);
    ofile << c;
    ofile.close();
    return true;
  }
  return false;
}

int SchoolClass::SaveHelper(Node *&root, std::fstream &file) {
  if (root != nullptr) {
    int l = SaveHelper(root->left, file);
    file << root->data->id << '\n';
    file << root->data->name << '\n';
    file << root->data->birthdate << '\n';
    file << root->data->status << '\n';
    int r = SaveHelper(root->right, file);
    return l + r + 1;
  }
  return 0;
}

bool SchoolClass::Insert(const Student &student) {
  Student *stud = new Student(student);
  if (!InsertIdHelper(idRoot, stud)) return false;
  InsertNameHelper(nameRoot, stud);
  return true;
}

Student *SchoolClass::Find(const std::string &id) {
  return FindHelper(idRoot, id);
}

void SchoolClass::PrintAll() { PrintAllHelper(nameRoot); }

void SchoolClass::PrintAllHelper(Node *&root) {
  if (root != nullptr) {
    PrintAllHelper(root->left);
    PrintStudent(root->data);
    std::cout << "\n";
    PrintAllHelper(root->right);
  }
}

void SchoolClass::PrintGraduated() { PrintGraduatedHelper(nameRoot); }

void SchoolClass::PrintGraduatedHelper(Node *&root) {
  if (root != nullptr) {
    PrintGraduatedHelper(root->left);
    if (root->data->status) {
      PrintStudent(root->data);
      std::cout << "\n";
    }
    PrintGraduatedHelper(root->right);
  }
}

bool SchoolClass::Remove(const std::string &id) {
  Student *student = RemoveIdHelper(idRoot, id);
  if (!student) return false;
  RemoveNameHelper(nameRoot, student);
  delete student;
  return true;
}

Student *SchoolClass::RemoveIdHelper(Node *&root, const std::string &id) {
  if (root == nullptr)
    return nullptr;
  else if (root->data->id > id)
    return RemoveIdHelper(root->left, id);
  else if (root->data->id < id)
    return RemoveIdHelper(root->right, id);
  else {
    Student *student = root->data;
    if (root->left == nullptr && root->right == nullptr) {
      root->data = nullptr;
      delete root;
      root = nullptr;
    } else if (root->left == nullptr || root->right == nullptr) {
      Node *temp;
      if (root->left == NULL)
        temp = root->right;
      else
        temp = root->left;
      root->data = nullptr;
      delete root;
      root = temp;
    } else {
      Node *temp = FindMax(root->left);
      root->data = temp->data;
      RemoveIdHelper(root->left, temp->data->id);
    }
    return student;
  }
}

void SchoolClass::RemoveNameHelper(Node *&root, Student *student) {
  if (root == nullptr)
    return;
  else if (root->data->name > student->name)
    RemoveNameHelper(root->left, student);
  else if (root->data->name < student->name)
    RemoveNameHelper(root->right, student);
  else {
    if (root->data != student) {
      RemoveNameHelper(root->left, student);
    } else if (root->left == nullptr && root->right == nullptr) {
      root->data = nullptr;
      delete root;
      root = nullptr;
    } else if (root->left == nullptr || root->right == nullptr) {
      Node *temp;
      if (root->left == NULL)
        temp = root->right;
      else
        temp = root->left;
      Student *student = root->data;
      root->data = nullptr;
      delete root;
      root = temp;
    } else {
      Node *temp = FindMax(root->left);
      root->data = temp->data;
      RemoveNameHelper(root->left, temp->data);
    }
  }
}

SchoolClass::Node *SchoolClass::FindMax(Node *&root) {
  if (root == nullptr)
    return nullptr;
  else if (root->right != nullptr)
    return FindMax(root->right);
  return root;
}

Student *SchoolClass::FindHelper(Node *&root, const std::string &id) {
  if (root == nullptr) {
    return nullptr;
  }
  if (root->data->id == id) return root->data;
  if (root->data->id > id) return FindHelper(root->left, id);

  return FindHelper(root->right, id);
}

SchoolClass::Node *SchoolClass::InsertIdHelper(Node *&root, Student *student) {
  if (root == nullptr) {
    root = new Node(student);
    return root;
  }
  if (root->data->id == student->id) return nullptr;
  if (root->data->id > student->id) return InsertIdHelper(root->left, student);

  return InsertIdHelper(root->right, student);
}

void SchoolClass::InsertNameHelper(Node *&root, Student *student) {
  if (root == nullptr) {
    root = new Node(student);
    return;
  }
  if (root->data->name < student->name) {
    InsertNameHelper(root->right, student);
    return;
  }
  InsertNameHelper(root->left, student);
}

int main() {
  SchoolClass sc;

  std::fstream file("student.data", std::ios::in);
  if (file.is_open()) {
    int n;
    file >> n;
    Student temp;
    for (int i = 0; i < n; i++) {
      file >> temp.id;
      file >> temp.name;
      file >> temp.birthdate;
      file >> temp.status;
      if (!sc.Insert(temp))
        std::cerr << "Skipped an id duplicate in file. (" << temp.id << ")\n";
    }
  }
  file.close();

  int choice;
  do {
    std::cout << "Type a number to choose what to do:\n"
              << "7 .Remove all graduated\n"
              << "6 .Insert\n"
              << "5 .Find\n"
              << "4 .Print all\n"
              << "3 .Print graduated\n"
              << "2 .Remove\n"
              << "1 .Save\n"
              << "0 .Exit\n";
    std::cin >> choice;
    switch (choice) {
      case 7:
        sc.RemoveGraduated();
        break;
      case 6: {
        Student temp;
        std::cout << "Enter id: ";
        std::cin >> temp.id;
        std::cout << "Enter name: ";
        std::cin >> temp.name;
        std::cout << "Enter birthdate: ";
        std::cin >> temp.birthdate;
        std::cout << "Enter status: ";
        std::cin >> temp.status;
        if (sc.Insert(temp)) {
          std::cout << "Added.\n";
        } else {
          int choice2;
          do {
            std::cout << "Id duplicate do you want to replace the student in "
                         "database ?\n"
                      << "1. Yes\n"
                      << "0. No\n";
            std::cin >> choice2;
            if (choice2 == 1) {
              sc.Remove(temp.id);
              sc.Insert(temp);
              break;
            }
          } while (choice2 != 0);
        }
      }

      break;
      case 5: {
        std::string id;
        std::cout << "Enter id: ";
        std::cin >> id;
        Student *res = sc.Find(id);
        if (res) {
          PrintStudent(res);
          int choice2;
          do {
            std::cout << "Edit student ?\n"
                      << "1. Yes\n"
                      << "0. No\n";
            std::cin >> choice2;
            if (choice2 == 1) {
              Student temp;
              std::cout << "Enter id: ";
              std::cin >> temp.id;
              std::cout << "Enter name: ";
              std::cin >> temp.name;
              std::cout << "Enter birthdate: ";
              std::cin >> temp.birthdate;
              std::cout << "Enter status: ";
              std::cin >> temp.status;
              sc.Remove(id);
              sc.Insert(temp);
              break;
            }
          } while (choice2 != 0);
        } else {
          std::cout << "Student " << id << " not found.\n";
        }
      } break;
      case 4:
        sc.PrintAll();
        break;
      case 3:
        sc.PrintGraduated();
        break;
      case 2: {
        std::string id;
        std::cout << "Enter id: ";
        std::cin >> id;
        if (sc.Remove(id)) {
          std::cout << "Removed " << id << "\n";
        } else {
          std::cout << "Cant find " << id << "\n";
        }
      } break;
      case 1: {
        sc.Save("student.data");
      } break;
      default:
        break;
    }
    std::cout << "\n\n";
  } while (choice != 0);

  std::cout << "Have a nice day.";

  return 0;
}