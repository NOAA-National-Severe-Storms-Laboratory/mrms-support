
#SOME_FUTURE_INCLUDE      = -I/path/include
#SOME_FUTURE_LIB          = -L/path -lsomething

MRMSDIR=/localdata/Builds/MRMS

LOCAL_LIBRARIES =\
        -L$(MRMSDIR)/lib -lnetcdf

INCLUDES =\
        -I$(MRMSDIR)/include

SYS_LIBRARIES = -lm -lz


.SUFFIXES : .cc .h

.cc.o:
	$(CXX) $(CXXFLAGS) -c $<


              #CXX = CC
              CXX = g++
      CXXINCLUDES = $(INCLUDES)
    CXXDEBUGFLAGS = -g
       #CXXOPTIONS =  -LANG:std -O2 
       CXXOPTIONS = -Wall -O3 -g
         CXXFLAGS = $(CXXDEBUGFLAGS) $(CXXOPTIONS) $(CXXINCLUDES)

               MV = mv
               CP = cp
               RM = rm -f
 
               
SHARED_SRCS=\
 mrms_binary_reader.cc\
 write_netCDF_lib.cc\
 write_CF_netCDF_2d.cc\
 write_CF_netCDF_3d.cc\
 write_CF_netCDF_2d_FAA.cc\
 write_CF_netCDF_3d_FAA.cc\
 ProductInfo.cc\
 setupMRMS_ProductRefData.cc\
 HeaderAttribute.cc
  
  
MAIN_SRC=\
 mrms_to_CFncdf_main.cc

SHARED_OBJS=${SHARED_SRCS:.cc=.o}

MAIN_OBJS=${MAIN_SRC:.cc=.o} $(SHARED_OBJS)

PROGRAMS = mrms_to_CFncdf
  
all:: $(PROGRAMS)

mrms_to_CFncdf: $(MAIN_OBJS)
	$(RM) $@
	$(CXX) -o $@ $(CXXFLAGS) $(MAIN_OBJS) $(LOCAL_LIBRARIES) $(SYS_LIBRARIES) 
     
	
clean::
	$(RM) mrms_to_CFncdf
	$(RM) *.o core


