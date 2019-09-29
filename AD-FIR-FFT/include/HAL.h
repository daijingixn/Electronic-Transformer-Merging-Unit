/* CH376оƬ Ӳ������� V1.0 */
/* �ṩI/O�ӿ��ӳ��� */

#include	"CH376INC.H"

#ifndef	__CH376_HAL_H__
#define __CH376_HAL_H__

#ifdef __CX51__
#ifndef __C51__
#define __C51__		1
#endif
#endif

#ifdef __C51__
#define	BIG_ENDIAN		1
#endif
#ifdef __C51__
#pragma NOAREGS
#endif


/* ���ӵ�USB����״̬���� */
#define		ERR_USB_UNKNOWN		0xFA	/* δ֪����,��Ӧ�÷��������,����Ӳ�����߳������ */

/* ��ʱָ��΢��ʱ��,���ݵ�Ƭ����Ƶ����,����ȷ */


/* ��ʱָ������ʱ��,���ݵ�Ƭ����Ƶ����,����ȷ */


void	CH376_PORT_INIT( void );  		/* CH376ͨѶ�ӿڳ�ʼ�� */

void	xEndCH376Cmd( void );			/* ����CH376����,������SPI�ӿڷ�ʽ */

void	xWriteCH376Cmd( UINT8 mCmd );	/* ��CH376д���� */

void	xWriteCH376Data( INT8 mData );	/* ��CH376д���� */

UINT8	xReadCH376Data( void );			/* ��CH376������ */

UINT8	Query376Interrupt( void );		/* ��ѯCH376�ж�(INT#����Ϊ�͵�ƽ) */

UINT8	mInitCH376Host( void );			/* ��ʼ��CH376 */

#endif