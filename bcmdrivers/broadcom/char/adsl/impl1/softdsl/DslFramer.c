/*
<:copyright-broadcom 
 
 Copyright (c) 2002 Broadcom Corporation 
 All Rights Reserved 
 No portions of this material may be reproduced in any form without the 
 written permission of: 
          Broadcom Corporation 
          16215 Alton Parkway 
          Irvine, California 92619 
 All information contained in this document is Broadcom Corporation 
 company private, proprietary, and trade secret. 
 
:>
*/
/****************************************************************************
 *
 * DslFramer.c -- DSL common framer 
 *
 * Description:
 *	This file contains root functions of DslFramer
 *
 *
 * Copyright (c) 1993-1998 AltoCom, Inc. All rights reserved.
 * Authors: Ilya Stomakhin
 *
 * $Revision: 1.1 $
 *
 * $Id: DslFramer.c,v 1.1 2008/08/25 06:41:01 l65130 Exp $
 *
 * $Log: DslFramer.c,v $
 * Revision 1.1  2008/08/25 06:41:01  l65130
 * 【变更分类】建立基线
 * 【问题单号】
 * 【问题描述】
 * 【修改说明】
 *
 * Revision 1.1  2008/06/20 06:21:21  z67625
 * *** empty log message ***
 *
 * Revision 1.1  2008/01/14 02:47:17  z30370
 * *** empty log message ***
 *
 * Revision 1.2  2007/12/16 10:09:55  z45221
 * 合入人:
 * s48571
 *
 * 合入内容：
 * ADSL驱动更新版本至A2x020h
 * ADSLfirmware版本更换版本至a2pb023k/b2pb023k
 *
 * 修改文件列表：
 * /bcmdrivers/broadcom/char/adsl/impl1/AdslCore.c
 * /bcmdrivers/broadcom/char/adsl/impl1/AdslCore.h
 * /bcmdrivers/broadcom/char/adsl/impl1/AdslCoreFrame.c
 * /bcmdrivers/broadcom/char/adsl/impl1/AdslCoreFrame.h
 * /bcmdrivers/broadcom/char/adsl/impl1/AdslCoreMap.h
 * /bcmdrivers/broadcom/char/adsl/impl1/AdslDrvVersion.h
 * /bcmdrivers/broadcom/char/adsl/impl1/AdslFile.c
 * /bcmdrivers/broadcom/char/adsl/impl1/AdslFile.h
 * /bcmdrivers/broadcom/char/adsl/impl1/AdslSelfTest.c
 * /bcmdrivers/broadcom/char/adsl/impl1/AdslSelfTest.h
 * /bcmdrivers/broadcom/char/adsl/impl1/BcmAdslCore.c
 * /bcmdrivers/broadcom/char/adsl/impl1/BcmAdslCore.h
 * /bcmdrivers/broadcom/char/adsl/impl1/BcmAdslDiag.h
 * /bcmdrivers/broadcom/char/adsl/impl1/BcmAdslDiagLinux.c
 * /bcmdrivers/broadcom/char/adsl/impl1/BcmAdslDiagNone.c
 * /bcmdrivers/broadcom/char/adsl/impl1/BcmAdslDiagRtems.c
 * /bcmdrivers/broadcom/char/adsl/impl1/BcmOs.h
 * /bcmdrivers/broadcom/char/adsl/impl1/Makefile
 * /bcmdrivers/broadcom/char/adsl/impl1/adsl.c
 * /bcmdrivers/broadcom/char/adsl/impl1/adsldrv.c
 * /bcmdrivers/broadcom/char/adsl/impl1/adslcore6348/adsl_defs.h
 * /bcmdrivers/broadcom/char/adsl/impl1/adslcore6348/adsl_lmem.c
 * /bcmdrivers/broadcom/char/adsl/impl1/adslcore6348/adsl_lmem.h
 * /bcmdrivers/broadcom/char/adsl/impl1/adslcore6348/adsl_sdram.c
 * /bcmdrivers/broadcom/char/adsl/impl1/adslcore6348/adsl_sdram.h
 * /bcmdrivers/broadcom/char/adsl/impl1/adslcore6348B/adsl_defs.h
 * /bcmdrivers/broadcom/char/adsl/impl1/adslcore6348B/adsl_lmem.c
 * /bcmdrivers/broadcom/char/adsl/impl1/adslcore6348B/adsl_lmem.h
 * /bcmdrivers/broadcom/char/adsl/impl1/adslcore6348B/adsl_sdram.c
 * /bcmdrivers/broadcom/char/adsl/impl1/adslcore6348B/adsl_sdram.h
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/AdslCoreDefs.h
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/AdslMib.c
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/AdslMib.gh
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/AdslMib.h
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/AdslMibObj.c
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/AdslMibOid.h
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/AdslXfaceData.h
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/BlockUtil.h
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/CircBuf.h
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/DslFramer.c
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/DslFramer.h
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/Flatten.c
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/Flatten.h
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/G992p3OvhMsg.c
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/G992p3OvhMsg.gh
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/G992p3OvhMsg.h
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/G997.c
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/G997.gh
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/G997.h
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/HdlcByte.c
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/HdlcFramer.c
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/HdlcFramer.h
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/MathUtil.h
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/MipsAsm.h
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/MiscUtil.h
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/SoftAtmVc.h
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/SoftDsl.gh
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/SoftDsl.h
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/SoftDslFrame.c
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/SoftModem.h
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/SoftModemTypes.h
 *
 * /bcmdrivers/broadcom/includeAdslMibDef.h
 * /bcmdrivers/broadcom/includeDiagDef.h
 * /bcmdrivers/broadcom/includeadsldrv.h
 * /bcmdrivers/broadcom/includebcmadsl.h
 *
 * /userapps/broadcom/adslctl/adslctl.c
 * /userapps/broadcom/adslctl/adsluser.c
 *
 * /userapps/broadcom/cfm/html/statsadsl.html
 * /userapps/broadcom/cfm/html/countrysupport/italy_vdf/info.html
 * /userapps/broadcom/cfm/inc/syscall.h
 * /userapps/broadcom/cfm/main/adslcfgmngr/adslctlapi.c
 * /userapps/broadcom/cfm/util/system/syscall.c
 * /userapps/broadcom/cfm/web/cgimain.c
 * /userapps/broadcom/cfm/web/cgimain.h
 *
 * Revision 1.3  2004/07/21 01:39:41  ilyas
 * Reset entire G.997 state on retrain. Timeout in G.997 if no ACK
 *
 * Revision 1.2  2004/04/12 23:41:10  ilyas
 * Added standard header for shared ADSL driver files
 *
 * Revision 1.1  2001/12/13 02:28:27  ilyas
 * Added common framer (DslPacket and G997) and G997 module
 *
 *
 *
 *****************************************************************************/

