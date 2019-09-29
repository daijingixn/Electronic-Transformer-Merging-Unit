

/*================================================================================
CH395 TCP/IP 协议族接口
MSC51 演示程序，演示4个socket 分别使用UDP,TCP Client,TCP Server以及IP RAW ,单片机
收到数据后，按位取反后上传。MCS51@24MHZ,KEIL 3.51
=================================================================================*/
/* 头文件包含*/
#include "stdio.h"
#include "string.h"
#include "CH395INC.H"
#include "CH395.H"
#include "ch395cmd.h"
#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File
/* 常用变量定义 */
struct _SCOK_INF  ScokInf;                                   		/* 保存Socket信息 */
struct _CH395_SYS  CH395Inf;                                   		/* 保存CH395信息 */
/* CH395相关定义 */
//const UINT8 CH395MACAddr[6] = {0x02,0x03,0x04,0x05,0x06,0x07};    /* CH395MAC地址 */
const UINT8 CH395IPAddr[4] = {192,168,16,11};                       /* CH395IP地址 */
const UINT8 CH395GWIPAddr[4] = {192,168,16,1};                      /* CH395网关 */
const UINT8 CH395IPMask[4] = {255,255,255,0};                       /* CH395子网掩码 */

/* socket 相关定义,为方便演示，socket0-2定义了源端口和目的端口,socket3 */
/* 为IP RAW，需要定义IP 协议字段的协议类型 */
const UINT8  Socket0DesIP[4] = {192,168,16,10};                      /* Socket 0目的IP地址 */
const UINT16 Socket0DesPort = 2000;                                  /* Socket 0目的端口 */
const UINT16 Socket0SourPort = 5000;                                 /* Socket 0源端口 */
#define CH395_INT_WIRE              GpioDataRegs.GPADAT.bit.GPIO22                             /* CH395的INT#引脚 */
unsigned char MyBuffer[100];

  void xEndCH395Cmd(void)
  { 
  GpioDataRegs.GPBSET.bit.GPIO57=1;
  } 
  void xCH395CmdStart(void )    
  { 
   GpioDataRegs.GPBCLEAR.bit.GPIO57=1;
  }
/*==============================================================================
* Function Name  : CH395_PORT_INIT
* Description    : 硬件初始化部分
* Input          : None
* Output         : None
* Return         : None
==============================================================================*/
void CH395_PORT_INIT(void)
{
    SpiaRegs.SPIBRR=0x0005;
    SpiaRegs.SPISTS.all=0x0000;                 // Baud rate 3.75M
    SpiaRegs.SPIPRI.all=0x0001;             // stop immediately                                         //--DA7614工作时SPI的设置: 无延迟的下降沿方式(时钟的初始态为高),16 bit data
    SpiaRegs.SPICCR.all=0x0047;             // initialize spi,output at falling edge, 16 bit data
    SpiaRegs.SPICTL.all=0x0006;             // Master,normal phase, enable transmission
    SpiaRegs.SPICCR.all=0x00c7;

}
/*******************************************************************************
* Function Name  : Spi395Exchange
* Description    : 硬件SPI输出且输入8个位数据
* Input          : d---将要送入到CH395的数据
* Output         : None
* Return         : None
*******************************************************************************/
UINT8 Spi395Exchange( UINT8 d )
{  
    UINT8  RES1;
    SpiaRegs.SPITXBUF=d<<8;  /* 先将数据写入SPI数据寄存器,然后查询SPI状态寄存器以等待*/                         
    while(SpiaRegs.SPISTS.bit.INT_FLAG==0){}  /* 查询SPI状态寄存器的标志位以等待SPI字节传输完成数据,发送完成标志位置1*/
    RES1=(UINT8)SpiaRegs.SPIRXBUF;
    return(RES1);     /*从SPI数据寄存器读出数据*/                              
}

/*==============================================================================
* Function Name  : xWriteCH395Cmd
* Description    : 向CH395写命令
* Input          : cmd 8位的命令码
* Output         : None
* Return         : None
==============================================================================*/
void xWriteCH395Cmd(UINT8 cmd)
{                                                                    
    xEndCH395Cmd();                                                  /* 防止CS原来为低，先将CD置高 */
    xCH395CmdStart( );                                               /* 命令开始，CS拉低 */
    Spi395Exchange(cmd);                                             /* SPI发送命令码 */
    DELAY_US(2L);                                                    /* 必要延时,延时1.5uS确保读写周期不小于1.5uS */
}

/*==============================================================================
* Function Name  : xWriteCH395Data
* Description    : 向CH395写数据
* Input          : mdata 8位数据
* Output         : None
* Return         : None
==============================================================================*/
void  xWriteCH395Data(UINT8 mdata)
{   
    Spi395Exchange(mdata);                                           /* SPI发送数据 */
}

