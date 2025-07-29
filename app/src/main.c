/******************************************************************************************
*@file    main.c
*@brief   Main application file for the Zephyr project
*@spdx_license_identifier: Apache-2.0
******************************************************************************************/

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

#include <app/drivers/blink.h>

#include <app_version.h>

LOG_MODULE_REGISTER(main, CONFIG_APP_LOG_LEVEL);

int main(void)
{
	int err = 0;

	while (1) {
		k_sleep(K_MSEC(100));
	}

	return 0;
}

