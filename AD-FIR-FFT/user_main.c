/****************************************Copyright (c)**************************************************
**
**
**
**
**--------------�ļ���Ϣ--------------------------------------------------------------------------------
**��   ��   ��: user_main.c
**��   ��   ��:
**����޸�����:
**��        ��: �������������
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
/*---------------------�Դ�ͷ�ļ�-----------------------------*/
#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File
#include "DSP2833x_Project.h"

/*--------------------�Զ���ͷ�ļ�----------------------------*/
#include "IQmathLib.h"
#include "qmath.h"
#include "user_header.h"  						//������������
#include "user_macro.h"							//�꺯��						 	//��������
#include "fir_proc.h"
#include "math.h"
/*-----------------------�ж�����-----------------------------*/
interrupt void Cpu_Timer0_ISR(void);

/*-----------------------��������-----------------------------*/
void DATA_manage(float *Input,float * Coefficient,float *data);
void FIR();
struct compx EE(struct compx a,struct compx b);
void FFT(struct compx *xin);
float REAL_value(float value_50hz,float k);
float MEAURE_value(float value_0hz,float value_50hz,float k);
float RATIO_error(float MEASURE_value,float TRUE_value);
float ABSOLUTE_error(float MEASURE_value,float TRUE_value);
float A_error();
/*-----------------------�궨��-----------------------------*/
#define A_SET 1              //�Ƿ��A����д��� 1Ϊ���� 0Ϊ�ر�
#define B_SET 0              //�Ƿ��B����д��� 1Ϊ���� 0Ϊ�ر�
#define C_SET 0              //�Ƿ��C����д��� 1Ϊ���� 0Ϊ�ر�
#define FREQ_SET 1           //����ֵΪ1ʱ������Ƶ��Ϊ3200HZ����������Ϊ64�㣻����ֵΪ2ʱ������Ƶ��Ϊ6400HZ����������Ϊ128����
#define FIR_SET 1            //����ֵΪ1ʱ����ֹƵ��Ϊ500HZ������ֵΪ2ʱ����ֹƵ��Ϊ2KHZ������ֵΪ3ʱ����ֹƵ��Ϊ10KHZ;
#define AD_ASTART		    ((Uint16 *)0x100000)						//Ƭ��AD�����ݶ�ȡ�׵�ַ
#define AD_BSTART		    ((Uint16 *)0x110000)					 	//Ƭ��AD�����ݶ�ȡ�׵�ַ
#define BUF_SIZE  16       //������ͬʱ������·��
#define PI 3.14159           //����Բ����ֵ
#define FFT_N FREQ_N                                                   //���帣��Ҷ�任�ĵ���
#define SCALE  10.0  			//����Ϊ10V
#define K 1.007222388861		//����ϵ��

#if (FREQ_SET==1)
	#define FREQ_N 64            //������õ������ݸ���
#endif
#if (FREQ_SET==2)
	#define FREQ_N 128           //������õ������ݸ���
#endif

/*-----------------------��������-----------------------------*/
#pragma   DATA_SECTION(ramtest1,"ZONE7DATA1");
int16   ramtest1[10];
int16   addat[16];
int16 interruptnumber=0;//���жϵĴ������м���

 float ADdata1[FREQ_N];//AD����������ݾ�������ת�����������
 float ADdata2[FREQ_N];
 float ADdata3[FREQ_N];

 float TEMP_store1[FREQ_N];//��֤DSP����20ms������������񣬽�ADdata�е�����ת���������
 float TEMP_store2[FREQ_N];
 float TEMP_store3[FREQ_N];

 float FIRdata1[FREQ_N];//TEMP_store�����ݾ���FIR�˲���õ��Ľ��
 float FIRdata2[FREQ_N];
 float FIRdata3[FREQ_N];

 float FFTdata1[FREQ_N];//�˲�������ݽ���FFT����Ҷ�任
 float FFTdata2[FREQ_N];
 float FFTdata3[FREQ_N];

 int A1[FREQ_N];
 int A2[FREQ_N];
 int A3[FREQ_N];

 int C1[FREQ_N];
 int C2[FREQ_N];
 int C3[FREQ_N];

 int D1[FREQ_N];
 int D2[FREQ_N];
 int D3[FREQ_N];


 float A_data[3];
 float B_data[3];
 float C_data[3];

 float m_value1;
 float r_value1;
 float m_value2;
 float r_value2;
 float m_value3;
 float r_value3;

 int temp=0;
 float fSum;

