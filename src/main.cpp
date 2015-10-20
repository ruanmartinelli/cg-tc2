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
		// playerShots.push_back(Shot(player.getGunPosX(),
		// 							player.getGunPosY(),
		// 							player.getCurrentAngleGun(),
		// 							player.getAngle(),
		// 							player.getVelTiro(),
		// 							player.getAngleGun()));
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

	// key control
	if(keys['a'] == 1 || keys['A'] == 1) player.rotate(-player.getVelHelicoptero() * timeDifference);
	if(keys['d'] == 1 || keys['D'] == 1) player.rotate(player.getVelHelicoptero() * timeDifference);
	if(keys['w'] == 1 || keys['W'] == 1){
		// checks if next position exceeds boudaries
		if(!onArena(player, arena.getArena(), -player.getVelHelicoptero() * timeDifference))
			player.moveY(-player.getVelHelicoptero() * timeDifference);
	}
	if(keys['s'] == 1 || keys['S'] == 1){
		// checks if next position exceeds boudaries
		if(!onArena(player, arena.getArena(), player.getVelHelicoptero() * timeDifference))
			player.moveY(player.getVelHelicoptero() * timeDifference);
	}
	if(keys['+'] == 1) player.moveHelice(0.1 * timeDifference);
	if(keys['-'] == 1) player.moveHelice(-0.1 * timeDifference);

	// enemies conditional movement
	for(int i = 0; i < enemies.size() ; i++){
		float rndm = 40 + (rand() % (int)(180 - 40 + 1));
		float vel= -enemies.at(i).getVelHelicoptero() * timeDifference;
		if(onEnemy(enemies, i)){
			enemies.at(i).setCollided(true);
		}else{
			enemies.at(i).setCollided(false);
		}
		if(!enemies.at(i).getCollided() && !onArena(enemies.at(i), arena.getArena(), vel)){
			enemies.at(i).moveY(vel);
		}else{
			enemies.at(i).rotate(rndm);
			enemies.at(i).moveY(vel);
			enemies.at(i).setCollided(false);
		}
	}

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

	enemies.at(0).rotate(90 * timeDifference * directionMove);
	enemies.at(1).rotate(90 * timeDifference * directionMove);
	enemies.at(2).rotate(60 * timeDifference * directionMove);
	glutTimerFunc(nextMove,timerEnemyMovement,0);
}

void timerGasBar(int value){
	// on posto
	if(player.getFlying() && !onPosto(player, arena.getPostoAbastecimento())){
		player.decGas();
	}

	// refuels
	if(onPosto(player, arena.getPostoAbastecimento())){
		player.setGas(player.getTempoDeVoo());
	}

	glutTimerFunc((1000),timerGasBar,0);
	glutPostRedisplay();
}

void timerEnemyShooting(int value){

	for(int i = 0 ; i < enemies.size() ; i++){
		enemyShots.push_back(Shot(enemies.at(i).getGunPosX(),
									enemies.at(i).getGunPosY(),
									fmod(enemies.at(i).getAngle(),360.0),
									fmod(enemies.at(i).getAngle(),360.0),
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

	if(mouseX < x ) player.rotateGun(timeDifference* 0.1);
	if(mouseX > x )	player.rotateGun(timeDifference* -0.1);
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
	enemies.push_back(config.readEnemyHelicopter(path, ARENAX/100 * 90, ARENAY/100 * 10));
	enemies.push_back(config.readEnemyHelicopter(path, ARENAX/100 * 90, ARENAY/100 * 90));
	enemies.push_back(config.readEnemyHelicopter(path, ARENAX/100 * 10, ARENAY/100 * 90));
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

	glutPassiveMotionFunc(motion);
	glutMainLoop		();

}
