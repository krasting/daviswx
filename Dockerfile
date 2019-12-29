# Base 3.7.5 Python build on alpine linux
FROM krasting/python-3.7.5-numpy-mpl-pandas-flask

# clone the git repository
WORKDIR /app
RUN git clone https://github.com/krasting/daviswx

# build and install the package
WORKDIR /app/daviswx
RUN git checkout dev
RUN python setup.py install
