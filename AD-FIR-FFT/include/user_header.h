/****************************************Copyright (c)**************************************************
**                       		     
**
**
**
**--------------ÎÄ¼þÐÅÏ¢--------------------------------------------------------------------------------
**ÎÄ   ¼þ   Ãû: user_header.h
**´´   ½¨   ÈË: 
**×îºóÐÞ¸ÄÈÕÆÚ: 
**Ãè        Êö: ±ä»»Æ÷Í·ÎÄ¼þ
				°üÀ¨°æ±¾ÐÅÏ¢,ºê¶¨Òå,±äÁ¿ÉùÃ÷
**              
**--------------ÀúÊ·°æ±¾ÐÅÏ¢----------------------------------------------------------------------------
** ´´½¨ÈË: 
** °æ  ±¾: 
** ÈÕ¡¡ÆÚ: 
** Ãè¡¡Êö: 
**
**--------------µ±Ç°°æ±¾ÐÞ¶©------------------------------------------------------------------------------
** ÐÞ¸ÄÈË: 
** ÈÕ¡¡ÆÚ: 
** Ãè¡¡Êö: 
**
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
#ifndef DCDC_header_H
#define DCDC_header_H

#ifdef __cplusplus
extern "C" {
#endif

//--------------------------ºê¶¨Òå-----------------------------------------------
				
//-----------------------²ÎÊýÏà¹Øºê¶¨Òå------------------------------------------
//--------------------------°æ±¾ÐÅÏ¢-----------------------------------------------
#define MC_TYPE 			60701			//»úÐÍ²ÎÊý
#define MC_REV 				41222			//Èí¼þ°æ±¾ºÅ
#define MC_DATE 			60815			//³ö³§ÈÕÆÚ
#define MC_ID				1				//²úÆ·±àºÅ
#define MC_WRKEY			999				//¹¦ÄÜÂëÐÞ¸ÄÃÜÂë
#define MC_MYKEY			1021			//ÖÆÔìÉÌÊ¹ÓÃµÄÃÜÂë

//------------------------µ÷ÊÔ×´Ì¬Èí¿ª¹Ø-----------------------------------------------
#define	ON					1				          //¿ª
#define	OFF					0				          //¹Ø
#define	DEBUG_OPER			OFF			              //1=²»´ø²Ù×÷Æ÷2009.6.24

//********************************************************************************************//
//===================¶î¶¨µçÁ÷»ù×¼Öµ·åÖµ£¨Ã¿´ÎÊµÑé¸ù¾ÝÐèÒª¸ü¸Ä£©=====================================
#define NPR_IACN  473        //Íø²à¶î¶¨µçÁ÷»ù×¼Öµ ¶î¶¨ÓÐÐ§ÖµÎª334A
#define GRD_UN    563        //¶î¶¨µçÍøÏàµçÑ¹·åÖµ690VÏµÍ³

//********************************************************************************************//
 
//----------------------------ÏµÍ³¹¤×÷³£Êý------------------------------------------------

#define NPR_L       0.5e-3     //Íø²àÂË²¨µç¸ÐÖµ£¨H£©

//-------------³£ÓÃ³£Á¿ºê¶¨Òå-------------------------//
#define	SQRT3		1.73205081			//sqrt(3)
#define	SQRT3_2		0.8660254           //sqrt(3)/2
#define	SQRT3_3		0.57735027          //sqrt(3)/3
#define	SQRT2		1.41421356			//sqrt(2)
#define	PAI			3.1415926           //Ô²ÖÜÂÊ
#define TWOPAI      6.2831853           //2*PAI
#define PAI_2       1.5707963			//PAI/2
#define PAI_3       1.0471975			//PAI/3
#define TWOPAI_3    2.0943951			//2*PAI/3


//------------------------------ÑÓÊ±Ê±¼ä-------------------------------------------------
#define	DELAY_MAIN1			5										//Ò»¼¶Ñ­»·£º5ms
#define	DELAY_MAIN2			10										//¶þ¼¶Ñ­»·£º10ms
#define	DELAY_MAIN3			20										//Èý¼¶Ñ­»·£º20ms
#define	DELAY_MAIN4			50										//ËÄ¼¶Ñ­»·£º50ms
#define	DELAY_MAIN5			100										//Îå¼¶Ñ­»·£º100ms
#define	DELAY_MAIN6			1000									//Áù¼¶Ñ­»·£º1000ms

//canopen
#define	DELAY_CANOPENTX		13										//CANOPENTX£º7ms
#define	DELAY_CANOPENOVER	500										//CANOPENOVER£º500ms,HEARTBEAT
#define	DELAY_SCICANOPENOVER 250									//20090817
#define	DELAY_CANFAULT       10000									//CANOPENOVER£ºÉÏµçºóÅÐ¶ÏCANÍ¨Ñ¶¹ÊÕÏ

#define DELAY_AMUX          5      	//ÂýËÙAD
#define DELAY_UDCWAVE		1500	//Ö±Á÷µçÑ¹²¨¶¯³¬Ê±Ê±¼ä

#define	DELAY_POWERON		5000  	//ÉÏµçÊ±¼ä
#define	DELAY_PWMOUT		1000   	//ÏµÍ³´ÓÆô¶¯±êÖ¾ÖÃÎ»µ½Âö³å·¢ÉúÔÊÐí±êÖ¾ÖÃÎ»ÑÓÊ±(ms)
#define	DELAY_NPRSTDBY		1000   	//NPR´ý»ú---°å×Ó¹¤×÷µÆÂýËÙÉÁË¸(ms)
#define	DELAY_NPRRUN		100	   	//NPR¹¤×÷---°å×Ó¹¤×÷µÆ¿ìËÙÉÁË¸(ms)
#define	DELAY_MPRSTDBY		1000   	//MPR´ý»ú---°å×Ó¹¤×÷µÆÂýËÙÉÁË¸(ms)
#define	DELAY_MPRRUN		100	   	//MPR¹¤×÷---°å×Ó¹¤×÷µÆ¿ìËÙÉÁË¸(ms) 
#define	DELAY_FREQ			200	   	//ÆµÂÊÊ§°ÜÔÊÐíÑÓÊ±
#define	DELAY_CBFREQ		1000	//´ÓÖ÷¶Ï·´À¡±ÕºÏµ½ÅÐ¶ÏÍøÆµ¹ÊÕÏµÄÑÓÊ±£¨ms£©

#define	DELAY_FREQ2			200	   	//ÆµÂÊÊ§°ÜÔÊÐíÑÓÊ±
#define	DELAY_OTSER			60000  	//³¬Ê±ÑÏÖØÑÓÊ±(ms)
#define	DELAY_SCISPACE		10	   	//Í¨Ñ¶½ÓÊÕµ½·¢ËÍµÄ¼ä¸ôÊ±¼ä(ms)
#define	DELAY_SCIOVER		100	   	//Í¨Ñ¶½ÓÊÕ/·¢ËÍ³¬Ê±Ê±(ms)
//-----Protection-------
#define	DELAY_ESTOP  		6					//
#define	DELAY_CBTP		    6					//
#define DELAY_EXFAULT       500 
#define DELAY_CBERROR       2000     //2s 
#define DELAY_MAINKERROR    2000     //2s 
#define DELAY_MAINFERROR    2000     //2s
#define DELAY_STACERROR     2000     //2s
#define DELAY_PREERROR      85000     20100920 //15s
#define DELAY_PGOVLOAD      10000    //10s
#define DELAY_QGOVLOAD      10000    //10s
#define DELAY_CBRESET       500    	 //0.5s
#define DELAY_SPEEDOUT      5    //50ms 20091022atzy Ö÷¿Øfastshutdown
#define DELAY_UACLV1        10000     //10s   20091027atzy

#define	DELAY_EE		    20					//eepromÑÓ³ÙÊ±¼ä

#define	DELAY_ISTEADY0	    1000	 //RunCtrlÍø²àÍ£»ú¸ø¶¨ÑÓÊ±1s
#define	DELAY_MPRSTEADY0    50     //RunCtrlÍø²àÍ£»ú¸ø¶¨ÑÓÊ±0.05s 
#define	DELAY_SENSZFSTDY    60000    //RunCtrlÍø²àÍ£»ú¸ø¶¨ÑÓÊ±60s
/*
//sysctl_start µ÷ÊÔ°æ
#define	DELAY_OPENCONTAC	2000	 //ÑÏÖØ²»¿É»Ö¸´¹ÊÕÏÏÂ£¬·¢³ö¶ÏÖ÷¶ÏÖ¸Áîºóµ½·¢³ö¶Ï¶¨×Ó½Ó´¥Æ÷ºÍÖ÷½Ó´¥Æ÷µÄÑÓÊ± 2s 

#define	DELAY_MKOFF	        5000	 //½ÓÊÕµ½ÏµÍ³Í£»úÖ¸Áîºó£¬ÑÓÊ±¶ÏÖ÷½Ó´¥Æ÷¼ÆÊý 5s
#define	DELAY_CBOFF	        1000	 //½ÓÊÕµ½ÏµÍ³Í£»úÖ¸Áîºó£¬ÑÓÊ±¶ÏÖ÷¶Ï¼ÆÊý 2s

#define	DELAY_CLOSE_CB	    5000	 //Õý³£Æô¶¯£¬Ö÷¶Ï´¢ÄÜµ½Ö÷¶ÏºÏÕ¢µÄÑÓÊ±¼ÆÊý 5s 
#define	DELAY_PRECOK        9000	 //Õý³£Æô¶¯£¬Ô¤³äµçÊ±¼ä 9s   ³äµç³£Êý=2.115s
#define	DELAY_STEADYFB	    2000	 //Õý³£Æô¶¯£¬¼ì²âµ½VdcÎÈ¶¨ÔÚ1100Vµ½ÔÊÐí»ú²àÂö³åµÄÑÓÊ± 2s
#define	DELAY_MPRSTART 	    5000	 //Õý³£Æô¶¯£¬VdcÎÈ¶¨ºóµ½MPR·¢Âö³åµÄÑÓÊ± 5s
//sysctl_end  
*/ 

//sysctl_start ×îÖÕ°æ
#define	DELAY_OPENCONTAC	2000	 //ÑÏÖØ²»¿É»Ö¸´¹ÊÕÏÏÂ£¬·¢³ö¶ÏÖ÷¶ÏÖ¸Áîºóµ½·¢³ö¶Ï¶¨×Ó½Ó´¥Æ÷ºÍÖ÷½Ó´¥Æ÷µÄÑÓÊ± 2s 

#define	DELAY_ACCONTOFF	        2000	 //ÑÓÊ±¶Ï½»Á÷²à½Ó´¥Æ÷ 2s
#define	DELAY_CBOFF	        1000	 //½ÓÊÕµ½ÏµÍ³Í£»úÖ¸Áîºó£¬ÑÓÊ±¶ÏÖ÷¶Ï¼ÆÊý 2s

#define	DELAY_CLOSE_CB	    1000	 	//Õý³£Æô¶¯£¬20100124CPCÊÔÑé¸Ä 0s 
#define	DELAY_PRECOK        8000	 //Õý³£Æô¶¯£¬Ô¤³äµçÊ±¼ä 8s   ³äµç³£Êý=2.115s

//cy
#define	DELAY_VDCSTEADY	    2000	 //Õý³£Æô¶¯£¬¼ì²âµ½VdcÎÈ¶¨ÔÚ240~450VÖ®¼äÖÃÖ±Á÷µçÑ¹ÎÈ¶¨±êÖ¾Î»µÄÑÓÊ± 2s
#define	DELAY_ACCONTON 	    1000	 //Õý³£Æô¶¯£¬Ö±Á÷µçÑ¹ÎÈ¶¨ºóºÏAC½Ó´¥Æ÷ÑÓÊ±¼ÆÊý 1s
#define	DELAY_NPRSTART 	    1000	 //Õý³£Æô¶¯£¬½»Á÷µçÑ¹ÔÚ·¶Î§ÄÚÑÓÊ±ÖÃÉÏÎ»»úÒªÇóNPR·¢Âö³å±êÖ¾Î» 1s
//cy
//sysctl_end  


#define	DELAY_RESET	        2000  	 //ÏµÍ³¸´Î»ÑÓÊ±£¬·ÀÖ¹Îó²Ù×÷ 2s
#define	DELAY_CLOSTACMD	    1000  	 //ÔÊÐí¶¨×Ó½Ó´¥Æ÷£¬·ÀÖ¹Îó²Ù×÷ 1s
#define	DELAY_NPRCMD	    1000  	 //ÉÏÎ»»úÔÊÐíNPR·¢Âö³å£¬·ÀÖ¹Îó²Ù×÷ 1s
#define	DELAY_MPRCMD	    1000  	 //ÉÏÎ»»úÔÊÐíMPR·¢Âö³å£¬·ÀÖ¹Îó²Ù×÷ 1s

#define	DELAY_QCAPSPDIN     120    	//×ª×ÓËÙ¶È¼ì²âÕý³£120ms   20090817
#define	DELAY_QCAPDISTURB   100    	//Á¬Ðø10´Î¼ì²â×ª×ÓËÙ¶È²»Õý³£±¨¹ÊÕÏ 100ms  20090817
#define	DELAY_QEPCNTOK      1000    //Á¬Ðø1sÎ´·¢ÉúÉÏÒç´íÎó 1s
#define	DELAY_QEPZDISTURB   1000    //Á¬Ðø1s·¢ÉúZÐÅºÅÌáÇ°µ½À´±»¸ÉÈÅ´íÎó  1s

#define	DELAY_OCSEIN1     	250    	//20090817
#define	DELAY_OCSEIN2   	250    	//20090817
#define	DELAY_OCSSYSRUN1    250    	//20090817
#define	DELAY_OCSSYSRUN2   	250    	//20090817

#define	DELAY_DATASAVE   	2000    //¹ÊÕÏ·¢ÉúºóÑÓÊ±2sºóÍ£Ö¹´æ´¢20091109atzy
//LVRT
#define	DELAY_SCRIZERO	    100  	 //¼ì²âÑÓÊ±1¸ö×î´ó×ª²îÖÜÆÚ 100ms/10Hz
#define	DELAY_MPWMSTOP	    0  	 	 //0ms
#define	DELAY_MPWMRESTART	200  	 //200ms
#define	DELAYMPWM			5  	 	 //5ms
#define	DELAY_SCRONDELAY	2000  	 //2s
#define	DELAY_LVSTATE		20  	 //20ms
#define	DELAY_LVRCV			20  	 //20ms

//---------------------------¹ÊÕÏ±£»¤»Ø²îÖµ-----------------------------------------------
#define	SC_IAC_HW			2			//ÊäÈëµçÁ÷±£»¤»Ø²î(»ù×¼µçÁ÷µÄ°Ù·ÖÖµ)
#define	SC_UDC_HW			20			//µçÑ¹±£»¤»Ø²î(V)
#define	SC_UAC_HW			20			//µçÑ¹±£»¤»Ø²î(V)
#define	SC_MSPD_HW			30			//×ªËÙ±£»¤»Ø²î(V) r/min
#define	SC_POWOROV_HW	    0	    	//¹¦ÂÊ¹ýÔØ±£»¤»Ø²î(W) 0kW

#define	et_gate	    		50000	    //¹ýÔØ±£»¤¼ÆËã

