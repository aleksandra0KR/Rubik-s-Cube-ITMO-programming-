#include "cube.h"

void Cube::right_rotation_90(){

    colors temp_front0 = front[0][2];
    colors temp_front1 = front[1][2];
    colors temp_front2 = front[2][2];

    front[0][2] = down[0][2];
    front[1][2] = down[1][2];
    front[2][2] = down[2][2];

    down[0][2] = back[2][0];
    down[1][2] = back[1][0];
    down[2][2] = back[0][0];

    back[0][0] = up[2][2];
    back[1][0] = up[1][2];
    back[2][0] = up[0][2];

    up[0][2] = temp_front0;
    up[1][2] = temp_front1;
    up[2][2] = temp_front2;

    colors temp[3][3];
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            temp[i][j] = right[i][j];
        }
    }

    right[0][0] = temp[2][0];
    right[0][1] = temp[1][0];
    right[0][2] = temp[0][0];

    right[1][0] = temp[2][1];
    right[1][2] = temp[0][1];

    right[2][0] = temp[2][2];
    right[2][1] = temp[1][2];
    right[2][2] = temp[0][2];

    cout << "Right rotation is completed\n";
}

void Cube::right_rotation_against_90(){

    colors temp_front02 = front[0][2];
    colors temp_front12 = front[1][2];
    colors temp_front22 = front[2][2];

    front[0][2] = up[0][2];
    front[1][2] = up[1][2];
    front[2][2] = up[2][2];

    up[0][2] = back[2][0];
    up[1][2] = back[1][0];
    up[2][2] = back[0][0];

    back[0][0] = down[2][2];
    back[1][0] = down[1][2];
    back[2][0] = down[0][2];

    down[0][2] = temp_front02;
    down[1][2] = temp_front12;
    down[2][2] = temp_front22;

    colors temp[3][3];
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            temp[i][j]  = right[i][j];
        }
    }

    right[0][0] = temp[0][2];
    right[0][1] = temp[1][2];
    right[0][2] = temp[2][2];

    right[1][0] = temp[0][1];
    right[1][2] = temp[2][1];

    right[2][0] = temp[0][0];
    right[2][1] = temp[1][0];
    right[2][2] = temp[2][0];

    cout << "Right rotation against is completed\n";
}


void Cube::left_rotation_against_90(){

    colors temp_front0 = front[0][0];
    colors temp_front1 = front[1][0];
    colors temp_front2 = front[2][0];

    front[0][0] = down[0][0];
    front[1][0] = down[1][0];
    front[2][0] = down[2][0];

    down[0][0] = back[2][2];
    down[1][0] = back[1][2];
    down[2][0] = back[0][2];

    back[0][2] = up[2][0];
    back[1][2] = up[1][0];
    back[2][2] = up[0][0];

    up[0][0] = temp_front0;
    up[1][0] = temp_front1;
    up[2][0] = temp_front2;

    colors temp[size][size];
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            temp[i][j] = left[i][j];
        }
    }

    left[0][0] = temp[0][2];
    left[0][1] = temp[1][2];
    left[0][2] = temp[2][2];

    left[1][0] = temp[0][1];
    left[1][2] = temp[2][1];

    left[2][0] = temp[0][0];
    left[2][1] = temp[1][0];
    left[2][2] = temp[2][0];

    cout << "Left rotation against is completed\n";
}


void Cube::left_rotation_90(){

    colors temp_front0 = front[0][0];
    colors temp_front1 = front[1][0];
    colors temp_front2 = front[2][0];

    front[0][0] = up[0][0];
    front[1][0] = up[1][0];
    front[2][0] = up[2][0];

    up[0][0] = back[2][2];
    up[1][0] = back[1][2];
    up[2][0] = back[0][2];

    back[0][2] = down[2][0];
    back[1][2] = down[1][0];
    back[2][2] = down[0][0];

    down[0][0] = temp_front0;
    down[1][0] = temp_front1;
    down[2][0] = temp_front2;

    colors temp[size][size];
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            temp[i][j] = left[i][j];
        }
    }

    left[0][0] = temp[2][0];
    left[0][1] = temp[1][0];
    left[0][2] = temp[0][0];

    left[1][0] = temp[2][1];
    left[1][2] = temp[0][1];

    left[2][0] = temp[2][2];
    left[2][1] = temp[1][2];
    left[2][2] = temp[0][2];

    cout << "Left rotation is completed\n";
}

