/****************************************Copyright (c)**************************************************
**
**
**
**
**--------------文件信息--------------------------------------------------------------------------------
**文   件   名: user_main.c
**创   建   人:
**最后修改日期:
**描        述: 控制软件主程序
**
**--------------历史版本信息----------------------------------------------------------------------------
** 创建人:
** 版  本:
** 日　期:
** 描　述:
**
**--------------当前版本修订------------------------------------------------------------------------------
** 修改人:
** 日　期:
** 描　述:
**
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
/*---------------------自带头文件-----------------------------*/
#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File
#include "DSP2833x_Project.h"

/*--------------------自定义头文件----------------------------*/
#include "IQmathLib.h"
#include "qmath.h"
#include "user_header.h"  						//变量常量定义
#include "user_macro.h"							//宏函数						 	//工作控制
#include "fir_proc.h"
#include "math.h"
/*-----------------------中断声明-----------------------------*/
interrupt void Cpu_Timer0_ISR(void);

/*-----------------------函数声明-----------------------------*/
void DATA_manage(float *Input,float * Coefficient,float *data);
void FIR();
struct compx EE(struct compx a,struct compx b);
void FFT(struct compx *xin);
float REAL_value(float value_50hz,float k);
float MEAURE_value(float value_0hz,float value_50hz,float k);
float RATIO_error(float MEASURE_value,float TRUE_value);
float ABSOLUTE_error(float MEASURE_value,float TRUE_value);
float A_error();
/*-----------------------宏定义-----------------------------*/
#define A_SET 1              //是否对A相进行处理 1为处理 0为关闭
#define B_SET 0              //是否对B相进行处理 1为处理 0为关闭
#define C_SET 0              //是否对C相进行处理 1为处理 0为关闭
#define FREQ_SET 1           //当该值为1时，采样频率为3200HZ，采样点数为64点；当该值为2时，采样频率为6400HZ，采样点数为128个点
#define FIR_SET 1            //当该值为1时，截止频率为500HZ；当该值为2时，截止频率为2KHZ；当该值为3时，截止频率为10KHZ;
#define AD_ASTART		    ((Uint16 *)0x100000)						//片外AD的数据读取首地址
#define AD_BSTART		    ((Uint16 *)0x110000)					 	//片外AD的数据读取首地址
#define BUF_SIZE  16       //最多可以同时采样的路数
#define PI 3.14159           //定义圆周率值
#define FFT_N FREQ_N                                                   //定义福利叶变换的点数
#define SCALE  10.0  			//量程为10V
#define K 1.007222388861		//补偿系数

#if (FREQ_SET==1)
	#define FREQ_N 64            //采样后得到的数据个数
#endif
#if (FREQ_SET==2)
	#define FREQ_N 128           //采样后得到的数据个数
#endif

/*-----------------------变量声明-----------------------------*/
#pragma   DATA_SECTION(ramtest1,"ZONE7DATA1");
int16   ramtest1[10];
int16   addat[16];
int16 interruptnumber=0;//对中断的次数进行计数

 float ADdata1[FREQ_N];//AD采样后的数据经过幅度转换放入该数组
 float ADdata2[FREQ_N];
 float ADdata3[FREQ_N];

 float TEMP_store1[FREQ_N];//保证DSP能在20ms内完成运算任务，将ADdata中的数据转存入该数组
 float TEMP_store2[FREQ_N];
 float TEMP_store3[FREQ_N];

 float FIRdata1[FREQ_N];//TEMP_store中数据经过FIR滤波后得到的结果
 float FIRdata2[FREQ_N];
 float FIRdata3[FREQ_N];

 float FFTdata1[FREQ_N];//滤波后的数据进行FFT傅里叶变换
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

struct compx {float real,imag;};                                    //定义一个复数结构
struct compx s[FFT_N];                                              //FFT输入和输出：从S[1]开始存放，根据大小自己定义


float fXn[16]={ 0.0 };


float exadc[BUF_SIZE];     //将采样后得到的数据进行幅度处理放入该数组

