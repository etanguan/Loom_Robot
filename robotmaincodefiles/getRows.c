

int getRows()
{
	const int MIN_ROWS = 2;
	const int MAX_ROWS = 20;
	const int INIT_ROWS = 5;
	displayString(3, "Select number of rows");
	int rows = INIT_ROWS;
	displayString( 6, "%d", rows);
	int temp = rows;
	while(!getButtonPress(ENTER_BUTTON))
	{

		if( getButtonPress(UP_BUTTON) )
		{
			while( !getButtonPress(UP_BUTTON) )
			{	}
			while( getButtonPress(UP_BUTTON) )
			{	}
			rows += 2;
		}

		if( getButtonPress(DOWN_BUTTON) )
		{
			while( !getButtonPress(DOWN_BUTTON) )
			{	}
			while( getButtonPress(DOWN_BUTTON) )
			{	}
			rows -= 2;
		}

		if( rows<MIN_ROWS || rows>MAX_ROWS )
			rows = temp;

		if( temp != rows )
		{
			displayString( 6, "%d", rows);
			temp = rows;
		}
	}
	return rows;
}

task main()
{
	getRows();


}
