#include <iostream>
#include <string>
#include <ctime>
#include <map>

// Struct data
enum Status { PENDING, PROSES, SELESAI };
std::map<Status, std::string> statusMap{
{PENDING, "Pending"},
{PROSES, "Proses"},
{SELESAI, "Selesai"},
};

struct Node{
    int id;
    std::string name;
    int phoneNum;
    std::string desc;
    std::time_t time;
    Status status;
    Node *next;

  Node(): time(std::time(NULL)), next(nullptr){};
};

// Struct Queue menggunakan linkedlist
struct Queue{
  Node *head;
  Node *tail;

  // Constructor untuk mendefinisikan default head dan tail;
  Queue(): head(nullptr), tail(nullptr){};
  // Destructor untuk handle memory safety
  ~Queue(){
    while(head != nullptr)
    {
      Node *tmp = head;
      head = head->next;
      delete tmp;
    }
    tail = nullptr;
    std::cout << "Success handle memory safety" << std::endl;
  }

  // Mendefinisasikan fungsi dari Queue
  // Note: fungsi yang bukan original dari Queue didefinisasikan dengan tanda "_"
  bool _isNull();
  void _insert(const size_t index, const std::string &name, const int phoneNum, const std::string &desc);
  void _remove(size_t index);
  void pop();
  void push(const std::string &name, const int phoneNum, const std::string &desc);
  // void front();
  // void back();
  void show();
  void updateStatus(size_t index, Status newStatus);
  void showBasedOnStatus(Status status);
  void showBasedOnDesc(std::string desc);
  void showmMenu();
  size_t size();
};