CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		pocoservertest.o T.o

LIBS = -lPocoNet -lPocoFoundation -lPocoUtil -lPocoJSON

TARGET =	pocoservertest

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
