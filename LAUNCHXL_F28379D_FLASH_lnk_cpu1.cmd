MEMORY
{
PAGE 0 :  /* Program Memory */
	/* Memory (RAM/FLASH) blocks can be moved to PAGE1 for data allocation */
	RESET           	: origin = 0x3FFFC0, length = 0x000002
   
#ifdef __TI_COMPILER_VERSION__
	#if __TI_COMPILER_VERSION__ >= 20012000
GROUP {      /* GROUP memory ranges for crc/checksum of entire flash */
	#endif
#endif

	/* BEGIN is used for the "boot to Flash" bootloader mode   */
	BEGIN				: origin = 0x080000, length = 0x000002
	BEGIN_FLASH			: origin = 0x090000, length = 0x000002

	/* Flash sectors */
	//	Boot-Loader
	FLASHA				: origin = 0x080002, length = 0x00FFFE	//	0x001FFE
	//	Application
	FLASHB				: origin = 0x090002, length = 0x02FFFE	//	0x007FFE


#ifdef __TI_COMPILER_VERSION__
	#if __TI_COMPILER_VERSION__ >= 20012000
}  crc(_table_name, algorithm=C28_CHECKSUM_16)
	#endif
#endif

PAGE 1 : /* Data Memory */
	/* Memory (RAM/FLASH) blocks can be moved to PAGE0 for program allocation */

	BOOT_RSVD	: origin = 0x000002, length = 0x000120	/* Part of M0, BOOT rom will use this for stack */

	RAMM0		: origin = 0x000122, length = 0x0006DE	// 0x2DE	/* on-chip RAM block M1 */
   	//RAMM1		: origin = 0x000400, length = 0x000400

	RAMD0		: origin = 0x00B000, length = 0x001000	//	0x800
   	//RAMD1		: origin = 0x00B800, length = 0x000800

	/*Local memory*/
	//	CLA Program
	RAMLS0		: origin = 0x008000, length = 0x001000
	//	CLA Data
	RAMLS2		: origin = 0x009000, length = 0x002000

#ifdef CPU1
	//	CPU1 Using
	RAMGS0	   	: origin = 0x00C000, length = 0x008000
#else
	//	CPU2 Using
	RAMGS8      : origin = 0x014000, length = 0x008000
#endif

   	CPU2TOCPU1RAM	: origin = 0x03F800, length = 0x000400
   	CPU1TOCPU2RAM   : origin = 0x03FC00, length = 0x000400
}


SECTIONS
{
   	/* Allocate program areas: */
   	.cinit              : > FLASHB      						PAGE = 0, ALIGN(4)
   	.pinit              : > FLASHB      						PAGE = 0, ALIGN(4)
   	.text               : > FLASHB								PAGE = 0, ALIGN(4)
   	codestart           : > BEGIN_FLASH							PAGE = 0, ALIGN(4)

#ifdef __TI_COMPILER_VERSION__
	#if __TI_COMPILER_VERSION__ >= 15009000
    .TI.ramfunc : {}
						LOAD = FLASHB,
#ifdef CPU1
						RUN = RAMGS0,
#else
						RUN = RAMGS8,
#endif
						LOAD_START(_RamfuncsLoadStart),
						LOAD_SIZE(_RamfuncsLoadSize),
						LOAD_END(_RamfuncsLoadEnd),
						RUN_START(_RamfuncsRunStart),
						RUN_SIZE(_RamfuncsRunSize),
						RUN_END(_RamfuncsRunEnd),
						PAGE = 0, ALIGN(4)
	#else
	ramfuncs :
						LOAD = FLASHB,
#ifdef CPU1
						RUN = RAMGS0,
#else
						RUN = RAMGS8,
#endif
						LOAD_START(_RamfuncsLoadStart),
						LOAD_SIZE(_RamfuncsLoadSize),
						LOAD_END(_RamfuncsLoadEnd),
						RUN_START(_RamfuncsRunStart),
						RUN_SIZE(_RamfuncsRunSize),
						RUN_END(_RamfuncsRunEnd),
						PAGE = 0, ALIGN(4)
   #endif
#endif
						 
	/* Allocate uninitalized data sections: */
	.stack				: >	RAMM1		PAGE = 1
	.ebss				: >	RAMGS0		PAGE = 1
	.esysmem			: >	RAMGS0		PAGE = 1

	/* Initalized sections go in Flash */
	.econst				: > FLASHB		PAGE = 0, ALIGN(4)
	.switch				: > FLASHB		PAGE = 0, ALIGN(4)

	.reset				: > RESET		PAGE = 0, TYPE = DSECT /* not used, */

	Filter_RegsFile		: > RAMGS0		PAGE = 1

	SHARERAMGS0			: > RAMGS0		PAGE = 1
	SHARERAMGS1			: > RAMGS0		PAGE = 1

	/* The following section definitions are required when using the IPC API Drivers */
	GROUP : > CPU1TOCPU2RAM, PAGE = 1
	{
		PUTBUFFER
		PUTWRITEIDX
		GETREADIDX
	}

	GROUP : > CPU2TOCPU1RAM, PAGE = 1
	{
		GETBUFFER :    TYPE = DSECT
		GETWRITEIDX :  TYPE = DSECT
		PUTREADIDX :   TYPE = DSECT
	}

	/* crc/checksum section configured as COPY section to avoid including in executable */
	.TI.memcrc          : type = COPY
}

/*
//===========================================================================
// End of file.
//===========================================================================
*/
