/*
 * (C) Copyright 2013
 * NVIDIA Corporation <www.nvidia.com>
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#ifndef _PINMUX_CONFIG_VENICE2_H_
#define _PINMUX_CONFIG_VENICE2_H_

#define DEFAULT_PINMUX(_pingrp, _mux, _pull, _tri, _io)		\
	{							\
		.pingrp		= PMUX_PINGRP_##_pingrp,	\
		.func		= PMUX_FUNC_##_mux,		\
		.pull		= PMUX_PULL_##_pull,		\
		.tristate	= PMUX_TRI_##_tri,		\
		.io		= PMUX_PIN_##_io,		\
		.lock		= PMUX_PIN_LOCK_DEFAULT,	\
		.od		= PMUX_PIN_OD_DEFAULT,		\
		.ioreset	= PMUX_PIN_IO_RESET_DEFAULT,	\
	}

#define I2C_PINMUX(_pingrp, _mux, _pull, _tri, _io, _lock, _od)	\
	{							\
		.pingrp		= PMUX_PINGRP_##_pingrp,	\
		.func		= PMUX_FUNC_##_mux,		\
		.pull		= PMUX_PULL_##_pull,		\
		.tristate	= PMUX_TRI_##_tri,		\
		.io		= PMUX_PIN_##_io,		\
		.lock		= PMUX_PIN_LOCK_##_lock,	\
		.od		= PMUX_PIN_OD_##_od,		\
		.ioreset	= PMUX_PIN_IO_RESET_DEFAULT,	\
	}

#define DDC_PINMUX(_pingrp, _mux, _pull, _tri, _io, _lock, _rcv_sel) \
	{							\
		.pingrp		= PMUX_PINGRP_##_pingrp,	\
		.func		= PMUX_FUNC_##_mux,		\
		.pull		= PMUX_PULL_##_pull,		\
		.tristate	= PMUX_TRI_##_tri,		\
		.io		= PMUX_PIN_##_io,		\
		.lock		= PMUX_PIN_LOCK_##_lock,	\
		.rcv_sel	= PMUX_PIN_RCV_SEL_##_rcv_sel,	\
		.ioreset	= PMUX_PIN_IO_RESET_DEFAULT,	\
	}

#define VI_PINMUX(_pingrp, _mux, _pull, _tri, _io, _lock, _ioreset) \
	{							\
		.pingrp		= PMUX_PINGRP_##_pingrp,	\
		.func		= PMUX_FUNC_##_mux,		\
		.pull		= PMUX_PULL_##_pull,		\
		.tristate	= PMUX_TRI_##_tri,		\
		.io		= PMUX_PIN_##_io,		\
		.lock		= PMUX_PIN_LOCK_##_lock,	\
		.od		= PMUX_PIN_OD_DEFAULT,		\
		.ioreset	= PMUX_PIN_IO_RESET_##_ioreset	\
	}

#define CEC_PINMUX(_pingrp, _mux, _pull, _tri, _io, _lock, _od)	\
	{							\
		.pingrp     = PMUX_PINGRP_##_pingrp,		\
		.func       = PMUX_FUNC_##_mux,			\
		.pull       = PMUX_PULL_##_pull,		\
		.tristate   = PMUX_TRI_##_tri,			\
		.io         = PMUX_PIN_##_io,			\
		.lock       = PMUX_PIN_LOCK_##_lock,		\
		.od         = PMUX_PIN_OD_##_od,		\
		.ioreset    = PMUX_PIN_IO_RESET_DEFAULT,	\
	}

#define USB_PINMUX CEC_PINMUX

#define DEFAULT_PADCFG(_drvgrp, _slwf, _slwr, _drvup, _drvdn, _lpmd, _schmt, _hsm) \
	{						\
		.drvgrp = PMUX_DRVGRP_##_drvgrp,	\
		.slwf   = _slwf,			\
		.slwr   = _slwr,			\
		.drvup  = _drvup,			\
		.drvdn  = _drvdn,			\
		.lpmd   = PMUX_LPMD_##_lpmd,		\
		.schmt  = PMUX_SCHMT_##_schmt,		\
		.hsm    = PMUX_HSM_##_hsm,		\
	}

static struct pmux_pingrp_config tegra124_pinmux_common[] = {
	/* EXTPERIPH1 pinmux */
	DEFAULT_PINMUX(DAP_MCLK1_PW4,     EXTPERIPH1,  NORMAL,    NORMAL,   OUTPUT),

	/* I2S0 pinmux */
	DEFAULT_PINMUX(DAP1_DIN_PN1,      I2S0,        NORMAL,    TRISTATE, INPUT),
	DEFAULT_PINMUX(DAP1_DOUT_PN2,     I2S0,        NORMAL,    NORMAL,   INPUT),
	DEFAULT_PINMUX(DAP1_FS_PN0,       I2S0,        NORMAL,    NORMAL,   INPUT),
	DEFAULT_PINMUX(DAP1_SCLK_PN3,     I2S0,        NORMAL,    NORMAL,   INPUT),

	/* I2S1 pinmux */
	DEFAULT_PINMUX(DAP2_DIN_PA4,      I2S1,        NORMAL,    TRISTATE, INPUT),
	DEFAULT_PINMUX(DAP2_DOUT_PA5,     I2S1,        NORMAL,    NORMAL,   INPUT),
	DEFAULT_PINMUX(DAP2_FS_PA2,       I2S1,        NORMAL,    NORMAL,   INPUT),
	DEFAULT_PINMUX(DAP2_SCLK_PA3,     I2S1,        NORMAL,    NORMAL,   INPUT),

	/* I2S3 pinmux */
	DEFAULT_PINMUX(DAP4_DIN_PP5,      I2S3,        NORMAL,    NORMAL,   INPUT),
	DEFAULT_PINMUX(DAP4_DOUT_PP6,     I2S3,        NORMAL,    NORMAL,   INPUT),
	DEFAULT_PINMUX(DAP4_FS_PP4,       I2S3,        NORMAL,    NORMAL,   INPUT),
	DEFAULT_PINMUX(DAP4_SCLK_PP7,     I2S3,        NORMAL,    NORMAL,   INPUT),

	/* CLDVFS pinmux */
	DEFAULT_PINMUX(DVFS_PWM_PX0,      CLDVFS,      NORMAL,    NORMAL,   OUTPUT),
	DEFAULT_PINMUX(DVFS_CLK_PX2,      CLDVFS,      NORMAL,    NORMAL,   OUTPUT),

	/* ULPI pinmux */
	DEFAULT_PINMUX(ULPI_DATA0_PO1,    ULPI,        NORMAL,    NORMAL,   INPUT),
	DEFAULT_PINMUX(ULPI_DATA1_PO2,    ULPI,        NORMAL,    NORMAL,   INPUT),
	DEFAULT_PINMUX(ULPI_DATA2_PO3,    ULPI,        NORMAL,    NORMAL,   INPUT),
	DEFAULT_PINMUX(ULPI_DATA3_PO4,    ULPI,        NORMAL,    NORMAL,   INPUT),
	DEFAULT_PINMUX(ULPI_DATA4_PO5,    ULPI,        UP,        NORMAL,   INPUT),
	DEFAULT_PINMUX(ULPI_DATA5_PO6,    ULPI,        UP,        NORMAL,   INPUT),
	DEFAULT_PINMUX(ULPI_DATA6_PO7,    ULPI,        NORMAL,    NORMAL,   INPUT),

	/* EC KBC/SPI */
	DEFAULT_PINMUX(ULPI_CLK_PY0,      SPI1,        UP,        NORMAL,   INPUT),
	DEFAULT_PINMUX(ULPI_DIR_PY1,      SPI1,        UP,        NORMAL,   INPUT),
	DEFAULT_PINMUX(ULPI_NXT_PY2,      SPI1,        NORMAL,    NORMAL,   INPUT),
	DEFAULT_PINMUX(ULPI_STP_PY3,      SPI1,        NORMAL,    NORMAL,   INPUT),

	/* I2C3 (TPM) pinmux */
	I2C_PINMUX(CAM_I2C_SCL_PBB1, I2C3, NORMAL, NORMAL, INPUT, DEFAULT, ENABLE),
	I2C_PINMUX(CAM_I2C_SDA_PBB2, I2C3, NORMAL, NORMAL, INPUT, DEFAULT, ENABLE),

	/* I2C2 pinmux */
	I2C_PINMUX(GEN2_I2C_SCL_PT5, I2C2, NORMAL, NORMAL, INPUT, DEFAULT, ENABLE),
	I2C_PINMUX(GEN2_I2C_SDA_PT6, I2C2, NORMAL, NORMAL, INPUT, DEFAULT, ENABLE),

	/* UARTD pinmux (UART4 on Servo board, unused) */
	DEFAULT_PINMUX(PJ7,      UARTD,       NORMAL,    NORMAL,   OUTPUT),
	DEFAULT_PINMUX(PB0,      UARTD,       NORMAL,    TRISTATE, INPUT),
	DEFAULT_PINMUX(PB1,      UARTD,       NORMAL,    TRISTATE, INPUT),
	DEFAULT_PINMUX(PK7,      UARTD,       NORMAL,    NORMAL,   OUTPUT),

	/* SPI4 (Winbond 'boot ROM') */
	DEFAULT_PINMUX(PG5,       SPI4,        NORMAL,    NORMAL,   INPUT),
	DEFAULT_PINMUX(PG6,       SPI4,        UP,        NORMAL,   INPUT),
	DEFAULT_PINMUX(PG7,       SPI4,        UP,        NORMAL,   INPUT),
	DEFAULT_PINMUX(PI3,       SPI4,        NORMAL,    NORMAL,   INPUT),

	/* Touch IRQ */
	DEFAULT_PINMUX(GPIO_W3_AUD_PW3,   RSVD1,       NORMAL,    NORMAL,   INPUT),

	/* PWM1 pinmux */
	DEFAULT_PINMUX(PH1,       PWM1,       NORMAL,    NORMAL,   OUTPUT),

	/* SDMMC1 pinmux */
	DEFAULT_PINMUX(SDMMC1_CLK_PZ0,    SDMMC1,      NORMAL,    NORMAL,   INPUT),
	DEFAULT_PINMUX(SDMMC1_CMD_PZ1,    SDMMC1,      UP,        NORMAL,   INPUT),
	DEFAULT_PINMUX(SDMMC1_DAT0_PY7,   SDMMC1,      UP,        NORMAL,   INPUT),
	DEFAULT_PINMUX(SDMMC1_DAT1_PY6,   SDMMC1,      UP,        NORMAL,   INPUT),
	DEFAULT_PINMUX(SDMMC1_DAT2_PY5,   SDMMC1,      UP,        NORMAL,   INPUT),
	DEFAULT_PINMUX(SDMMC1_DAT3_PY4,   SDMMC1,      UP,        NORMAL,   INPUT),

	/* SDMMC3 pinmux */
	DEFAULT_PINMUX(SDMMC3_CLK_PA6,    SDMMC3,      NORMAL,    NORMAL,   INPUT),
	DEFAULT_PINMUX(SDMMC3_CMD_PA7,    SDMMC3,      UP,        NORMAL,   INPUT),
	DEFAULT_PINMUX(SDMMC3_DAT0_PB7,   SDMMC3,      UP,        NORMAL,   INPUT),
	DEFAULT_PINMUX(SDMMC3_DAT1_PB6,   SDMMC3,      UP,        NORMAL,   INPUT),
	DEFAULT_PINMUX(SDMMC3_DAT2_PB5,   SDMMC3,      UP,        NORMAL,   INPUT),
	DEFAULT_PINMUX(SDMMC3_DAT3_PB4,   SDMMC3,      UP,        NORMAL,   INPUT),
	DEFAULT_PINMUX(SDMMC3_CLK_LB_IN_PEE5,  SDMMC3,  UP,        TRISTATE, INPUT),
	DEFAULT_PINMUX(SDMMC3_CLK_LB_OUT_PEE4, SDMMC3,  DOWN,      NORMAL,   INPUT),

	/* SDMMC4 pinmux */
	DEFAULT_PINMUX(SDMMC4_CLK_PCC4,    SDMMC4,      NORMAL,    NORMAL,   INPUT),
	DEFAULT_PINMUX(SDMMC4_CMD_PT7,     SDMMC4,      UP,        NORMAL,   INPUT),
	DEFAULT_PINMUX(SDMMC4_DAT0_PAA0,   SDMMC4,      UP,        NORMAL,   INPUT),
	DEFAULT_PINMUX(SDMMC4_DAT1_PAA1,   SDMMC4,      UP,        NORMAL,   INPUT),
	DEFAULT_PINMUX(SDMMC4_DAT2_PAA2,   SDMMC4,      UP,        NORMAL,   INPUT),
	DEFAULT_PINMUX(SDMMC4_DAT3_PAA3,   SDMMC4,      UP,        NORMAL,   INPUT),
	DEFAULT_PINMUX(SDMMC4_DAT4_PAA4,   SDMMC4,      UP,        NORMAL,   INPUT),
	DEFAULT_PINMUX(SDMMC4_DAT5_PAA5,   SDMMC4,      UP,        NORMAL,   INPUT),
	DEFAULT_PINMUX(SDMMC4_DAT6_PAA6,   SDMMC4,      UP,        NORMAL,   INPUT),
	DEFAULT_PINMUX(SDMMC4_DAT7_PAA7,   SDMMC4,      UP,        NORMAL,   INPUT),

	/* BLINK pinmux */
	DEFAULT_PINMUX(CLK_32K_OUT_PA0,   BLINK,       NORMAL,    NORMAL,   OUTPUT),

	/* KBC pinmux */
	DEFAULT_PINMUX(KB_COL0_PQ0,       KBC,         UP,        NORMAL,   INPUT),
	DEFAULT_PINMUX(KB_COL1_PQ1,       KBC,         UP,        NORMAL,   INPUT),
	DEFAULT_PINMUX(KB_COL2_PQ2,       KBC,         UP,        NORMAL,   INPUT),
	DEFAULT_PINMUX(KB_ROW0_PR0,       KBC,         UP,        NORMAL,   INPUT),
	DEFAULT_PINMUX(KB_ROW1_PR1,       KBC,         UP,        NORMAL,   INPUT),

	/* Misc */
	DEFAULT_PINMUX(PV0,               RSVD1,       NORMAL,    TRISTATE, OUTPUT),
	DEFAULT_PINMUX(KB_ROW7_PR7,       RSVD1,       UP,        NORMAL,   INPUT),

	/* UARTA pinmux (BR_UART_TXD/RXD on Servo board) */
	DEFAULT_PINMUX(KB_ROW9_PS1,       UARTA,       UP,        NORMAL,   OUTPUT),
	DEFAULT_PINMUX(KB_ROW10_PS2,      UARTA,       UP,        TRISTATE, INPUT),

	/* I2CPWR pinmux (I2C5) */
	I2C_PINMUX(PWR_I2C_SCL_PZ6, I2CPWR, NORMAL, NORMAL, INPUT, DEFAULT, ENABLE),
	I2C_PINMUX(PWR_I2C_SDA_PZ7, I2CPWR, NORMAL, NORMAL, INPUT, DEFAULT, ENABLE),

	/* RTCK pinmux */
	DEFAULT_PINMUX(JTAG_RTCK,     RTCK,        NORMAL,    NORMAL,   INPUT),

	/* CLK pinmux */
	DEFAULT_PINMUX(CLK_32K_IN,    CLK,         NORMAL,    TRISTATE, INPUT),

	/* PWRON pinmux */
	DEFAULT_PINMUX(CORE_PWR_REQ,  PWRON,       NORMAL,    NORMAL,   OUTPUT),

	/* CPU pinmux */
	DEFAULT_PINMUX(CPU_PWR_REQ,   CPU,         NORMAL,    NORMAL,   OUTPUT),

	/* PMI pinmux */
	DEFAULT_PINMUX(PWR_INT_N,     PMI,         NORMAL,    TRISTATE, INPUT),

	/* RESET_OUT_N pinmux */
	DEFAULT_PINMUX(RESET_OUT_N,   RESET_OUT_N, NORMAL,    NORMAL,   OUTPUT),

	/* EXTPERIPH3 pinmux */
	DEFAULT_PINMUX(CLK3_OUT_PEE0, EXTPERIPH3,  NORMAL,    NORMAL,   OUTPUT),

	/* I2C1 pinmux */
	I2C_PINMUX(GEN1_I2C_SCL_PC4, I2C1, NORMAL, NORMAL, INPUT, DEFAULT, ENABLE),
	I2C_PINMUX(GEN1_I2C_SDA_PC5, I2C1, NORMAL, NORMAL, INPUT, DEFAULT, ENABLE),

	/* UARTB, GPS */
	DEFAULT_PINMUX(UART2_CTS_N_PJ5,   UARTB,       NORMAL,    TRISTATE, INPUT),
	DEFAULT_PINMUX(UART2_RTS_N_PJ6,   UARTB,       NORMAL,    NORMAL,   OUTPUT),
	DEFAULT_PINMUX(UART2_RXD_PC3,     IRDA,        NORMAL,    TRISTATE, INPUT),
	DEFAULT_PINMUX(UART2_TXD_PC2,     IRDA,        NORMAL,    NORMAL,   OUTPUT),

	/* UARTC (WIFI/BT) */
	DEFAULT_PINMUX(UART3_CTS_N_PA1,   UARTC,       NORMAL,    TRISTATE, INPUT),
	DEFAULT_PINMUX(UART3_RTS_N_PC0,   UARTC,       NORMAL,    NORMAL,   OUTPUT),
	DEFAULT_PINMUX(UART3_RXD_PW7,     UARTC,       NORMAL,    TRISTATE, INPUT),
	DEFAULT_PINMUX(UART3_TXD_PW6,     UARTC,       NORMAL,    NORMAL,   OUTPUT),

	/* CEC pinmux */
	CEC_PINMUX(HDMI_CEC_PEE3, CEC, NORMAL, NORMAL, INPUT, DEFAULT, DISABLE),

	/* I2C4 (HDMI_DDC) pinmux */
	DDC_PINMUX(DDC_SCL_PV4, I2C4, NORMAL, NORMAL, INPUT, DEFAULT, HIGH),
	DDC_PINMUX(DDC_SDA_PV5, I2C4, NORMAL, NORMAL, INPUT, DEFAULT, HIGH),

	/* USB pinmux */
	USB_PINMUX(USB_VBUS_EN0_PN4, USB, NORMAL, NORMAL, INPUT, DEFAULT, ENABLE),
	USB_PINMUX(USB_VBUS_EN1_PN5, USB, NORMAL, NORMAL, INPUT, DEFAULT, ENABLE),

	/* Unused, marked SNN_ on schematic, TRISTATE 'em */
	DEFAULT_PINMUX(PBB0,     RSVD3,       NORMAL,    TRISTATE, INPUT),
	DEFAULT_PINMUX(PBB3,     RSVD3,       NORMAL,    TRISTATE, INPUT),
	DEFAULT_PINMUX(PBB4,     RSVD3,       NORMAL,    TRISTATE, INPUT),
	DEFAULT_PINMUX(PBB5,     RSVD2,       NORMAL,    TRISTATE, INPUT),
	DEFAULT_PINMUX(PBB6,     RSVD1,       NORMAL,    TRISTATE, INPUT),
	DEFAULT_PINMUX(PBB7,     RSVD1,       NORMAL,    TRISTATE, INPUT),
	DEFAULT_PINMUX(PCC1,     RSVD1,       NORMAL,    TRISTATE, INPUT),
	DEFAULT_PINMUX(PCC2,     RSVD1,       NORMAL,    TRISTATE, INPUT),
	DEFAULT_PINMUX(PH3,      GMI,         NORMAL,    TRISTATE, INPUT),
	DEFAULT_PINMUX(PI7,      GMI,         NORMAL,    TRISTATE, INPUT),
	DEFAULT_PINMUX(PJ2,      RSVD1,       NORMAL,    TRISTATE, INPUT),
	DEFAULT_PINMUX(GPIO_X5_AUD_PX5,   RSVD3,       NORMAL,    TRISTATE, INPUT),
	DEFAULT_PINMUX(GPIO_X6_AUD_PX6,   GMI,         NORMAL,    TRISTATE, INPUT),
	DEFAULT_PINMUX(GPIO_W2_AUD_PW2,   RSVD1,       NORMAL,    TRISTATE, INPUT),
	DEFAULT_PINMUX(PFF2,     RSVD1,   NORMAL,    TRISTATE, INPUT),
	DEFAULT_PINMUX(USB_VBUS_EN2_PFF1, RSVD1,       NORMAL,    TRISTATE, INPUT),
	DEFAULT_PINMUX(KB_COL5_PQ5,       RSVD1,       NORMAL,    TRISTATE, INPUT),
	DEFAULT_PINMUX(KB_ROW2_PR2,       RSVD1,       NORMAL,    TRISTATE, INPUT),
	DEFAULT_PINMUX(KB_ROW3_PR3,       KBC,         NORMAL,    TRISTATE, INPUT),
	DEFAULT_PINMUX(KB_ROW5_PR5,       RSVD2,       NORMAL,    TRISTATE, INPUT),
	DEFAULT_PINMUX(KB_ROW6_PR6,       KBC,         NORMAL,    TRISTATE, INPUT),
	DEFAULT_PINMUX(KB_ROW13_PS5,      RSVD1,       NORMAL,    TRISTATE, INPUT),
	DEFAULT_PINMUX(KB_ROW14_PS6,      RSVD1,       NORMAL,    TRISTATE, INPUT),
	DEFAULT_PINMUX(KB_ROW16_PT0,      RSVD1,       NORMAL,    TRISTATE, INPUT),
	DEFAULT_PINMUX(OWR,               RSVD1,       NORMAL,    TRISTATE, INPUT),
	DEFAULT_PINMUX(ULPI_DATA7_PO0,    ULPI,        NORMAL,    TRISTATE, INPUT),
	DEFAULT_PINMUX(DAP3_DIN_PP1,      RSVD1,       NORMAL,    TRISTATE, INPUT),
	DEFAULT_PINMUX(DAP3_FS_PP0,       RSVD1,       NORMAL,    TRISTATE, INPUT),
	DEFAULT_PINMUX(DAP3_SCLK_PP3,     RSVD2,       NORMAL,    TRISTATE, INPUT),
	DEFAULT_PINMUX(CLK2_OUT_PW5,      RSVD1,       NORMAL,    TRISTATE, INPUT),
	DEFAULT_PINMUX(SDMMC1_WP_N_PV3,   RSVD1,       NORMAL,    TRISTATE, INPUT),
	DEFAULT_PINMUX(CAM_MCLK_PCC0,     RSVD1,       NORMAL,    TRISTATE, INPUT),
	DEFAULT_PINMUX(CLK3_REQ_PEE1,     RSVD1,       NORMAL,    TRISTATE, INPUT),
	DEFAULT_PINMUX(SPDIF_OUT_PK5,     RSVD1,       NORMAL,    TRISTATE, INPUT),
};