#include "SoftDsl.gh"

#include "DslFramer.h"
#include "BlockUtil.h"
#include "BlankList.h"
#include "Que.h"
#include "DList.h"

/*
**
**		Dsl Framer memory management functions
**
*/

Private void DslFramerMemExit(void *gDslVars, dslFramerControl *dfCtrl)
{
	if (NULL != dfCtrl->freePacketPool)
		DslFrameFreeMemForFrames(gDslVars, dfCtrl->freePacketPool);

	DslFrameFreeMemForBuffers(gDslVars, dfCtrl->pBufMemory, dfCtrl->nRxBufSize, dfCtrl->freeBufPool);

	dfCtrl->freePacketPool = NULL;
	dfCtrl->freeBufPool = NULL; 
}

Private Boolean DslFramerMemInit(void *gDslVars, dslFramerControl *dfCtrl, int rxBufNum, int rxBufSize, int rxPacketNum)
{
	int				i;
	dslFrame		*pFrame;
	dslFrameBuffer	*pBuf;
	uchar			*pBufMem;

	dfCtrl->nRxBuffers = rxBufNum;
	dfCtrl->nRxBufSize = rxBufSize;
	dfCtrl->nRxPackets = rxPacketNum;

	pBufMem = DslFrameAllocMemForBuffers(gDslVars, &dfCtrl->freeBufPool, rxBufNum, rxBufSize*rxBufNum);
	if (NULL == pBufMem)
		return false;

	dfCtrl->pBufMemory = pBufMem;

	/* Initialize dslPacket and add them into blank list */

	dfCtrl->freePacketPool = DslFrameAllocMemForFrames(gDslVars, rxPacketNum + 1);
	if (NULL == dfCtrl->freePacketPool) {
		DslFramerMemExit(gDslVars, dfCtrl);
		return false;
	}

	dfCtrl->freePacketListPtr = NULL;
	for (i = 0; i < rxPacketNum; i++) {
		pFrame = DslFrameAllocFrame(gDslVars, dfCtrl->freePacketPool);
		DslFrameInit(gDslVars, pFrame);
		BlankListAdd(&dfCtrl->freePacketListPtr, pFrame);
	}

	/* Define all the slots as empty and build a list of them */

	dfCtrl->freeBufListPtr = DslFrameAllocFrame(gDslVars, dfCtrl->freePacketPool);
	DslFrameInit (gDslVars, dfCtrl->freeBufListPtr);
	for (i = 0; i < rxBufNum; i++) {
		pBuf = DslFrameAllocBuffer (gDslVars, dfCtrl->freeBufPool, pBufMem, rxBufSize);
		pBufMem += rxBufSize;
		DslFrameEnqueBufferAtFront(gDslVars, dfCtrl->freeBufListPtr, pBuf);
	}


	return true;
}

