#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x839c2ece, "module_layout" },
	{ 0xb22abe51, "param_ops_uint" },
	{ 0xaa6922be, "i2c_del_driver" },
	{ 0x1c8c52db, "i2c_register_driver" },
	{ 0x92997ed8, "_printk" },
	{ 0xd752788b, "regmap_bulk_write" },
	{ 0xc6cbbc89, "capable" },
	{ 0x9c3cf915, "_dev_err" },
	{ 0x8da6585d, "__stack_chk_fail" },
	{ 0x9a85518a, "__pm_runtime_disable" },
	{ 0xac454ec8, "device_property_read_string" },
	{ 0xd808f2b, "_dev_info" },
	{ 0x593e9446, "devm_nvmem_register" },
	{ 0xb6fadb41, "pm_runtime_enable" },
	{ 0xbbc55423, "__pm_runtime_set_status" },
	{ 0x907756ac, "devm_i2c_new_dummy_device" },
	{ 0x12b333b0, "devm_regulator_get" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xde16ecff, "devm_kmalloc" },
	{ 0x4eb65247, "__devm_regmap_init_i2c" },
	{ 0x5a35049, "_dev_warn" },
	{ 0x8407c254, "device_property_present" },
	{ 0xff5e6c50, "device_property_read_u32_array" },
	{ 0x50d0ef31, "of_device_get_match_data" },
	{ 0xf8a2fa83, "of_match_device" },
	{ 0xd67cda50, "i2c_match_id" },
	{ 0xdcb764ad, "memset" },
	{ 0x5e2d7875, "cpu_hwcap_keys" },
	{ 0x14b89635, "arm64_const_caps_ready" },
	{ 0x43a60bff, "__dynamic_dev_dbg" },
	{ 0xa6cd3df5, "__pm_runtime_idle" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x2dc47400, "regmap_bulk_read" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xa0a97546, "__pm_runtime_resume" },
	{ 0x4304ced, "regulator_disable" },
	{ 0x9e0ecd5a, "regulator_enable" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("acpi*:INT3499:*");
MODULE_ALIAS("acpi*:TPF0001:*");
MODULE_ALIAS("of:N*T*Catmel,24c00");
MODULE_ALIAS("of:N*T*Catmel,24c00C*");
MODULE_ALIAS("of:N*T*Catmel,24c01");
MODULE_ALIAS("of:N*T*Catmel,24c01C*");
MODULE_ALIAS("of:N*T*Catmel,24cs01");
MODULE_ALIAS("of:N*T*Catmel,24cs01C*");
MODULE_ALIAS("of:N*T*Catmel,24c02");
MODULE_ALIAS("of:N*T*Catmel,24c02C*");
MODULE_ALIAS("of:N*T*Catmel,24cs02");
MODULE_ALIAS("of:N*T*Catmel,24cs02C*");
MODULE_ALIAS("of:N*T*Catmel,24mac402");
MODULE_ALIAS("of:N*T*Catmel,24mac402C*");
MODULE_ALIAS("of:N*T*Catmel,24mac602");
MODULE_ALIAS("of:N*T*Catmel,24mac602C*");
MODULE_ALIAS("of:N*T*Catmel,spd");
MODULE_ALIAS("of:N*T*Catmel,spdC*");
MODULE_ALIAS("of:N*T*Catmel,24c04");
MODULE_ALIAS("of:N*T*Catmel,24c04C*");
MODULE_ALIAS("of:N*T*Catmel,24cs04");
MODULE_ALIAS("of:N*T*Catmel,24cs04C*");
MODULE_ALIAS("of:N*T*Catmel,24c08");
MODULE_ALIAS("of:N*T*Catmel,24c08C*");
MODULE_ALIAS("of:N*T*Catmel,24cs08");
MODULE_ALIAS("of:N*T*Catmel,24cs08C*");
MODULE_ALIAS("of:N*T*Catmel,24c16");
MODULE_ALIAS("of:N*T*Catmel,24c16C*");
MODULE_ALIAS("of:N*T*Catmel,24cs16");
MODULE_ALIAS("of:N*T*Catmel,24cs16C*");
MODULE_ALIAS("of:N*T*Catmel,24c32");
MODULE_ALIAS("of:N*T*Catmel,24c32C*");
MODULE_ALIAS("of:N*T*Catmel,24cs32");
MODULE_ALIAS("of:N*T*Catmel,24cs32C*");
MODULE_ALIAS("of:N*T*Catmel,24c64");
MODULE_ALIAS("of:N*T*Catmel,24c64C*");
MODULE_ALIAS("of:N*T*Catmel,24cs64");
MODULE_ALIAS("of:N*T*Catmel,24cs64C*");
MODULE_ALIAS("of:N*T*Catmel,24c128");
MODULE_ALIAS("of:N*T*Catmel,24c128C*");
MODULE_ALIAS("of:N*T*Catmel,24c256");
MODULE_ALIAS("of:N*T*Catmel,24c256C*");
MODULE_ALIAS("of:N*T*Catmel,24c512");
MODULE_ALIAS("of:N*T*Catmel,24c512C*");
MODULE_ALIAS("of:N*T*Catmel,24c1024");
MODULE_ALIAS("of:N*T*Catmel,24c1024C*");
MODULE_ALIAS("of:N*T*Catmel,24c2048");
MODULE_ALIAS("of:N*T*Catmel,24c2048C*");
MODULE_ALIAS("i2c:24c00");
MODULE_ALIAS("i2c:24c01");
MODULE_ALIAS("i2c:24cs01");
MODULE_ALIAS("i2c:24c02");
MODULE_ALIAS("i2c:24cs02");
MODULE_ALIAS("i2c:24mac402");
MODULE_ALIAS("i2c:24mac602");
MODULE_ALIAS("i2c:spd");
MODULE_ALIAS("i2c:24c02-vaio");
MODULE_ALIAS("i2c:24c04");
MODULE_ALIAS("i2c:24cs04");
MODULE_ALIAS("i2c:24c08");
MODULE_ALIAS("i2c:24cs08");
MODULE_ALIAS("i2c:24c16");
MODULE_ALIAS("i2c:24cs16");
MODULE_ALIAS("i2c:24c32");
MODULE_ALIAS("i2c:24cs32");
MODULE_ALIAS("i2c:24c64");
MODULE_ALIAS("i2c:24cs64");
MODULE_ALIAS("i2c:24c128");
MODULE_ALIAS("i2c:24c256");
MODULE_ALIAS("i2c:24c512");
MODULE_ALIAS("i2c:24c1024");
MODULE_ALIAS("i2c:24c2048");
MODULE_ALIAS("i2c:at24");

MODULE_INFO(srcversion, "C4DEA0C2F0FED512E696948");
