//PID 控制水阀启动程序
/* PID计算程序 */
uint8_t PIDcalc(uint8_t level_des, uint8_t level_act, uint8_t Kp,uint8_t Ki, uint8_t Kd)
{
  /*
  输入：
      1. 期望水位 level_des
      2. 实际水位 level_act
      3. 比例因子 Kp
      4. 积分因子 Ki
      5. 微分因子 Kd
  输出：
      控制信号(阀门打开程度)：u_new
  公式：
      离散形式
      u_delta = Kp * (error_delta) + Ki * error_current + Kd * (error_delta-error_delta_last)
      u_new = u_old + u_delta
  */
  
  
  /* 这里需要将控制的旧值，误差一次旧值以及误差二次旧值设定成static */
  // 主要原因是 如果不设置成static的话，那么重新进入这个函数的时候就会将这些值进行清空，所以必须固定住他们
  static uint8_t u_old = 0, error_old = 0, error_old2 = 0;
  uint8_t error_new;
  uint8_t u_new;

  //计算当前误差
  error_new = level_des - level_act;
  
  u_new = u_old + Kp*(error_new-error_old) + Ki*error_new + Kd*(error_new - 2 * error_old + error_old2);

  // 更新误差值以及控制信号值
  error_old2 = error_old;
  error_old = error_new;
  u_old = u_new;

  return u_new

}