static struct pmux_pingrp_config unused_pins_lowpower[] = {
	DEFAULT_PINMUX(DAP_MCLK1_REQ_PEE2,      RSVD3,    DOWN, TRISTATE, OUTPUT),
};

/* Initially setting all used GPIO's to non-TRISTATE */
static struct pmux_pingrp_config tegra124_pinmux_set_nontristate[] = {
	DEFAULT_PINMUX(GPIO_X4_AUD_PX4,     RSVD1,  DOWN,    NORMAL,    OUTPUT),
	DEFAULT_PINMUX(GPIO_X7_AUD_PX7,     RSVD1,  DOWN,    NORMAL,    OUTPUT),
	DEFAULT_PINMUX(GPIO_W2_AUD_PW2,     RSVD1,  UP,      NORMAL,    INPUT),
	DEFAULT_PINMUX(GPIO_X3_AUD_PX3,     RSVD3,  UP,      NORMAL,    INPUT),

	/* EN_VDD_BL */
	DEFAULT_PINMUX(DAP3_DOUT_PP2,       I2S2,   DOWN,    NORMAL,    OUTPUT),

	/* MODEM */
	DEFAULT_PINMUX(PV0,        RSVD3,  NORMAL,  NORMAL,    INPUT),
	DEFAULT_PINMUX(PV1,        RSVD1,  NORMAL,  NORMAL,    INPUT),

