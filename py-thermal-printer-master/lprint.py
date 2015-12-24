import printer, fileinput 

p = printer.ThermalPrinter(serialport="/dev/ttyAMA0")

for line in fileinput.input():
    p.print_text(line)

p.linefeed()
p.linefeed()
p.linefeed()
