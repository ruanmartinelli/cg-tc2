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
float gx = 0.0, gy = 0.0;

void moveEnemies(){
	static GLdouble previousTime = 0;
	double currentTime, timeDiference;

	currentTime = glutGet(GLUT_ELAPSED_TIME);
	timeDiference = currentTime - previousTime;
	previousTime = currentTime;

	for(int i = 0 ; i < enemies.size(); i ++){
		enemies.at(i).moveY(enemies.at(i).getVelHelicoptero() * timeDiference * -1);
		if(rand() % 100 > 97) enemies.at(i).rotate(45);
	}
}

void display(void){
	cout << player.getGunPosX() <<endl;
	glClear (GL_COLOR_BUFFER_BIT);

		// arena and helicopter
		glPushMatrix();
			arena.drawArena(ARENAX, ARENAY);
		glPopMatrix();

		// gun
		glPushMatrix();
			for(int i = 0 ; i < playerShots.size() ; i++) playerShots.at(i).draw();
			if(enemyShots.size()>0){
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
			//moveEnemies();

		glPopMatrix();

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
    GLdouble timeDiference;

    currentTime = glutGet(GLUT_ELAPSED_TIME);
    timeDiference = currentTime - previousTime;
    previousTime = currentTime;

	if(keys['a'] == 1 || keys['A'] == 1) player.rotate(-player.getVelHelicoptero() * timeDiference);
	if(keys['d'] == 1 || keys['D'] == 1) player.rotate(player.getVelHelicoptero() * timeDiference);
	if(keys['w'] == 1 || keys['W'] == 1){
		player.moveY(-player.getVelHelicoptero() * timeDiference);
		if(keys['a'] == 1 || keys['A'] == 1) player.moveX(-player.getVelHelicoptero() * timeDiference);
		if(keys['d'] == 1 || keys['D'] == 1) player.moveX(player.getVelHelicoptero() * timeDiference);
	}
	if(keys['s'] == 1 || keys['S'] == 1){
		player.moveY(player.getVelHelicoptero() * timeDiference);
		if(keys['a'] == 1 || keys['A'] == 1) player.moveX(-player.getVelHelicoptero() * timeDiference);
		if(keys['d'] == 1 || keys['D'] == 1) player.moveX(player.getVelHelicoptero() * timeDiference);

	}
	if(keys['+'] == 1) player.moveHelice(0.1 * timeDiference);
	if(keys['-'] == 1) player.moveHelice(-0.1 * timeDiference);

	glutPostRedisplay();
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
									enemies.at(i).getCurrentAngleGun(),
									enemies.at(i).getAngle(),
									enemies.at(i).getVelTiro(),
									enemies.at(i).getAngleGun()));
	}
	// glutTimerFunc(value,timerEnemyShooting,value);
	glutTimerFunc(2000,timerEnemyShooting,200);

	glutPostRedisplay();
}

float mouseX = 0.0;
void motion(int x, int y){
	static GLdouble previousTime = 0;
    GLdouble currentTime;
    GLdouble timeDiference;
    currentTime = glutGet(GLUT_ELAPSED_TIME);
    timeDiference = currentTime - previousTime;
    previousTime = currentTime;

	if(mouseX < x ){
		player.rotateGun(timeDiference* 0.1);
	}
	if(mouseX > x ){
		player.rotateGun(timeDiference* -0.1);
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
	glutTimerFunc((player.getTempoDeVoo() * 1000)/5, timerGasBar, 0);
	// glutTimerFunc((1/enemies.at(0).getFreqTiro()), timerEnemyShooting, 1/enemies.at(0).getFreqTiro());
	glutTimerFunc(200,timerEnemyShooting,200);

	glutPassiveMotionFunc(motion);
	glutMainLoop		();

}
