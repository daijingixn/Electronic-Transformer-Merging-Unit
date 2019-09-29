/****************************************Copyright (c)**************************************************
**                       		     
**
**
**
**--------------�ļ���Ϣ--------------------------------------------------------------------------------
**��   ��   ��: user_header.h
**��   ��   ��: 
**����޸�����: 
**��        ��: �任��ͷ�ļ�
				�����汾��Ϣ,�궨��,��������
**              
**--------------��ʷ�汾��Ϣ----------------------------------------------------------------------------
** ������: 
** ��  ��: 
** �ա���: 
** �衡��: 
**
**--------------��ǰ�汾�޶�------------------------------------------------------------------------------
** �޸���: 
** �ա���: 
** �衡��: 
**
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
#ifndef DCDC_header_H
#define DCDC_header_H

#ifdef __cplusplus
extern "C" {
#endif

//--------------------------�궨��-----------------------------------------------
				
//-----------------------������غ궨��------------------------------------------
//--------------------------�汾��Ϣ-----------------------------------------------
#define MC_TYPE 			60701			//���Ͳ���
#define MC_REV 				41222			//����汾��
#define MC_DATE 			60815			//��������
#define MC_ID				1				//��Ʒ���
#define MC_WRKEY			999				//�������޸�����
#define MC_MYKEY			1021			//������ʹ�õ�����

//------------------------����״̬����-----------------------------------------------
#define	ON					1				          //��
#define	OFF					0				          //��
#define	DEBUG_OPER			OFF			              //1=����������2009.6.24

//********************************************************************************************//
//===================�������׼ֵ��ֵ��ÿ��ʵ�������Ҫ���ģ�=====================================
#define NPR_IACN  473        //����������׼ֵ ���ЧֵΪ334A
#define GRD_UN    563        //��������ѹ��ֵ690Vϵͳ

//********************************************************************************************//
 
//----------------------------ϵͳ��������------------------------------------------------

#define NPR_L       0.5e-3     //�����˲����ֵ��H��

//-------------���ó����궨��-------------------------//
#define	SQRT3		1.73205081			//sqrt(3)
#define	SQRT3_2		0.8660254           //sqrt(3)/2
#define	SQRT3_3		0.57735027          //sqrt(3)/3
#define	SQRT2		1.41421356			//sqrt(2)
#define	PAI			3.1415926           //Բ����
#define TWOPAI      6.2831853           //2*PAI
#define PAI_2       1.5707963			//PAI/2
#define PAI_3       1.0471975			//PAI/3
#define TWOPAI_3    2.0943951			//2*PAI/3


//------------------------------��ʱʱ��-------------------------------------------------
#define	DELAY_MAIN1			5										//һ��ѭ����5ms
#define	DELAY_MAIN2			10										//����ѭ����10ms
#define	DELAY_MAIN3			20										//����ѭ����20ms
#define	DELAY_MAIN4			50										//�ļ�ѭ����50ms
#define	DELAY_MAIN5			100										//�弶ѭ����100ms
#define	DELAY_MAIN6			1000									//����ѭ����1000ms

//canopen
#define	DELAY_CANOPENTX		13										//CANOPENTX��7ms
#define	DELAY_CANOPENOVER	500										//CANOPENOVER��500ms,HEARTBEAT
#define	DELAY_SCICANOPENOVER 250									//20090817
#define	DELAY_CANFAULT       10000									//CANOPENOVER���ϵ���ж�CANͨѶ����

#define DELAY_AMUX          5      	//����AD
#define DELAY_UDCWAVE		1500	//ֱ����ѹ������ʱʱ��

#define	DELAY_POWERON		5000  	//�ϵ�ʱ��
#define	DELAY_PWMOUT		1000   	//ϵͳ��������־��λ�����巢�������־��λ��ʱ(ms)
#define	DELAY_NPRSTDBY		1000   	//NPR����---���ӹ�����������˸(ms)
#define	DELAY_NPRRUN		100	   	//NPR����---���ӹ����ƿ�����˸(ms)
#define	DELAY_MPRSTDBY		1000   	//MPR����---���ӹ�����������˸(ms)
#define	DELAY_MPRRUN		100	   	//MPR����---���ӹ����ƿ�����˸(ms) 
#define	DELAY_FREQ			200	   	//Ƶ��ʧ��������ʱ
#define	DELAY_CBFREQ		1000	//�����Ϸ����պϵ��ж���Ƶ���ϵ���ʱ��ms��

#define	DELAY_FREQ2			200	   	//Ƶ��ʧ��������ʱ
#define	DELAY_OTSER			60000  	//��ʱ������ʱ(ms)
#define	DELAY_SCISPACE		10	   	//ͨѶ���յ����͵ļ��ʱ��(ms)
#define	DELAY_SCIOVER		100	   	//ͨѶ����/���ͳ�ʱʱ(ms)
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
#define DELAY_SPEEDOUT      5    //50ms 20091022atzy ����fastshutdown
#define DELAY_UACLV1        10000     //10s   20091027atzy

#define	DELAY_EE		    20					//eeprom�ӳ�ʱ��

#define	DELAY_ISTEADY0	    1000	 //RunCtrl����ͣ��������ʱ1s
#define	DELAY_MPRSTEADY0    50     //RunCtrl����ͣ��������ʱ0.05s 
#define	DELAY_SENSZFSTDY    60000    //RunCtrl����ͣ��������ʱ60s
/*
//sysctl_start ���԰�
#define	DELAY_OPENCONTAC	2000	 //���ز��ɻָ������£�����������ָ��󵽷����϶��ӽӴ��������Ӵ�������ʱ 2s 

#define	DELAY_MKOFF	        5000	 //���յ�ϵͳͣ��ָ�����ʱ�����Ӵ������� 5s
#define	DELAY_CBOFF	        1000	 //���յ�ϵͳͣ��ָ�����ʱ�����ϼ��� 2s

#define	DELAY_CLOSE_CB	    5000	 //�������������ϴ��ܵ����Ϻ�բ����ʱ���� 5s 
#define	DELAY_PRECOK        9000	 //����������Ԥ���ʱ�� 9s   ��糣��=2.115s
#define	DELAY_STEADYFB	    2000	 //������������⵽Vdc�ȶ���1100V����������������ʱ 2s
#define	DELAY_MPRSTART 	    5000	 //����������Vdc�ȶ���MPR���������ʱ 5s
//sysctl_end  
*/ 

//sysctl_start ���հ�
#define	DELAY_OPENCONTAC	2000	 //���ز��ɻָ������£�����������ָ��󵽷����϶��ӽӴ��������Ӵ�������ʱ 2s 

#define	DELAY_ACCONTOFF	        2000	 //��ʱ�Ͻ�����Ӵ��� 2s
#define	DELAY_CBOFF	        1000	 //���յ�ϵͳͣ��ָ�����ʱ�����ϼ��� 2s

#define	DELAY_CLOSE_CB	    1000	 	//����������20100124CPC����� 0s 
#define	DELAY_PRECOK        8000	 //����������Ԥ���ʱ�� 8s   ��糣��=2.115s

//cy
#define	DELAY_VDCSTEADY	    2000	 //������������⵽Vdc�ȶ���240~450V֮����ֱ����ѹ�ȶ���־λ����ʱ 2s
#define	DELAY_ACCONTON 	    1000	 //����������ֱ����ѹ�ȶ����AC�Ӵ�����ʱ���� 1s
#define	DELAY_NPRSTART 	    1000	 //����������������ѹ�ڷ�Χ����ʱ����λ��Ҫ��NPR�������־λ 1s
//cy
//sysctl_end  


#define	DELAY_RESET	        2000  	 //ϵͳ��λ��ʱ����ֹ����� 2s
#define	DELAY_CLOSTACMD	    1000  	 //�����ӽӴ�������ֹ����� 1s
#define	DELAY_NPRCMD	    1000  	 //��λ������NPR�����壬��ֹ����� 1s
#define	DELAY_MPRCMD	    1000  	 //��λ������MPR�����壬��ֹ����� 1s

#define	DELAY_QCAPSPDIN     120    	//ת���ٶȼ������120ms   20090817
#define	DELAY_QCAPDISTURB   100    	//����10�μ��ת���ٶȲ����������� 100ms  20090817
#define	DELAY_QEPCNTOK      1000    //����1sδ����������� 1s
#define	DELAY_QEPZDISTURB   1000    //����1s����Z�ź���ǰ���������Ŵ���  1s

#define	DELAY_OCSEIN1     	250    	//20090817
#define	DELAY_OCSEIN2   	250    	//20090817
#define	DELAY_OCSSYSRUN1    250    	//20090817
#define	DELAY_OCSSYSRUN2   	250    	//20090817

#define	DELAY_DATASAVE   	2000    //���Ϸ�������ʱ2s��ֹͣ�洢20091109atzy
//LVRT
#define	DELAY_SCRIZERO	    100  	 //�����ʱ1�����ת������ 100ms/10Hz
#define	DELAY_MPWMSTOP	    0  	 	 //0ms
#define	DELAY_MPWMRESTART	200  	 //200ms
#define	DELAYMPWM			5  	 	 //5ms
#define	DELAY_SCRONDELAY	2000  	 //2s
#define	DELAY_LVSTATE		20  	 //20ms
#define	DELAY_LVRCV			20  	 //20ms

