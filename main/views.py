import serial
from django.shortcuts import render
from django.utils import timezone
final_list = []

#Your serial port might be different !!!
ser = serial.Serial('COM3', baudrate=9600, timeout=1)


def home(request):

    data = ser.readline()
    if data != b'':
        new_set = data.__str__()[2:len(data)].split()
        humidity = new_set[0]+"  %RH"
        temperature = new_set[1]+" °C"
        time = timezone.now()
        final_list.append((humidity, temperature, time))
        print(humidity, temperature)

    print(final_list)

    stuff = {
        'final_list': final_list
    }

    return render(request, 'main/base.html', stuff)
