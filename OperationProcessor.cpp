#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>
#include <sstream>

using namespace std;

class Operation {
private:
    long double value;
    vector<string> commands;

public:
    Operation(long double initialValue, const vector<string>& initialCommands) {
        value = initialValue;
        commands = initialCommands;
    }

    void processCommands() {
        for (const auto& commandLine : commands) {
            istringstream stream(commandLine);
            string operation;
            long double number;
            stream >> operation >> number; // Считываем операцию и число из строки

            if (operation == "+") {
                value += number;
            } else if (operation == "*") {
                value *= number;
            } else if (operation == "sin") {
                // Здесь предполагается, что если операция - sin, то следующее число игнорируется.
                // Пересчитываем только значение value.
                value = sin(value);
            } else {
                cout << "Unknown operation: " << operation << endl;
            }
            cout << "Result: " << value << endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian"); // Устанавливаем локаль для корректного отображения Кириллицы
    long double initialValue;
    cin >> initialValue;

    vector<string> commands;
    string path = "myFile.txt";
    ifstream fileStream(path);

    if (!fileStream.is_open()) {
        cout << "Ошибка при открытии файла." << endl;
    } else {
        cout << "Файл успешно открыт." << endl;
        string line;
        while (getline(fileStream, line)) {
            if (!line.empty()) {
                commands.push_back(line);
                cout << line << endl; // Выводим строку для проверки
            }
        }
        fileStream.close();
    }

    Operation operation(initialValue, commands);
    operation.processCommands();

    return 0;
}
