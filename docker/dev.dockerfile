FROM gcc:bookworm

RUN apt-get update
RUN apt-get install -y git
RUN apt-get install -y wget
RUN apt-get install -y llvm
RUN apt-get install -y clang
RUN apt-get install -y cmake

WORKDIR /usr/app/external/googletest
RUN wget https://github.com/google/googletest/archive/refs/tags/v1.15.2.tar.gz
ENV GOOGLE_TEST_ARCHIVE_PATH=/usr/app/external/googletest/v1.15.2.tar.gz

WORKDIR /usr/app/external/jsoncpp
RUN wget https://github.com/open-source-parsers/jsoncpp/archive/refs/tags/1.9.6.tar.gz
ENV JSONCPP_ARCHIVE_PATH=/usr/app/external/jsoncpp/1.9.6.tar.gz

# Sources root dir should be mounted to this location when running the container
WORKDIR /usr/app/src

CMD ["/bin/bash", "-c"]