/*
**
**		DslFramer stat functions
**
*/

Public void DslFramerClearStat(dslFramerControl *dfCtrl)
{
	dfCtrl->dslByteCntRxTotal	= 0;
	dfCtrl->dslByteCntTxTotal	= 0;

	dfCtrl->dslFrameCntRxTotal= 0;
	dfCtrl->dslFrameCntRxErr	= 0;
	dfCtrl->dslFrameCntTxTotal= 0;
}

/*
**
**		DslFramer reporting functions 
**
*/

#undef DSL_FRAMER_REPORT_RX_FRAMES
#undef DSL_FRAMER_REPORT_TX_FRAMES

#ifdef DSL_FRAMER_REPORT_RX_FRAMES
#define	DslFramerReportRxPacket(gDslVars,dfCtrl,pFr)	DslFramerReportFrame(gDslVars,dfCtrl,kDslFramerRxFrame,pFr)
#else
#define	DslFramerReportRxPacket(gDslVars,dfCtrl,pFr)
#endif

#ifdef DSL_FRAMER_REPORT_TX_FRAMES
#define	DslFramerReportTxPacket(gDslVars,dfCtrl,pFr)	DslFramerReportFrame(gDslVars,dfCtrl,kDslFramerTxFrame,pFr)
#else
#define	DslFramerReportTxPacket(gDslVars,dfCtrl,pFr)
#endif

#if defined(DSL_FRAMER_REPORT_RX_FRAMES) || defined(DSL_FRAMER_REPORT_TX_FRAMES)
Private void DslFramerReportFrame(void *gDslVars, dslFramerControl *dfCtrl, ulong frameStatusCode, dslFrame *pFrame)
{
	dslStatusStruct		status;
	dslFrameBuffer		*pFrBuf;
	dslFramerStatus		*pFramerStatus;

	status.code = dfCtrl->statusCode;
	pFramerStatus = (dslFramerStatus *) ((char *) &status + dfCtrl->statusOffset);

	pFramerStatus->code = frameStatusCode;

	pFrBuf = DslFrameGetFirstBuffer(gDslVars, pFrame);
	if (NULL != pFrBuf) {
		pFramerStatus->param.frame.framePtr = DslFrameBufferGetAddress(gDslVars, pFrBuf);
		pFramerStatus->param.frame.length	= DslFrameBufferGetLength(gDslVars, pFrBuf);
	}
	else {
		pFramerStatus->param.frame.framePtr = NULL;
		pFramerStatus->param.frame.length   = 0;
	}
	dfCtrl->statusHandlerPtr (gDslVars, &status);
}
#endif

Private void DslFramerReportStatus(void *gDslVars, dslFramerControl *dfCtrl, ulong statusCode, int value)
{
	dslStatusStruct		status;
	dslFramerStatus		*pFramerStatus;

	status.code = dfCtrl->statusCode;
	pFramerStatus = (dslFramerStatus *) ((char *) &status + dfCtrl->statusOffset);

	pFramerStatus->code = statusCode;
	pFramerStatus->param.value = value;

	dfCtrl->statusHandlerPtr (gDslVars, &status);
}