//-----------------------------CANOPENÍ¨ÐÅºê¶¨Òå----------------------------------------------
#define	SCICANOPENRXNUM		10										//CANOPENRXÊý¾Ý°ü´óÐ¡
#define	SCICANOPENTXNUM		18										//CANOPENTXÊý¾Ý°ü´óÐ¡
#define CANOPENCOM_HEAD		0x7E									//CANOPEN±¨Í·
//#define CANOPENCOM_RX		0x03									//FUNCTION_RX
//#define CANOPENCOM_TX1		0x01									//FUNCTION_TX
//#define CANOPENCOM_TX2		0x02									//FUNCTION_TX 
//-----------------------------CANOPENÍ¨ÐÅºê¶¨ÒåNORMAL----------------------------------------------
#define CAN_TEN  	  10000     //Ö÷¿ØÖ¸Áî¶î¶¨×ª¾Ø»ù×¼Öµ (³£Ç£:1800r/minÊ±P=1560kW,Te=P*60/(n*2*pie)=8276 NM )
#define CAN_ANGLEN     90       //Ö÷¿ØÖ¸Áî¶î¶¨ÎÞ¹¦ÒòÊý½Ç¶È»ù×¼Öµ 
#define CAN_SPEED     1500      //Ö÷¿ØÖ¸Áî¶î¶¨×ªËÙ»ù×¼Öµ 
#define CAN_TEMP      100       //Ö÷¿ØÖ¸Áî¶î¶¨ÎÂ¶È»ù×¼Öµ 

//-----------------------------485Í¨Åºê¶¨Òå----------------------------------------------
#define	SCI485NUM			10										//485Êý¾Ý°ü´óÐ¡
#define COM_HEAD			0x7E									//SCI±¨Í·

#define RESUME_KEY			0x5A5A									//»Ö¸´³ö³§²ÎÊýµÄÐ£ÑéÂë

//µØÖ·×Ö½Ú
#define COM_OPERATOR		0x80									//ÉÏÎ»»úÎª²Ù×÷Æ÷(×î¸ßÎ»Îª1)

//ÉÏÎ»»ú·¢ËÍÃüÁî
#define COM_RD				0x0001									//¶ÁÈ¡¹¦ÄÜÂë(¶ÁÈ¡ÏÂÎ»»úEEPROMÖÐµÄ¹¦ÄÜÂëÖµÐ´Èëµ½ÉÏÎ»»úEEPROMÖÐ)
#define COM_WR				0x0002									//ÐÞ¸Ä¹¦ÄÜÂë(ÐÞ¸ÄÏÂÎ»»úRAMÖÐµÄ¹¦ÄÜÂëÖµ)
#define COM_SAVE			0x0004									//ÐÞ¸Ä¹¦ÄÜÂë²¢´æ´¢(ÐÞ¸ÄÏÂÎ»»úRAMÖÐµÄ¹¦ÄÜÂëÖµ²¢±£´æ»»úµÄEEPROM)
#define COM_RESUME			0x0008									//»Ö¸´³ö³§²Î
#define COM_NEEDSTOP		0x0010									//ÏÂÎ»»úÓ¦µ±´¦ÓÚÍ£»ú×´Ì¬²ÅÄÜ½øÐÐ(ÈçÉÏµç³õÊ¼»¯,¹¦ÄÜÂë¶Á³ö¡¢Ð£ÑéºÍÐ´µÈ,ÌáÊ¾Î»»úÓ¦µ±£»ú)
#define COM_SAVEALL			0x0020									//ÐÞ¸Ä¹¦ÄÜÂë²¢´æ´¢(ÈçÊý¾Ý¸´Ð´¹¦ÄÜÖÐÐèÒªÏÂÎ»»úÐ´ÈëËùÓÐ²ÎÊý,°üÀ¨¾ßÓÐÖ»¶ÁÊôÐÔµÄ¹¦ÄÜÂë)
#define COM_VGIVE			0x0040									//ÐÞ¸ÄdcdcµçÑ¹¸ø¶¨Öµ
#define COM_IGIVE			0x0080									//ÐÞ¸ÄdcdcµçÁ÷¸ø¶¨Öµ

//ÏÂÎ»»ú·´À¡ÃüÁî
#define COM_SUCCESS			0x80									//×î¸ßÎ»ÎªÍ¨Ñ¶ÎÕÊÖ³É¹¦±êÖ¾

//ÉÏÎ»»ú×´Ì¬×Ö
#define COM_UPNORM			0x0001									//0Î»ÎªÉÏÎ»»úÕý³£±êÖ¾
//#define COM_UPINIT		0x0002									//1Î»ÎªÉÏÎ»»ú³õÊ¼»¯ê³±êÖ¾
#define COM_KEYSTOP			0x0100									//1=ÉÏÎ»»ú'STOP'¼üÓÐÐ§(Í£Ö¹)
#define COM_KEYFWD			0x0200									//1=ÉÏÎ»»ú'FWD'¼üÓÐÐ§(³äµç)
#define COM_KEYREV			0x0400									//1=ÉÏÎ»»ú'REV'¼üÓÐÐ§(·Åµç)
//#define COM_KEYRESET		0x0800									//1=ÉÏÎ»»ú'RESET'¼üÓÐÐ§(Ô¤Áô)

//ÏÂÎ»»ú·´À¡×´Ì¬×Ö
#define COM_SLAVENORM		0x0001									//0Î»ÎªÏÂÎ»»úÕý³£±êÖ¾
#define COM_SLAVEINIT		0x0002									//1Î»ÎªÏÂÎ»»ú³õÊ¼»¯Íê³É±êÖ¾
#define COM_SLAVERUN		0x0004									//2Î»ÎªÏÂÎ»»úÔËÐÐ±êÖ¾
#define COM_SLAVEFWD		0x0008									//3Î»ÎªÏÂÎ»»ú³äµç
#define COM_SLAVEREV		0x0010									//4Î»ÎªÏÂÎ»»ú·Åµç
#define COM_SLAVEDEB		0x0020									//5Î»ÎªÏÂÎ»»úµ÷ÊÔ

//CANOPENÉÏÎ»»ú×´Ì¬×Ö
#define COM_EIN			    0x0001									//BIT0
#define COM_NPREIN			0x0002									//BIT1
#define COM_SYSRUN			0x0004									//BIT2
#define COM_PGMODE			0x0010									//BIT4
#define COM_QGMODE			0x0020									//BIT5
#define COM_OCSRESET		0x0080									//BIT7
#define COM_HEARTBEAT1		0x8000									//BIT15
//CANOPEN·´À¡ÉÏÎ»»úµÄ±äÁ÷Æ÷×´Ì¬×Ö1
#define COM_NPRREADY	    0x0001									//BIT0
#define COM_NPRON			0x0002									//BIT1
#define COM_READYGENERATION	0x0004									//BIT2
#define COM_FAILURE			0x0008									//BIT3
#define COM_SPEEDINRANGE	0x0010									//BIT4
#define COM_FAILUREA		0x0020									//BIT5
#define COM_FAILUREB		0x0040									//BIT6
#define COM_TOOCOLD		    0x0080									//BIT7
#define COM_PLIM	        0x0100									//BIT8
#define COM_QLIM			0x0200									//BIT9
#define COM_GRIDFAILURE 	0x0400									//BIT10
#define COM_CROWBAR			0x0800									//BIT11
#define COM_VLIM        	0x1000									//BIT12
#define COM_HEARTBEAT2		0x8000									//BIT15

#define COM_NPRREADY_NOT	    0xFFFE								//BIT0
#define COM_NPRON_NOT			0xFFFD								//BIT1
#define COM_READYGENERATION_NOT	0xFFFB								//BIT2
#define COM_FAILURE_NOT			0xFFF7								//BIT3
#define COM_SPEEDINRANGE_NOT	0xFFEF								//BIT4
#define COM_FAILUREA_NOT		0xFFDF								//BIT5
#define COM_FAILUREB_NOT		0xFFBF								//BIT6
#define COM_TOOCOLD_NOT		    0xFF7F								//BIT7
#define COM_PLIM_NOT	        0xFEFF								//BIT8
#define COM_QLIM_NOT			0xFDFF								//BIT9
#define COM_GRIDFAILURE_NOT 	0xFBFF								//BIT10
#define COM_CROWBAR_NOT			0xF7FF								//BIT11
#define COM_VLIM_NOT        	0xEFFF								//BIT12
#define COM_HEARTBEAT2_NOT		0x7FFF								//BIT15
//CANOPEN·´À¡ÉÏÎ»»úµÄ±äÁ÷Æ÷×´Ì¬×Ö2
#define COM_ILIM			0x0001									//BIT0
#define COM_HEATSINKT		0x0002									//BIT1
#define COM_ESTOP			0x0004									//BIT2
#define COM_CBTRIP			0x0010									//BIT4
#define COM_POWLIM			0x0040									//BIT6
#define COM_VOLDIP			0x0100									//BIT8
#define COM_CBCLOSED		0x8000									//BIT15	 20090815

#define COM_ILIM_NOT		0xFFFE									//BIT0
#define COM_HEATSINKT_NOT	0xFFFD									//BIT1
#define COM_ESTOP_NOT		0xFFFB									//BIT2
#define COM_CBTRIP_NOT		0xFFEF									//BIT4
#define COM_POWLIM_NOT		0xFFBF									//BIT6
#define COM_VOLDIP_NOT	    0xFEFF									//BIT8
#define COM_CBCLOSED_NOT	0x7FFF									//BIT15 20090815

//-------------------------AD¡¢DA×ª»»¼°Êý¾Ý¶ÁÈ¡µÄ¿ØÖÆ-----------------------------------------
#define	AD8364_CONVERT		1										//8364¿ªÊ¼×ª»»
//#define	AD1544_CONVERT		2										//1544¿ªÊ¼×ª»»
//#define	DA7614_CONVERT		4										//7614¿ªÊ¼×ª»»
//ad
#define AD_ASTART		    ((Uint16 *)0x100000)						//Æ¬ÍâADµÄÊý¾Ý¶ÁÈ¡Ê×µØÖ·
#define AD_BSTART		    ((Uint16 *)0x110000)						//Æ¬ÍâADµÄÊý¾Ý¶ÁÈ¡Ê×µØÖ·
#define NETCS		        ((Uint16 *)0x120000)						//Æ¬ÍâADµÄÊý¾Ý¶ÁÈ¡Ê×µØÖ·
#define AD_DA_CTRL		    ((Uint16 *)0x130000)						//Æ¬ÍâAD,DAµÄ¿ØÖÆ×Ö½ÚµØÖ·
//da
#define DA_ADD0				((Uint16 *)0x1B0000)						//Êä³öµØÖ·0
#define DA_ADD1				((Uint16 *)0x1B0001)						//Êä³öµØÖ·1
#define DA_ADD2				((Uint16 *)0x1B0002)						//Êä³öµØÖ·2
#define DA_ADD3				((Uint16 *)0x1B0003)						//Êä³öµØÖ·3

//External RAM 20091109atzy
#define RAM_START		    ((Uint16 *)0x200000)						//Æ¬ÍâRAMÊ×µØÖ·XINTF zone 7
#define RAM_END		        ((Uint16 *)0x23FFFF)						//Æ¬ÍâRAMÎ²µØÖ·XINTF zone 7
#define RAM_BIAS		    10000						//Ã¿¸ö±äÁ¿Æ«ÒÆÁ¿=4s/(0.4ms/point)=10000points/variable
Uint16  RAMDATA_POS;						    		//´æ´¢±äÁ¿µÄ´æ´¢µãÎ»ÖÃ[0,7999]


//----------------------------ÊäÈëÊä³öµØÖ·¶¨Òå--------------------------------------------
#define IN1_ADDR			((Uint16 *)0x140000)	//ÊäÈëµØÖ·1
#define IN2_ADDR			((Uint16 *)0x150000)	//ÊäÈëµØÖ·2
#define IN3_ADDR			((Uint16 *)0x160000)	//ÊäÈëµØ·3
#define IN4_ADDR			((Uint16 *)0x170000)	//ÊäÈëµØÖ·4

#define OUT1_ADDR			((Uint16 *)0x180000)	//Êä³öµØÖ·2
#define OUT2_ADDR			((Uint16 *)0x190000)	//Êä³öµØÖ·3
#define OUT3_ADDR			((Uint16 *)0x1A0000)	//Êä³öµØÖ·3
#define OUT4_ADDR			((Uint16 *)0x1C0000)	//Êä³öµØÖ·4,ÓëÂýËÙADÓÐ¹Ø

//--------------------------------SPIÍ¨Ñ¶ºê¶¨Òå-------------------------------------------
#define	SPINUM				4										//SPI¿Ú·¢ËÍ/½ÓÊÕÊý¾ÝÁ¿

//-----------------------------------Ê±ÖÓ--------------------------------------------------
#define	HSPCLK				75      		//¸ßËÙ»ù×¼Ê±ÖÓÆµÂÊ(Hz)
#define	LSPCLK				37500000		//µÍËÙ»ù×¼Ê±ÖÓÆµÂÊ(Hz)

//--------------------------------±êÖ¾Î»¶¨å-----------------------------------------------
//flag[0]ÏÔÊ¾¼°Éè¶¨±ê
#define	SL_DISPLAY0			0x00			//LEDÏÔÊ¾0
#define	SL_DISPLAY1			0x01			//LEDÏÔÊ¾1
#define	SL_DISPLAY2			0x02			//LEDÏÔÊ¾2
#define	SL_DISPLAY3			0x03			//LEDÏÔÊ¾3
#define	SL_DISPLAY4			0x04			//LEDÏÔÊ¾4
#define	SL_DISPLAY5			0x05			//LEDÏÔÊ¾5
#define	SL_DISPLAY6			0x06			//LEDÏÔÊ¾6
#define	SL_DISPLAY7			0x07			//LEDÏÔÊ¾7
#define SL_OCS_NPRSTART     0x08            //=1Ö÷¿ØÒªÇóNPR·¢Âö³å        
#define SL_OCS_MPRSTART     0x09            //=1Ö÷¿ØÒªÇóMPR·¢Âö³å
#define SL_OCS_RESET        0x0A            //=1Ö÷¿Ø·¢¹ýÀ´µÄ¹ÊÕÏ¸´Î»ÐÅºÅ  
#define SL_SERIESTOPING    	0x0B			//=1ÕýÔÚÑÏÖØ¹ÊÕÏÍ£»ú¹ý³Ì 
#define	SL_SERIESTOP        0x0C      		//=1ÏµÍ³ÑÏÖØ²»¿É»Ö¸´¹ÊÕÏ±êÖ¾Î» 
#define SL_SENSZFSTDY       0x0D            //=1´«¸ÐÆ÷ÁãÆ¯ÂË²¨½áÊø 
#define	SL_EINSTOPING       0x0E      		//=1ÕýÔÚÕý³£¶ÏÖ÷¶ÏÍ£»ú¹ý³Ì
#define SL_SYSSTOPING       0x0F            //=1ÕýÔÚÕý³£¶ÏÖ÷½Ó´¥Æ÷Í£»ú¹ý³Ì

 
  

