// 函数1 LED的EXIT代码
uint32_t count = 0;
void HAL_GPIO_EXIT_Callback(uint16_t GPIO_Pin)
{
  UNUSED(GPIO_Pin);

  /*利用switch 语句进行选择判断，要记住每个case最后要加break*/   
  switch(GPIO_Pin){
    case GPIO_PIN_1:
      // Toogle 逻辑 翻转逻辑
      // 在图中，PD4接的是LED灯1，然后PD4对应的端口组以及具体的引脚号分别是GPIOD和GPIO_PIN_4
      HAL_GPIO_TooglePin(GPIOD, GPIO_PIN_4);

      break;
    case GPION_PIN_2:
      // 这里要加是因为要数Key2的数字
      count++; 
      if (count>= 6) and (count<= 10){
        //如果Key2大于等于6小于等于10的话，要打开LED2
        HAL_GPIO_WritePin(GPIOD,GPIO_PIN_5,GPIO_PIN_SET);
      }
      else{
        //如果Key2大于10的话，要关闭LED2
        HAL_GPIO_WritePin(GPIOD,GPIO_PIN_5,GPION_PIN_RESET);
      }
      break;
    default: 
      break;
  }

}

// 函数2 按钮的去抖动代码
const debouncefrequency = 10;
// GPIO_TypeDef* 代表的是寄存器的首地址，
uint8_t debounce(GPIO_TypeDef* GPIOx, uint16_t GPIO_PIN)
{
  // 初始化状态 定义 当前状态以及上一秒的状态
  uint8_t state;
  uint8_t state_last;
  //读上一步的状态
  state_last = HAL_GPIO_ReadPin(GPIO_TypeDef* GPIOx, GPIO_PIN);
  
  // 去抖动核心逻辑
  for (int counter = 0; count< deboouncefrequency; count++)
  {
    HAL_Delay(1); //延时一秒
    state = HAL_GPIO_ReadPin(GPIO_TypeDef* GPIOx,GPIO_PIN); //读取目前的状态
    
    // 如果目前的状态不等于上一次状态，说明还在抖动状态
    // 那么就要重新清零计数器，并且更新上一次的状态
    if (state != state_last) 
    {
      counter = 0;
      state_last = state;
    }

  }

  // 最后到达了消除抖动的阶段，所以目前的状态是稳定的，也就可以正常输出
  if(state == 0)
  {
    return 1; // state 等于0 说明摁下，也就是表示True 按下  
  }
  else
  {
    return 0; //其他情况设置成0
  }


}
















void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
