/*
 * app_Receiver.cpp
 *
 *  Created on: 29 ene. 2019
 *      Author: Admin
 */

/* Interfaces */
#include "app_Receiver.h"

/* Variables */
static RF24 ro_Receiver(7,8);

unsigned char addresses[][6] = {"1Node","2Node"};

/* Functions */
/* **************************
 * Name: app_ReceiverInit
 * Description: TBD
 * **************************/
void app_ReceiverInit(void)
{
	ro_Receiver.begin();

	// Set the PA Level low to prevent power supply related issues since this is a
	// getting_started sketch, and the likelihood of close proximity of the devices. RF24_PA_MAX is default.
	ro_Receiver.setPALevel(RF24_PA_LOW);

	ro_Receiver.openWritingPipe(addresses[0]);
	ro_Receiver.openReadingPipe(1,addresses[1]);

	// Start the radio listening for data
	ro_Receiver.startListening();

	/* Turn Off Led */
	digitalWrite(0u,LOW); //Set low pin D0
}

/* **************************
 * Name: app_ReceiverTask
 * Description: TBD
 * **************************/
void app_ReceiverTask(void)
{
	unsigned char laub_ReceiveBuffer[6u];
	unsigned char *lp_ReceiveBuffer;
	static unsigned char rub_FailCounter;

	/* Check if something is received */
	if(ro_Receiver.available())
	{//Reception
		lp_ReceiveBuffer = laub_ReceiveBuffer;
		ro_Receiver.read(lp_ReceiveBuffer,1u);

		/* Reset Fail Counter */
		rub_FailCounter = 0u;

		/* Turn On Led */
		digitalWrite(0u,HIGH); //Set high pin D0

	}
	else
	{//Nothing received
		if(rub_FailCounter < 200u)
		{
			/* Increase Fail Counter */
			rub_FailCounter++;
		}
		else
		{
			/* Turn Off Led */
			digitalWrite(0u,LOW); //Set low pin D0
		}
	}
}
