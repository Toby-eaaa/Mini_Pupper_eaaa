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
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x9f46ced8, "__sw_hweight64" },
	{ 0xa0a97546, "__pm_runtime_resume" },
	{ 0x9c3cf915, "_dev_err" },
	{ 0xbbc55423, "__pm_runtime_set_status" },
	{ 0xb6fadb41, "pm_runtime_enable" },
	{ 0xff2988c, "devm_gpiochip_add_data_with_key" },
	{ 0x1f92a049, "pwmchip_add" },
	{ 0x8407c254, "device_property_present" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x4eb65247, "__devm_regmap_init_i2c" },
	{ 0xde16ecff, "devm_kmalloc" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x5e2d7875, "cpu_hwcap_keys" },
	{ 0x14b89635, "arm64_const_caps_ready" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xa6cd3df5, "__pm_runtime_idle" },
	{ 0x9a85518a, "__pm_runtime_disable" },
	{ 0xd4f78e20, "pwmchip_remove" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x3086771f, "regmap_update_bits_base" },
	{ 0x85900e7a, "regmap_write" },
	{ 0x1357975a, "gpiochip_get_data" },
	{ 0x8da6585d, "__stack_chk_fail" },
	{ 0xc19ad693, "regmap_read" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("of:N*T*Cnxp,pca9685-pwm");
MODULE_ALIAS("of:N*T*Cnxp,pca9685-pwmC*");
MODULE_ALIAS("i2c:pca9685");

MODULE_INFO(srcversion, "F08E8D9B1A0DCC5ADABC0EC");
