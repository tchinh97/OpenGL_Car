#include <GLUT/glut.h>
#include <OpenGL/glu.h>
#include <OpenGL/gl.h>

static GLfloat spin = 0;
static GLfloat move = 0;

void init(){
    glClearColor(0, 0, 0, 0);   //black
//    glClearColor(1, 1, 1, 1);   // white
}

void reshape(int w, int h){
//    ma tran phep chieu
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
//    phep chieu phoi canh
    gluPerspective(40, (GLfloat) w / (GLfloat) h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);
//    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    
//     than xe
    glPushMatrix();
    glScalef(2, 1, 1);
    glTranslatef(move*0.55+0.24, 0.675, 0);
    glColor3f(1, 0, 0);
    glutWireCube(1);
    glPopMatrix();
    
//     banh xe 1
    glPushMatrix();
    glTranslatef(move, 0, 0);
    glRotatef(spin, 0, 0, 1);
    glColor3f(0, 1, 1);
    glutSolidTorus(0.1, 0.2, 10, 10);
    glPopMatrix();
    
//    banh xe 2
    glPushMatrix();
    glTranslatef(move, 0, 0.5);
    glRotatef(spin, 0, 0, 1);
    glColor3f(0, 1, 1);
    glutSolidTorus(0.1, 0.2, 10, 10);
    glPopMatrix();
    
//    banh xe 3
    glPushMatrix();
    glTranslatef(move + 1, 0, 0);
    glRotatef(spin, 0, 0, 1);
    glColor3f(1, 1, 1);
    glutSolidTorus(0.1, 0.2, 10, 10);
    glPopMatrix();
    
//    banh xe 4
    glPushMatrix();
    glTranslatef(move + 1, 0, 0.5);
    glRotatef(spin, 0, 0, 1);
    glColor3f(1, 1, 1);
    glutSolidTorus(0.1, 0.2, 10, 10);
    glPopMatrix();
    
    glutSwapBuffers();
    glFlush();
}

// Di chuyen sang phai theo truc Ox
void spinRight(void) {
    move = move + 0.01;
    spin = spin + 2.0;
    glutPostRedisplay();
}

// Di chuyen sang trai theo truc Ox
void spinLeft(void){
    move = move - 0.01;
    spin = spin - 2.0;
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
    switch (button) {
//            chuột phải
        case GLUT_RIGHT_BUTTON:
            if (state == GLUT_DOWN)
                    glutIdleFunc(spinRight);
            break;
//            chuột trái
        case GLUT_LEFT_BUTTON:
            if(state == GLUT_DOWN)
                glutIdleFunc(spinLeft);
            break;
//            nút giữa chuột
        case GLUT_MIDDLE_BUTTON:
            if (state == GLUT_DOWN)
                glutIdleFunc(NULL);
            break;
        default:
            break;
    }
}



int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("car");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