//flag[1]´®ÐÐÍ¨ÐÅÏà¹Ø±ê;eepromÏà¹Ø±ê
#define SL_TX		    	0x10			//1=±íÊ¾sciÕýÔÚ·¢ËÍ
#define SL_RX		    	0x11			//1=±íÊ¾sci½ÓÊÕÍê³ÉÑÓÊ±ÖÐ
#define SL_RESUME    		0x12			//1=»Ö¸´³ö³§²ÎÊý½øÐÐÖÐ
#define SL_HEADOK			0x13			//1=±¾Ö¡Êý¾Ý±¨Í·ÕýÈ·
#define SL_SETRTIMER		0x14			//1=ÐèÒªÐ£ÕýÊµÊ±Ê±ÖÓ
#define SL_EE_NOACK			0x15
#define	SL_EE_FAIL			0x16			//=1eepromÐ´Èë´íÎó
#define SL_CODEOK			0x17			//=1¹¦ÄÜÂëÐ£ÑéÍê±Ï
#define SL_EEASK_INI		0x18			//=ÉÏÎ»»úÒªÇóeeprom»Ö¸´³ö³§²ÎÊý
#define SL_EEASK_MCODE		0x19			//=1´æÔÚÐÞ¸Ä¹¦ÄÜÂëÇëÇó
#define SL_EEASK_ERRSAVE	0x1A			//=1´æÔÚ±£´æ¹ÊÕÏÐÅÏ¢ÇëÇó
#define SL_EEBUSY_INI		0x1B			//=1»Ö¸´³ö³§²ÎÊý½øÐÐÖÐ
#define SL_EEBUSY_MCODE		0x1C			//=1ÐÞ¸Ä¹¦ÄÜÂë½øÐÐÖÐ
#define SL_EEBUSY_ERRSAVE	0x1D			//=1±£´æ¹ÊÕÏÐÅÏ¢½øÐÐÖÐ 
	
//flag[2]¹ÊÕÏ±êÖ¾Î»//cy
#define SL_ACCONFAIL		0x20			//=1 ½Ó´¥Æ÷±ÕºÏ¹ÊÕÏ
#define SL_UFO				0x21			//=1 UÏàÉÏÇÅ±ÛÇý¶¯±£»¤
#define	SL_VFO	        	0x22     		//=1 VÏàÉÏÇÅ±ÛÇý¶¯±£»¤  
#define	SL_WFO	    		0x22     	    //=1 WÏàÉÏÇÅ±ÛÇý¶¯±£»¤
#define SL_BFO				0x23			//=1 ÏÂÇÅ±ÛÇý¶¯±£»¤
#define	SL_HIAC           	0x24      		//=1 ½»Á÷Ó²¹ýÁ÷
#define	SL_HUDCOV        	0x25      		//=1 Ö±Á÷Ó²¹ýÑ¹ 
#define	SL_SIA       		0x26      		//=1 ½»Á÷AÏàÈí¹ýÁ÷
#define SL_SIB        		0x27        	//=1 ½»Á÷BÏàÈí¹ýÁ÷ 
#define SL_SIC   			0x28         	//=1 ½»Á÷CÏàÈí¹ýÁ÷
#define SL_SUDCOV     		0x29         	//=1 Ö±Á÷Èí¹ýÑ¹
#define SL_SUDCLV			0x2A         	//=1 Ö±Á÷ÈíÇ·Ñ¹
#define SL_UACOV       		0x2B         	//=1 ½»Á÷µçÑ¹¹ýÑ¹
#define SL_UACLV        	0x2C         	//=1 ½»Á÷µçÑ¹Ç·Ñ¹ 
#define SL_FE1        		0x2D         	//=1 µçÍøÆµÂÊ¹ÊÕÏ 
#define SL_IPMTOV        	0x2E         	//=1 IGBT¹ýÈÈ 
#define SL_LTOV        		0x2F         	//=1 µç¿¹Æ÷¹ýÈÈ 
//cy

//flag[3]×´Ì¬±ê
#define SL_POWERON			0x30			//=1ÏµÍ³ÉÏµçÍê³É
#define SL_VDCON			0x31			//=1ÉÏµç±êÖ¾£¨ÖÐ¼äµçÑ¹´ïµ½´ËÖµÖ÷¶Ï¿ÉÒÔ±ÕºÏ£©
#define SL_WARNING			0x32			//=1±¨¾¯
#define SL_OFFCB			0x33			//=1¶ÏÖ÷¶Ï
#define SL_SOFT				0x34			//=1»ºÂýÍ£Ö¹
#define SL_SHUT				0x35			//=1½ô¼±Í£Ö¹
#define SL_NRCVR			0x36			//=1¹ÊÕÏ²»ÄÜ»Ö¸´
#define SL_DRCVR			0x37			//=1¹ÊÕÏÑÓÊ±»Ö¸´
#define SL_IRCVR			0x38			//=1¹ÊÕÏÁ¢¼´»Ö¸´
#define SL_CNT				0x39			//=1¼ÆÈë¹ÊÕÏ´ÎÊý
#define SL_OTSER			0x3A			//=1¹ÊÕÏ³¬Ê±ÑÏÖØ
#define SL_SAVE				0x3B			//=1¹ÊÕÏÐèÒª´æ´¢
#define SL_STEADYGV			0x3C			//=1Vdc¸ø¶¨ÎÈ¶¨
#define SL_VDCSTEADY		0x3D			//=1VdcµçÑ¹ÎÈ¶¨
#define SL_DEADCOMP1		0x3E			//=1Íø²àËÀÇø²¹³¥Ê¹ÄÜ
#define SL_DEADCOMP2		0x3F			//=1µç»ú²àËÀÇø²¹³¥Ê¹ÄÜ 

//flag[4]¹ÊÕÏ±ê1
#define SL_ERROR			0x40			//=1ÏµÍ³¹ÊÕÏ
#define SL_ERRSTOP			0x41			//=1ÏµÍ³ÑÏÖØ¹ÊÕÏµ¼ÖÂÍ£»ú
#define	SL_PDPINTA			0x42			//=1¹¦ÂÊÇý¶¯±£»¤A
#define	SL_PDPINTB			0x43			//=1¹¦ÂÊÇý¶¯±£»¤B
#define	SL_UDCWAVE			0x44			//=1ÖÐ¼äµçÑ¹²»ÎÈ¶¨£¬³¬³ö580VºÍ620V
#define	SL_SUDCOVH			0x45			//=1ÖÐ¼äµçÑ¹¹ýÑ¹¹ÊÕÏ±êÖ¾Î»(ÍøÑ¹µøÂä)
#define SL_HIA1			    0x46			//=1Íø²à±äÁ÷Æ÷AÏàÓ²¼þ¹ýÁ÷
#define SL_HIB1			    0x47			//=1Íø²à±äÁ÷Æ÷BÏàÓ²¼þ¹ýÁ÷
#define SL_HIC1			    0x48			//=1Íø²à±äÁ÷Æ÷CÏàÓ²¼þ¹ýÁ÷
#define SL_HIA2		 	   	0x49			//=1µç»ú²à±äÁ÷Æ÷AÏàÓ²¼þ¹ýÁ÷
#define SL_HIB2		   	 	0x4A			//=1µç»ú²à±äÁ÷Æ÷BÏàÓ²¼þ¹ýÁ÷
#define SL_HIC2		   	 	0x4B			//=1µç»ú²à±äÁ÷Æ÷CÏàÓ²¼þ¹ýÁ÷
#define SL_SIAC1		    0x4C			//=1Íø²à±äÁ÷Æ÷Èí¼þ¹ýÁ÷
#define SL_SIAC2		    0x4D			//=1µç»ú²à±äÁ÷Æ÷Èí¼þ¹ýÁ÷

//flag[5]¹ÊÕÏ±ê2//cy 
#define SL_TTOV				0x50			//=1±äÑ¹Æ÷¹ýÈÈ
#define SL_PGOV				0x51			//=1ÓÐ¹¦¹¦ÂÊ¹ýÔØ
#define SL_QGOV				0x52			//=1ÎÞ¹¦¹¦ÂÊ¹ýÔØ
#define SL_IslandPro_U		0x53			//=1µçÑ¹¹Âµº±£»¤
#define SL_IslandPro_F		0x54			//=1ÆµÂÊ¹Âµº±£»¤
//cy
#define	SL_GRDFQE			0x55			//=1Íø²àÆµÂÊ¼ì²âÓÐÎó
#define	SL_PDPASERIES		0x56			//=1Íø²àÑÏÖØ¹ÊÕÏ
#define SL_PDPBSERIES		0x57			//=1µç»ú²àÑÏÖØ¹ÊÕÏ
#define SL_HIACOV1			0x59			//=1Íø²à½»Á÷Ó²¼þ±£»¤¹ýÁ÷¹ÊÕÏ
#define SL_HIACOV2			0x5A			//=1µç»ú²à½»Á÷Ó²¼þ±£»¤¹ýÁ÷¹ÊÕÏ
#define SL_CBTRIP 			0x5B			//=1Ö÷¶ÏÍÑ¿Û»òÕßÖ÷¿Ø¶Ï¿ªÖ÷¶Ï¹ÊÕÏ
#define	SL_EXFAIL		    0x5C			//=1±äÁ÷Æ÷Íâ²¿Ó²¼þ¹ÊÕÏ
#define	SL_ESTOP			0x5D			//=1Íâ²¿½ô¼±Í£»ú¹ÊÕÏ
#define SL_PHORDE		    0x5F            //=1ÏàÐòÕý³£

//flag[6]ÔËÐÐ·½Ê½
//#define SL_NPR_SINGLE		0x60			//=1Íø²à¶ÀÁ¢¹¤×÷Ä£Ê½
//#define SL_MPR_SINGLE		0x61			//=1µç»ú²à¶ÀÁ¢¹¤×÷Ä£Ê½
//#define SL_BACK2BACK		0x62			//=1±³¿¿±³ÔËÐÐ
//#define SL_NPR_REACTIVE		0x63			//=1Íø²àÎÞ¹¦²¢Íø¹¤×÷Ä£Ê½
//#define SL_NPR_PWMSTOP      0x64            //=1Íø²àÍ£Ö¹Âö³å
//#define SL_MPR_PWMSTOP      0x65            //=1»ú²àÍ£Ö¹Âö³å
#define	SL_NPR_START		0x66			//Íø²à±äÁ÷Æ÷ÔËÐÐÖ¸Áî 1=ÔËÐÐ
#define	SL_MPR_START		0x67			//»ú²à±äÁ÷Æ÷ÔËÐÐÖ¸Áî 1=ÔËÐÐ
#define	SL_NPR_RUN			0x68			//=1Íø²à±äÁ÷Æ÷¹¤×÷ÔÊÐí
#define	SL_MPR_RUN			0x69			//=1»ú²à±äÁ÷Æ÷¹¤×÷ÊÐí 
#define	SL_NPR_RUNING		0x6A			//=1Íø²à±äÁ÷Æ÷ÕýÔÚ¹¤÷
#define	SL_MPR_RUNING		0x6B			//=1»ú²à±äÁ÷Æ÷ÕýÔÚ¹¤×÷
#define	SL_TAOVONCE			0x6C			//=1Íø²àÇÅ±Û³¬ÎÂ¹ÊÕÏÐÅºÅÊÜ¸ÉÈÅ
#define	SL_TBOVONCE			0x6D			//=1µç»ú²àÇÅ±Û³¬ÎÂ¹ÊÕÏÐÅºÅÊÜ¸ÉÈÅ
#define SL_FAN_WORK         0x6E			//=1ÒªÇó¹¦ÂÊ·çÉÈ¿ªÊ¼¹¤×÷
#define	SL_FANSELECT		0x6F			//=0¹¦ÂÊ·ç»úÐÇ½Ó 1¹¦ÂÊ·ç»ú½Ç½Ó
								
//flag[7]Êä³ö±ê1,IOÊä³ö   0x180000          //¼ÌµçÆ÷Êä³ö£¬=1 Êä³öDC24V
#define _OUT1_DATA			flag[7]	
#define CL_OUT_CONVRUN          0x70         	//=1±äÁ÷Æ÷ÔËÐÐP5.5
#define CL_OUT_CONVFAIL			0x71			//=1±äÁ÷Æ÷¹ÊÕÏP5.6
#define CL_OUT_ACCONTON			0x72			//=1ºÏ½»Á÷½Ó´¥Æ÷P5.7
#define	CL_OUT_DCCONTON    		0x73			//=1ºÏÖ±Á÷½Ó´¥Æ÷P5.8
#define CL_OUT_FANWORK		    0x74			//=1·ç»úÔËÐÐP5.9

//flag[8]Êä³ö±ê2         0x190000           //¼ÌµçÆ÷Êä³ö£¬=1 Êä³öAC220V
#define _OUT2_DATA			flag[8]
#define CL_RELAY8      		0x80			//±¸ÓÃ
#define CL_RELAY9          	0x81			//±¸ÓÃ

//flag[15]Êä³ö±ê4         0x1A0000          //ÂýËÙADµØÖ·Êä³ö
#define _OUT3_DATA			flag[15]									
#define SL_PHASEA			0xF0		     //						
#define SL_PHASEB			0xF1             //
 

//flag[11]Êä³ö±ê4         0x1C0000          //ÂýËÙADµØÖ·Êä³ö
#define _OUT4_DATA			flag[11]									
#define SL_LSADA0			0xB0		     //A0						
#define SL_LSADA1			0xB1             //A1
#define SL_LSADA2			0xB2             //A2
#define SL_LSADA3			0xB3	         //A3							
							

						

//flag[9]ÊäÈë±ê12
#define _IN12_DATA			flag[9]			//±äÁ÷Æ÷²¼þ×´Ì¬·´À¡
//---------------------0x140000----------------------------------------------------------------------------	
#define SL_IN1_EMESTOP 			0x90			//=1 Íâ²¿¼±Í£¹ÊÕÏ¬¬	P4.1
#define SL_IN1_SYSSTAR			0x91			//=1 ÏµÍ³Æô¶¯		P4.2
#define SL_IN1_CONVRUN			0x92			//=1 Äæ±äÆ÷²¢ÍøÔËÐÐ£¬P4.3  
#define SL_IN1_ACCONTA 			0x93			//=1 ½»Á÷½Ó´¥Æ÷´¦ÓÚºÏÕ¢×´Ì¬	P4.4
#define SL_IN1_DCCONTA	    	0x94			//=1 Ö±Á÷½Ó´¥Æ÷´¦ÓÚºÏÕ¢×´Ì¬£¬P4.5
#define SL_IN1_SPARE	  	 	0x95			//=1 ±¸ÓÃ	P4.6¬£		
//---------------------0x150000---------------------------------------------------------------------------	
#define SL_IN2_UFO			0x98	//=1 UÏàÉÏÇÅ±ÛÇý¶¯±£»¤
#define SL_IN2_VFO			0x99	//=1 VÏàÉÏÇÅ±ÛÇý¶¯±£»¤
#define SL_IN2_WFO			0x9A	//=1 WÏàÉÏÇÅ±Û±£»¤					
#define SL_IN2_BFO			    0x9B	//=1 ÏÂÇÅ±ÛÇý¶¯±£»¤ 
#define SL_IN2_HIAC			0x9C	//=1 ½»Á÷Ó²¹ýÁ÷
#define SL_IN2_HUDCOV			0x9D	//=1 Ö±Á÷Ó²¹ýÑ¹


