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

}
















void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
