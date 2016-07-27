BUILD_DIRS = lib \
	   src

all: 
	@ for dir in ${BUILD_DIRS}; do (cd $${dir}; ${MAKE}) ; done

clean: 
	@ for dir in ${BUILD_DIRS}; do (cd $${dir}; ${MAKE} clean) ; done
