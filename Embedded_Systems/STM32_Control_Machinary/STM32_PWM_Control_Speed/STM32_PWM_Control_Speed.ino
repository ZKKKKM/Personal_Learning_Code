// 根据设定的PWM驱动电机转动

#define ARR 999 /*题目中要求设定的ARR参数*/

void PMW_Setspeed(uint8_t dutycycle) // 假设输入时PWM的占空比值 duty_cycle: [0-100]
{
  /*
  参数：
  ratio : [0, 1]
  CCR: (0, ARR)
  公式；
  ratio = (CCR)/(ARR + 1)
  */
  uint8_t ratio;

  // 处理占空比的不同情况
  if (dutycycle < 0)
    ratio = 0;
  else if (dutycycle > 100)
    ratio = 1;
  else
    ratio = dutycycle / 100 ;

  CCR = ratio * (ARR + 1);
  // 利用PWM设置速度
  __HAL_TIM_Setcompare(&him3,TIM_CHANNEL_1,CCR)


}
