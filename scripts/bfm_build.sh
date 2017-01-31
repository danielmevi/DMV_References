setenv SC_INSTALL_DIR /nfs/site/proj/vt/tools/sim/collateral/systemc/2.2.1-threaded/gcc_4.3.2/x86-64_linux26/opt
setenv VCS_HOME /nfs/site/eda/tools/synopsys/vcsmx/G-2012.09-3/common
setenv VCS_PATH /nfs/site/eda/tools/synopsys/vcsmx/G-2012.09-3/common
setenv CXX /usr/intel/pkgs/gcc/4.3.2/bin/g++
setenv CC /usr/intel/pkgs/gcc/4.3.2/bin/gcc

bin/build-libs -bfm=idi2 -clean -thread=12 -64bit --disable_srtp --debugmsgs=no #Add this flag if compilation requires it: -boost=/usr/intel/pkgs/boost/1.50.0-gcc-4.6.2/include
#DEBUG
#bin/build-libs -bfm=idi2 -clean -thread=12 -64bit --disable_srtp -debug

bin/runtest -clean -cleanr  -bfm=idi2 -test=IDIBasic/IDIEmulateIaMode_skx -64bit
bin/verify -bfm=idi2 -test=IDIBasic/IDIEmulateIaMode_skx

