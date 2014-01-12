require "serialport"

#params for serial port
port_str = "/dev/tty.usbmodem1431"  #may be different for you
baud_rate = 9600
data_bits = 8
stop_bits = 1
parity = SerialPort::NONE

sp = SerialPort.new(port_str, baud_rate, data_bits, stop_bits, parity)

#just read forever
command = ''
while true do
   while (input = sp.gets) do  
      if(input)
        command += input.chomp
        next unless input.include?(';')
        puts command
        if command =~ /lights on/
          `open ~/ossources/arduino/speech_recognition/prendiendo_luz.m4a`  
        end
        command = ''
      end
    end
end

sp.close                       #see note 1