//---------------------------���ϱ����ز�ֵ-----------------------------------------------
#define	SC_IAC_HW			2			//������������ز�(��׼�����İٷ�ֵ)
#define	SC_UDC_HW			20			//��ѹ�����ز�(V)
#define	SC_UAC_HW			20			//��ѹ�����ز�(V)
#define	SC_MSPD_HW			30			//ת�ٱ����ز�(V) r/min
#define	SC_POWOROV_HW	    0	    	//���ʹ��ر����ز�(W) 0kW

#define	et_gate	    		50000	    //���ر�������

//-----------------------------CANOPENͨ�ź궨��----------------------------------------------
#define	SCICANOPENRXNUM		10										//CANOPENRX���ݰ���С
#define	SCICANOPENTXNUM		18										//CANOPENTX���ݰ���С
#define CANOPENCOM_HEAD		0x7E									//CANOPEN��ͷ
//#define CANOPENCOM_RX		0x03									//FUNCTION_RX
//#define CANOPENCOM_TX1		0x01									//FUNCTION_TX
//#define CANOPENCOM_TX2		0x02									//FUNCTION_TX 
//-----------------------------CANOPENͨ�ź궨��NORMAL----------------------------------------------
#define CAN_TEN  	  10000     //����ָ��ת�ػ�׼ֵ (��ǣ:1800r/minʱP=1560kW,Te=P*60/(n*2*pie)=8276 NM )
#define CAN_ANGLEN     90       //����ָ���޹������ǶȻ�׼ֵ 
#define CAN_SPEED     1500      //����ָ��ת�ٻ�׼ֵ 
#define CAN_TEMP      100       //����ָ���¶Ȼ�׼ֵ 

//-----------------------------485ͨź궨��----------------------------------------------
#define	SCI485NUM			10										//485���ݰ���С
#define COM_HEAD			0x7E									//SCI��ͷ

#define RESUME_KEY			0x5A5A									//�ָ�����������У����

//��ַ�ֽ�
#define COM_OPERATOR		0x80									//��λ��Ϊ������(���λΪ1)

//��λ����������
#define COM_RD				0x0001									//��ȡ������(��ȡ��λ��EEPROM�еĹ�����ֵд�뵽��λ��EEPROM��)
#define COM_WR				0x0002									//�޸Ĺ�����(�޸���λ��RAM�еĹ�����ֵ)
#define COM_SAVE			0x0004									//�޸Ĺ����벢�洢(�޸���λ��RAM�еĹ�����ֵ�����滻���EEPROM)
#define COM_RESUME			0x0008									//�ָ�������
#define COM_NEEDSTOP		0x0010									//��λ��Ӧ������ͣ��״̬���ܽ���(���ϵ��ʼ��,�����������У���д��,��ʾλ��Ӧ�����)
#define COM_SAVEALL			0x0020									//�޸Ĺ����벢�洢(�����ݸ�д��������Ҫ��λ��д�����в���,��������ֻ�����ԵĹ�����)
#define COM_VGIVE			0x0040									//�޸�dcdc��ѹ����ֵ
#define COM_IGIVE			0x0080									//�޸�dcdc��������ֵ

//��λ����������
#define COM_SUCCESS			0x80									//���λΪͨѶ���ֳɹ���־

//��λ��״̬��
#define COM_UPNORM			0x0001									//0λΪ��λ��������־
//#define COM_UPINIT		0x0002									//1λΪ��λ����ʼ��곱�־
#define COM_KEYSTOP			0x0100									//1=��λ��'STOP'����Ч(ֹͣ)
#define COM_KEYFWD			0x0200									//1=��λ��'FWD'����Ч(���)
#define COM_KEYREV			0x0400									//1=��λ��'REV'����Ч(�ŵ�)
//#define COM_KEYRESET		0x0800									//1=��λ��'RESET'����Ч(Ԥ��)

//��λ������״̬��
#define COM_SLAVENORM		0x0001									//0λΪ��λ��������־
#define COM_SLAVEINIT		0x0002									//1λΪ��λ����ʼ����ɱ�־
#define COM_SLAVERUN		0x0004									//2λΪ��λ�����б�־
#define COM_SLAVEFWD		0x0008									//3λΪ��λ�����
#define COM_SLAVEREV		0x0010									//4λΪ��λ���ŵ�
#define COM_SLAVEDEB		0x0020									//5λΪ��λ������

//CANOPEN��λ��״̬��
#define COM_EIN			    0x0001									//BIT0
#define COM_NPREIN			0x0002									//BIT1
#define COM_SYSRUN			0x0004									//BIT2
#define COM_PGMODE			0x0010									//BIT4
#define COM_QGMODE			0x0020									//BIT5
#define COM_OCSRESET		0x0080									//BIT7
#define COM_HEARTBEAT1		0x8000									//BIT15
//CANOPEN������λ���ı�����״̬��1
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
//CANOPEN������λ���ı�����״̬��2
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

//-------------------------AD��DAת�������ݶ�ȡ�Ŀ���-----------------------------------------
#define	AD8364_CONVERT		1										//8364��ʼת��
//#define	AD1544_CONVERT		2										//1544��ʼת��
//#define	DA7614_CONVERT		4										//7614��ʼת��
//ad
#define AD_ASTART		    ((Uint16 *)0x100000)						//Ƭ��AD�����ݶ�ȡ�׵�ַ
#define AD_BSTART		    ((Uint16 *)0x110000)						//Ƭ��AD�����ݶ�ȡ�׵�ַ
#define NETCS		        ((Uint16 *)0x120000)						//Ƭ��AD�����ݶ�ȡ�׵�ַ
#define AD_DA_CTRL		    ((Uint16 *)0x130000)						//Ƭ��AD,DA�Ŀ����ֽڵ�ַ
//da
#define DA_ADD0				((Uint16 *)0x1B0000)						//�����ַ0
#define DA_ADD1				((Uint16 *)0x1B0001)						//�����ַ1
#define DA_ADD2				((Uint16 *)0x1B0002)						//�����ַ2
#define DA_ADD3				((Uint16 *)0x1B0003)						//�����ַ3

//External RAM 20091109atzy
#define RAM_START		    ((Uint16 *)0x200000)						//Ƭ��RAM�׵�ַXINTF zone 7
#define RAM_END		        ((Uint16 *)0x23FFFF)						//Ƭ��RAMβ��ַXINTF zone 7
#define RAM_BIAS		    10000						//ÿ������ƫ����=4s/(0.4ms/point)=10000points/variable
Uint16  RAMDATA_POS;						    		//�洢�����Ĵ洢��λ��[0,7999]


//----------------------------���������ַ����--------------------------------------------
#define IN1_ADDR			((Uint16 *)0x140000)	//�����ַ1
#define IN2_ADDR			((Uint16 *)0x150000)	//�����ַ2
#define IN3_ADDR			((Uint16 *)0x160000)	//����ط3
#define IN4_ADDR			((Uint16 *)0x170000)	//�����ַ4

#define OUT1_ADDR			((Uint16 *)0x180000)	//�����ַ2
#define OUT2_ADDR			((Uint16 *)0x190000)	//�����ַ3
#define OUT3_ADDR			((Uint16 *)0x1A0000)	//�����ַ3
#define OUT4_ADDR			((Uint16 *)0x1C0000)	//�����ַ4,������AD�й�

//--------------------------------SPIͨѶ�궨��-------------------------------------------
#define	SPINUM				4										//SPI�ڷ���/����������

//-----------------------------------ʱ��--------------------------------------------------
#define	HSPCLK				75      		//���ٻ�׼ʱ��Ƶ��(Hz)
#define	LSPCLK				37500000		//���ٻ�׼ʱ��Ƶ��(Hz)

//--------------------------------��־λ���-----------------------------------------------
//flag[0]��ʾ���趨��
#define	SL_DISPLAY0			0x00			//LED��ʾ0
#define	SL_DISPLAY1			0x01			//LED��ʾ1
#define	SL_DISPLAY2			0x02			//LED��ʾ2
#define	SL_DISPLAY3			0x03			//LED��ʾ3
#define	SL_DISPLAY4			0x04			//LED��ʾ4
#define	SL_DISPLAY5			0x05			//LED��ʾ5
#define	SL_DISPLAY6			0x06			//LED��ʾ6
#define	SL_DISPLAY7			0x07			//LED��ʾ7
#define SL_OCS_NPRSTART     0x08            //=1����Ҫ��NPR������        
#define SL_OCS_MPRSTART     0x09            //=1����Ҫ��MPR������
#define SL_OCS_RESET        0x0A            //=1���ط������Ĺ��ϸ�λ�ź�  
#define SL_SERIESTOPING    	0x0B			//=1�������ع���ͣ������ 
#define	SL_SERIESTOP        0x0C      		//=1ϵͳ���ز��ɻָ����ϱ�־λ 
#define SL_SENSZFSTDY       0x0D            //=1��������Ư�˲����� 
#define	SL_EINSTOPING       0x0E      		//=1��������������ͣ������
#define SL_SYSSTOPING       0x0F            //=1�������������Ӵ���ͣ������

 
  

