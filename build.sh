if [ ! -d "bin" ]; then
    mkdir bin
else
	rm bin/*
fi

g++ -g -O0 -I . -o bin/interrupts_EP interrupts_joodi-alasaad_kemal-sogut_EP.cpp
g++ -g -O0 -I . -o bin/interrupts_RR interrupts_joodi-alasaad_kemal-sogut.cpp
g++ -g -O0 -I . -o bin/interrupts_EP_RR interrupts_joodi-alasaad_kemal-sogut_EP_RR.cpp