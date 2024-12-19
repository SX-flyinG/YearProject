#include <iostream>
#include <fstream>
using namespace std;

void registration(char* username, char* password);
int reg(char* username, char* password);
void LogIn(char* username, char* password);
void lobby(); // Assuming lobby() is defined elsewhere

int reg(char* username, char* password) {
    int choice;

    cout << "Write a num of move :\n0 - Exit;\n1 - Registration;\n2 - Log in;\n ";
    cin >> choice;
    cin.ignore();

    while (choice < 0 || choice > 2) {
        cout << "Write a valid num of move: ";
        cin >> choice;
        cin.ignore();
    }

    if (choice == 0) {
        // delete dynamic's values and close program
        delete[] username;
        delete[] password;
        cout << "Goodbye!" << endl;
        return 0;
    }
    else if (choice == 1) {
        registration(username, password);
    }
    else if (choice == 2) {
        LogIn(username, password);
    }

    // delete dynamic values
    delete[] username;
    delete[] password;

    return 0;
}

void registration(char* username, char* password) {
    system("cls");
    cout << "Write your nickname (max 16 letters and no space): ";
    cin.getline(username, 16);
    // Write in txt file a username of the user
    ofstream inFileName("username.txt");
    inFileName << username;
    inFileName.close();

    system("cls");
    cout << "Write your password (max 64 letters and no space): ";
    cin.getline(password, 64);
    // Write in txt file a password which user wrote
    ofstream inFilePass("password.txt");
    inFilePass << password;
    inFilePass.close();

    // Delete all history of matches because it's registration and we have a new user
    ofstream inHistoryOfMatches("history.txt");
    inHistoryOfMatches << " ";
    inHistoryOfMatches.close();

    // Go to main lobby
    lobby();
}


void LogIn(char* username, char* password) {
    system("cls");
    cout << "Write your nickname (max 16 letters and no space): ";
    cin.getline(username, 16); // Чтение username с ограничением в 15 символов + \0

    char storedUsername[17]; // Буфер для username из файла (макс. 16 символов + \0)
    ifstream usernameFile("username.txt");
    if (!usernameFile) {
        cout << "Error opening username file!" << endl;
        return;
    }
    usernameFile.getline(storedUsername, 17);
    usernameFile.close();

    system("cls");
    cout << "Write your password (max 64 letters and no space): ";
    cin.getline(password, 64); // Чтение password с ограничением в 63 символа + \0

    char storedPassword[65]; // Буфер для password из файла (макс. 64 символа + \0)
    ifstream passwordFile("password.txt");
    if (!passwordFile) {
        cout << "Error opening password file!" << endl;
        return;
    }
    passwordFile.getline(storedPassword, 65);
    passwordFile.close();


    // Сравнение строк
    if (strcmp(username, storedUsername) == 0 && strcmp(password, storedPassword) == 0) {
        cout << "Login successful!" << endl;
        // Вызов lobby() — предположительно, основная программа
        lobby();
    }
    else {
        int choice;
        system("cls");
        cout << "You wrote incorrect username or password. Do you want to try again? [0 - no; 1 - yes]: ";
        cin >> choice;
        cin.ignore(); // Убираем остаток символов из ввода
        if (choice == 1) {
            LogIn(username, password);
        }
        else {
            cout << "Goodbye!" << endl;
        }
    }
}