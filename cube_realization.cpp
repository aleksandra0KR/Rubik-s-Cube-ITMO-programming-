#include "cube.h"
#include <fstream>


using std::ifstream;
using std::ofstream;
using std::endl;


char return_letter(colors col) {
    if (col == RED) {
        return 'r';
    }
    if (col == WHITE) {
        return 'w';
    }
    if (col == ORANGE) {
        return 'o';
    }
    if (col == BLUE) {
        return 'b';
    }
    if (col == GREEN) {
        return 'g';
    }
    if (col == YELLOW) {
        return 'y';
    }
}

colors return_clor(char col) {
    if (col == 'r') {
        return RED;
    }
    if (col == 'w') {
        return WHITE;
    }
    if (col == 'o') {
        return ORANGE;
    }
    if (col == 'b') {
        return BLUE;
    }
    if (col == 'g') {
        return GREEN;
    }
    if (col == 'y') {
        return YELLOW;
    }
}

void Cube::random_situation() {
    srand(time(0));
    int number_of_flips = rand() % 50;
    for (int i = 0; i < number_of_flips; i++) {
        int command = rand() % 12;
        switch (command) {
            case 0 :
                this->right_rotation_90();
                break;
            case 1:
                this->right_rotation_against_90();
                break;
            case 2:
                this->left_rotation_90();
                break;
            case 3:
                this->left_rotation_against_90();
                break;
            case 4:
                this->up_rotation_90();
                break;
            case 5:
                this->up_rotation_against_90();
                break;
            case 6:
                this->down_rotation_90();
                break;
            case 7:
                this->down_rotation_against_90();
                break;
            case 8:
                this->front_rotation_90();
                break;
            case 9:
                this->front_rotation_against_90();
                break;
            case 10:
                this->back_rotation_90();
                break;
            case 11:
                this->back_rotation_against_90();
                break;
        }
        this->show_to_concol();
    }
}

void Cube::fill_from_the_file(const char *name_of_the_file) {
    ifstream file;
    file.open(name_of_the_file);
    char col;
    char temp[3][3];
    for (int i = 0; i < size * 2; i++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                file >> col;
                temp[i][j] = (col);
            }
        }
        if (temp[1][1] == 'r') {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    down[i][j] = return_clor(temp[i][j]);
                }
            }
        } else if (temp[1][1] == 'o') {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    up[i][j] = return_clor(temp[i][j]);
                }
            }
        } else if (temp[1][1] == 'y') {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    back[i][j] = return_clor(temp[i][j]);
                }
            }
        } else if (temp[1][1] == 'b') {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    right[i][j] = return_clor(temp[i][j]);
                }
            }
        } else if (temp[1][1] == 'w') {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    front[i][j] = return_clor(temp[i][j]);
                }
            }
        } else if (temp[1][1] == 'g') {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    left[i][j] = return_clor(temp[i][j]);
                }
            }
        }
    }

    file.close();
    cout << "reading from the file complited\n";
}

bool Cube::has_all_colors() {
    int red = 0, white = 0, yellow = 0, blue = 0, green = 0, orange = 0;
    for (int i = 0; i < size; i++) {
        for (auto col: front[i]) {
            if (return_letter(col) == 'r') {
                red++;
            }
            if (return_letter(col) == 'w') {
                white++;
            }
            if (return_letter(col) == 'o') {
                orange++;
            }
            if (return_letter(col) == 'b') {
                blue++;
            }
            if (return_letter(col) == 'g') {
                green++;
            }
            if (return_letter(col) == 'y') {
                yellow++;
            }
        }
        for (auto col: left[i]) {
            if (return_letter(col) == 'r') {
                red++;
            }
            if (return_letter(col) == 'w') {
                white++;
            }
            if (return_letter(col) == 'o') {
                orange++;
            }
            if (return_letter(col) == 'b') {
                blue++;
            }
            if (return_letter(col) == 'g') {
                green++;
            }
            if (return_letter(col) == 'y') {
                yellow++;
            }
        }
        for (auto col: right[i]) {
            if (return_letter(col) == 'r') {
                red++;
            }
            if (return_letter(col) == 'w') {
                white++;
            }
            if (return_letter(col) == 'o') {
                orange++;
            }
            if (return_letter(col) == 'b') {
                blue++;
            }
            if (return_letter(col) == 'g') {
                green++;
            }
            if (return_letter(col) == 'y') {
                yellow++;
            }
        }
        for (auto col: back[i]) {
            if (return_letter(col) == 'r') {
                red++;
            }
            if (return_letter(col) == 'w') {
                white++;
            }
            if (return_letter(col) == 'o') {
                orange++;
            }
            if (return_letter(col) == 'b') {
                blue++;
            }
            if (return_letter(col) == 'g') {
                green++;
            }
            if (return_letter(col) == 'y') {
                yellow++;
            }
        }
        for (auto col: down[i]) {
            if (return_letter(col) == 'r') {
                red++;
            }
            if (return_letter(col) == 'w') {
                white++;
            }
            if (return_letter(col) == 'o') {
                orange++;
            }
            if (return_letter(col) == 'b') {
                blue++;
            }
            if (return_letter(col) == 'g') {
                green++;
            }
            if (return_letter(col) == 'y') {
                yellow++;
            }
        }
        for (auto col: up[i]) {
            if (return_letter(col) == 'r') {
                red++;
            }
            if (return_letter(col) == 'w') {
                white++;
            }
            if (return_letter(col) == 'o') {
                orange++;
            }
            if (return_letter(col) == 'b') {
                blue++;
            }
            if (return_letter(col) == 'g') {
                green++;
            }
            if (return_letter(col) == 'y') {
                yellow++;
            }
        }
    }
    if (red == 9 and white == 9 and yellow == 9 and blue == 9 and green == 9 and orange == 9) return true;
    return false;
}

