import serial
ser=serial.Serial('/dev/tty.usbmodem318', 57600, timeout=1, writeTimeout=0)
ser.write(chr(0xF4))
ser.write(chr(0x02))
ser.write(chr(0x01))
ser.write(chr(0xF4))
ser.write(chr(0x04))
ser.write(chr(0x00))