/**
 * PCA9685 Debugging Module
 * 
 * Additional debugging library to link the PWM-Chip command to the gshell terminal library.
 * Allows direct access via the terminal library to the PCA9685's registers.
 */

#ifndef _DBG_TEMPLATE_IC_H_
#define _DBG_TEMPLATE_IC_H_

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "template_ic.h"
#include "gshell.h"

/** @brief Debugging Module for the TEMPLATE_IC
 *
 * Initialises the debugging module with a pointer to one (or an array) or TEMPLATE_IC structs,
 * together with the amount of structs pointed at.
 * Returns a pointer to an gshell command, which can be passed over to the gshell library 
 * to access it.
 *
 * This allows one or multiple TEMPLATE_IC chips to be directly manipulated via a terminal.
 * 
 * @params pArr		Pointer to the TEMPLATE_IC struct(s)
 * @params pcaCount	Amount of structures pointed to
 * @returns			gshell command instance
 */
gshell_cmd_t* dbg_tmpic_init(tmpic_t *pArr, uint8_t pCount);

#endif /* _DBG_TEMPLATE_IC_H_ */
