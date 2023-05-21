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

void Cube::random_situation() {
    int number_of_flips = rand() % 12;
    for(int i = 0; i < number_of_flips; i++){
        int command = rand() % 12;
        switch(command){
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
    bool WY = down[1][1] == RED and up[1][1] == ORANGE;
    bool BG = left[1][1] == GREEN and right[1][1] == BLUE;
    bool RO = front[1][1] == WHITE and back[1][1] == YELLOW;
    return WY and BG and RO and has_all_colors();
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
        }            out << " ";

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
        }            cout << " ";

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
    /*
    for(int i = 0; i < size; i++){
       for (auto col: front[i]){
            cout<<return_letter(col)<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i = 0; i < size; i++){
        for (auto col: back[i]){
            cout<<return_letter(col)<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i = 0; i < size; i++){
        for (auto col: left[i]){
            cout<<return_letter(col)<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i = 0; i < size; i++){
        for (auto col: right[i]){
            cout<<return_letter(col)<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i = 0; i < size; i++){
        for (auto col: up[i]){
            cout<<return_letter(col)<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i = 0; i < size; i++){
        for (auto col: down[i]){
            cout<<return_letter(col)<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
*/
}
