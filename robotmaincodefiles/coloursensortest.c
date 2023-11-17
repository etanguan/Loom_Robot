
task main()
{
	SensorType[S3] = sensorEV3_Color;
	wait1Msec(50);
	SensorMode[S3] = modeEV3Color_Color;
	wait1Msec(50);

	string colourValues[8] = {"none","black","blue","green","yellow","red","white","brown"};
	string colour = "hello";
	string temp;
	while(!getButtonPress(ENTER_BUTTON))
	{
		for(int count = 0; count < 8; count ++)
		{
			if(SensorValue[S3] == count)
				colour = colourValues[count];
		}


		if( colour != temp )
		{
			displayString(3, colour);
			temp = colour;
		}
	}


}
