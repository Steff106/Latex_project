/*
 * File: Chart.c
 *
 * Code generated for Simulink model 'Chart'.
 *
 * Model version                  : 11.49
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Nov 20 14:06:02 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. Execution efficiency
 *    3. RAM efficiency
 * Validation result: Not run
 */

#include "Chart.h"
#include "Chart_types.h"
#include "rtwtypes.h"

/* Exported data definition */

/* Definition for custom storage class: FileScope */
static uint8_t rtis_active_c3_Chart;   /* '<Root>/Chart' */

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Model step function */
void Chart_step(void)
{
  /* Chart: '<Root>/Chart' */
  if (((uint32_t)rtis_active_c3_Chart) == 0U) {
    rtis_active_c3_Chart = 1U;
#if EC_MOTOR_CONTROL == USED_MOTOR_CONTROL
    /* Outport: '<Root>/Motor' */
    rtY.Motor = 1.0;
#elif EC_MOTOR_CONTROL != USED_MOTOR_CONTROL
    /* Outport: '<Root>/Motor' */
    rtY.Motor = 2.0;
#endif

  } else {

#if EC_MOTOR_CONTROL == USED_MOTOR_CONTROL

    /* Outport: '<Root>/Motor' */
    rtY.Motor = 1.0;

#elif EC_MOTOR_CONTROL != USED_MOTOR_CONTROL

    /* Outport: '<Root>/Motor' */
    rtY.Motor = 2.0;

#endif

  }

  /* End of Chart: '<Root>/Chart' */
}

/* Model initialize function */
void Chart_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
