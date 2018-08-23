
import struct
import socket
import serial

emwave_socket= socket.socket(socket.AF_INET, socket.SOCK_STREAM)
emwave_socket.connect(('localhost', 20480))

arduino_conn = serial.Serial("COM3", 115200)

print(arduino_conn.readline())

def get_ibi_number_from_data_stream(data):
    data_arr = data.split(' ')
    IBI_str = data_arr[9]
    print(IBI_str)
    IBI = int(IBI_str[5:(len(IBI_str)-1)])
    print('IBI is ',IBI)
    # IBI_byte1 = bytes(int(IBI/256))
    IBIi = int((IBI%400-IBI%8)/8)
    print(IBIi)
    return IBIi


while True:

    orig_data = emwave_socket.recv(4000)
    print (orig_data)
    data = orig_data.decode('utf-8')

    if "IBI=" not in data: continue

    # IBI_byte = bytes(IBI)
    arduino_conn.write(struct.pack('b', get_ibi_number_from_data_stream(data)))


    