/*********************************************************************************************************
** 函数名称: main
** 功能描述: 系统初始化,主循环
** 输　入:
** 输　出:
** 注  释:
**-------------------------------------------------------------------------------------------------------
** 作　者:
** 日　期:
**-------------------------------------------------------------------------------------------------------
** 修改人:
** 日　期:
**------------------------------------------------------------------------------------------------------
***********************************************************************************************/
void main(void)
{
    int i,j;
    //滤波器参数
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
//--------------------------------系统初始化--------------------------------
	InitSysCtrl();
//---------------------------------IO初始化---------------------------------
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
//--------------------------------外设初始化--------------------------------
	InitPeripherals();

//--------------------------------中断部分---------------------------------
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

//20ms为一个周期 取64个点，则定时器中断应为0.3125ms
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

//20ms为一个周期 取128个点，则定时器中断应为0.15625ms
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

////--------------------------------复位AD7606--------------------------------
    GpioDataRegs.GPBSET.bit.GPIO60 = 1;
    DELAY_US(0.5L);
	GpioDataRegs.GPBCLEAR.bit.GPIO60 = 1;
	DELAY_US(0.5L);
	GpioDataRegs.GPBSET.bit.GPIO60 = 1;

//--------------------------------工作初始化--------------------------------
    for(i=0;i<BUF_SIZE;i++)
	{
       exadc[i]=0;
	}

    GpioDataRegs.GPASET.bit.GPIO20 = 1;//选择NET模式
    netinit();
    int  init_status;
//----------------------------------主循环---------------------------------------------------------
	for(;;)
	{
		//CH395TEST();
	//GpioDataRegs.GPBSET.bit.GPIO35 = 1;
//----------------------------------每次运行----------------------------------
		  //判断中断是否已经采集一组数据
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

					//进行FIR滤波部分
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
						FIRdata1[i]=fSum;//FIR滤波后得到的数据
						C1[i]=FIRdata1[i]*1000;
					}

					fSum=0;
					for(i=0;i<=FREQ_N-1;i++)
					{
						fSum=FIRdata1[i]+fSum;
					}
					sum2=fSum/FREQ_N;

					//进行傅里叶变换部分
					//将滤波后的数据放入复数数组
					for(i=0;i<=FREQ_N-1;i++)
					{
						s[i].real=FIRdata1[i];
						s[i].imag=0;
					}

					FFT(s);                                        //进行快速傅里叶变换

					for(i=0;i<=FREQ_N-1;i++)//对傅里叶变换后的数据进行幅度处理  //FFTdata数组为最终得到的数据
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
					CH395SendData(0,"A",100); /* 发送数据 */

				}
				if(B_SET==1)
				{
					//进行FIR滤波部分
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
						FIRdata2[i]=fSum;//FIR滤波后得到的数据
						C2[i]=FIRdata2[i]*1000;
					}

					//进行傅里叶变换部分
					//将滤波后的数据放入复数数组
					for(i=0;i<=FREQ_N-1;i++)
					{
						s[i].real=FIRdata2[i];
						s[i].imag=0;
					}

					FFT(s);                                        //进行快速傅里叶变换

					for(i=0;i<=FREQ_N-1;i++)//对傅里叶变换后的数据进行幅度处理  //FFTdata数组为最终得到的数据
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
					CH395SendData(0,"B",100); /* 发送数据 */
				}
				if(C_SET==1)
				{
					//进行FIR滤波部分
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
						FIRdata3[i]=fSum;//FIR滤波后得到的数据
						C3[i]=FIRdata3[i]*1000;
					}

					//进行傅里叶变换部分
					//将滤波后的数据放入复数数组
					for(i=0;i<=FREQ_N-1;i++)
					{
						s[i].real=FIRdata3[i];
						s[i].imag=0;
					}

					FFT(s);                                        //进行快速傅里叶变换

					for(i=0;i<=FREQ_N-1;i++)//对傅里叶变换后的数据进行幅度处理  //FFTdata数组为最终得到的数据
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
					CH395SendData(0,"C",100); /* 发送数据 */
				}

			}
	}
}

