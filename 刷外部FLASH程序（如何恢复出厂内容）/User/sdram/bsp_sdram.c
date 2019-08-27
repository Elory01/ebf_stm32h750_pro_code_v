/**
  ******************************************************************************
  * @file    bsp_sdram.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   sdramӦ�ú����ӿ�
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:Ұ��  STM32 H750 ������  
  * ��̳    :http://www.chuxue123.com
  * �Ա�    :http://firestm32.taobao.com
  *
  ******************************************************************************
  */
  
#include "./sdram/bsp_sdram.h"  
static FMC_SDRAM_CommandTypeDef Command;
SDRAM_HandleTypeDef hsdram1;
#define sdramHandle hsdram1
/**
  * @brief  �ӳ�һ��ʱ��
  * @param  �ӳٵ�ʱ�䳤��
  * @retval None
  */
static void SDRAM_delay(__IO uint32_t nCount)
{
  __IO uint32_t index = 0; 
  for(index = (100000 * nCount); index != 0; index--)
  {
  }
}

/**
  * @brief  ��ʼ������SDRAM��IO
  * @param  ��
  * @retval ��
  */
static void SDRAM_GPIO_Config(void)
{		
	GPIO_InitTypeDef GPIO_InitStructure;
  
	/* ʹ��SDRAM��ص�IOʱ�� */
	/*��ַ�ź���*/
	FMC_A0_GPIO_CLK();FMC_A1_GPIO_CLK(); FMC_A2_GPIO_CLK();
	FMC_A3_GPIO_CLK();FMC_A4_GPIO_CLK(); FMC_A5_GPIO_CLK();
	FMC_A6_GPIO_CLK();FMC_A7_GPIO_CLK(); FMC_A8_GPIO_CLK();
	FMC_A9_GPIO_CLK();FMC_A10_GPIO_CLK();FMC_A11_GPIO_CLK();
	FMC_A12_GPIO_CLK();
	/*�����ź���*/
	FMC_D0_GPIO_CLK(); FMC_D1_GPIO_CLK() ; FMC_D2_GPIO_CLK() ; 
	FMC_D3_GPIO_CLK(); FMC_D4_GPIO_CLK() ; FMC_D5_GPIO_CLK() ;
	FMC_D6_GPIO_CLK(); FMC_D7_GPIO_CLK() ; FMC_D8_GPIO_CLK() ;
	FMC_D9_GPIO_CLK(); FMC_D10_GPIO_CLK(); FMC_D11_GPIO_CLK();
	FMC_D12_GPIO_CLK();FMC_D13_GPIO_CLK(); FMC_D14_GPIO_CLK();
	FMC_D15_GPIO_CLK();FMC_D16_GPIO_CLK(); FMC_D17_GPIO_CLK(); 
	FMC_D18_GPIO_CLK();FMC_D19_GPIO_CLK(); FMC_D20_GPIO_CLK();
	FMC_D21_GPIO_CLK();FMC_D22_GPIO_CLK(); FMC_D23_GPIO_CLK();
	FMC_D24_GPIO_CLK();FMC_D25_GPIO_CLK(); FMC_D26_GPIO_CLK();
	FMC_D27_GPIO_CLK();FMC_D28_GPIO_CLK(); FMC_D29_GPIO_CLK();
	FMC_D30_GPIO_CLK();FMC_D31_GPIO_CLK();	
	/*�����ź���*/
	FMC_CS_GPIO_CLK() ; FMC_BA0_GPIO_CLK(); FMC_BA1_GPIO_CLK() ;
	FMC_WE_GPIO_CLK() ; FMC_RAS_GPIO_CLK(); FMC_CAS_GPIO_CLK();
	FMC_CLK_GPIO_CLK(); FMC_CKE_GPIO_CLK(); FMC_UDQM_GPIO_CLK();
	FMC_LDQM_GPIO_CLK();FMC_UDQM2_GPIO_CLK();FMC_LDQM2_GPIO_CLK();
  
	/*-- SDRAM IO ���� -----------------------------------------------------*/     
	GPIO_InitStructure.Mode      = GPIO_MODE_AF_PP;//����Ϊ���ù���
	GPIO_InitStructure.Pull      = GPIO_PULLUP;
	GPIO_InitStructure.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStructure.Alternate = GPIO_AF12_FMC;

	/*��ַ�ź��� �����������*/
	GPIO_InitStructure.Pin = FMC_A0_GPIO_PIN; 
	HAL_GPIO_Init(FMC_A0_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_A1_GPIO_PIN; 
	HAL_GPIO_Init(FMC_A1_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_A2_GPIO_PIN; 
	HAL_GPIO_Init(FMC_A2_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_A3_GPIO_PIN; 
	HAL_GPIO_Init(FMC_A3_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_A4_GPIO_PIN; 
	HAL_GPIO_Init(FMC_A4_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_A5_GPIO_PIN; 
	HAL_GPIO_Init(FMC_A5_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_A6_GPIO_PIN; 
	HAL_GPIO_Init(FMC_A6_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_A7_GPIO_PIN; 
	HAL_GPIO_Init(FMC_A7_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_A8_GPIO_PIN; 
	HAL_GPIO_Init(FMC_A8_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_A9_GPIO_PIN; 
	HAL_GPIO_Init(FMC_A9_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_A10_GPIO_PIN; 
	HAL_GPIO_Init(FMC_A10_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_A11_GPIO_PIN; 
	HAL_GPIO_Init(FMC_A11_GPIO_PORT, &GPIO_InitStructure);
	
  GPIO_InitStructure.Pin = FMC_A12_GPIO_PIN; 
	HAL_GPIO_Init(FMC_A12_GPIO_PORT, &GPIO_InitStructure);

	/*�����ź��� �����������*/
	GPIO_InitStructure.Pin = FMC_D0_GPIO_PIN; 
	HAL_GPIO_Init(FMC_D0_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_D1_GPIO_PIN; 
	HAL_GPIO_Init(FMC_D1_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_D2_GPIO_PIN; 
	HAL_GPIO_Init(FMC_D2_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_D3_GPIO_PIN; 
	HAL_GPIO_Init(FMC_D3_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_D4_GPIO_PIN; 
	HAL_GPIO_Init(FMC_D4_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_D5_GPIO_PIN; 
	HAL_GPIO_Init(FMC_D5_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_D6_GPIO_PIN; 
	HAL_GPIO_Init(FMC_D6_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_D7_GPIO_PIN; 
	HAL_GPIO_Init(FMC_D7_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_D8_GPIO_PIN; 
	HAL_GPIO_Init(FMC_D8_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_D9_GPIO_PIN; 
	HAL_GPIO_Init(FMC_D9_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_D10_GPIO_PIN; 
	HAL_GPIO_Init(FMC_D10_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_D11_GPIO_PIN; 
	HAL_GPIO_Init(FMC_D11_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_D12_GPIO_PIN; 
	HAL_GPIO_Init(FMC_D12_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_D13_GPIO_PIN; 
	HAL_GPIO_Init(FMC_D13_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_D14_GPIO_PIN; 
	HAL_GPIO_Init(FMC_D14_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_D15_GPIO_PIN; 
	HAL_GPIO_Init(FMC_D15_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_D16_GPIO_PIN; 
	HAL_GPIO_Init(FMC_D16_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_D17_GPIO_PIN; 
	HAL_GPIO_Init(FMC_D17_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_D18_GPIO_PIN; 
	HAL_GPIO_Init(FMC_D18_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_D19_GPIO_PIN; 
	HAL_GPIO_Init(FMC_D19_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_D20_GPIO_PIN; 
	HAL_GPIO_Init(FMC_D20_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_D21_GPIO_PIN; 
	HAL_GPIO_Init(FMC_D21_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_D22_GPIO_PIN; 
	HAL_GPIO_Init(FMC_D22_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_D23_GPIO_PIN; 
	HAL_GPIO_Init(FMC_D23_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_D24_GPIO_PIN; 
	HAL_GPIO_Init(FMC_D24_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_D25_GPIO_PIN; 
	HAL_GPIO_Init(FMC_D25_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_D26_GPIO_PIN; 
	HAL_GPIO_Init(FMC_D26_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_D27_GPIO_PIN; 
	HAL_GPIO_Init(FMC_D27_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_D28_GPIO_PIN; 
	HAL_GPIO_Init(FMC_D28_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_D29_GPIO_PIN; 
	HAL_GPIO_Init(FMC_D29_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_D30_GPIO_PIN; 
	HAL_GPIO_Init(FMC_D30_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_D31_GPIO_PIN; 
	HAL_GPIO_Init(FMC_D31_GPIO_PORT, &GPIO_InitStructure);
	/*�����ź���*/
	GPIO_InitStructure.Pin = FMC_CS_GPIO_PIN; 
	HAL_GPIO_Init(FMC_CS_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_BA0_GPIO_PIN; 
	HAL_GPIO_Init(FMC_BA0_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_BA1_GPIO_PIN;
	HAL_GPIO_Init(FMC_BA1_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_WE_GPIO_PIN; 
	HAL_GPIO_Init(FMC_WE_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_RAS_GPIO_PIN; 
	HAL_GPIO_Init(FMC_RAS_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_CAS_GPIO_PIN; 
	HAL_GPIO_Init(FMC_CAS_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_CLK_GPIO_PIN; 
	HAL_GPIO_Init(FMC_CLK_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_CKE_GPIO_PIN; 
	HAL_GPIO_Init(FMC_CKE_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_UDQM_GPIO_PIN; 
	HAL_GPIO_Init(FMC_UDQM_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_LDQM_GPIO_PIN; 
	HAL_GPIO_Init(FMC_LDQM_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_UDQM2_GPIO_PIN; 
	HAL_GPIO_Init(FMC_UDQM2_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = FMC_LDQM2_GPIO_PIN; 
	HAL_GPIO_Init(FMC_LDQM2_GPIO_PORT, &GPIO_InitStructure);
}

/**
  * @brief  ��SDRAMоƬ���г�ʼ������
  * @param  None. 
  * @retval None.
  */
static void SDRAM_InitSequence(void)
{
	uint32_t tmpr = 0;

	/* Step 1 ----------------------------------------------------------------*/
	/* ������������ṩ��SDRAM��ʱ�� */
	Command.CommandMode = FMC_SDRAM_CMD_CLK_ENABLE;
	Command.CommandTarget = FMC_COMMAND_TARGET_BANK;
	Command.AutoRefreshNumber = 1;
	Command.ModeRegisterDefinition = 0;
	/* ������������ */
	HAL_SDRAM_SendCommand(&sdramHandle, &Command, SDRAM_TIMEOUT);

	/* Step 2: ��ʱ100us */ 
	SDRAM_delay(1);

	/* Step 3 ----------------------------------------------------------------*/
	/* ������������е�bankԤ��� */ 
	Command.CommandMode = FMC_SDRAM_CMD_PALL;
	Command.CommandTarget = FMC_COMMAND_TARGET_BANK;
	Command.AutoRefreshNumber = 1;
	Command.ModeRegisterDefinition = 0;
	/* ������������ */
	HAL_SDRAM_SendCommand(&sdramHandle, &Command, SDRAM_TIMEOUT);   

	/* Step 4 ----------------------------------------------------------------*/
	/* ��������Զ�ˢ�� */   
	Command.CommandMode = FMC_SDRAM_CMD_AUTOREFRESH_MODE;
	Command.CommandTarget = FMC_COMMAND_TARGET_BANK;
	Command.AutoRefreshNumber = 8;
	Command.ModeRegisterDefinition = 0;
	/* ������������ */
	HAL_SDRAM_SendCommand(&sdramHandle, &Command, SDRAM_TIMEOUT);

	/* Step 5 ----------------------------------------------------------------*/
	/* ����sdram�Ĵ������� */
	tmpr = (uint32_t)SDRAM_MODEREG_BURST_LENGTH_1          |
				   SDRAM_MODEREG_BURST_TYPE_SEQUENTIAL   |
				   SDRAM_MODEREG_CAS_LATENCY_3           |
				   SDRAM_MODEREG_OPERATING_MODE_STANDARD |
				   SDRAM_MODEREG_WRITEBURST_MODE_SINGLE;

	/* �����������SDRAM�Ĵ��� */
	Command.CommandMode = FMC_SDRAM_CMD_LOAD_MODE;
	Command.CommandTarget = FMC_COMMAND_TARGET_BANK;
	Command.AutoRefreshNumber = 1;
	Command.ModeRegisterDefinition = tmpr;
	/* ������������ */
	HAL_SDRAM_SendCommand(&sdramHandle, &Command, SDRAM_TIMEOUT);

	/* Step 6 ----------------------------------------------------------------*/

	/* ����ˢ�¼����� */
	/* ˢ������=64ms/8192��=7.8125us */
	/* COUNT=(7.8125us x Freq) - 20 */
	/* ������ˢ������ */
	HAL_SDRAM_ProgramRefreshRate(&sdramHandle, 824); 
}


/**
  * @brief  ��ʼ������ʹ��SDRAM��FMC��GPIO�ӿڣ�
  *         ��������SDRAM��д����ǰ��Ҫ������
  * @param  None
  * @retval None
  */
void SDRAM_Init(void)
{

  //ʹ��GPIO��ʱ��
  RCC->AHB4ENR |= 0x1FC; 

  //���ö˿�C��D��E��F��G��H��I��Ӧ������Ϊ�����������
  GPIOC->MODER = 0xFFFFFFFE;
  GPIOC->OTYPER = 0;
  GPIOC->OSPEEDR = 0x00000003;
  GPIOC->PUPDR = 0x00000001;
  GPIOC->AFR[0] = 0x0000000C;
  
  GPIOD->MODER = 0xAFEAFFFA;
  GPIOD->OTYPER = 0;
  GPIOD->OSPEEDR = 0xF03F000F;
  GPIOD->PUPDR = 0x50150005;
  GPIOD->AFR[0] = 0x000000CC;  
  GPIOD->AFR[1] = 0xCC000CCC;

  GPIOE->MODER = 0xAAAABFFA;
  GPIOE->OTYPER = 0;
  GPIOE->OSPEEDR = 0xFFFFC00F;
  GPIOE->PUPDR = 0x55554005;
  GPIOE->AFR[0] = 0xC00000CC;  
  GPIOE->AFR[1] = 0xCCCCCCCC;
  
  GPIOF->MODER = 0xAABFFAAA;
  GPIOF->OTYPER = 0;
  GPIOF->OSPEEDR = 0xFFC00FFF;
  GPIOF->PUPDR = 0x55400555;
  GPIOF->AFR[0] = 0x00CCCCCC;
  GPIOF->AFR[1] = 0xCCCCC000;
  
  GPIOG->MODER = 0xBFFEFAEA;
  GPIOG->OTYPER = 0;
  GPIOG->OSPEEDR = 0xC0030F3F;
  GPIOG->PUPDR = 0x40010515;
  GPIOG->AFR[0] = 0x00CC0CCC;  
  GPIOG->AFR[1] = 0xC000000C;

  GPIOH->MODER = 0xAAAAAFFF;
  GPIOH->OTYPER = 0;
  GPIOH->OSPEEDR = 0xFFFFF000;
  GPIOH->PUPDR = 0x55555000;
  GPIOH->AFR[0] = 0xCC000000;  
  GPIOH->AFR[1] = 0xCCCCCCCC;  

  GPIOI->MODER = 0xFFEBAAAA;
  GPIOI->OTYPER = 0;
  GPIOI->OSPEEDR = 0x003CFFFF;
  GPIOI->PUPDR = 0x00145555;
  GPIOI->AFR[0] = 0xCCCCCCCC;  
  GPIOI->AFR[1] = 0x00000CC0;
  
//  //ʹ��PLL2R
//  RCC->PLLCFGR |= (1 << 21); 
//  //����PLL2
//  RCC->CR &= ~(1 << 26);
//  RCC->PLLCKSELR |= (5 << 12);
//  RCC->PLL2DIVR = 0x0201028F;
//  RCC->PLLCFGR |= (2<<6);
//  RCC->PLLCFGR &= ~(1<<5);
//  RCC->CR |= (1 << 26);
//  while(!(RCC->CR&(1<<27)));
  //RCC->D1CCIPR |= (1<<0); 

  //ʹ��FMCʱ��
  RCC->AHB3ENR |= (1 << 12); 
  FMC_SDRAM_DEVICE->SDCR[0] = 0x00003AD0;  
  FMC_SDRAM_DEVICE->SDCR[1] = 0x000001E9;  
  FMC_SDRAM_DEVICE->SDTR[0] = 0x0F1F7FFF;  
  FMC_SDRAM_DEVICE->SDTR[1] = 0x01010471;                                         
  FMC_Bank1_R->BTCR[0] |= 0x80000000;  
  
  
	/* Step 1 ----------------------------------------------------------------*/
	/* ������������ṩ��SDRAM��ʱ�� */
   
  FMC_SDRAM_DEVICE->SDCMR = 0x00000009;
  while((FMC_SDRAM_DEVICE->SDSR&(1<<5)));
	/* Step 2: ��ʱ100us */ 
	SDRAM_delay(1);

	/* Step 3 ----------------------------------------------------------------*/
	/* ������������е�bankԤ��� */ 

  FMC_SDRAM_DEVICE->SDCMR = 0x0000000A;
  while((FMC_SDRAM_DEVICE->SDSR&(1<<5)));

	/* Step 4 ----------------------------------------------------------------*/
	/* ��������Զ�ˢ�� */   
  FMC_SDRAM_DEVICE->SDCMR = 0x000000EB;
  while((FMC_SDRAM_DEVICE->SDSR&(1<<5)));

	/* Step 5 ----------------------------------------------------------------*/
	/* ����sdram�Ĵ������� */
  FMC_SDRAM_DEVICE->SDCMR =0x0004600C;
  while((FMC_SDRAM_DEVICE->SDSR&(1<<5)));
	/* Step 6 ----------------------------------------------------------------*/
  /* ������ˢ������ */
  FMC_SDRAM_DEVICE->SDRTR |= (1855<<1);  
}



/**
  * @brief  �ԡ��֡�Ϊ��λ��sdramд������ 
  * @param  pBuffer: ָ�����ݵ�ָ�� 
  * @param  uwWriteAddress: Ҫд���SDRAM�ڲ���ַ
  * @param  uwBufferSize: Ҫд�����ݴ�С
  * @retval None.
  */
void SDRAM_WriteBuffer(uint32_t* pBuffer, uint32_t uwWriteAddress, uint32_t uwBufferSize)
{
  __IO uint32_t write_pointer = (uint32_t)uwWriteAddress;

  /* ��ֹд���� */
  HAL_SDRAM_WriteProtection_Disable(&hsdram1);
  /* ���SDRAM��־���ȴ���SDRAM���� */ 
  while(HAL_SDRAM_GetState(&hsdram1) != RESET)
  {
  }

  /* ѭ��д������ */
  for (; uwBufferSize != 0; uwBufferSize--) 
  {
    /* �������ݵ�SDRAM */
    *(uint32_t *) (SDRAM_BANK_ADDR + write_pointer) = *pBuffer++;

    /* ��ַ����*/
    write_pointer += 4;
  }
    
}

/**
  * @brief  ��SDRAM�ж�ȡ���� 
  * @param  pBuffer: ָ��洢���ݵ�buffer
  * @param  ReadAddress: Ҫ��ȡ���ݵĵ�ʮ
  * @param  uwBufferSize: Ҫ��ȡ�����ݴ�С
  * @retval None.
  */
void SDRAM_ReadBuffer(uint32_t* pBuffer, uint32_t uwReadAddress, uint32_t uwBufferSize)
{
  __IO uint32_t write_pointer = (uint32_t)uwReadAddress;
  
   
  /* ���SDRAM��־���ȴ���SDRAM���� */  
  while ( HAL_SDRAM_GetState(&hsdram1) != RESET)
  {
  }
  
  /*��ȡ���� */
  for(; uwBufferSize != 0x00; uwBufferSize--)
  {
   *pBuffer++ = *(__IO uint32_t *)(SDRAM_BANK_ADDR + write_pointer );
    
   /* ��ַ����*/
    write_pointer += 4;
  } 
}


/**
  * @brief  ����SDRAM�Ƿ����� 
  * @param  None
  * @retval ��������1���쳣����0
  */
uint8_t SDRAM_Test(void)
{
  /*д�����ݼ�����*/
  uint32_t counter=0;
  
  /* 8λ������ */
  uint8_t ubWritedata_8b = 0, ubReaddata_8b = 0;  
  
  /* 16λ������ */
  uint16_t uhWritedata_16b = 0, uhReaddata_16b = 0; 
  
  SDRAM_INFO("���ڼ��SDRAM����8λ��16λ�ķ�ʽ��дsdram...");


  /*��8λ��ʽ��д���ݣ���У��*/
  
  /* ��SDRAM����ȫ������Ϊ0 ��SDRAM_SIZE����8λΪ��λ�� */
  for (counter = 0x00; counter < SDRAM_SIZE; counter++)
  {
    *(__IO uint8_t*) (SDRAM_BANK_ADDR + counter) = (uint8_t)0x0;
  }
  
  /* ������SDRAMд������  8λ */
  for (counter = 0; counter < SDRAM_SIZE; counter++)
  {
    *(__IO uint8_t*) (SDRAM_BANK_ADDR + counter) = (uint8_t)(ubWritedata_8b + counter);
  }
  
  /* ��ȡ SDRAM ���ݲ����*/
  for(counter = 0; counter<SDRAM_SIZE;counter++ )
  {
    ubReaddata_8b = *(__IO uint8_t*)(SDRAM_BANK_ADDR + counter);  //�Ӹõ�ַ��������
    
    if(ubReaddata_8b != (uint8_t)(ubWritedata_8b + counter))      //������ݣ�������ȣ���������,���ؼ��ʧ�ܽ����
    {
      SDRAM_ERROR("8λ���ݶ�д���󣡳���λ�ã�%d",counter);
      return 0;
    }
  }
	
  
  /*��16λ��ʽ��д���ݣ������*/
  
  /* ��SDRAM����ȫ������Ϊ0 */
  for (counter = 0x00; counter < SDRAM_SIZE/2; counter++)
  {
    *(__IO uint16_t*) (SDRAM_BANK_ADDR + 2*counter) = (uint16_t)0x00;
  }
  
  /* ������SDRAMд������  16λ */
  for (counter = 0; counter < SDRAM_SIZE/2; counter++)
  {
    *(__IO uint16_t*) (SDRAM_BANK_ADDR + 2*counter) = (uint16_t)(uhWritedata_16b + counter);
  }
  
    /* ��ȡ SDRAM ���ݲ����*/
  for(counter = 0; counter<SDRAM_SIZE/2;counter++ )
  {
    uhReaddata_16b = *(__IO uint16_t*)(SDRAM_BANK_ADDR + 2*counter);  //�Ӹõ�ַ��������
    
    if(uhReaddata_16b != (uint16_t)(uhWritedata_16b + counter))      //������ݣ�������ȣ���������,���ؼ��ʧ�ܽ����
    {
      SDRAM_ERROR("16λ���ݶ�д���󣡳���λ�ã�%d",counter);

      return 0;
    }
  }

  
  SDRAM_INFO("SDRAM��д����������"); 
  /*���������return 1 */
  return 1;
  

}


/*********************************************END OF FILE**********************/

