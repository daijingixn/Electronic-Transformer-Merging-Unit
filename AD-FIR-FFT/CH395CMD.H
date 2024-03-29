/********************************** (C) COPYRIGHT *******************************
* File Name          : CH395CMD.H
* Author             : tech9
* Version            : V1.0
* Date               : 2012/12/01
* Description        : CH395芯片命令接口文件,常用子程序外部调用
*                    Website: http://wch.cn
*                    Email:   tech@wch.cn 
*******************************************************************************/

#ifndef __CH395CMD_H__
#define __CH395CMD_H__

void CH395CMDReset(void);                                            /* 复位 */

void CH395CMDSleep(void);                                            /* 睡眠 */

UINT8 CH395CMDGetVer(void);                                          /* 获取芯片及固件版本号 */

UINT8 CH395CMDCheckExist(UINT8 testdata);                            /* 测试命令 */

void CH395CMDSetPHY(UINT8 phystat);                                  /* 设置PHY状态  */

UINT8 CH395CMDGetPHYStatus(void);                                    /* 获取PHY状态 */

UINT8 CH395CMDGetGlobIntStatus(void);                                /* 获取CH395全局中断状态 */

UINT8 CH395CMDInitCH395(void);                                       /* 初始化CH395 */

void CH395CMDSetUartBaudRate(UINT32 baudrate);                       /* 设置波特率 */

UINT8 CH395GetCmdStatus(void);                                       /* 获取命令执行状态 */

void CH395CMDSetIPAddr(UINT8 *ipaddr);                               /* 设置CH395的IP地址 */

void CH395CMDSetGWIPAddr(UINT8 *gwipaddr);                           /* 设置CH395的网关IP地址 */

void CH395CMDSetMASKAddr(UINT8 *maskaddr);                           /* 设置子网掩码 */

void CH395CMDSetMACAddr(UINT8 *amcaddr);                             /* 设置CH395的MAC地址 */

void CH395CMDGetMACAddr(UINT8 *amcaddr);                             /* 获取MAC地址 */

void CH395CMDSetMACFilt(UINT8 filtype,UINT32 table0,UINT32 table1);  /* 设置CH395的MAC过滤 */

void CH395CMDGetUnreachIPPT(UINT8 *list);                            /* 获取不可达地址以及端口 */

void CH395CMDGetRemoteIPP(UINT8 sockindex,UINT8 *list);              /* 获取远端IP和端口，一般在TCP Server下使用 */

void CH395SetSocketDesIP(UINT8 sockindex,UINT8 *ipaddr);             /* 设置scoket n的目的IP地址 */

void CH395SetSocketProtType(UINT8 sockindex,UINT8 prottype);         /* 设置socket n的协议类型 */

void CH395SetSocketDesPort(UINT8 sockindex,UINT16 desprot);          /* 设置socket n的目的端口 */

void CH395SetSocketSourPort(UINT8 sockindex,UINT16 surprot);         /* 设置socket n的源端口 */

void CH395SetSocketIPRAWProto(UINT8 sockindex,UINT8 prototype);      /* 在IPRAW模式下，设置socket n的IP包协议字段 */

void CH395SetRecvThresLen(UINT8 sockindex,UINT16 len);               /* 设置socket n的接收中断阀值 */

void CH395SendData(UINT8 sockindex,UINT8 *databuf,UINT16 len);       /* 向socket n的发送缓冲区写数据 */

UINT16 CH395GetReceLength(UINT8 sockindex);                          /* 获取socket n的接收长度 */

void CH395ClearRecvBuf(UINT8 sockindex);                             /* 清除socket n的接收缓冲区 */

void CH395GetReceData(UINT8 sockindex,UINT16 len,UINT8 *pbuf);       /* 获取接收数据 */

void CH395CMDSetRetryCount(UINT8 count);                             /* 设置最大重试次数 */

void CH395CMDSetRetryPeriod(UINT16 period);                          /* 设置最大重试周期 单位 毫秒*/

void CH395CMDGetSocketStatus(UINT8 sockindex,UINT8 *status) ;        /* 获取socket n的状态 */

UINT8  CH395OpenSocket(UINT8 sockindex);                             /* 打开socket n*/

UINT8  CH395CloseSocket(UINT8 sockindex);                             /* 关闭socket n*/

UINT8 CH395TCPConnect(UINT8 sockindex);                               /* TCP连接 */

UINT8 CH395TCPListen(UINT8 sockindex);                                /* TCP监听 */

UINT8 CH395TCPDisconnect(UINT8 sockindex);                            /* TCP断开连接 */

UINT8 CH395GetSocketInt(UINT8 sockindex);                            /* 获取socket n的中断状态 */
                                                                     
UINT8 CH395CRCRet6Bit(UINT8 *mac_addr);                              /* 多播地址CRC32，用于HASH过滤 */
                                                                     /*Function Count = 36 */
/***************************以下为不常用命令*************************************************************************/

void CH395WriteRegister(UINT32 addr,UINT32 mdata);                   /* 写CH395内部寄存器 */

void CH395WriteProtRegister(UINT32 addr,UINT32 mdata);               /* 写CH395内部保护寄存器 */

UINT32 CH395ReadRegister(UINT32 addr);                               /* 读CH395内部寄存器 */

UINT8 CH395ReadVar8(UINT8 index ,UINT8 addr);                        /* 读8位内部变量 */

void CH395WriteVar8(UINT8 index ,UINT8 addr,UINT8 mdata);            /* 写8位内部变量 */

UINT32 CH395ReadVar32(UINT8 index ,UINT8 addr);                      /* 读内部32位变量 */

void CH395WriteVar32(UINT8 index ,UINT8 addr,UINT32 mdata);          /* 写内部32位变量 */

void CH395WriteRAM(UINT8 *buf);                                      /* 测试使用，写内部4K SRAM */

void CH395ReadRAM(UINT8 *buf);                                       /* 测试使用，读内部4K SRAM */

#endif

/****************************endfile@tech9*************************************/
