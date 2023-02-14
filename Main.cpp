#include <iostream>
#include <vector>
using namespace std;

class Checkers {
public:
    Checkers() {
        bool temp = true;
        for (int i = 0; i < 8 * 8; ++i) {
            if (i % 8 == 0)
                temp = !temp;

            if (temp == true) {
                field.push_back('#');
                temp = false;
            }
            else {
                field.push_back(' ');
                temp = true;
            }
        }
    }

    void CoutField() {
        char CharCord = 'A'; int IntCord = 1;

        cout << "\n\n  ";
        for (int i = 0; i < 8; ++i) { cout << "" << IntCord; IntCord += 1; } cout << "\n";

        for (int i = 0; i < 8 * 8; ++i) {
            if (i % 8 == 0 && i != 0) { cout << "\n"; }
            if (i % 8 == 0) { cout << CharCord << " "; CharCord += 1; }
            cout << field[i];
        }
    }

    void PlaceSomething(char c_pos, int i_pos, char c_posTo, int i_posTo, bool queen) {
        c_pos -= 64;  c_posTo -= 64;

        if (c_pos > 8 || c_pos < 1) {
            cout << "\nError #1, Try again\n";
            return;
        }

        if (c_posTo > 8 || c_posTo < 1) {
            cout << "\nError #2, Try again\n";
            return;
        }

        if (field[i_pos + c_pos * 8 - 9] != '#') {
            cout << "\nError #3, Try again\n";
            return;
        }

        if (field[i_posTo + c_posTo * 8 - 9] != '#') {
            cout << "\nFalse\n";
            return;
        }

        field[i_pos + c_pos * 8 - 9] = 'X';

        if (field[i_pos + c_pos * 8 - 16] == '#')
            field[i_pos + c_pos * 8 - 16] = 'x';

        if (field[i_pos + c_pos * 8 - 18] == '#')
            field[i_pos + c_pos * 8 - 18] = 'x';

        if (field[i_pos + c_pos * 8 - 0] == '#')
            field[i_pos + c_pos * 8 - 0] = 'x';

        if (field[i_pos + c_pos * 8 - 2] == '#')
            field[i_pos + c_pos * 8 - 2] = 'x';

        if (queen == true) {
            int magnifier = 9;
            for (int i = 0; i < 8; i++) {
                if (field[i_pos + c_pos * 8 + magnifier] == '#')
                    field[i_pos + c_pos * 8 + magnifier] = 'x';

                if (field[i_pos + c_pos * 8 - magnifier + 16 * i] == '#')
                    field[i_pos + c_pos * 8 - magnifier + 16 * i] = 'x';
                magnifier += 9;
            }
            magnifier = 9;
            for (int i = 0; i < 8; i++) {
                if (field[i_pos + c_pos * 8 - magnifier] == '#')
                    field[i_pos + c_pos * 8 - magnifier] = 'x';

                if (field[i_pos + c_pos * 8 - magnifier + i * 2] == '#')
                    field[i_pos + c_pos * 8 - magnifier + i * 2] = 'x';

                magnifier += 9;
            }
        }

        if (field[i_posTo + c_posTo * 8 - 9] == 'x')
            cout << "\nTrue\n";
        else
            cout << "\nFalse\n";
    }

protected:
    vector<char> field;
};

int main() {
    Checkers Game;
    int i_pos, i_posTo;
    char c_pos, c_posTo;
    bool Queen;

    Game.CoutField();

    cout << "\n---\tQueen\t---\n";
    cout << "Queen (true - 1/false - 0): "; cin >> Queen;

    cout << "\n---\tMove From\t---\n";
    cout << "Enter a capital letter: "; cin >> c_pos;
    cout << "Enter a num: "; cin >> i_pos;

    cout << "---\tTo\t---\n";
    cout << "Enter a capital letter: "; cin >> c_posTo;
    cout << "Enter a num: "; cin >> i_posTo;

    Game.PlaceSomething(c_pos, i_pos, c_posTo, i_posTo, Queen);

    return 0;
}

/*
Вихідним положенням для однієї з фігур є поле b2.
Приклад
Викличте метод, щоб перевірити, чи може звичайна переміститися з b2 в c3
Викличте метод, щоб перевірити, чи можна дамку з b2 в d4
Викличте метод, щоб перевірити, чи можна перемістити звичайну від b2 до d3
Приклад виведення
true
true
false
*/
