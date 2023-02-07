#include "template_ic.h"

void tmpic_initStruct(tmpic_t* inst, uint8_t i2cAddr, void* io, uint8_t (*startTrans)(void*), uint8_t (*sendBytes)(void*,uint8_t,uint8_t*,uint16_t),uint8_t (*transBytes)(void*,uint8_t,uint8_t*,uint16_t),uint8_t (*getBytes)(void*,uint8_t,uint8_t*,uint16_t),uint8_t (*endTrans)(void*))
{
	inst->errors = TEMPLATE_IC_NO_ERROR;
	inst->ioInt = io;
	inst->ioStart = startTrans;
	inst->ioSend = sendBytes;
    inst->ioTrans = transBytes;
	inst->ioRecv = getBytes;
	inst->ioFinish = endTrans;
}

uint8_t tmpic_initChip(tmpic_t* inst)
{
	inst->errors = TEMPLATE_IC_NO_ERROR;

	/* Perform initialisation of the chip here */

	return inst->errors;
}

void tmpic_writeReg(tmpic_t* inst, uint8_t regAddr, uint8_t value)
{
	uint8_t dataPackage[2] = {regAddr, value};

	inst->ioStart(inst->ioInt);
	inst->errors |= inst->ioSend(inst->ioInt, 0 /*ADDRESS*/, dataPackage, 2);
    // OR...
	inst->errors |= inst->ioTrans(inst->ioInt, 0 /*ADDRESS*/, dataPackage, 2);
	inst->ioFinish(inst->ioInt);
}

uint8_t tmpic_readReg(tmpic_t* inst, uint8_t regAddr)
{
	uint8_t dataPackage = regAddr;

	inst->ioStart(inst->ioInt);

	inst->errors |= inst->ioSend(inst->ioInt, 0 /*ADDRESS*/, &dataPackage, 1);
	inst->errors |= inst->ioRecv(inst->ioInt, 0 /*ADDRESS*/, &dataPackage, 1);
    // OR...    
	inst->errors |= inst->ioTrans(inst->ioInt, 0 /*ADDRESS*/, &dataPackage, 1);

	
	inst->ioFinish(inst->ioInt);

	return dataPackage;
}