//flag[1]����ͨ����ر�;eeprom��ر�
#define SL_TX		    	0x10			//1=��ʾsci���ڷ���
#define SL_RX		    	0x11			//1=��ʾsci���������ʱ��
#define SL_RESUME    		0x12			//1=�ָ���������������
#define SL_HEADOK			0x13			//1=��֡���ݱ�ͷ��ȷ
#define SL_SETRTIMER		0x14			//1=��ҪУ��ʵʱʱ��
#define SL_EE_NOACK			0x15
#define	SL_EE_FAIL			0x16			//=1eepromд�����
#define SL_CODEOK			0x17			//=1������У�����
#define SL_EEASK_INI		0x18			//=��λ��Ҫ��eeprom�ָ���������
#define SL_EEASK_MCODE		0x19			//=1�����޸Ĺ���������
#define SL_EEASK_ERRSAVE	0x1A			//=1���ڱ��������Ϣ����
#define SL_EEBUSY_INI		0x1B			//=1�ָ���������������
#define SL_EEBUSY_MCODE		0x1C			//=1�޸Ĺ����������
#define SL_EEBUSY_ERRSAVE	0x1D			//=1���������Ϣ������ 
	
//flag[2]���ϱ�־λ//cy
#define SL_ACCONFAIL		0x20			//=1 �Ӵ����պϹ���
#define SL_UFO				0x21			//=1 U�����ű���������
#define	SL_VFO	        	0x22     		//=1 V�����ű���������  
#define	SL_WFO	    		0x22     	    //=1 W�����ű���������
#define SL_BFO				0x23			//=1 ���ű���������
#define	SL_HIAC           	0x24      		//=1 ����Ӳ����
#define	SL_HUDCOV        	0x25      		//=1 ֱ��Ӳ��ѹ 
#define	SL_SIA       		0x26      		//=1 ����A�������
#define SL_SIB        		0x27        	//=1 ����B������� 
#define SL_SIC   			0x28         	//=1 ����C�������
#define SL_SUDCOV     		0x29         	//=1 ֱ�����ѹ
#define SL_SUDCLV			0x2A         	//=1 ֱ����Ƿѹ
#define SL_UACOV       		0x2B         	//=1 ������ѹ��ѹ
#define SL_UACLV        	0x2C         	//=1 ������ѹǷѹ 
#define SL_FE1        		0x2D         	//=1 ����Ƶ�ʹ��� 
#define SL_IPMTOV        	0x2E         	//=1 IGBT���� 
#define SL_LTOV        		0x2F         	//=1 �翹������ 
//cy

//flag[3]״̬��
#define SL_POWERON			0x30			//=1ϵͳ�ϵ����
#define SL_VDCON			0x31			//=1�ϵ��־���м��ѹ�ﵽ��ֵ���Ͽ��Ապϣ�
#define SL_WARNING			0x32			//=1����
#define SL_OFFCB			0x33			//=1������
#define SL_SOFT				0x34			//=1����ֹͣ
#define SL_SHUT				0x35			//=1����ֹͣ
#define SL_NRCVR			0x36			//=1���ϲ��ָܻ�
#define SL_DRCVR			0x37			//=1������ʱ�ָ�
#define SL_IRCVR			0x38			//=1���������ָ�
#define SL_CNT				0x39			//=1������ϴ���
#define SL_OTSER			0x3A			//=1���ϳ�ʱ����
#define SL_SAVE				0x3B			//=1������Ҫ�洢
#define SL_STEADYGV			0x3C			//=1Vdc�����ȶ�
#define SL_VDCSTEADY		0x3D			//=1Vdc��ѹ�ȶ�
#define SL_DEADCOMP1		0x3E			//=1������������ʹ��
#define SL_DEADCOMP2		0x3F			//=1�������������ʹ�� 

//flag[4]���ϱ�1
#define SL_ERROR			0x40			//=1ϵͳ����
#define SL_ERRSTOP			0x41			//=1ϵͳ���ع��ϵ���ͣ��
#define	SL_PDPINTA			0x42			//=1������������A
#define	SL_PDPINTB			0x43			//=1������������B
#define	SL_UDCWAVE			0x44			//=1�м��ѹ���ȶ�������580V��620V
#define	SL_SUDCOVH			0x45			//=1�м��ѹ��ѹ���ϱ�־λ(��ѹ����)
#define SL_HIA1			    0x46			//=1���������A��Ӳ������
#define SL_HIB1			    0x47			//=1���������B��Ӳ������
#define SL_HIC1			    0x48			//=1���������C��Ӳ������
#define SL_HIA2		 	   	0x49			//=1����������A��Ӳ������
#define SL_HIB2		   	 	0x4A			//=1����������B��Ӳ������
#define SL_HIC2		   	 	0x4B			//=1����������C��Ӳ������
#define SL_SIAC1		    0x4C			//=1����������������
#define SL_SIAC2		    0x4D			//=1�����������������

//flag[5]���ϱ�2//cy 
#define SL_TTOV				0x50			//=1��ѹ������
#define SL_PGOV				0x51			//=1�й����ʹ���
#define SL_QGOV				0x52			//=1�޹����ʹ���
#define SL_IslandPro_U		0x53			//=1��ѹ�µ�����
#define SL_IslandPro_F		0x54			//=1Ƶ�ʹµ�����
//cy
#define	SL_GRDFQE			0x55			//=1����Ƶ�ʼ������
#define	SL_PDPASERIES		0x56			//=1�������ع���
#define SL_PDPBSERIES		0x57			//=1��������ع���
#define SL_HIACOV1			0x59			//=1���ཻ��Ӳ��������������
#define SL_HIACOV2			0x5A			//=1����ཻ��Ӳ��������������
#define SL_CBTRIP 			0x5B			//=1�����ѿۻ������ضϿ����Ϲ���
#define	SL_EXFAIL		    0x5C			//=1�������ⲿӲ������
#define	SL_ESTOP			0x5D			//=1�ⲿ����ͣ������
#define SL_PHORDE		    0x5F            //=1��������

//flag[6]���з�ʽ
//#define SL_NPR_SINGLE		0x60			//=1�����������ģʽ
//#define SL_MPR_SINGLE		0x61			//=1������������ģʽ
//#define SL_BACK2BACK		0x62			//=1����������
//#define SL_NPR_REACTIVE		0x63			//=1�����޹���������ģʽ
//#define SL_NPR_PWMSTOP      0x64            //=1����ֹͣ����
//#define SL_MPR_PWMSTOP      0x65            //=1����ֹͣ����
#define	SL_NPR_START		0x66			//�������������ָ�� 1=����
#define	SL_MPR_START		0x67			//�������������ָ�� 1=����
#define	SL_NPR_RUN			0x68			//=1�����������������
#define	SL_MPR_RUN			0x69			//=1���������������� 
#define	SL_NPR_RUNING		0x6A			//=1������������ڹ��
#define	SL_MPR_RUNING		0x6B			//=1������������ڹ���
#define	SL_TAOVONCE			0x6C			//=1�����ű۳��¹����ź��ܸ���
#define	SL_TBOVONCE			0x6D			//=1������ű۳��¹����ź��ܸ���
#define SL_FAN_WORK         0x6E			//=1Ҫ���ʷ��ȿ�ʼ����
#define	SL_FANSELECT		0x6F			//=0���ʷ���ǽ� 1���ʷ���ǽ�
								
//flag[7]�����1,IO���   0x180000          //�̵��������=1 ���DC24V
#define _OUT1_DATA			flag[7]	
#define CL_OUT_CONVRUN          0x70         	//=1����������P5.5
#define CL_OUT_CONVFAIL			0x71			//=1����������P5.6
#define CL_OUT_ACCONTON			0x72			//=1�Ͻ����Ӵ���P5.7
#define	CL_OUT_DCCONTON    		0x73			//=1��ֱ���Ӵ���P5.8
#define CL_OUT_FANWORK		    0x74			//=1�������P5.9

//flag[8]�����2         0x190000           //�̵��������=1 ���AC220V
#define _OUT2_DATA			flag[8]
#define CL_RELAY8      		0x80			//����
#define CL_RELAY9          	0x81			//����

//flag[15]�����4         0x1A0000          //����AD��ַ���
#define _OUT3_DATA			flag[15]									
#define SL_PHASEA			0xF0		     //						
#define SL_PHASEB			0xF1             //
 

//flag[11]�����4         0x1C0000          //����AD��ַ���
#define _OUT4_DATA			flag[11]									
#define SL_LSADA0			0xB0		     //A0						
#define SL_LSADA1			0xB1             //A1
#define SL_LSADA2			0xB2             //A2
#define SL_LSADA3			0xB3	         //A3							
							

						

