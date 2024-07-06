#ifndef __KEY_H
#define __KEY_H

#include "main.h"
#include "stdbool.h"

#define Key1 GPIO_PIN_0 /*A*/

//#define KEY_LONG 1
typedef enum{
	B1_S=1,
	B1_D,
	B1_L,
	B2_S,
	B2_D,
	B2_L,
	B3_S,
	B3_D,
	B3_L,
	B4_S,
	B4_D,
	B4_L,
}Button;

typedef struct{
	
	uint8_t Key_Judge;
	bool Key_Sta;
	bool Key_Single;
	uint8_t Key_TimeCount;
	bool Key_Double;
	bool Key_Long;
	bool Double_TimeCountEN;
	uint8_t Double_TimeCount;

}KEY;

                        
extern KEY key[1];

void	Key_Scan(void);
#endif

