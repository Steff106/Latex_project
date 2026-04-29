/* Outputs for Atomic SubSystem: '<S2>/Variant_Subsystem' */
#if EC_MOTOR_CONTROL == USED_MOTOR_CONTROL
    /* Outputs for Atomic SubSystem: '<S4>/Subsystem1' */
    /* Switch: '<S5>/Switch' incorporates:
     *  Constant: '<S5>/Constant'
     *  Constant: '<S5>/Constant1'
     *  Inport: '<Root>/MBSE_input' */
    if (MBSE_input.test_in > 0.0F) {
      MBSE_output.test_out = 1.0F;
    } else {
      MBSE_output.test_out = 0.0F;
    }
    /* End of Switch: '<S5>/Switch' */
    /* End of Outputs for SubSystem: '<S4>/Subsystem1' */
#else
    /* Outputs for Atomic SubSystem: '<S4>/Subsystem2' */
    /* Switch: '<S6>/Switch' incorporates:
     *  Constant: '<S6>/Constant'
     *  Constant: '<S6>/Constant1'
     *  Inport: '<Root>/MBSE_input' */
    if (MBSE_input.test_in > 0.0F) {
      MBSE_output.test_out = 2.0F;
    } else {
      MBSE_output.test_out = 0.0F;
    }
    /* End of Switch: '<S6>/Switch' */
    /* End of Outputs for SubSystem: '<S4>/Subsystem2' */
#endif
    /* End of Outputs for SubSystem: '<S2>/Variant_Subsystem' */
	
#include "Options_catalog.h"
#if EC_MOTOR_CONTROL == USED_MOTOR_CONTROL
    if (MBSE_input.test_in > 0.0F) {
      MBSE_output.test_out = 1.0F;
    } else {
      MBSE_output.test_out = 0.0F;
    }
#else
    if (MBSE_input.test_in > 0.0F) {
      MBSE_output.test_out = 2.0F;
    } else {
      MBSE_output.test_out = 0.0F;
    }
#endif