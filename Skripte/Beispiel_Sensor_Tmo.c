  # if (ACTIVATE_MOTOR_NTC == ENABLE_OPTION)
  playground_input.motor_temperature_model_sensor = SR_Temperature_NSR_get_value(SR_Temperature_NSR_meas_motor);
  # else
  playground_input.motor_temperature_model_sensor = SR_Temperature_NSR_get_electronics_temperature();
  # endif