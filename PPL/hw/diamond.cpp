/*
 * CS3210 - Principles of Programming Languages - Fall 2022
 * Instructor: Thyago Mota
 * Student: Erik Sundblad
 * Description: Homework 02 - Diamond Problem
 */

#include <iostream>
#include <string>

using namespace std;

class Device {
    protected: 
        string manufacturer;
    
    public: 
        Device(string manufacturer) {
            this->manufacturer = manufacturer;
        }
        
        friend ostream& operator<<(ostream&, const Device&);
};

ostream& operator<<(ostream& os, const Device& device)
{
    os << device.manufacturer;
    return os;
}

class Printer: public Device {
    
    protected:    
        string type;
        
    public: 
        Printer(string manufacturer, string type): Device(manufacturer) {
            this->type = type;
        }
        
        friend ostream& operator<<(ostream&, const Printer&);
};

ostream& operator<<(ostream& os, const Printer& printer)
{
    os << printer.manufacturer << ", " << printer.type;
    return os;
}

class Scanner: public Device {
    
    protected:    
        string dpi;
        
    public: 
        Scanner(string manufacturer, string dpi): Device(manufacturer) {
            this->dpi = dpi;
        }
        
        friend ostream& operator<<(ostream&, const Scanner&);
};

ostream& operator<<(ostream& os, const Scanner& scanner)
{
    os << scanner.manufacturer << ", " << scanner.dpi;
    return os;
}

class MultifunctionPrinter: public Printer, public Scanner {
        
    public: 
        MultifunctionPrinter(string manufacturer, string type, string dpi): Printer(manufacturer, type), Scanner(manufacturer, dpi) {
        }
        
        friend ostream& operator<<(ostream&, const MultifunctionPrinter&);
};

ostream& operator<<(ostream& os, const MultifunctionPrinter& multifunctionPrinter)
{
    // Using Device class manufacturer variable to resolve amibigouity 
    os << multifunctionPrinter.Device::manufacturer << ", " << multifunctionPrinter.type << ", " << multifunctionPrinter.dpi;
    return os;
}

int main() {
    MultifunctionPrinter ts6300("Canon", "Inkjet", "600");
    std::cout << ts6300;

    return 0;
}