//flag[10]ÊäÈë±ê34      0x160000
#define _IN34_DATA			flag[10]			//¿ØÖÆ°åÓ²¼þ±£»¤¹ÊÕÏ·´À¡
//-----------------------------------------------------------------------------------------------				
#define SL_IN3_VDCOV			0xA0			//=1 Ö±Á÷µçÑ¹¹ýÑ¹
#define SL_IN3_NPRIOV			0xA1			//=1 Íø²à½»Á÷Ó²¼þ±£»¤¹ýÁ÷¹ÊÕÏ
#define SL_IN3_MPRIOV			0xA2			//=1 µç»ú²à½»Á÷Ó²¼þ±£»¤¹ýÁ÷¹ÊÕÏ

#define SL_IN3_CBTRIP		    0xA3			//=1 Ö÷¶Ï¹ýÁ÷ÍÑ¿Û¹ÊÕÏ  P4.9   20090816
//#define SL_IN3_OCS_NPRSTART		0xA4			//=1 ÉÏÎ»»úÔÊÐí·¢Íø²àÂö³å  ²Ù×÷°åÐÅºÅ£¬·ç³¡Ã»ÓÃ
//#define SL_IN3_OCS_MPRSTART		0xA5			//=1 ÉÏÎ»»úÔÊÐí·¢»ú²àÂö³å  ²Ù×÷°åÐÅºÅ£¬·ç³¡Ã»ÓÃ


//flag[12]Ö÷¿ØÍ¨Ñ¶±êÖ¾Î»
#define SL_OCS_EIN          0xC0            //=1Ö÷¿Ø·¢¹ýÀ´µÄÏµÍ³Æô¶¯ÐÅºÅ  bit0 ºÏÖ÷¶ÏÂ·Æ÷
#define SL_OCS_SYSRUN    	0xC1			//=1Ö÷¿Ø·¢¹ýÀ´µÄ±äÁ÷Æ÷Æô¶¯ÐÅºÅ  bit2 ¿ªÊ¼Ô¤³äµçÖ±ÖÁ¶¨×Ó½Ó´¥Æ÷±ÕºÏ
#define SL_CBCLOSED    	    0xC2			//=1·´À¡Ö÷¿Ø£¬Ö÷¶ÏÒÑ¾­±ÕºÏ
#define SL_MPR_SYNOK        0xC3            //=1»ú²àÍ¬²½²¢ÍøÍê³É±êÖ¾Î»				
#define SL_OCS_NPREIN       0xC4            //=1Ö÷¿ØÒªÇó±äÁ÷Æ÷Íø²àµ¥¶ÀÎÞ¹¦²¢ÍøÔËÐÐ				
#define SL_PGOV_COM         0xC5            //=1ÓÐ¹¦¹¦ÂÊ³¬³öÏÞÖÆ£¬Í¨ÖªÖ÷¿Ø ³ÖÐø10sºó±äÁ÷Æ÷»á±¨¹ÊÕÏ			
#define SL_QGOV_COM         0xC6            //=1ÎÞ¹¦¹¦ÂÊ³¬³öÏÞÖÆ£¬Í¨ÖªÖ÷¿Ø ³ÖÐø10sºó±äÁ÷Æ÷»á±¨ÕÏ				
//canopen
#define SL_COMOVER		0xC8			//=1 Í¨Ñ¶¹ÊÕÏ
#define SL_CANOPENHEADOK	0xC9			//=1 SL_CANOPENHEADOK
#define SL_CANOPENTX		0xCA			//=1 SL_CANOPENOVER 
#define SL_TEST		        0xCB			//=1 SL_CANOPENOVER 


//flag[13]
#define SL_GRIDLOSE70		0xD0			//Îª¼à²âÍøÑ¹µøÂä20091027atzy
#define	SL_GRIDLOSE50       0xD1      		//Îª¼à²âÍøÑ¹µøÂä20091027atzy
#define	SL_GRIDLOSE30       0xD2      		//Îª¼à²âÍøÑ¹µøÂä20091027atzy
#define	SL_GRIDLOSE15       0xD3      		//Îª¼à²âÍøÑ¹µøÂä20091027atzy
#define	SL_ERRDATASAVE      0xD4      		//´¥·¢Íâ²¿RAMÊý¾Ý×ª´æ20091109atzy
//LVRT±êÖ¾Î»
#define SL_LV_MSTOP         0xD5       		    
#define SL_LV_NSTOP         0xD6
#define SL_LV_SCRON         0xD7
#define SL_LV_SCRRUNING     0xD8
#define SL_LV_SCRIZERO      0xD9
#define SL_LV_MPWMOUT		0xDA		
#define SL_LV_STATE		    0xDB		


//flag[14]
#define SL_RESET            0xE1
#define SL_SIOVST           0xE2
#define SL_NPR_TLOV         0xE3
#define SL_MPR_TLOV         0xE4
#define SL_DRAW			    0xE5			//=1»æÍ¼
#define SL_CHARGEOK			0xE6			//=1Ô¤³äµçÍê³É
#define SL_SPEED_IN_RANGE	0xE7			//=1×ªËÙÔÚ·¶Î§ÒÔÄÚ
#define SL_CONFIGPWM		0xE8			//=1 PWMÂö³åÅäÖÃÍê³É±êÖ¾Î»,²¢ÇÒ±£Ö¤ConfigPwm()Ö»ÄÜÔËÐÐÒ»´Î
#define SL_RUN				0xE9			//=1ÏµÍ³ÔËÐÐ
#define SL_STACTRIPEN		0xEA			//=1£¬¶¨×ÓµçÁ÷ºÜÐ¡£¬¶¨×Ó½Ó´¥Æ÷¶Ï¿ªÔÊÐí
#define	SL_TAOV				0xEB			//Íø²à³¬ÎÂ
#define SL_TBOV			    0xEC			//»ú²à³¬ÎÂ
#define SL_SKTOV            0xED            //Èí¼þÅÐ¶ÏSKIIP³¬ÎÂ
#define SL_NPR_PWMOUT       0xEE            //Íø²àÂö³åÒÑ¾­Ê¹ÄÜ±êÖ¾Î»,²¢ÇÒ±£Ö¤Enepwmio_NPR()Ö»ÄÜÔËÐÐÒ»´Î
#define SL_MPR_PWMOUT       0xEF            //»ú²àÂö³åÒÑ¾­Ê¹ÄÜ±êÖ¾Î»,²¢ÇÒ±£Ö¤Enepwmio_MPR()Ö»ÄÜÔËÐÐÒ»´Î




//------------------------------------const¶¨Òå--------------------------------------------

//eepromÎ»²Ù×÷
const  Uint16 ONEBYTE[8]={0x0080,0x0040,0x0020,0x0010,0x0008,0x0004,0x0002,0x0001};

//AD1544Í¨µÀÑ¡Ôñ
const  Uint16 AD1544[4]={0x0000,0x2000,0x4000,0x6000};		
//--------------------------------------±äÁ¿¶¨Òå-------------------------------------------
Uint16	flag[15];													//±êÖ¾Î»±äÁ¿
Uint16	disp[15];													//±êÖ¾±äÁ¿

float   RUN_mpridrf_exi;
Uint16  RUN_mpriq;
Uint16  _OUT3_TEST;
Uint16  _NQEPPCO;

int32   ET_SUM1;
int32   ET_SUM2;

/*ÏÂÃæµÄÓÃ×÷SVPWM¼ÆËã*/
Uint16 SW_NPR,SW_MPR; 
float   vdc;	 
float   m=0.0;
float   ua_m=0,ub_m=0,uc_m=0;  //µ÷ÖÆ²¨
float   u_alfa_NPR=0,u_beta_NPR=0;
float   u_alfa_MPR=0,u_beta_MPR=0;


//¸ø¶¨Öµ¼Ä´æÆ÷
struct	GIVE{
	float   npridrf;					   //Íø²àÖÐ¼äÖ±Á÷µçÑ¹¸ø¶¨Öµ
	float   npriqrf;                   //Íø²àÎÞ¹¦µçÁ÷¸ø¶¨Öµ(½öÍø²àÎÞ¹¦ÔËÐÐÊ±Ê¹ÓÃ)
	float   toqrf;                      //»ú²à×ª¾Ø¸ø¶¨Öµ(ÓÐ¹¦)
	float   anglerf;                    //»ú²à¹¦ÂÊÒòÊý½Ç¶È¸ø¶¨Öµ(ÎÞ¹¦) ½Ç¶È
}GIVE;
float OCS_Trf;                          //Ö÷¿Ø¸ø¹ýÀ´µÄ×ª¾ØÖ¸Áî

//¸ø¶¨»ý·ÖÏà¹Ø¼Ä´æÆ÷
struct	RUN{									
	float   npridrf;						//µçÑ¹¸ø¶¨»ý·ÖÖµ
	float   npridstep;						//µçÑ¹¸ø¶¨»ý·Ö²½³¤
	float   mpridrf;						//ÓÐ¹¦µçÁ÷¸ø¶¨»ý·ÖÖµ
	float   mpridstep;						//ÓÐ¹¦µçÁ÷¸ø¶¨»ý·Ö²½³¤
	float   npriqrf;						//ÎÞ¹¦µçÁ÷¸ø¨»ý·ÖÖ?
 	float   npriqstep;						//ÎÞ¹¦µçÁ÷¸ø¶¨»ý·Ö²½³¤
	float   mpriqrf;						//ÎÞ¹¦µçÁ÷¸ø¨»ý·ÖÖ?
 	float   mpriqstep;						//ÎÞ¹¦µçÁ÷¸ø¶¨»ý·Ö²½¤
	float   toqrf;						//×ª¾Ø¸ø¶¨»ý·ÖÖµ
	float   toqstep;					//×ª¾Ø¸ø¶¨»ý·Ö²½³¤
	float   aglrf;						//¹¦ÂÊÒòÊý½Ç¸ø¶¨»ý
	float   aglstep;					//¹¦ÂÊÒòÊý½Ç¸ø¶¨»ý·Ö²½³¤

	float   staidrf;					//½âÁÐ¶¨×ÓdÖáµçÁ÷Ö¸Áî
	float   staiqrf;					//½âÁÐ¶¨×ÓqÖáµçÁ÷Ö¸Áî
	float   staidstep;					//½âÁÐ¶¨×ÓdÖáµçÁ÷²½³¤
	float   staiqstep;					//½âÁÐ¶¨×ÓqÖáµçÁ÷²½³¤  

	float   mpridrf_g;						
	float   mpriqrf_g;					
    
    float   radianrf;
	float   mpridrf_exi;
	float   mpridrf_var;
}RUN; 
//×ø±ê±ä»»Ïà¹Ø¼Ä´æÆ÷
struct	TRANS_DATA{
    float a;           	//aÏà
	float b;           	//bÏà
	float c;           	//cÏà
	float alfa;	       	//alfaÖá
	float beta;	       	//betaÖá
	float d;		   	//dÖá
	float q;           	//qÖá 
	float sintheta;    	//ÕýÏÒÖµ
	float costheta;	   	//ÓàÏÒÖµ
	float dflt;	   		//ÂË²¨ºódÖµ
	float qflt;	   		//ÂË²¨ºóqÖµ
	float amp;			//·ùÖµ
	float ampflt;		//ÂË²¨ºó·ùÖµ
	float dflt2;	   	//Ð¡ÂË²¨ºódÖµ20091027atzyÎªÁË¼ì²âµçÍøµøÂä
};																 
struct	TRANS_DATA TRS_NPR_I;   //Íø²à±äÁ÷Æ÷µÄµçÁ÷£¨ÕâÀï²ÉÓÃNPR×÷Îªºó×º£¬²»ÓÃgrd£¬ÒÔÇø·ÖµçÍøµçÁ÷»¹ÊÇÍø²à±äÁ÷Æ÷µçÁ÷£©
struct	TRANS_DATA TRS_MPR_I;   //»ú²à±äÁ÷Æ÷µÄµçÁ÷
struct	TRANS_DATA TRS_MPR_U;   //»ú²à±äÁ÷Æ÷ËãÂö³åÓÃ
struct	TRANS_DATA TRS_NPR_U;   //Íø²à±äÁ÷Æ÷ËãÂö³å
struct	TRANS_DATA TRS_NGS_U;   //Íø²àµçÍøµçÑ¹
struct	TRANS_DATA TRS_STA_I;   //¶¨×ÓµçÁ÷
struct	TRANS_DATA TRS_STA_U;   //¶¨×ÓµçÑ¹
struct	TRANS_DATA TRS_GSTA_U;  //Ä¿±ê¶¨×ÓµçÑ¹
struct	TRANS_DATA TRS_PSTA_U;  //ÓÃÓÚ±àÂëÆ÷Î»ÖÃ¼ì²âµÄ¶¨×ÓµçÑ¹
struct	TRANS_DATA TRS_PMPR_I;  //ÓÃÓÚ±àÂëÆ÷Î»ÖÃ¼ì²âµÄ×ª×ÓµçÁ÷   
struct	TRANS_DATA DIP_NPR_U;  //ÓÃÓÚ¹¦ÂÊ¼ÆËã  
struct	TRANS_DATA DIP_NPR_I;  //ÓÃÓÚ¹¦ÂÊ¼ÆËã 
struct	TRANS_DATA DIP_STA_U;  //ÓÃÓÚ¹¦ÂÊ¼ÆËã 
struct	TRANS_DATA DIP_STA_I;  //ÓÃÓÚ¹¦ÂÊ¼ÆËã 
struct	TRANS_DATA DIP_MPR_I;  //ÓÃÓÚ¹¦ÂÊ¼ÆËã  


//PI»·Ïà¹Ø¼Ä´æÆ÷
struct PI_DATA
{
	float reference;							//¸ø¶¨Öµ
	float feedback;								//·´À¡Öµ
	float errorp;								//Ç°´ÎÎó²î
	float error;								//Îó²î
	float integrator;							//Ç°´Î»ýÖ½á¹û
	float out;
};  
struct PI_DATA PI_NPR_Id;				//Íø²à±äÁ÷Æ÷dÖáµçÁ÷±Õ»·
struct PI_DATA PI_NPR_Iq;				//Íø²à±äÁ÷Æ÷qÖáµçÁ÷±Õ»·
struct PI_DATA PI_MPR_Id;				//»ú²à±ä÷Æ÷dÖáµçÁ÷±Õ»·
struct PI_DATA PI_MPR_Iq;				//»ú²à±äÁ÷Æ÷qÖáµçÁ÷±Õ»·
struct PI_DATA PI_NPR_U;				//Íø²à±äÁ÷Æ÷µçÑ¹»·
struct PI_DATA PI_MPR_U;				//Õ»·
struct PI_DATA PI_STA_Id;				//Àø´Å¿ØÖÆd
struct PI_DATA PI_STA_Iq;				//Àø´Å¿ØÖÆq 

struct PI_PARA
{
   float kp;
   float ki;
   float kd;
   float errmax;
   float errmin;
   float incrementmax;
   float outmax;
};
struct PI_PARA PI_PARA_NPRU;
struct PI_PARA PI_PARA_NPRID;
struct PI_PARA PI_PARA_MPRU;
struct PI_PARA PI_PARA_MPRID;
struct PI_PARA PI_PARA_NPRIQ;
struct PI_PARA PI_PARA_MPRIQ;
struct PI_PARA PI_PARA_DYNU;
struct PI_PARA PI_PARA_DYNID;
struct PI_PARA PI_PARA_DYNIQ;
struct PI_PARA PI_PARA_MPRI;
struct PI_PARA PI_PARA_STAI;


