<<<<<<< HEAD:robotmaincodefiles/loom_code_rc.c
/*
Group #
Names:
Version 1.0
Assumptions:  None

Sensors and Motors:
	- S4 = touch 1
	- S2 = touch 2
	- S3 = color

	- MotorA = fork
	- MotorB = shuttle 1
	- MotorC = shuttle 2
	- MotorD = heddle
*/

void configureAllSensors(); //configures all sensors to standard configuration

void waitButton(TEV3Buttons button_name);
int numberOfPasses();
void flipHeddles(bool cw);
void pushFork(int pass);
void passShuttle(int pass);
void checkEmergencyPause();
void checkSpool();


task main()
{
	configureAllSensors();


	displayString(6, "Press enter fucker");
  waitButton(buttonEnter);

	nMotorEncoder[motorD]=0;
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
	const float CM_TO_ENC = 360/(2.29*PI);

	if (cw)
	{
		motor[motorD] = 10;
		while (nMotorEncoder[motorD] < 8.5*CM_TO_ENC)
		{checkEmergencyPause();}
		motor[motorD] = 0;
	}
	else
	{
		motor[motorD] = -10;
		while (nMotorEncoder[motorD] > 0)
		{checkEmergencyPause();}
		motor[motorD]=0;
	}

}

void pushFork(int pass)
{
	const float MAX_PUSH_CM = 25;
	const float CM_TO_ENC = 180/(3.91*PI);
	const float DEVIATION = 0.2; //2mm

	nMotorEncoder[motorA] = 0;

	motor[motorA] = -25;
	while (abs(nMotorEncoder[motorA]) < (MAX_PUSH_CM*CM_TO_ENC) - (pass*DEVIATION)*CM_TO_ENC)
	{checkEmergencyPause();}

	motor[motorA] = 0;
	wait1Msec(500);

	motor[motorA] = 25;
	while (nMotorEncoder[motorA] < 0)
	{checkEmergencyPause();}

	motor[motorA] = 0;
}

void passShuttle(int pass)
{
	//pass forward
	motor[motorB] = motor[motorC] = -15;
	while(!SensorValue[S4])
	{checkEmergencyPause();}	//wait until touch sensor is hit
	motor[motorB] = motor[motorC] = 0;

	flipHeddles(true);
	pushFork(pass);

	motor[motorB] = motor[motorC] = 15;
	while(!SensorValue[S2])
	{checkEmergencyPause();}	//wait until touch sensor is hit
	motor[motorB] = motor[motorC] = 0;

	flipHeddles(false);
	pushFork(pass);

}

void checkEmergencyPause()
{
	if (getButtonPress(buttonLeft) && getButtonPress(buttonRight))
	{
		motor[motorA] = motor[motorB] = motor[motorC] = motor[motorD] = 0; //immediatley stop everything
		//displayString --> terminated message

		while(!getButtonPress(buttonLeft) && !getButtonPress(buttonRight))
		{} //wait for the left and right button to be pressed again
		//create array that stores current motor value, set motors to zero, resume motors to what they originally are
	}
}

void checkSpool () {
	if (SensorValue[S3] != (int)colorRed) {
		displayString(5, "please refill spool.");
		displayString(7, "Press enter once refilled");
		while (SensorValue[S3] != (int)colorRed) 
		{}
		waitButton(buttonEnter);
	}
}



=======
/*
Group #
Names:
Version 1.0
Assumptions:  None

Sensors and Motors:
	- S4 = touch 1
	- S2 = touch 2
	- S3 = color

	- MotorA = fork
	- MotorB = shuttle 1
	- MotorC = shuttle 2
	- MotorD = heddle
*/

void configureAllSensors(); //configures all sensors to standard configuration

void waitButton(TEV3Buttons button_name);
int numberOfPasses();
void flipHeddles(bool cw);
void pushFork(int pass);
void passShuttle(int pass);
void checkEmergencyPause();


task main()
{
	configureAllSensors();


	displayString(6, "Press enter fucker");
  waitButton(buttonEnter);

	nMotorEncoder[motorD]=0;
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
	const float CM_TO_ENC = 360/(2.29*PI);

	if (cw)
	{
		motor[motorD] = 10;
		while (nMotorEncoder[motorD] < 8.5*CM_TO_ENC)
		{checkEmergencyPause();}
		motor[motorD] = 0;
	}
	else
	{
		motor[motorD] = -10;
		while (nMotorEncoder[motorD] > 0)
		{checkEmergencyPause();}
		motor[motorD]=0;
	}

}

void pushFork(int pass)
{
	const float MAX_PUSH_CM = 25;
	const float CM_TO_ENC = 180/(3.91*PI);
	const float DEVIATION = 0.2; //2mm

	nMotorEncoder[motorA] = 0;

	motor[motorA] = -25;
	while (abs(nMotorEncoder[motorA]) < (MAX_PUSH_CM*CM_TO_ENC) - (pass*DEVIATION)*CM_TO_ENC)
	{checkEmergencyPause();}

	motor[motorA] = 0;
	wait1Msec(500);

	motor[motorA] = 25;
	while (nMotorEncoder[motorA] < 0)
	{checkEmergencyPause();}

	motor[motorA] = 0;
}

void passShuttle(int pass)
{
	//pass forward
	motor[motorB] = motor[motorC] = -15;
	while(!SensorValue[S4])
	{checkEmergencyPause();}	//wait until touch sensor is hit
	motor[motorB] = motor[motorC] = 0;

	flipHeddles(true);
	pushFork(pass);

	motor[motorB] = motor[motorC] = 15;
	while(!SensorValue[S2])
	{checkEmergencyPause();}	//wait until touch sensor is hit
	motor[motorB] = motor[motorC] = 0;

	flipHeddles(false);
	pushFork(pass);

}

void checkEmergencyPause()
{
	if (getButtonPress(buttonLeft) && getButtonPress(buttonRight))
	{
		//create array that stores current motor value, set motors to zero, resume motors to what they originally are
		int motorValues[4] = { motor[MotorA], motor[MotorB], motor[MotorC], motor[MotorD] };
		motor[motorA] = motor[motorB] = motor[motorC] = motor[motorD] = 0; //immediatley stop everything
		//displayString --> terminated message

		while(!getButtonPress(buttonLeft) && !getButtonPress(buttonRight))
		{} //wait for the left and right button to be pressed again
		
		for (int index = 0; index < 4; index++)
		{
			motor[index] = motorValues[index];
		}
	}
}
>>>>>>> b700d1de04d5a7b6c2d017299b61a7f50b6b14a7:alannafile/loom_code_rc.c
