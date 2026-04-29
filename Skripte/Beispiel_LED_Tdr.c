#if (MODELBASED_PLAYGROUND == ENABLE_OPTION)
  bool derating_active = playground_out.derating_LED_active;
#else
  bool derating_mosfet_temperature_active = check_mosfet_temperature_derating_LED();
  bool derating_motor_temperature_active  = check_motor_temperature_derating_LED();
  bool derating_active = derating_mosfet_temperature_active || derating_motor_temperature_active;
#endif