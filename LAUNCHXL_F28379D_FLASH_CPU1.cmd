CLA_SCRATCHPAD_SIZE = 0x100;
--undef_sym=__cla_scratchpad_end
--undef_sym=__cla_scratchpad_start

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
	BEGIN           	: origin = 0x080000, length = 0x000002
	/* Flash sectors */
	FLASH				: origin = 0x080002, length = 0x07DFFE	/* on-chip Flash */
	FLASHBB				: origin = 0x0FE000, length = 0x001FF0	/* on-chip Flash */
	FLASHBB_DO_NOT_USE	: origin = 0x0FFFF0, length = 0x000010    /* Reserve and do not use for code as per the errata advisory "Memory: Prefetching Beyond Valid Memory" */
#ifdef __TI_COMPILER_VERSION__
  #if __TI_COMPILER_VERSION__ >= 20012000
}  crc(_ccs_flash_checksum, algorithm=C28_CHECKSUM_16)
  #endif
#endif   

	/* Memory (RAM/FLASH) blocks can be moved to PAGE0 for program allocation */
	RAMM			: origin = 0x000002, length = 0x0017FE		//0x0006DE
	RAMD			: origin = 0x00B000, length = 0x001000
	RAMLS			: origin = 0x008000, length = 0x003000
	RAMGS			: origin = 0x00C000, length = 0x010000

   	CANA_MSG_RAM  	: origin = 0x049000, length = 0x000800
	CANB_MSG_RAM   	: origin = 0x04B000, length = 0x000800
}

SECTIONS
{
	/* Allocate program areas: */
	.cinit				: > FLASH		PAGE = 0, ALIGN(8)
	.pinit				: > FLASH		PAGE = 0, ALIGN(8)
	.text				: > FLASH		PAGE = 0, ALIGN(8)
	codestart			: > BEGIN		PAGE = 0, ALIGN(8)
                         
#ifdef __TI_COMPILER_VERSION__
	#if __TI_COMPILER_VERSION__ >= 15009000
	.TI.ramfunc			: {} LOAD = FLASH,
						RUN = RAMGS,
						LOAD_START(_RamfuncsLoadStart),
						LOAD_SIZE(_RamfuncsLoadSize),
						LOAD_END(_RamfuncsLoadEnd),
						RUN_START(_RamfuncsRunStart),
						RUN_SIZE(_RamfuncsRunSize),
						RUN_END(_RamfuncsRunEnd),
						PAGE = 0, ALIGN(8)
	#else
	ramfuncs			: LOAD = FLASH,
						RUN = RAMGS,
						LOAD_START(_RamfuncsLoadStart),
						LOAD_SIZE(_RamfuncsLoadSize),
						LOAD_END(_RamfuncsLoadEnd),
						RUN_START(_RamfuncsRunStart),
						RUN_SIZE(_RamfuncsRunSize),
						RUN_END(_RamfuncsRunEnd),
						PAGE = 0, ALIGN(8)
	#endif
#endif
						 
	/* Allocate uninitalized data sections: */
	.stack		: > RAMM	PAGE = 0
	.ebss		: > RAMLS	PAGE = 0
	.esysmem	: > RAMLS	PAGE = 0

	/* Initalized sections go in Flash */
	.econst		: > FLASH	PAGE = 0, ALIGN(8)
	.switch		: > FLASH	PAGE = 0, ALIGN(8)
	.reset		: > RESET	PAGE = 0, TYPE = DSECT /* not used, */
   
	/* crc/checksum section configured as COPY section to avoid including in executable */
	.TI.memcrc	: type = COPY

	CLAscratch	:
				{ *.obj(CLAscratch)
				. += CLA_SCRATCHPAD_SIZE;
				*.obj(CLAscratch_end) } >  RAMLS,  PAGE = 0

	.scratchpad		: > RAMLS,       PAGE = 0
	.bss_cla		: > RAMLS,       PAGE = 0
	.const_cla		: > RAMLS,       PAGE = 0

	ramgs0 			: > RAMGS

	/* CLA specific sections */
	CLA1mathTables	: > RAMLS, PAGE=0

	Cla1Prog		: > RAMLS, PAGE=0

	CLADataLS0		: > RAMLS, PAGE=0
	CLADataLS1		: > RAMLS, PAGE=0

	Cla1ToCpuMsgRAM	: > RAMLS, PAGE = 0
	CpuToCla1MsgRAM	: > RAMLS, PAGE = 0
}

/*
//===========================================================================
// End of file.
//===========================================================================
*/