//÷Ñ­»·¶¨Ê±Æ÷¼°ÑÓÊ±¼ÆÊýÆ÷
struct	MAIN_LOOP{
	int32 cnt1;					//Ö÷Ñ­»·¶¨Ê±¼ÄæÆ÷5ms
	int32 cnt2;					//Ö÷Ñ­»·¶¨Ê±¼Ä´æÆ÷10ms
	int32 cnt3;					//Ö÷Ñ­»·¶¨Ê±¼Ä´æÆ÷20ms
	int32 cnt4;					//Ö÷Ñ­»·¶¨Ê±¼Ä´æÆ÷50ms
	int32 cnt5;					//Ö÷Ñ­»·¶¨Ê±¼Ä´æÆ÷100ms
	int32 cnt6;					//Ö÷Ñ­»·¶¨Ê±¼Ä´æÆ÷1000ms

	int32 pulse;				//Ö÷Ñ­»··ÖÊ±Âö³å¼Ä´æÆ÷
	
	int32 cnt_poweron;			//preparation time delay
	int32 cnt_pwmout;			//PWMÊä³öÑÓÊ±
	int32 cnt_nprlamp;			//Íø²àÂö³å·¢³öÖ¸Ê¾µÆÉÁË¸ÑÓÊ±¼ÆÊý
	int32 cnt_mprlamp;			//»ú²àÂö³å·¢³öÖ¸Ê¾µÆÉÁË¸ÑÓÊ±¼ÆÊý 

	int32 cnt_freq;			   //ÆµÂÊÆ«ÒÆ¼Æ±
	int32 cnt_freq2;
	int32 cnt_cbfreq;
	int32 cnt_estop;
	int32 cnt_rcvr;				//¹ÊÕÏÑÓÊ±»Ö¸´¼ÆÊ±
	int32 cnt_otser;			//¬ÊÑÏÖØÑÓÊ?

	int32 cnt_exfault;
	int32 cnt_cbtp;
	int32 cnt_cberror;
	int32 cnt_mainkerror;
	int32 cnt_mainferror;
	int32 cnt_preerror;
	int32 cnt_stacerror;
	int32 cnt_pgovload;
	int32 cnt_qgovload;
	int32 cnt_canfault;
	int32 cnt_speedout;
	int32 cnt_uaclv1;   //20091027atzy
		

	int32 cnt_isteady0;
    int32 cnt_mprsteady0;
	int32 cnt_senszfstdy;

//sysctl_zl_start
    int32 cnt_opencontac;      //ÑÏÖØ²»¿É»Ö¸´¹ÊÕÏÏÂ£¬·¢³ö¶ÏÖ÷¶ÏÖ¸Áîºóµ½·¢³ö¶Ï¶¨×Ó½Ó´¥Æ÷ºÍÖ÷½Ó´¥Æ÷µÄÑÓÊ±

	int32 cnt_accontoff;       //ÑÓÊ±¶Ï½»Á÷½Ó´¥Æ÷
	int32 cnt_cboff;           //½ÓÕµ½ÏµÍ³Í£»úÖ¸Áîºó£¬ÑÓÊ±¶ÏÖ÷¶Ï¼ÆÊý

	int32 cnt_closecb;         //Õý³£Æô¶¯/Í£Ö¹£¬Ö÷¶Ï´¢ÄÜµ½Ö÷¶ÏºÏÕ¢µÄÑÓÊ±¼ÆÊý
	int32 cnt_precok;          //Õý³£Æô¶¯/Í£Ö¹£¬¼ì²âµ½Vdc´ïµ½950Vµ½·¢³öºÏÖ÷½Ó´¥Æ÷Ö¸ÁîµÄÑÓÊ±¼ÆÊý
	int32 cnt_scrondelay;       
//cy
	int32 cnt_vdcsteady;        //¼ì²âµ½VdcÎÈ¶¨ÔÚ240~450VÖ®¼äÖÃÖ±Á÷µçÑ¹ÎÈ¶¨±êÖ¾Î»µÄÑÓÊ±¼ÆÊý
	int32 cnt_vdcunsteady;      //¼ì²âµ½Vdc²»ÔÚ240~450VÖ®¼äÇåÖ±Á÷µçÑ¹ÎÈ¶¨±êÖ¾Î»µÄÑÓÊ±¼ÆÊý
	int32 cnt_acconton;			//Ö±Á÷µçÑ¹ÎÈ¶¨ºóºÏAC½Ó´¥Æ÷ÑÓÊ±¼ÆÊý
	int32 cnt_nprstart;			//½»Á÷µçÑ¹ÔÚ·¶Î§ÄÚÑÓÊ±ÖÃÉÏÎ»»úÒªÇóNPR·¢Âö³å±êÖ¾Î»
	int32 cnt_nprstop;			//½»Á÷µçÑ¹²»ÔÚ·¶Î§ÄÚÑÓÊ±ÇåÉÏÎ»»úÒªÇóNPR·¢Âö³å±êÖ¾Î»
//cy

//sysctl_zl_end 
    int32 cnt_AMUX;            //ÂýËÙAD
	int32 cnt_reset;
    int32 cnt_clostacmd;
	int32 cnt_nprcmd;
	int32 cnt_mprcmd;


	//canopen
	int32 canopen_rx;
	int32 canopen_tx;
	int32 cnt_cbreset;

	int32 et_relay1;     
	int32 et_relay2;

	int32 cnt_ocsein1;     
	int32 cnt_ocsein2;
	int32 cnt_ocssysrun1;     
	int32 cnt_ocssysrun2;

	int32 cnt_datasave;

}MAIN_LOOP;  

//ÂýËÙAD´¦Àí¼Ä´æÆ÷
Uint16 _OUT_AMUX1=0;  //ÓÃÓÚÂýËÙADÑ¡Í¨ÐÅºÅ£¬Ã¿´ÎÒªÑ¡Í¨ÏÂÒ»¸öADÍ¨µÀ£¬_OUT_AMUX¼Ó1£¬È»ºóËÍµ½CPLDÈ¥´¦Àí£¬Ñ¡Í¨16Ñ¡1Ð¾Æ¬
Uint16 _OUT_AMUX2;    //ÓÃÓÚÂýËÙADÑ¡Í¨ÐÅºÅ£¬Ã¿´ÎÒªÑ¡Í¨ÏÂÒ»¸öADÍ¨µÀ£¬_OUT_AMUX¼Ó1£¬È»ºóËÍµ½CPLDÈ¥´¦Àí£¬Ñ¡Í¨16Ñ¡1Ð¾Æ¬
struct  AMUX{
    float NPR_tempa;  		//NPRµÄAÏà°ëµ¼ÌåÎÂ¶È£¬Skiip´«»ØÀ´µÄ
    float NPR_tempb;  		//NPRµÄBÏà°ëµ¼ÌåÎÂ¶È£¬Skiip´«»ØÀ´µÄ
    float NPR_tempc;  		//NPRµÄCÏà°ëµ¼ÌåÎÂ¶È£¬Skiip´«»ØÀ´µÄ
    float MPR_tempa;  		//MPRµÄAÏà°ëµ¼ÌåÎÂ¶È£¬Skiip´«»ØÀ´µÄ
    float MPR_tempb;  		//MPRµÄBÏà°ëµ¼ÌåÎÂ¶È£¬Skiip´«»ØÀ´µÄ
    float MPR_tempc;  		//MPRµÄCÏà°ëµ¼ÌåÎÂ¶È£¬Skiip´«»ØÀ´µÄ
    float Lac_temp;   		//½»Á÷²âµç¸ÐÎÂ¶È
	float Ldudt_temp; 		//du/dtµÄÎÂ¶È
	float skiiptempmax;    	//SKIIPÄ£¿éµÄÎÂ¶È×î´óÖµ
	float NPR_skiiptemp;    //Íø²àSKIIPÄ£¿éµÄÎÂ¶È×î´óÖµ
	float MPR_skiiptemp;    //»ú²àSKIIPÄ£¿éµÄÎÂ¶È×î´óÖµ
}AMUX;

//ADÄ£¿é´¦Àí¼Ä´æÆ÷
struct	AD{
	int16  dat[24];													//ADµ±Ç°×ª»»½á¹û´æ·Å
	Uint32 cputime;
	Uint32 cputime_last;
}AD;
//cy
//AD×ª»»½á¹û¼Ä´æÆ÷
struct	ADFINAL{
	int16  ia1;				//½»Á÷²àµçÁ÷Ia
	int16  ib1;				//½»Á÷²àµçÁ÷Ib
	int16  idc;				//Ö±Á÷²àµçÁ÷Idc
	int16  uab;				//½»Á÷²àµçÑ¹Uab
	int16  ubc;				//½»Á÷²àµçÑ¹Ubc
    int16  udc;             //Ö±Á÷²àµçÑ¹Udc
    int16  AMUX;            //ÂýËÙADÐÅºÅ
	int16  ia2;				//½»Á÷380V²àµçÁ÷
}ADFINAL;
//cy   

//ÍøÑ¹Ê¸Á¿
struct AD_DATA{
	  float  a;
	  float  b;
	  float  c;
	  float  ab;
	  float  bc;
	  float  ac;
	  float  ba;
	  float  dc; 
	  float  a_temp;
	  float  b_temp;
	  float  c_temp;
	  float  ab_temp;
	  float  bc_temp;
	  float  a_dc;
	  float  b_dc;
	  float  c_dc;
	  float  ps;
	  float  a2;
};
struct AD_DATA AD_OUT_U;  //½»Á÷²àµçÑ¹
struct AD_DATA AD_OUT_STA_U;  //µç»ú¶¨×Ó²àµçÑ¹ ´óÂË²¨Í¨µÀ
struct AD_DATA AD_OUT_NGS_U;  //µçÍøµçÑ¹£¨Ö÷¶Ïºó£©
struct AD_DATA AD_OUT_NPR_I;  //Íø²à±äÁ÷Æ÷µçÁ÷
struct AD_DATA AD_OUT_MPR_I;  //»ú²à±äÁ÷Æ÷µçÁ÷
struct AD_DATA AD_OUT_STA_I;  //¶¨×Ó²àµçÁ÷  
struct AD_DATA AD_OUT_NGF_U;  //µçÍøµçÑ¹£¨Ö÷¶Ïºó£©´óÂË²¨Í¨µÀ
struct AD_DATA AD_OUT_STAD_U;  //²îÖµ
struct AD_DATA AD_OUT_SCR_I;  //ACTIVECROWBARµçÁ÷  
 

float  AD_OUT_UDC; //AD¼ÆËãºóÊä³öµÄÖ±Á÷µçÑ¹£¨V£©
float  AD_OUT_UDC_PRO; //AD¼ÆËãºóÊä³öµÄÖ±Á÷µçÑ¹£¨V£© LVRT±£»¤ÓÃVdc£¬¼õÐ¡ÂË²¨

//ÇóÆ½¾ùÖµ
struct MEAN_DATA{
       float ia,ib,ic;  	//½»Á÷²àµçÁ÷Æ½¾ùÖµÂË²¨
	   float idc;  			//Ö±Á÷²àµçÁ÷Æ½¾ùÖµÂË²¨
	   float uab,ubc;	   	//½»Á÷²àÏßµçÑ¹Æ½¾ùÖµÂË²¨
	   float ua,ub,uc;	   	//½»Á÷²àÏàµçÑ¹Æ½¾ùÖµÂË²¨
       float ia2;  			//380V²àµçÁ÷Æ½¾ùÖµÂË²¨
	   float udc;			//Ö±Á÷²àµçÑ¹Æ½¾ùÖµÂË²¨

	   float zfia1,zfib1,zfic1; 	//Íø²àµçÁ÷´«¸ÐÆ÷ÁãÆ¯ÂË²¨
	   float zfuab,zfubc; 			//Íø²àµçÑ¹´«¸ÐÆ÷ÁãÆ¯ÂË²¨
	   float zfidc;					//Ö±Á÷²àµçÁ÷´«¸ÐÆ÷ÁãÆ¯ÂË²¨
	   float zfia2;					//380V²àµçÁ÷´«¸ÐÆ÷ÁãÆ¯ÂË²¨

}MEAN_DATA;  

//±£»¤Ä£¿é½á¹û±äÁ¿
struct	PRO{									
				float	Uab;	//½»Á÷²à abÏßµçÑ¹Êµ¼ÊÖµ(V)
				float	Ubc;	//½»Á÷²à bcÏßµçÑ¹Êµ¼ÊÖµ(V)
				float   Ua;	  	//½»Á÷²àaÏàµçÑ¹V RMS
				float   Ub;	  	//½»Á÷²àbÏàµçÑ¹V RMS
				float   Uc;	  	//½»Á÷²àcÏàµçÑ¹V RMS
				float   Ia;   	//½»Á÷²àAÏà²¢ÍøµçÁ÷ÓÐÐ§Öµ,µ¥Î»A
				float   Ib;	  	//½»Á÷²àBÏà²¢ÍøµçÁ÷ÓÐÐ§Öµ,µ¥Î»A
				float   Ic;	  	//½»Á÷²àCÏà²¢ÍøµçÁ÷ÓÐÐ§Öµ,µ¥Î»A
   				float   IPM_tempa; //IPMÄ£¿éAÏàÎÂ¶È
				float   IPM_tempb; //IPMÄ£¿éBÏàÎÂ¶È
				float   IPMtempmax;//IPMÄ£¿éµÄÎÂ¶È×î´óÖµ
   				float   L_temp; //µç¸ÐÎÂ¶È
				float   T_temp; //±äÑ¹Æ÷ÎÂ¶È 


