/**
 * @file globals.h
 * @brief Module globals.
 *
 */


#ifndef _OSCC_KIA_SOUL_THROTTLE_GLOBALS_H_
#define _OSCC_KIA_SOUL_THROTTLE_GLOBALS_H_


#include "DAC_MCP49xx.h"
#include "mcp_can.h"

#include "throttle_control.h"


/*
 * @brief Chip select pin of the DAC IC.
 *
 */
#define PIN_DAC_CHIP_SELECT ( 9 )

/*
 * @brief Chip select pin of the CAN IC.
 *
 */
#define PIN_CAN_CHIP_SELECT ( 10 )

/*
 * @brief High signal pin of the accelerator position sensor.
 *
 */
#define PIN_ACCELERATOR_POSITION_SENSOR_HIGH ( A0 )

/*
 * @brief Low signal pin of the accelerator position sensor.
 *
 */
#define PIN_ACCELERATOR_POSITION_SENSOR_LOW ( A1 )

/*
 * @brief High signal pin of the accelerator position spoof output.
 *
 */
#define PIN_ACCELERATOR_POSITION_SPOOF_HIGH ( A2 )

/*
 * @brief Low signal pin of the accelerator position spoof output.
 *
 */
#define PIN_ACCELERATOR_POSITION_SPOOF_LOW ( A3 )

/*
 * @brief Relay enable pin for the spoof output.
 *
 */
#define PIN_SPOOF_ENABLE ( 6 )


#ifdef GLOBAL_DEFINED
    DAC_MCP49xx g_dac( DAC_MCP49xx::MCP4922, PIN_DAC_CHIP_SELECT );
    MCP_CAN g_control_can( PIN_CAN_CHIP_SELECT );

    #define EXTERN
#else
    extern DAC_MCP49xx g_dac;
    extern MCP_CAN g_control_can;

    #define EXTERN extern
#endif


EXTERN uint32_t g_throttle_command_last_rx_timestamp;
EXTERN uint32_t g_throttle_report_last_tx_timestamp;

EXTERN kia_soul_throttle_control_state_s g_throttle_control_state;
EXTERN uint16_t g_accelerator_spoof_output_sum;


#endif /* _OSCC_KIA_SOUL_THROTTLE_GLOBALS_H_ */
