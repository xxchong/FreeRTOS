#include "Key.h"
#include "string.h"
#include "sys.h"
KEY key[1]={0};




void Key_Scan(void)
{
 
			/*��������StaΪ0��δ����δ1*/
		key[0].Key_Sta=PAin(0);
		for(int i=0 ; i<1 ; i++)
		{
			switch(key[i].Key_Judge)
			{
				case 0:{
									/*��һ�ΰ��°���*/
									if(key[i].Key_Sta == 0)
									{
										key[i].Key_Judge=1;
										
									}		
							}break;
				case 1:{
						      /*��ʱ��10ms���жϰ����Ƿ񻹰���*/
						      if(key[i].Key_Sta == 0)
						      {
						      	key[i].Key_Judge=2;
										key[i].Key_TimeCount=0;
						      }else {
										key[i].Key_Judge=0;
									}									
								}break;
				case 2:{
				        	/*�ж��Ƿ��ɿ�����*/
				        	if(key[i].Key_Sta == 1)
				        	{
										key[i].Key_Judge=0;/*�ж�λ��0*/
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