//flag[9]�����12
#define _IN12_DATA			flag[9]			//���������״̬����
//---------------------0x140000----------------------------------------------------------------------------	
#define SL_IN1_EMESTOP 			0x90			//=1 �ⲿ��ͣ���Ϭ�	P4.1
#define SL_IN1_SYSSTAR			0x91			//=1 ϵͳ����		P4.2
#define SL_IN1_CONVRUN			0x92			//=1 ������������У�P4.3  
#define SL_IN1_ACCONTA 			0x93			//=1 �����Ӵ������ں�բ״̬	P4.4
#define SL_IN1_DCCONTA	    	0x94			//=1 ֱ���Ӵ������ں�բ״̬��P4.5
#define SL_IN1_SPARE	  	 	0x95			//=1 ����	P4.6��		
//---------------------0x150000---------------------------------------------------------------------------	
#define SL_IN2_UFO			0x98	//=1 U�����ű���������
#define SL_IN2_VFO			0x99	//=1 V�����ű���������
#define SL_IN2_WFO			0x9A	//=1 W�����ű۱���					
#define SL_IN2_BFO			    0x9B	//=1 ���ű��������� 
#define SL_IN2_HIAC			0x9C	//=1 ����Ӳ����
#define SL_IN2_HUDCOV			0x9D	//=1 ֱ��Ӳ��ѹ


//flag[10]�����34      0x160000
#define _IN34_DATA			flag[10]			//���ư�Ӳ���������Ϸ���
//-----------------------------------------------------------------------------------------------				
#define SL_IN3_VDCOV			0xA0			//=1 ֱ����ѹ��ѹ
#define SL_IN3_NPRIOV			0xA1			//=1 ���ཻ��Ӳ��������������
#define SL_IN3_MPRIOV			0xA2			//=1 ����ཻ��Ӳ��������������

#define SL_IN3_CBTRIP		    0xA3			//=1 ���Ϲ����ѿ۹���  P4.9   20090816
//#define SL_IN3_OCS_NPRSTART		0xA4			//=1 ��λ��������������  �������źţ��糡û��
//#define SL_IN3_OCS_MPRSTART		0xA5			//=1 ��λ��������������  �������źţ��糡û��


//flag[12]����ͨѶ��־λ
#define SL_OCS_EIN          0xC0            //=1���ط�������ϵͳ�����ź�  bit0 ������·��
#define SL_OCS_SYSRUN    	0xC1			//=1���ط������ı����������ź�  bit2 ��ʼԤ���ֱ�����ӽӴ����պ�
#define SL_CBCLOSED    	    0xC2			//=1�������أ������Ѿ��պ�
#define SL_MPR_SYNOK        0xC3            //=1����ͬ��������ɱ�־λ				
#define SL_OCS_NPREIN       0xC4            //=1����Ҫ����������൥���޹���������				
#define SL_PGOV_COM         0xC5            //=1�й����ʳ������ƣ�֪ͨ���� ����10s��������ᱨ����			
#define SL_QGOV_COM         0xC6            //=1�޹����ʳ������ƣ�֪ͨ���� ����10s��������ᱨ��				
//canopen
#define SL_COMOVER		0xC8			//=1 ͨѶ����
#define SL_CANOPENHEADOK	0xC9			//=1 SL_CANOPENHEADOK
#define SL_CANOPENTX		0xCA			//=1 SL_CANOPENOVER 
#define SL_TEST		        0xCB			//=1 SL_CANOPENOVER 


//flag[13]
#define SL_GRIDLOSE70		0xD0			//Ϊ�����ѹ����20091027atzy
#define	SL_GRIDLOSE50       0xD1      		//Ϊ�����ѹ����20091027atzy
#define	SL_GRIDLOSE30       0xD2      		//Ϊ�����ѹ����20091027atzy
#define	SL_GRIDLOSE15       0xD3      		//Ϊ�����ѹ����20091027atzy
#define	SL_ERRDATASAVE      0xD4      		//�����ⲿRAM����ת��20091109atzy
//LVRT��־λ
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
#define SL_DRAW			    0xE5			//=1��ͼ
#define SL_CHARGEOK			0xE6			//=1Ԥ������
#define SL_SPEED_IN_RANGE	0xE7			//=1ת���ڷ�Χ����
#define SL_CONFIGPWM		0xE8			//=1 PWM����������ɱ�־λ,���ұ�֤ConfigPwm()ֻ������һ��
#define SL_RUN				0xE9			//=1ϵͳ����
#define SL_STACTRIPEN		0xEA			//=1�����ӵ�����С�����ӽӴ����Ͽ�����
#define	SL_TAOV				0xEB			//���೬��
#define SL_TBOV			    0xEC			//���೬��
#define SL_SKTOV            0xED            //����ж�SKIIP����
#define SL_NPR_PWMOUT       0xEE            //���������Ѿ�ʹ�ܱ�־λ,���ұ�֤Enepwmio_NPR()ֻ������һ��
#define SL_MPR_PWMOUT       0xEF            //���������Ѿ�ʹ�ܱ�־λ,���ұ�֤Enepwmio_MPR()ֻ������һ��




//------------------------------------const����--------------------------------------------

//eepromλ����
const  Uint16 ONEBYTE[8]={0x0080,0x0040,0x0020,0x0010,0x0008,0x0004,0x0002,0x0001};

//AD1544ͨ��ѡ��
const  Uint16 AD1544[4]={0x0000,0x2000,0x4000,0x6000};		
//--------------------------------------��������-------------------------------------------
Uint16	flag[15];													//��־λ����
Uint16	disp[15];													//��־����

float   RUN_mpridrf_exi;
Uint16  RUN_mpriq;
Uint16  _OUT3_TEST;
Uint16  _NQEPPCO;

int32   ET_SUM1;
int32   ET_SUM2;

/*���������SVPWM����*/
Uint16 SW_NPR,SW_MPR; 
float   vdc;	 
float   m=0.0;
float   ua_m=0,ub_m=0,uc_m=0;  //���Ʋ�
float   u_alfa_NPR=0,u_beta_NPR=0;
float   u_alfa_MPR=0,u_beta_MPR=0;


//����ֵ�Ĵ���
struct	GIVE{
	float   npridrf;					   //�����м�ֱ����ѹ����ֵ
	float   npriqrf;                   //�����޹���������ֵ(�������޹�����ʱʹ��)
	float   toqrf;                      //����ת�ظ���ֵ(�й�)
	float   anglerf;                    //���๦�������Ƕȸ���ֵ(�޹�) �Ƕ�
}GIVE;
float OCS_Trf;                          //���ظ�������ת��ָ��

//����������ؼĴ���
struct	RUN{									
	float   npridrf;						//��ѹ��������ֵ
	float   npridstep;						//��ѹ�������ֲ���
	float   mpridrf;						//�й�������������ֵ
	float   mpridstep;						//�й������������ֲ���
	float   npriqrf;						//�޹�������������?
 	float   npriqstep;						//�޹������������ֲ���
	float   mpriqrf;						//�޹�������������?
 	float   mpriqstep;						//�޹������������ֲ��
	float   toqrf;						//ת�ظ�������ֵ
	float   toqstep;					//ת�ظ������ֲ���
	float   aglrf;						//���������Ǹ�����
	float   aglstep;					//���������Ǹ������ֲ���

	float   staidrf;					//���ж���d�����ָ��
	float   staiqrf;					//���ж���q�����ָ��
	float   staidstep;					//���ж���d���������
	float   staiqstep;					//���ж���q���������  

	float   mpridrf_g;						
	float   mpriqrf_g;					
    
    float   radianrf;
	float   mpridrf_exi;
	float   mpridrf_var;
}RUN; 
//����任��ؼĴ���
struct	TRANS_DATA{
    float a;           	//a��
	float b;           	//b��
	float c;           	//c��
	float alfa;	       	//alfa��
	float beta;	       	//beta��
	float d;		   	//d��
	float q;           	//q�� 
	float sintheta;    	//����ֵ
	float costheta;	   	//����ֵ
	float dflt;	   		//�˲���dֵ
	float qflt;	   		//�˲���qֵ
	float amp;			//��ֵ
	float ampflt;		//�˲����ֵ
	float dflt2;	   	//С�˲���dֵ20091027atzyΪ�˼���������
};																 
struct	TRANS_DATA TRS_NPR_I;   //����������ĵ������������NPR��Ϊ��׺������grd�������ֵ��������������������������
struct	TRANS_DATA TRS_MPR_I;   //����������ĵ���
struct	TRANS_DATA TRS_MPR_U;   //�����������������
struct	TRANS_DATA TRS_NPR_U;   //���������������
struct	TRANS_DATA TRS_NGS_U;   //���������ѹ
struct	TRANS_DATA TRS_STA_I;   //���ӵ���
struct	TRANS_DATA TRS_STA_U;   //���ӵ�ѹ
struct	TRANS_DATA TRS_GSTA_U;  //Ŀ�궨�ӵ�ѹ
struct	TRANS_DATA TRS_PSTA_U;  //���ڱ�����λ�ü��Ķ��ӵ�ѹ
struct	TRANS_DATA TRS_PMPR_I;  //���ڱ�����λ�ü���ת�ӵ���   
struct	TRANS_DATA DIP_NPR_U;  //���ڹ��ʼ���  
struct	TRANS_DATA DIP_NPR_I;  //���ڹ��ʼ��� 
struct	TRANS_DATA DIP_STA_U;  //���ڹ��ʼ��� 
struct	TRANS_DATA DIP_STA_I;  //���ڹ��ʼ��� 
struct	TRANS_DATA DIP_MPR_I;  //���ڹ��ʼ���  


