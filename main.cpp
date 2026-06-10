#include <iostream>
#include <fstream>
using namespace std;

void add(string addTask) {
    ofstream file("tasks.txt", ios::app);
    file << addTask << endl;
}

void list() {
    string line;
    int numb = 1;
    ifstream file("tasks.txt");
    while(getline (file, line)) {
        cout << numb << ". " << line << endl;
        numb++;
    }
}

void deleteTask(string taskToDelete) {
    string line;
    ifstream file("tasks.txt");
    ofstream tempFile("temp.txt");
    int numbTask = stoi(taskToDelete);
    int numb = 1;
    int maxNumb = 0;

    while (getline (file, line)) {
        maxNumb++;
    }
    if (numbTask > maxNumb || numbTask < 1){
        cout << "Task Doesn't Exist" << endl;
        return;
    } else {
        file.clear();
        file.seekg(0);
        while (getline (file, line)) {
            if (numb != numbTask) {
                tempFile << line << endl;
            }
            numb++;
        }
    }

    file.close();
    tempFile.close();
    remove("tasks.txt");
    rename("temp.txt", "tasks.txt");
}

int main(int argc, char* argv[]) {
    if (argc < 2){
        cout << "Usage: ./task <command> [argument]" <<endl;
        return 1;
    } 
    string command = argv[1];
    if (argc < 3){
        if (command == "list") {
            list();
        } else {
            cout << "more specific";
        }
    } else {
        if (command == "add") {
            add(argv[2]);
        } else if (command == "delete") {
            deleteTask(argv[2]);
        }
    }

    return 0;
}