if (playground_output.motor_temperature_hot == true)
  {
    SR_Error_trigger(SR_Error_codes_instance_master, (uint8_t)NSR_Error_code_motor_temperature_hot, 1u);
  }
if (playground_output.electronic_temperature_hot == true)
  {
    SR_Error_trigger(SR_Error_codes_instance_master, (uint8_t)NSR_Error_code_electronic_temperature_hot, 0u);
  }