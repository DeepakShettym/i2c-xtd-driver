
---

### **5. `Makefile` (Build the Driver)**
```makefile
obj-m += i2c_xtd_driver.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
