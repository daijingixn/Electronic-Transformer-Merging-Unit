//###########################################################################
//
// FILE:	DSP2833x_Gpio.c
//
// TITLE:	DSP2833x General Purpose I/O Initialization & Support Functions.
//
//###########################################################################
// $TI Release: DSP2833x Header Files V1.10 $
// $Release Date: February 15, 2008 $
//###########################################################################

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File

//---------------------------------------------------------------------------
// InitGpio: 
//---------------------------------------------------------------------------
// This function initializes the Gpio to a known (default) state.
//
// For more details on configuring GPIO's as peripheral functions,
// refer to the individual peripheral examples and/or GPIO setup example. 
void InitGpio(void)
{
   EALLOW;
   
//EPWM1-12
   GpioCtrlRegs.GPAPUD.bit.GPIO0 = 1;//disable pullup on GPIO0
   GpioCtrlRegs.GPAPUD.bit.GPIO1 = 1;//disable pullup on GPIO1
   GpioCtrlRegs.GPAPUD.bit.GPIO2 = 1;//disable pullup on GPIO2
   GpioCtrlRegs.GPAPUD.bit.GPIO3 = 1;//disable pullup on GPIO3
   GpioCtrlRegs.GPAPUD.bit.GPIO4 = 1;//disable pullup on GPIO4
   GpioCtrlRegs.GPAPUD.bit.GPIO5 = 1;//disable pullup on GPIO5
   GpioCtrlRegs.GPAPUD.bit.GPIO6 = 1;//disable pullup on GPIO6
   GpioCtrlRegs.GPAPUD.bit.GPIO7 = 1;//disable pullup on GPIO7
   GpioCtrlRegs.GPAPUD.bit.GPIO8 = 1;//disable pullup on GPIO8
   GpioCtrlRegs.GPAPUD.bit.GPIO9 = 1;//disable pullup on GPIO9
   GpioCtrlRegs.GPAPUD.bit.GPIO10 = 1;//disable pullup on GPIO10
   GpioCtrlRegs.GPAPUD.bit.GPIO11 = 1;//disable pullup on GPIO11

  
    GpioDataRegs.GPACLEAR.bit.GPIO0 = 1;  //
    GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 0;  //
    GpioCtrlRegs.GPADIR.bit.GPIO0 = 1;  // 
	
	GpioDataRegs.GPACLEAR.bit.GPIO1 = 1;  //
    GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 0;  //
    GpioCtrlRegs.GPADIR.bit.GPIO1 = 1;  // 
	
	GpioDataRegs.GPACLEAR.bit.GPIO2 = 1;  //
    GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 0;  //
    GpioCtrlRegs.GPADIR.bit.GPIO2 = 1;  // 
	
	GpioDataRegs.GPACLEAR.bit.GPIO3 = 1;  //
    GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 0;  //
    GpioCtrlRegs.GPADIR.bit.GPIO3 = 1;  // 
   
    GpioDataRegs.GPACLEAR.bit.GPIO4 = 1;  //
    GpioCtrlRegs.GPAMUX1.bit.GPIO4 = 0;  //
    GpioCtrlRegs.GPADIR.bit.GPIO4 = 1;  // 
	
	GpioDataRegs.GPACLEAR.bit.GPIO5 = 1;  //
    GpioCtrlRegs.GPAMUX1.bit.GPIO5 = 0;  //
    GpioCtrlRegs.GPADIR.bit.GPIO5 = 1;  // 
   
    GpioDataRegs.GPACLEAR.bit.GPIO6 = 1;  //
    GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 0;  //
    GpioCtrlRegs.GPADIR.bit.GPIO6 = 1;  // 
	
	GpioDataRegs.GPACLEAR.bit.GPIO7 = 1;  //
    GpioCtrlRegs.GPAMUX1.bit.GPIO7 = 0;  //
    GpioCtrlRegs.GPADIR.bit.GPIO7 = 1;  // 
	
	GpioDataRegs.GPACLEAR.bit.GPIO8 = 1;  //
    GpioCtrlRegs.GPAMUX1.bit.GPIO8 = 0;  //
    GpioCtrlRegs.GPADIR.bit.GPIO8 = 1;  // 
	
	GpioDataRegs.GPACLEAR.bit.GPIO9 = 1;  //
    GpioCtrlRegs.GPAMUX1.bit.GPIO9 = 0;  //
    GpioCtrlRegs.GPADIR.bit.GPIO9 = 1;  // 
   
    GpioDataRegs.GPACLEAR.bit.GPIO10 = 1;  //
    GpioCtrlRegs.GPAMUX1.bit.GPIO10 = 0;  //
    GpioCtrlRegs.GPADIR.bit.GPIO10 = 1;  // 
	
	GpioDataRegs.GPACLEAR.bit.GPIO11 = 1;  //
    GpioCtrlRegs.GPAMUX1.bit.GPIO11 = 0;  //
    GpioCtrlRegs.GPADIR.bit.GPIO11 = 1;  //  

// TZ_INT
   GpioCtrlRegs.GPAPUD.bit.GPIO12 = 0;   // TZ1
   GpioCtrlRegs.GPAPUD.bit.GPIO13 = 0;   // TZ2
   GpioCtrlRegs.GPAQSEL1.bit.GPIO12 = 1;
   GpioCtrlRegs.GPAQSEL1.bit.GPIO13 = 1;
   GpioCtrlRegs.GPAMUX1.bit.GPIO12 = 1;
   GpioCtrlRegs.GPAMUX1.bit.GPIO13 = 1;

//AD7606
   GpioCtrlRegs.GPAPUD.bit.GPIO14 = 0;    // AD1BUSY
   GpioCtrlRegs.GPAPUD.bit.GPIO15 = 0;    // XHOLD_ADCON
   GpioCtrlRegs.GPAQSEL1.bit.GPIO14 = 3;
   GpioCtrlRegs.GPAMUX1.bit.GPIO14 = 0;
   GpioCtrlRegs.GPAMUX1.bit.GPIO15 = 0;
   GpioDataRegs.GPACLEAR.bit.GPIO15 = 1;
   GpioCtrlRegs.GPADIR.bit.GPIO15 = 1;
   GpioCtrlRegs.GPADIR.bit.GPIO14 = 0;

   GpioCtrlRegs.GPBPUD.bit.GPIO60 = 0;  //ADRES
   GpioCtrlRegs.GPBMUX2.bit.GPIO60 = 0;
   GpioDataRegs.GPBCLEAR.bit.GPIO60 = 1;
   GpioCtrlRegs.GPBDIR.bit.GPIO60 = 1;
//CAN
   GpioCtrlRegs.GPAPUD.bit.GPIO16 = 1;// CANTXB)
   GpioCtrlRegs.GPAPUD.bit.GPIO17 = 0;// CANRXB)
   GpioCtrlRegs.GPAQSEL2.bit.GPIO17 = 3; //
   GpioCtrlRegs.GPAMUX2.bit.GPIO16 = 2;  //
   GpioCtrlRegs.GPAMUX2.bit.GPIO17 = 2;  //

//SCI_B
   GpioCtrlRegs.GPAPUD.bit.GPIO18 = 0;//SCITXDB
   GpioCtrlRegs.GPAPUD.bit.GPIO19 = 0;//SCIRXDB
   GpioCtrlRegs.GPAQSEL2.bit.GPIO19 = 3;
   GpioCtrlRegs.GPAMUX2.bit.GPIO18 = 2;
   GpioCtrlRegs.GPAMUX2.bit.GPIO19 = 2;

// CHOOSE USB/NET
    GpioCtrlRegs.GPAPUD.bit.GPIO20 = 0;  // CHOOSE USB/NET
	GpioCtrlRegs.GPAMUX2.bit.GPIO20 = 0;
	GpioDataRegs.GPACLEAR.bit.GPIO20 = 1;
    GpioCtrlRegs.GPADIR.bit.GPIO20 = 1;

//CH376_INT
	GpioCtrlRegs.GPAPUD.bit.GPIO21 = 0;  //CH376_INT
    GpioCtrlRegs.GPAQSEL2.bit.GPIO21 = 3;
    GpioCtrlRegs.GPAMUX2.bit.GPIO21 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO21= 0;

//CH395_INT
	GpioCtrlRegs.GPAPUD.bit.GPIO22 = 0;  //CH395_INT
    GpioCtrlRegs.GPAQSEL2.bit.GPIO22 = 3;
    GpioCtrlRegs.GPAMUX2.bit.GPIO22 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO22= 0;

//CAP1-6
	GpioCtrlRegs.GPAPUD.bit.GPIO24 = 0; //CAP1
	GpioCtrlRegs.GPAPUD.bit.GPIO25 = 0; //APWM1
	GpioCtrlRegs.GPAPUD.bit.GPIO26 = 0; //APWM2
	GpioCtrlRegs.GPAPUD.bit.GPIO27 = 0; //CAP2
	GpioCtrlRegs.GPAQSEL2.bit.GPIO24 = 1;
	GpioCtrlRegs.GPAQSEL2.bit.GPIO25 = 1;
	GpioCtrlRegs.GPAQSEL2.bit.GPIO26 = 1;
	GpioCtrlRegs.GPAQSEL2.bit.GPIO27 = 1;
	GpioCtrlRegs.GPAMUX2.bit.GPIO24 = 1;
	GpioCtrlRegs.GPAMUX2.bit.GPIO25 = 1;
	GpioCtrlRegs.GPAMUX2.bit.GPIO26 = 1;
	GpioCtrlRegs.GPAMUX2.bit.GPIO27 = 1;
//EEPROM
    GpioCtrlRegs.GPBPUD.bit.GPIO32 = 0;   // SCL
	GpioCtrlRegs.GPBQSEL1.bit.GPIO32 = 1;  // SDA
    GpioCtrlRegs.GPBMUX1.bit.GPIO32 = 0;
   
    GpioCtrlRegs.GPBPUD.bit.GPIO33 = 0;
    GpioDataRegs.GPBSET.bit.GPIO33 = 1;
    GpioCtrlRegs.GPBMUX1.bit.GPIO33 = 0;
    GpioCtrlRegs.GPBDIR.bit.GPIO33 = 1;

//485_EN
	GpioCtrlRegs.GPBPUD.bit.GPIO34 =1;//485_EN
    GpioCtrlRegs.GPBMUX1.bit.GPIO34=0;
	GpioCtrlRegs.GPBDIR.bit.GPIO34=1;
    GpioDataRegs.GPBCLEAR.bit.GPIO34=1;

//SCI_C
	GpioCtrlRegs.GPBPUD.bit.GPIO36 = 0;//SCIRXDA
	GpioCtrlRegs.GPBPUD.bit.GPIO35 = 0;//SCITXDA
	GpioCtrlRegs.GPBQSEL1.bit.GPIO36 = 3;
	GpioCtrlRegs.GPBMUX1.bit.GPIO36 = 1;
	GpioCtrlRegs.GPBMUX1.bit.GPIO35 = 1;

//QEP
 	GpioCtrlRegs.GPBPUD.bit.GPIO50 = 0;//QEPA
	GpioCtrlRegs.GPBPUD.bit.GPIO51 = 0;//QEPB
	GpioCtrlRegs.GPBPUD.bit.GPIO53 = 0;//QEPS
    GpioCtrlRegs.GPBQSEL2.bit.GPIO50 = 1;
	GpioCtrlRegs.GPBQSEL2.bit.GPIO51 = 1;
	GpioCtrlRegs.GPBQSEL2.bit.GPIO53 = 1;
	GpioCtrlRegs.GPBMUX2.bit.GPIO50 = 1;
	GpioCtrlRegs.GPBMUX2.bit.GPIO51 = 1;
	GpioCtrlRegs.GPBMUX2.bit.GPIO53 = 1;
	GpioCtrlRegs.GPBDIR.bit.GPIO50  = 0;
	GpioCtrlRegs.GPBDIR.bit.GPIO51  = 0;
	GpioCtrlRegs.GPBDIR.bit.GPIO53  = 0;

//SPI
    GpioCtrlRegs.GPBPUD.bit.GPIO54 = 0;//SPI_SIMO
    GpioCtrlRegs.GPBPUD.bit.GPIO55 = 0;//SPI_SOMI
    GpioCtrlRegs.GPBPUD.bit.GPIO56 = 0;//SPI_CLK

    GpioCtrlRegs.GPBQSEL2.bit.GPIO54 = 3;
    GpioCtrlRegs.GPBQSEL2.bit.GPIO55 = 3;
    GpioCtrlRegs.GPBQSEL2.bit.GPIO56 = 3;

	GpioCtrlRegs.GPBMUX2.bit.GPIO54 = 1;
    GpioCtrlRegs.GPBMUX2.bit.GPIO55 = 1;
    GpioCtrlRegs.GPBMUX2.bit.GPIO56 = 1;
//SPICS_CH395
    GpioCtrlRegs.GPBPUD.bit.GPIO57 = 0;// CH395_CS
	GpioCtrlRegs.GPBMUX2.bit.GPIO57 = 0;
	GpioDataRegs.GPBSET.bit.GPIO57 = 1;
    GpioCtrlRegs.GPBDIR.bit.GPIO57 = 1;
//SPICS_CH376
    GpioCtrlRegs.GPBPUD.bit.GPIO52 = 0;//CH376_CS
	GpioCtrlRegs.GPBMUX2.bit.GPIO52 = 0;
	GpioDataRegs.GPBSET.bit.GPIO52 = 1;
    GpioCtrlRegs.GPBDIR.bit.GPIO52 = 1;

//LCD128_64
    GpioCtrlRegs.GPBPUD.bit.GPIO58 = 0;   //LCD_CLK
    GpioCtrlRegs.GPBPUD.bit.GPIO61 = 0;   //LCDSID
    GpioCtrlRegs.GPBMUX2.bit.GPIO58 = 0;
    GpioCtrlRegs.GPBMUX2.bit.GPIO61 = 0;
    GpioCtrlRegs.GPBMUX2.bit.GPIO59 = 0;//LCDCS
    GpioCtrlRegs.GPBPUD.bit.GPIO60 = 0; //LCDRST
	GpioDataRegs.GPBSET.bit.GPIO60 = 1;
	GpioCtrlRegs.GPBMUX2.bit.GPIO60 = 0;
	GpioCtrlRegs.GPBDIR.bit.GPIO60 = 1;
//SCI_C
	GpioCtrlRegs.GPBPUD.bit.GPIO62 = 0; //RXDC
	GpioCtrlRegs.GPBPUD.bit.GPIO63 = 0;	//TXDC
	GpioCtrlRegs.GPBQSEL2.bit.GPIO62 = 3;
	GpioCtrlRegs.GPBMUX2.bit.GPIO62 = 1;
	GpioCtrlRegs.GPBMUX2.bit.GPIO63 = 1;
//XD0-15
 	GpioCtrlRegs.GPCMUX1.bit.GPIO64 = 3;  // XD15
    GpioCtrlRegs.GPCMUX1.bit.GPIO65 = 3;  // XD14
    GpioCtrlRegs.GPCMUX1.bit.GPIO66 = 3;  // XD13
    GpioCtrlRegs.GPCMUX1.bit.GPIO67 = 3;  // XD12
    GpioCtrlRegs.GPCMUX1.bit.GPIO68 = 3;  // XD11
    GpioCtrlRegs.GPCMUX1.bit.GPIO69 = 3;  // XD10
    GpioCtrlRegs.GPCMUX1.bit.GPIO70 = 3;  // XD19
    GpioCtrlRegs.GPCMUX1.bit.GPIO71 = 3;  // XD8
    GpioCtrlRegs.GPCMUX1.bit.GPIO72 = 3;  // XD7
    GpioCtrlRegs.GPCMUX1.bit.GPIO73 = 3;  // XD6
    GpioCtrlRegs.GPCMUX1.bit.GPIO74 = 3;  // XD5
    GpioCtrlRegs.GPCMUX1.bit.GPIO75 = 3;  // XD4
    GpioCtrlRegs.GPCMUX1.bit.GPIO76 = 3;  // XD3
    GpioCtrlRegs.GPCMUX1.bit.GPIO77 = 3;  // XD2
    GpioCtrlRegs.GPCMUX1.bit.GPIO78 = 3;  // XD1
    GpioCtrlRegs.GPCMUX1.bit.GPIO79 = 3;  // XD0

//XA0-19
    GpioCtrlRegs.GPBMUX1.bit.GPIO40 = 3;  // XA0/XWE1n
    GpioCtrlRegs.GPBMUX1.bit.GPIO41 = 3;  // XA1
    GpioCtrlRegs.GPBMUX1.bit.GPIO42 = 3;  // XA2
    GpioCtrlRegs.GPBMUX1.bit.GPIO43 = 3;  // XA3
    GpioCtrlRegs.GPBMUX1.bit.GPIO44 = 3;  // XA4
    GpioCtrlRegs.GPBMUX1.bit.GPIO45 = 3;  // XA5
    GpioCtrlRegs.GPBMUX1.bit.GPIO46 = 3;  // XA6
    GpioCtrlRegs.GPBMUX1.bit.GPIO47 = 3;  // XA7
    GpioCtrlRegs.GPCMUX2.bit.GPIO80 = 3;  // XA8
    GpioCtrlRegs.GPCMUX2.bit.GPIO81 = 3;  // XA9
    GpioCtrlRegs.GPCMUX2.bit.GPIO82 = 3;  // XA10
    GpioCtrlRegs.GPCMUX2.bit.GPIO83 = 3;  // XA11
    GpioCtrlRegs.GPCMUX2.bit.GPIO84 = 3;  // XA12
    GpioCtrlRegs.GPCMUX2.bit.GPIO85 = 3;  // XA13
    GpioCtrlRegs.GPCMUX2.bit.GPIO86 = 3;  // XA14
    GpioCtrlRegs.GPCMUX2.bit.GPIO87 = 3;  // XA15
    GpioCtrlRegs.GPBMUX1.bit.GPIO39 = 3;  // XA16
    GpioCtrlRegs.GPAMUX2.bit.GPIO31 = 3;  // XA17
    GpioCtrlRegs.GPAMUX2.bit.GPIO30 = 3;  // XA18
    GpioCtrlRegs.GPAMUX2.bit.GPIO29 = 3;  // XA19
    GpioCtrlRegs.GPBMUX1.bit.GPIO38 = 3;  // XWE0
    GpioCtrlRegs.GPBMUX1.bit.GPIO37 = 3;  // XZCS7
    GpioCtrlRegs.GPAMUX2.bit.GPIO28 = 3;  // XZCS6 
	EDIS;
}	
	
//===========================================================================
// End of file.
//===========================================================================
