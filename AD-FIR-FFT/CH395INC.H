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
/* �������ͺͳ������� */
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
/* ������� */
/* һ���������˳�����:
          һ��������(���ڴ��ڷ�ʽ,������֮ǰ����Ҫ����ͬ����),
          ���ɸ���������(������0��),
          ���ɸ��������(������0��)
       ��������������: CMDxy_NAME
       ���е�x��y��������, x˵�������������ݸ���(�ֽ���), y˵������������ݸ���(�ֽ���), y�����W��ʾ��Ҫ�ȴ�����ִ�гɹ�
       ��Щ�����ܹ�ʵ��0������ֽڵ����ݿ��д, ���ݿ鱾�����ֽ���δ����������x��y֮�� */
/* ********************************************************************************************************************* */
#define CMD01_GET_IC_VER                     0X01                    /* ��ȡоƬ�Լ��̼��汾�� */
/* ���: �汾��( λ7Ϊ0, λ6Ϊ1, λ5~λ0Ϊ�汾�� ) */
/*       CH3395���ذ汾�ŵ�ֵΪ041H���汾��Ϊ01H */

#define CMD31_SET_BAUDRATE                   0x02                    /* ���ڷ�ʽ: ���ô���ͨѶ������(�ϵ���߸�λ���Ĭ�ϲ�����Ϊ9600bps */
/* ����: 3�ֽڲ����ʣ����ֽ���ǰ */
/* ���: ����״̬( CMD_RET_SUCCESS, ����ֵ˵������δ��� ) */

#define CMD00_ENTER_SLEEP                    0x03                    /* ����˯��״̬ */

#define CMD00_RESET_ALL                      0X05                    /* ִ��Ӳ����λ */

#define CMD11_CHECK_EXIST                    0X06                    /* ����ͨѶ�ӿ��Լ�����״̬ */
/* ����: �������� */
/* ���: �������ݵİ�λȡ�� */

#define CMD10_SET_PHY                        0X20                    /* ����PHY��Ĭ��ΪAuto���Զ�Э�� */
/* ���룺PHY�������ο�PHY�������� */

#define CMD60_SET_MAC_ADDR                   0X21                    /* ����MAC��ַ ������CMD00H_INIT_CH395֮ǰ������� */
/* ���룺6�ֽڵ�MAC��ַ */

#define CMD40_SET_IP_ADDR                    0X22                    /* ����IP��ַ ������CMD00H_INIT_CH395֮ǰ������� */
/* ���룺4�ֽڵ�IP��ַ */

#define CMD40_SET_GWIP_ADDR                  0X23                    /* ��������IP��ַ ������CMD00H_INIT_CH395֮ǰ������� */
/* ���룺4�ֽڵ�����IP��ַ */

#define CMD40_SET_MASK_ADDR                  0X24                    /* �����������룬 ������CMD00H_INIT_CH395֮ǰ������� */
/* ���룺4�ֽڵ��������� */

#define CMD90_SET_MAC_FILT                   0X25                    /* ����MAC���� ���Խ��й㲥���ಥ�ȹ��� */
/*���룺9�ֽڲ�������1�ֽ�Ϊ�������ͣ��ο��������Ͷ��壬*/
/*      ��2����5�ֽ�ΪHASH0����6����9�ֽ�ΪHASH1 */

#define CMD01_GET_PHY_STATUS                 0X26                    /* ��ȡPHY��ǰ״̬����Ͽ����ӣ�10/100M FULL/HALF*/
/*�������ǰPHY״̬��״̬������ο�PHY�������� */

#define CMD0W_INIT_CH395                     0X27                    /* ��ʼ��CH395 */
/*������ִ��ʱ���Լ200MS����Ҫ�ȴ�������ִ�гɹ����ſ��Է���һ������*/

#define CMD08_GET_UNREACH_IPPORT             0X28                     /* ��ȡ���ɴ���Ϣ */
/*�����8�ֽڣ���1�ֽ�Ϊ���ɴ����ͣ��ο����ɴ����Ͷ���
        ��2�ֽ�Э�鲻�ɴ�Э����
        ��3��4�ֽڲ��ɴ�˿�
        ��5-8�ֲ��ɴ�IP*/

#define CMD01_GET_GLOB_INT_STATUS            0X29                    /* ��ȡȫ���ж�״̬�����ֵΪ1S������������Ϊ0 */
/*�����ȫ���ж�״̬���ο�ȫ���ж�״̬���� */

#define CMD10_SET_RETRAN_COUNT               0X2A                    /* ���Դ���������TCPģʽ����Ч */
/*���룺���Դ��� */

#define CMD20_SET_RETRAN_PERIOD              0X2B                    /* �������ڣ����ֵΪ20������TCPģʽ����Ч������������Ϊ0 */
/*���룺�������� */

#define CMD01_GET_CMD_STATUS                 0X2C                    /* ��ȡ����ִ��״̬ */
/*���������ִ��״̬���ο�����ִ��״̬���� */

