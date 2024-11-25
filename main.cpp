/*
Author: Mohammed Atef Abd El-Kader
ID: 20231143
Date: 25 Nov 2024
Version: 3.0
*/

/*
--> Task Manager :
    A program that displays the processes running on the system. The program reads the output of the "tasklist" command and parses the
    process details (image name, PID, session name, session ID, and memory usage). The user can display the processes, sort them by image
    name, PID, or memory usage, and exit the program.
*/

#include <bits/stdc++.h>
using namespace std;

struct Process{
    string imageName;
    int PID {};
    string sessionName;
    int session {};
    string memoryUsage;
};

class TaskManager {
private:
    vector<Process> processesGroup;

    // Convert the memory usage from string to integer.
    static int convertMemoryUsage(const string& memoryUsage) {
        int memory = 0;

        // Iterate over the memory usage string and convert it to an integer.
        for (char character : memoryUsage) {
            // If the character is a digit, convert it to an integer. Otherwise, continue to the next character.
            // This is to avoid the commas in the memory usage.
            if (character >= '0' && character <= '9') {
                memory = memory * 10 + (character - '0');
            }
            else continue;
        }
        return memory;
    }

    // This function is used to split the output of the "tasklist" command into words.
    static vector<string> splitWords(const string& sentence) {
        vector<string> words;
        string word;
        bool openQuotes = false;

        for (char character : sentence) {
            if (character == '"') {
                openQuotes = !openQuotes;       // Toggle open/close state
                if (!openQuotes && !word.empty()) {
                    words.push_back(word);      // Add the word when closing quotes
                    word.clear();
                }
            }
            else if (openQuotes) {
                word += character;      // Append characters inside quotes
            }
        }
        return words;
    }

public:

    // Constructor to initialize the processes.
    TaskManager() {
        system ("tasklist /FO CSV /NH > ProcessesList.csv");
        ifstream file("ProcessesList.csv");     // Open the file.
        string line;
        // Read the file line by line.
        while (getline(file, line)) {
            // Split the line into words.
            vector<string> words = splitWords(line);
            // If the line is not empty, parse the process details.
            if (!words.empty()) {
                Process process;
                process.imageName = words[0];
                process.PID = stoi(words[1]);
                process.sessionName = words[2];
                process.session = stoi(words[3]);
                process.memoryUsage = words[4];
                processesGroup.push_back(process);
            }
        }
    };

    // Sort the processes by image name.
    void sortedByImageName() {
        // Sort the processes by image name.
        sort(processesGroup.begin(), processesGroup.end(), ([](auto firstProcess, auto secondProcess){
            // Compare the image names.
            for (int i = 0; i < min(firstProcess.imageName.size(), secondProcess.imageName.size()); ++i) {
                // If the characters are different, return the comparison result.
                // Otherwise, continue to the next character.
                if (firstProcess.imageName[i] != secondProcess.imageName[i]) {
                    return firstProcess.imageName[i] < secondProcess.imageName[i];
                }
            }
            return firstProcess.imageName.size() < secondProcess.imageName.size();
        }));
    }

    // Sort the processes by PID.
    void sortedByPID() {
        sort(processesGroup.begin(), processesGroup.end(), ([](auto firstProcess, auto secondProcess){
            // Compare the PIDs.
            return firstProcess.PID < secondProcess.PID;
        }));
    }

    // Sort the processes by PID.
    void sortedBySessionNumber() {
        sort(processesGroup.begin(), processesGroup.end(), ([](auto firstProcess, auto secondProcess){
            // Compare the PIDs.
            return firstProcess.session < secondProcess.session;
        }));
    }

    // Sort the processes by memory usage.
    void sortedByMemoryUsage() {
        sort(processesGroup.begin(), processesGroup.end(), ([](auto firstProcess, auto secondProcess){
            // Compare the memory usages.
            return convertMemoryUsage(firstProcess.memoryUsage) < convertMemoryUsage(secondProcess.memoryUsage);
        }));
    }