	         	float	NPR_iac;								//²¢ÍøµçÁ÷·åÖµ,»ù×¼µçÁ÷µÄ°Ù·ÖÖµ
				float	MPR_iac;								//¶¨×ÓµçÁ÷·åÖµ,»ù×¼µçÁ÷µÄ°Ù·ÖÖµ
				float	udc;									//ÖÐ¼äÖ±Á÷µçÑ¹ÕýÊµ¼ÊÖµ(V)
				float	NPR_uab;								//Íø²à abÏßµçÑ¹Êµ¼ÊÖµ(V)
				float	NPR_ubc;								//Íø²à bcÏßµçÑ¹Êµ¼ÊÖµ(V)
				float	STA_uab;								//¶¨×Ó²à abÏßµçÑ¹Êµ¼ÊÖµ(V)
				float	STA_ubc;								//¶¨×Ó²à bcÏßµçÑ¹Êµ¼ÊÖµ(V)
				float	GID_uab;								//µçÍø²à abÏßµçÑ¹Êµ¼ÊÖµ(V) 20091026atzy
				float	GID_ubc;								//µçÍø²à bcÏßµçÑ¹Êµ¼ÊÖµ(V) 20091026atzy
				float	rcvr;									//ÑÓ³Ù»Ö¸´Ê±¼ä
				float   STA_iac;                            	//¶¨×Ó½»Á÷µçÁ÷iac
				float   STA_iba;                            	//¶¨×Ó½»Á÷µçÁ÷iba
				float   speed;                               	//µç»ú×ªËÙ r/min
				float   speedflt;                               //20090815
				float   sta_iar;	  							//¶¨×Ó²àaÏàµçÁ÷A RMS
				float   sta_ibr;	  							//¶¨×Ó²àbÏàµçÁ÷A RMS
				float   sta_icr;	  							//¶¨×Ó²àcÏàµçÁ÷A RMS
				float   sta_uar;	  							//¶¨×Ó²àaÏàµçÑ¹V RMS
				float   sta_ubr;	  							//¶¨×Ó²àbÏàµçÑ¹V RMS
				float   sta_ucr;	 							//¶¨×Ó²àcÏàµçÑ¹V RMS
				float   npr_uar;	  							//Íø²àaÏàµçÑ¹V RMS
				float   npr_ubr;	  							//Íø²àbÏàµçÑ¹V RMS
				float   npr_ucr;	  							//Íø²àcÏàµçÑ¹V RMS
				float   npr_iar;   								//Íø²à,AÏà²¢ÍøµçÁ÷ÐÐ§Öµ,µ¥Î»A
				float   npr_ibr;	  							//Íø²à,BÏà²¢ÍøµçÁ÷ÐÐ§Öµ,µ¥Î»A
				float   npr_icr;	  							//Íø²à,CÏà²¢ÍøµçÁ÷ÓÐÐ§Öµ,µ¥Î»A
				float   Psactive; 								//¶¨×Ó²àÓÐ¹¦¹¦ÂÊ
				float   Psreactive; 							//¶¨Ó²àÎÞ¹¦¹¦ÂÊ
				float   Ps;          							//¶¨×Ó²àÊÓÔÚ¹¦ÂÊ
				float   Pnactive;    							//Íø²àÓÐ¹¦¹¦ÂÊ
				float   Pnreactive;  							//Íø²àÎÞ¹¦¹¦ÂÊ
				float   Pn;          							//Íø²àÊÓÔÚ¹¦Ê
				float   Pgactive;    							//²¢Íø×ÜµÄÓÐ¹¦¹¦ÂÊ	
				float   Pgreactive;  							//Íø²à×ÜÄÞ¹¦¹¦ÂÊ				
				float   Pg;       								//¢Íø×ÜµÄÊÓÔÚ¹¦ÂÊ
		   }PRO; 
 
//ÏÔÊ¾à¿Ø±äÁ¿
struct	DISP{										
    			float  Iai;   	//½»Á÷²àµçÁ÷Ë²Ê±Öµ,µ¥Î»A
				float  Ibi;	  	//½»Á÷²àµçÁ÷Ë²Ê±Öµ,µ¥Î»A
				float  Ici;	  	//½»Á÷²àµçÁ÷Ë²Ê±Öµ,µ¥Î»A
				float  Ia;		//½»Á÷²àµçÁ÷ÓÐÐ§Öµ,µ¥Î»A
				float  Ib;	  	//½»Á÷²àµçÁ÷ÓÐÐ§Öµ,µ¥Î»A
				float  Ic;	  	//½»Á÷²àµçÁ÷ÓÐÐ§Öµ,µ¥Î»A
    			float  Uab;	  //Íø²àabÏàµçÑ¹V RMS
				float  Ubc;	  //Íø²àbcÏàµçÑ¹V RMS

				float  L_temp;  //µç¸ÐÎÂ¶È ÉãÊÏ¶È
				float  T_temp;  //±äÑ¹Æ÷ÎÂ¶È ÉãÊÏ¶È
				float  IPM_tempa;  //IPMÄ£¿éAÏàÎÂ¶È
				float  IPM_tempb;  //IPMÄ£¿éBÏàÎÂ¶È
				float  udc;			//ÖÐ¼äÖ±Á÷µçÑ¹
				float  npridrf;		//dÖáµçÁ÷Ö¸Áî		
				float  npriqrf;		//qÖáµçÁ÷Ö¸Áî
				float  freq;
				float  pionu;   	//Íø²àµçÑ¹»·Êä³ö
				float  pionid;		//Íø²àµçÁ÷d»·Êä³ö
				float  pioniq;		//Íø²àµçÁ÷q»·Êä³ö
				float  Pnactive;    //½»Á÷²àÓÐ¹¦¹¦ÂÊ
				float  Pnreactive;  //½»Á÷²àÎÞ¹¦¹¦ÂÊ
				float  Pn;          //½»Á÷²àÊÓÔÚ¹¦ÂÊ
			}DISP;
 
//¶»Ä£¿é±äÁ¿
struct CAP_DATA	{
					float		prd;				//Cap4ÊÂ¼þÖÜÆÚ
					Uint32		adsmptsctr; 		//AD²ÉÑùÊ±¿ÌµÄCap4¼ÆÊýÆ÷Öµ(±¾´ÎADÔÚCAP4Ö®ºóÔËÐÐ)
					float 		phase;	    		//ÊÂ¼þµ±Ç°ÏàÎ»//ÓÃÓÚÏàÐò¼ì²é
					float 		freqtmp;			//¾´ÎÊÂ¼þÆµÂÊ
					float 		freq;	    		//È·ÈÏºóµÄÆµÂÊ
					float	    omigasyn;			//Í¬²½½ÇÆµÂÊ£­µçÆµÂÊ
					float 		omigaslp;	    	//×ª²î½ÇÆµÂÊ
					float	    radpertb;			//¼ÆÊýÆ÷¼Æµ¥Î»Ê±¼äÊ¸Á¿Î»ÖÃÔöÁ¿ rad per timebase
					float	    nprtrstheta;		//Íø²àËã·¨Õý±ä»»½Ç¶È
					float	    npratitheta;		//Íø²àËã·¨·´±ä»»½Ç¶È
					float	    mprtrstheta;		//»úàËã·¨Õý±ä»»½Ç¶È
					float	    mpratitheta;		//»ú²àËã·¨·´±ä»»½Ç¶È
					float	    stavectheta;	    //¶¨×Ó´ÅÁ´Ïà¶ÔÓëAÏàÖáÏßÎ»ÖÃ	
				};
struct CAP_DATA CAP3,CAP4;

struct QEPDATA{
//----------------------×ª×ÓÎ»ÖÃ¼ì²â±äÁ¿-----------------------------------------------------------
					Uint16		qcapprd;		//QCAPµ¥ÔªÖÜÆÚ¼Ä´æÆ÷Öµ£¬ÓÃÓÚ²âÖÜ·¨Ëã×ªËÙ
					float 		omigamec;		//»úÐµ½ÇËÙ¶È
					float 		omigarote;	    //µçÆø½ÇÙ¶È rotor electric
					float 		omigaroteflt;	//
					float 		rotpos;			//×ª×Óµ±Ç°Î»ÖÃrad£¨µç»¡¶È£©
					Uint32   	adsmposcnt;		//²ÉÑùÊ±¿Ì±àÂëÆ÷¶ÁÊý  
					Uint32 		posilat;        //¼ÇÂ¼ZÐÅºÅÉÏÉýÑØÊ±CNT¼ÆÊýÖµ
					Uint32 		qposlat;        //¼ÇÂ¼Unit timeÄÚQEPCNTµÄ¼ÆÊýÖµ£¬ÓÃÓÚ²âÆµ·¨Ëã×ªËÙ
					Uint32 		qposlat1;        //¼ÇÂ¼Unit timeÄÚQEPCNTµÄ¼ÆÊýÖµ£¬ÓÃÓÚ²âÆµ·¨Ëã×ªËÙ
					Uint32 		qposlat2;        //¼ÇÂ¼Unit timeÄÚQEPCNTµÄ¼ÆÊýÖµ£¬ÓÃÓÚ²âÆµ·¨Ëã×ªËÙ
					float 		rotposdisp;		//DAÏÔÊ¾
					float 		rotradpret0;	//ÓÃÓÚQEP ZÐÅºÅ¿¹¸ÉÈÅ
//----------------------±àÂëÆ÷Î»ÖÃ¼ì²â±äÁ¿--------------------------------------------------------	
					float 		encodpos;		//±àÂëÆ÷Î»ÖÃrad£¨µç»¡¶È£©
					float 		u_stapos;		//2S²Î¿¼ÏµÏÂ¶¨×ÓµçÑ¹Ê¸Á¿µÄÎ»ÖÃrad£¨µç»¡¶È£©
					float 		i_rotpos;		//2S²Î¿¼ÏµÏÂ×ª×ÓµçÁ÷Ê¸Á¿µÄÎ»ÖÃrad£¨µç»¡¶È£©
			  }QEPDATA; 

//SCIÄ£¿é±äÁ¿
struct	SCI{
					Uint16 txb[SCI485NUM];			//SCIB·¢ËÍÊý¾Ý
					Uint16 rxb[SCI485NUM];			//SCIB½ÓÊÕÊý¾Ý	
					int32 cnt_sciover;				//SCI·¢ËÍ/½ÓÊÕ³¬Ê±¶¨Ê±Æ÷
					int32 cnt_scispace;				//SCI½ÓÊÕµ½·¢ËÍµÄ¼ä¸ô¶¨Ê±Æ÷
		   }SCI;

//SCICANOPENÄ£¿é±äÁ¿
struct	SCI_CANOPEN{
					Uint16 txb[SCICANOPENTXNUM];			//SCIB·¢ËÍÊý¾Ý
					Uint16 rxb[SCICANOPENRXNUM];			//SCIB½ÓÊÕÊý¾Ý
					Uint16 heartbeat;
					int32  cnt_heartbeat;
					int32  cnt_sciover;
					Uint16 rx_controlword;
					Uint16 rx_npridrf;
					Uint16 rx_npriqrf;
					Uint16 rx_torque;
					Uint16 rx_angle;
					Uint16 tx_torque;
					Uint16 tx_speed;
					Uint16 tx_state1;
					Uint16 tx_state2;	
					Uint16 tx_watertempin;
					Uint16 tx_watertempout;
					Uint16 tx_skiiptempmax;
					Uint16 tx_demand;
		   }SCI_canopen;

//SPIÄ£¿é±äÁ¿
struct	SPI{
					Uint16 da7614_txb[SPINUM];		//SPI,DA·¢ËÍÊý¾Ý
					Uint16 da7614point;				//
		   }SPI;

//EEPROMÄ£¿é±äÁ¿
struct	EEPROM{
				Uint16 data[11];					//¶Á³ö»òÐ´ÈëµÄÊý¾Ý
				Uint16 point;						//EEPROMµ±Ç°×÷±äÁ¿ÐòºÅ
				Uint16 mcode;						//ÐèÒªÐÞ¸ÄµÄ¹¦ÄÜÂëÃû³Æ
			  }EEPROM;

//RTIMERÄ£¿é±äÁ¿
struct	RTIMER{
				Uint16 time[6];				//µ±Ç°Ê±¼ä[5~0]-->Äê ÔÂ ÈÕ Ê± ·Ö Ãë£¨¾ùÎª8Î»Êý¾Ý£©
			  }RTIMER;

//-----------------------------ÄÚ²¿±äÁ¿----------------------------------------------------------
Uint16  _NULL_VAL=0;
Uint16  _MSG_SCOUT1;												//SCOUTÐÅÏ¢¼¶±ð(Ç°´Î)
Uint16  _MSG_SCOUT2;												//SCOUTÐÅÏ¢¼¶±ð(±¾´Î)
Uint16  _SY_RTRN;
Uint32   POSCNT_TEST;
float   DM_imrd;   						//×ª×ÓÀø´ÅµçÁ÷
float   DM_imrq;   						//×ª×ÓÀø´ÅµçÁ÷
float   DM_Lr;							//µ±Ç°ÖØÊÔ´ÎÊý
float   Te_feedback;                    //Êµ¼Ê×ª¾ØÖµ·´À¡
float   Pnactive;    					//Íø²àÓÐ¹¦¹¦ÂÊ
float   Pnreactive;    					//Íø²àÎÞ¹¦¹¦ÂÊ
//----------------------------²ÎÊý±äÁ¿------------------------------------------------------------
Uint16 _MC_TYPE;						//»úÐÍ²ÎÊý
Uint16 _MC_REV;							//Èí¼þ°æ±¾
Uint16 _MC_DATE;						//³ö³§ÈÕÆÚ
Uint16 _MC_ID;							//²úÆ·±àºÅ
Uint16 _SCIB_ADDR;						//485½ÚµãµØÖ·

Uint16 _SW_FR;							//¿ª¹ØÆµÂÊ(kHz)
Uint16 _DEADTIME;						//Âö³åµÄ×îÐ¡µ¼Í¨Ê±¼ä(us)
Uint16 _COMPTIME;						//Âö³åµÄ×îÐ¡µ¼Í¨Ê±¼ä(ms)
Uint16 _MINONTIME;						//Âö³åµÄ×îÐ¡µ¼Í¨Ê±¼ä(us)

Uint16 _RU_UDCT;						//µçÑ¹Ö¸Áî»ý·ÖÊ±¼ä(ms)
Uint16 _RU_IDT;							//µçÁ÷Ö¸Áî»ý·ÖÊ±¼ä(ms)
Uint16 _RU_IQT;							//µçÁ÷Ö¸Áî»ý·ÖÊ±¼ä(ms)
Uint16 _RU_TOQT;						//×ª¾ØÖ¸Áî»ý·ÖÊ±ä(ms)
Uint16 _RU_AGLT;                        //¹¦ÂÊÒòÊý½ÇÖ¸Áî»ý·ÖÊ±¼ä(ms)
Uint16 _NIDRF;							//Ö±Á÷µçÑ¹¸ø¶¨Öµ
Uint16 _MIDRF;							//dÖáµçÁ÷¸ø¶¨Öµ
Uint16 _NIQRF;							//qÖáµçÁ÷¸ø¶¨Öµ
Uint16 _MIQRF;							//qÖáµçÁ÷¸ø¶¨Öµ
Uint16 _TOQRF;							//×ª¾ØÖ¸Áî
Uint16 _AGLRF;							//»ú²à¹¦ÂÊÒòÊý½Ç
Uint16 _EIDCO;							//ÊÖ¶¯ »ú²àÀø´ÅµçÁ÷µ÷ÕûÏµÊý
Uint16 _ENCODPOS;						//ÊÖ¶¯ ±àÂëÆ÷³õÊ¼Î»ÖÃ½Ç¶È
Uint16 _EIN;							//
Uint16 _SYSRUN;							//
Uint16 _RESET;							//
Uint16 _STDBY1;							//±¸ÓÃ1
Uint16 _STDBY2;							//±¸ÓÃ2
Uint16 _STDBY3;							//±¸ÓÃ3
Uint16 _STDBY4;							//±¸ÓÃ4
Uint16 _STDBY5;							//±¸ÓÃ5
Uint16 _STDBY6;							//±¸ÓÃ6
Uint16 _STDBY7;							//±¸ÓÃ7
Uint16 _STDBY8;							//±¸ÓÃ8
float _eidco;
float _encodpos;

