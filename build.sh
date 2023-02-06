
mkdir -p obj
mkdir -p bin 

cd obj
g++ --std=c++17 -c -I../include  ../src/MessageFactory.cpp ../src/UnknownMessage.cpp ../src/KeepAlive.cpp ../src/StatusUpdate.cpp
cd ../bin

g++ ../src/main.cpp -I../include --std=c++17 -o factoryTest ../obj/StatusUpdate.o ../obj/MessageFactory.o ../obj/UnknownMessage.o ../obj/KeepAlive.o 

