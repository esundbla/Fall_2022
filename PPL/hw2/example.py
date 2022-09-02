'''
 * CS3210 - Principles of Programming Languages - Fall 2022
 * Instructor: Thyago Mota
 * Student: Erik Sundblad
 * Description: Homework 02 - Diamond Problem
'''

class Device: 
    
    def __init__(self, manufacturer) -> None:
        self.manufacturer = manufacturer
        

    def __str__(self) -> str:
        return self.manufacturer

class Printer(Device): 

    def __init__(self, manufacturer, type) -> None:
        Device.__init__(self, manufacturer)
        self.type = type


    def __str__(self) -> str:
        return self.manufacturer + " " + self.type

class Scanner(Device): 

    def __init__(self, manufacturer, dpi) -> None:
        Device.__init__(self, manufacturer)
        self.dpi = dpi

    def __str__(self) -> str:

        return self.manufacturer + " " + self.dpi

class MultifunctionPrinter(Printer, Scanner): 

    def __init__(self, manufacturer, type, dpi) -> None:
        Printer.__init__(self, manufacturer, type)
        Scanner.__init__(self, manufacturer, dpi)

    def __str__(self) -> str:
        return self.manufacturer + " " + self.dpi + " " + self.type

if __name__ == '__main__':
    ts6300 = MultifunctionPrinter("Canon", "Inkjet", "600")
    print(ts6300)
   