//PI����ؼĴ���
struct PI_DATA
{
	float reference;							//����ֵ
	float feedback;								//����ֵ
	float errorp;								//ǰ�����
	float error;								//���
	float integrator;							//ǰ�λ�ֽ��
	float out;
};  
struct PI_DATA PI_NPR_Id;				//���������d������ջ�
struct PI_DATA PI_NPR_Iq;				//���������q������ջ�
struct PI_DATA PI_MPR_Id;				//��������d������ջ�
struct PI_DATA PI_MPR_Iq;				//���������q������ջ�
struct PI_DATA PI_NPR_U;				//�����������ѹ��
struct PI_DATA PI_MPR_U;				//ջ�
struct PI_DATA PI_STA_Id;				//���ſ���d
struct PI_DATA PI_STA_Iq;				//���ſ���q 

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


//�ѭ����ʱ������ʱ������
struct	MAIN_LOOP{
	int32 cnt1;					//��ѭ����ʱ�����5ms
	int32 cnt2;					//��ѭ����ʱ�Ĵ���10ms
	int32 cnt3;					//��ѭ����ʱ�Ĵ���20ms
	int32 cnt4;					//��ѭ����ʱ�Ĵ���50ms
	int32 cnt5;					//��ѭ����ʱ�Ĵ���100ms
	int32 cnt6;					//��ѭ����ʱ�Ĵ���1000ms

	int32 pulse;				//��ѭ����ʱ����Ĵ���
	
	int32 cnt_poweron;			//preparation time delay
	int32 cnt_pwmout;			//PWM�����ʱ
	int32 cnt_nprlamp;			//�������巢��ָʾ����˸��ʱ����
	int32 cnt_mprlamp;			//�������巢��ָʾ����˸��ʱ���� 

	int32 cnt_freq;			   //Ƶ��ƫ�ƼƱ
	int32 cnt_freq2;
	int32 cnt_cbfreq;
	int32 cnt_estop;
	int32 cnt_rcvr;				//������ʱ�ָ���ʱ
	int32 cnt_otser;			//���������?

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
    int32 cnt_opencontac;      //���ز��ɻָ������£�����������ָ��󵽷����϶��ӽӴ��������Ӵ�������ʱ

	int32 cnt_accontoff;       //��ʱ�Ͻ����Ӵ���
	int32 cnt_cboff;           //��յ�ϵͳͣ��ָ�����ʱ�����ϼ���

	int32 cnt_closecb;         //��������/ֹͣ�����ϴ��ܵ����Ϻ�բ����ʱ����
	int32 cnt_precok;          //��������/ֹͣ����⵽Vdc�ﵽ950V�����������Ӵ���ָ�����ʱ����
	int32 cnt_scrondelay;       
//cy
	int32 cnt_vdcsteady;        //��⵽Vdc�ȶ���240~450V֮����ֱ����ѹ�ȶ���־λ����ʱ����
	int32 cnt_vdcunsteady;      //��⵽Vdc����240~450V֮����ֱ����ѹ�ȶ���־λ����ʱ����
	int32 cnt_acconton;			//ֱ����ѹ�ȶ����AC�Ӵ�����ʱ����
	int32 cnt_nprstart;			//������ѹ�ڷ�Χ����ʱ����λ��Ҫ��NPR�������־λ
	int32 cnt_nprstop;			//������ѹ���ڷ�Χ����ʱ����λ��Ҫ��NPR�������־λ
//cy

//sysctl_zl_end 
    int32 cnt_AMUX;            //����AD
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

//����AD����Ĵ���
Uint16 _OUT_AMUX1=0;  //��������ADѡͨ�źţ�ÿ��Ҫѡͨ��һ��ADͨ����_OUT_AMUX��1��Ȼ���͵�CPLDȥ����ѡͨ16ѡ1оƬ
Uint16 _OUT_AMUX2;    //��������ADѡͨ�źţ�ÿ��Ҫѡͨ��һ��ADͨ����_OUT_AMUX��1��Ȼ���͵�CPLDȥ����ѡͨ16ѡ1оƬ
struct  AMUX{
    float NPR_tempa;  		//NPR��A��뵼���¶ȣ�Skiip��������
    float NPR_tempb;  		//NPR��B��뵼���¶ȣ�Skiip��������
    float NPR_tempc;  		//NPR��C��뵼���¶ȣ�Skiip��������
    float MPR_tempa;  		//MPR��A��뵼���¶ȣ�Skiip��������
    float MPR_tempb;  		//MPR��B��뵼���¶ȣ�Skiip��������
    float MPR_tempc;  		//MPR��C��뵼���¶ȣ�Skiip��������
    float Lac_temp;   		//���������¶�
	float Ldudt_temp; 		//du/dt���¶�
	float skiiptempmax;    	//SKIIPģ����¶����ֵ
	float NPR_skiiptemp;    //����SKIIPģ����¶����ֵ
	float MPR_skiiptemp;    //����SKIIPģ����¶����ֵ
}AMUX;

//ADģ�鴦��Ĵ���
struct	AD{
	int16  dat[24];													//AD��ǰת��������
	Uint32 cputime;
	Uint32 cputime_last;
}AD;
//cy
//ADת������Ĵ���
struct	ADFINAL{
	int16  ia1;				//���������Ia
	int16  ib1;				//���������Ib
	int16  idc;				//ֱ�������Idc
	int16  uab;				//�������ѹUab
	int16  ubc;				//�������ѹUbc
    int16  udc;             //ֱ�����ѹUdc
    int16  AMUX;            //����AD�ź�
	int16  ia2;				//����380V�����
}ADFINAL;
//cy   

//��ѹʸ��
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
struct AD_DATA AD_OUT_U;  //�������ѹ
struct AD_DATA AD_OUT_STA_U;  //������Ӳ��ѹ ���˲�ͨ��
struct AD_DATA AD_OUT_NGS_U;  //������ѹ�����Ϻ�
struct AD_DATA AD_OUT_NPR_I;  //�������������
struct AD_DATA AD_OUT_MPR_I;  //�������������
struct AD_DATA AD_OUT_STA_I;  //���Ӳ����  
struct AD_DATA AD_OUT_NGF_U;  //������ѹ�����Ϻ󣩴��˲�ͨ��
struct AD_DATA AD_OUT_STAD_U;  //��ֵ
struct AD_DATA AD_OUT_SCR_I;  //ACTIVECROWBAR����  
 

float  AD_OUT_UDC; //AD����������ֱ����ѹ��V��
float  AD_OUT_UDC_PRO; //AD����������ֱ����ѹ��V�� LVRT������Vdc����С�˲�

//��ƽ��ֵ
struct MEAN_DATA{
       float ia,ib,ic;  	//���������ƽ��ֵ�˲�
	   float idc;  			//ֱ�������ƽ��ֵ�˲�
	   float uab,ubc;	   	//�������ߵ�ѹƽ��ֵ�˲�
	   float ua,ub,uc;	   	//���������ѹƽ��ֵ�˲�
       float ia2;  			//380V�����ƽ��ֵ�˲�
	   float udc;			//ֱ�����ѹƽ��ֵ�˲�

	   float zfia1,zfib1,zfic1; 	//���������������Ư�˲�
	   float zfuab,zfubc; 			//�����ѹ��������Ư�˲�
	   float zfidc;					//ֱ���������������Ư�˲�
	   float zfia2;					//380V�������������Ư�˲�

}MEAN_DATA;  

//����ģ��������
struct	PRO{									
				float	Uab;	//������ ab�ߵ�ѹʵ��ֵ(V)
				float	Ubc;	//������ bc�ߵ�ѹʵ��ֵ(V)
				float   Ua;	  	//������a���ѹV RMS
				float   Ub;	  	//������b���ѹV RMS
				float   Uc;	  	//������c���ѹV RMS
				float   Ia;   	//������A�ಢ��������Чֵ,��λA
				float   Ib;	  	//������B�ಢ��������Чֵ,��λA
				float   Ic;	  	//������C�ಢ��������Чֵ,��λA
   				float   IPM_tempa; //IPMģ��A���¶�
				float   IPM_tempb; //IPMģ��B���¶�
				float   IPMtempmax;//IPMģ����¶����ֵ
   				float   L_temp; //����¶�
				float   T_temp; //��ѹ���¶� 