bool Cube::check() {
    bool flag = true;
    if (down[1][1] == RED) {
        if (up[1][1] != ORANGE) flag = false;
    }
    if (left[1][1] == GREEN) {
        if (right[1][1] != BLUE) flag = false;
    }
    if (front[1][1] == WHITE) {
        if (back[1][1] != YELLOW) flag = false;
    }
    return flag and has_all_colors();
}

void Cube::show() {
    ofstream out("Cube.out");
    for (int i = 0; i < size; i++) {
        out << "       ";
        for (auto col: up[i]) {
            out << return_letter(col) << " ";
        }
        out << endl;
    }

    for (int i = 0; i < size; i++) {
        for (auto col: left[i]) {
            out << return_letter(col) << " ";
        }

        out << " ";

        for (auto col: front[i]) {
            out << return_letter(col) << " ";
        }

        out << " ";

        for (auto col: right[i]) {
            out << return_letter(col) << " ";
        }
        out << " ";

        for (auto col: back[i]) {
            out << return_letter(col) << " ";
        }

        out << endl;
    }

    for (int i = 0; i < size; i++) {
        out << "       ";
        for (auto col: down[i]) {
            out << return_letter(col) << " ";
        }
        out << endl;
    }

    out << endl;
    out.close();
}


void Cube::show_to_concol() {
    cout << "This is your cube right now: " << '\n';
    for (int i = 0; i < size; i++) {
        cout << "       ";
        for (auto col: up[i]) {
            cout << return_letter(col) << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < size; i++) {
        for (auto col: left[i]) {
            cout << return_letter(col) << " ";
        }

        cout << " ";

        for (auto col: front[i]) {
            cout << return_letter(col) << " ";
        }

        cout << " ";

        for (auto col: right[i]) {
            cout << return_letter(col) << " ";
        }
        cout << " ";

        for (auto col: back[i]) {
            cout << return_letter(col) << " ";
        }

        cout << endl;
    }

    for (int i = 0; i < size; i++) {
        cout << "       ";
        for (auto col: down[i]) {
            cout << return_letter(col) << " ";
        }
        cout << endl;
    }

    cout << endl;
}

bool Cube::check_solved() {

    for (int i = 0; i < size; i++) {
        for (auto col: up[i]) {
            if (col != ORANGE) return false;
        }
    }

    for (int i = 0; i < size; i++) {
        for (auto col: down[i]) {
            if (col != RED) return false;
        }
    }

    for (int i = 0; i < size; i++) {
        for (auto col: back[i]) {
            if (col != YELLOW) return false;
        }
    }

    for (int i = 0; i < size; i++) {
        for (auto col: right[i]) {
            if (col != BLUE) return false;
        }
    }

    for (int i = 0; i < size; i++) {
        for (auto col: front[i]) {
            if (col != WHITE) return false;
        }
    }

    for (int i = 0; i < size; i++) {
        for (auto col: left[i]) {
            if (col != GREEN) return false;
        }
    }
    return true;
}

void Cube::check_solved_answer_for_cout() {
    if (check_solved()) cout << "Your cude is right\n";
    else cout << "Ooops, mistake...";
}

void Cube::check_answer_for_cout() {
    if (check()) cout << "Your cude is right and has all colers\n";
    else cout << "Ooops, mistake...";
}
