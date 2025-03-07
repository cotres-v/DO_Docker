FROM debian

USER root

RUN apt-get update \
    && apt-get install -y gcc spawn-fcgi libfcgi-dev nginx\
    && rm -rf /var/lib/apt/lists

COPY ./webserver.c ./home/webserver.c
COPY ./nginx/nginx.conf /etc/nginx/nginx.conf
COPY ./run.sh ./home/run.sh

WORKDIR /home/

RUN chmod u-s /usr/bin/mount \
    && chmod u-s /usr/bin/umount \
    && chmod u-s /usr/bin/passwd \
    && chmod g-s /usr/bin/chage \
    && chmod g-s /usr/bin/expiry \
    && chmod u-s /usr/bin/su \
    && chmod u-s /usr/bin/chsh \ 
    && chmod u-s /usr/bin/gpasswd \
    && chmod u-s /usr/bin/chfn \
    && chmod u-s /usr/bin/newgrp \
    && chmod g-s /usr/sbin/unix_chkpwd \
    && gcc -Wall -Wextra -Werror /home/webserver.c -lfcgi -o fcgi.app \
    && rm -rf /etc/apt/keyrings/nginx-archive-keyring.gpg

USER nginx

CMD ["sh", "./run.sh"]

HEALTHCHECK --interval=30s --timeout=3s \
    CMD curl --fail http://localhoust:80/ || exit 1