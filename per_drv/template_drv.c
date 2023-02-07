#include "template_drv.h"

uint8_t tmpdrv_init(TEMPLATE_DRV_t *drv)
{

}

uint8_t tmpdrv_InterfacePrepare(void *inttmpdrv)
{
	TEMPLATE_DRV_t *tmpdrv = (TEMPLATE_DRV_t*)inttmpdrv;
	
	// Apply initialisation or changes to the peripheral here

	return 0;
}

uint8_t tmpdrv_InterfaceSendBytes(void *inttmpdrv, uint8_t addr,
									uint8_t *buf_ptr, uint16_t buf_len)
{
	TEMPLATE_DRV_t *tmpdrv = (TEMPLATE_DRV_t*)inttmpdrv;
	uint32_t byteCnt;
	
	if (addr != 0)	tmpdrv_transfer(tmpdrv, addr);
	
	for(byteCnt = 0; byteCnt < buf_len; byteCnt++)
	{
		tmpdrv_transfer(tmpdrv,buf_ptr[byteCnt]);
	}
	
	return 0;
}

uint8_t tmpdrv_InterfaceTransceiveBytes(void *inttmpdrv, uint8_t addr,
									uint8_t *buf_ptr, uint16_t buf_len)
{
	TEMPLATE_DRV_t *tmpdrv = (TEMPLATE_DRV_t*)inttmpdrv;
	uint32_t byteCnt;
	
	if (addr != 0)	tmpdrv_transfer(tmpdrv, addr);
	
	for(byteCnt = 0; byteCnt < buf_len; byteCnt++)
	{
		buf_ptr[byteCnt] = tmpdrv_transfer(tmpdrv,buf_ptr[byteCnt]);
	}
	
	return 0;
}

uint8_t tmpdrv_InterfaceGetBytes(void *inttmpdrv, uint8_t addr,
									uint8_t *buf_ptr, uint16_t buf_len)
{
	TEMPLATE_DRV_t *tmpdrv = (TEMPLATE_DRV_t*)inttmpdrv;
	uint32_t byteCnt;
	
	if (addr != 0)	tmpdrv_transfer(tmpdrv, addr);
	
	for(byteCnt = 0; byteCnt < buf_len; byteCnt++)
	{
		buf_ptr[byteCnt] = tmpdrv_transfer(tmpdrv,0);
	}
	
	return 0;
}

uint8_t tmpdrv_InterfaceFinish(void *inttmpdrv)
{
	TEMPLATE_DRV_t *tmpdrv = (TEMPLATE_DRV_t*)inttmpdrv;
	
	// Apply de-initialisation here
	
	return 0;
}