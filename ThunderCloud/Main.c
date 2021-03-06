#pragma config(Sensor, dgtl1,  					cubeGrabber,      	sensorDigitalOut)
#pragma config(Motor,  port2,           frontLeft,    			tmotorVex393, openLoop)
#pragma config(Motor,  port3,           backLeft,      			tmotorVex393, openLoop)
#pragma config(Motor,  port4,           backRight,     			tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port5,           frontRight,    			tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port6,						rightFrontLift,		 	tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port7,     			rightBackLift,		 	tmotorVex393, openLoop)
#pragma config(Motor,  port8,		  			leftFrontLift,		 	tmotorVex393, openLoop)
#pragma config(Motor,  port9,						leftBackLift,		 		tmotorVex393, openLoop, reversed)


#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

#include "PIDController.c"


const int ARMAX = 1800;
const int ARMIN = 0;
bool solExtended = false;

void robotShutdown()
{
	motor[port1] = 0;
	motor[port2] = 0;
	motor[port3] = 0;
	motor[port4] = 0;
	motor[port5] = 0;
	motor[port6] = 0;
	motor[port7] = 0;
	motor[port8] = 0;
	motor[port9] = 0;
	motor[port10] = 0;
	SensorValue[cubeGrabber] = 0;
}


void driveArcade(int y, int x)
{
	motor[frontLeft] = motor[backLeft] = y + x;
	motor[frontRight] = motor[backRight] = y - x;
}
void driveTank(int l, int r)
{
	motor[frontLeft] = motor[backLeft] = l;
	motor[frontRight] = motor[backRight] = r;
}

void setLiftSpeed(int y, int x)
{
	motor[rightFrontLift] = motor[rightBackLift] = y + x;
	motor[leftFrontLift] = motor[leftBackLift] = y - x;
}

void setCubeGrabber()
{
	if(solExtended)
	{
		SensorValue[cubeGrabber] = 0;
	}
	else
	{
		SensorValue[cubeGrabber] = 1;
	}
	solExtended = !solExtended;
}

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
  // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}



task autonomous()
{


	AutonomousCodePlaceholderForTesting();  // Remove this function call once you have "real" code.
}



task usercontrol()
{
	// User control code here, inside the loop
	int btn6UValue = 0;
	while (true)
	{
				int driveX = vexRT[Ch4];
		  	int driveY = vexRT[Ch3] ;
		  	int liftSpeed = vexRT[Ch2];
		  	int liftCorrection = vexRT[Ch1];



				if (abs(driveY) < 8) driveY = 0; // Drive deadband
				if (abs(driveX) < 8) driveX = 0; // Drive deadband
				if (abs(liftSpeed) < 8) liftSpeed = 0; // Lift deadband

		  	driveArcade(driveY * 100 / 128, driveX * 100 / 128);
		  	setLiftSpeed(liftSpeed * 100 / 128, liftCorrection * 64 / 128);
		  	if(btn6UValue!=vexRT[Btn6U] && vexRT[Btn6U]==1)
		  	{
		  		setCubeGrabber();
		  	}
		  	btn6UValue = vexRT[Btn6U];
		  	wait1Msec(20);

	}
}
