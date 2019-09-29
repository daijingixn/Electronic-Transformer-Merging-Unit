/****************************************Copyright (c)**************************************************
**                       		     
**
**                              
**
**--------------文件信息--------------------------------------------------------------------------------
**文   件   名: user_macro.h
**创   建   人: 
**最后修改日期: 
**描        述: 变流器宏函数定义文件
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
#ifndef DCDC_macro_H
#define DCDC_macro_H

#ifdef __cplusplus
extern "C" {
#endif


#define	M_EnXint1() 		(XIntruptRegs.XINT1CR.bit.ENABLE=1)

#define	M_DisXint1() 		(XIntruptRegs.XINT1CR.bit.ENABLE=0)



#define M_ClrXint1()    	(PieCtrlRegs.PIEIFR1.bit.INTx4=0)

#define	M_ClrCap2IFR()		(EvaRegs.EVAIFRC.all = BIT1)
#define	M_ClrT2ofIFR()		(EvaRegs.EVAIFRB.all = BIT3)

#define	M_ClrCap5IFR()		(EvbRegs.EVBIFRC.all = BIT1)
#define	M_ClrT4ofIFR()		(EvbRegs.EVBIFRB.all = BIT3)

//#define M_StartCpuTimer0()  (CpuTimer0Regs.TCR.bit.TSS = 0)
//#define M_StopCpuTimer0()   (CpuTimer0Regs.TCR.bit.TSS = 1)

//#define	M_StartTimer1()		(EvaRegs.T1CON.bit.TENABLE=1)
//#define	M_StopTimer1()		(EvaRegs.T1CON.bit.TENABLE=0)

//#define	M_StartTimer2()		(EvaRegs.T2CON.bit.TENABLE=1)
//#define	M_StopTimer2()		(EvaRegs.T2CON.bit.TENABLE=0)

//#define	M_StartTimer3()		(EvbRegs.T3CON.bit.TENABLE=1)
//#define	M_StopTimer3()		(EvbRegs.T3CON.bit.TENABLE=0)

//#define	M_StartTimer4()		(EvbRegs.T4CON.bit.TENABLE=1)
//#define	M_StopTimer4()		(EvbRegs.T4CON.bit.TENABLE=0)

#define	M_ChkT1Direction()	(EPwm1Regs.TBSTS.all&BIT0)
#define	M_ChkT3Direction()	(EPwm4Regs.TBSTS.all&BIT0)

//#define	M_ClrCnt(x)			(*timer_cnt[x] =0)
/*********************************************************************************************************
** 函数名称: M_TimerDelay
** 功能描述: 计时器值加1
** 输　入: 	 计时器的值
** 输　出:   计时器加1后的值
** 注  释: 	 
**-------------------------------------------------------------------------------------------------------
** 作　者: 
** 日　期: 
**-------------------------------------------------------------------------------------------------------
** 修改人:
** 日　期:
**------------------------------------------------------------------------------------------------------
***********************************************************************************************/

#define	M_TimerDelay(x)		(x+1)

/*********************************************************************************************************
** 函数名称: M_ChkFlag
** 功能描述: 检查计时器的值
** 输　入: 	 计时器的值
** 输　出:   若计时已到则返回值>=0,否则返回值<0
** 注  释: 	 
**-------------------------------------------------------------------------------------------------------
** 作　者: 
** 日　期: 
**-------------------------------------------------------------------------------------------------------
** 修改人:
** 日　期:
**------------------------------------------------------------------------------------------------------
***********************************************************************************************/

#define	M_ChkCounter(x,y)	((int32)(x-y))

/*********************************************************************************************************
** 函数名称: M_ChkFlag
** 功能描述: 检查标志位的值
** 输　入: 	 待检查的标志位
** 输　出:   若该标志位为1则返回值!=0,否则返回值=0
** 注  释: 	 
**-------------------------------------------------------------------------------------------------------
** 作　者: 
** 日　期: 
**-------------------------------------------------------------------------------------------------------
** 修改人:
** 日　期:
**------------------------------------------------------------------------------------------------------
***********************************************************************************************/

#define	M_ChkFlag(x)		(flag[(x & 0xF0)>>4] &(((Uint16)0x0001)<<(x & 0x0F)))

