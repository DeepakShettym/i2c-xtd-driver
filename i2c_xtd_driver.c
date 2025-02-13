#include <linux/module.h>
#include <linux/i2c.h>
#include <linux/of.h>

#define DRIVER_NAME "i2c_xtd"

static int i2c_xtd_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
    pr_info("I2C XTD Driver: Device detected at address 0x%02x\n", client->addr);
    return 0;
}

static int i2c_xtd_remove(struct i2c_client *client)
{
    pr_info("I2C XTD Driver: Device removed\n");
    return 0;
}

static const struct i2c_device_id i2c_xtd_id[] = {
    { "i2c_xtd", 0 },
    { }
};
MODULE_DEVICE_TABLE(i2c, i2c_xtd_id);

static const struct of_device_id i2c_xtd_of_match[] = {
    { .compatible = "vendor,i2c-xtd" },
    { }
};
MODULE_DEVICE_TABLE(of, i2c_xtd_of_match);

static struct i2c_driver i2c_xtd_driver = {
    .driver = {
        .name = DRIVER_NAME,
        .of_match_table = i2c_xtd_of_match,
    },
    .id_table = i2c_xtd_id,
    .probe = i2c_xtd_probe,
    .remove = i2c_xtd_remove,
};

module_i2c_driver(i2c_xtd_driver);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("I2C XTD Device Driver");
MODULE_AUTHOR("Deepak M");
