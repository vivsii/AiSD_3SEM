#include <iostream>
#include <Windows.h>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void hanoi(int n, int source, int target, int dop, std::vector<std::string>& actions) {
    if (n == 1) {
        actions.push_back("Переместить диск (" + to_string(n) + ") с " + to_string(source) + " на " + to_string(target) + " стержень");
        return;
    }
    hanoi(n - 1, source, dop, target, actions);
    actions.push_back("Переместить диск (" + to_string(n) + ") с " + to_string(source) + " на " + to_string(target) + " стержень");
    hanoi(n - 1, dop, target, source, actions);
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N, k;
    cout << "Введите количество дисков (N): ";
    cin >> N;
    cout << "Введите количество стержней (k): ";
    cin >> k;

    if (N < 1 || k < 3) {
        cout << "Некорректные входные данные." << endl;
        return 1;
    }

    vector<string> actions;
    hanoi(N, 1, k, k - 1, actions);

    for (const string& action : actions) {
        cout << action << std::endl;
    }

    return 0;

}