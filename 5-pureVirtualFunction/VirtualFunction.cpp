#include <iostream>
using namespace std;

class Instrument {
    public:
        virtual void MakeSound() = 0;
};

class Accordion : public Instrument {
    public:
        void MakeSound() {
            cout << "Accordion playing..." << endl;
        }
};

class Piano : public Instrument {
    public:
        void MakeSound() {
            cout << "Piano playing..." << endl;
        }
};

int main () {
    Instrument *instrumentAccordion = new Accordion();
    instrumentAccordion->MakeSound();

    Instrument *instrumentPiano = new Piano();
    instrumentPiano->MakeSound();

    Instrument *instrument[2] = { instrumentPiano, instrumentAccordion };
    
    for(int i = 0; i < 2; i++){
        instrument[i]->MakeSound();
    }

    return 0;

}