#define CMD06_GET_REMOT_IPP_SN               0x2D                    /* ��ȡԶ�˵Ķ˿��Լ�IP��ַ����������TCP������ģʽ��ʹ�� */
/*�����6�ֽڣ���1-4�ֽ�ΪԶ�˵�IP��ַ����5-6�ֽ�ΪԶ�˵Ķ˿ں�*/

#define CMD10_CLEAR_RECV_BUF_SN              0X2E                    /* ������ջ�����  */
/*���룺��1�ֽ�Ϊsocket������ֵ */

#define CMD12_GET_SOCKET_STATUS_SN           0X2F                    /* ��ȡsocket n״̬ */
/*���룺socket������ֵ��*/
/*�������1�ֽڣ�socket n �򿪻��߹ر�
        ��2�ֽڣ�TCP״̬������TCPģʽ�ҵ�1�ֽ�Ϊ��״̬��������*/

#define CMD11_GET_INT_STATUS_SN              0X30                    /* ��ȡsocket n���ж�״̬ */
/*���룺 socket������ֵ*/
/*�����ȫ���ж�״̬���ο�ȫ���ж�״̬���� */
        
#define CMD50_SET_IP_ADDR_SN                 0X31                    /* ����socket n��Ŀ��IP��ַ */
/*���룺��1�ֽ�Ϊsocket������ֵ����2��5�ֽ�ΪIP��ַ*/
        
#define CMD30_SET_DES_PORT_SN                0X32                    /* ����socket n��Ŀ�Ķ˿� */
/*���룺��1�ֽ�Ϊsocket������ֵ����2��3�ֽ�ΪĿ�Ķ˿�*/
        
#define CMD30_SET_SOUR_PORT_SN               0X33                     /* ����socket n��Դ�˿� */
/*���룺��1�ֽ�Ϊsocket������ֵ����2��3�ֽ�ΪԴ�˿�*/
        
#define CMD20_SET_PROTO_TYPE_SN              0X34                    /* ����socket n��Э������*/
/*���룺��1�ֽ�Ϊsocket������ֵ����2Э�����ͣ��ο�Э�����Ͷ���*/

#define CMD1W_OPEN_SCOKET_SN                 0X35                    /* ��socket n*/
/*���룺��1�ֽ�Ϊsocket������ֵ����������Ҫ�ȴ�����ִ�гɹ� */

#define CMD1W_TCP_LISTEN_SN                  0X36                    /* scoket n�������յ������socket n���������ģʽ������TCPģʽ��Ч */
/*���룺��1�ֽ�Ϊsocket������ֵ����������Ҫ�ȴ�����ִ�гɹ� */

#define CMD1W_TCP_CONNECT_SN                 0X37                    /* scoket n���ӣ��յ������socket n����ͻ���ģʽ������TCPģʽ��Ч */
/*���룺��1�ֽ�Ϊsocket������ֵ����������Ҫ�ȴ�����ִ�гɹ� */

#define CMD1W_TCP_DISNCONNECT_SN             0X38                    /* scoket n�Ͽ����ӣ��յ������socket n�Ͽ��������ӣ�����TCPģʽ��Ч */
/*���룺��1�ֽ�Ϊsocket������ֵ����������Ҫ�ȴ�����ִ�гɹ� */

#define CMD30_WRITE_SEND_BUF_SN              0X39                    /* ��scoket n������д������ */
/*���룺��1�ֽ�Ϊsocket������ֵ����2��3�ֽ�Ϊ����*/

#define CMD12_GET_RECV_LEN_SN                0X3B                    /* ��ȡscoket n�������ݵĳ��� */
/*���룺socket������ֵ*/
/*�����2�ֽڵĽ��ճ���*/

#define CMD30_READ_RECV_BUF_SN               0X3C                    /* ��ȡscoket n���ջ���������*/
/*���룺��1�ֽ�Ϊsocket������ֵ����2��3�ֽ�Ϊ��ȡ�ĳ���n,��λ��ǰ */
/*�����n������*/

#define CMD1W_CLOSE_SCOKET_SN                0X3D                    /* �ر�scoket n*/
/*���룺socket������ֵ*/

#define CMD20_SET_IPRAW_PRO_SN               0X3E                    /* ��IP RAW�£�����socket n��IP��Э������ */
/*���룺��1�ֽ�Ϊsocket������ֵ,��2�ֽ�ΪIP RAWЭ������ */

#define CMD01_PING_ENABLE                    0X3F                    /* ����/�ر�PING */
/*���룺1�ֽڣ�0Ϊ�ر�PING��1Ϊ����PING��Ĭ�Ͽ��� */

#define CMD06_GET_MAC_ADDR                   0X40                    /* ��ȡMAC��ַ */
/* �����6�ֽڵ�MAC��ַ */
 /*37*/
/*******************************************************************************/
/* Э������ */
#define PROTO_TYPE_IP_RAW                    0                       /* IP��ԭʼ���� */
#define PROTO_TYPE_MAC_RAW                   1                       /* MAC��ԭʼ���� */
#define PROTO_TYPE_UDP                       2                       /* UDPЭ������ */
#define PROTO_TYPE_TCP                       3                       /* TCPЭ������ */

