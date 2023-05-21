#pragma once
#include <vector>
#include <iostream>
using std::cout;
using std::vector;

enum colors{
    GREEN,
    WHITE,
    BLUE,
    YELLOW,
    ORANGE,
    RED
};

class Cube{
private:
    int const size = 3;
    vector<vector<colors>> left;
    vector<vector<colors>> front;
    vector<vector<colors>> right;
    vector<vector<colors>> back;
    vector<vector<colors>> up;
    vector<vector<colors>> down;

public:
    Cube(){
        for(int i = 0; i < size; i++){
            left.push_back({});
            front.push_back({});
            right.push_back({});
            back.push_back({});
            up.push_back({});
            down.push_back({});
            for(int j = 0; j < size; j++){
                left[i].push_back(GREEN);
                front[i].push_back(WHITE);
                right[i].push_back(BLUE);
                back[i].push_back(YELLOW);
                up[i].push_back(ORANGE);
                down[i].push_back(RED);
            }
        }
    }
    void random_situation();
    void fill_from_the_file(const char* name_of_the_file);
    void show();
    void show_to_concol();
    bool has_all_colors();
    bool check();


    void right_rotation_90();
    void right_rotation_against_90();
    void left_rotation_90();
    void left_rotation_against_90();

    void front_rotation_90();
    void front_rotation_against_90();
    void back_rotation_90();
    void back_rotation_against_90();

    void down_rotation_90();
    void down_rotation_against_90();
    void up_rotation_90();
    void up_rotation_against_90();
};
