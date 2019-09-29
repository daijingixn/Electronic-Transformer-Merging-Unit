/********************************** (C) COPYRIGHT *********************************
* File Name          : CH395CMD.C
* Author             : tech9
* Version            : V1.0
* Date               : 2012/12/01
* Description        : C Define for CH395
*                      Website: http://wch.cn
*                      Email:   tech@wch.cn         
**********************************************************************************/

#ifndef   __CH395INC_H__
#define   __CH395INC_H__
/* ********************************************************************************************************************* */
/* 常用类型和常量定义 */
#ifdef __cplusplus
extern "C" {
#endif

#ifndef     TRUE
#define     TRUE    1
#define     FALSE   0
#endif
#ifndef     NULL
#define     NULL    0
#endif

#ifndef UINT8
typedef unsigned char                UINT8;
#endif
#ifndef UINT16
typedef unsigned short               UINT16;
#endif
#ifndef UINT32
typedef unsigned long                UINT32;
#endif
#ifndef INT8
typedef signed char                  INT8;
#endif
#ifndef INT16
typedef signed short                 INT16;
#endif
#ifndef INT32
typedef signed long                  INT32;
#endif
#ifndef PUINT8
typedef unsigned char               *PUINT8;
#endif
#ifndef PUINT16
typedef unsigned short              *PUINT16;
#endif
#ifndef PUINT32
typedef unsigned long               *PUINT32;
#endif
#ifndef UINT8V
typedef unsigned char volatile       UINT8V;
#endif
#ifndef PUINT8V
typedef unsigned char volatile      *PUINT8V;
#endif

/* ********************************************************************************************************************* */
/* 命令代码 */
/* 一个命令操作顺序包含:
          一个命令码(对于串口方式,命令码之前还需要两个同步码),
          若干个输入数据(可以是0个),
          若干个输出数据(可以是0个)
       命令码起名规则: CMDxy_NAME
       其中的x和y都是数字, x说明最少输入数据个数(字节数), y说明最少输出数据个数(字节数), y如果是W表示需要等待命令执行成功
       有些命令能够实现0到多个字节的数据块读写, 数据块本身的字节数未包含在上述x或y之内 */
/* ********************************************************************************************************************* */
#define CMD01_GET_IC_VER                     0X01                    /* 获取芯片以及固件版本号 */
/* 输出: 版本号( 位7为0, 位6为1, 位5~位0为版本号 ) */
/*       CH3395返回版本号的值为041H即版本号为01H */

#define CMD31_SET_BAUDRATE                   0x02                    /* 串口方式: 设置串口通讯波特率(上电或者复位后的默认波特率为9600bps */
/* 输入: 3字节波特率，第字节在前 */
/* 输出: 操作状态( CMD_RET_SUCCESS, 其它值说明操作未完成 ) */

#define CMD00_ENTER_SLEEP                    0x03                    /* 进入睡眠状态 */

#define CMD00_RESET_ALL                      0X05                    /* 执行硬件复位 */

#define CMD11_CHECK_EXIST                    0X06                    /* 测试通讯接口以及工作状态 */
/* 输入: 任意数据 */
/* 输出: 输入数据的按位取反 */

#define CMD10_SET_PHY                        0X20                    /* 设置PHY，默认为Auto，自动协商 */
/* 输入：PHY参数，参考PHY参数定义 */

#define CMD60_SET_MAC_ADDR                   0X21                    /* 设置MAC地址 必须在CMD00H_INIT_CH395之前设置完毕 */
/* 输入：6字节的MAC地址 */

#define CMD40_SET_IP_ADDR                    0X22                    /* 设置IP地址 必须在CMD00H_INIT_CH395之前设置完毕 */
/* 输入：4字节的IP地址 */

#define CMD40_SET_GWIP_ADDR                  0X23                    /* 设置网关IP地址 必须在CMD00H_INIT_CH395之前设置完毕 */
/* 输入：4字节的网关IP地址 */

#define CMD40_SET_MASK_ADDR                  0X24                    /* 设置子网掩码， 必须在CMD00H_INIT_CH395之前设置完毕 */
/* 输入：4字节的子网掩码 */

#define CMD90_SET_MAC_FILT                   0X25                    /* 设置MAC过滤 可以进行广播，多播等过滤 */
/*输入：9字节参数，第1字节为过滤类型，参考过滤类型定义，*/
/*      第2至第5字节为HASH0，第6至第9字节为HASH1 */

#define CMD01_GET_PHY_STATUS                 0X26                    /* 获取PHY当前状态，如断开连接，10/100M FULL/HALF*/
/*输出：当前PHY状态，状态定义请参考PHY参数定义 */

#define CMD0W_INIT_CH395                     0X27                    /* 初始化CH395 */
/*此命令执行时间大约200MS，需要等待此命令执行成功，才可以发下一条命令*/

#define CMD08_GET_UNREACH_IPPORT             0X28                     /* 获取不可达信息 */
/*输出：8字节，第1字节为不可达类型，参考不可达类型定义
        第2字节协议不可达协议码
        第3，4字节不可达端口
        第5-8字不可达IP*/

#define CMD01_GET_GLOB_INT_STATUS            0X29                    /* 获取全局中断状态，最大值为1S，不可以设置为0 */
/*输出：全局中断状态，参考全局中断状态定义 */

#define CMD10_SET_RETRAN_COUNT               0X2A                    /* 重试次数，仅在TCP模式下有效 */
/*输入：重试次数 */

#define CMD20_SET_RETRAN_PERIOD              0X2B                    /* 重试周期，最大值为20，仅在TCP模式下有效，不可以设置为0 */
/*输入：重试周期 */

#define CMD01_GET_CMD_STATUS                 0X2C                    /* 获取命令执行状态 */
/*输出：命令执行状态，参考命令执行状态定义 */

#define CMD06_GET_REMOT_IPP_SN               0x2D                    /* 获取远端的端口以及IP地址，该命令在TCP服务器模式下使用 */
/*输出：6字节，第1-4字节为远端的IP地址，第5-6字节为远端的端口号*/

#define CMD10_CLEAR_RECV_BUF_SN              0X2E                    /* 清除接收缓冲区  */
/*输入：第1字节为socket的索引值 */

#define CMD12_GET_SOCKET_STATUS_SN           0X2F                    /* 获取socket n状态 */
/*输入：socket的索引值，*/
/*输出：第1字节：socket n 打开或者关闭
        第2字节：TCP状态，仅在TCP模式且第1字节为打开状态下有意义*/

#define CMD11_GET_INT_STATUS_SN              0X30                    /* 获取socket n的中断状态 */
/*输入： socket的索引值*/
/*输出：全局中断状态，参考全局中断状态定义 */
        
#define CMD50_SET_IP_ADDR_SN                 0X31                    /* 设置socket n的目的IP地址 */
/*输入：第1字节为socket的索引值，第2至5字节为IP地址*/
        
#define CMD30_SET_DES_PORT_SN                0X32                    /* 设置socket n的目的端口 */
/*输入：第1字节为socket的索引值，第2至3字节为目的端口*/
        
#define CMD30_SET_SOUR_PORT_SN               0X33                     /* 设置socket n的源端口 */
/*输入：第1字节为socket的索引值，第2至3字节为源端口*/
        
#define CMD20_SET_PROTO_TYPE_SN              0X34                    /* 设置socket n的协议类型*/
/*输入：第1字节为socket的索引值，第2协议类型，参考协议类型定义*/

#define CMD1W_OPEN_SCOKET_SN                 0X35                    /* 打开socket n*/
/*输入：第1字节为socket的索引值，此命令需要等待命令执行成功 */

#define CMD1W_TCP_LISTEN_SN                  0X36                    /* scoket n监听，收到此命令，socket n进入服务器模式，仅对TCP模式有效 */
/*输入：第1字节为socket的索引值，此命令需要等待命令执行成功 */

#define CMD1W_TCP_CONNECT_SN                 0X37                    /* scoket n连接，收到此命令，socket n进入客户端模式，仅对TCP模式有效 */
/*输入：第1字节为socket的索引值，此命令需要等待命令执行成功 */

#define CMD1W_TCP_DISNCONNECT_SN             0X38                    /* scoket n断开连接，收到此命令，socket n断开已有连接，仅对TCP模式有效 */
/*输入：第1字节为socket的索引值，此命令需要等待命令执行成功 */

#define CMD30_WRITE_SEND_BUF_SN              0X39                    /* 向scoket n缓冲区写入数据 */
/*输入：第1字节为socket的索引值，第2至3字节为长度*/

#define CMD12_GET_RECV_LEN_SN                0X3B                    /* 获取scoket n接收数据的长度 */
/*输入：socket的索引值*/
/*输出：2字节的接收长度*/

#define CMD30_READ_RECV_BUF_SN               0X3C                    /* 读取scoket n接收缓冲区数据*/
/*输入：第1字节为socket的索引值，第2至3字节为读取的长度n,低位在前 */
/*输出：n个数据*/

#define CMD1W_CLOSE_SCOKET_SN                0X3D                    /* 关闭scoket n*/
/*输入：socket的索引值*/

#define CMD20_SET_IPRAW_PRO_SN               0X3E                    /* 在IP RAW下，设置socket n的IP包协议类型 */
/*输入：第1字节为socket的索引值,第2字节为IP RAW协议类型 */

#define CMD01_PING_ENABLE                    0X3F                    /* 开启/关闭PING */
/*输入：1字节，0为关闭PING，1为开启PING，默认开启 */

#define CMD06_GET_MAC_ADDR                   0X40                    /* 获取MAC地址 */
/* 输出：6字节的MAC地址 */
 /*37*/
/*******************************************************************************/
/* 协议类型 */
#define PROTO_TYPE_IP_RAW                    0                       /* IP层原始数据 */
#define PROTO_TYPE_MAC_RAW                   1                       /* MAC层原始数据 */
#define PROTO_TYPE_UDP                       2                       /* UDP协议类型 */
#define PROTO_TYPE_TCP                       3                       /* TCP协议类型 */

/* PHY 命令参数/状态 */
#define PHY_DISCONN                          (1<<0)                  /* PHY断开 */
#define PHY_10M_FLL                          (1<<1)                  /* 10M全双工 */
#define PHY_10M_HALF                         (1<<2)                  /* 10M半双工 */
#define PHY_100M_FLL                         (1<<3)                  /* 100M全双工 */
#define PHY_100M_HALF                        (1<<4)                  /* 100M半双工 */
#define PHY_AUTO                             (1<<5)                  /* PHY自动模式，CMD10H_SET_PHY */

/*CH395 MAC过滤*/
#define MAC_FILT_RECV_BORADPKT               (1<<0)                  /* 使能接收广播包 */
#define MAC_FILT_RECV_ALL                    (1<<1)                  /* 使能接收所有数据包 */
#define MAC_FILT_RECV_MULTIPKT               (1<<2)                  /* 使能接收多播包 */
#define MAC_FILT_RECV_ENABLE                 (1<<3)                  /* 使能接收 */
#define MAC_FILT_SEND_ENABLE                 (1<<4)                  /* 使能发送 */

/* 中断状态 */
/* 以下为GLOB_INT会产生的状态 */
#define GINT_STAT_UNREACH                    (1<<0)                  /* 不可达中断*/
#define GINT_STAT_IP_CONFLI                  (1<<1)                  /* IP冲突*/
#define GINT_STAT_PHY_CHANGE                 (1<<2)                  /* PHY状态改变 */
#define GINT_STAT_DHCP                       (1<<3)                  /* PHY状态改变 */
#define GINT_STAT_SOCK0                      (1<<4)                  /* scoket0 产生中断 */
#define GINT_STAT_SOCK1                      (1<<5)                  /* scoket1 产生中断 */
#define GINT_STAT_SOCK2                      (1<<6)                  /* scoket2 产生中断 */
#define GINT_STAT_SOCK3                      (1<<7)                  /* scoket3 产生中断 */

/*以下为Sn_INT会产生的状态*/
#define SINT_STAT_SENBUF_FREE                (1<<0)                  /* 发送缓冲区空闲 */
#define SINT_STAT_SEND_OK                    (1<<1)                  /* 发送成功 */
#define SINT_STAT_RECV                       (1<<2)                  /* socket端口接收到数据或者接收缓冲区不为空 */
#define SINT_STAT_CONNECT                    (1<<3)                  /* 连接成功,TCP模式下产生此中断 */
#define SINT_STAT_DISCONNECT                 (1<<4)                  /* 连接断开,TCP模式下产生此中断 */
#define SINT_STAT_TIM_OUT                    (1<<6)                  /* ARP和TCP模式下会发生此中断 */

/* 获取命令状态 */
#define CMD_ERR_SUCCESS                      0x00                    /* 命令操作成功 */
#define CMD_RET_ABORT                        0x5F                    /* 命令操作失败 */
#define CH395_ERR_BUSY                       0x10                    /* 忙状态，表示当前正在执行命令 */
#define CH395_ERR_MEM                        0x11                    /* 内存错误 */
#define CH395_ERR_BUF                        0x12                    /* 缓冲区错误 */
#define CH395_ERR_TIMEOUT                    0x13                    /* 超时 */
#define CH395_ERR_RTE                        0x14                    /* 路由错误*/
#define CH395_ERR_ABRT                       0x15                    /* 连接停止*/
#define CH395_ERR_RST                        0x16                    /* 连接复位 */
#define CH395_ERR_CLSD                       0x17                    /* 连接关闭/socket 在关闭状态*/
#define CH395_ERR_CONN                       0x18                    /* 无连接 */
#define CH395_ERR_VAL                        0x19                    /* 错误的值 */
#define CH395_ERR_ARG                        0x1a                    /* 错误的参数 */
#define CH395_ERR_USE                        0x1b                    /* 已经被使用 */
#define CH395_ERR_IF                         0x1c                    /* MAC错误  */
#define CH395_ERR_ISCONN                     0x1d                    /* 已连接 */
#define CH395_ERR_UNKNOW                     0xFA                    /* 未知错误 */

/* 不可达代码 */
#define UNREACH_CODE_HOST                    0                        /* 主机不可达 */
#define UNREACH_CODE_NET                     1                        /* 网络不可达 */
#define UNREACH_CODE_PROTOCOL                2                        /* 协议不可达 */
#define UNREACH_CODE_PROT                    3                        /* 端口不可达 */
/*其他值请参考RFC792文档*/

/* 命令包头 */
#define SER_SYNC_CODE1                       0X57                     /* 串口命令同步码1 */
#define SER_SYNC_CODE2                       0XAB                     /* 串口命令同步码2 */

/* TCP状态 */
#define TCP_CLOSED                           0                     
#define TCP_LISTEN                           1
#define TCP_SYN_SENT                         2
#define TCP_SYN_RCVD                         3
#define TCP_ESTABLISHED                      4
#define TCP_FIN_WAIT_1                       5
#define TCP_FIN_WAIT_2                       6
#define TCP_CLOSE_WAIT                       7
#define TCP_CLOSING                          8
#define TCP_LAST_ACK                         9
#define TCP_TIME_WAIT                        10

#ifdef __cplusplus
}
#endif
#endif

/****************************endfile@tech9*************************************/
