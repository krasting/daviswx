import setuptools

with open("README.md", "r") as fh:
    long_description = fh.read()

setuptools.setup(
    name="daviswx",
    version="0.0.1",
    author="John Krasting",
    author_email="krasting@gmail.com",
    description="Tools for accessing Davis Vantage Pro II",
    long_description=long_description,
    long_description_content_type="text/markdown",
    url="https://github.com/krasting/daviswx",
    packages=setuptools.find_packages(),
    classifiers=[
        "Programming Language :: Python :: 3",
        "License :: OSI Approved :: GNU Lesser General Public License v3",
        "Operating System :: OS Independent",
    ],
)
