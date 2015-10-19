#include <GL/glut.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#include <cstring>
#include "XMLConfig.h"
#include "Arena.h"
#include "Helicopter.h"
#include "Utils.h"


#define ARENAX arena.getArena().getWidth()
#define ARENAY arena.getArena().getHeight()

using namespace std;

Arena arena;
XMLConfig config;
Helicopter player;
vector<Shot> playerShots;
vector<Shot> enemyShots;
vector<Helicopter> enemies;

void moveEnemies(){
	static GLdouble previousTime = 0;
	double currentTime, timeDifference;

	currentTime = glutGet(GLUT_ELAPSED_TIME);
	timeDifference = currentTime - previousTime;
	previousTime = currentTime;

	// for(int i = 0 ; i < enemies.size(); i ++){
	// 	enemies.at(i).moveY(enemies.at(i).getVelHelicoptero() * timeDifference * -1);
	// 	if(rand() % 100 > 97) enemies.at(i).rotate(45);
	// }
}

void display(void){

	glClear (GL_COLOR_BUFFER_BIT);
		// arena and helicopter
		glPushMatrix();
			arena.drawArena(ARENAX, ARENAY);
		glPopMatrix();

		if(!checkDefeat(player, ARENAX/2.0,ARENAY/2.0)){
			// shots
			glPushMatrix();
				for(int i = 0 ; i < playerShots.size() ; i++) playerShots.at(i).draw();
				if(enemyShots.size() > 0){
					for(int i = 0 ; i < enemyShots.size() ; i++) enemyShots.at(i).draw();
				}
			glPopMatrix();

			glPushMatrix();
				player.draw();
			glPopMatrix();
			glPushMatrix();
				enemies.at(0).draw();
				enemies.at(1).draw();
				enemies.at(2).draw();
			glPopMatrix();
		}

	glEnd();
	glutSwapBuffers();
}

void mouse(int button, int state, int x, int y){
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){
		player.setFlying();
	}
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && player.getFlying()){
		playerShots.push_back(Shot(player.getGunPosX(),
									player.getGunPosY(),
									player.getCurrentAngleGun(),
									player.getAngle(),
									player.getVelTiro(),
									player.getAngleGun()));
	}
}

void idle(){
	static GLdouble previousTime = 0;
    GLdouble currentTime;
    GLdouble timeDifference;

    currentTime = glutGet(GLUT_ELAPSED_TIME);
    timeDifference = currentTime - previousTime;
    previousTime = currentTime;

	if(keys['a'] == 1 || keys['A'] == 1) player.rotate(-player.getVelHelicoptero() * timeDifference);
	if(keys['d'] == 1 || keys['D'] == 1) player.rotate(player.getVelHelicoptero() * timeDifference);
	if(keys['w'] == 1 || keys['W'] == 1){
		player.moveY(-player.getVelHelicoptero() * timeDifference);
		if(keys['a'] == 1 || keys['A'] == 1) player.moveX(-player.getVelHelicoptero() * timeDifference);
		if(keys['d'] == 1 || keys['D'] == 1) player.moveX(player.getVelHelicoptero() * timeDifference);
	}
	if(keys['s'] == 1 || keys['S'] == 1){
		player.moveY(player.getVelHelicoptero() * timeDifference);
		if(keys['a'] == 1 || keys['A'] == 1) player.moveX(-player.getVelHelicoptero() * timeDifference);
		if(keys['d'] == 1 || keys['D'] == 1) player.moveX(player.getVelHelicoptero() * timeDifference);

	}
	if(keys['+'] == 1) player.moveHelice(0.1 * timeDifference);
	if(keys['-'] == 1) player.moveHelice(-0.1 * timeDifference);

	// enemy movement
	enemies.at(0).moveY(enemies.at(0).getVelHelicoptero() * timeDifference * -1);
	enemies.at(1).moveY(enemies.at(1).getVelHelicoptero() * timeDifference * -1);
	enemies.at(2).moveY(enemies.at(2).getVelHelicoptero() * timeDifference * -1);
	glutPostRedisplay();
}

