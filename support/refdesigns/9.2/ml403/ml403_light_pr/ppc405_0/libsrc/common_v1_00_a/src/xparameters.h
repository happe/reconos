/* $Id: xparameters.h,v 1.81 2007/08/20 15:52:42 meinelte Exp $ */
/******************************************************************************
*
*       XILINX IS PROVIDING THIS DESIGN, CODE, OR INFORMATION "AS IS"
*       AS A COURTESY TO YOU, SOLELY FOR USE IN DEVELOPING PROGRAMS AND
*       SOLUTIONS FOR XILINX DEVICES.  BY PROVIDING THIS DESIGN, CODE,
*       OR INFORMATION AS ONE POSSIBLE IMPLEMENTATION OF THIS FEATURE,
*       APPLICATION OR STANDARD, XILINX IS MAKING NO REPRESENTATION
*       THAT THIS IMPLEMENTATION IS FREE FROM ANY CLAIMS OF INFRINGEMENT,
*       AND YOU ARE RESPONSIBLE FOR OBTAINING ANY RIGHTS YOU MAY REQUIRE
*       FOR YOUR IMPLEMENTATION.  XILINX EXPRESSLY DISCLAIMS ANY
*       WARRANTY WHATSOEVER WITH RESPECT TO THE ADEQUACY OF THE
*       IMPLEMENTATION, INCLUDING BUT NOT LIMITED TO ANY WARRANTIES OR
*       REPRESENTATIONS THAT THIS IMPLEMENTATION IS FREE FROM CLAIMS OF
*       INFRINGEMENT, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
*       FOR A PARTICULAR PURPOSE.
*
*       (c) Copyright 2002-2007 Xilinx Inc.
*       All rights reserved.
*
******************************************************************************/
/*****************************************************************************/
/**
*
* @file xparameters.h
*
* This file contains system parameters for the Xilinx device driver environment.
* It is a representation of the system in that it contains the number of each
* device in the system as well as the parameters and memory map for each
* device.  The user can view this file to obtain a summary of the devices in
* their system and the device parameters.
*
* This file may be automatically generated by a design tool such as System
* Generator.
*
******************************************************************************/

/***************************** Include Files *********************************/

#ifndef XPARAMETERS_H    /* prevent circular inclusions */
#define XPARAMETERS_H    /* by using protection macros */