/*==============================================================================
* Function Name  : xReadCH395Data
* Description    : 从CH395读数据
* Input          : None
* Output         : None
* Return         : 8位数据
==============================================================================*/
UINT8   xReadCH395Data( void )
{
    UINT8 i;
    i = Spi395Exchange(0xff);                                        /* SPI读数据 */
    return i;
}
/*==============================================================================
* Function Name  : mStopIfError
* Description    : 调试使用，显示错误代码，并停机
* Input          : iError   错误代码
* Output         : None
* Return         : None
==============================================================================*/
void mStopIfError(UINT8 iError)
{
    if (iError == CMD_ERR_SUCCESS) return;                           /* 操作成功 */
    DELAY_US(1L);
    while ( 1 )
    {
        DELAY_US(200000L);
        DELAY_US(200000L);
    }
}
/*==============================================================================
* Function Name  : CH395CMDReset
* Description    : 复位CH395芯片
* Input          : None
* Output         : None
* Return         : None
==============================================================================*/
void CH395CMDReset(void)
{
    xWriteCH395Cmd(CMD00_RESET_ALL);
    xEndCH395Cmd();
    DELAY_US(60000L);
}

/*==============================================================================
* Function Name  : CH395CMDSleep
* Description    : 使CH395进入睡眠状态
* Input          : None
* Output         : None
* Return         : None
==============================================================================*/
void CH395CMDSleep(void)
{
    xWriteCH395Cmd(CMD00_ENTER_SLEEP);
    xEndCH395Cmd();
}

/*==============================================================================
* Function Name  : CH395CMDSleep
* Description    : 获取芯片以及固件版本号，1字节，高四位表示芯片版本，
                   低四位表示固件版本
* Input          : None
* Output         : None
* Return         : 1字节芯片及固件版本号
==============================================================================*/
UINT8 CH395CMDGetVer(void)
{
    UINT8 i;

    xWriteCH395Cmd(CMD01_GET_IC_VER);
    i = xReadCH395Data();
    xEndCH395Cmd();
    return i;
}

/*==============================================================================
* Function Name  : CH395CMDCheckExist
* Description    : 测试命令，用于测试硬件以及接口通讯
* Input          : testdata 1字节测试数据
* Output         : None
* Return         : 硬件OK，返回 testdata按位取
==============================================================================*/
UINT8 CH395CMDCheckExist(UINT8 testdata)
{
    UINT8 i;

    xWriteCH395Cmd(CMD11_CHECK_EXIST);
    xWriteCH395Data(testdata);
    i = xReadCH395Data();
    xEndCH395Cmd();
    return i;
}

/*==============================================================================
* Function Name  : CH395CMDSetPHY
* Description    : 设置PHY，主要设置CH395 PHY为100/10M 或者全双工半双工，CH395默
                    为自动协商。
* Input          : phystat 参考PHY 命令参数/状态
* Output         : None
* Return         : None
==============================================================================*/
void CH395CMDSetPHY(UINT8 phystat)
{
    xWriteCH395Cmd(CMD10_SET_PHY);
    xWriteCH395Data(phystat);
    xEndCH395Cmd();
}

/*==============================================================================
* Function Name  : CH395CMDGetPHYStatus
* Description    : 获取PHY的状态
* Input          : None
* Output         : None
* Return         : 当前CH395PHY状态，参考PHY参数/状态定义
==============================================================================*/
UINT8 CH395CMDGetPHYStatus(void)
{
    UINT8 i;

    xWriteCH395Cmd(CMD01_GET_PHY_STATUS);
    i = xReadCH395Data();
    xEndCH395Cmd();
    return i;
}

/*==============================================================================
* Function Name  : CH395CMDGetGlobIntStatus
* Description    : 获取全局中断状态，收到此命令CH395自动取消中断
* Input          : None
* Output         : None
* Return         : 返回当前的全局中断状态
==============================================================================*/
UINT8 CH395CMDGetGlobIntStatus(void)
{
    UINT8 init_status;

    xWriteCH395Cmd(CMD01_GET_GLOB_INT_STATUS);
    init_status = xReadCH395Data();
    xEndCH395Cmd();
    return  init_status;
}

/*==============================================================================
* Function Name  : CH395CMDInitCH395
* Description    : 初始化CH395芯片。
* Input          : None
* Output         : None
* Return         : 返回执行结果
==============================================================================*/
UINT8 CH395CMDInitCH395(void)
{
    UINT8 i = 0;
    UINT8 s = 0;

    xWriteCH395Cmd(CMD0W_INIT_CH395);
    xEndCH395Cmd();
    while(1)
    {
        DELAY_US(5000L);                                                 /* 延时查询，建议2MS以上*/
        s = CH395GetCmdStatus();                                     /* 不能过于频繁查询*/
        if(s !=CH395_ERR_BUSY)break;                                 /* 如果CH395芯片返回忙状态*/
        if(i++ > 200)return CH395_ERR_UNKNOW;                        /* 超时退出,本函数需要500MS以上执行完毕 */
    }
    return s;
}

/*==============================================================================
* Function Name  : CH395CMDSetUartBaudRate
* Description    : 设置CH395串口波特率，仅在串口模式下有效
* Input          : baudrate 串口波特率
* Output         : None
* Return         : None
==============================================================================*/
void CH395CMDSetUartBaudRate(UINT32 baudrate)
{
    xWriteCH395Cmd(CMD31_SET_BAUDRATE);
    xWriteCH395Data((UINT8)baudrate);
    xWriteCH395Data((UINT8)((UINT16)baudrate >> 8));
    xWriteCH395Data((UINT8)(baudrate >> 16));
    xEndCH395Cmd();
}

