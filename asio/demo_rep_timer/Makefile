# THESE PATHS WILL NEED TO BE EDITED TO MATCH THE INSTALL PATHS ON YOUR PC...
# Path to Boost libraries:
BOOST_PATH := /home/mike/boost/boost_1_77_0

CXX = g++
CPPFLAGS = -I.. -I$(BOOST_PATH)      # put pre-processor settings (-I, -D, etc) here
CXXFLAGS = -Wall  # put compiler settings here
LDFLAGS = -L$(BOOST_PATH)/stage/lib -lpthread        # put linker settings here
LDFLAGS_EXTRA = -lpthread        # put linker settings here

rep_timer_demo: rep_timer_demo.o
	$(CXX) -o $@ $(CXXFLAGS) $(LDFLAGS) rep_timer_demo.o  $(LDFLAGS_EXTRA)

.cpp.o:
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $<

rep_timer_demo.cpp: ../basic_repeating_timer.hpp

clean:
	$(RM) rep_timer_demo.o rep_timer_demo

