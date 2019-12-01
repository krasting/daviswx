CC=gcc

REMSERIAL_OBJ = external/remserial-1.3/remserial external/remserial-1.3/remserial.o external/remserial-1.3/stty.o
VPROWX_OBJ = external/vproweather-0.6/vproweather external/vproweather-0.6/dhandler.o external/vproweather-0.6/main.o

all: $(REMSERIAL_OBJ) $(VPROWX_OBJ) 
remserial: $(HDF5_OBJ)
vproweather: $(VPROWX_OBJ)

$(REMSERIAL_OBJ):
	$(MAKE) -C external/remserial-1.3

$(VPROWX_OBJ):
	$(MAKE) -C external/vproweather-0.6 vproweather

clean:
	-cd external/remserial-1.3; make clean 
	-cd external/vproweather-0.6; make clean
