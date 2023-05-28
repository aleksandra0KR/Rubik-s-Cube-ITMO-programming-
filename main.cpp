#include "cube.h"

int main() {


    Cube my_cube;

    // чтение с файла
    my_cube.fill_from_the_file("file.txt");

    // проверка
    my_cube.check_answer_for_cout();

    // вывод в консоль
    my_cube.show_to_concol();

    // решение куба
    my_cube.main_solver();

    // проверка собранного куба
    my_cube.check_solved_answer_for_cout();

    // вывод в консоль
    my_cube.show_to_concol();

    // рандомная ситуация
    my_cube.random_situation();

    my_cube.main_solver();

    // вывод в файл
    my_cube.show();



    return 0;

}