float _stdby01;							//±¸ÓÃ¾­¹ýÐ¡Êýµã´¦ÀíºóÖµ
float _stdby02;							//±¸ÓÃ¾­¹ýÐ¡Êýµã´¦ÀíºóÖµ
float _stdby03;							//±¸ÓÃ¾­¹ýÐ¡Êýµã´¦ÀíºóÖµ
float _stdby04;							//±¸ÓÃ¾­¹ýÐ¡Êýµã´¦ÀíºóÖµ
float _stdby05;							//±¸ÓÃ¾­¹ýÐ¡Êýµã´¦ÀíºóÖµ
float _stdby06;							//±¸ÓÃ¾­¹ýÐ¡Êýµã´¦ÀíºóÖµ
float _stdby07;							//±¸ÓÃ¾­¹ýÐ¡Êýµã´¦ÀíºóÖµ
float _stdby08;							//±¸ÓÃ¾­ýÐ¡Êýµã´¦Àíºóµ
Uint16 _SCOUTL;							//µÍ16¸ö¹ÊÕÏÂëµ½SCOUT1
Uint16 _SCOUTH;							//¸ß16¸ö¹ÊÕÏÂëµ½SCOUT2 
//------------------------ÔËÐÐÄ£Ê½±äÁ¿-------------------------------------------------------------
Uint16 _ENSCR;							//
Uint16 _COMP2;							//µç»ú²à±äÁ÷Æ÷ËÀø²¹³¥Ê¹ÄÜ
Uint16 _AUTOCSTAC;							
Uint16 _OPERATION;						//ÔËÐÐÄ£Ê½
Uint16 _CANOPER;						//ÏµÍ³CANÊ¹ÄÜÄ£Ê½

//-----------------------PI·²ÎÊý±äÁ¿--------------------------------------------------------------
Uint16	_NPR_U_Kp;		  		//Íø²à±äÁ÷Æ÷µçÑ¹±Õ»·±ÈÀýÏµÊý
Uint16	_NPR_U_Ki;		   		//Íø²àäÁ÷Æ÷µçÑ¹±Õ»·»ý·ÖÏµÊý
Uint16	_NPR_U_Kd;		   		//Íø²à±äÁ÷Æ÷µçÑ¹±Õ»·Î¢·ÖÏµÊý
Uint16	_NPR_U_outmax;			//Íø²à±äÁ÷Æ÷çÑ¹±Õ»·Êä³öÏÞ·ù
Uint16	_NPR_U_errmax;		 	//Íø²à±äÁ÷Æ÷µçÑ¹±Õ»·Îó²îÏÞ·ù
Uint16	_NPR_U_errmin;		   	//Íø²à±äÁ÷Æ÷µçÑ¹±Õ»·Îó²îîÐÖµ
Uint16	_NPR_U_incrementmax;	//Íø²à±äÁ÷Æ÷µçÑ¹±Õ»·ÔöÁ¿ÏÞ·ù

Uint16	_NPR_ID_Kp;				//Íø²à±äÁ÷Æ÷µçÁ÷±Õ·±ÈÀýÏµÊý
Uint16	_NPR_ID_Ki;	   			//²à±äÁ÷Æ÷µçÁ÷±Õ»·»ý·ÖÏµÊý
Uint16	_NPR_ID_Kd;	   			//Íø²à±äÁ÷Æ÷µçÁ÷±Õ»·Î¢·ÖÏµÊý
Uint16	_NPR_ID_outmax;			//Íø²à±äÁ÷Æ÷µçÁ÷±Õ»·ÊäöÏÞ·ù
Uint16	_NPR_ID_errmax;	 		//Íø²à±äÁ÷Æ÷µçÁ÷±Õ»·Îó²îÏÞ·ù
Uint16	_NPR_ID_errmin;	  		//Íø²à±äÁ÷Æ÷µçÁ÷±Õ»·Îó²îîÐ¡Öµ
Uint16	_NPR_ID_incrementmax; 	//Íø²à±äÁ÷Æ÷µçÁ÷±Õ»·öÁ¿ÏÞ·ù

Uint16	_NPR_IQ_Kp;				//Íø²à±äÁ÷Æ÷µçÁ÷±Õ»·±ÈÀýÏµÊý
Uint16	_NPR_IQ_Ki;	   			//Íø²à±ä÷Æ÷µçÁ÷±Õ»·»ý·ÖÏµÊý
Uint16	_NPR_IQ_Kd;	   			//Íøà±äÁ÷Æ÷µçÁ÷±Õ»·Î¢·ÖÏµÊý
Uint16	_NPR_IQ_outmax;			//Íø²à±äÁ÷Æ÷µçÁ÷±Õ»·Êä³öÏÞ·ù
Uint16	_NPR_IQ_errmax;	 		//Íø²à±äÁ÷Æ÷µçÁ÷±Õ»·Îó²îÏÞ·ù
Uint16	_NPR_IQ_errmin;	  		//Íøà±äÁ÷Æ÷µçÁ÷±»·Îó²î×îÐ¡Öµ
Uint16	_NPR_IQ_incrementmax; 	//Íø²à±äÁ÷Æ÷µçÁ÷±Õ»·ÔöÁ¿ÏÞ·ù

Uint16	_MPR_U_Kp;	   			//»ú²à±äÁ÷Æ÷µçÑ¹±Õ»·±ÈÀýÏµÊý
Uint16	_MPR_U_Ki;	  			//»ú²à±äÁ÷Æ÷µçÑ¹±Õ»·»ý·ÖÏµÊý
Uint16	_MPR_U_Kd;	  			//»ú²à±äÁ÷Æ÷µçÑ¹±Õ»·Î¢·ÖÏµÊý
Uint16	_MPR_U_outmax;	 		//»ú²à±äÁ÷Æ÷µçÑ¹±Õ»·Êä³öÏÞ·ù
Uint16	_MPR_U_errmax;	  		//»ú²à±äÁ÷Æ÷µçÑ¹±Õ»·Îó²îÏÞù
Uint16	_MPR_U_errmin;		 	//»ú²à±äÁ÷Æ÷µçÑ¹±Õ»·Îó²î×îÐ¡Öµ
Uint16	_MPR_U_incrementmax; 	//»ú²à±äÁ÷Æ÷µçÑ¹±Õ»·ÔöÁ¿ÏÞ·ù

Uint16 _MPR_ID_Kp;				//»ú²à±äÁ÷Æ÷µçÁ÷±Õ»·±ÈÀýÏµÊý
Uint16 _MPR_ID_Ki;				//»ú²à±äÁ÷Æ÷µçÁ÷±Õ»·»ý·ÖÏµÊý
Uint16 _MPR_ID_Kd;				//»ú²à±äÁ÷Æ÷µçÁ÷±Õ»·Î¢·ÖÏµÊý
Uint16 _MPR_ID_outmax;			//»ú²à±äÁ÷Æ÷µçÁ÷±Õ»·Êä³öÏÞ·ù
Uint16 _MPR_ID_errmax;			//»ú²àäÁ÷Æ÷µçÁ÷±Õ»·Îó²îÏÞ·ù
Uint16 _MPR_ID_errmin;			//»ú²à±äÁ÷Æ÷µçÁ÷±Õ»·Îó²î×îÐ¡Öµ
Uint16 _MPR_ID_incrementmax;		//»ú²à±äÁ÷Æ÷µçÁ÷±Õ»·ÔöÁ¿ÏÞ·ù

Uint16 _MPR_IQ_Kp;				//»ú²à±äÁ÷Æ÷µçÁ÷±Õ»·±ÈÀýÏµÊý
Uint16 _MPR_IQ_Ki;				//»ú²à±äÁ÷Æ÷µçÁ÷±Õ»·»ý·ÖÏµÊý
Uint16 _MPR_IQ_Kd;				//»ú²à±äÁ÷Æ÷µçÁ÷±Õ»·Î¢·ÖÏµÊý
Uint16 _MPR_IQ_outmax;			//»ú²à±äÁ÷Æ÷µçÁ÷±Õ»·Êä³öÏÞ·ù
Uint16 _MPR_IQ_errmax;			//»ú²à±äÁ÷Æ÷µçÁ÷±Õ»·Îó²îÏÞ·ù
Uint16 _MPR_IQ_errmin;			//»ú²à±äÁ÷Æ÷µçÁ÷±Õ»·Îó²î×îÐ¡Öµ
Uint16 _MPR_IQ_incrementmax;	//»ú²à±äÁ÷Æ÷µçÁ÷±Õ»·ÔöÁ¿ÏÞ·ù


Uint16	_DYN_U_Kp;	   			//»ú²à±äÁ÷Æ÷µçÑ¹±Õ»·±ÈÀýÏµÊý
Uint16	_DYN_U_Ki;	  			//»ú²à±äÁ÷Æ÷µçÑ¹±Õ»·»ý·ÖÏµÊý
Uint16	_DYN_U_Kd;	  			//»ú²à±äÁ÷Æ÷µçÑ¹±Õ»·Î¢·ÖÏµÊý
Uint16	_DYN_U_outmax;	 		//»ú²à±äÁ÷Æ÷µçÑ¹±Õ»·Êä³öÏÞ·ù
Uint16	_DYN_U_errmax;	  		//»ú²à±äÁ÷Æ÷µç¹±»·Îó²îÏÞ·ù
Uint16	_DYN_U_errmin;		 	//»ú²à±äÁ÷Æ÷µçÑ¹±Õ»·Îó²î×îÐ¡Öµ
Uint16	_DYN_U_incrementmax; 	//»ú²à±äÁ÷Æ÷µç¹±Õ»·ÔöÁ¿ÏÞ·ù


Uint16 _SC_RTRN;													//¹ÊÕÏ×î´óÖØÊÔ´ÎÊý
Uint16 _SC_RTRT;													//Á½´Î¹ÊÕÏÖØÊÔ¼ä¸ôÊ±¼ä(ms)

Uint16 _SC_IACOV1;													//Ë²Ê±µ¹ýÁ÷±£»¤Öµ£¬»ù×¼µçÁ÷µÄ°Ù·ÖÖµ)
Uint16 _SC_UDCOV;													//ÖÐ¼äÖ±Á÷µçÑ¹¹ýÑ¹Öµ(V)
Uint16 _SC_UDCOVH;													//ÖÐ¼äÖ±Á÷µçÑ¹¹ýÑ¹Öµ£¨ÍøÑ¹µøÂä£©(V)
Uint16 _SC_UDCLV;													//ÖÐ¼äÖ±Á÷µçÑ¹Ç·Ñ¹Öµ(V)
Uint16 _SC_VDCON;													//ÉÏµçµçÑ¹
Uint16 _SC_UACOV1;													//ÍøÑ¹½»Á÷µçÑ¹¹ýÑ¹¶¯×÷Öµ(V)
Uint16 _SC_UACLV1;													//½»Á÷µçÑ¹È±Ïà¶¯×÷Öµ(V)
Uint16 _SC_IACOV2;													//·´Ê±ÏÞ¹ýÁ÷±£»¤Öµ£¬»ù×¼µçÁ÷µÄ°Ù·ÖÖµ)
Uint16 _SC_PGOV;													//
Uint16 _SC_QGOV;													//
Uint16 _SC_IACOVST;                                                 //¶¨×ÓµçÁ÷¹ýÁ÷±£»¤ 

Uint16 _BA_ERR4;													//µÚËÄ´Î¹ÊÕÏÐÅÏ¢
Uint16 _BA_ERR3;													//µÚÈý´Î¹ÊÕÏÐÅÏ¢
Uint16 _BA_ERR2;													//µÚ¶þ´ÎÊÕÏÐÅÏ¢
Uint16 _BA_ERR1;													//µÚÒ»´Î¹ÊÕÏÐÅÏ¢
//--------------------------------±¨¾¯ÐÅÏ¢±ä¿-----------------------------------------------------
Uint16 _BA_ENIDRF;													//×îÐÂ¹ÊÕÏÊ±¿Ì dÖáµçÁ÷Ö¸Áî(A)
Uint16 _BA_ENIQRF;													//×îÐÂ¹ÊÕÏÊ±¿Ì qÖáµçÁ÷Ö¸Áî(A)
Uint16 _BA_EMIQRF;													//×îÐÂ¹ÊÕÏÊ±¿Ì qÖáµçÁ÷Ö¸Áî(A)
Uint16 _BA_ETOQRF;													//×îÐÂ¹ÊÕÏÊ±¿Ì ×ª¾ØÖ¸Áî(NM)
Uint16 _BA_EURF;													//×îÐÂ¹ÊÕÏÊ±¿Ì ÖÐ¼äÖ±Á÷µçÑ¹¸ø¶¨(V)
Uint16 _BA_EUDC;													//×îÐÂ¹ÊÕÏÊ±¿Ì ÖÐ¼äÖ±Á÷µçÑ¹(V)
Uint16 _BA_EAGLRF;													//×îÐÂ¹ÊÕÏÊ±¿Ì ÎÞ¹¦½Ç¶ÈÖ¸Áî()
Uint16 _BA_EIA1;													//×îÐÂ¹ÊÕÏÊ±¿Ì Íø²àAÏàµçÁ÷ÓÐÐ§Öµ(A)
Uint16 _BA_EIB1;													//×îÐÂ¹ÊÕÏÊ±¿Ì Íø²àBÏàµçÁ÷ÓÐÐ§Öµ(A)
Uint16 _BA_EIC1;													//×îÐÂ¹ÊÕÏÊ±¿Ì Íø²àCÏàµçÁ÷ÓÐÐ§Öµ(A)
Uint16 _BA_EIA2;													//×îÐÂ¹ÊÕÏÊ±¿Ì ç»ú²àAÏàµçÁ÷ÓÐÐ§Öµ(A)
Uint16 _BA_EIB2;													//×îÐÂ¹ÊÕÏÊ±¿Ì µç»ú²àBàµçÁ÷ÓÐÐ§Öµ(A)
Uint16 _BA_EIC2;													//×îÐÂ¹ÊÕÏÊ±¿Ì µç»ú²àCÏàµçÁ÷ÓÐÐ§Öµ(A)
Uint16 _BA_EUAB1;													//×îÐÂ¹ÊÕÏÊ±¿Ì Íø²àAÏàµçÑ¹ÓÐÐ§Öµ(V)
Uint16 _BA_EUBC1;													//×îÐÂ¹ÊÕÏÊ±¿Ì Íø²àBÏàµçÑ¹ÓÐÐ§Öµ(V)
Uint16 _BA_EUAB2;													//×îÐÂ¹ÊÕÏÊ±¿Ì Íø²àÏàµçÑ¹ÓÐÐ§Öµ(V)
Uint16 _BA_EUBC2;													//×îÐÂ¹ÊÕÏÊ±¿Ì µç»ú²àAÏàµçÁ÷ÓÐÐ§Öµ(V)
Uint16 _BA_EUAB0;													//×îÐÂ¹ÊÕÏÊ±¿Ì Ö÷¶ÏÇ°ABÏßµçÑ¹ÓÐÐ§Öµ(V)
Uint16 _BA_EUBC0;													//×îÐÂ¹ÊÕÏÊ±¿Ì Ö÷¶ÏÇ°BCÏßµçÑ¹ÓÐÐ§Öµ(V)
Uint16 _BA_EFREQ;													//×îÐÂ¹ÊÕÏÊ±¿Ì µçÍøÆµÂÊ(hz)
Uint16 _BA_ESPEED;													//×îÐÂ¹ÊÕÏÊ±¿Ì µç»ú×ªËÙ(rpm)
Uint16 _BA_ENPRUD;              			//dÖáÖ÷¶ÏºóÍøÑ¹·´À¡20091026atzy
Uint16 _BA_ENPRUQ;          				//qÖáÖ÷¶ÏºóÍøÑ¹·´À¡20091026atzy
Uint16 _BA_ENPRUD2;          				//dÖáÖ÷¶ÏºóÍøÑ¹·´À¡ ÂË²¨ºó20091026atzy
Uint16 _BA_ENPRUQ2;          				//qÖáÖ÷¶ÏºóÍøÑ¹·´À¡ ÂË²¨ºó20091026atzy
Uint16 _BA_ENUDOUT;          				//Íø²àdÖáµçÑ¹Êä³ö20091026atzy
Uint16 _BA_ENUQOUT;          				//Íø²àqÖáµçÑ¹Êä³ö20091026atzy
Uint16 _BA_ETA1;													//×îÐÂ¹ÊÕÏÊ±¿Ì Íø²à±äÁ÷Æ÷AÇÅ±ÛÎÂ¶È
Uint16 _BA_ETB1;													//×îÐÂ¹ÊÕÏÊ±¿Ì Íø²à±äÁ÷Æ÷BÇÅ±ÛÎÂ¶È
Uint16 _BA_ETC1;													//×îÐÂ¹ÊÕÏÊ±¿Ì Íø²à±äÁ÷Æ÷CÇÅ±ÛÎÂ¶È
Uint16 _BA_ETA2;													//×îÐÂ¹ÊÕÏÊ±¿Ì µç»ú²à±äÁ÷Æ÷AÅ±ÛÎÂ¶È
Uint16 _BA_ETB2;													//×îÐÂ¹ÊÕÏÊ±¿Ì µç»ú²àäÁ÷Æ÷BÇÅ±ÛÎÂ¶È
Uint16 _BA_ETC2;													//×îÐÂ¹ÊÕÏÊ±¿Ì µç»ú²à±äÁ÷Æ÷CÇÅ±ÛÎÂ¶È
Uint16 _BA_EPIONU;													//×îÐÂ¹ÊÕÏÊ±¿Ì Íø²àµçÑ¹»·Êä³ö
Uint16 _BA_EPIONID;													//×îÐÂ¹ÊÕÏÊ±¿Ì Íø²àdÖáµçÁ÷»·Êä³ö
Uint16 _BA_EPIONIQ;													//×îÐÂ¹ÊÕÏÊ±¿Ì Íø²àqÖáµçÁ÷»·Êä³ö
Uint16 _BA_EMEXI;													//×îÐÂ¹ÊÕÏÊ±¿Ì »ú²àÀø´ÅÀíÂÛ¼ÆËãÖµÏÔÊ¾
Uint16 _BA_EPIOMID;													//×îÐÂ¹ÊÕÏÊ±¿Ì »ú²àdÖáµçÁ÷»·Êä³ö
Uint16 _BA_EPIOMIQ;													//×îÐÂ¹ÊÕÏÊ±¿Ì »ú²àqÖáµçÁ÷»·Êä³ö
Uint16 _BA_ETLAC;													//×îÐÂ¹ÊÕÏÊ±¿Ì Íø²àµç¸ÐÎÂ¶È
Uint16 _BA_ETLDUDT;													//×îÐÂ¹ÊÕÏÊ±¿Ì »ú²àµç¸ÐÎÂ¶È
Uint16 _BA_ETSKIIP;													//×îÐÂ¹ÊÕÏÊ±¿Ì SKIIPÎÂ¶È
Uint16 _BA_ESTAIAC;	
Uint16 _BA_ESTAIBA;	
Uint16 _BA_ETOQFB;	
Uint16 _BA_EPSTA;	
Uint16 _BA_EPNPR;	
Uint16 _BA_EPGRID;	