/*==============================================================================
* Function Name  : CH395GetCmdStatus
* Description    : 获取命令执行状态，某些命令需要等待命令执行结果
* Input          : None
* Output         : None
* Return         : 返回上一条命令执行状态
==============================================================================*/
UINT8 CH395GetCmdStatus(void)
{
    UINT8 i;

    xWriteCH395Cmd(CMD01_GET_CMD_STATUS);
    i = xReadCH395Data();
    xEndCH395Cmd();
    return i;
}

/*==============================================================================
* Function Name  : CH395CMDSetIPAddr
* Description    : 设置CH395的IP地址
* Input          : ipaddr 指IP地址
* Output         : None
* Return         : None
==============================================================================*/
void CH395CMDSetIPAddr(UINT8 *ipaddr)
{
    UINT8 i;

    xWriteCH395Cmd(CMD40_SET_IP_ADDR);
    for(i = 0; i < 4;i++)xWriteCH395Data(*ipaddr++);
    xEndCH395Cmd();
}

/*==============================================================================
* Function Name  : CH395CMDSetGWIPAddr
* Description    : 设置CH395的网关IP地址
* Input          : ipaddr 指向网关IP地址
* Output         : None
* Return         : None
==============================================================================*/
void CH395CMDSetGWIPAddr(UINT8 *gwipaddr)
{
    UINT8 i;

    xWriteCH395Cmd(CMD40_SET_GWIP_ADDR);
    for(i = 0; i < 4;i++)xWriteCH395Data(*gwipaddr++);
    xEndCH395Cmd();
}

/*==============================================================================
* Function Name  : CH395CMDSetMASKAddr
* Description    : 设置CH395的子网掩码，默认为255.255.255.0
* Input          : maskaddr 指子网掩码地址
* Output         : None
* Return         : None
==============================================================================*/
void CH395CMDSetMASKAddr(UINT8 *maskaddr)
{
    UINT8 i;

    xWriteCH395Cmd(CMD40_SET_MASK_ADDR);
    for(i = 0; i < 4;i++)xWriteCH395Data(*maskaddr++);
    xEndCH395Cmd();
}

/*==============================================================================
* Function Name  : CH395CMDSetMACAddr
* Description    : 设置CH395的MAC地址。
* Input          : amcaddr MAC地址指针
* Output         : None
* Return         : None
==============================================================================*/
void CH395CMDSetMACAddr(UINT8 *amcaddr)
{
    UINT8 i;

    xWriteCH395Cmd(CMD60_SET_MAC_ADDR);
    for(i = 0; i < 6;i++)xWriteCH395Data(*amcaddr++);
    xEndCH395Cmd();
     DELAY_US(100000L); ;
}

/*==============================================================================
* Function Name  : CH395CMDGetMACAddr
* Description    : 获取CH395的MAC地址。
* Input          : amcaddr MAC地址指针
* Output         : None
* Return         : None
==============================================================================*/
void CH395CMDGetMACAddr(UINT8 *amcaddr)
{
    UINT8 i;

    xWriteCH395Cmd(CMD06_GET_MAC_ADDR);
    for(i = 0; i < 6;i++)*amcaddr++ = xReadCH395Data();
    xEndCH395Cmd();
 }

/*==============================================================================
* Function Name  : CH395CMDSetMACFilt
* Description    : 设置MAC过滤。
* Input          : filtype 参考 MAC过滤
                   table0 Hash0
                   table1 Hash1
* Output         : None
* Return         : None
==============================================================================*/
void CH395CMDSetMACFilt(UINT8 filtype,UINT32 table0,UINT32 table1)
{
    xWriteCH395Cmd(CMD90_SET_MAC_FILT);
    xWriteCH395Data(filtype);
    xWriteCH395Data((UINT8)table0);
    xWriteCH395Data((UINT8)((UINT16)table0 >> 8));
    xWriteCH395Data((UINT8)(table0 >> 16));
    xWriteCH395Data((UINT8)(table0 >> 24));

    xWriteCH395Data((UINT8)table1);
    xWriteCH395Data((UINT8)((UINT16)table1 >> 8));
    xWriteCH395Data((UINT8)(table1 >> 16));
    xWriteCH395Data((UINT8)(table1 >> 24));
    xEndCH395Cmd();
}

/*==============================================================================
* Function Name  : CH395CMDGetUnreachIPPT
* Description    : 获取不可达信息 (IP,Port,Protocol Type)
* Input          : list 保存获取到的不可达
                        第1个字节为不可达代码，请参考 不可达代码(CH395INC.H)
                        第2个字节为IP包协议类型
                        第3-4字节为端口号
                        第4-8字节为IP地址
* Output         : None
* Return         : None
==============================================================================*/
void CH395CMDGetUnreachIPPT(UINT8 *list)
{
    UINT8 i;

    xWriteCH395Cmd(CMD08_GET_UNREACH_IPPORT);
    for(i = 0; i < 8; i++)
    {
        *list++ = xReadCH395Data();
    }   
    xEndCH395Cmd();
}