void Cube::front_rotation_90(){
    colors temp_up20 = up[2][0];
    colors temp_up21 = up[2][1];
    colors temp_up22 = up[2][2];

    up[2][0] = left[2][2];
    up[2][1] = left[1][2];
    up[2][2] = left[0][2];

    left[0][2] = down[0][0];
    left[1][2] = down[0][1];
    left[2][2] = down[0][2];

    down[0][0] = right[2][0];
    down[0][1] = right[1][0];
    down[0][2] = right[0][0];

    right[0][0] = temp_up20;
    right[1][0] = temp_up21;
    right[2][0] = temp_up22;

    colors temp[size][size];
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            temp[i][j] = front[i][j];
        }
    }

    front[0][0] = temp[2][0];
    front[0][1] = temp[1][0];
    front[0][2] = temp[0][0];

    front[1][0] = temp[2][1];
    front[1][2] = temp[0][1];

    front[2][0] = temp[2][2];
    front[2][1] = temp[1][2];
    front[2][2] = temp[0][2];

    cout << "Front rotation is completed\n";
}

void Cube::front_rotation_against_90(){
    colors temp_up20 = up[2][0];
    colors temp_up21 = up[2][1];
    colors temp_up22 = up[2][2];

    up[2][0] = right[0][0];
    up[2][1] = right[1][0];
    up[2][2] = right[2][0];

    right[0][0] = down[0][2];
    right[1][0] = down[0][1];
    right[2][0] = down[0][0];

    down[0][0] = left[0][2];
    down[0][1] = left[1][2];
    down[0][2] = left[2][2];

    left[0][2] = temp_up22 ;
    left[1][2] = temp_up21;
    left[2][2] = temp_up20;

    colors temp[3][3];
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            temp[i][j] =  front[i][j];
        }
    }

    front[0][0] = temp[0][2];
    front[0][1] = temp[1][2];
    front[0][2] = temp[2][2];

    front[1][0] = temp[0][1];
    front[1][2] = temp[2][1];

    front[2][0] = temp[0][0];
    front[2][1] = temp[1][0];
    front[2][2] = temp[2][0];

    cout << "Front rotation against is completed\n";
}

void Cube::back_rotation_against_90(){
    colors temp_up00 = up[0][0];
    colors temp_up01 = up[0][1];
    colors temp_up02 = up[0][2];

    up[0][0] = left[2][0];
    up[0][1] = left[1][0];
    up[0][2] = left[0][0];

    left[0][0] = down[2][0];
    left[1][0] = down[2][1];
    left[2][0] = down[2][2];

    down[2][0] = right[2][2];
    down[2][1] = right[1][2];
    down[2][2] = right[0][2];

    right[0][2] = temp_up00;
    right[1][2] = temp_up01;
    right[2][2] = temp_up02;

    colors temp[3][3];
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            temp[i][j] = back[i][j];
        }
    }

    back[0][0] = temp[0][2];
    back[0][1] = temp[1][2];
    back[0][2] = temp[2][2];

    back[1][0] = temp[0][1];
    back[1][2] = temp[2][1];

    back[2][0] = temp[0][0];
    back[2][1] = temp[1][0];
    back[2][2] = temp[2][0];

    cout << "Back rotation against is completed\n";
}

void Cube::back_rotation_90(){

    colors temp_up00 = up[0][0];
    colors temp_up01 = up[0][1];
    colors temp_up02 = up[0][2];

    up[0][0] = right[0][2];
    up[0][1] = right[1][2];
    up[0][2] = right[2][2];

    right[0][2] = down[2][2];
    right[1][2] = down[2][1];
    right[2][2] = down[2][0];

    down[2][0] = left[0][0];
    down[2][1] = left[1][0];
    down[2][2] = left[2][0];

    left[0][0] = temp_up02;
    left[1][0] = temp_up01;
    left[2][0] = temp_up00;

    colors temp[size][size];
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            temp[i][j] = back[i][j];
        }
    }

    back[0][0] = temp[2][0];
    back[0][1] = temp[1][0];
    back[0][2] = temp[0][0];

    back[1][0] = temp[2][1];
    back[1][2] = temp[0][1];

    back[2][0] = temp[2][2];
    back[2][1] = temp[1][2];
    back[2][2] = temp[0][2];

    cout << "Back rotation is completed\n";
}

