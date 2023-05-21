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
                left[i].push_back(ORANGE);
                front[i].push_back(BLUE);
                right[i].push_back(RED);
                back[i].push_back(GREEN);
                up[i].push_back(YELLOW);
                down[i].push_back(WHITE);
            }
        }
    }
    void fill_from_the_file(const char* name_of_the_file);
    void show();
    bool has_all_colors();
    bool check();
};