/*
**
**		DslFramer frame processing functions
**
*/

#define	DslFramerAllocateFrame(dfCtrl)				BlankListGet(&dfCtrl->freePacketListPtr)
#define	DslFramerAllocateBuffer(gDslVars,dfCtrl)	DslFrameDequeBuffer(gDslVars,dfCtrl->freeBufListPtr)
#define	DslFramerFreeBuffer(gDslVars,dfCtrl,pBuf)	DslFrameEnqueBufferAtFront(gDslVars,dfCtrl->freeBufListPtr,pBuf)

#define DslFramerIndicateRecevice(gDslVars,dfCtrl,pFr)	do {	\
	DslFramerReportRxPacket(gDslVars,dfCtrl,pFr);				\
	dfCtrl->dslFrameCntRxTotal++;								\
	dfCtrl->dslByteCntRxTotal += dfCtrl->rxFrameLen;			\
	(dfCtrl->rxIndicateHandlerPtr) (gDslVars, NULL, 0, pFr);	\
	dfCtrl->pRxFrame		= NULL;								\
	dfCtrl->rxFrameLen	= 0;									\
} while (0)

#define DslFramerAddFreeFrame(gDslVars,dfCtrl,pFr)	do {				\
	DslFrameEnqueFrameAtFront(gDslVars, dfCtrl->freeBufListPtr, pFr);	\
	BlankListAdd(&dfCtrl->freePacketListPtr, pFr);						\
} while (0)

#define DslFramerSendComplete(gDslVars,dfCtrl,pFr)	do {			\
	DslFramerReportTxPacket(gDslVars,dfCtrl,pFr);					\
	dfCtrl->dslFrameCntTxTotal++;									\
	dfCtrl->dslByteCntTxTotal += DslFrameGetLength(gDslVars, pFr);	\
	(dfCtrl->txCompleteHandlerPtr)(gDslVars, NULL, 0, pFr);			\
} while (0)

#define DslFramerTxFlushFrame(gDslVars,dfCtrl,pFr)	do {			\
	DslFramerReportStatus(gDslVars,dfCtrl,kDslFramerTxFrameErr,kDslFramerTxFrameErrFlushed);	\
	(dfCtrl->txCompleteHandlerPtr)(gDslVars, NULL, 0, pFr);			\
} while (0)


Private void DslFramerTxInit(dslFramerControl *dfCtrl)
{
	DListInit(&dfCtrl->dlistTxWaiting);
	dfCtrl->pTxFrame		= NULL;
	dfCtrl->pTxBuf		= NULL;
	dfCtrl->pTxBufData	= NULL;
	dfCtrl->pTxBufDataEnd	= NULL;
}

Public void DslFramerTxFlush(void *gDslVars, dslFramerControl *dfCtrl)
{
	DListHeader	*p = ((DListHeader *)(&dfCtrl->dlistTxWaiting))->next;
	dslFrame	*pFrame;

	while (DListValid(&dfCtrl->dlistTxWaiting, p)) {
		pFrame = (dslFrame *) DslFrameGetFrameAddressFromLink(gDslVars, p);
		p = DListNext(p);
		DslFramerTxFlushFrame(gDslVars, dfCtrl, pFrame);
	}

	if (NULL != dfCtrl->pTxFrame)
		DslFramerTxFlushFrame(gDslVars, dfCtrl, dfCtrl->pTxFrame);

	DslFramerTxInit(dfCtrl);
}


Private void DslFramerRxInit(dslFramerControl *dfCtrl)
{
	dfCtrl->pRxFrame		= NULL;
	dfCtrl->pRxBuf		= NULL;
	dfCtrl->pRxBufData	= NULL;
	dfCtrl->pRxBufDataEnd	= NULL;
	dfCtrl->rxFrameLen	= 0;
}

