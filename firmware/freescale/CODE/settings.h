/*
	The rapidradio project
	
	Author: Michal Okulski, The RapidRadio Team
	Website: http://rapidradio.pl
	Email: michal@rapidradio.pl
	Created: 11/2015
	
	Inspired by AVR's RFM70 libraries. 
	
	------------------------------------------------------------------------------------
	The MIT License (MIT)

	Copyright (c) 2015 Michal Okulski (micas.pro)

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in
	all copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
	THE SOFTWARE.
	------------------------------------------------------------------------------------
*/

#ifndef SETTINGS_H
#define SETTINGS_H

#include "typedef.h"
#include <stddef.h>
#include "PE_Types.h"

#define RFM_SENDING                   1
#define RFM_LISTENING                 0
#define RFM_IDLE                      2

typedef struct _Settings
{
    
  uint8_t _unused_start;
  
	uint8_t channel;
	uint8_t address[4];
	bool ack;
	bool verbose;
	uint8_t retries;
	uint8_t state;           // RFM_IDLE or RFM_SENDING or RFM_LISTENING
	
	uint8_t _unused_end;
  
} Settings;

extern volatile Settings settings; 
extern volatile bool settingsUpdated;

extern void SetDefaultSettings(void);
extern void SaveSettings(const Settings *s);

#endif