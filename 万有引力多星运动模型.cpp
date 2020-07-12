// 万有引力多星运动模型.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//该项目使用C++ ,搭载OpenGL，实现多星引力模拟系统

#include <iostream>
#include<GL\freeglut.h>
#include "system.h"
#include "matrix.h"
#include "FSM.h"

#define _DEBUG_

using std::cout;
using std::cin;
using std::endl;

#define W_WIDTH 1000
#define W_HIGHT 600

#ifndef _DEBUG_
int main() {
    Vector O(0, 0, 23.1), V(1, 0, 0);
    O.Rotate(Vector(0, 1, 0),PI * 8 / 5 );
    V.Rotate(Vector(0, 1, 0), PI * 8 / 5);
    cout << O << V;
}

#else
System S;
FSM myFsm;

void myinit(void);
void myReshape(GLsizei w, GLsizei h);
void display(void);
void move(int value);

GLfloat lightambient[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat lightdiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
GLfloat lightspecular[] = { 0.8f, 0.8f, 0.8f, 1.0f };
GLfloat lightpositon[] = { 0.0f , 0.0f , 0.0f ,1.0f };



mycamera camera;
float step = 1, alpha = PI * 0.5 / 180;

void processSpecialKeys(int key, int x, int y);
void processNormalKeys(unsigned char key, int x, int y);
void passiveMotion(int x, int y);

int main(int argc , char* argv[])
{
    cout << "务必按shift进入英文输入模式" << endl;
    cout << "模式选择操作说明如下：" << endl;
    cout << "先选择模型，然后选择光线衰减模式" << endl;
    cout << "输入 stable1,...,stable7,unstable1,...,unstable7 选择模型\n";
    cout << "输入 yes 选择光线衰减，no 光线不衰减" << endl;
    cout << "在光线会衰减模式下，输入 + 光线变亮 ， 输入 - 光线变暗" << endl;
    cout << "程序运行的任意时刻都可以选择模型与光线衰减模式，如果出现光线丢失（所有球都是黑色），输入 yes 可以解决" << endl;
    cout << "以下为视角控制方法:" << endl;
    cout << "w : 视角向前移动" << endl << "s :视角向后移动" << endl;
    cout << " ↑: 视角向上转动\n ↓: 视角向下转动\n ←: 视角向左转动\n →: 视角向右转动\n";

    glutInit(&argc , argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    glutInitWindowSize(W_WIDTH, W_HIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("多星系统");

    myinit();

    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
    glutTimerFunc(1, move, 0);
    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(processSpecialKeys);
//    glutPassiveMotionFunc(passiveMotion);

    glutMainLoop();

}


void myinit(void) {
    glEnable(GL_DEPTH_TEST);

    glEnable(GL_LIGHTING);

    glShadeModel(GL_SMOOTH);
}

void myReshape(GLsizei w, GLsizei h) {
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90, (GLfloat)w / h, 1, 2000);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(camera.eye().X(), camera.eye().Y(), camera.eye().Z(),
        camera.center().X(), camera.center().Y(), camera.center().Z(),
        camera.up().X(), camera.up().Y(), camera.up().Z()
    );
}

void move(int value) {
    S.simulate();
    
    glutPostRedisplay();
    glutTimerFunc(1, move, 0);
}

void display(void) {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_LIGHT1);
    glLightfv(GL_LIGHT1, GL_POSITION, lightpositon);
    glLightfv(GL_LIGHT1, GL_AMBIENT, lightambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightdiffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, lightspecular);

    if (myFsm.attenuation == true) {
        glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1);
        glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0);
        glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, myFsm.factor);
    }
    else{
        glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1);
        glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0);
        glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(camera.eye().X(), camera.eye().Y(), camera.eye().Z(),
        camera.center().X(), camera.center().Y(), camera.center().Z(),
        camera.up().X(), camera.up().Y(), camera.up().Z()
    );

    
    int i;
    for (i = 0; i < S.n; i++) {
        S.balls[i].Draw();
    }
    glutSwapBuffers();
}


void processSpecialKeys(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_UP: {
        camera.nod(alpha);
        break;
    }
    case GLUT_KEY_DOWN: {
        camera.nod(-alpha);
        break;
    }
    case GLUT_KEY_LEFT: {
        camera.shade(-alpha);
        break;
    }
    case GLUT_KEY_RIGHT: {
        camera.shade(alpha);
        break;
    }
    }
    lightpositon[0] = camera.eye().X();
    lightpositon[2] = camera.eye().Y();
    lightpositon[3] = camera.eye().Z();
//    cout << camera << std::endl;
    glutPostRedisplay();
}


void processNormalKeys(unsigned char key, int x, int y) {
    switch (key) {
    case 'w': {
        camera.forward(step);
        break;
    }
    case 's': {
        camera.forward(-step);
        break;
    }
    }
    lightpositon[0] = camera.eye().X();
    lightpositon[2] = camera.eye().Y();
    lightpositon[3] = camera.eye().Z();
    if (myFsm.nextState(key) == 1) {
        camera.reset();
        switch (myFsm.stable){
        case true: {
            S = stable_S[myFsm.select - 1];
            break;
        }
        case false: {
            S = unstable_S[myFsm.select - 1];
            break;
        }
        }
    }
    glutPostRedisplay();
}

void passiveMotion(int x, int y) {
    cout << x << "  " << y << endl;
}

#endif

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