Public void DslFramerRxFlushFrame (void *gDslVars, dslFramerControl *dfCtrl, int errCode)
{
	DslFramerReportStatus(gDslVars, dfCtrl, kDslFramerRxFrameErr, errCode);
	if (NULL != dfCtrl->pRxFrame)
		DslFramerAddFreeFrame(gDslVars, dfCtrl, dfCtrl->pRxFrame);
	if (NULL != dfCtrl->pRxBuf)
		DslFramerFreeBuffer(gDslVars, dfCtrl, dfCtrl->pRxBuf);

	DslFramerRxInit(dfCtrl);
}

Public void DslFramerRxFlush(void *gDslVars, dslFramerControl *dfCtrl)
{
	DslFramerRxFlushFrame (gDslVars, dfCtrl, kDslFramerRxFrameErrFlushed);
}



/*
**
**		DslFramer interface functions
**
*/

Public Boolean  DslFramerInit(
			void					*gDslVars,
			dslFramerControl		*dfCtrl,
			bitMap					setup,
			ulong					statusCode,
			ulong					statusOffset,
			dslFrameHandlerType		rxIndicateHandlerPtr,
			dslFrameHandlerType		txCompleteHandlerPtr,
			dslStatusHandlerType	statusHandlerPtr,
			ulong					rxBufNum,
			ulong					rxBufSize,
			ulong					rxPacketNum)
{
	Boolean		flag;

	if (dfCtrl->setup & kDslFramerInitialized)
		DslFramerClose (gDslVars, dfCtrl);

	dfCtrl->setup				 = setup;
	dfCtrl->statusCode			 = statusCode;
	dfCtrl->statusOffset		 = statusOffset;
 	dfCtrl->rxIndicateHandlerPtr = rxIndicateHandlerPtr;
	dfCtrl->txCompleteHandlerPtr = txCompleteHandlerPtr; 
	dfCtrl->statusHandlerPtr     = statusHandlerPtr;

	DslFramerTxInit(dfCtrl);
	DslFramerRxInit(dfCtrl);

	DslFramerClearStat(dfCtrl);
	flag = DslFramerMemInit(gDslVars, dfCtrl, rxBufNum, rxBufSize, rxPacketNum);
	if (flag)
		dfCtrl->setup |= kDslFramerInitialized;
	else
		dfCtrl->setup = 0;
	return flag;
}

Public void DslFramerClose(void *gDslVars, dslFramerControl *dfCtrl)
{
	if (dfCtrl->setup & kDslFramerInitialized) {
		DslFramerTxFlush(gDslVars, dfCtrl);
		DslFramerRxFlush(gDslVars, dfCtrl);
		DslFramerMemExit(gDslVars, dfCtrl);
	}
	dfCtrl->setup	= 0;
}
	
Public void DslFramerSendFrame(void *gDslVars, dslFramerControl *dfCtrl, dslFrame *pFrame)
{
	DListInsertTail(&dfCtrl->dlistTxWaiting, DslFrameGetLinkFieldAddress(gDslVars, pFrame));
}

Public void DslFramerReturnFrame(void *gDslVars, dslFramerControl *dfCtrl, dslFrame *pFrame)
{
	DslFramerAddFreeFrame(gDslVars, dfCtrl, pFrame);
}

Public void * DslFramerGetFramePoolHandler(dslFramerControl *dfCtrl)
{
	return dfCtrl->freePacketPool;
}

/*
**
**		DslFramer "data" interface functions 
**
*/

Public Boolean DslFramerRxGetPtr(void *gDslVars, dslFramerControl *dfCtrl, dslFramerBufDesc *pBufDesc)
{
	if (pBufDesc->bufFlags & (kDslFramerAbortFrame & kDslFramerEndOfFrame))
		DslFramerRxFlushFrame (gDslVars, dfCtrl, kDslFramerRxFrameErrAbort);

	if (pBufDesc->bufFlags & kDslFramerStartNewFrame) {
		if (NULL != dfCtrl->pRxFrame)
			DslFramerRxFlushFrame (gDslVars, dfCtrl, kDslFramerRxFrameErrPhy);

		dfCtrl->pRxFrame = DslFramerAllocateFrame(dfCtrl);
		if (NULL == dfCtrl->pRxFrame)
			return false;

		DslFrameInit (gDslVars, dfCtrl->pRxFrame);
		dfCtrl->pRxBuf		= NULL;
		dfCtrl->rxFrameLen	= 0;
		dfCtrl->pRxBufData	= NULL;
		dfCtrl->pRxBufDataEnd = NULL; 
	}

	/* find memory for phy request */

	if (dfCtrl->pRxBufData == dfCtrl->pRxBufDataEnd) {
		if (NULL == (dfCtrl->pRxBuf = DslFramerAllocateBuffer(gDslVars, dfCtrl)))
			return false;

		dfCtrl->pRxBufData = (uchar *) DslFrameBufferGetAddress(gDslVars, dfCtrl->pRxBuf);
		dfCtrl->pRxBufDataEnd = dfCtrl->pRxBufData + dfCtrl->nRxBufSize; 
	}

	pBufDesc->bufPtr = dfCtrl->pRxBufData;
	pBufDesc->bufLen = dfCtrl->pRxBufDataEnd - dfCtrl->pRxBufData;
	return true;
}

