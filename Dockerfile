FROM debian:bullseye

RUN apt-get update && apt-get install -y \
    bash \
    build-essential \
    gcc-multilib \
    libc6-dev-i386 \
    nasm \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /scripts

CMD ["tail", "-f", "/dev/null"]
