setenv SC_INSTALL_DIR /nfs/site/proj/vt/tools/sim/collateral/systemc/2.2-threaded/gcc_4.3.2/x86-64_linux26/opt
setenv VCS_HOME /nfs/site/eda/tools/synopsys/vcsmx/G-2012.09-3/common
setenv VCS_PATH /nfs/site/eda/tools/synopsys/vcsmx/G-2012.09-3/common
setenv CXX /usr/intel/pkgs/gcc/4.3.2/bin/g++
setenv CC /usr/intel/pkgs/gcc/4.3.2/bin/gcc

bin/build-libs -bfm=idi2 -clean -thread=12 -64bit --disable_srtp --debugmsgs=no
