#include <iostream>
#include <string>
using namespace std;

struct Book {
    int id;
    string title;
    string author;
};

Book library[100]; // Array to store books
int countBooks = 0;

// Add Book
void addBook() {
    cout << "Enter Book ID: ";
    cin >> library[countBooks].id;
    cout << "Enter Book Title: ";
    cin.ignore();
    getline(cin, library[countBooks].title);
    cout << "Enter Author Name: ";
    getline(cin, library[countBooks].author);
    countBooks++;
    cout << "\u2705 Book added successfully!\n\n";
}

// Display All Books
void displayBooks() {
    if (countBooks == 0) {
        cout << "No books found!\n\n";
        return;
    }
    for (int i = 0; i < countBooks; i++) {
        cout << "ID: " << library[i].id
             << " | Title: " << library[i].title
             << " | Author: " << library[i].author << endl;
    }
    cout << endl;
}

// Search Book
void searchBook() {
    int id;
    cout << "Enter Book ID to search: ";
    cin >> id;
    for (int i = 0; i < countBooks; i++) {
        if (library[i].id == id) {
            cout << "\u2705 Found: ID " << library[i].id
                 << " | Title: " << library[i].title
                 << " | Author: " << library[i].author << endl << endl;
            return;
        }
    }
    cout << "\u274C Book not found!\n\n";
}

// Delete Book
void deleteBook() {
    int id;
    cout << "Enter Book ID to delete: ";
    cin >> id;
    for (int i = 0; i < countBooks; i++) {
        if (library[i].id == id) {
            for (int j = i; j < countBooks - 1; j++) {
                library[j] = library[j + 1];
            }
            countBooks--;
            cout << "\u2705 Book deleted successfully!\n\n";
            return;
        }
    }
    cout << "\u274C Book not found!\n\n";
}

int main() {
    int choice;
    do {
        cout << "====== Library Management System ======\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search Book\n";
        cout << "4. Delete Book\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: deleteBook(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n\n";
        }
    } while (choice != 5);

    return 0;
}
