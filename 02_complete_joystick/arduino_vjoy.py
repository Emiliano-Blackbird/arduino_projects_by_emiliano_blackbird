import serial
import pyvjoy

COM_PORT = "COM5"     # Cambia al COM real de tu Arduino
BAUDRATE = 115200

# Abrir puerto serie
ser = serial.Serial(COM_PORT, BAUDRATE, timeout=1)

# Conectarse a vJoy device 1
j = pyvjoy.VJoyDevice(1)

print("Leyendo Arduino y mandando a vJoy… Ctrl+C para salir")

try:
    while True:
        line = ser.readline().decode('ascii').strip()
        if not line:
            continue
        parts = line.split(',')
        if len(parts) == 3:
            x = int(parts[0])
            y = int(parts[1])
            button = int(parts[2])

            # Normalizar 0-1023 a 1-32767 (vJoy expects 1..32767)
            vx = int((x / 1023.0) * 32767)
            vy = int((y / 1023.0) * 32767)

            j.set_axis(pyvjoy.HID_USAGE_X, vx)
            j.set_axis(pyvjoy.HID_USAGE_Y, vy)

            # Botón (vJoy es 1-based)
            j.set_button(1, button)  # 1=pressed, 0=released

except KeyboardInterrupt:
    print("Saliendo…")
finally:
    ser.close()