Public void	DslFramerRxDone  (void *gDslVars, dslFramerControl *dfCtrl, dslFramerBufDesc *pBufDesc)
{
	int		n, l;

	if (pBufDesc->bufFlags & kDslFramerAbortFrame) {
		DslFramerRxFlushFrame (gDslVars, dfCtrl, kDslFramerRxFrameErrAbort);
		return;
	}

	dfCtrl->pRxBufData += pBufDesc->bufLen;
	dfCtrl->rxFrameLen += pBufDesc->bufLen;

	if (dfCtrl->pRxBufData == dfCtrl->pRxBufDataEnd) {
		n = dfCtrl->nRxBufSize;
		if (pBufDesc->bufFlags & kDslFramerExtraByteMask) {
			n = (pBufDesc->bufFlags & kDslFramerExtraByteMask) >> kDslFramerExtraByteShift;
			dfCtrl->rxFrameLen -= n;
			n = dfCtrl->nRxBufSize - n;
			pBufDesc->bufFlags &= ~kDslFramerExtraByteMask;
		}
		DslFrameBufferSetLength(gDslVars, dfCtrl->pRxBuf, n);
		DslFrameEnqueBufferAtBack (gDslVars, dfCtrl->pRxFrame, dfCtrl->pRxBuf);
		dfCtrl->pRxBuf = NULL;
	}

	if (pBufDesc->bufFlags & (kDslFramerStartNewFrame | kDslFramerEndOfFrame)) {
		n = (pBufDesc->bufFlags & kDslFramerExtraByteMask) >> kDslFramerExtraByteShift;
		if (dfCtrl->rxFrameLen <= n) {
			DslFramerRxFlushFrame (gDslVars, dfCtrl, kDslFramerRxFrameErrPhy);
			return;
		}

		dfCtrl->rxFrameLen -= n;

		if (NULL != dfCtrl->pRxBuf) {
			l = dfCtrl->nRxBufSize - (dfCtrl->pRxBufDataEnd - dfCtrl->pRxBufData);
			if (l > n) {
				DslFrameBufferSetLength(gDslVars, dfCtrl->pRxBuf, l - n);
				DslFrameEnqueBufferAtBack (gDslVars, dfCtrl->pRxFrame, dfCtrl->pRxBuf);
				n = 0;
			}
			else {
				DslFramerFreeBuffer(gDslVars, dfCtrl, dfCtrl->pRxBuf);
				n -= l;
			}
			dfCtrl->pRxBuf = NULL;
		}

		if (n > 0) {
			dslFrameBuffer	*pBuf;

			pBuf = DslFrameGetLastBuffer(gDslVars, dfCtrl->pRxFrame);
			l = DslFrameBufferGetLength(gDslVars, pBuf);
			DslFrameBufferSetLength(gDslVars, pBuf, l - n);
		}

		DslFramerIndicateRecevice(gDslVars, dfCtrl, dfCtrl->pRxFrame);
	}
}

