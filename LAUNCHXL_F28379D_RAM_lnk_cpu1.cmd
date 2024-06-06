
MEMORY
{
PAGE 0 :
	/* BEGIN is used for the "boot to SARAM" bootloader mode   */

   	BEGIN			: origin = 0x000000, length = 0x000002
   	//RAMM0			: origin = 0x000122, length = 0x0002DE
   	//RAMD0			: origin = 0x00B000, length = 0x000800
   	//RAMLS0			: origin = 0x008000, length = 0x001000	//	CLA Program
   	//RAMLS2			: origin = 0x009000, length = 0x002000	//	CLA Data
   	RESET			: origin = 0x3FFFC0, length = 0x000002

   	BOOT_RSVD		: origin = 0x000002, length = 0x000120     /* Part of M0, BOOT rom will use this for stack */
   	RAMM1			: origin = 0x000400, length = 0x000400     /* on-chip RAM block M1 */
	RAMD			: origin = 0x00B000, length = 0x001000
	RAMLS			: origin = 0x008000, length = 0x003000
	RAMGS			: origin = 0x00C000, length = 0x010000
   	CANA_MSG_RAM  	: origin = 0x049000, length = 0x000800
	CANB_MSG_RAM   	: origin = 0x04B000, length = 0x000800
}


SECTIONS
{
   	codestart		: > 	BEGIN,     		PAGE = 0
   	.text			: >>	RAMD1 | RAMGS,	PAGE = 0
   	.cinit			: > 	RAMGS,     		PAGE = 0
   	.pinit			: > 	RAMGS,     		PAGE = 0
   	.switch			: > 	RAMGS,     		PAGE = 0
   	.reset			: > 	RESET,     		PAGE = 0, TYPE = DSECT /* not used, */

   	.stack  		: > 	RAMM1,     		PAGE = 0
   	.ebss   		: > 	RAMGS,    		PAGE = 0
   	.econst			: > 	RAMGS,    		PAGE = 0
   	.esysmem  		: > 	RAMGS,    		PAGE = 0

   	ramgs0   		: > 	RAMGS,    		PAGE = 0
   	ramgs1   		: > 	RAMGS,    		PAGE = 0


#ifdef __TI_COMPILER_VERSION__
   #if __TI_COMPILER_VERSION__ >= 15009000
    .TI.ramfunc : {} > RAMGS,      PAGE = 0
   #else
   ramfuncs         : > RAMGS      PAGE = 0
   #endif
#endif

	ramgs0 			: > RAMGS

   /* The following section definitions are for SDFM examples */
   Filter1_RegsFile : > RAMGS,	PAGE =0, fill=0x1111
   Filter2_RegsFile : > RAMGS,	PAGE =0, fill=0x2222
   Filter3_RegsFile : > RAMGS,	PAGE = 0, fill=0x3333
   Filter4_RegsFile : > RAMGS,	PAGE = 0, fill=0x4444
   Difference_RegsFile : >RAMGS, 	PAGE = 0, fill=0x3333
}

/*
//===========================================================================
// End of file.
//===========================================================================
*/
