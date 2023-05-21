#include "cube.h"

int main(){

    Cube my_cube;
    //cout << my_cube.check() << '\n';
    //my_cube.fill_from_the_file("file.txt");
    //cout <<my_cube.has_all_colors() << '\n';

   // my_cube.right_rotation_90();
    //my_cube.right_rotation_against_90();
    //my_cube.left_rotation_against_90();
   // my_cube.left_rotation_90();
 // my_cube.front_rotation_90();
  //my_cube.front_rotation_against_90();
  //my_cube.back_rotation_90();
  //my_cube.back_rotation_against_90();
  //my_cube.up_rotation_90();
  //my_cube.up_rotation_against_90();
  //my_cube.down_rotation_90();
    // my_cube.down_rotation_against_90();
    my_cube.random_situation();
   // my_cube.show();
    my_cube.show_to_concol();
    cout << my_cube.check() << '\n';
    return 0;

}
