/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : TouchGFXHAL.cpp
  ******************************************************************************
  * This file was created by TouchGFX Generator 4.21.3. This file is only
  * generated once! Delete this file from your project and re-generate code
  * using STM32CubeMX or change this file manually to update it.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

#include <TouchGFXHAL.hpp>
#include "stm32l562e_discovery_lcd.h"
#include <touchgfx/hal/OSWrappers.hpp>
extern TIM_HandleTypeDef htim16;

extern "C"  void Update_VSync(void)
{
	touchgfx::HAL::getInstance()->vSync();
	touchgfx::OSWrappers::signalVSync();
}

/* USER CODE BEGIN TouchGFXHAL.cpp */

using namespace touchgfx;

void TouchGFXHAL::initialize()
{
    // Calling parent implementation of initialize().
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.
    // Please note, HAL::initialize() must be called to initialize the framework.

    TouchGFXGeneratedHAL::initialize();
    /* Initializing LCD drivers */
	if (BSP_LCD_Init(0, LCD_ORIENTATION_PORTRAIT) != BSP_ERROR_NONE)
    {
        assert(0 && "Failed to initialize LCD Controller");
    }

	BSP_LCD_DisplayOn(0);
	/**
	  * @brief  Send RGB data to select the LCD GRAM.
	  * @param  Instance:     LCD Instance.
	  * @param  UseDMA:       Specifies if DMA will be used for data Transferring.
	  * @param  pData:        Pointer to data to write to LCD GRAM.
	  * @param  Xpos:         Specifies the X position.
	  * @param  Ypos:         Specifies the Y position.
	  * @param  Height:       Specifies the height of the rectangle to fill.
	  * @param  Width:        Specifies the width of the rectangle to fill.
	  * @retval int32_t:      BSP status.
	  */

	/**
	  * @brief  Fill rectangle with RGB buffer.
	  * @param  Instance LCD Instance.
	  * @param  Xpos X position on LCD.
	  * @param  Ypos Y position on LCD.
	  * @param  pData Pointer on RGB pixels buffer.
	  * @param  Width Width of the rectangle.
	  * @param  Height Height of the rectangle.
	  * @retval BSP status.*/
// if(  BSP_LCD_FillRGBRect(0,
//		 0,
//		 0,
//		 (uint8_t *) 0x20030000,
//		 240,
//		 240)
//		 != BSP_ERROR_NONE)
// {
//     assert(0 && "Failed to initialize LCD Controller");
// }
 HAL_TIM_Base_Start_IT(&htim16);
}

/**
 * Gets the frame buffer address used by the TFT controller.
 *
 * @return The address of the frame buffer currently being displayed on the TFT.
 */
uint16_t* TouchGFXHAL::getTFTFrameBuffer() const
{
    // Calling parent implementation of getTFTFrameBuffer().
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.

    return TouchGFXGeneratedHAL::getTFTFrameBuffer();
}

/**
 * Sets the frame buffer address used by the TFT controller.
 *
 * @param [in] address New frame buffer address.
 */
void TouchGFXHAL::setTFTFrameBuffer(uint16_t* address)
{
    // Calling parent implementation of setTFTFrameBuffer(uint16_t* address).
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.

    TouchGFXGeneratedHAL::setTFTFrameBuffer(address);
}

/**
 * This function is called whenever the framework has performed a partial draw.
 *
 * @param rect The area of the screen that has been drawn, expressed in absolute coordinates.
 *
 * @see flushFrameBuffer().
 */
void TouchGFXHAL::flushFrameBuffer(const touchgfx::Rect& rect)
{
    // Calling parent implementation of flushFrameBuffer(const touchgfx::Rect& rect).
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.
    // Please note, HAL::flushFrameBuffer(const touchgfx::Rect& rect) must
    // be called to notify the touchgfx framework that flush has been performed.
    // To calculate he start adress of rect,
    // use advanceFrameBufferToRect(uint8_t* fbPtr, const touchgfx::Rect& rect)
    // defined in TouchGFXGeneratedHAL.cpp

    //TouchGFXGeneratedHAL::flushFrameBuffer(rect);
	/* Set Cursor */


	    if(  BSP_LCD_FillRGBRect(0,
				 rect.x,
				 rect.y,
				 (uint8_t *) getClientFrameBuffer(),
			 rect.width,
			 rect.height)
	   		 != BSP_ERROR_NONE)
	    {
	        assert(0 && "Failed to initialize LCD Controller");
	    }
}

bool TouchGFXHAL::blockCopy(void* RESTRICT dest, const void* RESTRICT src, uint32_t numBytes)
{
    return TouchGFXGeneratedHAL::blockCopy(dest, src, numBytes);
}

/**
 * Configures the interrupts relevant for TouchGFX. This primarily entails setting
 * the interrupt priorities for the DMA and LCD interrupts.
 */
void TouchGFXHAL::configureInterrupts()
{
    // Calling parent implementation of configureInterrupts().
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.

    TouchGFXGeneratedHAL::configureInterrupts();
}

/**
 * Used for enabling interrupts set in configureInterrupts()
 */
void TouchGFXHAL::enableInterrupts()
{
    // Calling parent implementation of enableInterrupts().
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.

    TouchGFXGeneratedHAL::enableInterrupts();
}

/**
 * Used for disabling interrupts set in configureInterrupts()
 */
void TouchGFXHAL::disableInterrupts()
{
    // Calling parent implementation of disableInterrupts().
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.

    TouchGFXGeneratedHAL::disableInterrupts();
}

/**
 * Configure the LCD controller to fire interrupts at VSYNC. Called automatically
 * once TouchGFX initialization has completed.
 */
void TouchGFXHAL::enableLCDControllerInterrupt()
{
    // Calling parent implementation of enableLCDControllerInterrupt().
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.

    TouchGFXGeneratedHAL::enableLCDControllerInterrupt();
}

bool TouchGFXHAL::beginFrame()
{
    return TouchGFXGeneratedHAL::beginFrame();
}

void TouchGFXHAL::endFrame()
{
    TouchGFXGeneratedHAL::endFrame();
}

/* USER CODE END TouchGFXHAL.cpp */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