//中断程序
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
	//------------------------------数据读取---------------------------------
	//该组AD数据是100us之前的结果

		if(GpioDataRegs.GPADAT.bit.GPIO14==0)//AD_BUSY
		{

			addat[0] = *AD_ASTART;	      // UACA1交流侧电压Uab
			addat[1] = *(AD_ASTART);     // UACA2交流侧电压Ubc

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

	   exadc[1]=addat[4]*SCALE/32768+0.045;//对采样得到的数据进行幅度处理//初始时此值为32768
	   exadc[0]=addat[3]*SCALE/32768+0.045;
	   exadc[2]=addat[2]*SCALE/32768+0.045;

	   ADdata1[interruptnumber]= exadc[1];//将处理后的数据放入ADdata数组
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
函数原型：void FFT(struct compx *xin,int N)
函数功能：对输入的复数组进行快速傅里叶变换（FFT）
输入参数：*xin复数结构体组的首地址指针，struct型
*****************************************************************/
void FFT(struct compx *xin)
{
  int f,m,nv2,nm1,i,k,l,j=0;
  struct compx u,w,t;

   nv2=FFT_N/2;                  //变址运算，即把自然顺序变成倒位序，采用雷德算法
   nm1=FFT_N-1;
   for(i=0;i<nm1;i++)
   {
    if(i<j)                    //如果i<j,即进行变址
     {
      t=xin[j];
      xin[j]=xin[i];
      xin[i]=t;
     }
    k=nv2;                    //求j的下一个倒位序
    while(k<=j)               //如果k<=j,表示j的最高位为1
     {
      j=j-k;                 //把最高位变成0
      k=k/2;                 //k/2，比较次高位，依次类推，逐个比较，直到某个位为0
     }
   j=j+k;                   //把0改为1
  }

  {
   int le,lei,ip;                            //FFT运算核，使用蝶形运算完成FFT运算
    f=FFT_N;
   for(l=1;(f=f/2)!=1;l++)                  //计算l的值，即计算蝶形级数
           ;
  for(m=1;m<=l;m++)                         // 控制蝶形结级数
   {                                        //m表示第m级蝶形，l为蝶形级总数l=log（2）N
    le=2<<(m-1);                            //le蝶形结距离，即第m级蝶形的蝶形结相距le点
    lei=le/2;                               //同一蝶形结中参加运算的两点的距离
    u.real=1.0;                             //u为蝶形结运算系数，初始值为1
    u.imag=0.0;
    w.real=cos((float)PI/(float)lei);                     //w为系数商，即当前系数与前一个系数的商
    w.imag=-sin((float)PI/(float)lei);
    for(j=0;j<=lei-1;j++)                   //控制计算不同种蝶形结，即计算系数不同的蝶形结
     {
      for(i=j;i<=FFT_N-1;i=i+le)            //控制同一蝶形结运算，即计算系数相同蝶形结
       {
        ip=i+lei;                           //i，ip分别表示参加蝶形运算的两个节点
        t=EE(xin[ip],u);                    //蝶形运算，详见公式
        xin[ip].real=xin[i].real-t.real;
        xin[ip].imag=xin[i].imag-t.imag;
        xin[i].real=xin[i].real+t.real;
        xin[i].imag=xin[i].imag+t.imag;
       }
      u=EE(u,w);                           //改变系数，进行下一个蝶形运算
     }
   }
  }

}


/*******************************************************************
函数原型：struct compx EE(struct compx b1,struct compx b2)
函数功能：对两个复数进行乘法运算
输入参数：两个以联合体定义的复数a,b
输出参数：a和b的乘积，以联合体的形式输出
*******************************************************************/
struct compx EE(struct compx a,struct compx b)
{
 struct compx c;
 c.real=a.real*b.real-a.imag*b.imag;
 c.imag=a.real*b.imag+a.imag*b.real;
 return(c);
}


/*******************************************************************
函数原型：float REAL_value(float vlaue_50hz,float k)
函数功能：计算电压的真实值
输入参数：fft后50hz部分的数值,k为系数
输出参数：value_50hz和k的乘积输出
*******************************************************************/
float REAL_value(float value_50hz,float k)
{
	return value_50hz*k;
}


/*******************************************************************
函数原型：float MEAURE_value(float value_0hz,float value_50hz,float k)
函数功能：计算电压的测量值
输入参数：fft后50hz部分的数值与直流部分,k为系数
输出参数：(2.5/value_0hz)*value_50hz*k
*******************************************************************/
float MEAURE_value(float value_0hz,float value_50hz,float k)
{
	return (2.5/value_0hz)*value_50hz*k;
}


/*******************************************************************
函数原型：float RATIO_error(float MEASURE_value,float TRUE_value)
函数功能：计算比值误差
输入参数：MEASURE_value为电压测量值，TRUE_value为真是电压
输出参数：(MEASURE_value-TRUE_value)/TRUE_value
*******************************************************************/
float RATIO_error(float MEASURE_value,float TRUE_value)
{
	return (MEASURE_value-TRUE_value)/TRUE_value*100;
}


/*******************************************************************
函数原型：float ABSOLUTE_error(float MEASURE_value,float TRUE_value)
函数功能：计算绝对误差
输入参数：MEASURE_value为电压测量值，TRUE_value为真是电压
输出参数：(MEASURE_value-TRUE_value)
*******************************************************************/
float ABSOLUTE_error(float MEASURE_value,float TRUE_value)
{
	return (MEASURE_value-TRUE_value);
}


/*******************************************************************
函数原型：float A_error(float MEASURE_value,float TRUE_value)
函数功能：计算相位误差
输入参数：
输出参数：
*******************************************************************/
float A_error()
{

}