	/* BOOT_SEL0-3 */
	DEFAULT_PINMUX(PG0,         GMI,    NORMAL,  NORMAL,    INPUT),
	DEFAULT_PINMUX(PG1,         GMI,    NORMAL,  NORMAL,    INPUT),
	DEFAULT_PINMUX(PG2,         GMI,    NORMAL,  NORMAL,    INPUT),
	DEFAULT_PINMUX(PG3,         GMI,    NORMAL,  NORMAL,    INPUT),

	DEFAULT_PINMUX(CLK2_REQ_PCC5,        RSVD3,  NORMAL,  NORMAL,    OUTPUT),

	DEFAULT_PINMUX(KB_COL3_PQ3,         KBC,    UP,      NORMAL,    OUTPUT),
	DEFAULT_PINMUX(KB_COL4_PQ4,         SDMMC3, UP,      NORMAL,    INPUT),
	DEFAULT_PINMUX(KB_COL6_PQ6,         KBC,    UP,      NORMAL,    OUTPUT),
	DEFAULT_PINMUX(KB_COL7_PQ7,         KBC,    UP,      NORMAL,    OUTPUT),
	DEFAULT_PINMUX(KB_ROW4_PR4,         KBC,    DOWN,    NORMAL,    INPUT),
	DEFAULT_PINMUX(KB_ROW8_PS0,         KBC,    UP,      NORMAL,    INPUT),

