#include "Key.h"
#include "string.h"
#include "sys.h"
KEY key[1]={0};




void Key_Scan(void)
{
 
			/*按键按下Sta为0，未按下未1*/
		key[0].Key_Sta=PAin(0);
		for(int i=0 ; i<1 ; i++)
		{
			switch(key[i].Key_Judge)
			{
				case 0:{
									/*第一次按下按键*/
									if(key[i].Key_Sta == 0)
									{
										key[i].Key_Judge=1;
										
									}		
							}break;
				case 1:{
						      /*定时器10ms后判断按键是否还按下*/
						      if(key[i].Key_Sta == 0)
						      {
						      	key[i].Key_Judge=2;
										key[i].Key_TimeCount=0;
						      }else {
										key[i].Key_Judge=0;
									}									
								}break;
				case 2:{
				        	/*判断是否松开按键*/
				        	if(key[i].Key_Sta == 1)
				        	{
										key[i].Key_Judge=0;/*判断位置0*/
										if(key[i].Key_TimeCount < 70)
													key[i].Key_Single=1;
				        	}
									else
									{	
										if(key[i].Key_TimeCount > 70)
													key[i].Key_Long=1;
										key[i].Key_TimeCount++;
									}
							}break;
			}
	
		}
		
}




