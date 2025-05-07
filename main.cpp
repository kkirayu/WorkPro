#include <iostream>
#include <queue>
#include <string>

using namespace std;

enum Status {
    Pending,
    InProgress,
    Done
};

string statusToString(Status s) {
    switch (s) {
        case Pending: return "Pending";
        case InProgress: return "In Progress";
        case Done: return "Done";
        default: return "Unknown";
    }
}

struct Task {
    int id;
    string title;
    Status status;

    Task(int id, string title) {
        this->id = id;
        this->title = title;
        this->status = Pending;
    }
};

queue<Task> taskQueue;
int taskCounter = 1;

void addTask() {
    string title;
    cout << "Masukkan nama tugas: ";
    cin.ignore();
    getline(cin, title);
    Task newTask(taskCounter++, title);
    taskQueue.push(newTask);
    cout << "Tugas berhasil ditambahkan!\n";
}

void processTask() {
    if (taskQueue.empty()) {
        cout << "Tidak ada tugas yang menunggu.\n";
        return;
    }

    Task current = taskQueue.front();
    taskQueue.pop();
    cout << "Memproses tugas: " << current.title << "\n";

    current.status = InProgress;
    cout << "Status: " << statusToString(current.status) << "\n";

    // Simulasi selesai
    current.status = Done;
    cout << "Status: " << statusToString(current.status) << " ✅\n";
}

void showTasks() {
    if (taskQueue.empty()) {
        cout << "Tidak ada tugas dalam antrian.\n";
        return;
    }

    queue<Task> temp = taskQueue;
    cout << "\n=== Daftar Tugas ===\n";
    while (!temp.empty()) {
        Task t = temp.front();
        temp.pop();
        cout << "ID: " << t.id << " | Judul: " << t.title
             << " | Status: " << statusToString(t.status) << "\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\n=== MENU WORK PROGRESS ===\n";
        cout << "1. Tambah Tugas\n";
        cout << "2. Proses Tugas\n";
        cout << "3. Lihat Semua Tugas\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> choice;

        switch (choice) {
            case 1: addTask(); break;
            case 2: processTask(); break;
            case 3: showTasks(); break;
            case 0: cout << "Keluar dari program.\n"; break;
            default: cout << "Pilihan tidak valid.\n";
        }
    } while (choice != 0);

    return 0;
}
