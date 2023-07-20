
/* Include STM HAL for your desired chip */
#include "stm32f7xx_hal.h"

/* == CONFIGURATION == */

// Specify the instance (memory adress) of the timer peripheral
#define TIMER_INSTANCE      (   TIM8    )


/* == TYPES/DEFINES/MACROS == */

/* == FILE SCOPE FUNCS == */

/* == FILE SCOPE VARS == */

/* Timer Handle */
static TIM_HandleTypeDef htim;

/* == INTERFACE FUNCTIONS == */

void ws2812b_LL_TimerInit ( void ){

    TIM_MasterConfigTypeDef sMasterConfig;
    TIM_OC_InitTypeDef sConfigOC;

    htim.Instance = TIMER_INSTANCE;
    htim.Init.Prescaler = 14;
    htim.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim.Init.Period = 40;
    htim.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    if (HAL_TIM_PWM_Init(&htim) != HAL_OK)
    {
    _Error_Handler(__FILE__, __LINE__);
    }

    sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
    sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
    if (HAL_TIMEx_MasterConfigSynchronization(&htim, &sMasterConfig) != HAL_OK)
    {
    _Error_Handler(__FILE__, __LINE__);
    }

    sConfigOC.OCMode = TIM_OCMODE_PWM1;
    sConfigOC.Pulse = 0;
    sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
    if (HAL_TIM_PWM_ConfigChannel(&htim, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
    {
    _Error_Handler(__FILE__, __LINE__);
    }

    HAL_TIM_MspPostInit(&htim);
}

void ws2812b_LL_StartDma ( void * dmaBuffer, uint32_t bufferSizeBytes ) {
  
}