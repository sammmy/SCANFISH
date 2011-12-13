all: headers
	g++ -D_REENTRANT -o sf main.cpp canio.o cannet.o msg.o controller.o -lpthread
headers: canio.h cannet.h msg.h controller.h canlistener.h msgspv.h sferror.h generalScreen.h gsConnect.h gsMessageEditor.h gsReceive.h gsReceiveSL.h gsTransmit.h gsTransmitSL.h
	g++ -D_REENTRANT -c canio.cpp cannet.cpp msg.cpp controller.cpp gsReceiveSL.cpp gsReceive.cpp gsTransmitSL.cpp gsTransmit.cpp gsMessageEditor.cpp gsConnect.cpp main.cpp -lpthread
clean:
	rm -f *.o