    // Filter the processes by session name.
    void filterSessionName(const string& sessionName) {
        cout << "\t \t \t The Processes are: " << endl << endl;
        cout << "Image Name" << setw(20) << " " << "PID" << " Session Name" << setw(8) << " " << "Session#" << setw(4) << " " << "Mem Usage" << endl;
        cout << setw(25) << setfill('=') << " " << setw(8) << "=" << " " << setw(16) << "=" << " " << setw(11) << "=" << " " << setw(12) << "=" << endl;
        // Display the processes.
        for (const auto& item : processesGroup) {
            // If the session name matches the required session name, display the process.
            if (item.sessionName == sessionName) {
                cout << setw(24) << setfill(' ') << left << item.imageName.substr(0, 24);
                cout << ' ';
                cout << setw(8) << right << item.PID;
                cout << ' ';
                cout << setw(16) << left << item.sessionName;
                cout << ' ';
                cout << setw(11) << right << item.session;
                cout << ' ';
                cout << setw(12) << right << item.memoryUsage;
                cout << endl;
            }
        }
        cout << endl;
    }

    // Display the processes.
    void displayProcess () {
        cout << "\t \t \t The Processes are: " << endl << endl;
        cout << "Image Name" << setw(20) << " " << "PID" << " Session Name" << setw(8) << " " << "Session#" << setw(4) << " " << "Mem Usage" << endl;
        cout << setw(25) << setfill('=') << " " << setw(8) << "=" << " " << setw(16) << "=" << " " << setw(11) << "=" << " " << setw(12) << "=" << endl;
        // Display the processes.
        for (const auto& item : processesGroup) {
            cout << setw(24) << setfill(' ') << left << item.imageName.substr(0, 24);
            cout << ' ';
            cout << setw(8) << right << item.PID;
            cout << ' ';
            cout << setw(16) << left << item.sessionName;
            cout << ' ';
            cout << setw(11) << right << item.session;
            cout << ' ';
            cout << setw(12) << right << item.memoryUsage;
            cout << endl;
        }
        cout << endl;
    }
};

int main () {
    cout << "\tAhlan Ya User Ya Habibi..." << endl;
    while (true) {
        cout << "Choose:" << endl;
        cout << " 1) Display Processes.\n"
                " 2) Display Sorted Processes by Image Name.\n"
                " 3) Display Sorted Processes by PID.\n"
                " 4) Display Sorted Processes by Session Number.\n"
                " 5) Display Sorted Processes by Memory Usage.\n"
                " 6) Display Filtered Processes by Session Name.\n"
                " 7) Exit Program." << endl;
        cout << "Enter Your Choice :";
        string firstChoice;
        getline(cin, firstChoice);

        // If the user wants to display the processes.
        if (firstChoice == "1") {
            TaskManager taskManger;
            taskManger.displayProcess();
        }

        // If the user wants to sort the processes by image name.
        else if (firstChoice == "2") {
            TaskManager taskManger;
            taskManger.sortedByImageName();
            taskManger.displayProcess();
        }

        // If the user wants to sort the processes by PID.
        else if (firstChoice == "3") {
            TaskManager taskManger;
            taskManger.sortedByPID();
            taskManger.displayProcess();
        }

        // If the user wants to sort the processes by session number.
        else if (firstChoice == "4") {
            TaskManager taskManger;
            taskManger.sortedBySessionNumber();
            taskManger.displayProcess();
        }

        // If the user wants to sort the processes by memory usage.
        else if (firstChoice == "5") {
            TaskManager taskManger;
            taskManger.sortedByMemoryUsage();
            taskManger.displayProcess();
        }

        // If the user wants to filter the processes by session name.
        else if (firstChoice == "6") {
            while (true) {
                cout << "Which Session Name do you want to filter by?" << endl;
                cout << " 1) By Console.\n"
                        " 2) By Services.\n"
                        " 3) Back to main menu." << endl;
                string sessionName, secondChoice;
                cout << "Enter Your Choice :";
                getline(cin, secondChoice);

                // If the user enters an invalid choice.
                if (secondChoice != "1" && secondChoice != "2" && secondChoice != "3") {
                    cout << "Please, Enter a valid choice..." << endl << endl;
                    continue;
                }

                // Set the session name based on the user's choice.
                else if (secondChoice == "1") sessionName = "Console";
                else if (secondChoice == "2") sessionName = "Services";
                // If the user wants to go back.
                else if (secondChoice == "3") break;

                // Filter the processes by the session name.
                TaskManager taskManger;
                taskManger.filterSessionName(sessionName);
                break;
            }
        }

        // If the user wants to exit the program.
        else if (firstChoice == "7") {
            cout << "\n\t==> Thanks for using my program" << endl;
            cout << "\t\t ==> See You Later...." << endl;
            break;
        }

        // If the user enters an invalid choice.
        else cout << "Please, Enter a valid choice..." << endl << endl;
    }

    return 0;
}