float sum1=0;
float sum2=0;

struct compx {float real,imag;};                                    //����һ�������ṹ
struct compx s[FFT_N];                                              //FFT������������S[1]��ʼ��ţ����ݴ�С�Լ�����


float fXn[16]={ 0.0 };


float exadc[BUF_SIZE];     //��������õ������ݽ��з��ȴ�����������

/*********************************************************************************************************
** ��������: main
** ��������: ϵͳ��ʼ��,��ѭ��
** �䡡��:
** �䡡��:
** ע  ��:
**-------------------------------------------------------------------------------------------------------
** ������:
** �ա���:
**-------------------------------------------------------------------------------------------------------
** �޸���:
** �ա���:
**------------------------------------------------------------------------------------------------------
***********************************************************************************************/
void main(void)
{
    int i,j;
    //�˲�������
    float fHn[16];
    float fHn1[]=
    {
   		 0.00289032423803943,
   		 0.000559842182248612,
   		 -0.0101929745897693,
   		 -0.0265912809731155,
   		 -0.0154070008206851,
   		 0.0619531467811193,
   		 0.192361220554956,
   		 0.297037472830633,
   		 0.297037472830633,
   		 0.192361220554956,
   		 0.0619531467811191,
   		 -0.0154070008206851,
   		 -0.0265912809731155,
   		 -0.0101929745897692,
   		 0.000559842182248620,
   		 0.00289032423803943
   	};

    float fHn2[]=
    {
    		0.00272497882836175,
    		0.00111429277824130,
    		-0.0129327092508006,
    		0.0154380828301271,
    		0.0294871610759456,
    		-0.0957808601610423,
    		0.0377093934982017,
    		0.523927327195265,
    		0.523927327195264,
    		0.0377093934982010,
    		-0.0957808601610422,
    		0.0294871610759457,
    		0.0154380828301271,
    		-0.0129327092508006,
    		0.00111429277824132,
    		0.00272497882836175,
    };

    float fHn3[]=
    {
    		1
    };

    float fHn4[]=
    {
    		-0.00168487106780693,
    		-0.000280258674972190,
    		0.00563777395778147,
    		0.0223193822559291,
    		0.0525010256999210,
    		0.0919486683218550,
    		0.129806956202950,
    		0.153107166316765,
    		0.153107166316764,
    		0.129806956202950,
    		0.0919486683218550,
    		0.0525010256999210,
    };

    float fHn5[]=
    {
     		 0.00289032423803943,
     		 0.000559842182248612,
     		 -0.0101929745897693,
     		 -0.0265912809731155,
     		 -0.0154070008206851,
     		 0.0619531467811193,
     		 0.192361220554956,
     		 0.297037472830633,
     		 0.297037472830633,
     		 0.192361220554956,
     		 0.0619531467811191,
     		 -0.0154070008206851,
     		 -0.0265912809731155,
     		 -0.0101929745897692,
     		 0.000559842182248620,
     		 0.00289032423803943
    };

    float fHn6[]=
    {
    		0.00272497882836175,
    		0.00111429277824130,
    		-0.0129327092508006,
    		0.0154380828301271,
    		0.0294871610759456,
    		-0.0957808601610423,
    		 0.0377093934982017,
    		 0.523927327195265,
    		0.523927327195264,
    		 0.0377093934982010,
    		 -0.0957808601610422,
    		 0.0294871610759457,
    		 0.0154380828301271,
    		 -0.0129327092508006,
    		  0.00111429277824132,
    		  0.00272497882836175,
    };


#if(FIR_SET==1&&FREQ_SET==1)
    for(i=0;i<=15;i++)
    {
    	fHn[i]=fHn1[i];
    }
#endif

#if(FIR_SET==2&&FREQ_SET==1)
    for(i=0;i<=15;i++)
    {
    	fHn[i]=fHn2[i];
    }
#endif

#if(FIR_SET==3&&FREQ_SET==1)
    for(i=0;i<=15;i++)
    {
    	fHn[i]=fHn3[i];
    }
#endif

#if(FIR_SET==1&&FREQ_SET==2)
    for(i=0;i<=15;i++)
    {
    	fHn[i]=fHn4[i];
    }
#endif

#if(FIR_SET==2&&FREQ_SET==2)
    for(i=0;i<=15;i++)
    {
    	fHn[i]=fHn5[i];
    }
#endif

#if(FIR_SET==3&&FREQ_SET==2)
    for(i=0;i<=15;i++)
    {
    	fHn[i]=fHn6[i];
    }
#endif
//--------------------------------ϵͳ��ʼ��--------------------------------
	InitSysCtrl();
//---------------------------------IO��ʼ��---------------------------------
	InitGpio();
    DisableDog();

    EALLOW;
    GpioCtrlRegs.GPAMUX1.bit.GPIO12 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO12 = 1;
    GpioDataRegs.GPADAT.bit.GPIO12 = 0;
    GpioCtrlRegs.GPBMUX1.bit.GPIO34 = 0;
    GpioCtrlRegs.GPBDIR.bit.GPIO34 = 1;
    GpioDataRegs.GPBDAT.bit.GPIO34 = 0;
    EDIS;

	DINT;
   	InitPieCtrl();
	IER = 0x0000;
	IFR = 0x0000;
	InitPieVectTable();
//--------------------------------�����ʼ��--------------------------------
	InitPeripherals();

//--------------------------------�жϲ���---------------------------------
	EALLOW;
	PieVectTable.TINT0=&Cpu_Timer0_ISR;
	EDIS;

	InitCpuTimers();

#if (FREQ_SET==1)
#if (CPU_FRQ_150MHZ)
// Configure CPU-Timer 0, 1, and 2 to interrupt every second:
// 150MHz CPU Freq, 1 second Period (in uSeconds)
   ConfigCpuTimer(&CpuTimer0, 150, 312.5);
#endif

//20msΪһ������ ȡ64���㣬��ʱ���ж�ӦΪ0.3125ms
#if (CPU_FRQ_100MHZ)
// Configure CPU-Timer 0, 1, and 2 to interrupt every second:
// 100MHz CPU Freq, 1 second Period (in uSeconds)
   ConfigCpuTimer(&CpuTimer0, 100, 321.5);
#endif
#endif

#if (FREQ_SET==2)
#if (CPU_FRQ_150MHZ)
// Configure CPU-Timer 0, 1, and 2 to interrupt every second:
// 150MHz CPU Freq, 1 second Period (in uSeconds)
   ConfigCpuTimer(&CpuTimer0, 300, 312.5);
#endif

//20msΪһ������ ȡ128���㣬��ʱ���ж�ӦΪ0.15625ms
#if (CPU_FRQ_100MHZ)
// Configure CPU-Timer 0, 1, and 2 to interrupt every second:
// 100MHz CPU Freq, 1 second Period (in uSeconds)
   ConfigCpuTimer(&CpuTimer0, 200, 321.5);
#endif
#endif

   	CpuTimer0Regs.TCR.all = 0x4001; // Use write-only instruction to set TSS bit = 0

	IER|=M_INT1;
	PieCtrlRegs.PIEIER1.bit.INTx7= 1;

// Enable global Interrupts and higher priority real-time debug events:
	EINT;   // Enable Global interrupt INTM
	ERTM;   // Enable Global realtime interrupt DBGM

////--------------------------------��λAD7606--------------------------------
    GpioDataRegs.GPBSET.bit.GPIO60 = 1;
    DELAY_US(0.5L);
	GpioDataRegs.GPBCLEAR.bit.GPIO60 = 1;
	DELAY_US(0.5L);
	GpioDataRegs.GPBSET.bit.GPIO60 = 1;

//--------------------------------������ʼ��--------------------------------
    for(i=0;i<BUF_SIZE;i++)
	{
       exadc[i]=0;
	}

    GpioDataRegs.GPASET.bit.GPIO20 = 1;//ѡ��NETģʽ
    netinit();
    int  init_status;
//----------------------------------��ѭ��---------------------------------------------------------
	for(;;)
	{
		//CH395TEST();
	//GpioDataRegs.GPBSET.bit.GPIO35 = 1;
//----------------------------------ÿ������----------------------------------
		  //�ж��ж��Ƿ��Ѿ��ɼ�һ������
			if(interruptnumber>=FREQ_N-1)
			{
				if(A_SET==1)
				{

					fSum=0;
					for(i=0;i<=FREQ_N-1;i++)
					{
						fSum=TEMP_store1[i]+fSum;
					}
					sum1=fSum/FREQ_N;

					//����FIR�˲�����
					for(i=0;i<=FREQ_N-1;i++)
					{
						for (j=15;j>0;j--)
						{
							fXn[j]=fXn[j-1];
						}
						fXn[0]=TEMP_store1[i];

						fSum=0;
						for ( j=0;j<16;j++ )
						{
							fSum+=(fXn[j]*fHn[j]);
						}
						FIRdata1[i]=fSum;//FIR�˲���õ�������
						C1[i]=FIRdata1[i]*1000;
					}

					fSum=0;
					for(i=0;i<=FREQ_N-1;i++)
					{
						fSum=FIRdata1[i]+fSum;
					}
					sum2=fSum/FREQ_N;

					//���и���Ҷ�任����
					//���˲�������ݷ��븴������
					for(i=0;i<=FREQ_N-1;i++)
					{
						s[i].real=FIRdata1[i];
						s[i].imag=0;
					}

					FFT(s);                                        //���п��ٸ���Ҷ�任

					for(i=0;i<=FREQ_N-1;i++)//�Ը���Ҷ�任������ݽ��з��ȴ���  //FFTdata����Ϊ���յõ�������
					{
						if(i==0||i==FREQ_N-1)
						{
							FFTdata1[i]=sqrt(s[i].real*s[i].real+s[i].imag*s[i].imag)/FREQ_N;
							D1[i]=FFTdata1[i]*1000;
						}
						else
						{
							FFTdata1[i]=sqrt(s[i].real*s[i].real+s[i].imag*s[i].imag)/FREQ_N*2;
							D1[i]=FFTdata1[i]*1000;
						}
					}

					m_value1=REAL_value(FFTdata1[1],K);
					r_value1=MEAURE_value(FFTdata1[0],FFTdata1[1],K);
					A_data[0]=RATIO_error(m_value1,r_value1);
					A_data[1]=ABSOLUTE_error(m_value1,r_value1);
					A_data[3]=A_error();
					init_status = CH395CMDGetGlobIntStatus();
					init_status = CH395GetSocketInt(0);
					CH395SendData(0,"A",100); /* �������� */

				}
				if(B_SET==1)
				{
					//����FIR�˲�����
					for(i=0;i<=FREQ_N-1;i++)
					{
						for (j=15;j>0;j--)
						{
							fXn[j]=fXn[j-1];
						}
						fXn[0]=TEMP_store2[i];

						fSum=0;
						for ( j=0;j<16;j++ )
						{
							fSum+=(fXn[j]*fHn[j]);
						}
						FIRdata2[i]=fSum;//FIR�˲���õ�������
						C2[i]=FIRdata2[i]*1000;
					}

					//���и���Ҷ�任����
					//���˲�������ݷ��븴������
					for(i=0;i<=FREQ_N-1;i++)
					{
						s[i].real=FIRdata2[i];
						s[i].imag=0;
					}

					FFT(s);                                        //���п��ٸ���Ҷ�任

					for(i=0;i<=FREQ_N-1;i++)//�Ը���Ҷ�任������ݽ��з��ȴ���  //FFTdata����Ϊ���յõ�������
					{
						if(i==0||i==FREQ_N-1)
						{
							FFTdata2[i]=sqrt(s[i].real*s[i].real+s[i].imag*s[i].imag)/FREQ_N;
							D2[i]=FFTdata2[i]*1000;
						}
						else
						{
							FFTdata2[i]=sqrt(s[i].real*s[i].real+s[i].imag*s[i].imag)/FREQ_N*2;
							D2[i]=FFTdata2[i]*1000;
						}
					}

					r_value2=REAL_value(FFTdata2[1],K);
					m_value2=MEAURE_value(FFTdata2[0],FFTdata2[1],K);
					B_data[0]=RATIO_error(m_value2,r_value2);
					B_data[1]=ABSOLUTE_error(m_value2,r_value2);
					B_data[3]=A_error();

					init_status = CH395CMDGetGlobIntStatus();
					init_status = CH395GetSocketInt(0);
					CH395SendData(0,"B",100); /* �������� */
				}
				if(C_SET==1)
				{
					//����FIR�˲�����
					for(i=0;i<=FREQ_N-1;i++)
					{
						for (j=15;j>0;j--)
						{
							fXn[j]=fXn[j-1];
						}
						fXn[0]=TEMP_store3[i];

						fSum=0;
						for ( j=0;j<16;j++ )
						{
							fSum+=(fXn[j]*fHn[j]);
						}
						FIRdata3[i]=fSum;//FIR�˲���õ�������
						C3[i]=FIRdata3[i]*1000;
					}

					//���и���Ҷ�任����
					//���˲�������ݷ��븴������
					for(i=0;i<=FREQ_N-1;i++)
					{
						s[i].real=FIRdata3[i];
						s[i].imag=0;
					}

					FFT(s);                                        //���п��ٸ���Ҷ�任

					for(i=0;i<=FREQ_N-1;i++)//�Ը���Ҷ�任������ݽ��з��ȴ���  //FFTdata����Ϊ���յõ�������
					{
						if(i==0||i==FREQ_N-1)
						{
							FFTdata3[i]=sqrt(s[i].real*s[i].real+s[i].imag*s[i].imag)/FREQ_N;
							D3[i]=FFTdata3[i]*1000;
						}
						else
						{
							FFTdata3[i]=sqrt(s[i].real*s[i].real+s[i].imag*s[i].imag)/FREQ_N*2;
							D3[i]=FFTdata3[i]*1000;
						}
					}

					r_value3=REAL_value(FFTdata3[1],K);
					m_value3=MEAURE_value(FFTdata3[0],FFTdata3[1],K);
					C_data[0]=RATIO_error(m_value3,r_value3);
					C_data[1]=ABSOLUTE_error(m_value3,r_value3);
					C_data[3]=A_error();

					init_status = CH395CMDGetGlobIntStatus();
					init_status = CH395GetSocketInt(0);
					CH395SendData(0,"C",100); /* �������� */
				}

			}
	}
}

