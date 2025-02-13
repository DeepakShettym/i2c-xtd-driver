# I2C XTD Driver

This is a Linux kernel I2C driver for an example device.

## Features:
- Detects an I2C device over the bus.
- Uses both **Device Tree** (`of_match_table`) and **ID-based matching** (`id_table`).
- Implements `probe` and `remove` functions.

## Device Tree Example
```dts
&i2c1 {
    i2c_xtd@38 {
        compatible = "vendor,i2c-xtd";
        reg = <0x38>;
    };
};





