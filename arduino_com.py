import struct
import socket
import serial

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
    if "IBI=" in data:
        data_arr = data.split(' ')
        IBI_str = data_arr[9]
        print(IBI_str)
        IBI = int(IBI_str[5:(len(IBI_str)-1)])
        print('IBI is ',IBI)
        IBIi = int((IBI%400-IBI%8)/8)
        print(IBIi)
        ser.write(struct.pack('b', IBIi))



    