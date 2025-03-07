FROM nginx:latest

USER root

RUN apt-get update && \
    apt-get install -y gcc spawn-fcgi libfcgi-dev && \
    rm -rf /var/lib/apt/lists/*

COPY ./webserver.c ./viktor/webserver.c
COPY ./nginx/nginx.conf /etc/nginx/nginx.conf
COPY ./run.sh ./viktor/run.sh

WORKDIR /viktor/

RUN gcc -Wall -Wextra -Werror /viktor/webserver.c -lfcgi -o fcgi.app

CMD ["sh", "./run.sh"]
