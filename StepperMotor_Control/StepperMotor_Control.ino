#define CW 1
#define CCW 2



void drivestepmotor(int steps);
void main(void)
{
  STM32F407_Init(); // 假设所有初始化在STM32F407已经做完

  while(1)
  {
    // Stage 1: 300 steps rotations CW
    HAL_GPIO_WritePin(GPIOD,GPIO_PIN_4,GPIO_PIN_SET);     // H-Bridge A ON
    HAL_GPIO_WritePin(GPIOD,GPIO_PIN_6,GPIO_PIN_SET);     // H-Bridge B ON
    drivestepmotor(300); 
    // Stage 2: Wait 3 seconds
    HAL_GPIO_WritePin(GPIOD,GPIO_PIN_4, GPIO_PIN_RESET);  
    HAL_GPIO_WritePin(GPIOD,GPIO_PIN_6, GPIO_PIN_RESET); 
    HAL_Delay(3000);

    // Stage 3: 2 full rotations CCW
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_SET);    // H-Bridege A ON 
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_SET);    // H-Bridge  b ON
    drivestepmotor(-400); // 2* -200


    // Stage 4 : Wait 1.5 seconds
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD,GPIO_PIN_6, GPIO_PIN_RESET); 
    HAL_Delay(1500);


  }

}

void drivestepmotor(int step)
{
  int direction;
  int index = 0;
  int step_rem;


  if (step > 0){ direction = CW; }
  if (step < 0){ direction = CCW; }
  setp_rem = abs(step);

  while(setp_rem > 0)
  {
    if (direction == CW)
    {
      // 从 0 开始 直到 step_rem 的次数
      index++;
      if (index == step) {index = 0};
    }
    else
    {
      // 为了消除掉switch不能处理-1 -2 -3的方式，将index 从abs(steps)倒数
      if (index == 0) { index = abs(steps) + 1; }
      index--;
    }

    switch(index % 4)
    {
      case 1: // HH
        HAL_GPIO_WritePin(GPIOD,GPIO_PIN_5,GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD,GPIO_PIN_7,GPIO_PIN_SET);
        break;
      case 2: // LH
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, GPIO_PIN_SET);
        break;
      case 3: // LL
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, GPIO_PIN_RESET);
        break;
      case 4: // HL
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, GPIO_PIN_RESET);
        break;
      default:
        break;
    }

    HAL_Delay(50);
    step_rem--;

  }

}
