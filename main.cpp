#include <iostream>
#include <fstream>
using namespace std;

void add(string addTask){
    ofstream file("tasks.txt", ios::app);
    file << "[ ] "<< addTask << endl;
}

void list(){
    string line;
    int count = 1;
    ifstream file("tasks.txt");
    while(getline (file, line)){
        cout << count << ". " << line << endl;
        count++;
    }
}

void deleteTask(string taskToDelete){
    string line;
    ifstream file("tasks.txt");
    int numbTask = stoi(taskToDelete);
    int count = 1;
    int maxNumb = 0;

    while(getline (file, line)){
        maxNumb++;
    }
    if(numbTask > maxNumb || numbTask < 1){
        cout << "Task Doesn't Exist" << endl;
        return;
    }else{
        file.clear();
        file.seekg(0);
        ofstream tempFile("temp.txt");
        while(getline(file, line)){
            if(count != numbTask){
                tempFile << line << endl;
            }
            count++;
        }
    }

    file.close();
    remove("tasks.txt");
    rename("temp.txt", "tasks.txt");
}

void done(string taskDone){
    string line;
    ifstream file("tasks.txt");
    int numbTask = stoi(taskDone);
    int count = 1;
    int maxNumb = 0;

    while(getline(file, line)){
        maxNumb++;
    }
    if(numbTask > maxNumb || numbTask < 1){
        cout << "Task Doesn't Exist" << endl;
        return;
    }else{
        file.clear();
        file.seekg(0);
        ofstream tempFile("temp.txt");
        while(getline(file, line)){
            if(numbTask == count){
                size_t pos = line.find("[ ]");
                if(pos != string::npos){
                    line.replace(pos, 3, "[x]");
                    tempFile << line <<endl;
                }else{
                    cout << "Mark Already" << endl;
                    tempFile.close();
                    remove("temp.txt");
                    return;
                }
            }else{
                tempFile << line << endl;
            }
            count++;
        }
    }

    file.close();
    remove("tasks.txt");
    rename("temp.txt", "tasks.txt");
}

int main(int argc, char* argv[]){
    if(argc < 2){
        cout << "Usage: ./task <command> [argument]" <<endl;
        return 1;
    }

    string command = argv[1];
    if(argc < 3){
        if(command == "list"){
            list();
        }else{
            cout << "more specific";
        }
    }else{
        if(command == "add"){
            add(argv[2]);
        }else if (command == "delete"){
            deleteTask(argv[2]);
        }else if (command == "done"){
            done(argv[2]);
        }
    }

    return 0;
}