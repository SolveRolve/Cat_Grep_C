FROM quay.io/school21/alpine:3.16

RUN apk --no-cache --upgrade add \
    git \
    vim\
    git-lfs \
    curl \
    jq \
    bash \
    build-base \
    python3 \
    valgrind \
    cppcheck \
    alpine-sdk \
    pcre-dev \
    clang-extra-tools

COPY /grep /grep