/*********************************************************************************************************
** 函数名称: M_SetFlag
** 功能描述: 将标志位置位
** 输　入: 	 待置位的标志位
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

#define	M_SetFlag(x)		(flag[(x & 0xF0)>>4] |= (((Uint16)0x0001)<<(x & 0x0F)))

/*********************************************************************************************************
** 函数名称: M_ClrFlag
** 功能描述: 清空标志位
** 输　入: 	 待清空的标志位
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

#define	M_ClrFlag(x)		(flag[(x & 0xF0)>>4] &=~ (((Uint16)0x0001)<<(x & 0x0F)))

/*********************************************************************************************************
** 函数名称: M_NotFlag
** 功能描述: 将标志位取反
** 输　入: 	 待取反的标志位
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

#define	M_NotFlag(x)		(flag[(x & 0xF0)>>4] ^= (((Uint16)0x0001)<<(x & 0x0F)))

/*********************************************************************************************************
** 函数名称: M_SetBit M_ClrBit M_TurnBit
** 功能描述:  位置1   位清0   位取反
** 输　入: 	 x 目标数据；y 相应位
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
#define M_SetBit(x,y)	((x) |= (y))
#define M_ClrBit(x,y)	((x) &=~ (y))
#define M_TurnBit(x,y)	((x) ^= (y))
/*********************************************************************************************************
** 函数名称: M_SetFlag
** 功能描述: 将标志位置位
** 输　入: 	 待置位的标志位
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

#define	M_Setdisp(x)		(disp[(x & 0xF0)>>4] |= (((Uint16)0x0001)<<(x & 0x0F)))

/*********************************************************************************************************
** 函数名称: M_ClrFlag
** 功能描述: 清空标志位
** 输　入: 	 待清空的标志位
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

#define	M_Clrdisp(x)		(disp[(x & 0xF0)>>4] &=~ (((Uint16)0x0001)<<(x & 0x0F)))

/*********************************************************************************************************
** 函数名称: M_NotFlag
** 功能描述: 将标志位取反
** 输　入: 	 待取反的标志位
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

#define	M_Notdisp(x)		(disp[(x & 0xF0)>>4] ^= (((Uint16)0x0001)<<(x & 0x0F)))


#define M_EN485RXD()		(GpioDataRegs.GPBCLEAR.bit.GPIO34 = 1)

// 485发送允许
#define M_EN485TXD()		(GpioDataRegs.GPBSET.bit.GPIO34 = 1)

//-----SCIB
#define	M_DisTxRxb()		(SciaRegs.SCICTL1.all=0x0000)			// Disable TX RX

#define	M_EnTxb()			(SciaRegs.SCICTL1.all=0x0002)			// Enable TX, disable RX
#define	M_EnTxbInt()		(SciaRegs.SCIFFTX.bit.TXFFIENA=1)		// Enable TXINT, disable RXINT
#define	M_DisTxbInt()		(SciaRegs.SCIFFTX.bit.TXFFIENA=0)		// Disable TXINT RXINT
//#define	M_TxbFifoRst0()		(ScibRegs.SCIFFTX.bit.TXFIFOXRESET=0)	// 0=Reset FIFO
//#define	M_TxbFifoRst1()		(ScibRegs.SCIFFTX.bit.TXFIFOXRESET=1)	// 1=Normal
#define	M_ClrTxFifoInt()	(SciaRegs.SCIFFTX.bit.TXINTCLR=1)		// Clear Interrupt flag

#define	M_EnRxb()			(SciaRegs.SCICTL1.all=0x0001)			// Enable RX, disable TX
#define	M_EnRxbInt()		(SciaRegs.SCIFFRX.bit.RXFFIENA=1)		// Enable RXINT, disable TXINT
#define	M_DisRxbInt()		(SciaRegs.SCIFFRX.bit.RXFFIENA=0)		// Disable TXINT RXINT
//#define	M_RxbFifoRst0()		(ScibRegs.SCIFFRX.bit.RXFIFORESET=0)	// 0=Reset FIFO
//#define	M_RxbFifoRst1()		(ScibRegs.SCIFFRX.bit.RXFIFORESET=1)	// 1=Normal    
#define	M_ClrRxFifoInt()	(SciaRegs.SCIFFRX.bit.RXFFINTCLR=1)		// Clear Interrupt flag

#define	M_ClrRxFifoOvr()	(SciaRegs.SCIFFRX.bit.RXFFOVRCLR=1)  	// Clear Overflow flag

//#define M_CALUND(x,y)        (x*y+x*x)
//#define M_CALUSD(x,y)		 (x*x+y*y)

#define M_ClrQepPCO()		(EQep2Regs.QCLR.bit.PCO = 1)
#define M_ClrQepPHE()		(EQep2Regs.QCLR.bit.PHE = 1)
				 
#ifdef __cplusplus
}
#endif /* extern "C" */

#endif
//===========================================================================
// No more.
//===========================================================================
