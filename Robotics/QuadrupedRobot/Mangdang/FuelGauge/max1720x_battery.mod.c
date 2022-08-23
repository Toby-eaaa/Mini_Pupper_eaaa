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
	{ 0xaa6922be, "i2c_del_driver" },
	{ 0x1c8c52db, "i2c_register_driver" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x3086771f, "regmap_update_bits_base" },
	{ 0xca052af9, "devm_request_threaded_irq" },
	{ 0xe874c1d4, "sysfs_create_group" },
	{ 0xd01922d, "power_supply_register" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x4eb65247, "__devm_regmap_init_i2c" },
	{ 0x18584e39, "of_property_read_variable_u32_array" },
	{ 0xde16ecff, "devm_kmalloc" },
	{ 0xc49aaa8f, "power_supply_get_drvdata" },
	{ 0xd808f2b, "_dev_info" },
	{ 0x2a805b53, "power_supply_changed" },
	{ 0x9c3cf915, "_dev_err" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x85900e7a, "regmap_write" },
	{ 0x8c8569cb, "kstrtoint" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x8da6585d, "__stack_chk_fail" },
	{ 0xc19ad693, "regmap_read" },
	{ 0x5f142d6c, "power_supply_unregister" },
	{ 0xb4145f16, "sysfs_remove_group" },
	{ 0x3c12dfe, "cancel_work_sync" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("i2c:max17201");
MODULE_ALIAS("i2c:max17205");
MODULE_ALIAS("i2c:max17301");
MODULE_ALIAS("i2c:max17302");
MODULE_ALIAS("i2c:max17303");
MODULE_ALIAS("of:N*T*Cmaxim,max17201");
MODULE_ALIAS("of:N*T*Cmaxim,max17201C*");
MODULE_ALIAS("of:N*T*Cmaxim,max17205");
MODULE_ALIAS("of:N*T*Cmaxim,max17205C*");
MODULE_ALIAS("of:N*T*Cmaxim,max17301");
MODULE_ALIAS("of:N*T*Cmaxim,max17301C*");
MODULE_ALIAS("of:N*T*Cmaxim,max17302");
MODULE_ALIAS("of:N*T*Cmaxim,max17302C*");
MODULE_ALIAS("of:N*T*Cmaxim,max17303");
MODULE_ALIAS("of:N*T*Cmaxim,max17303C*");

MODULE_INFO(srcversion, "FA19F17109BAB8AFD069645");
