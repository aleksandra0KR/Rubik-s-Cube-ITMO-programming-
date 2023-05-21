#include "cube.h"
#include <fstream>

using std::ifstream;
using std::ofstream;
using std::endl;


char return_letter(colors col){
    if (col == RED) {
        return 'r';
    }
    if (col == WHITE) {
        return 'w';
    }
    if (col == ORANGE) {
        return 'o';
    }
    if (col == BLUE ) {
        return 'b';
    }
    if (col == GREEN) {
        return  'g';
    }
    if (col == YELLOW) {
        return 'y';
    }
}

colors return_clor(char col){
    if (col == 'r') {
        return RED;
    }
    if (col == 'w') {
        return WHITE;
    }
    if (col == 'o') {
        return ORANGE;
    }
    if (col == 'b' ) {
        return BLUE ;
    }
    if (col == 'g' ) {
        return GREEN ;
    }
    if (col == 'y' ) {
        return YELLOW;
    }
}

void Cube::fill_from_the_file(const char* name_of_the_file) {
    ifstream file;
    file.open(name_of_the_file);
        char col;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                file >> col;
                front[i][j] = return_clor(col);
            }
        }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            file >> col;
            back[i][j] = return_clor(col);
        }
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            file >> col;
            left[i][j] = return_clor(col);
        }
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            file >> col;
            right[i][j] = return_clor(col);
        }
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            file >> col;
            up[i][j] = return_clor(col);
        }
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            file >> col;
            down[i][j] = return_clor(col);
        }
    }

    file.close();
    cout << "reading from the file complited\n";
}

bool Cube::has_all_colors() {
    int red = 0, white = 0, yellow = 0, blue = 0, green = 0, orange = 0;
    for(int i = 0; i < size; i++){
        for(auto col: front[i]){
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
        for(auto col: left[i]){
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
        for(auto col: right[i]){
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
        for(auto col: back[i]){
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
        for(auto col: down[i]){
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
        for(auto col: up[i]){
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
    if (red == 9 and white == 9 and yellow == 9 and blue == 9 and green == 9 and orange == 9)  return true;
    return false;
}

bool Cube::check(){
    bool WY = down[1][1] == WHITE and up[1][1] == YELLOW;
    bool BG = left[1][1] == BLUE and right[1][1] == GREEN;
    bool RO = front[1][1] == RED and back[1][1] == ORANGE;
    return WY and BG and RO and has_all_colors();
}


void Cube::show() {
    ofstream out("Cube.out");
    out << endl;
    for (int i = 0; i < 3; i++) {
        out << "    ";
        for (int j = 0; j < 3; j++) {
            out << return_letter(up[i][j]);
        }
        out << endl;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            out << return_letter(left[i][j]);
        }

        out << " ";

        for (int j = 0; j < 3; j++) {
            out << return_letter(front[i][j]);
        }

        out << " ";

        for (int j = 0; j < 3; j++) {
            out << return_letter(right[i][j]);
        }            out << " ";

        for (int j = 0; j < 3; j++) {
            out << return_letter(right[i][j]);
        }

        out << " ";

        for (int j = 0; j < 3; j++) {
            out << return_letter(back[i][j]);
        }

        out << endl;
    }

    for (int i = 0; i < 3; i++) {
        out << "    ";
        for (int j = 0; j < 3; j++) {
            out << return_letter(down[i][j]);
        }
        out << endl;
    }

    out << endl;
    out.close();
}