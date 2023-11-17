/*
Group #
Names:
Version 1.0
Assumptions:  None

Sensors and Motors:
	- S1 = touch 1
	- S2 = touch 2
	- S3 = color

	- MotorA = heddle
	- MotorB = shuttle 1
	- MotorC = shuttle 2
	- MotorD = fork
*/

void configureAllSensors(); //configures all sensors to standard configuration

void waitButton(TEV3Buttons button_name);
int numberOfPasses();
void flipHeddles(bool cw);
void pushFork(int pass);
void passShuttle(int pass);


task main()
{
	configureAllSensors();
	waitButton(buttonEnter);



	//int total_passes = numberOfPasses(); //a pass is back AND forth
	
	//the user input function goes HERE

	bool string_left = true;
	for (int pass = 0; pass < 5 && string_left; pass++)
	{
		//if (SensorValue[S3] == colorRed)
			passShuttle(pass);
		//else
			//string_left = false;
	}


}


void configureAllSensors()
{
    SensorType[S1] = sensorEV3_Touch;

    SensorType[S2] = sensorEV3_Touch;

    SensorType[S3] = sensorEV3_Color;
    wait1Msec(50);
    SensorMode[S3] = modeEV3Color_Color;
    wait1Msec(50);
}

void waitButton(TEV3Buttons button_name)
{
    while(!getButtonPress(button_name))
    {}
    while(getButtonPress(button_name))
    {}
}

int numberOfPasses()
{
}

void waitButton(TEV3Buttons button_name)
{
    while(!getButtonPress(button_name))
    {}

    while(getButtonPress(button_name))
    {}
}

void flipHeddles(bool cw)
{
	const float CM_TO_ENC = 180/(2.75*PI);

	if (cw)
	{
		motor[motorA] = 10;
		while (nMotorEncoder[motorA] < 7.5*CM_TO_ENC)
		{}
	}
	else
	{
		motor[motorA] = -10;
		while (nMotorEncoder[motorA] > 7.5*CM_TO_ENC)
		{}
	}

}

void pushFork(int pass)
{
	const float MAX_PUSH_CM = 15;
	const float CM_TO_ENC = 180/(2.75*PI);
	const float DEVIATION = 0.2; //2mm

	nMotorEncoder[motorD] = 0;

	motor[motorD] = 25;
	while (nMotorEncoder[motorD] < (MAX_PUSH_CM*CM_TO_ENC) - (pass*DEVIATION)*CM_TO_ENC)
	{}

	motor[motorD] = 0;
	wait1Msec(500);

	motor[motorD] = -25;
	while (nMotorEncoder[motorD] > 0)
	{}

	motor[motorD] = 0;
}

void passShuttle(int pass)
{
	//pass forward
	motor[motorB] = motor[motorC] = 15;
	while(!SensorValue[S1])
	{}	//wait until touch sensor is hit
	motor[motorB] = motor[motorC] = 0;

	pushFork(pass);
	wait1Msec(6000); //moves the fork and heddle seperatly
	flipHeddles(true);


	motor[motorB] = motor[motorC] = -15;
	while(!SensorValue[S2])
	{}	//wait until touch sensor is hit
	motor[motorB] = motor[motorC] = 0;

	pushFork(pass);
	wait1Msec(6000); //moves the fork and heddle seperatly
	flipHeddles(false);

}
