#include <windows.h>
#include <GL/glut.h>

void init(void);
void tampil(void);
void mouse(int button, int state, int x, int y);
void ukuran(int, int);
void mouseMotion(int x, int y);
void keyboard(unsigned char, int, int);

float xrot=0.0f;
float yrot=0.0f;
float xdiff=0.0f;
float ydiff=0.0f;
bool mouseDown=false;
int is_depth;

void init(void){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_DEPTH_TEST);
    is_depth=1;
    glMatrixMode(GL_MODELVIEW);
}

void tampil(void){
    if (is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
        glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0,0,3,0,0,0,0,1,0);
    glRotatef(xrot, 1, 0, 0);
    glRotatef(yrot, 0, 1, 0);
    //pondasi
    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(0,-28,0);
    glScalef(43,2,15);
    glutSolidCube(3);
    glPopMatrix();
    //depan
    glBegin(GL_QUADS);
    glColor3f(0.752941,0.752941,0.752941);
    glVertex3f(-60,-25,22);
    glVertex3f(-60,25,22);
    glVertex3f(60,25,22);
    glVertex3f(60,-25,22);
    glEnd();
    //depan separo
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-62.5,-7,22.2);
    glVertex3f(-62.5,-5,22.2);
    glVertex3f(62.5,-5,22.2);
    glVertex3f(62.5,-7,22.2);
    glEnd();
    //belakang
    glBegin(GL_QUADS);
    glColor3f(0.752941,0.752941,0.752941);
    glVertex3f(-60,-25,-22);
    glVertex3f(-60,25,-22);
    glVertex3f(60,25,-22);
    glVertex3f(60,-25,-22);
    glEnd();
    //belakang separo
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-62.5,-7,-22.2);
    glVertex3f(-62.5,-5,-22.2);
    glVertex3f(62.5,-5,-22.2);
    glVertex3f(62.5,-7,-22.2);
    glEnd();
    //kanan
    glBegin(GL_QUADS);
    glColor3f(0.752941,0.752941,0.752941);
    glVertex3f(60,25,22);
    glVertex3f(60,-25,22);
    glVertex3f(60,-25,-22);
    glVertex3f(60,25,-22);
    glEnd();
    //kanan separo
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(63,-7,22.5);
    glVertex3f(63,-5,22.5);
    glVertex3f(63,-5,-22.5);
    glVertex3f(63,-7,-22.5);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor3f(0.752941,0.752941,0.752941);
    glVertex3f(-60,25,22);
    glVertex3f(-60,-25,22);
    glVertex3f(-60,-25,-22);
    glVertex3f(-60,25,-22);
    glEnd();
    //kiri separo
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-63,-7,22.5);
    glVertex3f(-63,-5,22.5);
    glVertex3f(-63,-5,-22.5);
    glVertex3f(-63,-7,-22.5);
    glEnd();
    //bawah
    glBegin(GL_QUADS);
    glColor3f(0.309804,0.309804,0.309804);
    glVertex3f(-60,-25,22);
    glVertex3f(60,-25,22);
    glVertex3f(60,-25,-22);
    glVertex3f(-60,-25,-22);
    glEnd();
    //atap rumah
    glPushMatrix();
    glColor3f(0.309804,0.309804,0.309804);
    glTranslatef(0,42,10);
    glRotatef(45,1,0,0);
    glScalef(40,1,11);
    glutSolidCube(3);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.309804,0.309804,0.309804);
    glTranslatef(0,42,-10);
    glRotatef(-45,1,0,0);
    glScalef(40,1,11);
    glutSolidCube(3);
    glPopMatrix();
    //atap rumah depan
    glPushMatrix();
    glColor3f(0.309804,0.309804,0.309804);
    glTranslatef(0,28,28);
    glRotatef(25,1,0,0);
    glScalef(40,1,10);
    glutSolidCube(3);
    glPopMatrix();
    //atap rumah belakang
    glPushMatrix();
    glColor3f(0.309804,0.309804,0.309804);
    glTranslatef(0,28,-28);
    glRotatef(-25,1,0,0);
    glScalef(40,1,10);
    glutSolidCube(3);
    glPopMatrix();
    //pintu list
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(0,-5.2,22);
    glRotatef(90,0,1,0);
    glScalef(0.5,12.5,8);
    glutSolidCube(3);
    glPopMatrix();
    //pintu
    glPushMatrix();
    glColor3f(0.6,0.6,0.6);
    glTranslatef(0,-6,22.5);
    glRotatef(90,0,1,0);
    glScalef(0.5,12,7);
    glutSolidCube(3);
    glPopMatrix();
    //list jendela kiri
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(-40,4,22);
    glRotatef(90,0,1,0);
    glScalef(0.5,6,7.4);
    glutSolidCube(3);
    glPopMatrix();
    //jendela kiri satu
    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-45,4,22.5);
    glRotatef(90,0,1,0);
    glScalef(0.5,5.5,3);
    glutSolidCube(3);
    glPopMatrix();
    //jendela kiri dua
    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-35,4,22.5);
    glRotatef(90,0,1,0);
    glScalef(0.5,5.5,3);
    glutSolidCube(3);
    glPopMatrix();
    //list jendela kanan
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(40,4,22);
    glRotatef(90,0,1,0);
    glScalef(0.5,6,7.4);
    glutSolidCube(3);
    glPopMatrix();
    //jendela kanan satu
    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(45,4,22.5);
    glRotatef(90,0,1,0);
    glScalef(0.5,5.5,3);
    glutSolidCube(3);
    glPopMatrix();
    //jendela kanan dua
    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(35,4,22.5);
    glRotatef(90,0,1,0);
    glScalef(0.5,5.5,3);
    glutSolidCube(3);
    glPopMatrix();
    //tempat tidur
    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-30,-23,-10);
    glRotatef(90,0,0,1);
    glScalef(2.5,5,8);
    glutSolidCube(3);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.6,0.6,0.6);
    glTranslatef(-30,-17,-21);
    glRotatef(90,0,1,0);
    glScalef(0.5,5,5);
    glutSolidCube(3);
    glPopMatrix();
    //figura
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.1);
    glVertex3f(-60,10,15);
    glVertex3f(-60,-10,15);
    glVertex3f(-60,-10,-15);
    glVertex3f(-60,10,-15);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-60,8,13);
    glVertex3f(-60,-8,13);
    glVertex3f(-60,-8,-13);
    glVertex3f(-60,8,-13);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.2,0.2,0.2);
    glVertex3f(-60,5,10);
    glVertex3f(-60,-5,10);
    glVertex3f(-60,-5,-10);
    glVertex3f(-60,5,-10);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6,0.6,0.6);
    glVertex3f(-60,5,10);
    glVertex3f(-60,-5,10);
    glVertex3f(-60,2,-10);
    glVertex3f(-60,5,-10);
    glEnd();
    //tv
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(60,10,15);
    glVertex3f(60,-10,15);
    glVertex3f(60,-10,-15);
    glVertex3f(60,10,-15);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.12,0.1,0.1);
    glVertex3f(60,9,13);
    glVertex3f(60,-9,13);
    glVertex3f(60,-9,-13);
    glVertex3f(60,9,-13);
    glEnd();
    //kursi tv
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(30,-23,-0);
    glRotatef(90,0,0,1);
    glScalef(2.5,5,8);
    glutSolidCube(3);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.6,0.6,0.6);
    glTranslatef(24,-15,-0);
    glRotatef(90,1,0,0);
    glScalef(1,8,3);
    glutSolidCube(3);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.6,0.6,0.6);
    glTranslatef(27,-17,-11.5);
    glRotatef(90,0,1,0);
    glScalef(1,2,3);
    glutSolidCube(3);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.6,0.6,0.6);
    glTranslatef(27,-17,11.5);
    glRotatef(90,0,1,0);
    glScalef(1,2,3);
    glutSolidCube(3);
    glPopMatrix();
    //karpet dpn tv
    glPushMatrix();
    glColor3f(0.6,0.6,0.6);
    glTranslatef(50,-25,-0);
    glRotatef(90,0,0,1);
    glScalef(0.2,5,8);
    glutSolidCube(3);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(50,-25,-0);
    glRotatef(90,0,0,1);
    glScalef(0.1,4,7);
    glutSolidCube(3);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(50,-25,-0);
    glRotatef(90,0,0,1);
    glScalef(0.1,3,6);
    glutSolidCube(3);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.3,0.3,0.3);
    glTranslatef(50,-25,-0);
    glRotatef(90,0,0,1);
    glScalef(0.1,2,5);
    glutSolidCube(3);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.1,0.1,0.1);
    glTranslatef(50,-25,-0);
    glRotatef(90,0,0,1);
    glScalef(0.1,1,4);
    glutSolidCube(3);
    glPopMatrix();

    glDisable (GL_COLOR_MATERIAL );
    glutSwapBuffers ();
}

void ukuran(int lebar, int tinggi){
    if(tinggi == 0) tinggi = 1;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50, lebar / tinggi, 5, 500);
    glTranslatef(0, -5, -150);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y){
    switch(key){
    case '5':
        if(is_depth){
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        } else{
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    } tampil();
}


void idle(){
    if(!mouseDown){
        xrot += 0.3f;
        yrot += 0.4f;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
    mouseDown = false;
}

void mouseMotion(int x, int y){
    if(mouseDown){
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(250, 80);
	glutCreateWindow("ELLEN ARNETTA - 672018186");
	init();
	glutDisplayFunc(tampil);
	glutReshapeFunc(ukuran);
    glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);

	glutIdleFunc(tampil);
	glutMainLoop();
	return 0;
}
