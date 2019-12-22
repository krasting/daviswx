# Base 3.7.5 Python build on alpine linux
FROM python:3.7.5-alpine3.10

# add developer packages and shell
# note: if using interactively, use "sh" instead of "bash"
RUN apk add --no-cache --virtual .build-deps \
            bash \
	    build-base \
            freetype \
 	    freetype-dev \
	    gcc \
            git \
            libc-dev \
            libpng \
	    libpng-dev \
            libstdc++ \
            make \
	    musl-dev
#	    python-dev \
RUN ln -s /usr/include/locale.h /usr/include/xlocale.h

# clone the git repository
WORKDIR /app
RUN git clone https://github.com/krasting/daviswx

# build and install the package
WORKDIR /app/daviswx
RUN git checkout dev
RUN python setup.py install

# install python stack
RUN pip install numpy
RUN pip install matplotlib pandas flask flask_apscheduler