	         	float	NPR_iac;								//����������ֵ,��׼�����İٷ�ֵ
				float	MPR_iac;								//���ӵ�����ֵ,��׼�����İٷ�ֵ
				float	udc;									//�м�ֱ����ѹ��ʵ��ֵ(V)
				float	NPR_uab;								//���� ab�ߵ�ѹʵ��ֵ(V)
				float	NPR_ubc;								//���� bc�ߵ�ѹʵ��ֵ(V)
				float	STA_uab;								//���Ӳ� ab�ߵ�ѹʵ��ֵ(V)
				float	STA_ubc;								//���Ӳ� bc�ߵ�ѹʵ��ֵ(V)
				float	GID_uab;								//������ ab�ߵ�ѹʵ��ֵ(V) 20091026atzy
				float	GID_ubc;								//������ bc�ߵ�ѹʵ��ֵ(V) 20091026atzy
				float	rcvr;									//�ӳٻָ�ʱ��
				float   STA_iac;                            	//���ӽ�������iac
				float   STA_iba;                            	//���ӽ�������iba
				float   speed;                               	//���ת�� r/min
				float   speedflt;                               //20090815
				float   sta_iar;	  							//���Ӳ�a�����A RMS
				float   sta_ibr;	  							//���Ӳ�b�����A RMS
				float   sta_icr;	  							//���Ӳ�c�����A RMS
				float   sta_uar;	  							//���Ӳ�a���ѹV RMS
				float   sta_ubr;	  							//���Ӳ�b���ѹV RMS
				float   sta_ucr;	 							//���Ӳ�c���ѹV RMS
				float   npr_uar;	  							//����a���ѹV RMS
				float   npr_ubr;	  							//����b���ѹV RMS
				float   npr_ucr;	  							//����c���ѹV RMS
				float   npr_iar;   								//����,A�ಢ�������Чֵ,��λA
				float   npr_ibr;	  							//����,B�ಢ�������Чֵ,��λA
				float   npr_icr;	  							//����,C�ಢ��������Чֵ,��λA
				float   Psactive; 								//���Ӳ��й�����
				float   Psreactive; 							//��Ӳ��޹�����
				float   Ps;          							//���Ӳ����ڹ���
				float   Pnactive;    							//�����й�����
				float   Pnreactive;  							//�����޹�����
				float   Pn;          							//�������ڹ��
				float   Pgactive;    							//�����ܵ��й�����	
				float   Pgreactive;  							//�������޹�����				
				float   Pg;       								//����ܵ����ڹ���
		   }PRO; 
 
//��ʾ�ر���
struct	DISP{										
    			float  Iai;   	//���������˲ʱֵ,��λA
				float  Ibi;	  	//���������˲ʱֵ,��λA
				float  Ici;	  	//���������˲ʱֵ,��λA
				float  Ia;		//�����������Чֵ,��λA
				float  Ib;	  	//�����������Чֵ,��λA
				float  Ic;	  	//�����������Чֵ,��λA
    			float  Uab;	  //����ab���ѹV RMS
				float  Ubc;	  //����bc���ѹV RMS