//�жϳ���
interrupt void Cpu_Timer0_ISR(void)
{
	//GpioDataRegs.GPADAT.bit.GPIO12 =~ GpioDataRegs.GPADAT.bit.GPIO12;
	//GpioDataRegs.GPBDAT.bit.GPIO34 =~ GpioDataRegs.GPBDAT.bit.GPIO34;
		static int16 i=0;
	    GpioDataRegs.GPASET.bit.GPIO15 = 1;//xhold
	//	DELAY_US(0.5L);
		GpioDataRegs.GPACLEAR.bit.GPIO15 = 1;
	//	DELAY_US(0.5L);
		GpioDataRegs.GPASET.bit.GPIO15 = 1;
	//	DELAY_US(5L);
	//------------------------------���ݶ�ȡ---------------------------------
	//����AD������100us֮ǰ�Ľ��

		if(GpioDataRegs.GPADAT.bit.GPIO14==0)//AD_BUSY
		{

			addat[0] = *AD_ASTART;	      // UACA1�������ѹUab
			addat[1] = *(AD_ASTART);     // UACA2�������ѹUbc

			addat[2] = *(AD_ASTART);     // INV_Uab
			addat[3] = *(AD_ASTART);     // INV_Ubc
			addat[4] = *(AD_ASTART);     // VDC+
			addat[5] = *(AD_ASTART);     // VDC-
			addat[6] = *(AD_ASTART);     // Ia
			addat[7] = *(AD_ASTART);     // Ib
			//DELAY_US(1L);
			addat[8] = *AD_BSTART;	      // Ic
			addat[9] = *AD_BSTART;        // Idc1
			addat[10] = *AD_BSTART;      // Idc2
			addat[11] = *AD_BSTART;      // Amux
			addat[12] = *AD_BSTART;      //
			addat[13] = *AD_BSTART;      //
			addat[14] = *AD_BSTART;     //
			addat[15] = *AD_BSTART;     //

		 }

	   exadc[1]=addat[4]*SCALE/32768+0.045;//�Բ����õ������ݽ��з��ȴ���//��ʼʱ��ֵΪ32768
	   exadc[0]=addat[3]*SCALE/32768+0.045;
	   exadc[2]=addat[2]*SCALE/32768+0.045;

	   ADdata1[interruptnumber]= exadc[1];//�����������ݷ���ADdata����
	   ADdata2[interruptnumber]= exadc[0];
	   ADdata3[interruptnumber]= exadc[2];

	   A1[interruptnumber]=exadc[1]*1000;
	   A2[interruptnumber]=exadc[0]*1000;
	   A3[interruptnumber]=exadc[2]*1000;

	   interruptnumber++;

	   if(interruptnumber>=FREQ_N)
	   {
		   interruptnumber=0;
		   for(i=0;i<=FREQ_N-1;i++)
		   {
			   TEMP_store1[i]=ADdata1[i];
			   TEMP_store2[i]=ADdata2[i];
			   TEMP_store3[i]=ADdata3[i];
		   }
	   }

	   // Acknowledge this interrupt to receive more interrupts from group 1
	   PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;

}


