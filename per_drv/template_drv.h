/* Template driver file. To easily change names, search & replace 
 * TEMPLATE_DRV and tmpdrv
 */

#ifndef _TEMPLATE_DRV_H_
#define _TEMPLATE_DRV_H_

#include <inttypes.h>
/* ADDITIONAL INCLUDES HERE */

typedef struct {
    /* Struct template to hold interface informations */
}TEMPLATE_DRV_t

uint8_t tmpdrv_init(TEMPLATE_DRV_t *drv); 

/* Add driver-specific interface functions */

/* Pazzy's standard library interface
 * For more see:
 * https://github.com/gfcwfzkm/library_template/blob/main/INTERFACE.md */
uint8_t tmpdrv_InterfacePrepare(void *inttmpdrv);

uint8_t tmpdrv_InterfaceSendBytes(void *inttmpdrv,
								uint8_t addr,
								uint8_t *buf_ptr,
								uint16_t buf_len);

uint8_t tmpdrv_InterfaceTransceiveBytes(void *inttmpdrv,
								uint8_t addr,
								uint8_t *buf_ptr,
								uint16_t buf_len);

uint8_t tmpdrv_InterfaceGetBytes(void *inttmpdrv,
								uint8_t addr,
								uint8_t *buf_ptr,
								uint16_t buf_len);

uint8_t tmpdrv_InterfaceFinish(void *inttmpdrv);

#endif /* _TEMPLATE_DRV_H_ */