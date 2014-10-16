#pragma config(Motor,  port1,           leftRear,      tmotorVex393HighSpeed_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           leftFront,     tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port3,           rightLift,     tmotorVex393_MC29, openLoop)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                tLift,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           rightLift,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           leftLift,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           leftLift,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           rightFront,    tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port10,          rightRear,     tmotorVex393HighSpeed_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

void driveArcade(int y, int x)
{
	motor[leftFront] = motor[leftRear] = y - x;
	motor[rightFront] = motor[rightRear] = y + x;
}

//Your code wouldnt compile b/c u had a parenthese instead of a bracket.
	// I can make it move!!! Nolan wouldn't let me copy last year's code until we tested this one, but we never did...

//Copying last year's code is not a good idea because it is a different robot and if you don't write your own code and understand it really well, they you will not be able to make necessary changes on the fly at tournaments --MASON
	//It looked like a good first try, however, some of the code you removed was necessary and I have put it back in and explained it below. I have been programming for many years and am happy to help you. Do not make changes to the code without
		//running it by me first. You can reach me at 713-416-9448 or at mason2smart@gmail.com. We need to work together as a team nobody can win as an individual.
			//The robot was moving under the previous code; all that needed changing were the ports
				//and the motors for the linear slide lift (which no longer exists). ALso, I am adding the Tank drive option back in. As I previously specifically stated in a comment, the tank drive was to be used for DEBUGGING THE DRIVETRAIN in
					//order to make sure all motors are functioning properly with the right speed and torque. Andrew Lynch had asked me to add this to the program.
						//You also deleted the deadband, which made sure no slight false readings came from the joysticks in the controller when the robot is supposed to be stationary. --Mason




void setLiftSpeed(int z)
{
	motor[rightLift] = motor[leftLift] = z;
	//to other programmers, "leftArm" refers to both left arm motors and "rightArm" refers to both right arm motors --Mason
}

void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
	// Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{
	driveArcade(100, 100);
	wait1Msec(10000); //ten seconds
	driveArcade(0,0);
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol()
{
	// User control code here, inside the loop

	while (true)
	{
		bool tankdrive = false; //enable tankdrive??? -- FOR DEBUGGING
		int liftSpeed = vexRT[Ch2]; //sets liftspeed equal to vexRT[Ch2]
		while (tankdrive==false)
		{
			int DriveX = -vexRT[Ch4]; //sets drive speed variables
			int DriveY = vexRT[Ch3];
			//sets lift speed variable

				if (abs(DriveY) < 5) DriveY = 0; // Deadband
				if (abs(DriveX) < 5) DriveX = 0; // Deadband
				if (abs(liftSpeed) < 5) liftSpeed = 0; //Deadband for lift

			driveArcade(DriveY, DriveX); //drive arcade method
			setLiftSpeed(liftSpeed); //lift speed method

				if (vexRT[Btn6U] == 1) //seperate controls right side of lift
		{
			motor[rightLift]=100; //lower power for more control
		}
		if (vexRT[Btn6D] == 1)
		{
			motor[rightLift]=-15; //lower power for more control, esp. when going down
		}

		if (vexRT[Ch2]==0)
		{if (vexRT[Btn6D]==0)
			{if (vexRT[Btn6U]==0) //if button not pushed and joystick for lift not moved, then no lift on that side
		{
			motor[rightLift] = 20; //constant to keep it level at current hieght. may need to be changed
		}}}

		if (vexRT[Ch2]==0)
		{if (vexRT[Btn5D]==0)
			{if (vexRT[Btn5U]==0)//if button not pushed and joystick for lift not moved, then no lift on that side
				{if (vexRT[Btn6D]==0)
					{if (vexRT[Btn6U]==0)
	{
			motor[leftLift] = 20; //constant to keep it level at current hieght. may need to be changed
		}
		else
		{
				if (vexRT[Btn5U] == 1) //seperate controls right side of lift
		{
				motor[leftLift]=100; //lower power for more control
		}
				if (vexRT[Btn5D] == 1)
		{
				motor[leftLift]=-15; //lower power for more control, esp. when going down
						if (vexRT[Btn6U] == 1) //seperate controls right side of lift
		{
			motor[rightLift]=100; //lower power for more control
		}
			if (vexRT[Btn6D] == 1)
		{
			motor[rightLift]=-15; //lower power for more control, esp. when going down
		}
			if (vexRT[Btn6U] == 1) //seperate controls right side of lift
		{
			motor[rightLift]=100; //lower power for more control
		}
		if (vexRT[Btn6D] == 1)
		{
			motor[rightLift]=-15; //lower power for more control, esp. when going down
		}
		if (liftSpeed != 0)
		{
			setLiftSpeed(liftSpeed);
		}
		}}}}}}
		                                          ///////////////////////////////////////SEPERATE CONTROLS FOR EACH SIDE OF LIFT
	if (vexRT[Btn5U] == 1) //seperate controls right side of lift
		{
			motor[leftLift]=100; //lower power for more control
		}
		if (vexRT[Btn5D] == 1)
		{
			motor[leftLift]=-15; //lower power for more control, esp. when going down
		}


	}
		                                        ///////////////////////////////////////SEPERATE CONTROLS FOR EACH SIDE OF LIFT

		while (tankdrive==true) //Tank Drive Option For Debugging DriveTrain
		{
			motor[leftRear] = motor[leftFront] = vexRT[Ch3];
			motor[rightRear] = motor[rightFront] = vexRT[Ch2];
			liftSpeed = 0; //while in tankdrive mode, liftspeed cannot be used because vexRT[Ch2 is being used for driving]
		}




	}

	// This is the main execution loop for the user control program. Each time through the loop
	// your program should update motor + servo values based on feedback from the joysticks.

	// .....................................................................................
	// Insert user code here. This is where you use the joystick values to update your motors, etc.
	// .....................................................................................
}