/*****************************************************************
����ԭ�ͣ�void FFT(struct compx *xin,int N)
�������ܣ�������ĸ�������п��ٸ���Ҷ�任��FFT��
���������*xin�����ṹ������׵�ַָ�룬struct��
*****************************************************************/
void FFT(struct compx *xin)
{
  int f,m,nv2,nm1,i,k,l,j=0;
  struct compx u,w,t;

   nv2=FFT_N/2;                  //��ַ���㣬������Ȼ˳���ɵ�λ�򣬲����׵��㷨
   nm1=FFT_N-1;
   for(i=0;i<nm1;i++)
   {
    if(i<j)                    //���i<j,�����б�ַ
     {
      t=xin[j];
      xin[j]=xin[i];
      xin[i]=t;
     }
    k=nv2;                    //��j����һ����λ��
    while(k<=j)               //���k<=j,��ʾj�����λΪ1
     {
      j=j-k;                 //�����λ���0
      k=k/2;                 //k/2���Ƚϴθ�λ���������ƣ�����Ƚϣ�ֱ��ĳ��λΪ0
     }
   j=j+k;                   //��0��Ϊ1
  }

  {
   int le,lei,ip;                            //FFT����ˣ�ʹ�õ����������FFT����
    f=FFT_N;
   for(l=1;(f=f/2)!=1;l++)                  //����l��ֵ����������μ���
           ;
  for(m=1;m<=l;m++)                         // ���Ƶ��νἶ��
   {                                        //m��ʾ��m�����Σ�lΪ���μ�����l=log��2��N
    le=2<<(m-1);                            //le���ν���룬����m�����εĵ��ν����le��
    lei=le/2;                               //ͬһ���ν��вμ����������ľ���
    u.real=1.0;                             //uΪ���ν�����ϵ������ʼֵΪ1
    u.imag=0.0;
    w.real=cos((float)PI/(float)lei);                     //wΪϵ���̣�����ǰϵ����ǰһ��ϵ������
    w.imag=-sin((float)PI/(float)lei);
    for(j=0;j<=lei-1;j++)                   //���Ƽ��㲻ͬ�ֵ��νᣬ������ϵ����ͬ�ĵ��ν�
     {
      for(i=j;i<=FFT_N-1;i=i+le)            //����ͬһ���ν����㣬������ϵ����ͬ���ν�
       {
        ip=i+lei;                           //i��ip�ֱ��ʾ�μӵ�������������ڵ�
        t=EE(xin[ip],u);                    //�������㣬�����ʽ
        xin[ip].real=xin[i].real-t.real;
        xin[ip].imag=xin[i].imag-t.imag;
        xin[i].real=xin[i].real+t.real;
        xin[i].imag=xin[i].imag+t.imag;
       }
      u=EE(u,w);                           //�ı�ϵ����������һ����������
     }
   }
  }

}