/*==============================================================================
* Function Name  : CH395CMDGetRemoteIPP
* Description    : 获取远端的IP和端口地址，一般在TCP Server模式下使用
* Input          : sockindex Socket索引
                   list 保存IP和端口
* Output         : None
* Return         : None
==============================================================================*/
void CH395CMDGetRemoteIPP(UINT8 sockindex,UINT8 *list)
{
    UINT8 i;

    xWriteCH395Cmd(CMD06_GET_REMOT_IPP_SN);
    xWriteCH395Data(sockindex);
    for(i = 0; i < 6; i++)
    {
        *list++ = xReadCH395Data();
    }
    xEndCH395Cmd();
}

/*==============================================================================
* Function Name  : CH395SetSocketDesIP
* Description    : 设置socket n的目的IP地址
* Input          : sockindex Socket索引
                   ipaddr 指向IP地址
* Output         : None
* Return         : None
==============================================================================*/
void CH395SetSocketDesIP(UINT8 sockindex,UINT8 *ipaddr)
{
    xWriteCH395Cmd(CMD50_SET_IP_ADDR_SN);
    xWriteCH395Data(sockindex);
    xWriteCH395Data(*ipaddr++);
    xWriteCH395Data(*ipaddr++);
    xWriteCH395Data(*ipaddr++);
    xWriteCH395Data(*ipaddr++);
    xEndCH395Cmd();
}

/*==============================================================================
* Function Name  : CH395SetSocketProtType
* Description    : 设置socket 的协议类型
* Input          : sockindex Socket索引
                   prottype 协议类型，请参考 socket协议类型定义(CH395INC.H)
* Output         : None
* Return         : None
==============================================================================*/
void CH395SetSocketProtType(UINT8 sockindex,UINT8 prottype)
{
    xWriteCH395Cmd(CMD20_SET_PROTO_TYPE_SN);
    xWriteCH395Data(sockindex);
    xWriteCH395Data(prottype);
    xEndCH395Cmd();
}

/*==============================================================================
* Function Name  : CH395SetSocketDesPort
* Description    : 设置socket n的协议类型
* Input          : sockindex Socket索引
                   desprot 2字节目的端口
* Output         : None
* Return         : None
==============================================================================*/
void CH395SetSocketDesPort(UINT8 sockindex,UINT16 desprot)
{
    xWriteCH395Cmd(CMD30_SET_DES_PORT_SN);
    xWriteCH395Data(sockindex);
    xWriteCH395Data((UINT8)desprot);
    xWriteCH395Data((UINT8)(desprot >> 8));
    xEndCH395Cmd();
}

/*==============================================================================
* Function Name  : CH395SetSocketSourPort
* Description    : 设置socket n的协议类型
* Input          : sockindex Socket索引
                   desprot 2字节源端口
* Output         : None
* Return         : None
==============================================================================*/
void CH395SetSocketSourPort(UINT8 sockindex,UINT16 surprot)
{
    xWriteCH395Cmd(CMD30_SET_SOUR_PORT_SN);
    xWriteCH395Data(sockindex);
    xWriteCH395Data((UINT8)surprot);
    xWriteCH395Data((UINT8)(surprot>>8));
    xEndCH395Cmd();
}

/*==============================================================================
* Function Name  : CH395SetSocketIPRAWProto
* Description    : IP模式下，socket IP包协议字段
* Input          : sockindex Socket索引
                   prototype IPRAW模式1字节协议字段
* Output         : None
* Return         : None
==============================================================================*/
void CH395SetSocketIPRAWProto(UINT8 sockindex,UINT8 prototype)
{
    xWriteCH395Cmd(CMD20_SET_IPRAW_PRO_SN);
    xWriteCH395Data(sockindex);
    xWriteCH395Data(prototype);
    xEndCH395Cmd();
}

/*==============================================================================
* Function Name  : CH395EnablePing
* Description    : 开启/关闭 PING
* Input          : enable : 1  开启PING
                          ：0  关闭PING
* Output         : None
* Return         : None
==============================================================================*/
void CH395EnablePing(UINT8 enable)
{
    xWriteCH395Cmd(CMD01_PING_ENABLE);
    xWriteCH395Data(enable);
    xEndCH395Cmd();
}

/*==============================================================================
* Function Name  : CH395SendData
* Description    : 向发送缓冲区写数据
* Input          : sockindex Socket索引
                   databuf  数据缓冲区
                   len   长度
* Output         : None
* Return         : None
==============================================================================*/
void CH395SendData(UINT8 sockindex,UINT8 *databuf,UINT16 len)
{
    UINT16 i;

    xWriteCH395Cmd(CMD30_WRITE_SEND_BUF_SN);
    xWriteCH395Data((UINT8)sockindex);
    xWriteCH395Data((UINT8)len);
    xWriteCH395Data((UINT8)(len>>8));
   
    for(i = 0; i < len; i++)
    {
        xWriteCH395Data(*databuf++);
    }
    xEndCH395Cmd();
}

