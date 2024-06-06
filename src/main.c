//###########################################################################
//
// FILE:    main.c
//
// TITLE:   Sysinteck_NPC Base Project program.
//
//###########################################################################
//  TI Release: F2837xD Support Library v210
//  Release Date: 22.10.23
//###########################################################################

/*
 *  Include
 */
#include "main.h"

/*
 *  @brief
 *      Main Function
 *  @param
 *      None
 *  @retval
 *      None
 */
void main(void)
{
    //  initialize Board
    init_board();

    //  Global Variable Initialize
    init_var();

    //  User Application Initialize
    init_app();

    //  Loop
    while(1)
    {
        main_routine();
    }
}

