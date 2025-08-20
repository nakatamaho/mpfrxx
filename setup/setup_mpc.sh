MPFR_VERSION=4.2.2
GMP_VERSION=6.3.0
VERSION=1.3.2
export CC=gcc-13
export CXX=g++-13

WRKDIR=/home/docker/mpfrxx/setup/work_mpc
ARCHIVEDIR=/home/docker/mpfrxx/archives/

rm -rf $WRKDIR
mkdir -p $WRKDIR
cd $WRKDIR
tar xvf $ARCHIVEDIR/mpc-${VERSION}.tar.gz
cd mpc-${VERSION}
./configure --with-gmp=/home/docker/mpfrxx/i/GMP-${GMP_VERSION} --with-mpfr=/home/docker/mpfrxx/i/MPFR-${MPFR_VERSION} --prefix=/home/docker/mpfrxx/i/MPC-${VERSION}
make -j`nproc`
make check
make install
cd ..
rm -rf $WRKDIR