/*==============================================================================
* Function Name  : CH395GetReceLength
* Description    : 获取接收缓冲区长度
* Input          : sockindex Socket索引
* Output         : None
* Return         : 返回接收缓冲区有效长度
==============================================================================*/
UINT16 CH395GetReceLength(UINT8 sockindex)
{
    UINT16 i;

    xWriteCH395Cmd(CMD12_GET_RECV_LEN_SN);
    xWriteCH395Data((UINT8)sockindex);
    i = xReadCH395Data();
    i = (UINT16)(xReadCH395Data()<<8) + i;
    xEndCH395Cmd();
    return i;
}

/*==============================================================================
* Function Name  : CH395ClearRecvBuf
* Description    : 清除接收缓冲区
* Input          : sockindex Socket索引
* Output         : None
* Return         : None
==============================================================================*/
void CH395ClearRecvBuf(UINT8 sockindex)
{
    xWriteCH395Cmd(CMD10_CLEAR_RECV_BUF_SN);
    xWriteCH395Data((UINT8)sockindex);
    xEndCH395Cmd();
}

/*==============================================================================
* Function Name  : CH395GetReceLength
* Description    : 读取接收缓冲区数据
* Input          : sockindex Socket索引
                   len   长度
                   pbuf  缓冲区
* Output         : None
* Return         : None
==============================================================================*/
void CH395GetReceData(UINT8 sockindex,UINT16 len,UINT8 *pbuf)
{
    UINT16 i;
    if(!len)return;
    xWriteCH395Cmd(CMD30_READ_RECV_BUF_SN);
    xWriteCH395Data(sockindex);
    xWriteCH395Data((UINT8)len);
    xWriteCH395Data((UINT8)(len>>8));
    for(i = 0; i < len; i++)
    {
       *pbuf = xReadCH395Data();
       pbuf++;
    }
    xEndCH395Cmd();
}

/*==============================================================================
* Function Name  : CH395CMDSetRetryCount
* Description    : 设置重试次数
* Input          : count 重试值，最大为20次
* Output         : None
* Return         : None
==============================================================================*/
void CH395CMDSetRetryCount(UINT8 count)
{
    xWriteCH395Cmd(CMD10_SET_RETRAN_COUNT);
    xWriteCH395Data(count);
    xEndCH395Cmd();
}

/*==============================================================================
* Function Name  : CH395CMDSetRetryPeriod
* Description    : 设置重试周期
* Input          : period 重试周期单位为毫秒，最大1000ms
* Output         : None
* Return         : None
==============================================================================*/
void CH395CMDSetRetryPeriod(UINT16 period)
{
    xWriteCH395Cmd(CMD10_SET_RETRAN_COUNT);
    xWriteCH395Data((UINT8)period);
    xWriteCH395Data((UINT8)(period>>8));
    xEndCH395Cmd();
}

/*==============================================================================
* Function Name  : CH395CMDGetSocketStatus
* Description    : 获取socket
* Input          : None
* Output         : socket n的状态信息，第1字节为socket 打开或者关闭
                   第2字节为TCP状态
* Return         : None
==============================================================================*/
void CH395CMDGetSocketStatus(UINT8 sockindex,UINT8 *status)
{
    xWriteCH395Cmd(CMD12_GET_SOCKET_STATUS_SN);
    xWriteCH395Data(sockindex);
    *status++ = xReadCH395Data();
    *status++ = xReadCH395Data();
    xEndCH395Cmd();
}

/*==============================================================================
* Function Name  : CH395OpenSocket
* Description    : 打开socket，此命令需要等待执行成功
* Input          : sockindex Socket索引
* Output         : None
* Return         : 返回执行结果
==============================================================================*/
UINT8  CH395OpenSocket(UINT8 sockindex)
{
    UINT8 i = 0;
    UINT8 s = 0;

    xWriteCH395Cmd(CMD1W_OPEN_SCOKET_SN);
    xWriteCH395Data(sockindex);
    xEndCH395Cmd();
    while(1)
    {
        DELAY_US(5000L);                                                 /* 延时查询，建议2MS以上*/
        s = CH395GetCmdStatus();                                     /* 不能过于频繁查询*/
        if(s !=CH395_ERR_BUSY)break;                                 /* 如果CH395芯片返回忙状态*/
        if(i++ > 200)return CH395_ERR_UNKNOW;                        /* 超时退出*/
    }
    return s;
}

/*==============================================================================
* Function Name  : CH395OpenSocket
* Description    : 关闭socket，
* Input          : sockindex Socket索引
* Output         : None
* Return         : 返回执行结果
==============================================================================*/
UINT8  CH395CloseSocket(UINT8 sockindex)
{
    UINT8 i = 0;
    UINT8 s = 0;

    xWriteCH395Cmd(CMD1W_CLOSE_SCOKET_SN);
    xWriteCH395Data(sockindex);
    xEndCH395Cmd();
    while(1)
    {
        DELAY_US(5000L);                                                 /* 延时查询，建议2MS以上*/
        s = CH395GetCmdStatus();                                     /* 不能过于频繁查询*/
        if(s !=CH395_ERR_BUSY)break;                                 /* 如果CH395芯片返回忙状态*/
        if(i++ > 200)return CH395_ERR_UNKNOW;                        /* 超时退出*/
    }
    return s;
}

