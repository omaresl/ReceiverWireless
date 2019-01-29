/*
 * app_Receiver.h
 *
 *  Created on: 29 ene. 2019
 *      Author: Admin
 */

#ifndef APP_RECEIVER_H_
#define APP_RECEIVER_H_

#include <Arduino.h>
#include "RF24.h"

/* Public Prototypes */
extern void app_ReceiverInit(void);
extern void app_ReceiverTask(void);

#endif /* APP_RECEIVER_H_ */
