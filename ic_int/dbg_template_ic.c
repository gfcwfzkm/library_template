#include "dbg_template_ic.h"

static tmpic_t *pList;
static uint8_t pCnt;
static uint8_t pSel;

static void gshell_cmd_dbg_tmpic(uint8_t argc, char *argv[])
{
	tmpic_t *pInst;
	// Generic temporary variables
	uint8_t u8RegVal, u8RegAddr;

	if (pCnt == 0)
	{
		gshell_putString_f("Not properly initialised - pCnt = 0!"G_CRLF);
		return;
	}
	else
	{
		pInst = (pList + pSel);
	}
	
	pInst->errors = PCA9685_NO_ERROR;

	if ((pCnt > 1) && (argc > 1) && (strncmp(argv[1], "select", 20) == 0))
	{
		if (argc > 2)
		{
			u8RegVal = (uint8_t)strtol(argv[2], NULL, 0);

			if (u8RegVal < pCnt)
			{
				gshell_printf_f("SENSOR-Chip %u deselected and %u selected!"G_CRLF, selPCA, u8RegVal);
				selPCA = u8RegVal;
			}
			else
			{
				gshell_printf_f("Value too high, choose a SENSOR-Chip between 0 and %u!"G_CRLF, pCnt);
			}
		}
		else
		{
			gshell_printf_f("%u SENSOR-Chips to select from, Chip %u currently selected."G_CRLF, pCnt, pSel);
		}
	}
	else if ((argc > 3) && (strncmp(argv[1], "write", 20) == 0))
	{
		u8RegAddr = (uint8_t)strtol(argv[2], NULL, 0);
		u8RegVal = (uint8_t)strtol(argv[3], NULL, 0);

		tmpic_writeReg(pInst, u8RegAddr, u8RegVal);

		gshell_printf_f("Value 0x%02X (%u) written into register 0x%02X."G_CRLF, u8RegVal, u8RegVal, u8RegAddr);
	}
	else if ((argc > 2) && (strncmp(argv[1], "read", 20) == 0))
	{
		u8RegAddr = (uint8_t)strtol(argv[2], NULL, 0);

		u8RegVal = tmpic_readReg(pInst, u8RegAddr);

		gshell_printf_f("Register 0x%02X contains the value 0x%02X (%u)."G_CRLF, u8RegAddr, u8RegVal, u8RegVal);
	}
	else
	{
		// Hilfe / Befehlsübersicht
		gshell_putString_f(G_TEXTBOLD G_TEXTUNDERL "TEMPLATE_IC Debug Module" G_TEXTNORMAL G_CRLF
		"select <val>      Select the SENSOR chip (if there are multiple) or"G_CRLF
		"                  returns the amount of SENSOR chips and the currently selected one."G_CRLF
		"write <reg> <val> Writes into the register <reg> the value <val>"G_CRLF
		"read <reg>        Reads the value of the register <reg> and prints it"G_CRLF);
	}
}

static gshell_cmd_t dbg_pca = 
{
	G_XARR("pca9685"),
	gshell_cmd_dbg_tmpic,
	G_XARR("PCA9685 Debugging and Monitoring"),
	NULL
};

gshell_cmd_t* dbg_tmpic_init(tmpic_t *pArr, uint8_t pCount)
{
	pList = pArr;
	pCnt = pCount;
	pSel = 0;

	return &dbg_pca;
}
