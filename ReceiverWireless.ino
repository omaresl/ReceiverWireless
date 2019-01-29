#include "Arduino.h"
#include "app_Receiver.h"
//The setup function is called once at startup of the sketch
void setup()
{
// Add your initialization code here
	app_ReceiverInit();
}

// The loop function is called in an endless loop
void loop()
{
//Add your repeated code here
	app_ReceiverTask();
}
