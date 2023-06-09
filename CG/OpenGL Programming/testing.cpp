#include<GL/glut.h>
#include<cmath>
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
    glColor3f(0, 0, 1);
    drawDisk(40);
    glColor3f(1, 1, 1);
    drawDisk(30);
    glEnd();
    for (int i = 0;i < 24;i++) {
        glRotatef(360 / 24, 0, 0, 1);
        glBegin(GL_LINES);
        glColor3f(0, 0, 1);
        glVertex2f(0, 0);
        glVertex2f(40, 0);
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
    glTranslatef(0, (frame + 10) % 400, 0);
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

void init() {
    glClearColor(0.2, 0.6, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0, 1000, 0, 1000);
}

void doframe(int v) {
    frame++;
    glutTimerFunc(10, doframe, 0);
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(800, 200);
    glutCreateWindow("Assignment 7 Koch Curve");
    init();
    glutDisplayFunc(animate);
    glutTimerFunc(10, doframe, 0);
    glutMainLoop();
    return 0;
}