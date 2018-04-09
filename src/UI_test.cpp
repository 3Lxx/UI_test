///////////////////////////////////////////////////////////////////////////////
/*!	\file UI_test.cpp
*
*   \brief Copyright (c) 2018 K&J Schmittschneider AG
*
*   \par Purpose: program to test the i2c devices PCA9555 and PCA9685
*   \author	LL
*   \date 	09.04.2018
*	\version	V0.1
*
* 	$Revision: 0.1 $
* 	$Id: UI_test.cpp,v 0.1 2018-04-09 $
******************************************************************************/
#include "PCA9555.h"
#include "PCA9685.h"

#include<iostream>
using namespace std;
#include <bitset>
#include <unistd.h>

//#define TEST_PCA9555 
#define TEST_PCA9685

void testPCA9555();
void testPCA9685();

int main (int argc, char *argv[]) 
{
#ifdef TEST_PCA9555
	testPCA9555();
#endif
#ifdef TEST_PCA9685
	testPCA9685();
#endif
	return 0;
} 

void testPCA9555()
{
	uint8_t ret = 0;
	PCA9555 ui_input(1,0x20);	//connected to i2c-1 on address 0x20 (default)
	while(1)
	{
		ret = ui_input.getInput(0);
		cout<<"PCA9555 Port 0 value: "<<bitset<8>(ret)<<endl;
		ret = ui_input.getInput(1);
		cout<<"PCA9555 Port 1 value: "<<bitset<8>(ret)<<endl;
		usleep(500);
	}
}

void testPCA9685()
{
	PCA9685 ui_output(1,0x40);	//connected to i2c-1 on address 0x40 (default)
	ui_output.setPWMFreq(100);	//set PWM frequency to 100 Hz
	while(1)
	{
		for(int i = 0; i<16;i++)
		{
			for(int j = 0; j<16; j++)
			{
				if(j==i) ui_output.setPWM(j,4095);
				else ui_output.setPWM(j,0);
			}
			usleep(500);				
		}
	}	
}
