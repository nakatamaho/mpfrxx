VERSION=4.2.2
GMP_VERSION=6.3.0  
export CC=gcc-13
export CXX=g++-13

WRKDIR=/home/docker/mpfrxx/setup/work_mpfr
ARCHIVEDIR=/home/docker/mpfrxx/archives/

rm -rf $WRKDIR
mkdir -p $WRKDIR
cd $WRKDIR
tar xvf $ARCHIVEDIR/mpfr-${VERSION}.tar.xz
cd mpfr-${VERSION}
./configure --with-gmp=/home/docker/mpfrxx/i/GMP-${GMP_VERSION} --prefix=/home/docker/mpfrxx/i/MPFR-${VERSION}
make -j`nproc`
make check
make install
cd ..
rm -rf $WRKDIR
