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
//    int count = 1;
//    /* set LED0 pin mode to output */
//    rt_pin_mode(LEDR_PIN, PIN_MODE_OUTPUT);
//    rt_pin_mode(LEDG_PIN, PIN_MODE_OUTPUT);
//
//    LOG_D("Hello RT-Thread!");
//    while (count++)
//    {
//        /* set LED0 pin level to high or low */
//        rt_pin_write(LEDR_PIN, count % 2);
//        rt_thread_mdelay(100);
//        rt_pin_write(LEDG_PIN, count % 2);
//        rt_thread_mdelay(100);
//    }

    return RT_EOK;
}

/*
 * Manifest of programs: Marquee sample
 *
 * marquee is probably the simplest example, it is like the first program
 * Hello World in every programming language that programmers learned.
 * So we will start with a marquee in the following example, start a thread to make it periodically
 * update (turn on or off) the LED.
 */

int led(void)
{
    rt_uint8_t count;

    rt_pin_mode(LEDR_PIN, PIN_MODE_OUTPUT);

    for(count = 0 ; count < 10 ;count++)
    {
        rt_pin_write(LEDR_PIN, PIN_HIGH);
        rt_kprintf("led on, count : %d\r\n", count);
        rt_thread_mdelay(500);

        rt_pin_write(LEDR_PIN, PIN_LOW);
        rt_kprintf("led off\r\n");
        rt_thread_mdelay(500);
    }
    return 0;
}
MSH_CMD_EXPORT(led, RT-Thread first led sample);
