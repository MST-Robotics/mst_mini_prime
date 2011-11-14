# James Anderson 
# My first make file
# Some reminders:
# Commands start with TAB not spaces
# $@ is the name of the target
# $< is the first dependancy
# $? is all dependancys more recent than the target

CXX = g++

all: keyboard_control

keyboard_control: keyboard_control.cpp MiniDrive.cpp miniservo.cpp serialDriver.cpp
	$(CXX) keyboard_control.cpp MiniDrive.cpp miniservo.cpp serialDriver.cpp  -lncurses -o $@

clean:
	rm -f keyboard_control