void Cube::down_rotation_90() {
    colors temp_front20 = front[2][0];
    colors temp_front21 = front[2][1];
    colors temp_front22 = front[2][2];

    front[2][0] = left[2][0];
    front[2][1] = left[2][1];
    front[2][2] = left[2][2];

    left[2][0] = back[2][0];
    left[2][1] = back[2][1];
    left[2][2] = back[2][2];

    back[2][0] = right[2][0];
    back[2][1] = right[2][1];
    back[2][2] = right[2][2];

    right[2][0] = temp_front20;
    right[2][1] = temp_front21;
    right[2][2] = temp_front22;

    colors temp[size][size];
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            temp[i][j] = down[i][j];
        }
    }

    down[0][0] = temp[2][0];
    down[0][1] = temp[1][0];
    down[0][2] = temp[0][0];

    down[1][0] = temp[2][1];
    down[1][2] = temp[0][1];

    down[2][0] = temp[2][2];
    down[2][1] = temp[1][2];
    down[2][2] = temp[0][2];

    cout << "down rotation is completed\n";
}

void Cube::down_rotation_against_90() {
    colors temp_front20 = front[2][0];
    colors temp_front21 = front[2][1];
    colors temp_front22 = front[2][2];

    front[2][0] = right[2][0];
    front[2][1] = right[2][1];
    front[2][2] = right[2][2];

    right[2][0] = back[2][0];
    right[2][1] = back[2][1];
    right[2][2] = back[2][2];

    back[2][0] = left[2][0];
    back[2][1] = left[2][1];
    back[2][2] = left[2][2];

    left[2][0] = temp_front20;
    left[2][1] = temp_front21;
    left[2][2] = temp_front22;

    colors temp[size][size];
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            temp[i][j] = down[i][j];
        }
    }

    down[0][0] = temp[0][2];
    down[0][1] = temp[1][2];
    down[0][2] = temp[2][2];

    down[1][0] = temp[0][1];
    down[1][2] = temp[2][1];

    down[2][0] = temp[0][0];
    down[2][1] = temp[1][0];
    down[2][2] = temp[2][0];

    cout << "down rotation against is completed\n";
}

void Cube::up_rotation_90() { ///
    colors temp_front00 = front[0][0];
    colors temp_front01 = front[0][1];
    colors temp_front02 = front[0][2];

    front[0][0] = left[0][0];
    front[0][1] = left[0][1];
    front[0][2] = left[0][2];

    left[0][0] = back[0][0];
    left[0][1] = back[0][1];
    left[0][2] = back[0][2];

    back[0][0] = right[0][0];
    back[0][1] = right[0][1];
    back[0][2] = right[0][2];

    right[0][0] = temp_front00;
    right[0][1] = temp_front01;
    right[0][2] = temp_front02;

    colors temp[size][size];
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            temp[i][j] = up[i][j];
        }
    }

    up[0][0] = temp[0][2];
    up[0][1] = temp[1][2];
    up[0][2] = temp[2][2];

    up[1][0] = temp[0][1];
    up[1][2] = temp[2][1];

    up[2][0] = temp[0][0];
    up[2][1] = temp[1][0];
    up[2][2] = temp[2][0];

    cout << "up rotation is completed\n";
}

void Cube::up_rotation_against_90() {
    colors temp_front00 = front[0][0];
    colors temp_front01 = front[0][1];
    colors temp_front02 = front[0][2];

    front[0][0] = right[0][0];
    front[0][1] = right[0][1];
    front[0][2] = right[0][2];

    right[0][0] = back[0][0];
    right[0][1] = back[0][1];
    right[0][2] = back[0][2];

    back[0][0] = left[0][0];
    back[0][1] = left[0][1];
    back[0][2] = left[0][2];

    left[0][0] = temp_front00;
    left[0][1] = temp_front01;
    left[0][2] = temp_front02;

    colors temp[size][size];
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            temp[i][j] = up[i][j];
        }
    }

    up[0][0] = temp[2][0];
    up[0][1] = temp[1][0];
    up[0][2] = temp[0][0];

    up[1][0] = temp[2][1];
    up[1][2] = temp[0][1];

    up[2][0] = temp[2][2];
    up[2][1] = temp[1][2];
    up[2][2] = temp[0][2];

    cout << "up rotation against is completed\n";
}
