CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		pocoservertest.o

LIBS = -lPocoNet -lPocoFoundation -lPocoUtil

TARGET =	pocoservertest

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