/* PHY �������/״̬ */
#define PHY_DISCONN                          (1<<0)                  /* PHY�Ͽ� */
#define PHY_10M_FLL                          (1<<1)                  /* 10Mȫ˫�� */
#define PHY_10M_HALF                         (1<<2)                  /* 10M��˫�� */
#define PHY_100M_FLL                         (1<<3)                  /* 100Mȫ˫�� */
#define PHY_100M_HALF                        (1<<4)                  /* 100M��˫�� */
#define PHY_AUTO                             (1<<5)                  /* PHY�Զ�ģʽ��CMD10H_SET_PHY */

/*CH395 MAC����*/
#define MAC_FILT_RECV_BORADPKT               (1<<0)                  /* ʹ�ܽ��չ㲥�� */
#define MAC_FILT_RECV_ALL                    (1<<1)                  /* ʹ�ܽ����������ݰ� */
#define MAC_FILT_RECV_MULTIPKT               (1<<2)                  /* ʹ�ܽ��նಥ�� */
#define MAC_FILT_RECV_ENABLE                 (1<<3)                  /* ʹ�ܽ��� */
#define MAC_FILT_SEND_ENABLE                 (1<<4)                  /* ʹ�ܷ��� */

/* �ж�״̬ */
/* ����ΪGLOB_INT�������״̬ */
#define GINT_STAT_UNREACH                    (1<<0)                  /* ���ɴ��ж�*/
#define GINT_STAT_IP_CONFLI                  (1<<1)                  /* IP��ͻ*/
#define GINT_STAT_PHY_CHANGE                 (1<<2)                  /* PHY״̬�ı� */
#define GINT_STAT_DHCP                       (1<<3)                  /* PHY״̬�ı� */
#define GINT_STAT_SOCK0                      (1<<4)                  /* scoket0 �����ж� */
#define GINT_STAT_SOCK1                      (1<<5)                  /* scoket1 �����ж� */
#define GINT_STAT_SOCK2                      (1<<6)                  /* scoket2 �����ж� */
#define GINT_STAT_SOCK3                      (1<<7)                  /* scoket3 �����ж� */

/*����ΪSn_INT�������״̬*/
#define SINT_STAT_SENBUF_FREE                (1<<0)                  /* ���ͻ��������� */
#define SINT_STAT_SEND_OK                    (1<<1)                  /* ���ͳɹ� */
#define SINT_STAT_RECV                       (1<<2)                  /* socket�˿ڽ��յ����ݻ��߽��ջ�������Ϊ�� */
#define SINT_STAT_CONNECT                    (1<<3)                  /* ���ӳɹ�,TCPģʽ�²������ж� */
#define SINT_STAT_DISCONNECT                 (1<<4)                  /* ���ӶϿ�,TCPģʽ�²������ж� */
#define SINT_STAT_TIM_OUT                    (1<<6)                  /* ARP��TCPģʽ�»ᷢ�����ж� */

/* ��ȡ����״̬ */
#define CMD_ERR_SUCCESS                      0x00                    /* ��������ɹ� */
#define CMD_RET_ABORT                        0x5F                    /* �������ʧ�� */
#define CH395_ERR_BUSY                       0x10                    /* æ״̬����ʾ��ǰ����ִ������ */
#define CH395_ERR_MEM                        0x11                    /* �ڴ���� */
#define CH395_ERR_BUF                        0x12                    /* ���������� */
#define CH395_ERR_TIMEOUT                    0x13                    /* ��ʱ */
#define CH395_ERR_RTE                        0x14                    /* ·�ɴ���*/
#define CH395_ERR_ABRT                       0x15                    /* ����ֹͣ*/
#define CH395_ERR_RST                        0x16                    /* ���Ӹ�λ */
#define CH395_ERR_CLSD                       0x17                    /* ���ӹر�/socket �ڹر�״̬*/
#define CH395_ERR_CONN                       0x18                    /* ������ */
#define CH395_ERR_VAL                        0x19                    /* �����ֵ */
#define CH395_ERR_ARG                        0x1a                    /* ����Ĳ��� */
#define CH395_ERR_USE                        0x1b                    /* �Ѿ���ʹ�� */
#define CH395_ERR_IF                         0x1c                    /* MAC����  */
#define CH395_ERR_ISCONN                     0x1d                    /* ������ */
#define CH395_ERR_UNKNOW                     0xFA                    /* δ֪���� */

/* ���ɴ���� */
#define UNREACH_CODE_HOST                    0                        /* �������ɴ� */
#define UNREACH_CODE_NET                     1                        /* ���粻�ɴ� */
#define UNREACH_CODE_PROTOCOL                2                        /* Э�鲻�ɴ� */
#define UNREACH_CODE_PROT                    3                        /* �˿ڲ��ɴ� */
/*����ֵ��ο�RFC792�ĵ�*/

/* �����ͷ */
#define SER_SYNC_CODE1                       0X57                     /* ��������ͬ����1 */
#define SER_SYNC_CODE2                       0XAB                     /* ��������ͬ����2 */

/* TCP״̬ */
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