/*==============================================================================
* Function Name  : CH395TCPConnect
* Description    : TCP连接，仅在TCP模式下有效，此命令需要等待执行成功
* Input          : sockindex Socket索引
* Output         : None
* Return         : 返回执行结果
==============================================================================*/
UINT8 CH395TCPConnect(UINT8 sockindex)
{
    UINT8 i = 0;
    UINT8 s = 0;

    xWriteCH395Cmd(CMD1W_TCP_CONNECT_SN);
    xWriteCH395Data(sockindex);
    xEndCH395Cmd();
    while(1)
    {
        DELAY_US(5000L);                                                 /* 延时查询，建议2MS以上*/
        s = CH395GetCmdStatus();                                     /* 不能过于频繁查询*/
        if(s !=CH395_ERR_BUSY)break;                                 /* 如果CH395芯片返回忙状态*/
        if(i++ > 200)return CH395_ERR_UNKNOW;                        /* 超时退出*/
    }
    return s;
}

/*==============================================================================
* Function Name  : CH395TCPListen
* Description    : TCP监听，仅在TCP模式下有效，此命令需要等待执行成功
* Input          : sockindex Socket索引
* Output         : None
* Return         : 返回执行结果
==============================================================================*/
UINT8 CH395TCPListen(UINT8 sockindex)
{
    UINT8 i = 0;
    UINT8 s = 0;

    xWriteCH395Cmd(CMD1W_TCP_LISTEN_SN);
    xWriteCH395Data(sockindex);
    xEndCH395Cmd();
    while(1)
    {
        DELAY_US(5000L);                                                 /* 延时查询，建议2MS以上*/
        s = CH395GetCmdStatus();                                     /* 不能过于频繁查询*/
        if(s !=CH395_ERR_BUSY)break;                                 /* 如果CH395芯片返回忙状态*/
        if(i++ > 200)return CH395_ERR_UNKNOW;                        /* 超时退出*/
    }
    return s;

}

/*==============================================================================
* Function Name  : CH395TCPDisconnect
* Description    : TCP断开，仅在TCP模式下有效，此命令需要等待执行成功
* Input          : sockindex Socket索引
* Output         : None
* Return         : None
==============================================================================*/
UINT8 CH395TCPDisconnect(UINT8 sockindex)
{
    UINT8 i = 0;
    UINT8 s = 0;

    xWriteCH395Cmd(CMD1W_TCP_DISNCONNECT_SN);
    xWriteCH395Data(sockindex);
    xEndCH395Cmd();

    while(1)
    {
        DELAY_US(5000L);                                                 /* 延时查询，建议2MS以上*/
        s = CH395GetCmdStatus();                                     /* 不能过于频繁查询*/
        if(s !=CH395_ERR_BUSY)break;                                 /* 如果CH395芯片返回忙状态*/
        if(i++ > 200)return CH395_ERR_UNKNOW;                        /* 超时退出*/
    }
    return s;

}

/*==============================================================================
* Function Name  : CH395GetSocketInt
* Description    : 获取socket n的中断状态
* Input          : sockindex   socket索引
* Output         : None
* Return         : 中断状态
==============================================================================*/
UINT8 CH395GetSocketInt(UINT8 sockindex)
{
    UINT8 intstatus;
    xWriteCH395Cmd(CMD11_GET_INT_STATUS_SN);
    xWriteCH395Data(sockindex);
    intstatus = xReadCH395Data();
    xEndCH395Cmd();
    return intstatus;
}

/*==============================================================================
* Function Name  : CH395CRCRet6Bit
* Description    : 对多播地址进行CRC运算，并取高6位。
* Input          : mac_addr   MAC地址
* Output         : None
* Return         : 返回CRC32的高6位
==============================================================================*/
UINT8 CH395CRCRet6Bit(UINT8 *mac_addr)
{
    INT32 perByte;
    INT32 perBit;
    const UINT32 poly = 0x04C11DB7;
    UINT32 crc_value = 0xFFFFFFFF;
    UINT8 c;
    for ( perByte = 0; perByte < 6; perByte ++ )
    {
        c = *(mac_addr++);
        for ( perBit = 0; perBit < 8; perBit++ )
        {
            crc_value = (crc_value<<1)^((((crc_value>>31)^c)&0x01)?poly:0);
            c >>= 1;
        }
    }
    crc_value=crc_value>>26;
    return ((UINT8)crc_value);
}

/****************************endfile@tech9*************************************/
/*==============================================================================
* Function Name  : InitCH395InfParam
* Description    : 初始化CH395Inf参数
* Input          : None
* Output         : None
* Return         : None
==============================================================================*/
void InitCH395InfParam(void)
{
    memset(&CH395Inf,0,sizeof(CH395Inf));                            /* 将CH395Inf全部清零*/
    memcpy(CH395Inf.IPAddr,CH395IPAddr,sizeof(CH395IPAddr));         /* 将IP地址写入CH395Inf中 */
    memcpy(CH395Inf.GWIPAddr,CH395GWIPAddr,sizeof(CH395GWIPAddr));   /* 将网关IP地址写入CH395Inf中 */
    memcpy(CH395Inf.MASKAddr,CH395IPMask,sizeof(CH395IPMask));       /* 将子网掩码写入CH395Inf中 */
//  memcpy(CH395Inf.MacAddr,CH395MACAddr,sizeof(CH395MACAddr));
}

