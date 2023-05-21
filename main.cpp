#include "cube.h"

int main(){

    Cube my_cube;
    cout << my_cube.check() << '\n';
    my_cube.fill_from_the_file("file.txt");
    my_cube.show();
    return 0;

}