#ifdef __cplusplus
extern "C" {
#endif

/* unifying driver changes

added XPAR_INTC_0_ACK_BEFORE, XPAR_INTC_1_ACK_BEFORE
changed XPAR_INTC_MAX_ID to XPAR_INTC_MAX_NUM_INTR_INPUTS
deleted XPAR_INTC_0_MAX_ID, XPAR_INTC_1_MAX_ID

*/

/************************** Constant Definitions *****************************/

/*
 * The following constants are for each device.
 *
 * An instance must exist for each physical device that exists in the system.
 * The device IDs in the following constants are unique between all devices to
 * allow device IDs to be searched in the future.
 */

/*****************************************************************************
 *
 * System Level defines. These constants are for devices that do not require
 * a device driver. Examples of these types of devices include volatile RAM
 * devices.
 */
#define XPAR_ZBT_NUM_INSTANCES   1
#define XPAR_ZBT_0_BASE          0x00000000
#define XPAR_ZBT_0_SIZE          0x00100000

#define XPAR_SRAM_NUM_INSTANCES  1
#define XPAR_SRAM_0_BASE         0x00100000
#define XPAR_SRAM_0_SIZE         0x00200000

#define XPAR_DDR_NUM_INSTANCES   1
#define XPAR_DDR_0_BASE          0xF0000000
#define XPAR_DDR_0_SIZE          0x01000000

#define XPAR_CORE_CLOCK_FREQ_HZ  12500000

#define XPAR_CPU_PPC405_CORE_CLOCK_FREQ_HZ  XPAR_CORE_CLOCK_FREQ_HZ

/*****************************************************************************
 *
 * Interrupt Controller (Intc) defines.
 * DeviceID starts at 0
 */
#define XPAR_XINTC_NUM_INSTANCES       2          /* Number of instances */
#define XPAR_INTC_MAX_NUM_INTR_INPUTS  31         /* max # inputs of all */
#define XPAR_INTC_SINGLE_BASEADDR      0x70800000 /* low level driver base */
#define XPAR_INTC_SINGLE_DEVICE_ID     0          /* single instance ID */
#define XPAR_INTC_SINGLE_ACK_BEFORE    0xFFFF00FF /* low level driver */

#define XPAR_INTC_0_DEVICE_ID          1          /* Device ID for instance */
#define XPAR_INTC_0_ACK_BEFORE         0xFFFF00FF /* Ack timing, before/after */
#define XPAR_INTC_0_BASEADDR           0x70800000 /* Register base address */

#define XPAR_INTC_0_UARTLITE_0_VEC_ID  4          /* Interrupt source for vector */
#define XPAR_INTC_0_WDTTB_0_VEC_ID     5          /* Interrupt source for vector */
#define XPAR_INTC_0_WD_0_VEC_ID        6          /* Interrupt source for vector */
#define XPAR_INTC_0_TMRCTR_0_VEC_ID    7          /* Interrupt source for vector */
#define XPAR_INTC_0_SPI_0_VEC_ID       11         /* Interrupt source for vector */
#define XPAR_INTC_0_IIC_0_VEC_ID       12         /* Interrupt source for vector */
#define XPAR_INTC_0_UARTNS550_0_VEC_ID 13         /* Interrupt source for vector */
#define XPAR_INTC_0_UARTNS550_1_VEC_ID 14         /* Interrupt source for vector */
#define XPAR_INTC_0_EMAC_0_VEC_ID      15         /* Interrupt source for vector */

#define XPAR_INTC_1_DEVICE_ID          2          /* Device ID for instance */
#define XPAR_INTC_1_ACK_BEFORE         0xFFFF00FF /* Ack timing, before/after */
#define XPAR_INTC_1_BASEADDR           0x70800020 /* Register base address */

#define XPAR_INTC_1_OPB_TO_PLB_ERR_VEC_ID 0       /* Interrupt source for vector */
#define XPAR_INTC_1_PLB_TO_OPB_ERR_VEC_ID 1       /* Interrupt source for vector */

/*****************************************************************************
 *
 * Ethernet 10/100 MAC defines.
 * DeviceID starts at 10
 */
#define XPAR_XEMAC_NUM_INSTANCES     1          /* Number of instances */

#define XPAR_EMAC_0_DEVICE_ID        10        /* Device ID for instance */
#define XPAR_EMAC_0_BASEADDR         0x60000000/* Device base address */
#define XPAR_EMAC_0_DMA_PRESENT      FALSE     /* Does device have DMA? */
#define XPAR_EMAC_0_ERR_COUNT_EXIST  TRUE      /* Does device have counters? */
#define XPAR_EMAC_0_MII_EXIST        TRUE      /* Does device support MII? */

/*****************************************************************************
 *
 * NS16550 UART defines.
 * DeviceID starts at 20
 */
#define XPAR_XUARTNS550_NUM_INSTANCES 1         /* Number of instances */

#define XPAR_UARTNS550_0_DEVICE_ID   20         /* Device ID for instance */
#define XPAR_UARTNS550_0_BASEADDR    0xA0010000 /* IPIF base address */
#define XPAR_UARTNS550_0_CLOCK_HZ    (66000000L)/* 66 MHz clock */

#define XPAR_UARTNS550_1_DEVICE_ID   21         /* Device ID for instance */
#define XPAR_UARTNS550_1_BASEADDR    0xA0000000 /* IPIF base address */
#define XPAR_UARTNS550_1_CLOCK_HZ    (66000000L)/* 66 MHz clock */

/*****************************************************************************
 *
 * UartLite defines.
 * DeviceID starts at 30
 */
#define XPAR_XUARTLITE_NUM_INSTANCES 1         /* Number of instances */

#define XPAR_UARTLITE_0_DEVICE_ID   30         /* Device ID for instance */
#define XPAR_UARTLITE_0_BASEADDR    0xA0020000 /* Device base address */
#define XPAR_UARTLITE_0_BAUDRATE    19200      /* Baud rate */
#define XPAR_UARTLITE_0_USE_PARITY  FALSE      /* Parity generator enabled */
#define XPAR_UARTLITE_0_ODD_PARITY  FALSE      /* Type of parity generated */
#define XPAR_UARTLITE_0_DATA_BITS   8          /* Data bits */

/*****************************************************************************
 *
 * ATM controller defines.
 * DeviceID starts at 40
 */
#define XPAR_XATMC_NUM_INSTANCES    1          /* Number of instances */

#define XPAR_ATMC_0_DEVICE_ID       40         /* Device ID for instance */
#define XPAR_ATMC_0_BASEADDR        0x70000000 /* Device base address */
#define XPAR_ATMC_0_DMA_PRESENT     FALSE      /* Does device have DMA? */

/*****************************************************************************
 *
 * Serial Peripheral Interface (SPI) defines.
 * DeviceID starts at 50
 */
#define XPAR_XSPI_NUM_INSTANCES      2         /* Number of instances */

#define XPAR_SPI_0_DEVICE_ID        50         /* Device ID for instance */
#define XPAR_SPI_0_BASEADDR         0x50000000 /* Device base address */
#define XPAR_SPI_0_FIFO_EXIST       TRUE       /* Does device have FIFOs? */
#define XPAR_SPI_0_SLAVE_ONLY       FALSE      /* Is the device slave only? */
#define XPAR_SPI_0_NUM_SS_BITS      32         /* Number of slave select bits */

#define XPAR_SPI_1_DEVICE_ID        51         /* Device ID for instance */
#define XPAR_SPI_1_BASEADDR         0x50000100 /* IPIF base address */
#define XPAR_SPI_1_FIFO_EXIST       TRUE       /* Does device have FIFOs? */
#define XPAR_SPI_1_SLAVE_ONLY       FALSE      /* Is the device slave only? */
#define XPAR_SPI_1_NUM_SS_BITS      32         /* Number of slave select bits */

/*****************************************************************************
 *
 * OPB Arbiter defines.
 * DeviceID starts at 60
 */
#define XPAR_XOPBARB_NUM_INSTANCES 1          /* Number of instances */

#define XPAR_OPBARB_0_DEVICE_ID    60         /* Device ID for instance */
#define XPAR_OPBARB_0_BASEADDR     0x80000000 /* Register base address */
#define XPAR_OPBARB_0_NUM_MASTERS  8          /* Number of masters on bus */

/*****************************************************************************
 *
 * Watchdog timer/timebase (WdtTb) defines.
 * DeviceID starts at 70
 */
#define XPAR_XWDTTB_NUM_INSTANCES   1          /* Number of instances */

#define XPAR_WDTTB_0_DEVICE_ID      70         /* Device ID for instance */
#define XPAR_WDTTB_0_BASEADDR       0x70800040 /* Register base address */

/*****************************************************************************
 *
 * Timer Counter (TmrCtr) defines.
 * DeviceID starts at 80
 */
#define XPAR_XTMRCTR_NUM_INSTANCES  2          /* Number of instances */

#define XPAR_TMRCTR_0_DEVICE_ID     80         /* Device ID for instance */
#define XPAR_TMRCTR_0_BASEADDR      0x70800100 /* Register base address */

/*****************************************************************************
 *
 * IIC defines.
 * DeviceID starts at 90
 */
#define XPAR_XIIC_NUM_INSTANCES     2          /* Number of instances */

#define XPAR_IIC_0_DEVICE_ID        90         /* Device ID for instance */
#define XPAR_IIC_0_BASEADDR         0xA8000000 /* Device base address */
#define XPAR_IIC_0_TEN_BIT_ADR      TRUE       /* Supports 10 bit addresses */

#define XPAR_IIC_1_DEVICE_ID        91         /* Device ID for instance */
#define XPAR_IIC_1_BASEADDR         0xA8000000 /* Device base address */
#define XPAR_IIC_1_TEN_BIT_ADR      TRUE       /* Supports 10 bit addresses */

/*****************************************************************************
 *
 * Flash defines.
 * DeviceID starts at 100
 */
#define XPAR_XFLASH_NUM_INSTANCES   1          /* Number of instances */
#define XPAR_FLASH_INTEL_SUPPORT               /* Include intel flash support */

#define XPAR_FLASH_0_DEVICE_ID      100        /* Device ID for first instance
*/
#define XPAR_FLASH_0_BASEADDR       0xFF000000 /* Base address of parts */
#define XPAR_FLASH_0_NUM_PARTS      2          /* Number of parts in array */
#define XPAR_FLASH_0_PART_WIDTH     2          /* Width of each part in bytes */
#define XPAR_FLASH_0_PART_MODE      2          /* Mode of each part in bytes */

/*****************************************************************************
 *
 * GPIO defines.
 * DeviceID starts at 110
 */
#define XPAR_XGPIO_NUM_INSTANCES    1

#define XPAR_GPIO_0_DEVICE_ID       110        /* Device ID for instance */
#define XPAR_GPIO_0_BASEADDR        0x90000000 /* Register base address */
#define XPAR_GPIO_0_INTERRUPT_PRESENT   0      /* Interrupts supported? */
#define XPAR_GPIO_0_IS_DUAL             0      /* Dual channels supported? */

/*****************************************************************************
 *
 * EMC defines.
 * DeviceID starts at 120
 */
#define XPAR_XEMC_NUM_INSTANCES     1

#define XPAR_EMC_0_DEVICE_ID       120         /* Device ID for instance */
#define XPAR_EMC_0_BASEADDR        0xE0000000  /* Register base address */
#define XPAR_EMC_0_NUM_BANKS_MEM   3           /* Number of banks */

/*****************************************************************************
 *
 * PLB Arbiter defines.
 * DeviceID starts at 130
 */
#define XPAR_XPLBARB_NUM_INSTANCES     1

#define XPAR_PLBARB_0_DEVICE_ID       130         /* Device ID for instance */
#define XPAR_PLBARB_0_BASEADDR        0x300       /* Register base address */
#define XPAR_PLBARB_0_NUM_MASTERS     1           /* Number of masters on bus */

/*****************************************************************************
 *
 * PLB To OPB Bridge defines.
 * DeviceID starts at 140
 */
#define XPAR_XPLB2OPB_NUM_INSTANCES     1

#define XPAR_PLB2OPB_0_DEVICE_ID       140         /* Device ID for instance */
#define XPAR_PLB2OPB_0_DCR_BASEADDR    0x0         /* DCR Register base address
*/
#define XPAR_PLB2OPB_0_NUM_MASTERS       1         /* Number of masters on bus
*/


/*****************************************************************************
 *
 * OPB To PLB Bridge defines.
 * DeviceID starts at 150
 */
#define XPAR_XOPB2PLB_NUM_INSTANCES     1
#define XPAR_XOPB2PLB_ANY_OPB_REG_INTF       /* Accessible from OPB, not DCR */

#define XPAR_OPB2PLB_0_DEVICE_ID       150   /* Device ID for instance */
#define XPAR_OPB2PLB_0_OPB_BASEADDR    0x0   /* Register base address */
#define XPAR_OPB2PLB_0_DCR_BASEADDR    0x0   /* DCR Register base address */


/*****************************************************************************
 *
 * System ACE defines.
 * DeviceID starts at 160
 */
#define XPAR_XSYSACE_NUM_INSTANCES    1

#define XPAR_SYSACE_0_DEVICE_ID       160         /* Device ID for instance */
#define XPAR_SYSACE_0_BASEADDR        0xCF000000  /* Register base address */


/*****************************************************************************
 *
 * HDLC defines.
 * DeviceID starts at 170
 */
#define XPAR_XHDLC_NUM_INSTANCES     1

#define XPAR_HDLC_0_DEVICE_ID       170             /* Device ID for instance */
#define XPAR_HDLC_0_BASEADDR        0x60010000      /* Register base address */
#define XPAR_HDLC_0_TX_MEM_DEPTH    2048            /* Tx FIFO depth (bytes) */
#define XPAR_HDLC_0_RX_MEM_DEPTH    2048            /* Rx FIFO depth (bytes) */
#define XPAR_HDLC_0_DMA_PRESENT     3               /* DMA SG in hardware */


/*****************************************************************************
 *
 * PS2 Reference driver defines.
 * DeviceID starts at 180
 */
#define XPAR_XPS2_NUM_INSTANCES    2

#define XPAR_PS2_0_DEVICE_ID       180             /* Device ID for instance */
#define XPAR_PS2_0_BASEADDR        0x40010000      /* Register base address */

#define XPAR_PS2_1_DEVICE_ID       181             /* Device ID for instance */
#define XPAR_PS2_1_BASEADDR        0x40020000      /* Register base address */

/*****************************************************************************
 *
 * Rapid IO defines.
 * DeviceID starts at 190
 */
#define XPAR_XRAPIDIO_NUM_INSTANCES    1

#define XPAR_RAPIDIO_0_DEVICE_ID       190             /* Device ID for instance */
#define XPAR_RAPIDIO_0_BASEADDR        0x60000000      /* Register base address */


/*****************************************************************************
 *
 * PCI defines.
 * DeviceID starts at 200
 */
#define XPAR_XPCI_NUM_INSTANCES                      1
#define XPAR_OPB_PCI_1_DEVICE_ID                     200
#define XPAR_OPB_PCI_1_BASEADDR                      0x86000000
#define XPAR_OPB_PCI_1_HIGHADDR                      0x860001FF
#define XPAR_OPB_PCI_1_PCIBAR_0                      0x10000000
#define XPAR_OPB_PCI_1_PCIBAR_LEN_0                  27
#define XPAR_OPB_PCI_1_PCIBAR2IPIF_0                 0xF0000000
#define XPAR_OPB_PCI_1_PCIBAR_ENDIAN_TRANSLATE_EN_0  0
#define XPAR_OPB_PCI_1_PCI_PREFETCH_0                1
#define XPAR_OPB_PCI_1_PCI_SPACETYPE_0               1
#define XPAR_OPB_PCI_1_PCIBAR_1                      0x3F000000
#define XPAR_OPB_PCI_1_PCIBAR_LEN_1                  15
#define XPAR_OPB_PCI_1_PCIBAR2IPIF_1                 0xC0FF8000
#define XPAR_OPB_PCI_1_PCIBAR_ENDIAN_TRANSLATE_EN_1  0
#define XPAR_OPB_PCI_1_PCI_PREFETCH_1                1
#define XPAR_OPB_PCI_1_PCI_SPACETYPE_1               1
#define XPAR_OPB_PCI_1_PCIBAR_2                      0x5F000000
#define XPAR_OPB_PCI_1_PCIBAR_LEN_2                  16
#define XPAR_OPB_PCI_1_PCIBAR2IPIF_2                 0x00000000
#define XPAR_OPB_PCI_1_PCIBAR_ENDIAN_TRANSLATE_EN_2  0
#define XPAR_OPB_PCI_1_PCI_PREFETCH_2                1
#define XPAR_OPB_PCI_1_PCI_SPACETYPE_2               1
#define XPAR_OPB_PCI_1_IPIFBAR_0                     0x80000000
#define XPAR_OPB_PCI_1_IPIF_HIGHADDR_0               0x81FFFFFF
#define XPAR_OPB_PCI_1_IPIFBAR2PCI_0                 0xF0000000
#define XPAR_OPB_PCI_1_IPIFBAR_ENDIAN_TRANSLATE_EN_0 0
#define XPAR_OPB_PCI_1_IPIF_PREFETCH_0               1
#define XPAR_OPB_PCI_1_IPIF_SPACETYPE_0              1
#define XPAR_OPB_PCI_1_IPIFBAR_1                     0x82000000
#define XPAR_OPB_PCI_1_IPIF_HIGHADDR_1               0x820007FF
#define XPAR_OPB_PCI_1_IPIFBAR2PCI_1                 0xCE000000
#define XPAR_OPB_PCI_1_IPIFBAR_ENDIAN_TRANSLATE_EN_1 0
#define XPAR_OPB_PCI_1_IPIF_PREFETCH_1               1
#define XPAR_OPB_PCI_1_IPIF_SPACETYPE_1              1
#define XPAR_OPB_PCI_1_IPIFBAR_2                     0x82320000
#define XPAR_OPB_PCI_1_IPIF_HIGHADDR_2               0x8232FFFF
#define XPAR_OPB_PCI_1_IPIFBAR2PCI_2                 0x00010000
#define XPAR_OPB_PCI_1_IPIFBAR_ENDIAN_TRANSLATE_EN_2 0
#define XPAR_OPB_PCI_1_IPIF_PREFETCH_2               1
#define XPAR_OPB_PCI_1_IPIF_SPACETYPE_2              1
#define XPAR_OPB_PCI_1_IPIFBAR_3                     0x82330000
#define XPAR_OPB_PCI_1_IPIF_HIGHADDR_3               0x8233FFFF
#define XPAR_OPB_PCI_1_IPIFBAR2PCI_3                 0x00010000
#define XPAR_OPB_PCI_1_IPIFBAR_ENDIAN_TRANSLATE_EN_3 0
#define XPAR_OPB_PCI_1_IPIF_PREFETCH_3               1
#define XPAR_OPB_PCI_1_IPIF_SPACETYPE_3              0
#define XPAR_OPB_PCI_1_IPIFBAR_4                     0x82340000
#define XPAR_OPB_PCI_1_IPIF_HIGHADDR_4               0x8234FFFF
#define XPAR_OPB_PCI_1_IPIFBAR2PCI_4                 0x00010000
#define XPAR_OPB_PCI_1_IPIFBAR_ENDIAN_TRANSLATE_EN_4 0
#define XPAR_OPB_PCI_1_IPIF_PREFETCH_4               0
#define XPAR_OPB_PCI_1_IPIF_SPACETYPE_4              0
#define XPAR_OPB_PCI_1_IPIFBAR_5                     0x82350000
#define XPAR_OPB_PCI_1_IPIF_HIGHADDR_5               0x8235FFFF
#define XPAR_OPB_PCI_1_IPIFBAR2PCI_5                 0x00010000
#define XPAR_OPB_PCI_1_IPIFBAR_ENDIAN_TRANSLATE_EN_5 0
#define XPAR_OPB_PCI_1_IPIF_PREFETCH_5               1
#define XPAR_OPB_PCI_1_IPIF_SPACETYPE_5              1
#define XPAR_OPB_PCI_1_DMA_BASEADDR                  0x87000000
#define XPAR_OPB_PCI_1_DMA_HIGHADDR                  0x8700007F
#define XPAR_OPB_PCI_1_DMA_CHAN_TYPE                 0
#define XPAR_OPB_PCI_1_DMA_LENGTH_WIDTH              11

/*****************************************************************************
 *
 * GEmac defines.
 * DeviceID starts at 210
 */
#define XPAR_XGEMAC_NUM_INSTANCES    1
#define XPAR_GEMAC_0_DEVICE_ID       210
#define XPAR_GEMAC_0_BASEADDR        0x61000000
#define XPAR_GEMAC_0_DMA_TYPE        9
#define XPAR_GEMAC_0_MIIM_EXIST      0
#define XPAR_GEMAC_0_INCLUDE_STATS   0


/*****************************************************************************
 *
 * Touchscreen defines .
 * DeviceID starts at 220
 */
#define XPAR_XTOUCHSCREEN_NUM_INSTANCES  1
#define XPAR_TOUCHSCREEN_0_DEVICE_ID     220
#define XPAR_TOUCHSCREEN_0_BASEADDR      0x70000000


/*****************************************************************************
 *
 * DDR defines .
 * DeviceID starts at 230
 */
#define XPAR_XDDR_NUM_INSTANCES         1
#define XPAR_DDR_0_DEVICE_ID            230
#define XPAR_DDR_0_BASEADDR             0
#define XPAR_DDR_0_INTERRUPT_PRESENT    0

/*****************************************************************************
 *
 * EmacLite defines .
 * DeviceID starts at 240
 */
#define XPAR_XEMACLITE_NUM_INSTANCES    1
#define XPAR_EMACLITE_0_DEVICE_ID       240
#define XPAR_EMACLITE_0_BASEADDR        0
#define XPAR_EMACLITE_0_TX_PING_PONG    0
#define XPAR_EMACLITE_0_RX_PING_PONG    0

/*****************************************************************************
 *
 * DSDAC defines .
 * DeviceID starts at 250
 */
#define XPAR_XDSDAC_NUM_INSTANCES       1
#define XPAR_DSDAC_0_DEVICE_ID          250
#define XPAR_DSDAC_0_BASEADDR           0

/*****************************************************************************
 *
 * DSADC defines .
 * DeviceID starts at 260
 */
#define XPAR_XDSADC_NUM_INSTANCES       1
#define XPAR_DSADC_0_DEVICE_ID          260
#define XPAR_DSADC_0_BASEADDR           0

/*****************************************************************************
 *
 * PCI Arbiter defines.
 * DeviceID starts at 270
 */
#define XPAR_XPCIARB_NUM_INSTANCES     1
#define XPAR_OPB_PCI_ARBITER_0_DEVICE_ID     270
#define XPAR_OPB_PCI_ARBITER_0_BASEADDR      0
#define XPAR_OPB_PCI_ARBITER_0_NUM_PCI_MSTRS 2

/*****************************************************************************
 *
 * TEMAC defines .
 * DeviceID starts at 280
 */
#define XPAR_XTEMAC_NUM_INSTANCES       1
#define XPAR_TEMAC_0_DEVICE_ID          280
#define XPAR_TEMAC_0_BASEADDR           0
#define XPAR_TEMAC_0_DMA_TYPE        3
#define XPAR_TEMAC_0_RDFIFO_DEPTH    131072
#define XPAR_TEMAC_0_WRFIFO_DEPTH    131072
#define XPAR_TEMAC_0_MAC_FIFO_DEPTH  16
#define XPAR_TEMAC_0_TEMAC_DCR_HOST  0
#define XPAR_TEMAC_0_DRE             0

/*****************************************************************************
 *
 * DMACENTRAL defines .
 * DeviceID starts at 290
 */
#define XPAR_XDMACENTRAL_NUM_INSTANCES       1
#define XPAR_DMACENTRAL_0_DEVICE_ID          290
#define XPAR_DMACENTRAL_0_BASEADDR           0
#define XPAR_DMACENTRAL_0_READ_OPTIONAL_REGS 0

/*****************************************************************************
 *
 * CAN defines
 * DeviceID starts at 300
 */
#define XPAR_XCAN_NUM_INSTANCES  1
#define XPAR_CAN_0_DEVICE_ID     300

/******************************************************************
 * Embedded Processor Block (EPB) Defines
 * Also known as Angelfire.
 */

/* Definitions for driver UARTEPB */
#define XPAR_XUARTEPB_NUM_INSTANCES 2

/* Definitions for peripheral EPB_0 - EPB_UART1 */
#define XPAR_EPB_0_UART1_BASEADDR 0x7D802000
#define XPAR_EPB_0_UART1_DEVICE_ID 0
#define XPAR_EPB_0_UART1_CLOCK_HZ 66666666

/* Definitions for peripheral EPB_0 - EPB_UART2 */
#define XPAR_EPB_0_UART2_BASEADDR 0x7D803000
#define XPAR_EPB_0_UART2_DEVICE_ID 1
#define XPAR_EPB_0_UART2_CLOCK_HZ 66666666


/******************************************************************/

/* Definitions for driver SPIEPB */
#define XPAR_XSPIEPB_NUM_INSTANCES 2

/* Definitions for peripheral EPB_0 - EPB_SPI1 */
#define XPAR_EPB_0_SPI1_BASEADDR 0x7D804000
#define XPAR_EPB_0_SPI1_DEVICE_ID 0
#define XPAR_EPB_0_SPI1_CLOCK_HZ 66666666

/* Definitions for peripheral EPB_0 - EPB_SPI2 */
#define XPAR_EPB_0_SPI2_BASEADDR 0x7D805000
#define XPAR_EPB_0_SPI2_DEVICE_ID 1
#define XPAR_EPB_0_SPI2_CLOCK_HZ 66666666


/******************************************************************/

/* Definitions for driver CANEPB */
#define XPAR_XCANEPB_NUM_INSTANCES 2

/* Definitions for peripheral EPB_0 - EPB_CAN1 */
#define XPAR_EPB_0_CAN1_BASEADDR 0x7D808000
#define XPAR_EPB_0_CAN1_DEVICE_ID 0

/* Definitions for peripheral EPB_0 - EPB_CAN2 */
#define XPAR_EPB_0_CAN2_BASEADDR 0x7D809000
#define XPAR_EPB_0_CAN2_DEVICE_ID 1


/******************************************************************/

/* Definitions for driver INTCEPB */
#define XPAR_XINTCEPB_NUM_INSTANCES 1

/* Definitions for peripheral EPB_0 - EPB_INTC */
#define XPAR_EPB_0_INTC_BASEADDR 0x7D80C000
#define XPAR_EPB_0_INTC_DEVICE_ID 0
#define XPAR_EPB_0_INTC_KIND_OF_INTR 0x00000000

/* Interrupt Identifiers for EPB_0_INTC */
#define XPAR_EPB_0_EMAC_INTR   2
#define XPAR_EPB_0_USB_INTR    3
#define XPAR_EPB_0_UART1_INTR  4
#define XPAR_EPB_0_UART2_INTR  5
#define XPAR_EPB_0_SPI1_INTR   6
#define XPAR_EPB_0_SPI2_INTR   7
#define XPAR_EPB_0_I2C1_INTR   8
#define XPAR_EPB_0_I2C2_INTR   9
#define XPAR_EPB_0_CAN1_INTR   10
#define XPAR_EPB_0_CAN2_INTR   11
#define XPAR_EPB_0_WDOG_INTR   12
#define XPAR_EPB_0_TTC1_INTR   13
#define XPAR_EPB_0_TTC2_INTR   14
#define XPAR_EPB_0_TTC3_INTR   15


/******************************************************************/

/* Definitions for driver I2CEPB */
#define XPAR_XI2CEPB_NUM_INSTANCES 2

/* Definitions for peripheral EPB_0 - EPB_I2C1 */
#define XPAR_EPB_0_I2C1_BASEADDR 0x7D806000
#define XPAR_EPB_0_I2C1_DEVICE_ID 0
#define XPAR_EPB_0_I2C1_CLOCK_HZ 66666666

/* Definitions for peripheral EPB_0 - EPB_I2C2 */
#define XPAR_EPB_0_I2C2_BASEADDR 0x7D807000
#define XPAR_EPB_0_I2C2_DEVICE_ID 1
#define XPAR_EPB_0_I2C2_CLOCK_HZ 66666666


/******************************************************************/

/* Definitions for driver TTCEPB */
#define XPAR_XTTCEPB_NUM_INSTANCES 3

/* Definitions for peripheral EPB_0 - EPB_TTC1 */
#define XPAR_EPB_0_TTC1_BASEADDR 0x7D80B000
#define XPAR_EPB_0_TTC1_DEVICE_ID 0
#define XPAR_EPB_0_TTC1_CLOCK_HZ 66666666

/* Definitions for peripheral EPB_0 - EPB_TTC2 */
#define XPAR_EPB_0_TTC2_BASEADDR 0x7D80B004
#define XPAR_EPB_0_TTC2_DEVICE_ID 1
#define XPAR_EPB_0_TTC2_CLOCK_HZ 66666666

/* Definitions for peripheral EPB_0 - EPB_TTC3 */
#define XPAR_EPB_0_TTC3_BASEADDR 0x7D80B008
#define XPAR_EPB_0_TTC3_DEVICE_ID 2
#define XPAR_EPB_0_TTC3_CLOCK_HZ 66666666


/******************************************************************/

/* Definitions for driver WDTEPB */
#define XPAR_XWDTEPB_NUM_INSTANCES 1

/* Definitions for peripheral EPB_0 - EPB_WDT */
#define XPAR_EPB_0_WDT_BASEADDR 0x7D80A000
#define XPAR_EPB_0_WDT_DEVICE_ID 0


/******************************************************************/

/* Definitions for driver EMACEPB */
#define XPAR_XEMACEPB_NUM_INSTANCES 1

/* Definitions for peripheral EPB_0 - EPB_EMAC */
#define XPAR_EPB_0_EMAC_BASEADDR 0x7D800000
#define XPAR_EPB_0_EMAC_DEVICE_ID 0


/******************************************************************/

/* Definitions for driver USBEPB */
#define XPAR_XUSBEPB_NUM_INSTANCES 1

/* Definitions for peripheral EPB_0 - EPB_USB */
#define XPAR_EPB_0_USB_BASEADDR 0x7D801000
#define XPAR_EPB_0_USB_DEVICE_ID 0


/******************************************************************/

/* Definitions for driver ADCEPB */
#define XPAR_XADCEPB_NUM_INSTANCES 1

/* Definitions for peripheral EPB_0 - EPB_ADC */
#define XPAR_EPB_0_ADC_BASEADDR 0x7D80D000
#define XPAR_EPB_0_ADC_DEVICE_ID 0
#define XPAR_EPB_0_ADC_CLOCK_HZ 66666666

/* Definitions for FLEXRAY Driver */
#define XPAR_XFLEXRAY_NUM_INSTANCES 1
#define XPAR_OPB_FLEXRAY_0_DEVICE_ID    0
#define XPAR_OPB_FLEXRAY_0_BASEADDR  0x7D80E000
#define XPAR_OPB_FLEXRAY_MAX_PAYLOAD_SIZE 254
#define XPAR_OPB_FLEXRAY_NO_OF_TX_BUFFERS   128
#define XPAR_OPB_FLEXRAY_NO_OF_RX_BUFFERS   128
#define XPAR_OPB_FLEXRAY_RX_FIFO_DEPTH      16

/* Definitions for MOST driver */
#define XPAR_XMOST_NUM_INSTANCES 1
#define XPAR_OPB_MOST_0_DEVICE_ID 0
#define XPAR_OPB_MOST_0_BASEADDR 0x7D810000
#define XPAR_OPB_MOST_OPMODE	0
#define XPAR_OPB_MOST_FWC 16
#define XPAR_OPB_MOST_EWC 16

/* Definitions for USB driver */
#define XPAR_XUSB_NUM_INSTANCES	1
#define XPAR_USB_0_DEVICE_ID	0
#define XPAR_USB_0_BASEADDR	0x7D813000

/*****************************************************************************
 *
 * HWICAP defines .
 */
#define XPAR_XHWICAP_NUM_INSTANCES       1
#define XPAR_OPB_HWICAP_0_DEVICE_ID      0
#define XPAR_OPB_HWICAP_0_BASEADDR        0xFFFFFFFF

/*****************************************************************************
 *
 * LLTEMAC and LLFIFO defines .
 */
#define XPAR_XLLTEMAC_NUM_INSTANCES      1
#define XPAR_XLLFIFO_NUM_INSTANCES       1

/*****************************************************************************
 *
 * PCIe defines .
 */
#define XPAR_XPCIE_NUM_INSTANCES       1

/*****************************************************************************
 *
 * MPMC defines .
 */
#define XPAR_XMPMC_NUM_INSTANCES         1

/*****************************************************************************
 *
 * SYSMON defines .
 */
#define XPAR_XSYSMON_NUM_INSTANCES         1


/*****************************************************************************
 *
 * SYSMON defines .
 */
#define XPAR_XSYSMON_NUM_INSTANCES         1

/*****************************************************************************
 *
 * MBox defines .
 */
#define XPAR_XMBOX_NUM_INSTANCES         	1
#define XPAR_XMBOX_0_DEVICE_ID				0
#define XPAR_XMBOX_0_BASEADDR				0x7D814000
#define XPAR_XMBOX_0_NUM_CHANNELS			1
#define XPAR_XMBOX_0_USE_FSL				0


/*****************************************************************************
 *
 * Mutex defines .
 */
#define XPAR_XMUTEX_NUM_INSTANCES         	1
#define XPAR_XMUTEX_0_DEVICE_ID				0
#define XPAR_XMUTEX_0_BASEADDR				0x7D815000
#define XPAR_XMUTEX_0_NUM_MUTEX				2
#define XPAR_XMUTEX_0_ENABLE_USER			1

/*
 * MicroBlaze sets this define but for the build check to
 * function it needs to be set here
 */
#define XPAR_CPU_ID 0


/**************************** Type Definitions *******************************/


/***************** Macros (Inline Functions) Definitions *********************/

#ifdef __cplusplus
}
#endif

#endif              /* end of protection macro */