/*==============================================================================
* Function Name  : InitSocketParam
* Description    : 初始化socket
* Input          : None
* Output         : None
* Return         : None
==============================================================================*/
void InitSocketParam(void)
{
    memset(&ScokInf,0,sizeof(ScokInf));                              /* 将ScokInf[0]全部清零*/
    memcpy(ScokInf.IPAddr,Socket0DesIP,sizeof(Socket0DesIP));        /* 将目的IP地址写入 */
    ScokInf.DesPort = Socket0DesPort;                                /* 目的端口 */
    ScokInf.SourPort = Socket0SourPort;                              /* 源端口 */
    ScokInf.ProtoType = PROTO_TYPE_TCP;                              /* TCP模式 */
    ScokInf.TcpMode = TCP_CLIENT_MODE;

}

/*==============================================================================
* Function Name  : CH395SocketInitOpen
* Description    : 配置CH395 socket 参数，初始化并打开socket
* Input          : None
* Output         : None
* Return         : None
==============================================================================*/
void CH395SocketInitOpen(void)
{
 UINT8 i;

    /* socket 0为TCP 客户端模式 */
    CH395SetSocketDesIP(0,ScokInf.IPAddr);                           /* 设置socket 0目标IP地址 */
    CH395SetSocketProtType(0,ScokInf.ProtoType);                     /* 设置socket 0协议类型 */
    CH395SetSocketDesPort(0,ScokInf.DesPort);                        /* 设置socket 0目的端口 */
    CH395SetSocketSourPort(0,ScokInf.SourPort);                      /* 设置socket 0源端口 */
    i = CH395OpenSocket(0);                                          /* 打开socket 0 */
    mStopIfError(i);                                                 /* 检查是否成功 */
    i = CH395TCPConnect(0);                                           /* TCP连接 */
    mStopIfError(i);                                                 /* 检查是否成功 */                                              /* 检查是否成功 */
}

/*==============================================================================
* Function Name  : CH395SocketInterrupt
* Description    : CH395 socket 中断,在全局中断中被调用
* Input          : sockindex  Socket索引
* Output         : None
* Return         : None
==============================================================================*/
void CH395SocketInterrupt(UINT8 sockindex)
{
    UINT8  sock_int_socket;
    UINT8  i;
    UINT16 len;
    UINT16 tmp;
   sock_int_socket = CH395GetSocketInt(sockindex);                   /* 获取socket 的中断状态 */
   sock_int_socket =  SINT_STAT_SENBUF_FREE;
   if(sock_int_socket & SINT_STAT_SENBUF_FREE)                       /* 发送缓冲区空闲，可以继续写入要发送的数据 */
   {
       if(ScokInf.SendLen >= ScokInf.RemLen)ScokInf.RemLen = 0;      /* 数据已经发送完毕 */
       else
       {
            ScokInf.pSend += ScokInf.SendLen;                        /* 对发送指针进行偏移 */
            ScokInf.RemLen -= ScokInf.SendLen;                       /* 计算剩余长度 */
            if(ScokInf.RemLen > 2048)ScokInf.SendLen = 2048;         /* 计算本次可以发送的数据长度 */
            else ScokInf.SendLen = ScokInf.RemLen;
            CH395SendData(sockindex,"888",10); /* 发送数据 */
       }
       CH395SendData(sockindex,"DAI",100); /* 发送数据 */
   }
   if(sock_int_socket & SINT_STAT_SEND_OK)                           /* 发送完成中断 */
   {
   }
   if(sock_int_socket & SINT_STAT_RECV)                              /* 接收中断 */
   {
       len = CH395GetReceLength(sockindex);                          /* 获取当前缓冲区内数据长度 */
       if(len == 0)return;
       if(ScokInf.RemLen != 0)return;                                /* 如果数据未发送完毕，则不再接收 */
       CH395GetReceData(sockindex,len,MyBuffer);                     /* 读取数据 */
       ScokInf.RemLen = len;                                         /* 保存长度 */
       for(tmp =0; tmp < len; tmp++)                                 /* 将所有数据按位取反 */
       {
          MyBuffer[tmp] = MyBuffer[tmp];
       }
       if(len > 2048)len = 2048;                                     /* 发送缓冲区最大为2048 */
       CH395SendData(sockindex,"444",len);
       ScokInf.SendLen = len;                                        /* 保存发送的长度 */
       ScokInf.pSend = MyBuffer;                                     /* 发送换取区指针 */

   }
   if(sock_int_socket & SINT_STAT_CONNECT)                          /* 连接中断，仅在TCP模式下有效*/
   {
    }
   if(sock_int_socket & SINT_STAT_DISCONNECT)                        /* 断开中断，仅在TCP模式下有效 */
   {
       CH395OpenSocket(0);                                          /* 打开socket 0 */
                                              /* 检查是否成功 */
       CH395TCPConnect(0);                                           /* TCP连接 */

   }
   if(sock_int_socket & SINT_STAT_TIM_OUT)                           /* 超时中断，仅在TCP模式下有效 */
   {
       /* 产生超时中断表示连接/发送/接收数据超时或者失败，产生超时时CH395芯片内部将会将此    */
       /* socket关闭，在某些情况下CH395并不会重试连接，例如远端端口未打开，如果CH395连接，则 */
       /* 远端设备可能会发出RST强制将此连接复位，此时CH395仍然会产生超时中断。本程序仅作演示 */
       /* 实际应用中不推荐产生产生超时中断后立即连接，可以间隔一定时间内重新打开socket进行连 */
       /* 即可。*/
       CH395OpenSocket(0);                                          /* 打开socket 0 */
                                                  /* 检查是否成功 */
       CH395TCPConnect(0);                                           /* TCP连接 */

   }
}


