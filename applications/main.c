/*
 * Copyright (c) 2006-2020, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2020-10-21     RT-Thread    first version
 */

#include <rtthread.h>
#include <rtdevice.h>
#include <drv_common.h>

#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>


#define LEDR_PIN    GET_PIN(B, 2)
#define LEDG_PIN    GET_PIN(E, 8)
//#define LED5_PIN    GET_PIN(D, 14)
//#define LED6_PIN    GET_PIN(D, 15)

int main(void)
{
    int count = 1;
    /* set LED0 pin mode to output */
    rt_pin_mode(LEDR_PIN, PIN_MODE_OUTPUT);
    rt_pin_mode(LEDG_PIN, PIN_MODE_OUTPUT);

    LOG_D("Hello RT-Thread!");
    while (count++)
    {
        /* set LED0 pin level to high or low */
        rt_pin_write(LEDR_PIN, count % 2);
        rt_thread_mdelay(100);
        rt_pin_write(LEDG_PIN, count % 2);
        rt_thread_mdelay(100);
    }

    return RT_EOK;
}
