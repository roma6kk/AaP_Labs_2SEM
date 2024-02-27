#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void FileFunc(string& output)
{
    for (int i = 0; i < output.length(); i++)
    {
        if (output[i] % 2 != 0 && output[i] >= '0' && output[i] <= '9')
            cout << output[i];
    }
}

int main()
{
    setlocale(0, "rus");
    string input;
    string output;
    fstream file("file.txt");

    if (!file.is_open())
    {
        cout << "Не удалось открыть file.txt" << endl;
    }
    else
    {
        cout << "Введите строку: " << endl;
        getline(cin, input);
        file << input;
        file.close();
    }

    file.open("file.txt");
    if (!file.is_open())
    {
        cout << "Не удалось открыть file.txt" << endl;
    }
    else
    {
        while (getline(file, output))
        {
            cout << output << endl;
        }
        file.close();

        FileFunc(output);
    }

    return 0;
}