/*==============================================================================
* Function Name  : CH395GlobalInterrupt
* Description    : CH395全局中断函数
* Input          : None
* Output         : None
* Return         : None
==============================================================================*/
void CH395GlobalInterrupt(void)
{
   UINT8  init_status;
   UINT16 i;
   UINT8  buf[10];

    init_status = CH395CMDGetGlobIntStatus();
    if(init_status & GINT_STAT_UNREACH)                              /* 不可达中断，读取不可达信息 */
    {
         DELAY_US(1L); //  printf("Init status : GINT_STAT_UNREACH\n");                 /* UDP模式下可能会产生不可达中断 */
        CH395CMDGetUnreachIPPT(buf);                                
    }
    if(init_status & GINT_STAT_IP_CONFLI)                            /* 产生IP冲突中断，建议重新修改CH395的 IP，并初始化CH395*/
    {
    }
    if(init_status & GINT_STAT_PHY_CHANGE)                           /* 产生PHY改变中断*/
    {
        DELAY_US(1L); //// printf("Init status : GINT_STAT_PHY_CHANGE\n");
        i = CH395CMDGetPHYStatus();                                  /* 获取PHY状态 */
        if(i == PHY_DISCONN)  DELAY_US(1L); //printf("Ethernet Disconnect\n");         /* 如果是PHY_DISCONN，CH395内部会自动关闭所有的socket*/
    }
    if(init_status & GINT_STAT_SOCK0)
    {
        CH395SocketInterrupt(0);                                     /* 处理socket 0中断*/
    }
    if(init_status & GINT_STAT_SOCK1)                                /* 本程序实际只用了socket0,该中断不会产生 */
    {
        CH395SocketInterrupt(1);                                     /* 处理socket 1中断*/
    }
    if(init_status & GINT_STAT_SOCK2)                                /* 本程序实际只用了socket0,该中断不会产生 */
    {
        CH395SocketInterrupt(2);                                     /* 处理socket 2中断*/
    }
    if(init_status & GINT_STAT_SOCK3)                                /* 本程序实际只用了socket0,该中断不会产生 */
    {
        CH395SocketInterrupt(3);                                     /* 处理socket 3中断*/
    }
}

/*==============================================================================
* Function Name  : CH395Init
* Description    : 配置CH395的IP,GWIP,MAC等参数，并初始化
* Input          : None
* Output         : None
* Return         : 函数执行结果
==============================================================================*/
UINT8  CH395Init(void)
{
    UINT8 i;

    i = CH395CMDCheckExist(0x65);                      
    if(i != 0x9a)return CH395_ERR_UNKNOW;                            /* 测试命令，如果无法通过返回0XFA */
                                                                     /* 返回0XFA一般为硬件错误或者读写时序不对 */
    CH395CMDSetIPAddr(CH395Inf.IPAddr);                              /* 设置CH395的IP地址 */
//  CH395CMDSetMACAddr(CH395Inf.MacAddr);                            /* 设置CH395的MAC地址 */
    CH395CMDSetGWIPAddr(CH395Inf.GWIPAddr);                          /* 设置网关地址 */
    CH395CMDSetMASKAddr(CH395Inf.MASKAddr);                          /* 设置子网掩码，默认为255.255.255.0*/   
    i = CH395CMDInitCH395();                                         /* 初始化CH395芯片 */
    return i;
}
/*==============================================================================
* Function Name  : main
* Description    : main主函数
* Input          : None
* Output         : None
* Return         : None
==============================================================================*/
void netinit()
{   
    CH395_PORT_INIT();
    CH395CMDReset();
    DELAY_US(100000L);
    InitCH395InfParam();                                             /* 初始化CH395相关变量 */
    while(1)
    {
    if( CH395Init()==0x00)
    {
    break;
    }
    else
    {
    }
    }
    DELAY_US(1L) ;
      while(1)
  {                                                                 /* 等待以太网连接成功*/
       if(CH395CMDGetPHYStatus() == PHY_DISCONN)                     /* 查询CH395是否连接 */
       {
          DELAY_US(200000L);
      }
       else
       {
           DELAY_US(1L);
           break;
      }
   }
   InitSocketParam();                                                /* 初始化socket相关变量 */
   CH395SocketInitOpen();
}
/*==============================================================================
* Function Name  : main
* Description    : main主函数
* Input          : None
* Output         : None
* Return         : None
==============================================================================*/
void CH395TEST()
{
  float num=0,num1=0;
  netinit();                                          /* 初始化CH395芯片 */
   while(1)
   {
       if(CH395_INT_WIRE == 0)
       CH395GlobalInterrupt();
   }
}
/****************************endfile@tech9*************************************/