Private dslFrame * DslFramerGetTxFrame(void *gDslVars, dslFramerControl *dfCtrl)
{
	DListHeader		*p;
	dslFrameBuffer	*pTxBuf;

	dfCtrl->pTxBuf = NULL;
	p = DListFirst(&dfCtrl->dlistTxWaiting);
	while (DListValid(&dfCtrl->dlistTxWaiting,p)) {
		DListRemove(p);
		dfCtrl->pTxFrame = DslFrameGetFrameAddressFromLink(gDslVars, p);
		pTxBuf = DslFrameGetFirstBuffer (gDslVars, dfCtrl->pTxFrame);
		if (NULL != pTxBuf) {
			dfCtrl->pTxBuf = pTxBuf;
			dfCtrl->pTxBufData = (uchar *) DslFrameBufferGetAddress(gDslVars, pTxBuf);
			dfCtrl->pTxBufDataEnd = dfCtrl->pTxBufData + DslFrameBufferGetLength(gDslVars, pTxBuf);
			break;
		}
		p = DListFirst(&dfCtrl->dlistTxWaiting);
	}
	
	if (NULL == dfCtrl->pTxBuf)
		dfCtrl->pTxFrame = NULL;

	return dfCtrl->pTxFrame;
}

Public Boolean	DslFramerTxGetPtr(void *gDslVars, dslFramerControl *dfCtrl, dslFramerBufDesc *pBufDesc)
{
	dslFrameBuffer			*pTxBuf;
	int						len;

	pBufDesc->bufFlags = 0;

	do {
		if (dfCtrl->pTxBufData != dfCtrl->pTxBufDataEnd) {
			pBufDesc->bufPtr = dfCtrl->pTxBufData;
			pBufDesc->bufLen = dfCtrl->pTxBufDataEnd - dfCtrl->pTxBufData;
			return true;
		}

		if (NULL != dfCtrl->pTxBuf) {
			if (NULL != (pTxBuf = DslFrameGetNextBuffer (gDslVars, dfCtrl->pTxBuf))) {
				dfCtrl->pTxBuf = pTxBuf;
				dfCtrl->pTxBufData = (uchar *) DslFrameBufferGetAddress(gDslVars, pTxBuf);
				len = DslFrameBufferGetLength(gDslVars, pTxBuf);
				dfCtrl->pTxBufDataEnd = dfCtrl->pTxBufData + len;

				pBufDesc->bufPtr = dfCtrl->pTxBufData;
				pBufDesc->bufLen = len;
				return true;
			}
		}

		if (NULL != dfCtrl->pTxFrame)
			DslFramerSendComplete(gDslVars, dfCtrl, dfCtrl->pTxFrame);

		pBufDesc->bufFlags = kDslFramerStartNewFrame;
		dfCtrl->pTxFrame = DslFramerGetTxFrame(gDslVars, dfCtrl);
	} while (NULL != dfCtrl->pTxFrame);

	return false;
}

Public void	DslFramerTxDone(void *gDslVars, dslFramerControl *dfCtrl, dslFramerBufDesc *pBufDesc)
{
	dslFrameBuffer			*pTxBuf;

	dfCtrl->pTxBufData += pBufDesc->bufLen;
	pBufDesc->bufFlags = 0;

	if (dfCtrl->pTxBufData != dfCtrl->pTxBufDataEnd)
		return;
		
	if (NULL != dfCtrl->pTxBuf) {
		if (NULL != (pTxBuf = DslFrameGetNextBuffer (gDslVars, dfCtrl->pTxBuf))) {
			dfCtrl->pTxBuf = pTxBuf;
			dfCtrl->pTxBufData = (uchar *) DslFrameBufferGetAddress(gDslVars, pTxBuf);
			dfCtrl->pTxBufDataEnd = dfCtrl->pTxBufData + DslFrameBufferGetLength(gDslVars, pTxBuf);
			return;
		}
	}

	if (NULL != dfCtrl->pTxFrame) {
		DslFramerSendComplete(gDslVars, dfCtrl, dfCtrl->pTxFrame);
		pBufDesc->bufFlags = kDslFramerEndOfFrame;
		dfCtrl->pTxFrame = DslFramerGetTxFrame(gDslVars, dfCtrl);
	}
}

Public Boolean DslFramerTxIdle (void *gDslVars, dslFramerControl *dfCtrl)
{
	return (dfCtrl->pTxBufData == dfCtrl->pTxBufDataEnd) && (DListEmpty(&dfCtrl->dlistTxWaiting));
}

