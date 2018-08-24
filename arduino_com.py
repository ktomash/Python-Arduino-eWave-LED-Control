
import struct
import socket
import serial

# con = False
print("init")
s= socket.socket(socket.AF_INET, socket.SOCK_STREAM)
print("socket made")

s.connect(('localhost', 20480))
print("socket conn")

ser = serial.Serial("COM3", 115200)
print("serial made")

 
orig_data = s.recv(4000)

print (orig_data)
print ("ok")

ii = 0

while ii < 1000:

    orig_data = s.recv(4000)
    print (orig_data)

    data = orig_data.decode('utf-8')
    if "IBI=" in data:
        data_arr = data.split(' ')
        IBI_str = data_arr[9]
        print(IBI_str)
        IBI = int(IBI_str[5:(len(IBI_str)-1)])
        print('IBI is ',IBI)
        # IBI_byte1 = bytes(int(IBI/256))
        IBIi = int((IBI%400-IBI%8)/8)
        print(IBIi)
        # IBI_byte = bytes(IBI)
        ser.write(struct.pack('b', IBIi))
    ii = ii + 1



    