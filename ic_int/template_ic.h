#ifndef _TEMPLATE_IC_H_
#define _TEMPLATE_IC_H_

#include <inttypes.h>

enum TEMPLATE_IC_ERROR {
	TEMPLATE_IC_NO_ERROR,
	TEMPLATE_IC_IOERROR
};

typedef struct {
	enum TEMPLATE_IC_ERROR errors;
	void *ioInt;
	uint8_t (*ioStart)(void*);
	uint8_t (*ioSend)(void*,
					  uint8_t,
					  uint8_t*
					  uint16_t);
	uint8_t (*ioTrans)(void*,
					  uint8_t,
					  uint8_t*
					  uint16_t);
	uint8_t (*ioRecv)(void*,
					  uint8_t,
					  uint8_t*
					  uint16_t);
	uint8_t (*ioFinish)(void*);
}tmpic_t;

void tmpic_initStruct(tmpic_t* inst, void* io, uint8_t (*startTrans)(void*),
		uint8_t (*sendBytes)(void*,uint8_t,uint8_t*,uint16_t),
		uint8_t (*transBytes)(void*,uint8_t,uint8_t*,uint16_t),
		uint8_t (*getBytes)(void*,uint8_t,uint8_t*,uint16_t),uint8_t (*endTrans)(void*));

uint8_t tmpic_initChip(tmpic_t* inst);

void tmpic_writeReg(tmpic_t* inst, uint8_t regAddr, uint8_t value);
uint8_t tmpic_readReg(tmpic_t* inst, uint8_t regAddr);

#endif /* _TEMPLATE_IC_H_ */