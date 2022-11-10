

main: main.o ViewMain.o ViewSocket.o ViewInput.o ViewData.o Timer.o ModelSocket.o ModelData.o ModelAttribute.o ISocket.o IObserver.o IController.o ICommand.o ControllerSocket.o ControllerInput.o ControllerData.o ControllerCommand.o 
	g++ main.o ViewMain.o ViewSocket.o ViewInput.o ViewData.o Timer.o ModelSocket.o ModelData.o ModelAttribute.o ISocket.o IObserver.o IController.o ICommand.o ControllerSocket.o ControllerInput.o ControllerData.o ControllerCommand.o -o main -lgdi32 -lws2_32 -lpthread

main.o: main.cpp 
	g++ -c main.cpp -o main.o -lws2_32 

ViewMain.o: ViewMain.cpp
	g++ -c ViewMain.cpp -o ViewMain.o 

ViewSocket.o: ViewSocket.cpp
	g++ -c ViewSocket.cpp -o ViewSocket.o 

ViewInput.o: ViewInput.cpp 
	g++ -c ViewInput.cpp -o ViewInput.o 

ViewData.o: ViewData.cpp
	g++ -c ViewData.cpp -o ViewData.o 

Timer.o: Timer.cpp
	g++ -c Timer.cpp -o Timer.o 

ModelSocket.o: ModelSocket.cpp
	g++ -c ModelSocket.cpp -o ModelSocket.o 

ModelData.o: ModelData.cpp
	g++ -c ModelData.cpp -o ModelData.o 

ModelAttribute.o: ModelAttribute.cpp
	g++ -c ModelAttribute.cpp -o ModelAttribute.o 

ISocket.o: ISocket.cpp
	g++ -c ISocket.cpp -o ISocket.o 

IObserver.o: IObserver.cpp
	g++ -c IObserver.cpp -o IObserver.o

IController.o: IController.cpp
	g++ -c IController.cpp -o IController.o 

ICommand.o: ICommand.cpp
	g++ -c ICommand.cpp -o ICommand.o 

ControllerSocket.o: ControllerSocket.cpp
	g++ -c ControllerSocket.cpp -o ControllerSocket.o 

ControllerInput.o: ControllerInput.cpp
	g++ -c ControllerInput.cpp -o ControllerInput.o

ControllerData.o: ControllerData.cpp
	g++ -c ControllerData.cpp -o ControllerData.o

ControllerCommand.o: ControllerCommand.cpp
	g++ -c ControllerCommand.cpp -o ControllerCommand.o 
