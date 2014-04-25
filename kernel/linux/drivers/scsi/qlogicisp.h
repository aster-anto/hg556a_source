/*
 * QLogic ISP1020 Intelligent SCSI Processor Driver (PCI)
 * Written by Erik H. Moe, ehm@cris.com
 * Copyright 1995, Erik H. Moe
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2, or (at your option) any
 * later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 */

/* Renamed and updated to 1.3.x by Michael Griffith <grif@cs.ucr.edu> */

/*
 * $Date: 2008/08/26 03:55:43 $
 * $Revision: 1.1 $
 *
 * $Log: qlogicisp.h,v $
 * Revision 1.1  2008/08/26 03:55:43  l65130
 * 【变更分类】建立基线
 * 【问题单号】
 * 【问题描述】
 * 【修改说明】
 *
 * Revision 1.1  2008/06/20 09:26:22  z67625
 * *** empty log message ***
 *
 * Revision 1.1  2008/01/14 05:53:07  z30370
 * *** empty log message ***
 *
 * Revision 1.1  2006/12/20 19:23:18  d55909
 * *** empty log message ***
 *
 * Revision 1.1  2006/11/14 17:10:36  d55909
 * 新建模块
 *
 * Revision 1.1  2006/04/19 05:32:30  z60003055
 * z60003055：新增BCM306 版本代码基线
 *
 * Revision 0.5  1995/09/22  02:32:56  root
 * do auto request sense
 *
 * Revision 0.4  1995/08/07  04:48:28  root
 * supply firmware with driver.
 * numerous bug fixes/general cleanup of code.
 *
 * Revision 0.3  1995/07/16  16:17:16  root
 * added reset/abort code.
 *
 * Revision 0.2  1995/06/29  03:19:43  root
 * fixed biosparam.
 * added queue protocol.
 *
 * Revision 0.1  1995/06/25  01:56:13  root
 * Initial release.
 *
 */

#ifndef _QLOGICISP_H
#define _QLOGICISP_H

/*
 * With the qlogic interface, every queue slot can hold a SCSI
 * command with up to 4 scatter/gather entries.  If we need more
 * than 4 entries, continuation entries can be used that hold
 * another 7 entries each.  Unlike for other drivers, this means
 * that the maximum number of scatter/gather entries we can
 * support at any given time is a function of the number of queue
 * slots available.  That is, host->can_queue and host->sg_tablesize
 * are dynamic and _not_ independent.  This all works fine because
 * requests are queued serially and the scatter/gather limit is
 * determined for each queue request anew.
 */
#define QLOGICISP_REQ_QUEUE_LEN	63	/* must be power of two - 1 */
#define QLOGICISP_MAX_SG(ql)	(4 + ((ql) > 0) ? 7*((ql) - 1) : 0)

int isp1020_detect(Scsi_Host_Template *);
int isp1020_release(struct Scsi_Host *);
const char * isp1020_info(struct Scsi_Host *);
int isp1020_queuecommand(Scsi_Cmnd *, void (* done)(Scsi_Cmnd *));
int isp1020_abort(Scsi_Cmnd *);
int isp1020_reset(Scsi_Cmnd *, unsigned int);
int isp1020_biosparam(struct scsi_device *, struct block_device *,
		sector_t, int[]);
#endif /* _QLOGICISP_H */
