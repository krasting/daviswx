CC=gcc

REMSERIAL_OBJ = remserial-1.3/remserial remserial-1.3/remserial.o remserial-1.3/stty.o
VPROWX_OBJ = vproweather-0.6/vproweather vproweather-0.6/dhandler.o vproweather-0.6/main.o

all: $(REMSERIAL_OBJ) $(VPROWX_OBJ) 
remserial: $(HDF5_OBJ)
vproweather: $(VPROWX_OBJ)

$(REMSERIAL_OBJ):
	$(MAKE) -C remserial-1.3

$(VPROWX_OBJ):
	$(MAKE) -C vproweather-0.6 vproweather

clean:
	-cd remserial-1.3; make clean 
	-cd vproweather-0.6; make clean
