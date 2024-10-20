set(APP_NAME "adc")
set(SOURCE_DIR ".")
set(PRIVATE_HEADER_DIR ".")
file(GLOB_RECURSE SOURCES "${SOURCE_DIR}/*.c")

add_executable(${APP_NAME}.elf ${SOURCES})

target_include_directories(
  ${APP_NAME}.elf
  PRIVATE ${PRIVATE_HEADER_DIR})

# Add custom commands for creating .hex, .bin, and .srec files
add_custom_command(
  TARGET ${APP_NAME}.elf
  POST_BUILD
  COMMAND avr-objcopy -j .text -j .data -O ihex ${APP_NAME}.elf ${APP_NAME}.hex
  COMMAND avr-objcopy -j .text -j .data -O binary ${APP_NAME}.elf
          ${APP_NAME}.bin
  COMMAND avr-objcopy -j .text -j .data -O srec ${APP_NAME}.elf ${APP_NAME}.srec
  COMMAND avr-objdump -h -S ${APP_NAME}.elf > ${APP_NAME}.lst
  COMMENT "Generating hex, bin, srec, and lst files")

# Add custom commands for EEPROM files
add_custom_command(
  TARGET ${APP_NAME}.elf
  POST_BUILD
  COMMAND avr-objcopy -j .eeprom --change-section-lma .eeprom=0 -O ihex
          ${APP_NAME}.elf ${APP_NAME}_eeprom.hex
  COMMAND avr-objcopy -j .eeprom --change-section-lma .eeprom=0 -O srec
          ${APP_NAME}.elf ${APP_NAME}_eeprom.srec
  COMMAND avr-objcopy -j .eeprom --change-section-lma .eeprom=0 -O binary
          ${APP_NAME}.elf ${APP_NAME}_eeprom.bin
  COMMENT "Generating EEPROM files")
