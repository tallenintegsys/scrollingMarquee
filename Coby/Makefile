HOME=/home/tallen/Downloads/arduino-1.8.19/hardware/tools/avr/
CC=$(HOME)bin/avr-gcc

all:
	$(CC) -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10819 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR -I/home/tallen/Downloads/arduino-1.8.19/hardware/arduino/avr/cores/arduino -I/home/tallen/Downloads/arduino-1.8.19/hardware/arduino/avr/variants/standard -I/home/tallen/Arduino/libraries/FastLED-3.5.0/src /tmp/arduino_build_998740/sketch/Coby.ino.cpp -o Coby.o
	$(CC) -w -Os -g -flto -fuse-linker-plugin -Wl,--gc-sections -mmcu=atmega328p -o /tmp/arduino_build_998740/Coby.ino.elf /tmp/arduino_build_998740/sketch/Coby.ino.cpp.o /tmp/arduino_build_998740/libraries/FastLED-3.5.0/FastLED.cpp.o /tmp/arduino_build_998740/libraries/FastLED-3.5.0/bitswap.cpp.o /tmp/arduino_build_998740/libraries/FastLED-3.5.0/colorpalettes.cpp.o /tmp/arduino_build_998740/libraries/FastLED-3.5.0/colorutils.cpp.o /tmp/arduino_build_998740/libraries/FastLED-3.5.0/hsv2rgb.cpp.o /tmp/arduino_build_998740/libraries/FastLED-3.5.0/lib8tion.cpp.o /tmp/arduino_build_998740/libraries/FastLED-3.5.0/noise.cpp.o /tmp/arduino_build_998740/libraries/FastLED-3.5.0/platforms.cpp.o /tmp/arduino_build_998740/libraries/FastLED-3.5.0/power_mgt.cpp.o /tmp/arduino_build_998740/libraries/FastLED-3.5.0/wiring.cpp.o /tmp/arduino_build_998740/libraries/FastLED-3.5.0/platforms/esp/32/clockless_rmt_esp32.cpp.o /tmp/arduino_build_998740/../arduino_cache_124135/core/core_arduino_avr_uno_3838e1c8c867dd90ac4b833f45104cba.a -L/tmp/arduino_build_998740 -lm
	$(HOME)bin/avr-objcopy -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0 /tmp/arduino_build_998740/Coby.ino.elf /tmp/arduino_build_998740/Coby.ino.eep
	$(HOME)bin/avr-objcopy -O ihex -R .eeprom /tmp/arduino_build_998740/Coby.ino.elf /tmp/arduino_build_998740/Coby.ino.hex
	$(HOME)bin/avr-size -A /tmp/arduino_build_998740/Coby.ino.elf
	$(HOME)bin/avrdude -C$(HOME)etc/avrdude.conf -v -patmega328p -carduino -P/dev/ttyACM0 -b115200 -D -Uflash:w:/tmp/arduino_build_998740/Coby.ino.hex

