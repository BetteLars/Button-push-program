/*
 * readkeys.h
 *
 *  Created on: Marts 1, 2012
 *      Author: Lasse
 */

#ifndef READKEYS_H_
#define READKEYS_H_
// Keys definitions
	enum bitNumbers { KEY0bit, KEY1bit, KEY2bit, KEY3bit, KEY4bit, KEY5bit, KEY6bit, KEY7bit, MAXbit };
// Event definitions
	enum events 	{ KEY0_EVENT_Enter, KEY1_EVENT_Cancel, KEY2_EVENT_Left, KEY3_EVENT_Rigth, KEY4_EVENT, KEY5_EVENT, KEY6_EVENT, KEY7_EVENT, TICK, NO_EVENT, MAXEVENTS };
// State definitions
	enum states		{ MENU, FALLOUTTIMER, KILLSWITCH, DB_lEVEL_setting, RESET_DEF,SoundMesure,MAXSTATES };

	int Readkeys(int RawKeys);

#endif /* READKEYS_H_ */
