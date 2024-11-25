#include <iostream>
#include <stdexcept>
#include <fstream>

using namespace std;

class MyException : public exception {
public:
    virtual const char* what() const noexcept {
        return "An error occurred";
    }
};

class MathError : public MyException {
public:
    const char* what() const noexcept override {
        return "Mathematical error occurred: division by zero";
    }
};

class MemoryError : public MyException {
public:
    const char* what() const noexcept override {
        return "Memory allocation error";
    }
};

class FileError : public MyException {
private:
    string filename;
    string errorMessage;
public:
    FileError(const string& file) : filename(file) {
        errorMessage = "File error: cannot open file " + filename;
    }

    const char* what() const noexcept override {
        return errorMessage.c_str();
    }
};

int main() {
    try {
        int a = 10, b = 0;
        if (b == 0) {
            throw MathError();
        }
        int result = a / b;

    }
    catch (const MathError& e) {
        cout << e.what() << endl;
    }

    try {
        int* ptr = new int[1000000000];
        if (!ptr) {
            throw MemoryError();
        }

    }
    catch (const MemoryError& e) {
        cout << e.what() << endl;
    }

    try {
        ifstream file("nonexistent_file.txt");
        if (!file.is_open()) {
            throw FileError("nonexistent_file.txt");
        }

    }
    catch (const FileError& e) {
        cout << e.what() << endl;
    }

    return 0;
}
