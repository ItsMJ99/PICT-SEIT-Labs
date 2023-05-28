#include<GL/glut.h>
#include<math.h>

void bresenhamCircle(float x, float y, float radius) {
    float cx, cy, d, r;
    r = radius;
    cx = x;
    cy = y;
    d = 3 - 2 * r;

}

void draw() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0, 1024, 768, 0);
    glColor3f(0.0, 0.0, 1.0);
    bresenhamCircle(500, 400, 20);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowPosition(800, 500);
    glutInitWindowSize(1024, 768);
    glutCreateWindow("Assignment 3 Bresenham Circle");
    glutDisplayFunc(draw);
    glutMainLoop();
}