# Boilerplate for Signal Project

## Installation:

Compile from scratch and move to your ~/.purple/plugins file , 

i'll make the binaries available from somewhere later.

compile as such:

note, ignore the first few steps if you already have the necesary libraries (you most likely do not.)

	sudo apt-get install libpurple-dev libjson-glib-dev libglib2.0-dev git make

	git clone https://github.com/signalapp/libsignal-protocol-c

	cd libsignal-protocol-c

	mkdir build

	cd build

	cmake -DCMAKE_BUILD_TYPE=Debug ..

	make

	sudo make install

	git clone https://github.com/mobile-bungalow/funyahoo-plusplus

	cd funyahoo-plusplus

	make

	mv signal.so (.dll on windows) (to your purple plugins directory)


