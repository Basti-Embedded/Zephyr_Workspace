/******************************************************************************
* @file    template.c
* @brief   Template Driver Source File
* @spdx_license_identifier: Apache-2.0
*******************************************************************************/

#define DT_DRV_COMPAT zephyr_device

#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

#if DT_NUM_INST_STATUS_OKAY(DT_DRV_COMPAT) == 0
#warning "driver enabled without any devices"
#endif

LOG_MODULE_REGISTER(TEMPLATE, CONFIG_ACCESS_POINT_LOG_LEVEL);

//======================================================================
//  DEFINES
//======================================================================

//======================================================================
//  TYPES
//======================================================================
struct template_config
{
    const struct device *uart;
    const struct gpio_dt_spec reset_gpio;
};

struct template_data
{
    const struct device *device_ptr;

};



//======================================================================
//  GLOBAL VARIABLES
//======================================================================

//======================================================================
//  FUNCTION DECLARATIONS
//======================================================================

int template_init(const struct device *dev);

//======================================================================
//  LOCAL FUNCTIONS
//======================================================================

//======================================================================
// API Functions
//======================================================================

/**********************************************************
 * @brief send data via UART to the MT3000
 * @param[in] dev pointer to the device structure
 * @retval return ACCESS_POINT_OK if the MT3000 Device was initalized successfully, otherwise ACCESS_POINT_ERROR 
 **********************************************************/
int template_init(const struct device *dev)
{
    const struct template_config *config = dev->config;
    struct template_data *data = dev->data;
    bool state = 0;
    int err = 0;
    
    data->device_ptr = dev;
}

//======================================================================
//  API FUNCTION DECLARATION
//======================================================================

static const struct access_point_api mt3000_api = {
    .api_function = function,
};

//======================================================================
//  DEVICE TREE DRIVER DEFINITIONS
//======================================================================

#define TEMPLATE_DEFINE(inst)                                                               \
    static struct template_data template_data_##inst;                                       \
    static const struct template_config template_config_##inst = {                          \
    .uart = DEVICE_DT_GET(DT_INST_BUS(inst)),                                               \
    .reset_gpio = GPIO_DT_SPEC_GET_OR(DT_INST(inst, zephyr_template), reset_gpios, NULL)    \
    };                                                                                      \
DEVICE_DT_INST_DEFINE(  inst,                                                               \
                        template_init,                                                      \
                        NULL,                                                               \
                        &template_data_##inst,                                              \
                        &template_config_##inst,                                            \
                        POST_KERNEL,                                                        \
                        CONFIG_ACCESS_POINT_INIT_PRIORITY,                                  \
                        &template_api);
                  
DT_INST_FOREACH_STATUS_OKAY(TEMPLATE_DEFINE)


//======================================================================
//  EOF
//======================================================================