				float  L_temp;  //����¶� ���϶�
				float  T_temp;  //��ѹ���¶� ���϶�
				float  IPM_tempa;  //IPMģ��A���¶�
				float  IPM_tempb;  //IPMģ��B���¶�
				float  udc;			//�м�ֱ����ѹ
				float  npridrf;		//d�����ָ��		
				float  npriqrf;		//q�����ָ��
				float  freq;
				float  pionu;   	//�����ѹ�����
				float  pionid;		//�������d�����
				float  pioniq;		//�������q�����
				float  Pnactive;    //�������й�����
				float  Pnreactive;  //�������޹�����
				float  Pn;          //���������ڹ���
			}DISP;
 
//��ģ�����
struct CAP_DATA	{
					float		prd;				//Cap4�¼�����
					Uint32		adsmptsctr; 		//AD����ʱ�̵�Cap4������ֵ(����AD��CAP4֮������)
					float 		phase;	    		//�¼���ǰ��λ//����������
					float 		freqtmp;			//����¼�Ƶ��
					float 		freq;	    		//ȷ�Ϻ��Ƶ��
					float	    omigasyn;			//ͬ����Ƶ�ʣ���Ƶ��
					float 		omigaslp;	    	//ת���Ƶ��
					float	    radpertb;			//�������Ƶ�λʱ��ʸ��λ������ rad per timebase
					float	    nprtrstheta;		//�����㷨���任�Ƕ�
					float	    npratitheta;		//�����㷨���任�Ƕ�
					float	    mprtrstheta;		//����㷨���任�Ƕ�
					float	    mpratitheta;		//�����㷨���任�Ƕ�
					float	    stavectheta;	    //���Ӵ��������A������λ��	
				};
struct CAP_DATA CAP3,CAP4;

struct QEPDATA{
//----------------------ת��λ�ü�����-----------------------------------------------------------
					Uint16		qcapprd;		//QCAP��Ԫ���ڼĴ���ֵ�����ڲ��ܷ���ת��
					float 		omigamec;		//��е���ٶ�
					float 		omigarote;	    //������ٶ� rotor electric
					float 		omigaroteflt;	//
					float 		rotpos;			//ת�ӵ�ǰλ��rad���绡�ȣ�
					Uint32   	adsmposcnt;		//����ʱ�̱���������  
					Uint32 		posilat;        //��¼Z�ź�������ʱCNT����ֵ
					Uint32 		qposlat;        //��¼Unit time��QEPCNT�ļ���ֵ�����ڲ�Ƶ����ת��
					Uint32 		qposlat1;        //��¼Unit time��QEPCNT�ļ���ֵ�����ڲ�Ƶ����ת��
					Uint32 		qposlat2;        //��¼Unit time��QEPCNT�ļ���ֵ�����ڲ�Ƶ����ת��
					float 		rotposdisp;		//DA��ʾ
					float 		rotradpret0;	//����QEP Z�źſ�����
//----------------------������λ�ü�����--------------------------------------------------------	
					float 		encodpos;		//������λ��rad���绡�ȣ�
					float 		u_stapos;		//2S�ο�ϵ�¶��ӵ�ѹʸ����λ��rad���绡�ȣ�
					float 		i_rotpos;		//2S�ο�ϵ��ת�ӵ���ʸ����λ��rad���绡�ȣ�
			  }QEPDATA; 

//SCIģ�����
struct	SCI{
					Uint16 txb[SCI485NUM];			//SCIB��������
					Uint16 rxb[SCI485NUM];			//SCIB��������	
					int32 cnt_sciover;				//SCI����/���ճ�ʱ��ʱ��
					int32 cnt_scispace;				//SCI���յ����͵ļ����ʱ��
		   }SCI;

//SCICANOPENģ�����
struct	SCI_CANOPEN{
					Uint16 txb[SCICANOPENTXNUM];			//SCIB��������
					Uint16 rxb[SCICANOPENRXNUM];			//SCIB��������
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

//SPIģ�����
struct	SPI{
					Uint16 da7614_txb[SPINUM];		//SPI,DA��������
					Uint16 da7614point;				//
		   }SPI;

//EEPROMģ�����
struct	EEPROM{
				Uint16 data[11];					//������д�������
				Uint16 point;						//EEPROM��ǰ���������
				Uint16 mcode;						//��Ҫ�޸ĵĹ���������
			  }EEPROM;

//RTIMERģ�����
struct	RTIMER{
				Uint16 time[6];				//��ǰʱ��[5~0]-->�� �� �� ʱ �� �루��Ϊ8λ���ݣ�
			  }RTIMER;

//-----------------------------�ڲ�����----------------------------------------------------------
Uint16  _NULL_VAL=0;
Uint16  _MSG_SCOUT1;												//SCOUT��Ϣ����(ǰ��)
Uint16  _MSG_SCOUT2;												//SCOUT��Ϣ����(����)
Uint16  _SY_RTRN;
Uint32   POSCNT_TEST;
float   DM_imrd;   						//ת�����ŵ���
float   DM_imrq;   						//ת�����ŵ���
float   DM_Lr;							//��ǰ���Դ���
float   Te_feedback;                    //ʵ��ת��ֵ����
float   Pnactive;    					//�����й�����
float   Pnreactive;    					//�����޹�����
//----------------------------��������------------------------------------------------------------
Uint16 _MC_TYPE;						//���Ͳ���
Uint16 _MC_REV;							//����汾
Uint16 _MC_DATE;						//��������
Uint16 _MC_ID;							//��Ʒ���
Uint16 _SCIB_ADDR;						//485�ڵ��ַ

Uint16 _SW_FR;							//����Ƶ��(kHz)
Uint16 _DEADTIME;						//�������С��ͨʱ��(us)
Uint16 _COMPTIME;						//�������С��ͨʱ��(ms)
Uint16 _MINONTIME;						//�������С��ͨʱ��(us)

Uint16 _RU_UDCT;						//��ѹָ�����ʱ��(ms)
Uint16 _RU_IDT;							//����ָ�����ʱ��(ms)
Uint16 _RU_IQT;							//����ָ�����ʱ��(ms)
Uint16 _RU_TOQT;						//ת��ָ�����ʱ�(ms)
Uint16 _RU_AGLT;                        //����������ָ�����ʱ��(ms)
Uint16 _NIDRF;							//ֱ����ѹ����ֵ
Uint16 _MIDRF;							//d���������ֵ
Uint16 _NIQRF;							//q���������ֵ
Uint16 _MIQRF;							//q���������ֵ
Uint16 _TOQRF;							//ת��ָ��
Uint16 _AGLRF;							//���๦��������
Uint16 _EIDCO;							//�ֶ� �������ŵ�������ϵ��
Uint16 _ENCODPOS;						//�ֶ� ��������ʼλ�ýǶ�
Uint16 _EIN;							//
Uint16 _SYSRUN;							//
Uint16 _RESET;							//
Uint16 _STDBY1;							//����1
Uint16 _STDBY2;							//����2
Uint16 _STDBY3;							//����3
Uint16 _STDBY4;							//����4
Uint16 _STDBY5;							//����5
Uint16 _STDBY6;							//����6
Uint16 _STDBY7;							//����7
Uint16 _STDBY8;							//����8
float _eidco;
float _encodpos;

float _stdby01;							//���þ���С���㴦���ֵ
float _stdby02;							//���þ���С���㴦���ֵ
float _stdby03;							//���þ���С���㴦���ֵ
float _stdby04;							//���þ���С���㴦���ֵ
float _stdby05;							//���þ���С���㴦���ֵ
float _stdby06;							//���þ���С���㴦���ֵ
float _stdby07;							//���þ���С���㴦���ֵ
float _stdby08;							//���þ��С���㴦���
Uint16 _SCOUTL;							//��16�������뵽SCOUT1
Uint16 _SCOUTH;							//��16�������뵽SCOUT2 
//------------------------����ģʽ����-------------------------------------------------------------
Uint16 _ENSCR;							//
Uint16 _COMP2;							//�����������������ʹ��
Uint16 _AUTOCSTAC;							
Uint16 _OPERATION;						//����ģʽ
Uint16 _CANOPER;						//ϵͳCANʹ��ģʽ

//-----------------------PI���������--------------------------------------------------------------
Uint16	_NPR_U_Kp;		  		//�����������ѹ�ջ�����ϵ��
Uint16	_NPR_U_Ki;		   		//�����������ѹ�ջ�����ϵ��
Uint16	_NPR_U_Kd;		   		//�����������ѹ�ջ�΢��ϵ��
Uint16	_NPR_U_outmax;			//����������ѹ�ջ�����޷�
Uint16	_NPR_U_errmax;		 	//�����������ѹ�ջ�����޷�
Uint16	_NPR_U_errmin;		   	//�����������ѹ�ջ������ֵ
Uint16	_NPR_U_incrementmax;	//�����������ѹ�ջ������޷�

Uint16	_NPR_ID_Kp;				//��������������շ����ϵ��
Uint16	_NPR_ID_Ki;	   			//������������ջ�����ϵ��
Uint16	_NPR_ID_Kd;	   			//��������������ջ�΢��ϵ��
Uint16	_NPR_ID_outmax;			//��������������ջ�����޷�
Uint16	_NPR_ID_errmax;	 		//��������������ջ�����޷�
Uint16	_NPR_ID_errmin;	  		//��������������ջ�����Сֵ
Uint16	_NPR_ID_incrementmax; 	//��������������ջ�����޷�

Uint16	_NPR_IQ_Kp;				//��������������ջ�����ϵ��
Uint16	_NPR_IQ_Ki;	   			//�������������ջ�����ϵ��
Uint16	_NPR_IQ_Kd;	   			//�������������ջ�΢��ϵ��
Uint16	_NPR_IQ_outmax;			//��������������ջ�����޷�
Uint16	_NPR_IQ_errmax;	 		//��������������ջ�����޷�
Uint16	_NPR_IQ_errmin;	  		//��������������������Сֵ
Uint16	_NPR_IQ_incrementmax; 	//��������������ջ������޷�

Uint16	_MPR_U_Kp;	   			//�����������ѹ�ջ�����ϵ��
Uint16	_MPR_U_Ki;	  			//�����������ѹ�ջ�����ϵ��
Uint16	_MPR_U_Kd;	  			//�����������ѹ�ջ�΢��ϵ��
Uint16	_MPR_U_outmax;	 		//�����������ѹ�ջ�����޷�
Uint16	_MPR_U_errmax;	  		//�����������ѹ�ջ�������
Uint16	_MPR_U_errmin;		 	//�����������ѹ�ջ������Сֵ
Uint16	_MPR_U_incrementmax; 	//�����������ѹ�ջ������޷�

Uint16 _MPR_ID_Kp;				//��������������ջ�����ϵ��
Uint16 _MPR_ID_Ki;				//��������������ջ�����ϵ��
Uint16 _MPR_ID_Kd;				//��������������ջ�΢��ϵ��
Uint16 _MPR_ID_outmax;			//��������������ջ�����޷�
Uint16 _MPR_ID_errmax;			//��������������ջ�����޷�
Uint16 _MPR_ID_errmin;			//��������������ջ������Сֵ
Uint16 _MPR_ID_incrementmax;		//��������������ջ������޷�

Uint16 _MPR_IQ_Kp;				//��������������ջ�����ϵ��
Uint16 _MPR_IQ_Ki;				//��������������ջ�����ϵ��
Uint16 _MPR_IQ_Kd;				//��������������ջ�΢��ϵ��
Uint16 _MPR_IQ_outmax;			//��������������ջ�����޷�
Uint16 _MPR_IQ_errmax;			//��������������ջ�����޷�
Uint16 _MPR_IQ_errmin;			//��������������ջ������Сֵ
Uint16 _MPR_IQ_incrementmax;	//��������������ջ������޷�


Uint16	_DYN_U_Kp;	   			//�����������ѹ�ջ�����ϵ��
Uint16	_DYN_U_Ki;	  			//�����������ѹ�ջ�����ϵ��
Uint16	_DYN_U_Kd;	  			//�����������ѹ�ջ�΢��ϵ��
Uint16	_DYN_U_outmax;	 		//�����������ѹ�ջ�����޷�
Uint16	_DYN_U_errmax;	  		//����������繱������޷�
Uint16	_DYN_U_errmin;		 	//�����������ѹ�ջ������Сֵ
Uint16	_DYN_U_incrementmax; 	//����������繱ջ������޷�


Uint16 _SC_RTRN;													//����������Դ���
Uint16 _SC_RTRT;													//���ι������Լ��ʱ��(ms)

Uint16 _SC_IACOV1;													//˲ʱ���������ֵ����׼�����İٷ�ֵ)
Uint16 _SC_UDCOV;													//�м�ֱ����ѹ��ѹֵ(V)
Uint16 _SC_UDCOVH;													//�м�ֱ����ѹ��ѹֵ����ѹ���䣩(V)
Uint16 _SC_UDCLV;													//�м�ֱ����ѹǷѹֵ(V)
Uint16 _SC_VDCON;													//�ϵ��ѹ
Uint16 _SC_UACOV1;													//��ѹ������ѹ��ѹ����ֵ(V)
Uint16 _SC_UACLV1;													//������ѹȱ�ද��ֵ(V)
Uint16 _SC_IACOV2;													//��ʱ�޹�������ֵ����׼�����İٷ�ֵ)
Uint16 _SC_PGOV;													//
Uint16 _SC_QGOV;													//
Uint16 _SC_IACOVST;                                                 //���ӵ����������� 

Uint16 _BA_ERR4;													//���Ĵι�����Ϣ
Uint16 _BA_ERR3;													//�����ι�����Ϣ
Uint16 _BA_ERR2;													//�ڶ��������Ϣ
Uint16 _BA_ERR1;													//��һ�ι�����Ϣ
//--------------------------------������Ϣ��-----------------------------------------------------
Uint16 _BA_ENIDRF;													//���¹���ʱ�� d�����ָ��(A)
Uint16 _BA_ENIQRF;													//���¹���ʱ�� q�����ָ��(A)
Uint16 _BA_EMIQRF;													//���¹���ʱ�� q�����ָ��(A)
Uint16 _BA_ETOQRF;													//���¹���ʱ�� ת��ָ��(NM)
Uint16 _BA_EURF;													//���¹���ʱ�� �м�ֱ����ѹ����(V)
Uint16 _BA_EUDC;													//���¹���ʱ�� �м�ֱ����ѹ(V)
Uint16 _BA_EAGLRF;													//���¹���ʱ�� �޹��Ƕ�ָ��()
Uint16 _BA_EIA1;													//���¹���ʱ�� ����A�������Чֵ(A)
Uint16 _BA_EIB1;													//���¹���ʱ�� ����B�������Чֵ(A)
Uint16 _BA_EIC1;													//���¹���ʱ�� ����C�������Чֵ(A)
Uint16 _BA_EIA2;													//���¹���ʱ�� ����A�������Чֵ(A)
Uint16 _BA_EIB2;													//���¹���ʱ�� �����B������Чֵ(A)
Uint16 _BA_EIC2;													//���¹���ʱ�� �����C�������Чֵ(A)
Uint16 _BA_EUAB1;													//���¹���ʱ�� ����A���ѹ��Чֵ(V)
Uint16 _BA_EUBC1;													//���¹���ʱ�� ����B���ѹ��Чֵ(V)
Uint16 _BA_EUAB2;													//���¹���ʱ�� �������ѹ��Чֵ(V)
Uint16 _BA_EUBC2;													//���¹���ʱ�� �����A�������Чֵ(V)
Uint16 _BA_EUAB0;													//���¹���ʱ�� ����ǰAB�ߵ�ѹ��Чֵ(V)
Uint16 _BA_EUBC0;													//���¹���ʱ�� ����ǰBC�ߵ�ѹ��Чֵ(V)
Uint16 _BA_EFREQ;													//���¹���ʱ�� ����Ƶ��(hz)
Uint16 _BA_ESPEED;													//���¹���ʱ�� ���ת��(rpm)
Uint16 _BA_ENPRUD;              			//d�����Ϻ���ѹ����20091026atzy
Uint16 _BA_ENPRUQ;          				//q�����Ϻ���ѹ����20091026atzy
Uint16 _BA_ENPRUD2;          				//d�����Ϻ���ѹ���� �˲���20091026atzy
Uint16 _BA_ENPRUQ2;          				//q�����Ϻ���ѹ���� �˲���20091026atzy
Uint16 _BA_ENUDOUT;          				//����d���ѹ���20091026atzy
Uint16 _BA_ENUQOUT;          				//����q���ѹ���20091026atzy
Uint16 _BA_ETA1;													//���¹���ʱ�� ���������A�ű��¶�
Uint16 _BA_ETB1;													//���¹���ʱ�� ���������B�ű��¶�
Uint16 _BA_ETC1;													//���¹���ʱ�� ���������C�ű��¶�
Uint16 _BA_ETA2;													//���¹���ʱ�� ����������Aű��¶�
Uint16 _BA_ETB2;													//���¹���ʱ�� ����������B�ű��¶�
Uint16 _BA_ETC2;													//���¹���ʱ�� ����������C�ű��¶�
Uint16 _BA_EPIONU;													//���¹���ʱ�� �����ѹ�����
Uint16 _BA_EPIONID;													//���¹���ʱ�� ����d����������
Uint16 _BA_EPIONIQ;													//���¹���ʱ�� ����q����������
Uint16 _BA_EMEXI;													//���¹���ʱ�� �����������ۼ���ֵ��ʾ
Uint16 _BA_EPIOMID;													//���¹���ʱ�� ����d����������
Uint16 _BA_EPIOMIQ;													//���¹���ʱ�� ����q����������
Uint16 _BA_ETLAC;													//���¹���ʱ�� �������¶�
Uint16 _BA_ETLDUDT;													//���¹���ʱ�� �������¶�
Uint16 _BA_ETSKIIP;													//���¹���ʱ�� SKIIP�¶�
Uint16 _BA_ESTAIAC;	
Uint16 _BA_ESTAIBA;	
Uint16 _BA_ETOQFB;	
Uint16 _BA_EPSTA;	
Uint16 _BA_EPNPR;	
Uint16 _BA_EPGRID;	

Uint16 _BA_TIME4_0;													//���¹���ʱ��(��)
Uint16 _BA_TIME4_1;													//���¹���ʱ��(�)
Uint16 _BA_TIME4_2;													//���¹���ʱ��(ʱ)
Uint16 _BA_TIME4_3;													//���¹���ʱ��(��)
Uint16 _BA_TIME4_4;													//���¹��ʱ��(��)
Uint16 _BA_TIME4_5;													//���¹���ʱ��(��)

Uint16 _BA_TIME3_0;													//�����ι���ʱ��(��)
Uint16 _BA_TIME3_1;													//�����ι���ʱ��(��)
Uint16 _BA_TIME3_2;													//�����ι���ʱ��(ʱ)
Uint16 _BA_TIME3_3;													//�����ι���ʱ��(��)
Uint16 _BA_TIME3_4;													//�����ι���ʱ��(��)
Uint16 _BA_TIME3_5;													//�����ι���ʱ��(��)

Uint16 _BA_TIME2_0;													//�ڶ��ι���ʱ��(��)
Uint16 _BA_TIME2_1;													//�ڶ��ι���ʱ��(��)
Uint16 _BA_TIME2_2;													//�ڶ��ι��ϱ�?ʱ)
Uint16 _BA_TIME2_3;													//�ڶ��ι���ʱ��(��)
Uint16 _BA_TIME2_4;													//�ڶ��ι���ʱ��(��)
Uint16 _BA_TIME2_5;													//�ڶ��ι���ʱ?��)

Uint16 _BA_TIME1_0;													//��һ�ι���ʱ��(��)
Uint16 _BA_TIME1_1;													//��һ�ι���ʱ��(��)
Uint16 _BA_TIME1_2;													//��һ�ι���ʱ��(ʱ)
Uint16 _BA_TIME1_3;													//��һ�ι���ʱ��(��)
Uint16 _BA_TIME1_4;													//��һ��
Uint16 _BA_TIME1_5;													//��һ�ι���ʱ��(��)

//-------------------------------------���м�ر���-----------------------------------------------
Uint16 _BA_MIDRF;													//d�����ָ��(A)
Uint16 _BA_NIQRF;													//q�����ָ��(A)
Uint16 _BA_MIQRF;													//q�����ָ��(A)
Uint16 _BA_TOQRF;													//ת��ָ��(NM)
Uint16 _BA_AGLRF;													//�޹��Ƕ�ָ��(NM)
Uint16 _BA_TOQFB;													//ת�ط���(NM)
Uint16 _BA_URF;														//�м�ֱ����ѹ����(V)
Uint16 _BA_UDC;														//�м�ֱ���ѹ(V)
Uint16 _BA_IA1;														//���A�������Чֵ(A)
Uint16 _BA_IB1;														//����B�����Ч�?A)
Uint16 _BA_IC1;														//����C�������Чֵ(A)
Uint16 _BA_IA2;														//�����A�������Чֵ(A)
Uint16 _BA_IB2;														//�����B�������Чֵ(A)
Uint16 _BA_IC2;														//�����C�������Чֵ(A)
Uint16 _BA_UAB1;													//����AB�ߵ�ѹ��Чֵ(V)
Uint16 _BA_UBC1;													//����BC�ߵ�ѹ��Чֵ(V)
Uint16 _BA_UAB2;													//�����AB�ߵ�ѹ��Чֵ(V)
Uint16 _BA_UBC2;													//�����BC�ߵ�����Чֵ(V)
Uint16 _BA_UAB0;												    	//����ǰAB�ߵ�ѹ��Чֵ(V)
Uint16 _BA_UBC0;												    	//����ǰBC�ߵ�����Чֵ(V) 
Uint16 _BA_FREQ;													//����Ƶ�(hz)
Uint16 _BA_SPEED;													//���ת��(rpm)
Uint16 _BA_TA1;														//���������A����¶
Uint16 _BA_TB1;														//��������B�ű��¶�
Uint16 _BA_TC1;														//���������C�ű��¶�
Uint16 _BA_TA2;														//����������A�ű��¶�
Uint16 _BA_TB2;														//����������B�ű��¶�
Uint16 _BA_TC2;														//����������C�ű��¶�
Uint16 _BA_PIONU;													//�����ѹ�����
Uint16 _BA_PIONID;													//����d����������
Uint16 _BA_PIONIQ;													//����q����������
Uint16 _BA_MEXI;													//
Uint16 _BA_PIOMID;													//����d����������
Uint16 _BA_PIOMIQ;													//����q����������
Uint16 _BA_GRDUD;													//������������ѹd
Uint16 _BA_GRDUQ;													//������������ѹq
Uint16 _BA_STAUD;													//���ӵ�ѹd
Uint16 _BA_STAUQ;													//���ӵ�q
Uint16 _BA_STAID;													//������������ѹd
Uint16 _BA_STAIQ;													//������������ѹq
Uint16 _BA_EXCID;													//������������ѹd
Uint16 _BA_EXCIQ;
Uint16 _BA_TLAC;
Uint16 _BA_TLDUDT;
Uint16 _BA_TNSKIIP;
Uint16 _BA_TMSKIIP;
Uint16 _BA_STAUABD;													//����ͬ������ǰ����ǰ���ѹ��
Uint16 _BA_STAUBCD;													//����ͬ������ǰ����ǰ���ѹ��
Uint16 _BA_STAIAC;													//�����ߵ�����Чֵ��ʾ
Uint16 _BA_STAIBA;													//�����ߵ�����Чֵ��ʾ
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
Uint16	_SCIB_BAUD;													//485������
Uint16  _BA_LEDV;
Uint16  _BA_LEDB;
//-----------------------�����ñ���-----------------------------------------------------------

int32 	zys = 0;
int16 	zys1,zys2,zys3,zys4;
Uint32 	i_cnt1=0;  //����CCS������ʾ
Uint32 	i_cnt2=0;  //����CCS������ʾ
Uint32 	i_cnt3=0;  //����CCS������ʾ
float   draw1[150]={0.0},draw2[150]={0.0},draw3[150]={0.0},draw4[150]={0.0},draw5[150]={0.0};
float   draw6[150]={0.0};//,draw7[100]={0.0},draw8[100]={0.0},draw9[100]={0.0},draw10[100]={0.0};
Uint16 zsector = 0;
float testtheta;


//------------------------�������-------------------------------

struct AD_DATA AD_OUT_I;  //��������
float   MPPT_Pnactive;		//����MPPTʱ���й�����
float   Pnactive_pre;	//��һ�ε������й�����
float   GIVE_NPR_Id_pre;	//��һ�εĵ�������ֵ
Uint32 	MPPT_cnt=0;		//����MPPTʱ�ļ���
Uint32 	cnt_Island_U=0;	//�����µ�������ѹ����ֵ
Uint32 	cnt_Island_F=0;	//�����µ�����Ƶ�ʼ���ֵ
float	MPPT_Time;		//��������ʵ��ʱ��
float	MPPT_Id;		//��������ʵ�ʱÿ�����ӵĵ���ֵ

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
