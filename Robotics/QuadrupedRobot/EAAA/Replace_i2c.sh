#!/bin/bash
#To run after the dephaiDepedencies.sh 

	sudo cp /boot/firmware/overlays/i2c3.dtbo.bak /home/ubuntu/i2c3.dtbo
	sudo rm /boot/firmware/overlays/i2c3.dtbo
	sudo cp /home/ubuntu/i2c3.dtbo /boot/firmware/overlays
	
	sudo cp /boot/firmware/overlays/i2c4.dtbo.bak /home/ubuntu/i2c4.dtbo
	sudo rm /boot/firmware/overlays/i2c4.dtbo
	sudo cp /home/ubuntu/i2c4.dtbo /boot/firmware/overlays
	
	sudo cp /boot/firmware/overlays/i2c5.dtbo.bak /home/ubuntu/i2c5.dtbo
	sudo rm /boot/firmware/overlays/i2c5.dtbo
	sudo cp /home/ubuntu/i2c5.dtbo /boot/firmware/overlays
	
	sudo cp /boot/firmware/overlays/i2c6.dtbo.bak /home/ubuntu/i2c6.dtbo
	sudo rm /boot/firmware/overlays/i2c6.dtbo
	sudo cp /home/ubuntu/i2c6.dtbo /boot/firmware/overlays

	sudo rm	/home/ubuntu/i2c3.dtbo
	sudo rm	/home/ubuntu/i2c4.dtbo
	sudo rm	/home/ubuntu/i2c5.dtbo
	sudo rm	/home/ubuntu/i2c6.dtbo
