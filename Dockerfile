# Base 3.7.5 Python build on alpine linux
FROM python:3.7.5-alpine3.10

# optional environment variables to set hostname
ENV DAVIS_HOSTNAME 
ENV DAVIS_PORT 

# add developer packages and shell
# note: if using interactively, use "sh" instead of "bash"
RUN apk add --no-cache --virtual .build-deps gcc git libc-dev make bash

# clone the git repository
WORKDIR /app
RUN git clone https://github.com/krasting/daviswx

# build and install the package
WORKDIR /app/daviswx
RUN git checkout dev
RUN python setup.py install

# install flask
RUN pip install flask

# remove developer tools to save space
RUN apk del .build-deps gcc

# open port 80 to the world
EXPOSE 80

# copy in simple flask script
WORKDIR /app
ADD app.py .

# start the server
ENTRYPOINT [ "python" ]
CMD [ "app.py" ]
