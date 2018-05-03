#ifndef PHYSICS_H
#define PHYSICS_H

#include "opencv2/opencv.hpp"
#include "Ball.h"
#include "Hand.h"

#define TOTAL_DIRECTIONS 60
#define BLOOD_AMOUNT 5
#define BLOOD_SPREAD 6
#define BLOOD_TTL 5000
#define NUM_SPIKES 16
//#define DAMAGE_PER_BLOOD 300
#define DAMAGE_PER_BLOOD 1

using namespace cv;
using namespace std;

class Physics {
private:
	bool initialized;
	bool disappearingBalls;
	bool enableKoike, enableSpin, enableBlood, isGame;
	bool finish;
	int MAX_BALL_COUNT;
	int standardBallsCount;
	vector<Ball> balls;
	double total_time;
	double last_ball_creation_time;
	
	int w, h;
	double gravity, friction;
	int botBorderHeight;

	Point spikePoints[NUM_SPIKES][3];

	Mat face;

	Ball generateBlood(int, float);
	void generateBall();
	bool killBall(int);
	void drawOverlay(Mat&, Mat&, Point);
	Mat rotate(Mat&, double);

	void updateSpikes();
	int findDirection(int[]);
	float mod2PI(float);
	bool inRange(float, float, float);
	bool mirrorPointAtStraightLine(Point2d&, float);

public:
	Physics();
	void init(int, Mat, int, bool, bool, bool, bool, bool);
	bool isInitialized() { return initialized; }
	void tick(double, Mat&, vector<Hand>&);
	Mat &draw(Mat&);
	Mat &drawGameOverOverlay(Mat&);
	
	int dist(int x1, int y1, int x2, int y2) { return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)); }
};

#endif