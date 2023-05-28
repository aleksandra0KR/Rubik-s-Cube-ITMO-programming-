#include "cube.h"
#include <GL/glut.h>

void Cube::call_coloring() {
    coloring(left, 2);
    coloring(right, 3);
    coloring(front, 0);
    coloring(back, 1);
    coloring(up, 4);
    coloring(down, 5);
}


void Cube::coloring(vector<vector<colors>> &side, int k) {
    vector<palette> tmp;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (side[i][j] == RED) {
                tmp.push_back({1, 0, 0});
            } else if (side[i][j] == GREEN) {
                tmp.push_back({0, 1, 0});
            } else if (side[i][j] == BLUE) {
                tmp.push_back({0, 0, 1});
            } else if (side[i][j] == WHITE) {
                tmp.push_back({1, 1, 1});
            } else if (side[i][j] == YELLOW) {
                tmp.push_back({1, 1, 0});
            } else if (side[i][j] == ORANGE) {
                tmp.push_back({1, 0.45, 0});
            }
        }
    }
    if (k == 0)
        square(0, 0, 0, 0, tmp); //front
    else if (k == 1)
        square(0, 1, 0, 180, tmp); //back
    else if (k == 2)
        square(0, 1, 0, 90, tmp); // left
    else if (k == 3)
        square(0, 1, 0, -90, tmp); // right
    else if (k == 4)
        square(1, 0, 0, 90, tmp); // up
    else if (k == 5)
        square(1, 0, 0, -90, tmp); //down
}


void Cube::square_mini(palette tmp, x_y_z a) {
    glPushMatrix();
    glTranslatef(a.x, a.y, a.z);
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(tmp.RED, tmp.GREEN, tmp.BLUE);
    glVertex3f(0, 0, 0);
    glVertex3f(-1, 0, 0);
    glVertex3f(-1, 1, 0);
    glVertex3f(0, 1, 0);
    glEnd();
    glPopMatrix();

}

void Cube::square(float x, float y, float z, float rotate, vector<palette> tmp) {
    glPushMatrix();
    glRotatef(rotate, x, y, z);
    glPushMatrix();
    glTranslatef(1.7, -1.7, -0.1);
    glScalef(3.4, 3.4, 1);
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0, 0, 0);
    glVertex3f(0, 0, -1.6);
    glVertex3f(-1, 0, -1.6);
    glVertex3f(-1, 1, -1.6);
    glVertex3f(0, 1, -1.6);
    glEnd();
    glPopMatrix();
    square_mini(tmp[0], {-0.6, 0.6, -1.71});
    square_mini(tmp[1], {0.5, 0.6, -1.71});
    square_mini(tmp[2], {1.6, 0.6, -1.71});
    square_mini(tmp[3], {-0.6, -0.5, -1.71});
    square_mini(tmp[4], {0.5, -0.5, -1.71});
    square_mini(tmp[5], {1.6, -0.5, -1.71});
    square_mini(tmp[6], {-0.6, -1.6, -1.71});
    square_mini(tmp[7], {0.5, -1.6, -1.71});
    square_mini(tmp[8], {1.6, -1.6, -1.71});
    glPopMatrix();
}

void Cube::display_f() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glRotatef(rotate_x, 1, 0, 0);
    glRotatef(rotate_y, 0, 1, 0);
    glPushMatrix();
    glScalef(0.3, 0.3, 0.3);
    call_coloring();
    glutPostRedisplay();
    glPopMatrix();
    glFlush();
    glutSwapBuffers();
}

void Cube::specialKeys_f(int key, int x, int y) {
    if (key == GLUT_KEY_RIGHT)
        rotate_y -= 5;

    else if (key == GLUT_KEY_LEFT)
        rotate_y += 5;

    else if (key == GLUT_KEY_UP)
        rotate_x += 5;

    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 5;
    glutPostRedisplay();
}

void Cube::normalKeys_f(unsigned char key, int x, int y) {
    if(key == '1')
        right_rotation_90();
    else if (key == '2')
        right_rotation_against_90();
    else if (key == '3')
        left_rotation_90();
    else if (key == '4')
        left_rotation_against_90();

    else if (key == '5')
        front_rotation_90();
    else if (key == '6')
        front_rotation_against_90();
    else if (key == '7')
        back_rotation_90();
    else if (key == '8')
        back_rotation_against_90();

    else if (key == '9')
        down_rotation_90();
    else if (key == '0')
        down_rotation_against_90();
    else if (key == '-')
        up_rotation_90();
    else if (key == '=')
        up_rotation_against_90();
    else if(key == 'r'){
        random_situation();
    }
    else if(key == 's'){
        main_solver();
    }
    else if(key == 'c'){
        check_solved_answer_for_cout();
    }

}
