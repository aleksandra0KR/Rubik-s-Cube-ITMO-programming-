#include "cube.h"
Cube my_cube;



void specialKeys(int key, int x, int y){
    my_cube.specialKeys_f(key, x, y);
}

void normalKeys(unsigned char key, int x, int y){
    my_cube.normalKeys_f(key, x, y);
}

void display(){
    my_cube.display_f();
}



int main(int argc, char* argv[]){
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(500,500);
  glutCreateWindow("Cube");
  glEnable(GL_DEPTH_TEST);
  glClearColor(0.2,0.2,0.2,1);
  glutDisplayFunc(display);
  glutKeyboardFunc(normalKeys);
  glutSpecialFunc(specialKeys);
  glutMainLoop();
  return 0;

}


