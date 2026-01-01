// 启动电机代码
// 功能： 1. 当KEY1闭合时启动电机，当KEY1断开时停止电机。
//        2. 在电机运行状态下，当KEY2闭合时驱动电机顺时针旋转，当KEY2断开时驱动电机逆时针旋转。

// 利用宏定义KEY1 以及 KEY2的状态
#define KEY1_STATE HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_1)
#define KEY2_STATE HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_2)

void main(void)
{
  /*系统初始化*/
  stm32f407board_init();

  while(1)
  {
    if (KEY1_STATE == 0) /* 当 KEY1断开 */
      HAL_GPIO_WritePIN(GPIOD,GPIO_PIN_4,GPIO_PIN_RESET) /* 关闭电机 */
    
    else /*当 KEY1 闭合*/
    {
      HAL_GPIO_WritePIN(GPIOD,GPIO_PIN_4,GPIO_SET); /* 启动电机 */
      if (KEY2_STATE == 0) /* KEY2断开 */
        HAL_GPIO_WritePIN(GPIOD,GPIO_PIN_3,GPIO_PIN_RESET); /* 输出反向电压使其逆时针旋转 */
      else /*Key2 闭合*/
      {
        HAL_GPIO_WritePIN(GPIOD,GPIO_PIN3,GPIO_PIN_SET);
      }
    }
  }





}
