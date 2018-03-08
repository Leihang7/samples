/*
 * File      : thread_create.c
 * This file is part of RT-Thread RTOS
 * COPYRIGHT (C) 2012, RT-Thread Development Team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-03-01     Tanek        the first version
 */

#include <stdio.h>
#include <rtthread.h>

/* the system main thread */
void sample_thread_entry(void *parameter)
{
    int counter = 0;
    rt_kprintf("%s\n", __FUNCTION__);
    
    while (1)
    {
        rt_kprintf("counter: %d\n", counter++);
        rt_thread_delay(RT_TICK_PER_SECOND);
    }
}

int sample_thread_create(void)
{
    rt_thread_t tid;
    
    rt_kprintf("%s\n", __FUNCTION__);

    tid = rt_thread_create("sample", sample_thread_entry, RT_NULL,
                           1024, RT_THREAD_PRIORITY_MAX / 3, 20);
    
    if (tid != RT_NULL)
    {
        rt_thread_startup(tid);
    }
    else
    {
        RT_ASSERT(tid != RT_NULL);
    }
    
    return 0;
}
INIT_APP_EXPORT(sample_thread_create);
