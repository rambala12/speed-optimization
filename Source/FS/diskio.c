/*-----------------------------------------------------------------------*/
/* Low level disk I/O module skeleton for Petit FatFs (C)ChaN, 2014      */
/*-----------------------------------------------------------------------*/

#include "diskio.h"
#include "sd_io.h"
#include <string.h>

SD_DEV dev;
int start = 1;

/*-----------------------------------------------------------------------*/
/* Initialize Disk Drive                                                 */
/*-----------------------------------------------------------------------*/

DSTATUS disk_initialize(void) {
	DSTATUS stat;

	if (SD_Init(&dev) != SD_OK) {
		stat = RES_ERROR;
	} else {
		stat = RES_OK;
	}

	return stat;
}




/*-----------------------------------------------------------------------*/
/* Read Partial Sector                                                   */
/*-----------------------------------------------------------------------*/
DRESULT disk_readp(BYTE * buff,	/* Pointer to the destination object */
									 DWORD sector,	/* Sector number (LBA) */
									 UINT offset,	/* Offset in the sector */
									 UINT count		/* Byte count (bit15:destination) */
		) {
	DRESULT res;
	// SD_Read reads entire block, but only stores count bytes starting at offset
			// selectively read from array
			// initially go through SD_Read once and store sector 
			// check sector, if sector changes then do SD read one more time
			
	// set static variables for prev_sector and static array
	static DWORD prev_sector;
	static BYTE buffy[512];
	// copy information into buffy
	
	
	if (start == 1) {
		// initial time calling SD_Read
		if (SD_Read(&dev, buffy, sector, 0, 512) != SD_OK) {
			res = RES_ERROR;
		} else {
			res = RES_OK;
		}
		start = 0;
	} else if (prev_sector != sector) {
		if (SD_Read(&dev, buffy, sector, 0, 512) != SD_OK) {
			res = RES_ERROR;
		} else {
			res = RES_OK;
		}
	} else {
		res = RES_OK;
	}
	// update information buff
	for (int i = 0; i < count; i++) {
		buff[i] = buffy[i + offset];
	} 
	prev_sector = sector;
	return res;
}

/*-----------------------------------------------------------------------*/
/* Write Partial Sector                                                  */
/*-----------------------------------------------------------------------*/

DRESULT disk_writep(const BYTE * buff,	/* Pointer to the data to be written, NULL:Initiate/Finalize write operation */
										DWORD sc		/* Sector number (LBA) or Number of bytes to send */
		) {
	DRESULT res;


	// AD
	// TODO: Need to port. SD_Write writes an entire sector, needs to be modified to just write specified number of bytes
	// Look into PFFS ports to see how this is done
	if (!buff) {
		if (sc) {

			// Initiate write process

		} else {

			// Finalize write process

		}
	} else {

		// Send data to the disk

	}

	return res;
}