void timerEnemyMovement(int value){
	int nextMove = (4 + rand() % (int)(6 - 4 + 1)) * 1000;
	int directionMove = pow(-1,(1 + rand() % (int)(2 - 1 + 1)));
	static GLdouble previousTime = 0;
	double currentTime, timeDifference;
	currentTime = glutGet(GLUT_ELAPSED_TIME);
	timeDifference = currentTime - previousTime;
	previousTime = currentTime;

	// cout << directionMove << endl;
	// cout << nextMove << endl;

	enemies.at(0).rotate(45 * timeDifference * directionMove);
	enemies.at(1).rotate(33 * timeDifference * directionMove);
	enemies.at(2).rotate(60 * timeDifference * directionMove);
	glutTimerFunc(nextMove,timerEnemyMovement,0);
}

void timerGasBar(int value){
	if(player.getFlying()){
		player.decGas();
	}
	glutTimerFunc((1000),timerGasBar,0);
	glutPostRedisplay();
}

void timerEnemyShooting(int value){
	for(int i = 0 ; i < enemies.size() ; i++){
		// enemies.at(i).setAngle(-player.getAngle());
		enemyShots.push_back(Shot(enemies.at(i).getGunPosX(),
									enemies.at(i).getGunPosY(),
									enemies.at(i).getAngle(),
									enemies.at(i).getAngle(),
									enemies.at(i).getVelTiro(),
									enemies.at(i).getAngleGun()));
	}
	glutTimerFunc(2000,timerEnemyShooting,200);

	glutPostRedisplay();
}

float mouseX = 0.0;
void motion(int x, int y){

	static GLdouble previousTime = 0;
    GLdouble currentTime;
    GLdouble timeDifference;
    currentTime = glutGet(GLUT_ELAPSED_TIME);
    timeDifference = currentTime - previousTime;
    previousTime = currentTime;

	if(mouseX < x ){
		player.rotateGun(timeDifference* 0.1);
	}
	if(mouseX > x ){
		player.rotateGun(timeDifference* -0.1);
	}
	mouseX = x;
}

int main(int argc, char* argv[]){
	char path[255];
	if(argc != 2){
		cout << "Running at default path './config/config.xml'..." << endl;
		strcpy(path, "../config/config.xml");
	}else{
		strcpy(path, argv[1]);
		strcat(path, "config.xml");
	}
	srand(time(NULL));

	config.readXML(path);
	arena.readXMLArena((config.getArena().getPath() + config.getArena().getName() + "." + config.getArena().getExtension()).c_str());
	player = config.readHelicopterConfig(path);
	player.setArena(ARENAX, ARENAY);
	enemies.push_back(config.readEnemyHelicopter(path));
	enemies.push_back(config.readEnemyHelicopter(path));
	enemies.push_back(config.readEnemyHelicopter(path));
	enemies.at(0).setAngle(0);

	glutInit 				(&argc, argv);
	glutInitDisplayMode 	(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize 		(ARENAX,ARENAY);
	glutInitWindowPosition 	(0, 0);
	glutCreateWindow 	("Arena");
	init 				(ARENAX, ARENAY);
	glutDisplayFunc		(display);
	glutMouseFunc		(mouse);
	glutIdleFunc		(idle);
	glutKeyboardFunc 	(setKeyDown);
	glutKeyboardUpFunc 	(setKeyUp);

	//timers
	glutTimerFunc((player.getTempoDeVoo() * 1000)/5, timerGasBar, 0);
	glutTimerFunc(rand() % (int)(5 - 2 + 1),timerEnemyMovement,0);
	glutTimerFunc(200,timerEnemyShooting,200);
	// glutTimerFunc((1/enemies.at(0).getFreqTiro()), timerEnemyShooting, 1/enemies.at(0).getFreqTiro());

	glutPassiveMotionFunc(motion);
	glutMainLoop		();

}
