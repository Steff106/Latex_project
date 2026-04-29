/** @brief Get motorcontrol limits for playground input in SI units, q15_t --> float */
static void get_motorcontrol_limits_playground(Mc_limits_playground * const p_limits_float)
{
  bool is_acceleration_active;
  Mc_limits_t Mc_limits_q15 =
  {
    .q_max_current_amplitude = 0,
    .q_min_torque = 0,
    .q_max_torque = 0,
    .q_min_power  = 0,
    .q_max_power  = 0
  };
  // get limits
  is_acceleration_active = Motor_control_sm_get_acceleration_active();
  Motor_control_SM_get_motorcontrol_limits(&Mc_limits_q15, is_acceleration_active);
  /* Convert and copy to limit structure */
  p_limits_float->q_max_current_amplitude = Math_convert_q15_to_float32(Mc_limits_q15.q_max_current_amplitude, (float)BASIS_CURRENT);
  p_limits_float->q_max_power = Math_convert_q15_to_float32(Mc_limits_q15.q_max_power, (float)BASIS_POWER);
  ...
}