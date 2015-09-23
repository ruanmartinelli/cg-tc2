#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

GLfloat gx = 0.0, gy = 0.0;

#define paddleHeight 80
#define paddleWidth 10
#define baseHeight 40
#define baseWidth 100
#define radiusWheel 30

int abc[256];

void zero(){

	int i;

	for( i = 0 ; i < 256 ; i++ ) abc[i] = 0;
}

class Robo{
	public:
		GLfloat gX, gY, gTheta1, gTheta2, gTheta3, gThetaWheel, direction;
		Robo(){
			gX = 0;
			gY = -100;
			gTheta1 = 0;
			gTheta2 = 0;
			gTheta3 = 0;
			gThetaWheel = 0;
			direction = -1;
		}
		void DrawRect(int height, int width, float R, float G, float B){
			glColor3f (R, G, B);
			glBegin(GL_QUADS);
				glVertex2f(-width/2.0, 0.0);
				glVertex2f(-width/2.0, height);
				glVertex2f(width/2.0, height);
				glVertex2f(width/2.0, 0.0);
			glEnd();
		}
		void DrawCirc(int r, float R, float G, float B){
			glColor3f (R, G, B);
			glPointSize(3.0);
			glBegin(GL_POINTS);
				for(int ang = 0; ang < 360; ang = ang + 20){

					float theta = 2.0f * 3.1415 * float(ang)/360.0;

					float x = r * cosf(theta);
					float y = r * sinf(theta);

					glVertex3f(x,y,0.0);
				}

			glEnd();

		}
		void DrawArm(GLfloat x, GLfloat y, GLfloat theta1, GLfloat theta2, GLfloat theta3){
				glPushMatrix();
					glTranslatef(x, y, 0);
					glRotatef(gTheta1,0.0,0.0,1.0);
					DrawRect(paddleHeight, paddleWidth, 0.0,0.0,1.0);
					glTranslatef(x, paddleHeight, 0);
					glRotatef(gTheta2,0.0,0.0,1.0);
					DrawRect(paddleHeight, paddleWidth, 1.0,0.0,1.0);
					glTranslatef(x, paddleHeight, 0);
					glRotatef(gTheta3,0.0,0.0,1.0);
					DrawRect(paddleHeight, paddleWidth, 0.0,1.0,1.0);
				glPopMatrix();



		}
		void DrawRobot(GLfloat x, GLfloat y, GLfloat thetaWheel, GLfloat theta1, GLfloat theta2, GLfloat theta3){
			glPushMatrix();
				glTranslatef(x, y, 0);
				DrawRect(baseHeight, baseWidth, 1, 0, 0);
				DrawArm(0.0, baseHeight, gTheta1, gTheta2, gTheta3);
				// DrawArm(0.0, baseHeight*2, gTheta1, gTheta2, gTheta3);
				// DrawArm(0.0, baseHeight*3, gTheta1, gTheta2, gTheta3);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(x+baseWidth/2, y, 0);
				glRotatef(gThetaWheel, 0.0, 0.0, 1.0);
				DrawCirc(radiusWheel,1.0,1.0,1.0);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(x-baseWidth/2, y, 0);
				glRotatef(gThetaWheel, 0.0, 0.0, 1.0);
				DrawCirc(radiusWheel,1.0,1.0,1.0);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-90-baseWidth, -250.0, 0);
				DrawRect(paddleHeight*3, paddleWidth, 0.2, 0.2, 0);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(90+baseWidth, -250.0, 0);
				DrawRect(paddleHeight*3, paddleWidth, 0.2, 0.2, 0);
			glPopMatrix();



		}
		void Draw(){
			DrawRobot(gX, gY, gThetaWheel, gTheta1, gTheta2, gTheta3);
		}
		void RodaBraco1(GLfloat inc){
			gTheta1 = gTheta1 + inc;
		}
		void RodaBraco2(GLfloat inc){
			gTheta2 = gTheta2 + inc;
		}
		void RodaBraco3(GLfloat inc){
			gTheta3 = gTheta3 + inc;
		}
		void Move(){
			if(gX == -100.0) ChangeDirection();
			if(gX == 100.0) ChangeDirection();
			MoveInX(direction);

		}
		void MoveInX(GLfloat gx){
			gX = gX + gx;
			gThetaWheel -= (gx * 360.0)/(2*3.1415*radiusWheel);
		}
		void MoveInY(GLfloat gy){
			gY = gY + gy;
		}
		GLfloat GetPosX(){ return gX; }
		GLfloat GetPosY(){ return gY; }
		void ChangeDirection(){
			direction = direction * -1;
		}
};

Robo robo;
bool animate = false;
void keypress(unsigned char key, int x, int j){
	switch(key){
		case 'w':
		case 'W':
			abc['w'] = 1;
			break;
		case 'S':
		case 's':
			abc['s'] = 1;
			break;
		case 'a':
		case 'A':
			abc['a'] = 1;
			break;
		case 'D':
		case 'd':
			abc['d'] = 1;
			break;
		case 'r':
			abc['r'] = 1;
			break;
		case 'f':
			abc['f'] = 1;
			break;
		case 't':
			abc['t'] = 1;
			break;
		case 'g':
			abc['g'] = 1;
			break;
		case 'y':
			abc['y'] = 1;
			break;
		case 'h':
			abc['h'] = 1;
			break;
		case '1':
			if(animate){
				animate = false; break;
		}
			if(!animate){
				animate = true;
				break;
			}
		default:
			break;
	}
	glutPostRedisplay();
}
void keyup(unsigned char key, int x, int j){
	switch(key){
		case 'a':
		case 'A':
			abc['a'] = 0;
			break;
		case 'D':
		case 'd':
			abc['d'] = 0;
			break;
		case 'w':
		case 'W':
			abc['w'] = 0;
			break;
		case 'S':
		case 's':
			abc['s'] = 0;
			break;
		case 'r':
			abc['r'] = 0;
			break;
		case 'f':
			abc['f'] = 0;
			break;
		case 't':
			abc['t'] = 0;
			break;
		case 'g':
			abc['g'] = 0;
			break;
		case 'y':
			abc['y'] =0;
			break;
		case 'h':
			abc['h'] = 0;
			break;

			break;

	}
	glutPostRedisplay();
}

void idle(){
	if(abc['a'] == 1) robo.MoveInX(-1.0);

	if(abc['d'] == 1) robo.MoveInX(1.0);

	if(abc['w'] == 1) robo.MoveInY(1.0);

	if(abc['s'] == 1) robo.MoveInY(-1.0);

	if(abc['r'] == 1) robo.RodaBraco1(1.0);

	if(abc['f'] == 1) robo.RodaBraco1(-1.0);

	if(abc['t'] == 1) robo.RodaBraco2(1.0);

	if(abc['g'] == 1) robo.RodaBraco2(-1.0);

	if(abc['y'] == 1) robo.RodaBraco3(1.0);

	if(abc['h'] == 1) robo.RodaBraco3(-1.0);

	if(animate) robo.Move();

	glutPostRedisplay();
}

void display(void){
	glClear (GL_COLOR_BUFFER_BIT);
	robo.Draw();
	glEnd();

	glutSwapBuffers();
}

void init (void){
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-250.0, 250.0, -250.0, 250.0, -100.0, 100.0);
}

int main(int argc, char** argv){
	zero();
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (700, 700);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("hello");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keypress);
	glutKeyboardUpFunc(keyup);
	glutIdleFunc(idle);
	// glutMouseFunc(mouse);

	glutMainLoop();

	return 0;
}