	DEFAULT_PINMUX(PU4,        RSVD3,  NORMAL,  NORMAL,    INPUT),
	DEFAULT_PINMUX(PU5,        RSVD3,  NORMAL,  NORMAL,    OUTPUT),
	DEFAULT_PINMUX(PU6,        RSVD3,  NORMAL,  NORMAL,    INPUT),

	DEFAULT_PINMUX(HDMI_INT_PN7,        RSVD1,  DOWN,    NORMAL,   INPUT),
	DEFAULT_PINMUX(SPDIF_IN_PK6,        RSVD2,  NORMAL,  NORMAL,   INPUT),
	DEFAULT_PINMUX(SDMMC3_CD_N_PV2,     SDMMC3, UP,      NORMAL,   INPUT),

	/* TS_SHDN_L */
	DEFAULT_PINMUX(PK1,        GMI,    NORMAL,   NORMAL,   OUTPUT),
};

static struct pmux_drvgrp_config venice2_padctrl[] = {
	/* (_drvgrp, _slwf, _slwr, _drvup, _drvdn, _lpmd, _schmt, _hsm) */
	DEFAULT_PADCFG(SDIO3, SDIOCFG_DRVUP_SLWF, SDIOCFG_DRVDN_SLWR,
		       SDIOCFG_DRVUP, SDIOCFG_DRVDN, NONE, NONE, NONE),
};
#endif /* PINMUX_CONFIG_VENICE2_H */