Uint16 _BA_TIME4_0;													//×îÐÂ¹ÊÕÏÊ±¼ä(Ãë)
Uint16 _BA_TIME4_1;													//×îÐÂ¹ÊÕÏÊ±¼ä(Ö)
Uint16 _BA_TIME4_2;													//×îÐÂ¹ÊÕÏÊ±¼ä(Ê±)
Uint16 _BA_TIME4_3;													//×îÐÂ¹ÊÕÏÊ±¼ä(ÈÕ)
Uint16 _BA_TIME4_4;													//×îÐÂ¹ÊÏÊ±¼ä(ÔÂ)
Uint16 _BA_TIME4_5;													//×îÐÂ¹ÊÕÏÊ±¼ä(Äê)

Uint16 _BA_TIME3_0;													//µÚÈý´Î¹ÊÕÏÊ±¼ä(Ãë)
Uint16 _BA_TIME3_1;													//µÚÈý´Î¹ÊÕÏÊ±¼ä(·Ö)
Uint16 _BA_TIME3_2;													//µÚÈý´Î¹ÊÕÏÊ±¼ä(Ê±)
Uint16 _BA_TIME3_3;													//µÚÈý´Î¹ÊÕÏÊ±¼ä(ÈÕ)
Uint16 _BA_TIME3_4;													//µÚÈý´Î¹ÊÕÏÊ±¼ä(ÔÂ)
Uint16 _BA_TIME3_5;													//µÚÈý´Î¹ÊÕÏÊ±¼ä(Äê)

Uint16 _BA_TIME2_0;													//µÚ¶þ´Î¹ÊÕÏÊ±¼ä(Ãë)
Uint16 _BA_TIME2_1;													//µÚ¶þ´Î¹ÊÕÏÊ±¼ä(·Ö)
Uint16 _BA_TIME2_2;													//µÚ¶þ´Î¹ÊÕÏ±¼?Ê±)
Uint16 _BA_TIME2_3;													//µÚ¶þ´Î¹ÊÕÏÊ±¼ä(ÈÕ)
Uint16 _BA_TIME2_4;													//µÚ¶þ´Î¹ÊÕÏÊ±¼ä(ÔÂ)
Uint16 _BA_TIME2_5;													//µÚ¶þ´Î¹ÊÕÏÊ±?Äê)

Uint16 _BA_TIME1_0;													//µÚÒ»´Î¹ÊÕÏÊ±¼ä(Ãë)
Uint16 _BA_TIME1_1;													//µÚÒ»´Î¹ÊÕÏÊ±¼ä(·Ö)
Uint16 _BA_TIME1_2;													//µÚÒ»´Î¹ÊÕÏÊ±¼ä(Ê±)
Uint16 _BA_TIME1_3;													//µÚÒ»´Î¹ÊÕÏÊ±¼ä(ÈÕ)
Uint16 _BA_TIME1_4;													//µÚÒ»´Î
Uint16 _BA_TIME1_5;													//µÚÒ»´Î¹ÊÕÏÊ±¼ä(Äê)

//-------------------------------------ÔËÐÐ¼à¿Ø±äÁ¿-----------------------------------------------
Uint16 _BA_MIDRF;													//dÖáµçÁ÷Ö¸Áî(A)
Uint16 _BA_NIQRF;													//qÖáµçÁ÷Ö¸Áî(A)
Uint16 _BA_MIQRF;													//qÖáµçÁ÷Ö¸Áî(A)
Uint16 _BA_TOQRF;													//×ª¾ØÖ¸Áî(NM)
Uint16 _BA_AGLRF;													//ÎÞ¹¦½Ç¶ÈÖ¸Áî(NM)
Uint16 _BA_TOQFB;													//×ª¾Ø·´À¡(NM)
Uint16 _BA_URF;														//ÖÐ¼äÖ±Á÷µçÑ¹¸ø¶¨(V)
Uint16 _BA_UDC;														//ÖÐ¼äÖ±Á÷çÑ¹(V)
Uint16 _BA_IA1;														//ÍøàAÏàµçÁ÷ÓÐÐ§Öµ(A)
Uint16 _BA_IB1;														//Íø²àBÏàÁ÷ÓÐ§Ö?A)
Uint16 _BA_IC1;														//Íø²àCÏàµçÁ÷ÓÐÐ§Öµ(A)
Uint16 _BA_IA2;														//µç»ú²àAÏàµçÁ÷ÓÐÐ§Öµ(A)
Uint16 _BA_IB2;														//µç»ú²àBÏàµçÁ÷ÓÐÐ§Öµ(A)
Uint16 _BA_IC2;														//µç»ú²àCÏàµçÁ÷ÓÐÐ§Öµ(A)
Uint16 _BA_UAB1;													//Íø²àABÏßµçÑ¹ÓÐÐ§Öµ(V)
Uint16 _BA_UBC1;													//Íø²àBCÏßµçÑ¹ÓÐÐ§Öµ(V)
Uint16 _BA_UAB2;													//µç»ú²àABÏßµçÑ¹ÓÐÐ§Öµ(V)
Uint16 _BA_UBC2;													//µç»ú²àBCÏßµçÁ÷ÓÐÐ§Öµ(V)
Uint16 _BA_UAB0;												    	//Ö÷¶ÏÇ°ABÏßµçÑ¹ÓÐÐ§Öµ(V)
Uint16 _BA_UBC0;												    	//Ö÷¶ÏÇ°BCÏßµçÁ÷ÓÐÐ§Öµ(V) 
Uint16 _BA_FREQ;													//µçÍøÆµÊ(hz)
Uint16 _BA_SPEED;													//µç»ú×ªËÙ(rpm)
Uint16 _BA_TA1;														//Íø²à±äÁ÷Æ÷AÇÅÛÎÂ¶
Uint16 _BA_TB1;														//Íø²à±äÁ÷÷BÇÅ±ÛÎÂ¶È
Uint16 _BA_TC1;														//Íø²à±äÁ÷Æ÷CÇÅ±ÛÎÂ¶È
Uint16 _BA_TA2;														//µç»ú²à±äÁ÷Æ÷AÇÅ±ÛÎÂ¶È
Uint16 _BA_TB2;														//µç»ú²à±äÁ÷Æ÷BÇÅ±ÛÎÂ¶È
Uint16 _BA_TC2;														//µç»ú²à±äÁ÷Æ÷CÇÅ±ÛÎÂ¶È
Uint16 _BA_PIONU;													//Íø²àµçÑ¹»·Êä³ö
Uint16 _BA_PIONID;													//Íø²àdÖáµçÁ÷»·Êä³ö
Uint16 _BA_PIONIQ;													//Íø²àqÖáµçÁ÷»·Êä³ö
Uint16 _BA_MEXI;													//
Uint16 _BA_PIOMID;													//»ú²àdÖáµçÁ÷»·Êä³ö
Uint16 _BA_PIOMIQ;													//»ú²àqÖáµçÁ÷»·Êä³ö
Uint16 _BA_GRDUD;													//´«¸ÐÆ÷²âÁ¿ÍøÑ¹d
Uint16 _BA_GRDUQ;													//´«¸ÐÆ÷²âÁ¿ÍøÑ¹q
Uint16 _BA_STAUD;													//¶¨×ÓµçÑ¹d
Uint16 _BA_STAUQ;													//¶¨×Óµç¹q
Uint16 _BA_STAID;													//´«¸ÐÆ÷²âÁ¿ÍøÑ¹d
Uint16 _BA_STAIQ;													//´«¸ÐÆ÷²âÁ¿ÍøÑ¹q
Uint16 _BA_EXCID;													//´«¸ÐÆ÷²âÁ¿ÍøÑ¹d
Uint16 _BA_EXCIQ;
Uint16 _BA_TLAC;
Uint16 _BA_TLDUDT;
Uint16 _BA_TNSKIIP;
Uint16 _BA_TMSKIIP;
Uint16 _BA_STAUABD;													//¶¨×ÓÍ¬²½²¢ÍøÇ°¶¨×ÓÇ°ºóµçÑ¹²î
Uint16 _BA_STAUBCD;													//¶¨×ÓÍ¬²½²¢ÍøÇ°¶¨×ÓÇ°ºóµçÑ¹²î
Uint16 _BA_STAIAC;													//¶¨×ÓÏßµçÁ÷ÓÐÐ§ÖµÏÔÊ¾
Uint16 _BA_STAIBA;													//¶¨×ÓÏßµçÁ÷ÓÐÐ§ÖµÏÔÊ¾
Uint16 _BA_PSTA;
Uint16 _BA_PNPR;
Uint16 _BA_PGRID;
Uint16 _BA_QSTA;
Uint16 _BA_QNPR;
Uint16 _BA_QGRID;
Uint16 _BA_SSTA;
Uint16 _BA_SNPR;
Uint16 _BA_SGRID;

Uint16 _SC_NPR_TLOV;
Uint16 _SC_MPR_TLOV;
Uint16 _SC_LVUDC1;
Uint16 _SC_LVUDC2;
Uint16 _SC_LVIAC2;
Uint16 _SC_TSCRON;
Uint16 _SC_MPR_UD;
Uint16 _SC_MPR_UQ;
Uint16 _SC_MSPEED1;
Uint16 _SC_MSPEED2;
Uint16 _SC_UDSTAC;
Uint16	_SCIB_BAUD;													//485²¨ÌØÂÊ
Uint16  _BA_LEDV;
Uint16  _BA_LEDB;
//-----------------------²âÊÔÓÃ±äÁ¿-----------------------------------------------------------

int32 	zys = 0;
int16 	zys1,zys2,zys3,zys4;
Uint32 	i_cnt1=0;  //ÓÃÓÚCCS²¨ÐÎÏÔÊ¾
Uint32 	i_cnt2=0;  //ÓÃÓÚCCS²¨ÐÎÏÔÊ¾
Uint32 	i_cnt3=0;  //ÓÃÓÚCCS²¨ÐÎÏÔÊ¾
float   draw1[150]={0.0},draw2[150]={0.0},draw3[150]={0.0},draw4[150]={0.0},draw5[150]={0.0};
float   draw6[150]={0.0};//,draw7[100]={0.0},draw8[100]={0.0},draw9[100]={0.0},draw10[100]={0.0};
Uint16 zsector = 0;
float testtheta;


//------------------------¹â·ü±äÁ¿-------------------------------

struct AD_DATA AD_OUT_I;  //µçÁ÷²ÉÑù
float   MPPT_Pnactive;		//¼ÆËãMPPTÊ±µÄÓÐ¹¦¹¦ÂÊ
float   Pnactive_pre;	//ÉÏÒ»´ÎµÄÍø²àÓÐ¹¦¹¦ÂÊ
float   GIVE_NPR_Id_pre;	//ÉÏÒ»´ÎµÄµçÁ÷¸ø¶¨Öµ
Uint32 	MPPT_cnt=0;		//¼ÆËãMPPTÊ±µÄ¼ÆÊý
Uint32 	cnt_Island_U=0;	//±»¶¯¹Âµº±£»¤µçÑ¹¼ÆÊýÖµ
Uint32 	cnt_Island_F=0;	//±»¶¯¹Âµº±£»¤ÆµÂÊ¼ÆÊýÖµ
float	MPPT_Time;		//¼ÆËã×î´ó¹¦ÂÊµãµÄÊ±¼ä
float	MPPT_Id;		//¼ÆËã×î´ó¹¦ÂÊµãÊ±Ã¿´ÎÔö¼ÓµÄµçÁ÷Öµ

struct	Island{
				float	DetaT;
				float	x;
				float	k; 
			}Island;

#ifdef __cplusplus
}
#endif /* extern "C" */


#endif

//===========================================================================
// No more.
//===========================================================================
