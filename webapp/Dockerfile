# Base 3.7.5 Python build on alpine linux
FROM krasting/daviswx

# optional environment variables to set hostname
#ENV DAVIS_HOSTNAME
#ENV DAVIS_PORT

# open port 80 to the world
EXPOSE 80

# copy in simple flask script
WORKDIR /app
ADD app.py .
ADD templates templates

# start the server
ENTRYPOINT [ "python" ]
CMD [ "app.py" ]
