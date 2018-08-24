import struct
import socket
import serial
import math

# con = False

s= socket.socket(socket.AF_INET, socket.SOCK_STREAM)


s.connect(('localhost', 20480))

ser = serial.Serial("COM3", 115200)
# while not con:
#     serin = ser.read()
#     con = True

print(ser.readline())
 
orig_data = s.recv(4000)

print (orig_data)
print ("ok")

ii = 0

while True:

    orig_data = s.recv(4000)
    print (orig_data)

    data = orig_data.decode('utf-8')
    if "EP=" in data:
        print(data)
        data_arr = data.split(' ')
        EP_str = data_arr[8]
        print(EP_str)
        EP = int(EP_str[4:(len(EP_str)-1)])
        print('EP is ',EP)
        CS = int (round (10*(math.log10 (1+EP/10) )) )
        print(CS)
        ser.write(struct.pack('b', CS))



    