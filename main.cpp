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

int main(int argc, char const *argv[])
{
    
    return 0;
}

void Queue::showmMenu() {
    system("cls");
    std::cout << "\n=== MENU QUEUE LINKED LIST ===\n";
    std::cout << "1. Tambah Data (Push)\n";
    std::cout << "2. Hapus Data Pertama (Pop)\n";
    std::cout << "3. Tampilkan Semua Data\n";
    std::cout << "4. Hitung Jumlah Data\n";
    std::cout << "5. Hapus Data pada Index (Remove)\n";
    std::cout << "6. Insert Data pada Index\n";
    std::cout << "7. Update Status data pada Index\n";
    std::cout << "8. Tampilkan data berdasarkan status yang dipilih\n";
    std::cout << "9. Tampilkan data berdasarkan deskripsi yang diketik\n";
    std::cout << "0. Keluar\n";
    std::cout << "\n==============================\n";
    std::cout << "Pilih menu: ";
}

void Queue::push(const std::string &name, const int phoneNum, const std::string &desc){
  /*
    Fungsi untuk melakukan push data
    */

  Node *newNode = new Node();
  time_t currentTimeStamp;

  newNode->name = name;
  newNode->phoneNum = phoneNum;
  newNode->desc = desc;
  newNode->time = time(&currentTimeStamp);
  newNode->status = PENDING;

  // Handle jika pertama kali push(index 0)
  if(head == nullptr){
    head = newNode;
    tail = newNode;
    return;
  }
  
  Node *current = head;
  while(current -> next != nullptr){
    current = current -> next;
  }
  current -> next = newNode;
}