/*******************************************************************
����ԭ�ͣ�struct compx EE(struct compx b1,struct compx b2)
�������ܣ��������������г˷�����
��������������������嶨��ĸ���a,b
���������a��b�ĳ˻��������������ʽ���
*******************************************************************/
struct compx EE(struct compx a,struct compx b)
{
 struct compx c;
 c.real=a.real*b.real-a.imag*b.imag;
 c.imag=a.real*b.imag+a.imag*b.real;
 return(c);
}


/*******************************************************************
����ԭ�ͣ�float REAL_value(float vlaue_50hz,float k)
�������ܣ������ѹ����ʵֵ
���������fft��50hz���ֵ���ֵ,kΪϵ��
���������value_50hz��k�ĳ˻����
*******************************************************************/
float REAL_value(float value_50hz,float k)
{
	return value_50hz*k;
}


/*******************************************************************
����ԭ�ͣ�float MEAURE_value(float value_0hz,float value_50hz,float k)
�������ܣ������ѹ�Ĳ���ֵ
���������fft��50hz���ֵ���ֵ��ֱ������,kΪϵ��
���������(2.5/value_0hz)*value_50hz*k
*******************************************************************/
float MEAURE_value(float value_0hz,float value_50hz,float k)
{
	return (2.5/value_0hz)*value_50hz*k;
}


/*******************************************************************
����ԭ�ͣ�float RATIO_error(float MEASURE_value,float TRUE_value)
�������ܣ������ֵ���
���������MEASURE_valueΪ��ѹ����ֵ��TRUE_valueΪ���ǵ�ѹ
���������(MEASURE_value-TRUE_value)/TRUE_value
*******************************************************************/
float RATIO_error(float MEASURE_value,float TRUE_value)
{
	return (MEASURE_value-TRUE_value)/TRUE_value*100;
}


/*******************************************************************
����ԭ�ͣ�float ABSOLUTE_error(float MEASURE_value,float TRUE_value)
�������ܣ�����������
���������MEASURE_valueΪ��ѹ����ֵ��TRUE_valueΪ���ǵ�ѹ
���������(MEASURE_value-TRUE_value)
*******************************************************************/
float ABSOLUTE_error(float MEASURE_value,float TRUE_value)
{
	return (MEASURE_value-TRUE_value);
}


/*******************************************************************
����ԭ�ͣ�float A_error(float MEASURE_value,float TRUE_value)
�������ܣ�������λ���
���������
���������
*******************************************************************/
float A_error()
{

}
