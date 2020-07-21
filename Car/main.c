#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <OpenGL/glu.h>
#include <OpenGL/gl.h>

//Góc quay của hình chữ nhật
static GLfloat goc = 0.0;

void init() {
//    Nền màu đen
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    
//    Xoay quanh trục z
    glRotatef(goc, 0.0, 0.0, 1.0);
    glColor3f(1.0, 1.0, 1.0);
    glRectf(-25.0, -25.0, 25.0, 25.0); /* vẽ hcn */
    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void spinDisplay(){
    goc = goc + 2.0;
    if (goc > 360)
        goc = goc - 360;
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y){
    switch (button){
        case GLUT_LEFT_BUTTON:
            if(state == GLUT_DOWN)
                glutIdleFunc(spinDisplay);
            break;
        case GLUT_MIDDLE_BUTTON:
            if(state == GLUT_DOWN)
                glutIdleFunc(NULL);
            break;
        default:
            break;
    }
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(250, 250);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("car");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
