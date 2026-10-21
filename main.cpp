#include <iostream>
#include <string>

using namespace std;

// تعريف كلاس Stack
class Stack {
private:
    string pages[100];
    int top;

public:
    Stack() { 
        top = -1; // المكدس يبدأ فارغاً
    }

    // دالة التحقق مما إذا كان المكدس فارغاً
    bool isEmpty() {
        return top == -1;
    }

    // دالة إضافة صفحة جديدة (Push)
    void push(string page) {
        if (top >= 99) {
            cout << "History is full" << endl; // البونص
            return;
        }
        top++;
        pages[top] = page;
    }

    // دالة الرجوع للخلف وإزالة الصفحة الأخيرة (Pop)
    string pop() {
        if (isEmpty()) {
            return ""; // إذا كان فارغاً
        }
        string page = pages[top];
        top--;
        return page;
    }
};

int main() {
    Stack history;
    int choice;
    string current = "home"; // الصفحة الحالية تبدأ بـ home

    do {
        cout << "\n1. Visit page  2. Back  3. Current page  0. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore(); // للتخلص من السطر الجديد

        if (choice == 1) {
            string newPage;
            cout << "URL: ";
            getline(cin, newPage);
            
            // عند زيارة صفحة جديدة، نقوم بحفظ الصفحة الحالية في الـ Stack أولاً
            history.push(current);
            // ثم تصبح الصفحة الجديدة هي الحالية
            current = newPage;
        } 
        else if (choice == 2) {
            // زر الرجوع (Back)
            if (history.isEmpty()) {
                cout << "No previous page" << endl;
            } else {
                current = history.pop();
                cout << "You are now on: " << current << endl;
            }
        } 
        else if (choice == 3) {
            // عرض الصفحة الحالية
            cout << "You are now on: " << current << endl;
        }

    } while (choice != 0);

    return 0;
}
