#include<iostream>
#include<GL/glut.h>
#include<cmath>
using namespace std;
#define pi 3.14
int frame = 0;

void drawdisk(float rad) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < 32; i++) {
        float angle = 2 * pi * i / 32;
        glVertex2f(rad * cos(angle), rad * sin(angle));
    }
    glEnd();
}

void drawbase() {
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2d(300, 0);
    glVertex2d(700, 0);
    glVertex2d(700, 100);
    glVertex2d(300, 100);
    glEnd();
    glFlush();
}

void drawflag() {
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2d(500, 225);
    glVertex2d(850, 225);
    glVertex2d(850, 300);
    glVertex2d(500, 300);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2d(500, 225);
    glVertex2d(850, 225);
    glVertex2d(850, 150);
    glVertex2d(500, 150);
    glEnd();

    glColor3f(1.0, 0.3, 0.1);
    glBegin(GL_POLYGON);
    glVertex2d(500, 150);
    glVertex2d(850, 150);
    glVertex2d(850, 75);
    glVertex2d(500, 75);
    glEnd();
}

void drawchakra() {
    glColor3f(0.0, 0.0, 1.0);
    drawdisk(60); // Adjust the radius value based on the flag size
    glColor3f(1.0, 1.0, 1.0);
    drawdisk(45); // Adjust the radius value based on the flag size
    glColor3f(0.0, 0.0, 1.0);
    for (int i = 0; i < 24; i++) {
        glRotatef(360 / 24, 0, 0, 1);
        glBegin(GL_LINES);
        glVertex2f(0, 0); // Adjust the coordinates based on the flag position
        glVertex2f(60, 0); // Adjust the coordinates based on the flag position
        glEnd();
    }
}

void drawsun() {
    glColor3f(1.0, 1.0, 0.0);
    drawdisk(10);
}

void animate() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawbase();

    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(50);
    glBegin(GL_LINES);
    glVertex2d(500, 0);
    glVertex2d(500, 700);
    glEnd();
    glLineWidth(1.0);

    glPushMatrix();
    glTranslated(0, ((frame + 10) % 400), 0);
    drawflag();
    glPopMatrix();

    glPushMatrix();
    glTranslated(675, ((frame + 10) % 400) + 185, 0);
    glScaled(0.5, 0.5, 0);
    drawchakra();
    glPopMatrix();

    glPushMatrix();
    glTranslated(200, 600, 0); // Adjust the coordinates to position the sun
    glScaled(10, 10, 1);
    drawsun();
    glPopMatrix();

    glutSwapBuffers();
}


void doframe(int v) {
    frame++;
    glutPostRedisplay();
    glutTimerFunc(10, doframe, 0);
}

void init() {
    glClearColor(0.1, 0.5, 1.0, 1.0);
    gluOrtho2D(0, 1024, 0, 768);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(800, 200);
    glutCreateWindow("Flag Hoisting");
    init();
    glutDisplayFunc(animate);
    glutTimerFunc(10, doframe, 0);
    glutMainLoop();
    return 0;
}

/*#include<iostream>
#include<cmath>
#include<GL/glut.h>
using namespace std;
#define pi 3.14
int frame = 0;

void drawDisk(float rad) {
    glBegin(GL_POLYGON);
    for (int i = 0;i < 32;i++) {
        float angle = 2 * pi * i / 32;
        glVertex2f(rad * cos(angle), rad * sin(angle));
    }
    glEnd();
}

void drawBase() {
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(300, 0);
    glVertex2f(700, 0);
    glVertex2f(700, 100);
    glVertex2f(300, 100);
    glEnd();
    glFlush();
}

void drawFlag() {
    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(500, 225);
    glVertex2f(850, 225);
    glVertex2f(850, 300);
    glVertex2f(500, 300);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(500, 225);
    glVertex2f(850, 225);
    glVertex2f(850, 150);
    glVertex2f(500, 150);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.5, 0.2);
    glVertex2f(500, 150);
    glVertex2f(850, 150);
    glVertex2f(850, 75);
    glVertex2f(500, 75);
    glEnd();
}

void drawSun() {
    glColor3f(1.0, 0.5, 0.2);
    drawDisk(10);
}

void drawChakra() {
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    drawDisk(35);
    glColor3f(1.0, 1.0, 1.0);
    drawDisk(25);
    glEnd();
    for (int i = 0;i < 24;i++) {
        glRotatef(360 / 24, 0, 0, 1);
        glBegin(GL_LINES);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(0, 0);
        glVertex2f(35, 0);
        glEnd();
    }
}


void animate() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawBase();

    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(50);
    glBegin(GL_LINES);
    glVertex2f(500, 0);
    glVertex2f(500, 700);
    glEnd();
    glLineWidth(1);

    glPushMatrix();
    glTranslated(0, ((frame + 10) % 400), 0);
    drawFlag();
    glPopMatrix();

    glPushMatrix();
    glTranslated(675, ((frame + 10) % 400) + 187, 0);
    drawChakra();
    glPopMatrix();

    glPushMatrix();
    glTranslated(200, 600, 0);
    glScaled(10, 10, 0);
    drawSun();
    glPopMatrix();

    glutSwapBuffers();
}

void doframe(int v) {
    frame++;
    glutPostRedisplay();
    glutTimerFunc(10, doframe, 0);
}

void init() {
    glClearColor(0.2, 0.6, 1.0, 1.0);
    gluOrtho2D(0, 1024, 0, 768);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowPosition(800, 200);
    glutInitWindowSize(1024, 768);
    glutCreateWindow("Flag Hoisting");
    init();
    glutDisplayFunc(animate);
    glutTimerFunc(10, doframe, 0);
    glutMainLoop();
    return 0;
}
*/